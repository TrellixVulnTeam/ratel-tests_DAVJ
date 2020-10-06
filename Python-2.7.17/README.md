[Python2](https://www.python.org/downloads/source/)
=============

Building Python2 interpreter with Ratel
-----------------------------
### Dependencies:

Depending on which features you want, you may need other libraries. We currently don't install it in our testing environment as it is not necessary. Thus, R interpreter with Ratel is probably not working well when involving a new libraries. Please feel free to contact us if you find any problem in your testing.


### Building and Installing Python2 from Source
**1. Download**

Use the following command(s) to download the latest source code of **Python2**:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```

**2. Configure**

Go to the target directory like Python-2.7.17:
  ```
    $ cd Python-2.7.17
  ```
Run the ./configure script. Particularly, we need specifying some influential environment variables like ***CFLAGS=-fPIC CPPFLAGS=-fPIC*** to generate the shared object running with **Ratel**:
  ```
    $ CFLAGS=-fPIC CPPFLAGS=-fPIC ./configure --enable-shared
  ```
**NOTE**: You can surely customize whatever you need in your settings such as ***--prefix=/usr/local/python2***, tha same operations as normal, see more by ***./configure --help*** for full options.

**3. Build**

If the configure step was successful, then you can build it:
  ```
    $ make
  ```

**4. Install**

After a successful build you may install the package. This is not needed, but you will have to give **python2** the correct location of the modules if you don't (see ./python -h).:
  ```
    $ sudo make install
  ```

How to Run R with Ratel and Measure its Performance?
-----------------------------------
Before the run, you have to configure the **LD_LIBRARY_PATH**, which can be achieved by the following command:
  ```
    $ export LD_LIBRARY_PATH=/home/xxx/apps/Python-2.7.17
  ```

Then, go to the folder where the shared object of **python** is, check if the interpreter binary works fine in native: 
  ```
    $ ./python ./tests/queue.py
  ```
Now start running **python2 interpreter** with **Ratel**:
  ```
    $ ./ratel -- ./python ./tests/queue.py
  ```
Benchmark **python2 interpreter** with **Ratel** using **pybench**. Go first to **pybench** under the **tests** folder, then run command below:
  ```
    $ ./ratel -- ./../python pybench.py -n 20
  ```

-----------------------------------
NOTE: For more about **pybench**, please check [here](https://pypi.org/project/pybench/).