Boost.Python bindings for the Echo Nest Musical Fingerprint
-----------------------------------------------------------

For more information see http://blog.echonest.com/post/545323349/the-echo-nest-musical-fingerprint-enmfp

To compile, get a hold of the Echonest code generator and drop Codegen.h and the appropriate shared library in this directory.

Install libboost-python and python-dev

    g++ -fpic -c -I/usr/include/python2.6 pycodegen.cpp
    g++ -shared -o pycodegen.so pycodegen.o -lpython2.6 -lboost_python -L. -lcodegen.Linux-i686

Then load it up in python:
    LD_LIBRARY_PATH=. python
    >>> import pycodegen
    >>> cg = pycodegen.pycodegen([list of samples], offset)
    >>> codes = cg.getCodes()
