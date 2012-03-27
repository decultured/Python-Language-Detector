// YAY?!?!

#include <Python.h>
#include "language_sample.h"
#include "language_database.h"

static PyObject *LangError;
static LanguageDatabase LangDatabase;

PyObject *lang_identify(PyObject *self, PyObject *args);
PyObject *lang_loadtrigrams(PyObject *self, PyObject *args);

static PyMethodDef LangMethods[] = {
    {"identify",  lang_identify, METH_VARARGS, "Identify a language from a unicode string."},
    {"load",  lang_loadtrigrams, METH_VARARGS, "Load the trigram files from a specified folder."},
    {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC initlanguageIdentifier(void) {
	PyObject *m;
	m = Py_InitModule("languageIdentifier", LangMethods);
	if (m == NULL)
		return;
		
	LangError = PyErr_NewException("languageIdentifier.error", NULL, NULL);
    Py_INCREF(LangError);
    PyModule_AddObject(m, "error", LangError);
}

PyObject *lang_identify(PyObject *self, PyObject *args) {
	int maxTrigrams = 300, maxInputLength = 900;
	const char *inputString;
	int stringSize; 
	if (!PyArg_ParseTuple(args, "s#ii", &inputString, &stringSize, &maxTrigrams, &maxInputLength))
		return NULL;

	LanguageSample *sample = new LanguageSample(&LangDatabase, inputString, maxTrigrams, maxInputLength);
	const char *result = sample->Identify();
	delete sample;
	
	return Py_BuildValue("s", result);
}

PyObject *lang_loadtrigrams(PyObject *self, PyObject *args) {
	const char *pathName;
	int stringSize; 
	if (!PyArg_ParseTuple(args, "s#", &pathName, &stringSize))
		return NULL;

	if (!LangDatabase.LoadAll(pathName)) {
		PyErr_SetString(LangError, "File Loads failed - Directory not found");
		return NULL;
	}
	
	return Py_BuildValue("s", pathName);
}

int main (int argc, char **argv) {
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Add a static module */
    initlanguageIdentifier();
}


