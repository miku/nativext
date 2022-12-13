// A fuller example can be found here: https://github.com/python/cpython/blob/main/Modules/xxmodule.c
//
// $ make build
// $ tree build
// [4.0K]  build
// ├── [4.0K]  lib.linux-x86_64-3.8
// │   └── [ 25K]  spam.cpython-38-x86_64-linux-gnu.so
// └── [4.0K]  temp.linux-x86_64-3.8
//     └── [ 19K]  spammodule.o
//
// http://web.mit.edu/people/amliu/vrut/python/ext/parseTuple.html, "s#", length as py_ssize_t not int
#define PY_SSIZE_T_CLEAN
#include <Python.h>

// The self argument points to the module object for module-level functions;
// for a method it would point to the object instance.
//
// The args argument will be a pointer to a Python tuple object containing the
// arguments. Each item of the tuple corresponds to an argument in the call’s
// argument list. The arguments are Python objects — in order to do anything
// with them in our C function we have to convert them to C values. The
// function PyArg_ParseTuple() in the Python API checks the argument types and
// converts them to C values. It uses a template string to determine the
// required types of the arguments as well as the types of the C variables into
// which to store the converted values.
//
// PyArg_ParseTuple() returns true (nonzero) if all arguments have the right
// type and its components have been stored in the variables whose addresses
// are passed. It returns false (zero) if an invalid argument list was passed.
// In the latter case it also raises an appropriate exception so the calling
// function can return NULL immediately (as we saw in the example).
static PyObject* spam_system(PyObject* self, PyObject* args)
{
    const char* command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command)) {
        // PyArg_ParseTuple has already set a PyExc_TypeError, probably
        return NULL;
    }
    sts = system(command);
    return PyLong_FromLong(sts);
}

// Now for some boilerplate. Method table, module definition.

static PyMethodDef SpamMethods[] = {
    // Typically `METH_VARARGS` or `METH_VARARGS | METH_KEYWORDS`
    //
    // The METH_KEYWORDS bit may be set in the third field if keyword arguments
    // should be passed to the function. In this case, the C function should
    // accept a third PyObject * parameter which will be a dictionary of
    // keywords. Would need: https://docs.python.org/3/c-api/arg.html#c.PyArg_ParseTupleAndKeywords
    { "system", spam_system, METH_VARARGS, "Execute a shell command" },
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",
    "An example module", // spam_doc, may be NULL
    -1, // so size of per-interpreter state of the module, or -1 if the module
        // keeps state in global variables.
    SpamMethods
};

// After a successful initialization, "spam" is added to sys.modules
PyMODINIT_FUNC PyInit_spam(void)
{
    return PyModule_Create(&spammodule);
}
