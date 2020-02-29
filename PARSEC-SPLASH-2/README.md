[PARSEC-SPLASH-2 Benchmark](https://github.com/connorimes/parsec-3.0)
=======================
The benchmark involved only is a subset of Parsec Benchmark, including 9 individual benchmarks in total, which are extracted conservatively from Parsec and are built into shared objects on a case by case basis. All of them have been successfully tested on the Ratel platform.


Building SPLASH-2 with Ratel
-----------------------------

### Building and Installing SPLASH-2 from Source
**1. Download**

Use the following command(s) to download the latest source code of memcached:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```

**2. Build**

Go to the target directory:
  ```
    $ cd splash-2
  ```
Run the ***build.sh*** script to build all benchmarks in order and to generate the shared object running with **Ratel** in their separate directory:
  ```
    $ ./build.sh make
  ```
**NOTE**: For ease of use and testing, we have contained some influential environment variables like ***CFLAGS=-fPIC CPPFLAGS=-fPIC LDFLAGS=-pie*** in each individual ***makefile***.

To clean all generated files and objects, just run the given command:
  ```
    $ ./build.sh clean
  ```

How to Run SPLASH-2 with Ratel?
-----------------------------------
Go to the ***apps/xxx/run*** directory where each shared object and the dependent inputs are, run it with **Ratel** by the specified parameters:
  ```
    $ ./ratel -- ./barnes 1 < input_1
  ```

Similarly, you can run each with the specified number of threads by customizing your ***input_x*** file referring to the ***input_template*** in the same place and adapting the number in CLI accordingly: 
  ```
    $ ./ratel -- ./water_nsquared <1> < input_<1>
	 
	$ ./ratel -- ./water_spatial <1> < input_<1>
	 
	$ ./ratel -- ./fmm <1> < input_<1>
	  
	$ ./ratel -- ./raytrace -s -p<1> teapot.env
	 
	$ ./ratel -- ./radiosity -batch -room -p <1>
	 
	$ ./ratel -- ./ocean_cp -n258 -p<1> -e1e-07 -r20000 -t28800
	 
	$ ./ratel -- ./ocean_ncp -n258 -p<1> -e1e-07 -r20000 -t28800
	 
	$ ./ratel -- ./volrend <1> head-scaleddown4
  ```

**NOTE**: For more commands, please check [here](http://www-flash.stanford.edu/apps/SPLASH).

-----------------------------------
**NOTE**: See [here](https://parsec.cs.princeton.edu/index.htm) for more about PARSEC.
