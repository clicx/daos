#!/usr/bin/python
'''
  (C) Copyright 2019 Intel Corporation.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  GOVERNMENT LICENSE RIGHTS-OPEN SOURCE SOFTWARE
  The Government's rights to use, modify, reproduce, release, perform, display,
  or disclose this software are subject to the terms of the Apache License as
  provided in Contract No. B609815.
  Any reproduction of computer software, computer software documentation, or
  portions thereof marked with this legend must also reproduce the markings.
'''

# Some useful test classes inherited from avocado.Test

from __future__ import print_function

import os
import subprocess
import json

from avocado import Test as avocadoTest
from avocado import skip

import fault_config_utils
import agent_utils
import server_utils
import write_host_file
from daos_api import DaosContext, DaosLog

# pylint: disable=invalid-name
def skipForTicket(ticket):
    ''' Skip a test with a comment about a ticket'''
    return skip("Skipping until {} is fixed.".format(ticket))
# pylint: enable=invalid-name

class Test(avocadoTest):
    '''
    Basic Test class

    :avocado: recursive
    '''
    def __init__(self, *args, **kwargs):
        super(Test, self).__init__(*args, **kwargs)
        # set a default timeout of 1 minute
        # tests that want longer should set a timeout in their .yaml file
        # all tests should set a timeout and 60 seconds will enforce that
        if not self.timeout:
            self.timeout = 60

        item_list = self.logdir.split('/')
        for index, item in enumerate(item_list):
            if item == 'job-results':
                self.job_id = item_list[index + 1]
                break

        self.log.info("Job-ID: %s", self.job_id)
        self.log.info("Test PID: %s", os.getpid())

        self.basepath = None
        self.orterun = None
        self.tmp = None
        self.server_group = None
        self.daosctl = None
        self.context = None
        self.pool = None
        self.container = None
        self.hostlist_servers = None
        self.hostfile_servers = None
        self.hostlist_clients = None
        self.hostfile_clients = None
        self.d_log = None
        self.uri_file = None
        self.fault_file = None
        self.subtest_name = None

    # pylint: disable=invalid-name
    def cancelForTicket(self, ticket):
        ''' Skip a test due to a ticket needing to be completed '''
        return self.cancel("Skipping until {} is fixed.".format(ticket))
    # pylint: enable=invalid-name

class TestWithoutServers(Test):
    '''
    Run tests without DAOS servers

    :avocado: recursive
    '''
    def setUp(self):
        super(TestWithoutServers, self).setUp()
        # get paths from the build_vars generated by build
        with open('../../../.build_vars.json') as build_vars:
            build_paths = json.load(build_vars)
        self.basepath = os.path.normpath(os.path.join(build_paths['PREFIX'],
                                                      '..') + os.path.sep)
        self.prefix = build_paths['PREFIX']
        self.tmp = os.path.join(self.prefix, 'tmp')
        self.daos_test = os.path.join(self.basepath, 'install', 'bin',
                                      'daos_test')
        self.orterun = os.path.join(self.basepath, 'install', 'bin', 'orterun')
        self.daosctl = os.path.join(self.basepath, 'install', 'bin', 'daosctl')

        # setup fault injection, this MUST be before API setup
        fault_list = self.params.get("fault_list", '/run/faults/*/')
        if fault_list:
            # not using workdir because the huge path was messing up
            # orterun or something, could re-evaluate this later
            tmp = os.path.join(self.basepath, 'install', 'tmp')
            self.fault_file = fault_config_utils.write_fault_file(tmp,
                                                                  fault_list,
                                                                  None)
            os.environ["D_FI_CONFIG"] = self.fault_file

        self.context = DaosContext(self.prefix + '/lib/')
        self.d_log = DaosLog(self.context)

    def tearDown(self):
        super(TestWithoutServers, self).tearDown()

        if self.fault_file:
            os.remove(self.fault_file)

class TestWithServers(TestWithoutServers):
    '''
    Run tests with DAOS servers

    :avocado: recursive
    '''
    def __init__(self, *args, **kwargs):
        super(TestWithServers, self).__init__(*args, **kwargs)

        self.agent_sessions = None

    def setUp(self):
        super(TestWithServers, self).setUp()

        self.server_group = self.params.get("server_group", '/server/',
                                            'daos_server')
        self.hostlist_servers = self.params.get("test_machines", '/run/hosts/*')

        self.hostfile_servers = write_host_file.write_host_file(
            self.hostlist_servers,
            self.workdir)

        self.agent_sessions = agent_utils.run_agent(self.basepath,
                                                    self.hostlist_servers)
        server_utils.run_server(self.hostfile_servers, self.server_group,
                                self.basepath)

    def tearDown(self):

        try:
            if self.agent_sessions:
                agent_utils.stop_agent(self.hostlist_servers,
                                       self.agent_sessions)
        finally:
            server_utils.stop_server(hosts=self.hostlist_servers)

        # pylint: disable=no-member
        test_name = str(self.name)
        colon = test_name.index(':')
        semicolon = test_name.index(';', colon)
        test_name = test_name[colon+1:semicolon]
        # collect up a debug log so that we have a separate one for each
        # test
        try:
            server_logfile = os.path.sep + "tmp"
            if os.getenv('TEST_TAG'):
                server_logfile += os.path.sep + "Functional_" + \
                                  os.getenv('TEST_TAG')

            if self.subtest_name:
                test_name += "-{}".format(self.subtest_name)

            client_logfile = os.path.join(
                server_logfile,
                "{}_client_daos.log".format(test_name))
            agent_logfile = os.path.join(
                server_logfile,
                "{}_agent_daos.log".format(test_name))
            server_logfile += os.path.sep + \
                "{}_server_daos.log".format(test_name)

            client_cmd = '''if [ -f /tmp/client.log ]; then
                if [ -e "{0}" ]; then
                    echo "Not overwriting existing file {0}"
                    exit 1
                else
                    mv /tmp/client.log {0}
                fi
            fi
            if [ -f /tmp/daos_agent.log ]; then
                if [ -e "{1}" ]; then
                    echo "Not overwriting existing file {1}"
                    exit 1
                else
                    mv /tmp/daos_agent.log {1}
                fi
            fi'''.format(client_logfile, agent_logfile)
            cmd = '''if [ -f /tmp/server.log ]; then
                if [ -e "{0}" ]; then
                    echo "Not overwriting existing file {0}"
                    exit 1
                else
                    mv /tmp/server.log {0}
                fi
            fi
            {1}'''.format(server_logfile, client_cmd)
            for host in self.hostlist_servers + \
                        (self.hostlist_clients if self.hostlist_clients
                         else []):
                subprocess.check_call(['/usr/bin/ssh', host, cmd])
            subprocess.check_call(client_cmd, shell=True)
        except KeyError:
            pass

        super(TestWithServers, self).tearDown()

class TestWithClients(TestWithServers):
    '''
    Run tests with DAOS servers and clients

    :avocado: recursive
    '''

    # TODO: use hostlist_servers and hostlist_clients
    def setUp(self):
        super(TestWithClients, self).setUp()
        self.error("TestWithClients() needs to be fleshed out")

    def tearDown(self):
        self.error("TestWithClients() needs to be fleshed out")
        super(TestWithClients, self).tearDown()
