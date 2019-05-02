# DFUSE Overview

Dfuse is a Filesystem-in-Userspace implementation providing a POSIX style filesystem through the standard kernel interfaces to local processes on a node.

## Limitations and known bugs

1. Missing callbacks
 * setattr

This will need changes to dfs to get right, as individual flags/attribures can be set so will need to be co-developed with the dfs backend. 
 * fgetattr
 * readlink
 * symlink

These three should all be simple to implement.
 * rename

This needs to check the DAOS namespace (the value of the ie_dfs pointer) for both the old and new parents are identical, and to return EXDEV if not, otherwise this is easy.
 * ioctl

This only needs to support the interception library, so should return pool/container UUIDs, and a array handle.  Will probably need changes to dfs to convert from oid to array handle.
 * extended attributes
 * Interception library

This needs to be flushed out in three areas, the initial initilisation, so calling daos_init() correctly at startup and being able to attach, the ioctl() to fetch the array handle for forwarded files and do any pool/container connect and finally the dfs_array* calls from within the readv/writev functions.
2. Incomplete implementations
 * readdir
 
The readdir implemtation currently uses a hard-coded number of entries so will only return this many files per directory.  Both libfuse and dfs export a interface which batches entries and uses an anchor/offset to keep track, however there is no way to request that the batch sizes for the two interfaces match.  An easy way would be to use a batch size of 1 for DFS, and simply iterate until the FUSE buffer was full, however this is probably not performant.  
Currently this is implemented as readdir() only so using the inode, with no opendir()/releasedir() callbacks so there is no open directory handle to store the anchor/offset between readdir calls on the same inode, adding a strut would allow saving of state between readdir() calls here as well as avoiding a hash table lookup per readdir() call.  
A proper implentation of readdir() should use readdirplus() to correctly insert returned entires into the inode table allowing for faster retreival later on.

 * Read/Write

These calls both currently work on inodes, not file handles which means there is no open file handle, or open()/release() callbacks.  The effect of this is that dfuse does not get to inspect or check the mode flags to open (permissions checks are done by the kernel) or get to save a fi->hp value, so there needs to be a hash table lookup for each I/O operation.  
For both read() and write() callbacks there are two options that control the data flow into the kernel, and given the size of the buffers these callbacks use this can make a big impact on performance, current dfuse implements the basic version only.
3. Performance considerations
 * Inode lookup

There is a seperate "inode record" hash table which is consulted on every new file, to check if it's been seen before and to allocate it a new inode.  To avoid two hash table searches and possible race conditions this code allocates a struct and a new inode number, then calls find_or_insert(), and frees the struct if the entry is already found.  This means the code will be doing lots of memory allocations which aren't requires and burning through the pid space as it does so.  Pids are 64 bit so this side isn't a concern, but using the "da" code to keep a cache of pre-allocated inode record entries would speed this up considerably.