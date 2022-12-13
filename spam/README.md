# Spam

```python
$ make clean
$ make build
$ ipython
Python 3.8.15 (default, Nov 29 2022, 18:19:30)
Type 'copyright', 'credits' or 'license' for more information
IPython 8.7.0 -- An enhanced Interactive Python. Type '?' for help.

In [1]: import spam

In [2]: spam.__file__
Out[2]: '/home/tir/code/miku/nativext/spam/spam.cpython-38-x86_64-linux-gnu.so'

In [3]: spam.system("ls")
build  Makefile  README.md  setup.py  spam.cpython-38-x86_64-linux-gnu.so  spammodule.c
Out[3]: 0
```

Notes on exceptions.

> Exception information is stored in three members of the interpreter’s thread
> state. These are NULL if there is no exception. Otherwise they are the C
> equivalents of the members of the Python tuple returned by sys.exc_info().
> These are the exception type, exception instance, and a traceback object.

Various ways to create an exception in the C API:

* `PyErr_SetString`
* `PyErr_SetFromErrno`
* `PyErr_SetObject`

Helpers:

* `PyErr_Occured`
* `PyErr_Clear`

Specific conditions:

* `PyErr_NoMemory`

Functions, that create object return 0 or positive value for success, NULL or
-1 for failure.

Exceptions:

* `PyExc_ZeroDivisionError`
* `PyExc_IOError`

Find an approriate exception:

* `PyExc_TypeError`, e.g. for a wrong set of args to a function


