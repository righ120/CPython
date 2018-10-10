#include <Python.h>

/*
 * Implements an example function.
 */
PyDoc_STRVAR(superfastcode_example_doc, "example(obj, number)\
\
Example function");

PyObject *superfastcode_example(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
    PyObject *obj = NULL;
    int number = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "obj", "number", NULL };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "Oi", keywords, &obj, &number)) {
        return NULL;
    }

    /* Function implementation starts here */

    if (number < 0) {
        PyErr_SetObject(PyExc_ValueError, obj);
        return NULL;    /* return NULL indicates error */
    }

    Py_RETURN_NONE;
}

/*
 * List of functions to add to superfastcode in exec_superfastcode().
 */
static PyMethodDef superfastcode_functions[] = {
    { "example", (PyCFunction)superfastcode_example, METH_VARARGS | METH_KEYWORDS, superfastcode_example_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize superfastcode. May be called multiple times, so avoid
 * using static state.
 */
int exec_superfastcode(PyObject *module) {
    PyModule_AddFunctions(module, superfastcode_functions);

    PyModule_AddStringConstant(module, "__author__", "Righ");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2018);

    return 0; /* success */
}

/*
 * Documentation for superfastcode.
 */
PyDoc_STRVAR(superfastcode_doc, "The superfastcode module");


static PyModuleDef_Slot superfastcode_slots[] = {
    { Py_mod_exec, exec_superfastcode },
    { 0, NULL }
};

static PyModuleDef superfastcode_def = {
    PyModuleDef_HEAD_INIT,
    "superfastcode",
    superfastcode_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    superfastcode_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_superfastcode() {
    return PyModuleDef_Init(&superfastcode_def);
}
