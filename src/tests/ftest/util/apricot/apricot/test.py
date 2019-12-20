#!/usr/bin/python
"""
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
"""
from __future__ import print_function

import os
import json
from getpass import getuser

from avocado import Test as avocadoTest
from avocado import skip, TestFail, fail_on

import fault_config_utils
from pydaos.raw import DaosContext, DaosLog, DaosApiError
from configuration_utils import Configuration
from command_utils import CommonConfig, CommandFailure
from agent_utils import DaosAgentYamlParameters, DaosAgentCommand
from agent_utils import DaosAgentManager, DaosAgentTransportCredentials
from agent_utils import include_local_host
from server_utils import DaosServerYamlParameters, DaosServerCommand
from server_utils import DaosServerManager, DaosServerTransportCredentials
from general_utils import get_partition_hosts
from logger_utils import TestLogger


# pylint: disable=invalid-name
def skipForTicket(ticket):
    """Skip a test with a comment about a ticket."""
    return skip("Skipping until {} is fixed.".format(ticket))
# pylint: enable=invalid-name


class Test(avocadoTest):
    """Basic Test class.

    :avocado: recursive
    """

    def __init__(self, *args, **kwargs):
        """Initialize a Test object."""
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

    # pylint: disable=invalid-name
    def cancelForTicket(self, ticket):
        """Skip a test due to a ticket needing to be completed."""
        return self.cancel("Skipping until {} is fixed.".format(ticket))
    # pylint: enable=invalid-name


class TestWithoutServers(Test):
    """Run tests without DAOS servers.

    :avocado: recursive
    """

    def __init__(self, *args, **kwargs):
        """Initialize a Test object."""
        super(TestWithoutServers, self).__init__(*args, **kwargs)

        self.basepath = None
        self.prefix = None
        self.bin = None
        self.daos_test = None
        self.daosctl = None
        self.cart_prefix = None
        self.cart_bin = None
        self.ompi_prefix = None
        self.ompi_bin = None
        self.orterun = None
        self.tmp = None
        self.fault_file = None
        self.context = None
        self.d_log = None
        self.test_log = None

    def setUp(self):
        """Set up run before each test."""
        super(TestWithoutServers, self).setUp()
        # get paths from the build_vars generated by build
        with open('../../.build_vars.json') as build_vars:
            build_paths = json.load(build_vars)
        self.basepath = os.path.normpath(os.path.join(build_paths['PREFIX'],
                                                      '..') + os.path.sep)
        self.prefix = build_paths['PREFIX']
        self.bin = os.path.join(self.prefix, 'bin')
        self.daos_test = os.path.join(self.bin, 'daos_test')
        self.daosctl = os.path.join(self.bin, 'daosctl')

        self.cart_prefix = build_paths['CART_PREFIX']
        self.cart_bin = os.path.join(self.cart_prefix, 'bin')

        self.ompi_prefix = build_paths["OMPI_PREFIX"]
        self.ompi_bin = os.path.join(self.ompi_prefix, "bin")
        self.orterun = os.path.join(self.ompi_bin, "orterun")

        # set default shared dir for daos tests in case DAOS_TEST_SHARED_DIR
        # is not set, for RPM env and non-RPM env.
        if self.prefix != "/usr":
            self.tmp = os.path.join(self.prefix, 'tmp')
        else:
            self.tmp = os.getenv(
                'DAOS_TEST_SHARED_DIR', os.path.expanduser('~/daos_test'))
        if not os.path.exists(self.tmp):
            os.makedirs(self.tmp)

        # setup fault injection, this MUST be before API setup
        fault_list = self.params.get("fault_list", '/run/faults/*/')
        if fault_list:
            # not using workdir because the huge path was messing up
            # orterun or something, could re-evaluate this later
            self.fault_file = fault_config_utils.write_fault_file(self.tmp,
                                                                  fault_list,
                                                                  None)
            os.environ["D_FI_CONFIG"] = self.fault_file

        self.context = DaosContext(self.prefix + '/lib64/')
        self.d_log = DaosLog(self.context)
        self.test_log = TestLogger(self.log, self.d_log)

    def tearDown(self):
        """Tear down after each test case."""
        super(TestWithoutServers, self).tearDown()

        if self.fault_file:
            os.remove(self.fault_file)


class TestWithServers(TestWithoutServers):
    """Run tests with DAOS servers and at least one client.

    Optionally run DAOS clients on specified hosts.  By default run a single
    DAOS client on the host executing the test.

    :avocado: recursive
    """

    def __init__(self, *args, **kwargs):
        """Initialize a TestWithServers object."""
        super(TestWithServers, self).__init__(*args, **kwargs)

        self.server_group = None
        self.hostlist_servers = None
        self.hostlist_clients = None
        self.partition_servers = None
        self.partition_clients = None
        self.config = None
        self.debug = False
        self.setup_start_servers = True
        self.setup_start_agents = True
        self.hostfile_servers = None
        self.hostfile_clients = None
        self.hostfile_servers_slots = 1
        self.hostfile_clients_slots = 1
        self.agent_managers = []
        self.server_managers = []
        self.pool = None
        self.container = None
        self.uri_file = None
        self.agent_log = None
        self.server_log = None
        self.control_log = None
        self.client_log = None
        self.log_dir = os.path.split(
            os.getenv("D_LOG_FILE", "/tmp/server.log"))[0]
        self.test_id = "{}-{}".format(
            os.path.split(self.filename)[1], self.name.str_uid)

    def setUp(self):
        """Set up each test case."""
        super(TestWithServers, self).setUp()

        self.server_group = self.params.get(
            "name", "/server_config/", "daos_server")

        # Determine which hosts to use as servers and optionally clients.
        test_servers = self.params.get("test_servers", "/run/hosts/*")
        test_clients = self.params.get("test_clients", "/run/hosts/*")

        # Support the use of a host type count to test with subsets of the
        # specified hosts lists
        server_count = self.params.get("server_count", "/run/hosts/*")
        client_count = self.params.get("client_count", "/run/hosts/*")

        # If server or client host list are defined through valid slurm
        # partition names override any hosts specified through lists.
        for name in ("servers", "clients"):
            host_list_name = "_".join(["test", name])
            partition_name = "_".join(["partition", name])
            partition = self.params.get(partition_name, "/run/hosts/*")
            host_list = locals()[host_list_name]
            if partition is not None and host_list is None:
                # If a partition is provided instead of a list of hosts use the
                # partition information to populate the list of hosts.
                setattr(self, partition_name, partition)
                locals()[host_list_name] = get_partition_hosts(partition_name)
            elif partition is not None and host_list is not None:
                self.fail(
                    "Specifying both a {} partition name and a list of hosts "
                    "is not supported!".format(name))

        # For API calls include running the agent on the local host
        test_clients = include_local_host(test_clients)

        # Supported combinations of yaml hosts arguments:
        #   - test_servers [+ server_count]
        #   - test_servers [+ server_count] + test_clients [+ client_count]
        if test_servers and test_clients:
            self.hostlist_servers = test_servers[:server_count]
            self.hostlist_clients = test_clients[:client_count]
        elif test_servers:
            self.hostlist_servers = test_servers[:server_count]
        self.log.info("hostlist_servers:  %s", self.hostlist_servers)
        self.log.info("hostlist_clients:  %s", self.hostlist_clients)

        # Find a configuration that meets the test requirements
        self.config = Configuration(
            self.params, self.hostlist_servers, debug=self.debug)
        if not self.config.set_config(self):
            self.cancel("Test requirements not met!")

        # If a specific count is specified, verify enough servers/clients are
        # specified to satisy the count
        host_count_checks = (
            ("server", server_count,
             len(self.hostlist_servers) if self.hostlist_servers else 0),
            ("client", client_count,
             len(self.hostlist_clients) if self.hostlist_clients else 0)
        )
        for host_type, expected_count, actual_count in host_count_checks:
            if expected_count:
                self.assertEqual(
                    expected_count, actual_count,
                    "Test requires {} {}; {} specified".format(
                        expected_count, host_type, actual_count))

        # Start the clients (agents)
        if self.setup_start_agents:
            self.start_agents()

        # Start the servers
        if self.setup_start_servers:
            self.start_servers()

    def start_agents(self, agent_groups=None, servers=None):
        """Start the daos_agent processes.

        Args:
            agent_groups (dict, optional): dictionary of lists of hosts on
                which to start the daos agent using a unquie server group name
                key. Defaults to None which will use the server group name from
                the test's yaml file to start the daos agents on all client
                hosts specified in the test's yaml file.
            servers (list): list of hosts running the doas servers to be used to
                define the access points in the agent yaml config file

        Raises:
            avocado.core.exceptions.TestFail: if there is an error starting the
                agents

        """
        if agent_groups is None:
            agent_groups = {self.server_group: self.hostlist_clients}

        self.log.debug("--- STARTING AGENT GROUPS: %s ---", agent_groups)

        if isinstance(agent_groups, dict):
            for group, hosts in agent_groups.items():
                transport = DaosAgentTransportCredentials()
                # Use the unique agent group name to create a unique yaml file
                config_file = self.get_config_file(group, "agent")
                # Setup the access points with the server hosts
                common_cfg = self.get_common_config(transport, group, servers)
                self.add_agent_manager(config_file, common_cfg)
                self.configure_manager(
                    "agent",
                    self.agent_managers[-1],
                    hosts,
                    self.hostfile_clients_slots)
            self.start_agent_managers()

    def start_servers(self, server_groups=None):
        """Start the daos_server processes.

        Args:
            server_groups (dict, optional): dictionary of lists of hosts on
                which to start the daos server using a unquie server group name
                key. Defaults to None which will use the server group name from
                the test's yaml file to start the daos server on all server
                hosts specified in the test's yaml file.

        Raises:
            avocado.core.exceptions.TestFail: if there is an error starting the
                servers

        """
        if server_groups is None:
            server_groups = {self.server_group: self.hostlist_servers}

        self.log.debug("--- STARTING SERVER GROUPS: %s ---", server_groups)

        if isinstance(server_groups, dict):
            for group, hosts in server_groups.items():
                transport = DaosServerTransportCredentials()
                # Use the unique agent group name to create a unique yaml file
                config_file = self.get_config_file(group, "server")
                # Setup the access points with the server hosts
                common_cfg = self.get_common_config(transport, group, hosts)
                self.add_server_manager(config_file, common_cfg)
                self.configure_manager(
                    "server",
                    self.server_managers[-1],
                    hosts,
                    self.hostfile_servers_slots)
            self.start_server_managers()

    def get_config_file(self, name, command):
        """Get the yaml configuration file.

        Args:
            name (str): unique part of the configuration file name
            command (str): command owning the configuration file

        Returns:
            str: daos_agent yaml configuration file full name

        """
        return os.path.join(self.tmp, "test_{}_{}.yaml".format(name, command))

    def get_common_config(self, transport, group, hosts=None):
        """Get the daos_agent common yaml configuration file parameters.

        Args:
            transport (TransportCredentials): the transport credentials
                configuration parameters
            group (str): server group name
            hosts (list, optional): list of hosts to be used as access points in
                the configuration file. Defaulys to None, which will use all the
                server hosts

        Returns:
            CommonConfig: common yaml configuration file parameters

        """
        if hosts is None:
            hosts = self.hostlist_servers

        common_cfg = CommonConfig(group, transport)
        common_cfg.update_hosts(hosts)
        return common_cfg

    def add_agent_manager(self, config_file=None, common_cfg=None, timeout=60):
        """Add a new daos agent manager object to the agent manager list.

        Args:
            config_file (str, optional): daos agent config file name. Defaults
                to None, which will use a default file name.
            common_cfg (CommonConfig, optional): daos agent config file
                settings shared between the agent and server. Defaults to None,
                which uses the class CommonConfig.
            timeout (int, optional): number of seconds to wait for the daos
                agent to start before reporting an error. Defaults to 60.
        """
        self.log.info("--- ADDING AGENT MANAGER ---")

        # Setup defaults
        if config_file is None:
            config_file = self.get_config_file("daos", "server")
        if common_cfg is None:
            common_cfg = self.get_common_config(
                DaosAgentTransportCredentials(), self.server_group,
                self.hostfile_servers)

        # Create an AgentCommand to manage with a new AgentManager object
        agent_cfg = DaosAgentYamlParameters(config_file, common_cfg)
        if self.agent_log is not None:
            self.log.info(
                "Using a test-specific daos_agent log file: %s",
                self.agent_log)
            agent_cfg.log_file.value = self.agent_log
        agent_cmd = DaosAgentCommand(self.bin, agent_cfg, timeout)
        self.agent_managers.append(DaosAgentManager(self.ompi_bin, agent_cmd))

    def add_server_manager(self, config_file=None, common_cfg=None, timeout=60):
        """Add a new daos server manager object to the server manager list.

        When adding multiple server managers unique yaml config file names
        and common config setting (due to the server group name) should be used.

        Args:
            config_file (str, optional): daos server config file name. Defaults
                to None, which will use a default file name.
            common_cfg (CommonConfig, optional): daos server config file
                settings shared between the agent and server. Defaults to None,
                which uses the class CommonConfig.
            timeout (int, optional): number of seconds to wait for the daos
                server to start before reporting an error. Defaults to 60.
        """
        self.log.info("--- ADDING SERVER MANAGER ---")

        # Setup defaults
        if config_file is None:
            config_file = self.get_config_file("daos", "server")
        if common_cfg is None:
            common_cfg = self.get_common_config(
                DaosServerTransportCredentials(), self.server_group,
                self.hostfile_servers)

        # Create an ServerCommand to manage with a new ServerManager object
        server_cfg = DaosServerYamlParameters(config_file, common_cfg)
        if self.server_log is not None:
            self.log.info(
                "Using a test-specific daos_server log file: %s",
                self.server_log)
            server_cfg.update_server_log_files(self.server_log)
        if self.control_log is not None:
            self.log.info(
                "Using a test-specific daos_server control log file: %s",
                self.control_log)
            server_cfg.update_control_log_file(self.control_log)
        server_cmd = DaosServerCommand(self.bin, server_cfg, timeout)
        self.server_managers.append(
            DaosServerManager(self.ompi_bin, server_cmd))

    def configure_manager(self, name, manager, hosts, slots):
        """Configure the agent/server manager object.

        Defines the environment variables, host list, and hostfile settings used
        to start the agent/server manager.

        Args:
            name (str): manager name
            manager (SubprocessManager): [description]
            hosts (list): list of hosts on which to start the daos agent/server
            slots (int): number of slots per server to define in the hostfile
        """
        self.log.info("--- CONFIGURING %s MANAGER ---", name.upper())
        manager.get_params(self)
        manager.add_environment_list(["PATH"])
        manager.hosts = (hosts, self.workdir, slots)

    @fail_on(CommandFailure)
    def start_agent_managers(self):
        """Start the daos_agent processes on each specified list of hosts."""
        self.log.info("--- STARTING AGENTS ---")
        self._start_manager_list("agent", self.agent_managers)

    @fail_on(CommandFailure)
    def start_server_managers(self):
        """Start the daos_server processes on each specified list of hosts."""
        self.log.info("--- STARTING SERVERS ---")
        self._start_manager_list("server", self.server_managers)

    def _start_manager_list(self, name, manager_list):
        """Start each manager in the specified list.

        Args:
            name (str): manager name
            manager_list (list): list of SubprocessManager objects to start
        """
        user = getuser()
        # We probalby want to do this parallel if end up with multiple managers
        for manager in manager_list:
            self.log.info(
                "Starting %s: group=%s, hosts=%s, config=%s",
                name, manager.get_config_value("name"), manager.hosts,
                manager.job.yaml.filename)
            manager.verify_socket_directory(user)
            manager.start()

    def tearDown(self):
        """Tear down after each test case."""
        # Destroy any containers first
        errors = self.destroy_containers(self.container)

        # Destroy any pools next
        errors.extend(self.destroy_pools(self.pool))

        # Stop the agents
        errors.extend(self.stop_agents())

        # Stop the servers
        errors.extend(self.stop_servers())

        # Complete tear down actions from the inherited class
        try:
            super(TestWithServers, self).tearDown()
        except OSError as error:
            errors.append(
                "Error running inheritted teardown(): {}".format(error))

        # Fail the test if any errors occurred during tear down
        if errors:
            self.fail(
                "Errors detected during teardown:\n  - {}".format(
                    "\n  - ".join(errors)))

    def destroy_containers(self, containers):
        """Close and destroy one or more containers.

        Args:
            containers (object): a list of or single DaosContainer or
                TestContainer object(s) to destroy

        Returns:
            list: a list of exceptions raised destroying the containers

        """
        error_list = []
        if containers:
            if not isinstance(containers, (list, tuple)):
                containers = [containers]
            self.test_log.info("Destroying containers")
            for container in containers:
                # Only close a container that has been openned by the test
                if not hasattr(container, "opened") or container.opened:
                    try:
                        container.close()
                    except (DaosApiError, TestFail) as error:
                        self.test_log.info("  {}".format(error))
                        error_list.append(
                            "Error closing the container: {}".format(error))

                # Only destroy a container that has been created by the test
                if not hasattr(container, "attached") or container.attached:
                    try:
                        container.destroy()
                    except (DaosApiError, TestFail) as error:
                        self.test_log.info("  {}".format(error))
                        error_list.append(
                            "Error destroying container: {}".format(error))
        return error_list

    def destroy_pools(self, pools):
        """Disconnect and destroy one or more pools.

        Args:
            pools (object): a list of or single DaosPool or TestPool object(s)
                to destroy

        Returns:
            list: a list of exceptions raised destroying the pools

        """
        error_list = []
        if pools:
            if not isinstance(pools, (list, tuple)):
                pools = [pools]
            self.test_log.info("Destroying pools")
            for pool in pools:
                # Only disconnect a pool that has been connected by the test
                if not hasattr(pool, "connected") or pool.connected:
                    try:
                        pool.disconnect()
                    except (DaosApiError, TestFail) as error:
                        self.test_log.info("  {}".format(error))
                        error_list.append(
                            "Error disconnecting pool: {}".format(error))

                # Only destroy a pool that has been created by the test
                if not hasattr(pool, "attached") or pool.attached:
                    try:
                        pool.destroy(1)
                    except (DaosApiError, TestFail) as error:
                        self.test_log.info("  {}".format(error))
                        error_list.append(
                            "Error destroying pool: {}".format(error))
        return error_list

    def stop_agents(self):
        """Stop the daos agents.

        Returns:
            list: a list of exceptions raised stopping the agents

        """
        self.test_log.info(
            "Stopping %s group(s) of agents", len(self.agent_managers))
        return self._stop_managers(self.agent_managers, "agents")

    def stop_servers(self):
        """Stop the daos server and I/O servers.

        Returns:
            list: a list of exceptions raised stopping the servers

        """
        self.test_log.info(
            "Stopping %s group(s) of servers", len(self.server_managers))
        return self._stop_managers(self.server_managers, "servers")

    def _stop_managers(self, managers, name):
        """Stop each manager object in the specified list.

        Args:
            managers (list): list of managers to stop
            name (str): manager list name

        Returns:
            list: a list of exceptions raised stopping the managers

        """
        error_list = []
        if managers:
            for manager in managers:
                try:
                    manager.stop()
                except CommandFailure as error:
                    self.test_log.info("  {}".format(error))
                    error_list.append(
                        "Error stopping {}: {}".format(name, error))
        return error_list

    def update_log_file_names(self, test_name=None):
        """Set unique log file names for agents, servers, and clients.

        Args:
            test_name (str, optional): name of test variant. Defaults to None.
        """
        if test_name:
            self.test_id = test_name

        self.agent_log = os.path.join(
            self.log_dir, "{}_agent_daos.log".format(self.test_id))
        self.server_log = os.path.join(
            self.log_dir, "{}_server_daos.log".format(self.test_id))
        self.control_log = os.path.join(
            self.log_dir, "{}_control_daos.log".format(self.test_id))
        self.client_log = os.path.join(
            self.log_dir, "{}_client_daos.log".format(self.test_id))
