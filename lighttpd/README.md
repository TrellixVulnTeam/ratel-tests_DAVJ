Lighttpd Application
====================

Building Lighttpd with Ratel
-----------------------------
### Dependencies:

Depending on which features you want, you need other libraries; On most systems you need to install the development version of the library packages, the library itself won't be enough!

On Ubuntu you can also use apt-get to install all build dependencies:
  ```
    $ sudo apt-get build-dep lighttpd
  ```

### Building and Installing Lighttpd from Source
**1. Download**

Use the following command(s) to download the latest source code of Lighttpd:
  ```
    $ git clone https://github.com/ratel-enclave/ratel-tests.git .
  ```
**2. Configure**

Go to the target directory:
  ```
    $ cd lighttpd-1.4.54
  ```
Run the ./configure script. Particularly, we need specifying some influential environment variables like ***CFLAGS=-fPIC CPPFLAGS=-fPIC LDFLAGS=-pie*** to generate the shared object running with **Ratel**:
  ```
    $ CFLAGS=-fPIC CPPFLAGS=-fPIC LDFLAGS=-pie ./configure
  ```
**NOTE**: You can surely customize whatever you need in your settings such as ***--prefix=/usr/local/lighttpd***, tha same operations as normal, see more by ***./configure --help*** for full options.

**3. Build**

If the configure step was successful, then you can build it:
  ```
    $ make
  ```

**4. Install**

After a successful build you may install the package. This is not needed, but you will have to give Lighttpd the correct location of the modules if you don't (see ./lighttpd -h).:
  ```
    $ sudo make install
  ```

How to Run Lighttpd with Ratel?
-----------------------------------
Go to the folder where the shared object of **lighttpd** is, then check if your configuration is OK by the command below: 
  ```
    $ ./lighttpd -t -f lighttpd.conf
  ```
**NOTE**: We have contained a generic ***lighttpd-test.conf*** in the same place with the lighttpd, you can also create your own's.

Now start the server with **Ratel** without detaching from the console:
  ```
    $ ./ratel ./lighttpd -D -f lighttpd.conf
  ```
and point your browser to http://127.0.0.1:3000/ to check if it works fine.

To stop the server, return to the command prompt and press ***ctrl-c***.

**NOTE**: See [here](https://github.com/lighttpd) for more about Lighttpd.