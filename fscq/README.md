[FSCQ Benchmark](https://github.com/mit-pdos/fscq)
=======================

Building LFStest for Ratel
-----------------------------

### Building LFStest from Source:

Use the following command(s) to download the latest source code of memcached:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```
Go to the target directory:
  ```
    $ cd fscq/LFStest
  ```
We have already added -pie -fPIC option in the Makefile. So you need to run **make**.
  ```
    $ make
  ```
How to Run LFStest with Ratel?
-----------------------------------
We have provided a **run.sh** file in the folder which runs all the tests with proper parameters. Make sure run.sh has execution permission and you already have ratel, libapp.so and libdynamorio.so in the same folder.
  ```
    $ ./run.sh
  ```
Building single-syscall benchmark for Ratel
-----------------------------

### Building single-syscall from Source:

Use the following command(s) to download the latest source code of memcached:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```
Go to the target directory:
  ```
    $ cd fscq/single-syscall
  ```
We have already added -pie -fPIC option in the Makefile. So you need to run **make**.
  ```
    $ make
  ```
How to Run single-syscall with Ratel?
-----------------------------------
We have provided a **run.sh** file in the folder which runs all the tests with proper parameters. Make sure run.sh has execution permission and you already have ratel, libapp.so and libdynamorio.so in the same folder.
  ```
    $ ./run.sh
  ```