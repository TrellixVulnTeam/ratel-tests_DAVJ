[SQLite-Speedtest1 Benchmark](https://github.com/mackyle/sqlite/blob/master/test/speedtest1.c)
=======================

Building SQLite-speeddtest1 for Ratel
-------------------------------------

### Building speedtest1 from Source:

Use the following command(s) to download the latest source code of SQLite-speedtest1:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```
Go to the target directory:
  ```
    $ cd SQLite-3.28.0
  ```
You need to run **make**.
  ```
    $ make
  ```
How to run speedtest1 with Ratel?
-----------------------------------

Run speedtest1 binary with [options] directly with ratel
  ```
    $ ./ratel -- ./speedtest1 --num=100
  ```
Use command **./speedtest1 --help** to know available options. 