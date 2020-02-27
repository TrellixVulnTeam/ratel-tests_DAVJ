[H2O Application](https://github.com/h2o/h2o)
====================

Building H2O with Ratel
-----------------------------
### Dependencies:

Depending on which features you want, you may need other libraries like libwslay. We currently don't install it in our testing environment as it is not necessary. Thus, H2O with Ratel is probably not working well when involving a new libraries. Please feel free to contact us if you find any problem in your testing.

### Building and Installing H2O from Source
**1. Download**

Use the following command(s) to download the latest source code of H2O:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```
**2. Configure**

Go to the target directory:
  ```
    $ cd h2o-2.2.6
  ```
Before building it, particularly, we need specifying some influential environment variables like ***C_FLAGS=-fPIC CXX_FLAGS=-fPIC LINKER_FLAGS=-pie*** to generate the shared object running with **Ratel**. Here we have added the following flags into CMakeLists.txt:
  ```
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
	SET(CMAKE_EXE_LINKER_FLAGS "-pie" CACHE INTERNAL "" FORCE)
  ```

**3. Build**

Build it using **cmake**:
  ```
    $ cmake ..
  ```
Once a Makefile was generated successfully, then do the **make**:
  ```
    $ make
  ```

**4. Install**

After a successful build you may install the package. This is not needed, but you will have to give H2O the correct location of the modules if you don't (see ./h2o -h).:
  ```
    $ sudo make install
  ```

How to Run H2O with Ratel?
-----------------------------------
Go to the folder where the shared object of **h2o** is, then start the server with **Ratel** without detaching from the console by the command below: 
  ```
    $ ./ratel -- ./h2o -c examples/h2o/h2o-test.conf
  ```
and point your browser to http://127.0.0.1:8081/ to check if it works fine.

**NOTE**: We have contained a ***h2o-test.conf*** in the directory of ***/examples/h2o/***, you can also create your own's. Also note that we here cannot use a relative path like "./../examples/h2o/h2o-test.conf".

To stop the server, return to the command prompt and press ***ctrl-c***.

-----------------------------------
**NOTE**: See [here](https://h2o.examp1e.net) to know for more about H2O.
