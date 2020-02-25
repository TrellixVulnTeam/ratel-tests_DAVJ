Iozone Benchmark
=======================

Building Iozone for Ratel
-----------------------------

### Building Iozone from Source:

Use the following command(s) to download the latest source code of memcached:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```
Go to the target directory:
  ```
    $ cd iozone-3.487
  ```
We have already added -pie -fPIC option in the Makefile. So you need to run **make** with the architecture name of your system (which should be AMD64 to support Ratel).
  ```
    $ make linux-AMD64
  ```
How to Run Iozone with Ratel?
-----------------------------------
Just like run other applications with the specified parameters:
  ```
    $ ./ratel -- ./iozone -a -q 4096
  ```
For more iozone running options you can take a look at [here](http://www.iozone.org/docs/IOzone_msword_98.pdf).

**NOTE**: Currently Ratel supports upto 4096 KB of record size without any bugs. For other parametes any value can be chosen.