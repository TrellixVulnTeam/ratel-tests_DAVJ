[Python3](https://www.python.org/downloads/source/)
=============

Building Python3 interpreter with Ratel-RIO
-----------------------------
### Dependencies:

Depending on which features you want, you may need other libraries. We currently don't install it in our testing environment as it is not necessary. Thus, R interpreter with Ratel-RIO is probably not working well when involving a new libraries. Please feel free to contact us if you find any problem in your testing.


### Building and Installing Python3 from Source
**1. Download**

Use the following command(s) to download the latest source code of **Python3**:
  ```
    $ git clone https://github.com/cimcs/Ratel-RIO-tests.git .
  ```

**2. Configure**

Go to the target directory like Python-3.8.2:
  ```
    $ cd Python-3.8.2
  ```
Run the ./configure script. Particularly, we need specifying some influential environment variables like ***CFLAGS=-fPIC CPPFLAGS=-fPIC*** to generate the shared object running with **Ratel-RIO**:
  ```
    $ CFLAGS=-fPIC CPPFLAGS=-fPIC ./configure --enable-shared
  ```
**NOTE**: You can surely customize whatever you need in your settings such as ***--prefix=/usr/local/python3***, tha same operations as normal, see more by ***./configure --help*** for full options.

**3. Build**

If the configure step was successful, then you can build it:
  ```
    $ make
  ```

**4. Install**

After a successful build you may install the package. This is not needed, but you will have to give **python3** the correct location of the modules if you don't (see ./python -h).:
  ```
    $ sudo make install
  ```

How to Run R with Ratel-RIO and Measure its Performance?
-----------------------------------
Before the run, you have to configure the **LD_LIBRARY_PATH**, which can be achieved by the following command:
  ```
    $ export LD_LIBRARY_PATH=/home/xxx/apps/Python-3.8.2
  ```

Then, go to the folder where the shared object of **python** is, check if the interpreter binary works fine in native: 
  ```
    $ ./python ./tests/queue.py
  ```
Now start running **python3 interpreter** with **Ratel-RIO**:
  ```
    $ ./ratel -- ./python ./tests/queue.py
  ```

-----------------------------------
NOTE: Benchmarking **python3 interpreter** with **Ratel-RIO** by a benchmark suit is not tested yet for now.
