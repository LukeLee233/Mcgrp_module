
**Following SWIG solution has been deprecated:**

***

~~In order to generate the proper module which can be generated
by the python you need to do the following steps.~~

    1. $> swig -python -c++ interface.i
    2. $> g++ -c -fPIC (*user defined source file) interface_wrap.c -I \
        /home/luke/anaconda3/pkgs/python-3.7.4-h265db76_1/include/python3.7m
    3. $> g++ -shared interface_wrap.o -o _interface.so

~~Then you can use `import interface` in python readily.~~

~~A tutriol can be found on [Documentation](http://www.swig.org/Doc1.3/Python.html#Python_nn2).~~


***

**pybind11 has been introduced cause better supporting on C++11**

***

A tutriol can be found on [Documentation](https://pybind11.readthedocs.io/en/master/intro.html).

The building process are managed by Makefile.



***

Author: Luke Lee

Date: 2020-3-31 
