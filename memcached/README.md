Memcached Application
=======================

Building Memcached with Ratel
-----------------------------
### Dependencies:

Memcached depends on libevent. If you're running an OS installed after 2010 the package provided by your OS should be good enough.

* libevent, https://www.monkey.org/~provos/libevent/ (libevent-dev)

It's very simple. For Debian or Ubuntu:

  ```
    $ sudo apt-get install libevent-dev
  ```

### Building and Installing Memcached from Source:

Use the following command(s) to download the latest source code of memcached:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```
Go to the target directory:
  ```
    $ cd memcached-1.5.20
  ```
Particularly, we need specifying some influential environment variables like ***CFLAGS=-fPIC CPPFLAGS=-fPIC LDFLAGS=-pie*** to generate the shared object running with Ratel:
  ```
    $ CFLAGS=-fPIC CPPFLAGS=-fPIC LDFLAGS=-pie ./configure
  ```
**NOTE**: You can surely customize whatever you need in your settings such as ***--prefix=/usr/local/memcached***, tha same operations as normal.

Then starting building and installing memcached using the commands below:
  ```
    $ make && make test && sudo make install
  ```
**NOTE**: See ./configure --help for full options. SASL support needs some optional additional libraries.

How to Run Memcached with Ratel?
-----------------------------------
Just like run other applications with the specified parameters:
  ```
    $ ./ratel ./memcached -l 127.0.0.1 -p 11211
  ```
Furthermore, you can try to run YCSB to test the memcached with Ratel. Here is example of what looks like:

  Load operations to insert data into memory:
  ```
    $ ./bin/ycsb load memcached -s -threads 100 -P workloads/workloada -p recordcount=100000000 -p operationcount=100000000 -p "memcached.hosts=127.0.0.1" -p "memcached.port=11211"
  ```
  Run operation to read or update the data memcached:
  ```
    $ ./bin/ycsb run memcached -s -threads 100 -P workloads/workloada -p recordcount=100000000 -p operationcount=100000000 -p "memcached.hosts=127.0.0.1" -p "memcached.port=11211"
  ```
**NOTE**: See [here](https://github.com/brianfrankcooper/YCSB) for more about YCSB.