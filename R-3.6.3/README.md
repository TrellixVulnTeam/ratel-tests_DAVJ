[R](https://cran.r-project.org)
=============

Building R interpreter with Ratel
-----------------------------
### Dependencies:

Depending on which features you want, you may need other libraries. We currently don't install it in our testing environment as it is not necessary. Thus, R interpreter with Ratel is probably not working well when involving a new libraries. Please feel free to contact us if you find any problem in your testing.


### Building and Installing R from Source
**1. Download**

Use the following command(s) to download the latest source code of **R**:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```

**2. Configure**

Go to the target directory like R-3.6.3:
  ```
    $ cd R-3.6.3
  ```
Run the ./configure script. Particularly, we need specifying some influential environment variables like ***CFLAGS=-fPIC CPPFLAGS=-fPIC LDFLAGS=-pie*** to generate the shared object running with **Ratel**:
  ```
    $ MAIN_CFLAGS=-fPIC SHLIB_CFLAGS=-fPIC MAIN_FFLAGS=-fPIC SHLIB_FFLAGS=-fPIC CFLAGS=-fPIC CPPFLAGS=-fPIC MAIN_LDR="-fPIC -pie" ./configure --with-pcre1 --enable-R-shlib --enable-R-static-lib --enable-BLAS-shlib --enable-shared
  ```
**NOTE**: You can surely customize whatever you need in your settings such as ***--prefix=/usr/local/R***, tha same operations as normal, see more by ***./configure --help*** for full options.

**3. Build**

If the configure step was successful, then you can build it:
  ```
    $ make
  ```

**4. Install**

After a successful build you may install the package. This is not needed, but you will have to give **R** the correct location of the modules if you don't (see ./R -h).:
  ```
    $ sudo make install
  ```

How to Run R with Ratel and Measure its Performance Using an R Benchmark Suite?
-----------------------------------
Before the run, you have to configure the **R_HOME**, which can be achieved by the following command:
  ```
    $ export R_HOME=/home/xxx/apps/R-3.6.3
  ```

Then, go to the folder where the shared object of **R** is, check if the interpreter binary works fine in native: 
  ```
    $ ./R --slave --vanilla -f ./../../tests/R-benchmark-25.R
  ```
Lastly, benchmarking **R interpreter** with **Ratel** by popular **R-benchmark-25**:
  ```
    $ ./ratel -- ./R --slave --vanilla -f ./../../tests/R-benchmark-25.R
  ```

-----------------------------------
NOTE: The original source of **R-benchmark-25.R** is at http://r.research.att.com/benchmarks/R-benchmark-25.R.
