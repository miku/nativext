// Python wrapper around certinfo.
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <curl/curl.h>

static size_t wrfu(void* ptr, size_t size, size_t nmemb, void* stream)
{
    (void)stream;
    (void)ptr;
    return size * nmemb;
}

struct curl_certinfo* certinfo(const char* url)
{
    CURL* curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, wrfu);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        curl_easy_setopt(curl, CURLOPT_CERTINFO, 1L);
        res = curl_easy_perform(curl);
        if (!res) {
            struct curl_certinfo* certinfo;
            res = curl_easy_getinfo(curl, CURLINFO_CERTINFO, &certinfo);
            if (!res && certinfo) {
                return certinfo;
            }
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return NULL;
}

static PyObject* certinfo_dump(PyObject* self, PyObject* args)
{
    const char* url;
    if (!PyArg_ParseTuple(args, "s", &url)) {
        return NULL;
    }
    struct curl_certinfo* ci;
    ci = certinfo(url);
    if (!ci) {
        PyErr_SetString(PyExc_LookupError, "failed to get certinfo");
        return NULL;
    }
    // certs  : list of certs
    // details: rows per cert
    // value  : string row
    PyObject *certs, *details, *value;
    certs = PyList_New(0);
    int i, result; // result, temporary python ops result code
    for (i = 0; i < ci->num_of_certs; i++) {
        struct curl_slist* slist;
        details = PyList_New(0);
        for (slist = ci->certinfo[i]; slist; slist = slist->next) {
            value = PyUnicode_FromString(slist->data);
            result = PyList_Append(details, value);
            if (result != 0) {
                PyErr_SetString(PyExc_RuntimeError, "failed to fetch certinfo");
                return NULL;
            }
        }
        result = PyList_Append(certs, details);
        if (result != 0) {
            PyErr_SetString(PyExc_RuntimeError, "failed to assemble result");
            return NULL;
        }
    }
    return certs;
}

static PyMethodDef certinfoMethods[] = {
    { "dump", certinfo_dump, METH_VARARGS, "Collect certificate info." },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef certinfoModule = {
    PyModuleDef_HEAD_INIT,
    "certinfo",
    "Wrapping curl example.",
    -1,
    certinfoMethods
};

PyMODINIT_FUNC PyInit_certinfo(void)
{
    return PyModule_Create(&certinfoModule);
}
