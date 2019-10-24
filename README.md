# c-to-go
Looking at an interesting C coroutine library.

This project is unfortunately *Nix (Linux, probably MacOS too) only.

### Tooling
This project use the following tools to build itself:
 
  - `GnuMakefile` (or just `make`)
  - `CMake` (version 3.12+ should do it)

### How-to
The build system creates a server executable from the source file called `server`.
This can be run to create an server instance. Once this is running, networking tools such as `telnet` can be used to communicate with the server.
