

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif 
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_24"
#define CYTHON_HEX_VERSION 0x001D18F0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #if defined(PyUnicode_IS_READY)
  #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #else
  #define __Pyx_PyUnicode_READY(op)       (0)
  #endif
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #if defined(PyUnicode_IS_READY) && defined(PyUnicode_GET_SIZE)
  #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03090000
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : ((PyCompactUnicodeObject *)(u))->wstr_length))
  #else
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
  #endif
  #else
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_LENGTH(u))
  #endif
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? ((void)(klass), PyMethod_New(func, self)) : __Pyx_NewRef(func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__decode
#define __PYX_HAVE_API__decode

#ifdef _OPENMP
#include <omp.h>
#endif 

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif



#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else 
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif 
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "decode",
};


struct __pyx_obj_6decode___pyx_scope_struct__object;
struct __pyx_obj_6decode___pyx_scope_struct_1_function;
struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter;
struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function;
struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function;
struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list;
struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr;


struct __pyx_obj_6decode___pyx_scope_struct__object {
  PyObject_HEAD
  PyObject *__pyx_v_consts_walker;
  PyObject *__pyx_v_object_type;
  PyObject *__pyx_v_store_length;
};



struct __pyx_obj_6decode___pyx_scope_struct_1_function {
  PyObject_HEAD
  PyObject *__pyx_v__chr;
  PyObject *__pyx_v_func_pos;
  PyObject *__pyx_v_func_poss;
  PyObject *__pyx_v_function_body;
  PyObject *__pyx_v_function_name;
  PyObject *__pyx_v_open_brackets;
  PyObject *__pyx_v_pattern;
  PyObject *__pyx_v_string;
  PyObject *__pyx_t_0;
  Py_ssize_t __pyx_t_1;
  PyObject *(*__pyx_t_2)(PyObject *);
};



struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter {
  PyObject_HEAD
  PyObject *__pyx_v_root_search;
  PyObject *__pyx_v_self;
};



struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function {
  PyObject_HEAD
  PyObject *__pyx_v_compile;
  PyObject *__pyx_v_exec;
  PyObject *__pyx_v_self;
};



struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function {
  PyObject_HEAD
  PyObject *__pyx_v_compile;
  PyObject *__pyx_v_self;
};



struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list {
  PyObject_HEAD
  PyObject *__pyx_v_const;
};



struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr {
  PyObject_HEAD
  struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *__pyx_outer_scope;
  PyObject *__pyx_v_i;
};




#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name);


static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);


static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);


static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);


#define __Pyx_ArgTypeTest(obj, type, none_allowed, name, exact)\
    ((likely((Py_TYPE(obj) == type) | (none_allowed && (obj == Py_None)))) ? 1 :\
        __Pyx__ArgTypeTest(obj, type, name, exact))
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact);


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_AddObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceAdd(op1, op2) : PyNumber_Add(op1, op2))
#endif


static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname);


static CYTHON_INLINE PyObject *__Pyx_GetAttr(PyObject *, PyObject *);


static CYTHON_INLINE int __Pyx_HasAttr(PyObject *, PyObject *);


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);


#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f)\
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    size_t defaults_size;  // used by FusedFunction for copying defaults
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj)  (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject* op, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *closure,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);


static CYTHON_INLINE PyObject* __Pyx_PyDict_Keys(PyObject* d);


typedef struct {
    PyObject *type;
    PyObject **method_name;
    PyCFunction func;
    PyObject *method;
    int flag;
} __Pyx_CachedCFunction;


static PyObject* __Pyx__CallUnboundCMethod0(__Pyx_CachedCFunction* cfunc, PyObject* self);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_CallUnboundCMethod0(cfunc, self)\
    (likely((cfunc)->func) ?\
        (likely((cfunc)->flag == METH_NOARGS) ?  (*((cfunc)->func))(self, NULL) :\
         (PY_VERSION_HEX >= 0x030600B1 && likely((cfunc)->flag == METH_FASTCALL) ?\
            (PY_VERSION_HEX >= 0x030700A0 ?\
                (*(__Pyx_PyCFunctionFast)(void*)(PyCFunction)(cfunc)->func)(self, &__pyx_empty_tuple, 0) :\
                (*(__Pyx_PyCFunctionFastWithKeywords)(void*)(PyCFunction)(cfunc)->func)(self, &__pyx_empty_tuple, 0, NULL)) :\
          (PY_VERSION_HEX >= 0x030700A0 && (cfunc)->flag == (METH_FASTCALL | METH_KEYWORDS) ?\
            (*(__Pyx_PyCFunctionFastWithKeywords)(void*)(PyCFunction)(cfunc)->func)(self, &__pyx_empty_tuple, 0, NULL) :\
            (likely((cfunc)->flag == (METH_VARARGS | METH_KEYWORDS)) ?  ((*(PyCFunctionWithKeywords)(void*)(PyCFunction)(cfunc)->func)(self, __pyx_empty_tuple, NULL)) :\
               ((cfunc)->flag == METH_VARARGS ?  (*((cfunc)->func))(self, __pyx_empty_tuple) :\
               __Pyx__CallUnboundCMethod0(cfunc, self)))))) :\
        __Pyx__CallUnboundCMethod0(cfunc, self))
#else
#define __Pyx_CallUnboundCMethod0(cfunc, self)  __Pyx__CallUnboundCMethod0(cfunc, self)
#endif


#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key);
#define __Pyx_PyObject_Dict_GetItem(obj, name)\
    (likely(PyDict_CheckExact(obj)) ?\
     __Pyx_PyDict_GetItem(obj, name) : PyObject_GetItem(obj, name))
#else
#define __Pyx_PyDict_GetItem(d, key) PyObject_GetItem(d, key)
#define __Pyx_PyObject_Dict_GetItem(obj, name)  PyObject_GetItem(obj, name)
#endif


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif


#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var, name)  {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif


#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif


static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);


static CYTHON_INLINE PyObject* __Pyx_PyUnicode_Substring(
            PyObject* text, Py_ssize_t start, Py_ssize_t stop);


static CYTHON_INLINE int __Pyx_init_unicode_iteration(
    PyObject* ustring, Py_ssize_t *length, void** data, int *kind);


#include <string.h>


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals);


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals);


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_SubtractObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_SubtractObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceSubtract(op1, op2) : PyNumber_Subtract(op1, op2))
#endif


static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, long intval, long inplace);


#if CYTHON_USE_TYPE_SLOTS
#define __Pyx_PyObject_DelAttrStr(o,n) __Pyx_PyObject_SetAttrStr(o, n, NULL)
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value);
#else
#define __Pyx_PyObject_DelAttrStr(o,n)   PyObject_DelAttr(o,n)
#define __Pyx_PyObject_SetAttrStr(o,n,v) PyObject_SetAttr(o,n,v)
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key);
#else
#define __Pyx_PyObject_GetItem(obj, key)  PyObject_GetItem(obj, key)
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);


#if CYTHON_COMPILING_IN_PYPY
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#elif PY_MAJOR_VERSION < 3
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyString_CheckExact(s)) ? PyUnicode_FromEncodedObject(s, NULL, "strict") :\
        PyObject_Format(s, f))
#elif CYTHON_USE_TYPE_SLOTS
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        likely(PyLong_CheckExact(s)) ? PyLong_Type.tp_str(s) :\
        likely(PyFloat_CheckExact(s)) ? PyFloat_Type.tp_str(s) :\
        PyObject_Format(s, f))
#else
    #define __Pyx_PyObject_FormatSimple(s, f) (\
        likely(PyUnicode_CheckExact(s)) ? (Py_INCREF(s), s) :\
        PyObject_Format(s, f))
#endif


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      Py_UCS4 max_char);


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_ExceptionMatches(err) __Pyx_PyErr_ExceptionMatchesInState(__pyx_tstate, err)
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err);
#else
#define __Pyx_PyErr_ExceptionMatches(err)  PyErr_ExceptionMatches(err)
#endif


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif


#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define __Pyx_HAS_GCC_DIAGNOSTIC
#endif


static PyObject* __Pyx_PyUnicode_BuildFromAscii(Py_ssize_t ulength, char* chars, int clength,
                                                int prepend_sign, char padding_char);


static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_Py_ssize_t(Py_ssize_t value, Py_ssize_t width, char padding_char, char format_char);


#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSwap(type, value, tb)  __Pyx__ExceptionSwap(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb);
#endif


static CYTHON_INLINE int __Pyx_PySequence_ContainsTF(PyObject* item, PyObject* seq, int eq) {
    int result = PySequence_Contains(seq, item);
    return unlikely(result < 0) ? result : (result == (eq == Py_EQ));
}


#if CYTHON_USE_PYTYPE_LOOKUP && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_LookupSpecial(PyObject* obj, PyObject* attr_name) {
    PyObject *res;
    PyTypeObject *tp = Py_TYPE(obj);
#if PY_MAJOR_VERSION < 3
    if (unlikely(PyInstance_Check(obj)))
        return __Pyx_PyObject_GetAttrStr(obj, attr_name);
#endif
    res = _PyType_Lookup(tp, attr_name);
    if (likely(res)) {
        descrgetfunc f = Py_TYPE(res)->tp_descr_get;
        if (!f) {
            Py_INCREF(res);
        } else {
            res = f(res, obj, (PyObject *)tp);
        }
    } else {
        PyErr_SetObject(PyExc_AttributeError, attr_name);
    }
    return res;
}
#else
#define __Pyx_PyObject_LookupSpecial(o,n) __Pyx_PyObject_GetAttrStr(o,n)
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(
        PyObject* obj, Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** py_start, PyObject** py_stop, PyObject** py_slice,
        int has_cstart, int has_cstop, int wraparound);


static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname);


static CYTHON_INLINE int __Pyx_IterFinish(void);


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method);


static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name);


static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index);


static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected);


static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected);


static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void);


static void __Pyx_UnpackTupleError(PyObject *, Py_ssize_t index);


#define __Pyx_unpack_tuple2(tuple, value1, value2, is_tuple, has_known_size, decref_tuple)\
    (likely(is_tuple || PyTuple_Check(tuple)) ?\
        (likely(has_known_size || PyTuple_GET_SIZE(tuple) == 2) ?\
            __Pyx_unpack_tuple2_exact(tuple, value1, value2, decref_tuple) :\
            (__Pyx_UnpackTupleError(tuple, 2), -1)) :\
        __Pyx_unpack_tuple2_generic(tuple, value1, value2, has_known_size, decref_tuple))
static CYTHON_INLINE int __Pyx_unpack_tuple2_exact(
    PyObject* tuple, PyObject** value1, PyObject** value2, int decref_tuple);
static int __Pyx_unpack_tuple2_generic(
    PyObject* tuple, PyObject** value1, PyObject** value2, int has_known_size, int decref_tuple);


static CYTHON_INLINE PyObject* __Pyx_dict_iterator(PyObject* dict, int is_dict, PyObject* method_name,
                                                   Py_ssize_t* p_orig_length, int* p_is_dict);
static CYTHON_INLINE int __Pyx_dict_iter_next(PyObject* dict_or_iter, Py_ssize_t orig_length, Py_ssize_t* ppos,
                                              PyObject** pkey, PyObject** pvalue, PyObject** pitem, int is_dict);


static int __Pyx_CheckKeywordStrings(PyObject *kwdict, const char* function_name, int kw_allowed);


#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
#define __Pyx_SetNameInClass(ns, name, value)\
    (likely(PyDict_CheckExact(ns)) ? _PyDict_SetItem_KnownHash(ns, name, value, ((PyASCIIObject *) name)->hash) : PyObject_SetItem(ns, name, value))
#elif CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_SetNameInClass(ns, name, value)\
    (likely(PyDict_CheckExact(ns)) ? PyDict_SetItem(ns, name, value) : PyObject_SetItem(ns, name, value))
#else
#define __Pyx_SetNameInClass(ns, name, value)  PyObject_SetItem(ns, name, value)
#endif


static PyObject *__Pyx_CalculateMetaclass(PyTypeObject *metaclass, PyObject *bases);


static PyObject *__Pyx_Py3MetaclassPrepare(PyObject *metaclass, PyObject *bases, PyObject *name, PyObject *qualname,
                                           PyObject *mkw, PyObject *modname, PyObject *doc);
static PyObject *__Pyx_Py3ClassCreate(PyObject *metaclass, PyObject *name, PyObject *bases, PyObject *dict,
                                      PyObject *mkw, int calculate_metaclass, int allow_py2_metaclass);


static PyObject* __Pyx_PyExec3(PyObject*, PyObject*, PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyExec2(PyObject*, PyObject*);


#if CYTHON_USE_PYLIST_INTERNALS && CYTHON_ASSUME_SAFE_MACROS
static CYTHON_INLINE int __Pyx_ListComp_Append(PyObject* list, PyObject* x) {
    PyListObject* L = (PyListObject*) list;
    Py_ssize_t len = Py_SIZE(list);
    if (likely(L->allocated > len)) {
        Py_INCREF(x);
        PyList_SET_ITEM(list, len, x);
        __Pyx_SET_SIZE(list, len + 1);
        return 0;
    }
    return PyList_Append(list, x);
}
#else
#define __Pyx_ListComp_Append(L,x) PyList_Append(L,x)
#endif


static CYTHON_INLINE Py_UCS4 __Pyx_PyUnicode_AsPy_UCS4(PyObject*);


#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyObject_Ord(c)\
    (likely(PyUnicode_Check(c)) ? (long)__Pyx_PyUnicode_AsPy_UCS4(c) : __Pyx__PyObject_Ord(c))
#else
#define __Pyx_PyObject_Ord(c) __Pyx__PyObject_Ord(c)
#endif
static long __Pyx__PyObject_Ord(PyObject* c);


#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttrNoDict PyObject_GenericGetAttr
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);


static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);


#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif


typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);


static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);


static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);


static PyObject* __Pyx_Globals(void);


static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);


static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);


#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)


static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg);


typedef PyObject *(*__pyx_coroutine_body_t)(PyObject *, PyThreadState *, PyObject *);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_ExcInfoStruct  _PyErr_StackItem
#else
typedef struct {
    PyObject *exc_type;
    PyObject *exc_value;
    PyObject *exc_traceback;
} __Pyx_ExcInfoStruct;
#endif
typedef struct {
    PyObject_HEAD
    __pyx_coroutine_body_t body;
    PyObject *closure;
    __Pyx_ExcInfoStruct gi_exc_state;
    PyObject *gi_weakreflist;
    PyObject *classobj;
    PyObject *yieldfrom;
    PyObject *gi_name;
    PyObject *gi_qualname;
    PyObject *gi_modulename;
    PyObject *gi_code;
    PyObject *gi_frame;
    int resume_label;
    char is_running;
} __pyx_CoroutineObject;
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
    PyTypeObject *type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
    PyObject *name, PyObject *qualname, PyObject *module_name);
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name);
static CYTHON_INLINE void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *self);
static int __Pyx_Coroutine_clear(PyObject *self);
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value);
static PyObject *__Pyx_Coroutine_Close(PyObject *self);
static PyObject *__Pyx_Coroutine_Throw(PyObject *gen, PyObject *args);
#if CYTHON_USE_EXC_INFO_STACK
#define __Pyx_Coroutine_SwapException(self)
#define __Pyx_Coroutine_ResetAndClearException(self)  __Pyx_Coroutine_ExceptionClear(&(self)->gi_exc_state)
#else
#define __Pyx_Coroutine_SwapException(self) {\
    __Pyx_ExceptionSwap(&(self)->gi_exc_state.exc_type, &(self)->gi_exc_state.exc_value, &(self)->gi_exc_state.exc_traceback);\
    __Pyx_Coroutine_ResetFrameBackpointer(&(self)->gi_exc_state);\
    }
#define __Pyx_Coroutine_ResetAndClearException(self) {\
    __Pyx_ExceptionReset((self)->gi_exc_state.exc_type, (self)->gi_exc_state.exc_value, (self)->gi_exc_state.exc_traceback);\
    (self)->gi_exc_state.exc_type = (self)->gi_exc_state.exc_value = (self)->gi_exc_state.exc_traceback = NULL;\
    }
#endif
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__pyx_tstate, pvalue)
#else
#define __Pyx_PyGen_FetchStopIterationValue(pvalue)\
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, pvalue)
#endif
static int __Pyx_PyGen__FetchStopIterationValue(PyThreadState *tstate, PyObject **pvalue);
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state);


static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code);


static int __Pyx_patch_abc(void);


#define __Pyx_Generator_USED
static PyTypeObject *__pyx_GeneratorType = 0;
#define __Pyx_Generator_CheckExact(obj) (Py_TYPE(obj) == __pyx_GeneratorType)
#define __Pyx_Generator_New(body, code, closure, name, qualname, module_name)\
    __Pyx__Coroutine_New(__pyx_GeneratorType, body, code, closure, name, qualname, module_name)
static PyObject *__Pyx_Generator_Next(PyObject *self);
static int __pyx_Generator_init(void);


static int __Pyx_check_binary_version(void);


static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);



static PyTypeObject *__pyx_ptype_6decode___pyx_scope_struct__object = 0;
static PyTypeObject *__pyx_ptype_6decode___pyx_scope_struct_1_function = 0;
static PyTypeObject *__pyx_ptype_6decode___pyx_scope_struct_2_eval_filter = 0;
static PyTypeObject *__pyx_ptype_6decode___pyx_scope_struct_3_exec_function = 0;
static PyTypeObject *__pyx_ptype_6decode___pyx_scope_struct_4_eval_function = 0;
static PyTypeObject *__pyx_ptype_6decode___pyx_scope_struct_5_bytes_list = 0;
static PyTypeObject *__pyx_ptype_6decode___pyx_scope_struct_6_genexpr = 0;
#define __Pyx_MODULE_NAME "decode"
extern int __pyx_module_is_main_decode;
int __pyx_module_is_main_decode = 0;


static PyObject *__pyx_builtin___import__;
static PyObject *__pyx_builtin_eval;
static PyObject *__pyx_builtin_compile;
static PyObject *__pyx_builtin_staticmethod;
static PyObject *__pyx_builtin_print;
static PyObject *__pyx_builtin_KeyboardInterrupt;
static PyObject *__pyx_builtin_input;
static PyObject *__pyx_builtin_enumerate;
static PyObject *__pyx_builtin_open;
static PyObject *__pyx_builtin_IndexError;
static PyObject *__pyx_builtin_chr;
static PyObject *__pyx_builtin_exit;
static PyObject *__pyx_builtin_UnicodeDecodeError;
static const char __pyx_k_A[] = "A";
static const char __pyx_k_B[] = "B";
static const char __pyx_k_C[] = "C";
static const char __pyx_k_D[] = "D";
static const char __pyx_k_E[] = "E";
static const char __pyx_k_F[] = "F";
static const char __pyx_k_G[] = "G";
static const char __pyx_k_H[] = "H";
static const char __pyx_k_I[] = "I";
static const char __pyx_k_J[] = "J";
static const char __pyx_k_K[] = "K";
static const char __pyx_k_L[] = "L";
static const char __pyx_k_M[] = "M";
static const char __pyx_k_N[] = "N";
static const char __pyx_k_O[] = "O";
static const char __pyx_k_P[] = "P";
static const char __pyx_k_Q[] = "Q";
static const char __pyx_k_R[] = "R";
static const char __pyx_k_S[] = "S";
static const char __pyx_k_T[] = "T";
static const char __pyx_k_U[] = "U";
static const char __pyx_k_V[] = "V";
static const char __pyx_k_W[] = "W";
static const char __pyx_k_X[] = "X";
static const char __pyx_k_Y[] = "Y";
static const char __pyx_k_Z[] = "Z";
static const char __pyx_k_a[] = "a";
static const char __pyx_k_b[] = "b";
static const char __pyx_k_c[] = "c";
static const char __pyx_k_d[] = "d";
static const char __pyx_k_e[] = "e";
static const char __pyx_k_f[] = "f";
static const char __pyx_k_g[] = "g";
static const char __pyx_k_h[] = "h";
static const char __pyx_k_i[] = "i";
static const char __pyx_k_j[] = "j";
static const char __pyx_k_k[] = "k";
static const char __pyx_k_l[] = "l";
static const char __pyx_k_m[] = "m";
static const char __pyx_k_n[] = "n";
static const char __pyx_k_o[] = "o";
static const char __pyx_k_p[] = "p";
static const char __pyx_k_q[] = "q";
static const char __pyx_k_r[] = "r";
static const char __pyx_k_s[] = "(?:[\\s]+)?\\()";
static const char __pyx_k_t[] = "t";
static const char __pyx_k_u[] = "u";
static const char __pyx_k_v[] = "v";
static const char __pyx_k_w[] = "w";
static const char __pyx_k_x[] = "x";
static const char __pyx_k_y[] = "y";
static const char __pyx_k_z[] = "z";
static const char __pyx_k_0b[] = "0b";
static const char __pyx_k_0m[] = " \342\234\223\033[0m";
static const char __pyx_k_PK[] = "PK\003\004";
static const char __pyx_k__4[] = "(";
static const char __pyx_k__5[] = ")";
static const char __pyx_k__8[] = "-";
static const char __pyx_k__9[] = "_";
static const char __pyx_k_io[] = "io";
static const char __pyx_k_os[] = "os";
static const char __pyx_k_py[] = "py";
static const char __pyx_k_rb[] = "rb";
static const char __pyx_k_re[] = "re";
static const char __pyx_k_wb[] = "wb";
static const char __pyx_k_U_2[] = "U\r\r\n";
static const char __pyx_k__11[] = "\r";
static const char __pyx_k__12[] = "";
static const char __pyx_k__15[] = "\n";
static const char __pyx_k__18[] = "\\((.+)\\)";
static const char __pyx_k__23[] = ".";
static const char __pyx_k__24[] = "\343\201\202";
static const char __pyx_k__25[] = "\343\201\203";
static const char __pyx_k__26[] = "\343\201\204";
static const char __pyx_k__27[] = "\343\201\205";
static const char __pyx_k__28[] = "\343\201\206";
static const char __pyx_k__29[] = "\343\201\207";
static const char __pyx_k__30[] = "\343\201\210";
static const char __pyx_k__31[] = "\343\201\211";
static const char __pyx_k__32[] = "\343\201\212";
static const char __pyx_k__33[] = "\343\201\213";
static const char __pyx_k__34[] = "\343\201\214";
static const char __pyx_k__35[] = "\343\201\215";
static const char __pyx_k__36[] = "\343\201\216";
static const char __pyx_k__37[] = "\343\201\217";
static const char __pyx_k__38[] = "\343\201\220";
static const char __pyx_k__39[] = "\343\201\221";
static const char __pyx_k__40[] = "\343\201\222";
static const char __pyx_k__41[] = "\343\201\223";
static const char __pyx_k__42[] = "\343\201\224";
static const char __pyx_k__43[] = "\343\201\225";
static const char __pyx_k__44[] = "\343\201\226";
static const char __pyx_k__45[] = "\343\201\227";
static const char __pyx_k__46[] = "\343\201\230";
static const char __pyx_k__47[] = "\343\201\231";
static const char __pyx_k__48[] = "\343\201\232";
static const char __pyx_k__49[] = "\343\201\233";
static const char __pyx_k__50[] = "\343\201\234";
static const char __pyx_k__51[] = "\343\201\235";
static const char __pyx_k__52[] = "\343\201\237";
static const char __pyx_k__53[] = "\343\201\240";
static const char __pyx_k__54[] = "\343\201\241";
static const char __pyx_k__55[] = "\343\201\242";
static const char __pyx_k__56[] = "\343\201\243";
static const char __pyx_k__57[] = "\343\201\244";
static const char __pyx_k__58[] = "\343\215\277";
static const char __pyx_k__59[] = "\343\203\234";
static const char __pyx_k__60[] = "\343\203\202";
static const char __pyx_k__61[] = "\343\202\266";
static const char __pyx_k__62[] = "\343\203\207";
static const char __pyx_k__63[] = "\343\202\264";
static const char __pyx_k__64[] = "\343\203\215";
static const char __pyx_k__65[] = "\343\203\214";
static const char __pyx_k__66[] = "\343\203\222";
static const char __pyx_k__67[] = "\343\202\265";
static const char __pyx_k__68[] = "\343\203\235";
static const char __pyx_k__69[] = "\343\203\231";
static const char __pyx_k__70[] = "\343\203\270";
static const char __pyx_k__71[] = "\343\203\206";
static const char __pyx_k__72[] = "\343\202\263";
static const char __pyx_k__73[] = "\343\203\272";
static const char __pyx_k__74[] = "\343\203\233";
static const char __pyx_k__75[] = "\343\203\213";
static const char __pyx_k_a_2[] = "a\r\r\n";
static const char __pyx_k_chr[] = "chr";
static const char __pyx_k_doc[] = "__doc__";
static const char __pyx_k_end[] = "end";
static const char __pyx_k_err[] = "err";
static const char __pyx_k_get[] = "get";
static const char __pyx_k_lib[] = "/lib";
static const char __pyx_k_log[] = "log";
static const char __pyx_k_out[] = "out";
static const char __pyx_k_pyc[] = ".pyc";
static const char __pyx_k_s_2[] = "s";
static const char __pyx_k_sys[] = "sys";
static const char __pyx_k_zip[] = "zip";
static const char __pyx_k_0m_2[] = "\033[0m";
static const char __pyx_k_EXIT[] = "EXIT";
static const char __pyx_k_List[] = "List";
static const char __pyx_k_SIZE[] = "SIZE";
static const char __pyx_k_Size[] = "Size";
static const char __pyx_k__109[] = "?";
static const char __pyx_k__110[] = " )";
static const char __pyx_k__111[] = "\003\363\r\n";
static const char __pyx_k_args[] = "args";
static const char __pyx_k_argv[] = "argv";
static const char __pyx_k_cast[] = "cast";
static const char __pyx_k_copy[] = "copy";
static const char __pyx_k_data[] = "data";
static const char __pyx_k_dict[] = "__dict__";
static const char __pyx_k_eval[] = "eval";
static const char __pyx_k_exec[] = "exec";
static const char __pyx_k_exit[] = "exit";
static const char __pyx_k_file[] = "file";
static const char __pyx_k_func[] = "func";
static const char __pyx_k_init[] = "__init__";
static const char __pyx_k_join[] = "join";
static const char __pyx_k_keys[] = "keys";
static const char __pyx_k_kill[] = "kill";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_math[] = "math";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_open[] = "open";
static const char __pyx_k_path[] = "path";
static const char __pyx_k_read[] = "read";
static const char __pyx_k_self[] = "self";
static const char __pyx_k_send[] = "send";
static const char __pyx_k_size[] = "size";
static const char __pyx_k_sqrt[] = "sqrt";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_text[] = "text";
static const char __pyx_k_util[] = "util";
static const char __pyx_k_zlib[] = "zlib";
static const char __pyx_k_1_31m[] = "# \033[1;31m";
static const char __pyx_k_1_32m[] = "# \033[1;32m";
static const char __pyx_k_DEBUG[] = "DEBUG";
static const char __pyx_k_ERROR[] = "ERROR: ";
static const char __pyx_k_bfile[] = "bfile";
static const char __pyx_k_char1[] = "char1";
static const char __pyx_k_char2[] = "char2";
static const char __pyx_k_chr_2[] = "_chr";
static const char __pyx_k_clear[] = "clear";
static const char __pyx_k_close[] = "close";
static const char __pyx_k_const[] = "const";
static const char __pyx_k_enter[] = "__enter__";
static const char __pyx_k_index[] = "index";
static const char __pyx_k_input[] = "input";
static const char __pyx_k_is_in[] = "is_in";
static const char __pyx_k_items[] = "items";
static const char __pyx_k_loads[] = "loads";
static const char __pyx_k_lower[] = "lower";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_pyc_2[] = "pyc";
static const char __pyx_k_split[] = "split";
static const char __pyx_k_start[] = "start";
static const char __pyx_k_strip[] = "strip";
static const char __pyx_k_throw[] = "throw";
static const char __pyx_k_types[] = "types";
static const char __pyx_k_utf_8[] = "utf-8";
static const char __pyx_k_write[] = "write";
static const char __pyx_k_CONFIG[] = "CONFIG";
static const char __pyx_k_Config[] = "Config";
static const char __pyx_k_Syntax[] = "Syntax";
static const char __pyx_k_base16[] = "base16";
static const char __pyx_k_base32[] = "base32";
static const char __pyx_k_base64[] = "base64";
static const char __pyx_k_base85[] = "base85";
static const char __pyx_k_codecs[] = "codecs";
static const char __pyx_k_config[] = "config";
static const char __pyx_k_consts[] = "consts";
static const char __pyx_k_decode[] = "<decode>";
static const char __pyx_k_dict_2[] = "dict";
static const char __pyx_k_eval_f[] = "eval_f";
static const char __pyx_k_exit_2[] = "__exit__";
static const char __pyx_k_filter[] = "filter";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_insert[] = "insert";
static const char __pyx_k_isfile[] = "isfile";
static const char __pyx_k_layers[] = " layers ";
static const char __pyx_k_lstrip[] = "lstrip";
static const char __pyx_k_module[] = "__module__";
static const char __pyx_k_object[] = "object";
static const char __pyx_k_output[] = "output";
static const char __pyx_k_python[] = "python";
static const char __pyx_k_remove[] = "remove";
static const char __pyx_k_return[] = "return";
static const char __pyx_k_source[] = "source";
static const char __pyx_k_string[] = "string";
static const char __pyx_k_syntax[] = "syntax";
static const char __pyx_k_system[] = "system";
static const char __pyx_k_target[] = "target";
static const char __pyx_k_typing[] = "typing";
static const char __pyx_k_Console[] = "Console";
static const char __pyx_k_ERROR_2[] = "ERROR ";
static const char __pyx_k_Process[] = "Process";
static const char __pyx_k_ZipFile[] = "ZipFile";
static const char __pyx_k_actions[] = "actions";
static const char __pyx_k_co_code[] = "co_code";
static const char __pyx_k_codeobj[] = "codeobj";
static const char __pyx_k_compile[] = "compile";
static const char __pyx_k_console[] = "console";
static const char __pyx_k_content[] = "content";
static const char __pyx_k_default[] = "default";
static const char __pyx_k_environ[] = "environ";
static const char __pyx_k_extract[] = "extract";
static const char __pyx_k_findall[] = "findall";
static const char __pyx_k_genexpr[] = "genexpr";
static const char __pyx_k_marshal[] = "marshal";
static const char __pyx_k_modules[] = "modules";
static const char __pyx_k_pattern[] = "pattern";
static const char __pyx_k_prepare[] = "__prepare__";
static const char __pyx_k_replace[] = "replace";
static const char __pyx_k_showast[] = "showast";
static const char __pyx_k_unicode[] = "unicode";
static const char __pyx_k_version[] = "version";
static const char __pyx_k_zip_ref[] = "zip_ref";
static const char __pyx_k_zipfile[] = "zipfile";
static const char __pyx_k_CodeType[] = "CodeType";
static const char __pyx_k_OLD_EVAL[] = "OLD_EVAL";
static const char __pyx_k_OLD_EXEC[] = "OLD_EXEC";
static const char __pyx_k_StringIO[] = "StringIO";
static const char __pyx_k_builtins[] = "builtins";
static const char __pyx_k_bytecode[] = "bytecode";
static const char __pyx_k_commands[] = "commands";
static const char __pyx_k_decode_2[] = "decode";
static const char __pyx_k_encoding[] = "# encoding: ";
static const char __pyx_k_endswith[] = "endswith";
static const char __pyx_k_filename[] = "filename";
static const char __pyx_k_func_pos[] = "func_pos";
static const char __pyx_k_function[] = "function";
static const char __pyx_k_getvalue[] = "getvalue";
static const char __pyx_k_infolist[] = "infolist";
static const char __pyx_k_is_alive[] = "is_alive";
static const char __pyx_k_layers_2[] = "layers";
static const char __pyx_k_psh_team[] = "@psh_team";
static const char __pyx_k_qualname[] = "__qualname__";
static const char __pyx_k_zip_code[] = "zip-code";
static const char __pyx_k_1_32msize[] = "# \033[1;32msize: ";
static const char __pyx_k_COPYRIGHT[] = "COPYRIGHT";
static const char __pyx_k_ENCODEING[] = "ENCODEING";
static const char __pyx_k_File_type[] = "File type ( ";
static const char __pyx_k_b16decode[] = "b16decode";
static const char __pyx_k_b32decode[] = "b32decode";
static const char __pyx_k_b64decode[] = "b64decode";
static const char __pyx_k_b85decode[] = "b85decode";
static const char __pyx_k_bz2_codec[] = "bz2_codec";
static const char __pyx_k_co_consts[] = "co_consts";
static const char __pyx_k_decompile[] = "decompile";
static const char __pyx_k_enumerate[] = "enumerate";
static const char __pyx_k_eval_body[] = "eval_body";
static const char __pyx_k_eval_data[] = "eval_data";
static const char __pyx_k_file_data[] = "file_data";
static const char __pyx_k_file_name[] = "file_name";
static const char __pyx_k_file_type[] = "file_type";
static const char __pyx_k_func_poss[] = "func_poss";
static const char __pyx_k_hash_type[] = "hash_type";
static const char __pyx_k_importlib[] = "importlib";
static const char __pyx_k_in_source[] = "in_source";
static const char __pyx_k_main___py[] = "__main__.py";
static const char __pyx_k_math_sqrt[] = "math-sqrt";
static const char __pyx_k_metaclass[] = "__metaclass__";
static const char __pyx_k_outstream[] = "outstream";
static const char __pyx_k_save_file[] = "save_file";
static const char __pyx_k_show_code[] = "show_code";
static const char __pyx_k_to_string[] = "to_string";
static const char __pyx_k_DEBUG_MODE[] = "DEBUG_MODE";
static const char __pyx_k_IndexError[] = "IndexError";
static const char __pyx_k_algogithom[] = "algogithom";
static const char __pyx_k_builtins_2[] = "__builtins__";
static const char __pyx_k_bytes_list[] = "bytes-list";
static const char __pyx_k_decompress[] = "decompress";
static const char __pyx_k_exceptions[] = "exceptions";
static const char __pyx_k_uncompyle6[] = "uncompyle6";
static const char __pyx_k_zip_code_2[] = "zip_code";
static const char __pyx_k_ALGORITHOMS[] = "ALGORITHOMS";
static const char __pyx_k_OLD_COMPILE[] = "OLD_COMPILE";
static const char __pyx_k_VIRTUAL_ENV[] = "VIRTUAL_ENV";
static const char __pyx_k_custom_data[] = "custom_data";
static const char __pyx_k_eval_filter[] = "eval-filter";
static const char __pyx_k_math_sqrt_2[] = "math_sqrt";
static const char __pyx_k_object_type[] = "object_type";
static const char __pyx_k_rich_syntax[] = "rich.syntax";
static const char __pyx_k_root_search[] = "root_search";
static const char __pyx_k_zlib_base64[] = "zlib-base64";
static const char __pyx_k_1_32mDONE_0m[] = "\n# \033[1;32mDONE \342\234\223\033[0m";
static const char __pyx_k_ERROR_length[] = "ERROR  length ";
static const char __pyx_k_MAGIC_NUMBER[] = "MAGIC_NUMBER";
static const char __pyx_k_bytes_list_2[] = "bytes_list";
static const char __pyx_k_getattribute[] = "__getattribute__";
static const char __pyx_k_machine_code[] = "machine-code";
static const char __pyx_k_rich_console[] = "rich.console";
static const char __pyx_k_staticmethod[] = "staticmethod";
static const char __pyx_k_store_length[] = "store_length";
static const char __pyx_k_tools_decode[] = "/tools/decode";
static const char __pyx_k_total_layers[] = "total_layers";
static const char __pyx_k_MAGIC_NUMBERS[] = "MAGIC_NUMBERS";
static const char __pyx_k_bad_functions[] = "bad_functions";
static const char __pyx_k_consts_walker[] = "consts_walker";
static const char __pyx_k_eval_filter_2[] = "eval_filter";
static const char __pyx_k_eval_function[] = "eval-function";
static const char __pyx_k_exec_function[] = "exec-function";
static const char __pyx_k_function_body[] = "function_body";
static const char __pyx_k_function_name[] = "function_name";
static const char __pyx_k_open_brackets[] = "open_brackets";
static const char __pyx_k_zlib_base64_2[] = "zlib_base64";
static const char __pyx_k_PYTHON_VERSION[] = "PYTHON_VERSION";
static const char __pyx_k_decompile_file[] = "decompile_file";
static const char __pyx_k_file_not_found[] = "# file not found!: ";
static const char __pyx_k_machine_code_2[] = "machine_code";
static const char __pyx_k_show_file_size[] = "show_file_size";
static const char __pyx_k_1_31mstopped_0m[] = "\r# \033[1;31mstopped!\033[0m";
static const char __pyx_k_eval_function_2[] = "eval_function";
static const char __pyx_k_exec_function_2[] = "exec_function";
static const char __pyx_k_multiprocessing[] = "multiprocessing";
static const char __pyx_k_uncompyle6_main[] = "uncompyle6.main";
static const char __pyx_k_ZIP_MAGIC_NUMBER[] = "ZIP_MAGIC_NUMBER";
static const char __pyx_k_abdullah_encrypt[] = "abdullah-encrypt";
static const char __pyx_k_codecs_bz2_codec[] = "codecs-bz2_codec";
static const char __pyx_k_custom_eval_data[] = "_custom_eval_data";
static const char __pyx_k_machine_code_py2[] = "machine-code-py2";
static const char __pyx_k_KeyboardInterrupt[] = "KeyboardInterrupt";
static const char __pyx_k_DecodingAlgorithms[] = "DecodingAlgorithms";
static const char __pyx_k_UnicodeDecodeError[] = "UnicodeDecodeError";
static const char __pyx_k_abdullah_encrypt_2[] = "abdullah_encrypt";
static const char __pyx_k_all_eval_functions[] = "all_eval_functions";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_codecs_bz2_codec_2[] = "codecs_bz2_codec";
static const char __pyx_k_machine_code_py2_2[] = "machine_code_py2";
static const char __pyx_k_decoding_algorithms[] = "decoding_algorithms";
static const char __pyx_k_CodeSearchAlgorithms[] = "CodeSearchAlgorithms";
static const char __pyx_k_Exception_exceptions[] = "Exception: exceptions:";
static const char __pyx_k_len_all_eval_functions[] = " == len(all_eval_functions):";
static const char __pyx_k_DecodingAlgorithms_zlib[] = "DecodingAlgorithms.zlib";
static const char __pyx_k_DecodingAlgorithms___init[] = "DecodingAlgorithms.__init__";
static const char __pyx_k_DecodingAlgorithms_base16[] = "DecodingAlgorithms.base16";
static const char __pyx_k_DecodingAlgorithms_base32[] = "DecodingAlgorithms.base32";
static const char __pyx_k_DecodingAlgorithms_base64[] = "DecodingAlgorithms.base64";
static const char __pyx_k_DecodingAlgorithms_base85[] = "DecodingAlgorithms.base85";
static const char __pyx_k_DecodingAlgorithms_marshal[] = "DecodingAlgorithms.marshal";
static const char __pyx_k_Finding_the_best_algorithm[] = "Finding the best algorithm:";
static const char __pyx_k_CodeSearchAlgorithms_object[] = "CodeSearchAlgorithms.object";
static const char __pyx_k_DecodingAlgorithms_zip_code[] = "DecodingAlgorithms.zip_code";
static const char __pyx_k_DecodingAlgorithms_math_sqrt[] = "DecodingAlgorithms.math_sqrt";
static const char __pyx_k_CodeSearchAlgorithms_function[] = "CodeSearchAlgorithms.function";
static const char __pyx_k_DecodingAlgorithms_bytes_list[] = "DecodingAlgorithms.bytes_list";
static const char __pyx_k_1_31mFailed_to_decode_the_file[] = "# \033[1;31mFailed to decode the file!\033[0m";
static const char __pyx_k_DecodingAlgorithms_eval_filter[] = "DecodingAlgorithms.eval_filter";
static const char __pyx_k_DecodingAlgorithms_zlib_base64[] = "DecodingAlgorithms.zlib_base64";
static const char __pyx_k_1_33mcan_t_show_the_code_becaus[] = "# \033[1;33mcan't show the code because the file is to big!\033[0m";
static const char __pyx_k_Decoded_by_HackerMode_tool_Copy[] = "\n# Decoded by HackerMode tool...\n# Copyright: PSH-TEAM\n# Follow us on telegram ( @psh_team )\n";
static const char __pyx_k_DecodingAlgorithms_machine_code[] = "DecodingAlgorithms.machine_code";
static const char __pyx_k_Press_enter_to_continue_or_n_to[] = "Press [enter] to continue\nor [n] to stop\n: ";
static const char __pyx_k_psh_team_developer_mode_total_l[] = "@psh_team <developer mode> total layers: ";
static const char __pyx_k_CodeSearchAlgorithms_object_loca[] = "CodeSearchAlgorithms.object.<locals>.consts_walker";
static const char __pyx_k_DecodingAlgorithms_abdullah_encr[] = "DecodingAlgorithms.abdullah_encrypt";
static const char __pyx_k_DecodingAlgorithms_bytes_list_lo[] = "DecodingAlgorithms.bytes_list.<locals>.genexpr";
static const char __pyx_k_DecodingAlgorithms_codecs_bz2_co[] = "DecodingAlgorithms.codecs_bz2_codec";
static const char __pyx_k_DecodingAlgorithms_eval_filter_l[] = "DecodingAlgorithms.eval_filter.<locals>.root_search";
static const char __pyx_k_DecodingAlgorithms_eval_function[] = "DecodingAlgorithms.eval_function.<locals>.eval";
static const char __pyx_k_DecodingAlgorithms_exec_function[] = "DecodingAlgorithms.exec_function.<locals>.exec";
static const char __pyx_k_USAGE_decode_file_py_output_py_d[] = "USAGE:\n decode file.py output.py\n decode file.py output.py @psh_team";
static const char __pyx_k_DecodingAlgorithms_machine_code_2[] = "DecodingAlgorithms.machine_code_py2";
static const char __pyx_k_DecodingAlgorithms_eval_function_2[] = "DecodingAlgorithms.eval_function.<locals>.compile";
static const char __pyx_k_DecodingAlgorithms_eval_function_3[] = "DecodingAlgorithms.eval_function.<locals>.print";
static const char __pyx_k_DecodingAlgorithms_eval_function_4[] = "DecodingAlgorithms.eval_function.<locals>.input";
static const char __pyx_k_DecodingAlgorithms_eval_function_5[] = "DecodingAlgorithms.eval_function.<locals>.exit";
static const char __pyx_k_DecodingAlgorithms_eval_function_6[] = "DecodingAlgorithms.eval_function.<locals>.builtins";
static const char __pyx_k_DecodingAlgorithms_eval_function_7[] = "DecodingAlgorithms.eval_function.<locals>.builtins.exec";
static const char __pyx_k_DecodingAlgorithms_eval_function_8[] = "DecodingAlgorithms.eval_function.<locals>.builtins.compile";
static const char __pyx_k_DecodingAlgorithms_eval_function_9[] = "DecodingAlgorithms.eval_function.<locals>.builtins.exit";
static const char __pyx_k_DecodingAlgorithms_exec_function_2[] = "DecodingAlgorithms.exec_function.<locals>.compile";
static const char __pyx_k_DecodingAlgorithms_exec_function_3[] = "DecodingAlgorithms.exec_function.<locals>.print";
static const char __pyx_k_DecodingAlgorithms_exec_function_4[] = "DecodingAlgorithms.exec_function.<locals>.input";
static const char __pyx_k_DecodingAlgorithms_exec_function_5[] = "DecodingAlgorithms.exec_function.<locals>.exit";
static const char __pyx_k_DecodingAlgorithms_exec_function_6[] = "DecodingAlgorithms.exec_function.<locals>.builtins";
static const char __pyx_k_DecodingAlgorithms_exec_function_7[] = "DecodingAlgorithms.exec_function.<locals>.builtins.exec";
static const char __pyx_k_DecodingAlgorithms_exec_function_8[] = "DecodingAlgorithms.exec_function.<locals>.builtins.compile";
static const char __pyx_k_DecodingAlgorithms_exec_function_9[] = "DecodingAlgorithms.exec_function.<locals>.builtins.exit";
static const char __pyx_k_DecodingAlgorithms_eval_function_10[] = "DecodingAlgorithms.eval_function";
static const char __pyx_k_DecodingAlgorithms_exec_function_10[] = "DecodingAlgorithms.exec_function";
static PyObject *__pyx_kp_u_0b;
static PyObject *__pyx_kp_u_0m;
static PyObject *__pyx_kp_u_0m_2;
static PyObject *__pyx_kp_u_1_31m;
static PyObject *__pyx_kp_u_1_31mFailed_to_decode_the_file;
static PyObject *__pyx_kp_u_1_31mstopped_0m;
static PyObject *__pyx_kp_u_1_32m;
static PyObject *__pyx_kp_u_1_32mDONE_0m;
static PyObject *__pyx_kp_u_1_32msize;
static PyObject *__pyx_kp_u_1_33mcan_t_show_the_code_becaus;
static PyObject *__pyx_n_u_A;
static PyObject *__pyx_n_s_ALGORITHOMS;
static PyObject *__pyx_n_u_B;
static PyObject *__pyx_n_u_C;
static PyObject *__pyx_n_s_CONFIG;
static PyObject *__pyx_n_s_COPYRIGHT;
static PyObject *__pyx_n_s_CodeSearchAlgorithms;
static PyObject *__pyx_n_s_CodeSearchAlgorithms_function;
static PyObject *__pyx_n_s_CodeSearchAlgorithms_object;
static PyObject *__pyx_n_s_CodeSearchAlgorithms_object_loca;
static PyObject *__pyx_n_s_CodeType;
static PyObject *__pyx_n_s_Config;
static PyObject *__pyx_n_s_Console;
static PyObject *__pyx_n_u_D;
static PyObject *__pyx_n_u_DEBUG;
static PyObject *__pyx_n_s_DEBUG_MODE;
static PyObject *__pyx_kp_u_Decoded_by_HackerMode_tool_Copy;
static PyObject *__pyx_n_s_DecodingAlgorithms;
static PyObject *__pyx_n_s_DecodingAlgorithms___init;
static PyObject *__pyx_n_s_DecodingAlgorithms_abdullah_encr;
static PyObject *__pyx_n_s_DecodingAlgorithms_base16;
static PyObject *__pyx_n_s_DecodingAlgorithms_base32;
static PyObject *__pyx_n_s_DecodingAlgorithms_base64;
static PyObject *__pyx_n_s_DecodingAlgorithms_base85;
static PyObject *__pyx_n_s_DecodingAlgorithms_bytes_list;
static PyObject *__pyx_n_s_DecodingAlgorithms_bytes_list_lo;
static PyObject *__pyx_n_s_DecodingAlgorithms_codecs_bz2_co;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_filter;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_filter_l;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_10;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_2;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_3;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_4;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_5;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_6;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_7;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_8;
static PyObject *__pyx_n_s_DecodingAlgorithms_eval_function_9;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_10;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_2;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_3;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_4;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_5;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_6;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_7;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_8;
static PyObject *__pyx_n_s_DecodingAlgorithms_exec_function_9;
static PyObject *__pyx_n_s_DecodingAlgorithms_machine_code;
static PyObject *__pyx_n_s_DecodingAlgorithms_machine_code_2;
static PyObject *__pyx_n_s_DecodingAlgorithms_marshal;
static PyObject *__pyx_n_s_DecodingAlgorithms_math_sqrt;
static PyObject *__pyx_n_s_DecodingAlgorithms_zip_code;
static PyObject *__pyx_n_s_DecodingAlgorithms_zlib;
static PyObject *__pyx_n_s_DecodingAlgorithms_zlib_base64;
static PyObject *__pyx_n_u_E;
static PyObject *__pyx_n_s_ENCODEING;
static PyObject *__pyx_kp_u_ERROR;
static PyObject *__pyx_kp_u_ERROR_2;
static PyObject *__pyx_kp_u_ERROR_length;
static PyObject *__pyx_n_u_EXIT;
static PyObject *__pyx_kp_u_Exception_exceptions;
static PyObject *__pyx_n_u_F;
static PyObject *__pyx_kp_u_File_type;
static PyObject *__pyx_kp_u_Finding_the_best_algorithm;
static PyObject *__pyx_n_u_G;
static PyObject *__pyx_n_u_H;
static PyObject *__pyx_n_u_I;
static PyObject *__pyx_n_s_IndexError;
static PyObject *__pyx_n_u_J;
static PyObject *__pyx_n_u_K;
static PyObject *__pyx_n_s_KeyboardInterrupt;
static PyObject *__pyx_n_u_L;
static PyObject *__pyx_n_s_List;
static PyObject *__pyx_n_u_M;
static PyObject *__pyx_n_s_MAGIC_NUMBER;
static PyObject *__pyx_n_s_MAGIC_NUMBERS;
static PyObject *__pyx_n_u_N;
static PyObject *__pyx_n_u_O;
static PyObject *__pyx_n_s_OLD_COMPILE;
static PyObject *__pyx_n_s_OLD_EVAL;
static PyObject *__pyx_n_s_OLD_EXEC;
static PyObject *__pyx_n_u_P;
static PyObject *__pyx_kp_b_PK;
static PyObject *__pyx_n_s_PYTHON_VERSION;
static PyObject *__pyx_kp_u_Press_enter_to_continue_or_n_to;
static PyObject *__pyx_n_s_Process;
static PyObject *__pyx_n_u_Q;
static PyObject *__pyx_n_u_R;
static PyObject *__pyx_n_u_S;
static PyObject *__pyx_n_s_SIZE;
static PyObject *__pyx_n_s_Size;
static PyObject *__pyx_n_s_StringIO;
static PyObject *__pyx_n_s_Syntax;
static PyObject *__pyx_n_u_T;
static PyObject *__pyx_n_u_U;
static PyObject *__pyx_kp_u_USAGE_decode_file_py_output_py_d;
static PyObject *__pyx_kp_b_U_2;
static PyObject *__pyx_n_s_UnicodeDecodeError;
static PyObject *__pyx_n_u_V;
static PyObject *__pyx_n_u_VIRTUAL_ENV;
static PyObject *__pyx_n_u_W;
static PyObject *__pyx_n_u_X;
static PyObject *__pyx_n_u_Y;
static PyObject *__pyx_n_u_Z;
static PyObject *__pyx_n_s_ZIP_MAGIC_NUMBER;
static PyObject *__pyx_n_s_ZipFile;
static PyObject *__pyx_kp_u__109;
static PyObject *__pyx_kp_u__11;
static PyObject *__pyx_kp_u__110;
static PyObject *__pyx_kp_b__111;
static PyObject *__pyx_kp_u__12;
static PyObject *__pyx_kp_u__15;
static PyObject *__pyx_kp_u__18;
static PyObject *__pyx_kp_u__23;
static PyObject *__pyx_n_u__24;
static PyObject *__pyx_n_u__25;
static PyObject *__pyx_n_u__26;
static PyObject *__pyx_n_u__27;
static PyObject *__pyx_n_u__28;
static PyObject *__pyx_n_u__29;
static PyObject *__pyx_n_u__30;
static PyObject *__pyx_n_u__31;
static PyObject *__pyx_n_u__32;
static PyObject *__pyx_n_u__33;
static PyObject *__pyx_n_u__34;
static PyObject *__pyx_n_u__35;
static PyObject *__pyx_n_u__36;
static PyObject *__pyx_n_u__37;
static PyObject *__pyx_n_u__38;
static PyObject *__pyx_n_u__39;
static PyObject *__pyx_kp_u__4;
static PyObject *__pyx_n_u__40;
static PyObject *__pyx_n_u__41;
static PyObject *__pyx_n_u__42;
static PyObject *__pyx_n_u__43;
static PyObject *__pyx_n_u__44;
static PyObject *__pyx_n_u__45;
static PyObject *__pyx_n_u__46;
static PyObject *__pyx_n_u__47;
static PyObject *__pyx_n_u__48;
static PyObject *__pyx_n_u__49;
static PyObject *__pyx_kp_u__5;
static PyObject *__pyx_n_u__50;
static PyObject *__pyx_n_u__51;
static PyObject *__pyx_n_u__52;
static PyObject *__pyx_n_u__53;
static PyObject *__pyx_n_u__54;
static PyObject *__pyx_n_u__55;
static PyObject *__pyx_n_u__56;
static PyObject *__pyx_n_u__57;
static PyObject *__pyx_kp_u__58;
static PyObject *__pyx_n_u__59;
static PyObject *__pyx_n_u__60;
static PyObject *__pyx_n_u__61;
static PyObject *__pyx_n_u__62;
static PyObject *__pyx_n_u__63;
static PyObject *__pyx_n_u__64;
static PyObject *__pyx_n_u__65;
static PyObject *__pyx_n_u__66;
static PyObject *__pyx_n_u__67;
static PyObject *__pyx_n_u__68;
static PyObject *__pyx_n_u__69;
static PyObject *__pyx_n_u__70;
static PyObject *__pyx_n_u__71;
static PyObject *__pyx_n_u__72;
static PyObject *__pyx_n_u__73;
static PyObject *__pyx_n_u__74;
static PyObject *__pyx_n_u__75;
static PyObject *__pyx_kp_u__8;
static PyObject *__pyx_n_u__9;
static PyObject *__pyx_n_u_a;
static PyObject *__pyx_kp_b_a_2;
static PyObject *__pyx_kp_u_abdullah_encrypt;
static PyObject *__pyx_n_s_abdullah_encrypt_2;
static PyObject *__pyx_n_u_actions;
static PyObject *__pyx_n_s_algogithom;
static PyObject *__pyx_n_s_all_eval_functions;
static PyObject *__pyx_n_s_args;
static PyObject *__pyx_n_s_argv;
static PyObject *__pyx_n_u_b;
static PyObject *__pyx_n_s_b16decode;
static PyObject *__pyx_n_s_b32decode;
static PyObject *__pyx_n_s_b64decode;
static PyObject *__pyx_n_s_b85decode;
static PyObject *__pyx_n_s_bad_functions;
static PyObject *__pyx_n_s_base16;
static PyObject *__pyx_n_u_base16;
static PyObject *__pyx_n_s_base32;
static PyObject *__pyx_n_u_base32;
static PyObject *__pyx_n_s_base64;
static PyObject *__pyx_n_u_base64;
static PyObject *__pyx_n_s_base85;
static PyObject *__pyx_n_u_base85;
static PyObject *__pyx_n_s_bfile;
static PyObject *__pyx_n_s_builtins;
static PyObject *__pyx_n_u_builtins;
static PyObject *__pyx_n_s_builtins_2;
static PyObject *__pyx_n_s_bytecode;
static PyObject *__pyx_kp_u_bytes_list;
static PyObject *__pyx_n_s_bytes_list_2;
static PyObject *__pyx_n_u_bz2_codec;
static PyObject *__pyx_n_u_c;
static PyObject *__pyx_n_s_cast;
static PyObject *__pyx_n_s_char1;
static PyObject *__pyx_n_s_char2;
static PyObject *__pyx_n_s_chr;
static PyObject *__pyx_n_s_chr_2;
static PyObject *__pyx_n_u_clear;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_close;
static PyObject *__pyx_n_u_co_code;
static PyObject *__pyx_n_s_co_consts;
static PyObject *__pyx_n_u_co_consts;
static PyObject *__pyx_n_s_codecs;
static PyObject *__pyx_kp_u_codecs_bz2_codec;
static PyObject *__pyx_n_s_codecs_bz2_codec_2;
static PyObject *__pyx_n_s_codeobj;
static PyObject *__pyx_n_s_commands;
static PyObject *__pyx_n_s_compile;
static PyObject *__pyx_n_u_config;
static PyObject *__pyx_n_s_console;
static PyObject *__pyx_n_s_const;
static PyObject *__pyx_n_s_consts;
static PyObject *__pyx_n_s_consts_walker;
static PyObject *__pyx_n_s_content;
static PyObject *__pyx_n_s_copy;
static PyObject *__pyx_n_s_custom_data;
static PyObject *__pyx_n_s_custom_eval_data;
static PyObject *__pyx_n_u_d;
static PyObject *__pyx_n_s_data;
static PyObject *__pyx_kp_u_decode;
static PyObject *__pyx_kp_s_decode_2;
static PyObject *__pyx_n_s_decoding_algorithms;
static PyObject *__pyx_n_s_decompile;
static PyObject *__pyx_n_s_decompile_file;
static PyObject *__pyx_n_s_decompress;
static PyObject *__pyx_n_s_default;
static PyObject *__pyx_n_s_dict;
static PyObject *__pyx_n_u_dict_2;
static PyObject *__pyx_n_s_doc;
static PyObject *__pyx_n_s_e;
static PyObject *__pyx_n_u_e;
static PyObject *__pyx_kp_u_encoding;
static PyObject *__pyx_n_s_end;
static PyObject *__pyx_n_s_endswith;
static PyObject *__pyx_n_s_enter;
static PyObject *__pyx_n_s_enumerate;
static PyObject *__pyx_n_s_environ;
static PyObject *__pyx_n_s_err;
static PyObject *__pyx_n_s_eval;
static PyObject *__pyx_n_u_eval;
static PyObject *__pyx_n_s_eval_body;
static PyObject *__pyx_n_s_eval_data;
static PyObject *__pyx_n_s_eval_f;
static PyObject *__pyx_kp_u_eval_filter;
static PyObject *__pyx_n_s_eval_filter_2;
static PyObject *__pyx_kp_u_eval_function;
static PyObject *__pyx_n_s_eval_function_2;
static PyObject *__pyx_n_s_exceptions;
static PyObject *__pyx_n_s_exec;
static PyObject *__pyx_n_u_exec;
static PyObject *__pyx_kp_u_exec_function;
static PyObject *__pyx_n_s_exec_function_2;
static PyObject *__pyx_n_s_exit;
static PyObject *__pyx_n_s_exit_2;
static PyObject *__pyx_n_s_extract;
static PyObject *__pyx_n_s_f;
static PyObject *__pyx_n_u_f;
static PyObject *__pyx_n_s_file;
static PyObject *__pyx_n_s_file_data;
static PyObject *__pyx_n_s_file_name;
static PyObject *__pyx_kp_u_file_not_found;
static PyObject *__pyx_n_s_file_type;
static PyObject *__pyx_n_s_filename;
static PyObject *__pyx_n_u_filter;
static PyObject *__pyx_n_s_findall;
static PyObject *__pyx_n_s_func;
static PyObject *__pyx_n_s_func_pos;
static PyObject *__pyx_n_s_func_poss;
static PyObject *__pyx_n_s_function;
static PyObject *__pyx_n_s_function_body;
static PyObject *__pyx_n_s_function_name;
static PyObject *__pyx_n_u_g;
static PyObject *__pyx_n_s_genexpr;
static PyObject *__pyx_n_s_get;
static PyObject *__pyx_n_s_getattribute;
static PyObject *__pyx_n_s_getvalue;
static PyObject *__pyx_n_u_h;
static PyObject *__pyx_n_s_hash_type;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_u_i;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_importlib;
static PyObject *__pyx_n_s_in_source;
static PyObject *__pyx_n_s_index;
static PyObject *__pyx_n_s_infolist;
static PyObject *__pyx_n_s_init;
static PyObject *__pyx_n_s_input;
static PyObject *__pyx_n_s_insert;
static PyObject *__pyx_n_s_io;
static PyObject *__pyx_n_s_is_alive;
static PyObject *__pyx_n_s_is_in;
static PyObject *__pyx_n_s_isfile;
static PyObject *__pyx_n_s_items;
static PyObject *__pyx_n_u_j;
static PyObject *__pyx_n_s_join;
static PyObject *__pyx_n_u_k;
static PyObject *__pyx_n_s_keys;
static PyObject *__pyx_n_s_kill;
static PyObject *__pyx_n_u_l;
static PyObject *__pyx_kp_u_layers;
static PyObject *__pyx_n_s_layers_2;
static PyObject *__pyx_kp_u_len_all_eval_functions;
static PyObject *__pyx_kp_u_lib;
static PyObject *__pyx_n_s_loads;
static PyObject *__pyx_n_s_log;
static PyObject *__pyx_n_s_lower;
static PyObject *__pyx_n_s_lstrip;
static PyObject *__pyx_n_u_m;
static PyObject *__pyx_kp_u_machine_code;
static PyObject *__pyx_n_s_machine_code_2;
static PyObject *__pyx_kp_u_machine_code_py2;
static PyObject *__pyx_n_s_machine_code_py2_2;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_u_main;
static PyObject *__pyx_kp_u_main___py;
static PyObject *__pyx_n_s_marshal;
static PyObject *__pyx_n_u_marshal;
static PyObject *__pyx_n_s_math;
static PyObject *__pyx_kp_u_math_sqrt;
static PyObject *__pyx_n_s_math_sqrt_2;
static PyObject *__pyx_n_s_metaclass;
static PyObject *__pyx_n_s_module;
static PyObject *__pyx_n_s_modules;
static PyObject *__pyx_n_s_multiprocessing;
static PyObject *__pyx_n_u_n;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_u_o;
static PyObject *__pyx_n_s_object;
static PyObject *__pyx_n_s_object_type;
static PyObject *__pyx_n_s_open;
static PyObject *__pyx_n_s_open_brackets;
static PyObject *__pyx_n_s_os;
static PyObject *__pyx_n_s_out;
static PyObject *__pyx_n_s_output;
static PyObject *__pyx_n_s_outstream;
static PyObject *__pyx_n_s_p;
static PyObject *__pyx_n_u_p;
static PyObject *__pyx_n_s_path;
static PyObject *__pyx_n_s_pattern;
static PyObject *__pyx_n_s_prepare;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_kp_u_psh_team;
static PyObject *__pyx_kp_u_psh_team_developer_mode_total_l;
static PyObject *__pyx_n_u_py;
static PyObject *__pyx_kp_u_pyc;
static PyObject *__pyx_n_u_pyc_2;
static PyObject *__pyx_n_u_python;
static PyObject *__pyx_n_u_q;
static PyObject *__pyx_n_s_qualname;
static PyObject *__pyx_n_u_r;
static PyObject *__pyx_n_u_rb;
static PyObject *__pyx_n_s_re;
static PyObject *__pyx_n_s_read;
static PyObject *__pyx_n_s_remove;
static PyObject *__pyx_n_s_replace;
static PyObject *__pyx_n_s_return;
static PyObject *__pyx_n_s_rich_console;
static PyObject *__pyx_n_s_rich_syntax;
static PyObject *__pyx_n_s_root_search;
static PyObject *__pyx_kp_u_s;
static PyObject *__pyx_n_u_s_2;
static PyObject *__pyx_n_s_save_file;
static PyObject *__pyx_n_s_self;
static PyObject *__pyx_n_s_send;
static PyObject *__pyx_n_s_show_code;
static PyObject *__pyx_n_s_show_file_size;
static PyObject *__pyx_n_s_showast;
static PyObject *__pyx_n_s_size;
static PyObject *__pyx_n_u_size;
static PyObject *__pyx_n_s_source;
static PyObject *__pyx_n_s_split;
static PyObject *__pyx_n_s_sqrt;
static PyObject *__pyx_n_s_start;
static PyObject *__pyx_n_s_staticmethod;
static PyObject *__pyx_n_s_store_length;
static PyObject *__pyx_n_s_string;
static PyObject *__pyx_n_u_string;
static PyObject *__pyx_n_s_strip;
static PyObject *__pyx_n_s_syntax;
static PyObject *__pyx_n_s_sys;
static PyObject *__pyx_n_s_system;
static PyObject *__pyx_n_u_t;
static PyObject *__pyx_n_s_target;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_u_text;
static PyObject *__pyx_n_s_throw;
static PyObject *__pyx_n_s_to_string;
static PyObject *__pyx_kp_u_tools_decode;
static PyObject *__pyx_n_s_total_layers;
static PyObject *__pyx_n_s_types;
static PyObject *__pyx_n_s_typing;
static PyObject *__pyx_n_u_u;
static PyObject *__pyx_n_s_uncompyle6;
static PyObject *__pyx_n_s_uncompyle6_main;
static PyObject *__pyx_n_u_unicode;
static PyObject *__pyx_kp_u_utf_8;
static PyObject *__pyx_n_s_util;
static PyObject *__pyx_n_u_v;
static PyObject *__pyx_n_s_version;
static PyObject *__pyx_n_u_w;
static PyObject *__pyx_n_u_wb;
static PyObject *__pyx_n_s_write;
static PyObject *__pyx_n_u_x;
static PyObject *__pyx_n_u_y;
static PyObject *__pyx_n_u_z;
static PyObject *__pyx_n_u_zip;
static PyObject *__pyx_kp_u_zip_code;
static PyObject *__pyx_n_s_zip_code_2;
static PyObject *__pyx_n_s_zip_ref;
static PyObject *__pyx_n_s_zipfile;
static PyObject *__pyx_n_s_zlib;
static PyObject *__pyx_n_u_zlib;
static PyObject *__pyx_kp_u_zlib_base64;
static PyObject *__pyx_n_s_zlib_base64_2;
static PyObject *__pyx_pf_6decode_20CodeSearchAlgorithms_6object_consts_walker(PyObject *__pyx_self, PyObject *__pyx_v_consts); 
static PyObject *__pyx_pf_6decode_20CodeSearchAlgorithms_object(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_string, PyObject *__pyx_v_object_type); 
static PyObject *__pyx_pf_6decode_20CodeSearchAlgorithms_2function(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_string, PyObject *__pyx_v_function_name); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_file_data, PyObject *__pyx_v_save_file, PyObject *__pyx_v_hash_type); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_11eval_filter_root_search(PyObject *__pyx_self, PyObject *__pyx_v_all_eval_functions); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_2eval_filter(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_4zlib(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_6zlib_base64(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_8codecs_bz2_codec(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_10base16(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_12base32(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_14base64(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_16base85(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_18marshal(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_20machine_code(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_22machine_code_py2(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_24zip_code(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_26abdullah_encrypt(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_exec(PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_2compile(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_4print(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_6input(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_exec(PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_2compile(PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_4exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_28exec_function(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_eval(PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_2compile(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_4print(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_6input(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_exec(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_2compile(PyObject *__pyx_self, PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_4exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_30eval_function(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_10bytes_list_genexpr(PyObject *__pyx_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_32bytes_list(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_34math_sqrt(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyObject *__pyx_pf_6decode_to_string(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_data); 
static PyObject *__pyx_pf_6decode_2data(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_filename); 
static PyObject *__pyx_pf_6decode_4show_code(CYTHON_UNUSED PyObject *__pyx_self); 
static PyObject *__pyx_pf_6decode_6show_file_size(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_file); 
static PyObject *__pyx_tp_new_6decode___pyx_scope_struct__object(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_1_function(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_2_eval_filter(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_3_exec_function(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_4_eval_function(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_5_bytes_list(PyTypeObject *t, PyObject *a, PyObject *k); 
static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_6_genexpr(PyTypeObject *t, PyObject *a, PyObject *k); 
static __Pyx_CachedCFunction __pyx_umethod_PyDict_Type_keys = {0, &__pyx_n_s_keys, 0, 0, 0};
static PyObject *__pyx_float_3_8;
static PyObject *__pyx_float_3_9;
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_2;
static PyObject *__pyx_int_4;
static PyObject *__pyx_int_10;
static PyObject *__pyx_int_16;
static PyObject *__pyx_tuple_;
static PyObject *__pyx_tuple__6;
static PyObject *__pyx_tuple__7;
static PyObject *__pyx_slice__21;
static PyObject *__pyx_slice__22;
static PyObject *__pyx_tuple__10;
static PyObject *__pyx_tuple__13;
static PyObject *__pyx_tuple__14;
static PyObject *__pyx_tuple__16;
static PyObject *__pyx_tuple__17;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__76;
static PyObject *__pyx_tuple__78;
static PyObject *__pyx_tuple__80;
static PyObject *__pyx_tuple__82;
static PyObject *__pyx_tuple__84;
static PyObject *__pyx_tuple__86;
static PyObject *__pyx_tuple__88;
static PyObject *__pyx_tuple__90;
static PyObject *__pyx_tuple__92;
static PyObject *__pyx_tuple__94;
static PyObject *__pyx_tuple__96;
static PyObject *__pyx_tuple__98;
static PyObject *__pyx_codeobj__2;
static PyObject *__pyx_codeobj__3;
static PyObject *__pyx_slice__108;
static PyObject *__pyx_tuple__100;
static PyObject *__pyx_tuple__102;
static PyObject *__pyx_tuple__104;
static PyObject *__pyx_tuple__106;
static PyObject *__pyx_tuple__112;
static PyObject *__pyx_tuple__113;
static PyObject *__pyx_tuple__115;
static PyObject *__pyx_tuple__116;
static PyObject *__pyx_tuple__118;
static PyObject *__pyx_tuple__120;
static PyObject *__pyx_tuple__122;
static PyObject *__pyx_tuple__124;
static PyObject *__pyx_tuple__126;
static PyObject *__pyx_tuple__128;
static PyObject *__pyx_tuple__130;
static PyObject *__pyx_tuple__132;
static PyObject *__pyx_tuple__134;
static PyObject *__pyx_tuple__136;
static PyObject *__pyx_tuple__138;
static PyObject *__pyx_tuple__140;
static PyObject *__pyx_tuple__142;
static PyObject *__pyx_tuple__144;
static PyObject *__pyx_tuple__146;
static PyObject *__pyx_tuple__148;
static PyObject *__pyx_tuple__150;
static PyObject *__pyx_tuple__152;
static PyObject *__pyx_tuple__154;
static PyObject *__pyx_tuple__155;
static PyObject *__pyx_tuple__157;
static PyObject *__pyx_tuple__159;
static PyObject *__pyx_tuple__161;
static PyObject *__pyx_tuple__162;
static PyObject *__pyx_tuple__163;
static PyObject *__pyx_tuple__164;
static PyObject *__pyx_tuple__165;
static PyObject *__pyx_codeobj__20;
static PyObject *__pyx_codeobj__77;
static PyObject *__pyx_codeobj__79;
static PyObject *__pyx_codeobj__81;
static PyObject *__pyx_codeobj__83;
static PyObject *__pyx_codeobj__85;
static PyObject *__pyx_codeobj__87;
static PyObject *__pyx_codeobj__89;
static PyObject *__pyx_codeobj__91;
static PyObject *__pyx_codeobj__93;
static PyObject *__pyx_codeobj__95;
static PyObject *__pyx_codeobj__97;
static PyObject *__pyx_codeobj__99;
static PyObject *__pyx_codeobj__101;
static PyObject *__pyx_codeobj__103;
static PyObject *__pyx_codeobj__105;
static PyObject *__pyx_codeobj__107;
static PyObject *__pyx_codeobj__114;
static PyObject *__pyx_codeobj__117;
static PyObject *__pyx_codeobj__119;
static PyObject *__pyx_codeobj__121;
static PyObject *__pyx_codeobj__123;
static PyObject *__pyx_codeobj__125;
static PyObject *__pyx_codeobj__127;
static PyObject *__pyx_codeobj__129;
static PyObject *__pyx_codeobj__131;
static PyObject *__pyx_codeobj__133;
static PyObject *__pyx_codeobj__135;
static PyObject *__pyx_codeobj__137;
static PyObject *__pyx_codeobj__139;
static PyObject *__pyx_codeobj__141;
static PyObject *__pyx_codeobj__143;
static PyObject *__pyx_codeobj__145;
static PyObject *__pyx_codeobj__147;
static PyObject *__pyx_codeobj__149;
static PyObject *__pyx_codeobj__151;
static PyObject *__pyx_codeobj__153;
static PyObject *__pyx_codeobj__156;
static PyObject *__pyx_codeobj__158;
static PyObject *__pyx_codeobj__160;





static PyObject *__pyx_pw_6decode_20CodeSearchAlgorithms_1object(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_20CodeSearchAlgorithms_1object = {"object", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_20CodeSearchAlgorithms_1object, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_20CodeSearchAlgorithms_1object(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_string = 0;
  PyObject *__pyx_v_object_type = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("object (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_string,&__pyx_n_s_object_type,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_string)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_object_type)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("object", 1, 2, 2, 1); __PYX_ERR(0, 72, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "object") < 0)) __PYX_ERR(0, 72, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_string = ((PyObject*)values[0]);
    __pyx_v_object_type = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("object", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 72, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("decode.CodeSearchAlgorithms.object", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_string), (&PyUnicode_Type), 1, "string", 1))) __PYX_ERR(0, 72, __pyx_L1_error)
  __pyx_r = __pyx_pf_6decode_20CodeSearchAlgorithms_object(__pyx_self, __pyx_v_string, __pyx_v_object_type);

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_20CodeSearchAlgorithms_6object_1consts_walker(PyObject *__pyx_self, PyObject *__pyx_v_consts); 
static PyMethodDef __pyx_mdef_6decode_20CodeSearchAlgorithms_6object_1consts_walker = {"consts_walker", (PyCFunction)__pyx_pw_6decode_20CodeSearchAlgorithms_6object_1consts_walker, METH_O, 0};
static PyObject *__pyx_pw_6decode_20CodeSearchAlgorithms_6object_1consts_walker(PyObject *__pyx_self, PyObject *__pyx_v_consts) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("consts_walker (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_20CodeSearchAlgorithms_6object_consts_walker(__pyx_self, ((PyObject *)__pyx_v_consts));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_20CodeSearchAlgorithms_6object_consts_walker(PyObject *__pyx_self, PyObject *__pyx_v_consts) {
  struct __pyx_obj_6decode___pyx_scope_struct__object *__pyx_cur_scope;
  struct __pyx_obj_6decode___pyx_scope_struct__object *__pyx_outer_scope;
  CYTHON_UNUSED PyObject *__pyx_v_index = NULL;
  PyObject *__pyx_v_const = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *(*__pyx_t_4)(PyObject *);
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  Py_ssize_t __pyx_t_7;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("consts_walker", 0);
  __pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct__object *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  
  __Pyx_INCREF(__pyx_int_0);
  __pyx_t_1 = __pyx_int_0;
  if (likely(PyList_CheckExact(__pyx_v_consts)) || PyTuple_CheckExact(__pyx_v_consts)) {
    __pyx_t_2 = __pyx_v_consts; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
    __pyx_t_4 = NULL;
  } else {
    __pyx_t_3 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_v_consts); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 77, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_4)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_5 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_5); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 77, __pyx_L1_error)
        #else
        __pyx_t_5 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 77, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        #endif
      } else {
        if (__pyx_t_3 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_5 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_5); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 77, __pyx_L1_error)
        #else
        __pyx_t_5 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 77, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        #endif
      }
    } else {
      __pyx_t_5 = __pyx_t_4(__pyx_t_2);
      if (unlikely(!__pyx_t_5)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 77, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_5);
    }
    __Pyx_XDECREF_SET(__pyx_v_const, __pyx_t_5);
    __pyx_t_5 = 0;
    __Pyx_INCREF(__pyx_t_1);
    __Pyx_XDECREF_SET(__pyx_v_index, __pyx_t_1);
    __pyx_t_5 = __Pyx_PyInt_AddObjC(__pyx_t_1, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1);
    __pyx_t_1 = __pyx_t_5;
    __pyx_t_5 = 0;

    
    if (unlikely(!__pyx_cur_scope->__pyx_v_object_type)) { __Pyx_RaiseClosureNameError("object_type"); __PYX_ERR(0, 78, __pyx_L1_error) }
    __pyx_t_5 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_const)), __pyx_cur_scope->__pyx_v_object_type, Py_EQ); __Pyx_XGOTREF(__pyx_t_5); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 78, __pyx_L1_error)
    __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 78, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (__pyx_t_6) {

      
      if (unlikely(!__pyx_cur_scope->__pyx_v_store_length)) { __Pyx_RaiseClosureNameError("store_length"); __PYX_ERR(0, 79, __pyx_L1_error) }
      if (unlikely(__pyx_cur_scope->__pyx_v_store_length == Py_None)) {
        PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
        __PYX_ERR(0, 79, __pyx_L1_error)
      }
      __pyx_t_7 = PyObject_Length(__pyx_v_const); if (unlikely(__pyx_t_7 == ((Py_ssize_t)-1))) __PYX_ERR(0, 79, __pyx_L1_error)
      __pyx_t_5 = PyInt_FromSsize_t(__pyx_t_7); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 79, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (unlikely(PyDict_SetItem(__pyx_cur_scope->__pyx_v_store_length, __pyx_t_5, __pyx_v_const) < 0)) __PYX_ERR(0, 79, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

      
      goto __pyx_L5;
    }

    
    __pyx_t_6 = __Pyx_HasAttr(__pyx_v_const, __pyx_n_u_co_consts); if (unlikely(__pyx_t_6 == ((int)-1))) __PYX_ERR(0, 80, __pyx_L1_error)
    __pyx_t_8 = (__pyx_t_6 != 0);
    if (__pyx_t_8) {

      
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_const, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 81, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (unlikely(!__pyx_cur_scope->__pyx_v_consts_walker)) { __Pyx_RaiseClosureNameError("consts_walker"); __PYX_ERR(0, 81, __pyx_L1_error) }
      __pyx_t_9 = __pyx_pf_6decode_20CodeSearchAlgorithms_6object_consts_walker(__pyx_cur_scope->__pyx_v_consts_walker, __pyx_t_5); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 81, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

      
    }
    __pyx_L5:;

    
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("decode.CodeSearchAlgorithms.object.consts_walker", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_index);
  __Pyx_XDECREF(__pyx_v_const);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_6decode_20CodeSearchAlgorithms_object(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_string, PyObject *__pyx_v_object_type) {
  struct __pyx_obj_6decode___pyx_scope_struct__object *__pyx_cur_scope;
  PyObject *__pyx_v_codeobj = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("object", 0);
  __pyx_cur_scope = (struct __pyx_obj_6decode___pyx_scope_struct__object *)__pyx_tp_new_6decode___pyx_scope_struct__object(__pyx_ptype_6decode___pyx_scope_struct__object, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct__object *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 72, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_object_type = __pyx_v_object_type;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_object_type);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_object_type);

  
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 73, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_string);
  __Pyx_GIVEREF(__pyx_v_string);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_string);
  __Pyx_INCREF(__pyx_kp_u_decode);
  __Pyx_GIVEREF(__pyx_kp_u_decode);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_kp_u_decode);
  __Pyx_INCREF(__pyx_n_u_exec);
  __Pyx_GIVEREF(__pyx_n_u_exec);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_n_u_exec);
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_1, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 73, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_codeobj = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 74, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_cur_scope->__pyx_v_store_length = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_20CodeSearchAlgorithms_6object_1consts_walker, 0, __pyx_n_s_CodeSearchAlgorithms_object_loca, ((PyObject*)__pyx_cur_scope), __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__2)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_cur_scope->__pyx_v_consts_walker = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_codeobj, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __pyx_pf_6decode_20CodeSearchAlgorithms_6object_consts_walker(__pyx_cur_scope->__pyx_v_consts_walker, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 83, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyDict_Keys(__pyx_cur_scope->__pyx_v_store_length); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PySequence_List(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_1 = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_4 = PyList_Sort(__pyx_t_1); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(0, 84, __pyx_L1_error)
  if (unlikely(__pyx_t_1 == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
    __PYX_ERR(0, 84, __pyx_L1_error)
  }
  __pyx_t_3 = __Pyx_GetItemInt_List(__pyx_t_1, -1L, long, 1, __Pyx_PyInt_From_long, 1, 1, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_GetItem(__pyx_cur_scope->__pyx_v_store_length, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("decode.CodeSearchAlgorithms.object", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_codeobj);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_6decode_20CodeSearchAlgorithms_4generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 




static PyObject *__pyx_pw_6decode_20CodeSearchAlgorithms_3function(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_20CodeSearchAlgorithms_3function = {"function", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_20CodeSearchAlgorithms_3function, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_20CodeSearchAlgorithms_3function(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_string = 0;
  PyObject *__pyx_v_function_name = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("function (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_string,&__pyx_n_s_function_name,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_string)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_function_name)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("function", 1, 2, 2, 1); __PYX_ERR(0, 87, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "function") < 0)) __PYX_ERR(0, 87, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_string = ((PyObject*)values[0]);
    __pyx_v_function_name = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("function", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 87, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("decode.CodeSearchAlgorithms.function", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_string), (&PyUnicode_Type), 1, "string", 1))) __PYX_ERR(0, 87, __pyx_L1_error)
  __pyx_r = __pyx_pf_6decode_20CodeSearchAlgorithms_2function(__pyx_self, __pyx_v_string, __pyx_v_function_name);

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_20CodeSearchAlgorithms_2function(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_string, PyObject *__pyx_v_function_name) {
  struct __pyx_obj_6decode___pyx_scope_struct_1_function *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("function", 0);
  __pyx_cur_scope = (struct __pyx_obj_6decode___pyx_scope_struct_1_function *)__pyx_tp_new_6decode___pyx_scope_struct_1_function(__pyx_ptype_6decode___pyx_scope_struct_1_function, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_1_function *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 87, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_string = __pyx_v_string;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_string);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_string);
  __pyx_cur_scope->__pyx_v_function_name = __pyx_v_function_name;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_function_name);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_function_name);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_6decode_20CodeSearchAlgorithms_4generator, __pyx_codeobj__3, (PyObject *) __pyx_cur_scope, __pyx_n_s_function, __pyx_n_s_CodeSearchAlgorithms_function, __pyx_kp_s_decode_2); if (unlikely(!gen)) __PYX_ERR(0, 87, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("decode.CodeSearchAlgorithms.function", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_6decode_20CodeSearchAlgorithms_4generator(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_6decode___pyx_scope_struct_1_function *__pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_1_function *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  int __pyx_t_7;
  PyObject *(*__pyx_t_8)(PyObject *);
  Py_ssize_t __pyx_t_9;
  Py_ssize_t __pyx_t_10;
  Py_ssize_t __pyx_t_11;
  void *__pyx_t_12;
  int __pyx_t_13;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("function", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    case 1: goto __pyx_L11_resume_from_yield;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 87, __pyx_L1_error)

  
  __pyx_t_1 = PyNumber_Add(__pyx_kp_u__4, __pyx_cur_scope->__pyx_v_function_name); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_s); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (!(likely(PyUnicode_CheckExact(__pyx_t_2))||((__pyx_t_2) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_2)->tp_name), 0))) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_cur_scope->__pyx_v_pattern = ((PyObject*)__pyx_t_2);
  __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_re); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_findall); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 89, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = NULL;
  __pyx_t_4 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
      __pyx_t_4 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_cur_scope->__pyx_v_pattern, __pyx_cur_scope->__pyx_v_string};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 89, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_GOTREF(__pyx_t_2);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_1, __pyx_cur_scope->__pyx_v_pattern, __pyx_cur_scope->__pyx_v_string};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_4, 2+__pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 89, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_GOTREF(__pyx_t_2);
  } else
  #endif
  {
    __pyx_t_5 = PyTuple_New(2+__pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 89, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (__pyx_t_1) {
      __Pyx_GIVEREF(__pyx_t_1); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1); __pyx_t_1 = NULL;
    }
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_pattern);
    __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_pattern);
    PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_4, __pyx_cur_scope->__pyx_v_pattern);
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_string);
    __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_string);
    PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_4, __pyx_cur_scope->__pyx_v_string);
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 89, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_GIVEREF(__pyx_t_2);
  __pyx_cur_scope->__pyx_v_func_poss = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __pyx_t_6 = PyObject_Length(__pyx_cur_scope->__pyx_v_func_poss); if (unlikely(__pyx_t_6 == ((Py_ssize_t)-1))) __PYX_ERR(0, 90, __pyx_L1_error)
  __pyx_t_7 = ((__pyx_t_6 < 0) != 0);
  if (unlikely(__pyx_t_7)) {

    
    __pyx_t_2 = __Pyx_PyObject_CallNoArg(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0]))); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 91, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_Raise(__pyx_t_2, 0, 0, 0);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __PYX_ERR(0, 91, __pyx_L1_error)

    
  }

  
  if (likely(PyList_CheckExact(__pyx_cur_scope->__pyx_v_func_poss)) || PyTuple_CheckExact(__pyx_cur_scope->__pyx_v_func_poss)) {
    __pyx_t_2 = __pyx_cur_scope->__pyx_v_func_poss; __Pyx_INCREF(__pyx_t_2); __pyx_t_6 = 0;
    __pyx_t_8 = NULL;
  } else {
    __pyx_t_6 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_cur_scope->__pyx_v_func_poss); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 92, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_8 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 92, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_8)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_3); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 92, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 92, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      } else {
        if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_3); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 92, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 92, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      }
    } else {
      __pyx_t_3 = __pyx_t_8(__pyx_t_2);
      if (unlikely(!__pyx_t_3)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 92, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_3);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_func_pos);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_func_pos, __pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_3);
    __pyx_t_3 = 0;

    
    if (unlikely(__pyx_cur_scope->__pyx_v_string == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
      __PYX_ERR(0, 93, __pyx_L1_error)
    }
    if (unlikely(__pyx_cur_scope->__pyx_v_string == Py_None)) {
      PyErr_Format(PyExc_AttributeError, "'NoneType' object has no attribute '%.30s'", "find");
      __PYX_ERR(0, 93, __pyx_L1_error)
    }
    __pyx_t_9 = PyUnicode_Find(__pyx_cur_scope->__pyx_v_string, __pyx_cur_scope->__pyx_v_func_pos, 0, PY_SSIZE_T_MAX, 1); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-2))) __PYX_ERR(0, 93, __pyx_L1_error)
    __pyx_t_3 = PyInt_FromSsize_t(__pyx_t_9); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 93, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_7 = (__pyx_t_3 == Py_None);
    if (__pyx_t_7) {
      __pyx_t_9 = 0;
    } else {
      __pyx_t_10 = __Pyx_PyIndex_AsSsize_t(__pyx_t_3); if (unlikely((__pyx_t_10 == (Py_ssize_t)-1) && PyErr_Occurred())) __PYX_ERR(0, 93, __pyx_L1_error)
      __pyx_t_9 = __pyx_t_10;
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(__pyx_cur_scope->__pyx_v_string == Py_None)) {
      PyErr_Format(PyExc_AttributeError, "'NoneType' object has no attribute '%.30s'", "find");
      __PYX_ERR(0, 93, __pyx_L1_error)
    }
    __pyx_t_10 = PyUnicode_Find(__pyx_cur_scope->__pyx_v_string, __pyx_cur_scope->__pyx_v_func_pos, 0, PY_SSIZE_T_MAX, 1); if (unlikely(__pyx_t_10 == ((Py_ssize_t)-2))) __PYX_ERR(0, 93, __pyx_L1_error)
    __pyx_t_3 = PyInt_FromSsize_t(__pyx_t_10); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 93, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_10 = PyObject_Length(__pyx_cur_scope->__pyx_v_func_pos); if (unlikely(__pyx_t_10 == ((Py_ssize_t)-1))) __PYX_ERR(0, 93, __pyx_L1_error)
    __pyx_t_5 = PyInt_FromSsize_t(__pyx_t_10); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 93, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 93, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_7 = (__pyx_t_1 == Py_None);
    if (__pyx_t_7) {
      __pyx_t_10 = PY_SSIZE_T_MAX;
    } else {
      __pyx_t_11 = __Pyx_PyIndex_AsSsize_t(__pyx_t_1); if (unlikely((__pyx_t_11 == (Py_ssize_t)-1) && PyErr_Occurred())) __PYX_ERR(0, 93, __pyx_L1_error)
      __pyx_t_10 = __pyx_t_11;
    }
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyUnicode_Substring(__pyx_cur_scope->__pyx_v_string, __pyx_t_9, __pyx_t_10); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 93, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_function_body);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_function_body, ((PyObject*)__pyx_t_1));
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;

    
    __Pyx_INCREF(__pyx_int_1);
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_open_brackets);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_open_brackets, __pyx_int_1);
    __Pyx_GIVEREF(__pyx_int_1);

    
    if (unlikely(__pyx_cur_scope->__pyx_v_string == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
      __PYX_ERR(0, 96, __pyx_L1_error)
    }
    if (unlikely(__pyx_cur_scope->__pyx_v_string == Py_None)) {
      PyErr_Format(PyExc_AttributeError, "'NoneType' object has no attribute '%.30s'", "find");
      __PYX_ERR(0, 96, __pyx_L1_error)
    }
    __pyx_t_10 = PyUnicode_Find(__pyx_cur_scope->__pyx_v_string, __pyx_cur_scope->__pyx_v_func_pos, 0, PY_SSIZE_T_MAX, 1); if (unlikely(__pyx_t_10 == ((Py_ssize_t)-2))) __PYX_ERR(0, 96, __pyx_L1_error)
    __pyx_t_1 = PyInt_FromSsize_t(__pyx_t_10); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 96, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_10 = PyObject_Length(__pyx_cur_scope->__pyx_v_func_pos); if (unlikely(__pyx_t_10 == ((Py_ssize_t)-1))) __PYX_ERR(0, 96, __pyx_L1_error)
    __pyx_t_5 = PyInt_FromSsize_t(__pyx_t_10); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 96, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 96, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_7 = (__pyx_t_3 == Py_None);
    if (__pyx_t_7) {
      __pyx_t_10 = 0;
    } else {
      __pyx_t_9 = __Pyx_PyIndex_AsSsize_t(__pyx_t_3); if (unlikely((__pyx_t_9 == (Py_ssize_t)-1) && PyErr_Occurred())) __PYX_ERR(0, 96, __pyx_L1_error)
      __pyx_t_10 = __pyx_t_9;
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyUnicode_Substring(__pyx_cur_scope->__pyx_v_string, __pyx_t_10, PY_SSIZE_T_MAX); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 96, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_13 = __Pyx_init_unicode_iteration(__pyx_t_3, (&__pyx_t_9), (&__pyx_t_12), (&__pyx_t_4)); if (unlikely(__pyx_t_13 == ((int)-1))) __PYX_ERR(0, 96, __pyx_L1_error)
    for (__pyx_t_11 = 0; __pyx_t_11 < __pyx_t_9; __pyx_t_11++) {
      __pyx_t_10 = __pyx_t_11;
      __pyx_t_5 = PyUnicode_FromOrdinal(__Pyx_PyUnicode_READ(__pyx_t_4, __pyx_t_12, __pyx_t_10)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 96, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v__chr);
      __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v__chr, __pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_5);
      __pyx_t_5 = 0;

      
      __pyx_t_7 = (__Pyx_PyUnicode_Equals(__pyx_cur_scope->__pyx_v__chr, __pyx_kp_u__4, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 97, __pyx_L1_error)
      if (__pyx_t_7) {

        
        __pyx_t_5 = __Pyx_PyInt_AddObjC(__pyx_cur_scope->__pyx_v_open_brackets, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 98, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_open_brackets);
        __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_open_brackets, __pyx_t_5);
        __Pyx_GIVEREF(__pyx_t_5);
        __pyx_t_5 = 0;

        
        goto __pyx_L9;
      }

      
      __pyx_t_7 = (__Pyx_PyUnicode_Equals(__pyx_cur_scope->__pyx_v__chr, __pyx_kp_u__5, Py_EQ)); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 99, __pyx_L1_error)
      if (__pyx_t_7) {

        
        __pyx_t_5 = __Pyx_PyInt_SubtractObjC(__pyx_cur_scope->__pyx_v_open_brackets, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 100, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_open_brackets);
        __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_open_brackets, __pyx_t_5);
        __Pyx_GIVEREF(__pyx_t_5);
        __pyx_t_5 = 0;

        
      }
      __pyx_L9:;

      
      __pyx_t_5 = PyNumber_InPlaceAdd(__pyx_cur_scope->__pyx_v_function_body, __pyx_cur_scope->__pyx_v__chr); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 101, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (!(likely(PyUnicode_CheckExact(__pyx_t_5))||((__pyx_t_5) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_5)->tp_name), 0))) __PYX_ERR(0, 101, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_function_body);
      __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_function_body, ((PyObject*)__pyx_t_5));
      __Pyx_GIVEREF(__pyx_t_5);
      __pyx_t_5 = 0;

      
      __pyx_t_5 = __Pyx_PyInt_EqObjC(__pyx_cur_scope->__pyx_v_open_brackets, __pyx_int_0, 0, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 102, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 102, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_7) {

        
        goto __pyx_L8_break;

        
      }
    }
    __pyx_L8_break:;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
    if (unlikely(__pyx_cur_scope->__pyx_v_string == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
      __PYX_ERR(0, 104, __pyx_L1_error)
    }
    if (unlikely(__pyx_cur_scope->__pyx_v_string == Py_None)) {
      PyErr_Format(PyExc_AttributeError, "'NoneType' object has no attribute '%.30s'", "find");
      __PYX_ERR(0, 104, __pyx_L1_error)
    }
    __pyx_t_9 = PyUnicode_Find(__pyx_cur_scope->__pyx_v_string, __pyx_cur_scope->__pyx_v_function_body, 0, PY_SSIZE_T_MAX, 1); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-2))) __PYX_ERR(0, 104, __pyx_L1_error)
    __pyx_t_3 = PyInt_FromSsize_t(__pyx_t_9); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 104, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (unlikely(__pyx_cur_scope->__pyx_v_function_body == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "object of type 'NoneType' has no len()");
      __PYX_ERR(0, 104, __pyx_L1_error)
    }
    __pyx_t_9 = __Pyx_PyUnicode_GET_LENGTH(__pyx_cur_scope->__pyx_v_function_body); if (unlikely(__pyx_t_9 == ((Py_ssize_t)-1))) __PYX_ERR(0, 104, __pyx_L1_error)
    __pyx_t_5 = PyInt_FromSsize_t(__pyx_t_9); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 104, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 104, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_7 = (__pyx_t_1 == Py_None);
    if (__pyx_t_7) {
      __pyx_t_9 = 0;
    } else {
      __pyx_t_10 = __Pyx_PyIndex_AsSsize_t(__pyx_t_1); if (unlikely((__pyx_t_10 == (Py_ssize_t)-1) && PyErr_Occurred())) __PYX_ERR(0, 104, __pyx_L1_error)
      __pyx_t_9 = __pyx_t_10;
    }
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyUnicode_Substring(__pyx_cur_scope->__pyx_v_string, __pyx_t_9, PY_SSIZE_T_MAX); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 104, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_string);
    __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_string, ((PyObject*)__pyx_t_1));
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;

    
    __Pyx_INCREF(__pyx_cur_scope->__pyx_v_function_body);
    __pyx_r = __pyx_cur_scope->__pyx_v_function_body;
    __Pyx_XGIVEREF(__pyx_t_2);
    __pyx_cur_scope->__pyx_t_0 = __pyx_t_2;
    __pyx_cur_scope->__pyx_t_1 = __pyx_t_6;
    __pyx_cur_scope->__pyx_t_2 = __pyx_t_8;
    __Pyx_XGIVEREF(__pyx_r);
    __Pyx_RefNannyFinishContext();
    __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
    
    __pyx_generator->resume_label = 1;
    return __pyx_r;
    __pyx_L11_resume_from_yield:;
    __pyx_t_2 = __pyx_cur_scope->__pyx_t_0;
    __pyx_cur_scope->__pyx_t_0 = 0;
    __Pyx_XGOTREF(__pyx_t_2);
    __pyx_t_6 = __pyx_cur_scope->__pyx_t_1;
    __pyx_t_8 = __pyx_cur_scope->__pyx_t_2;
    if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 105, __pyx_L1_error)

    
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  

  
  PyErr_SetNone(PyExc_StopIteration);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("function", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_1__init__ = {"__init__", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_1__init__, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_1__init__(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_self = 0;
  PyObject *__pyx_v_file_data = 0;
  PyObject *__pyx_v_save_file = 0;
  PyObject *__pyx_v_hash_type = 0;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__init__ (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_self,&__pyx_n_s_file_data,&__pyx_n_s_save_file,&__pyx_n_s_hash_type,0};
    PyObject* values[4] = {0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_self)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_file_data)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, 1); __PYX_ERR(0, 108, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (likely((values[2] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_save_file)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, 2); __PYX_ERR(0, 108, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (likely((values[3] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_hash_type)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, 3); __PYX_ERR(0, 108, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "__init__") < 0)) __PYX_ERR(0, 108, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 4) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
      values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
      values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
    }
    __pyx_v_self = values[0];
    __pyx_v_file_data = values[1];
    __pyx_v_save_file = values[2];
    __pyx_v_hash_type = ((PyObject*)values[3]);
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("__init__", 1, 4, 4, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 108, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("decode.DecodingAlgorithms.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_hash_type), (&PyDict_Type), 1, "hash_type", 1))) __PYX_ERR(0, 108, __pyx_L1_error)
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms___init__(__pyx_self, __pyx_v_self, __pyx_v_file_data, __pyx_v_save_file, __pyx_v_hash_type);

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms___init__(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self, PyObject *__pyx_v_file_data, PyObject *__pyx_v_save_file, PyObject *__pyx_v_hash_type) {
  PyObject *__pyx_v_algogithom = NULL;
  PyObject *__pyx_v_err = NULL;
  PyObject *__pyx_v_layers = 0;
  PyObject *__pyx_v_file = NULL;
  CYTHON_UNUSED PyObject *__pyx_v_e = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  Py_ssize_t __pyx_t_7;
  PyObject *(*__pyx_t_8)(PyObject *);
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  Py_ssize_t __pyx_t_13;
  Py_UCS4 __pyx_t_14;
  int __pyx_t_15;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  int __pyx_t_18;
  char const *__pyx_t_19;
  PyObject *__pyx_t_20 = NULL;
  PyObject *__pyx_t_21 = NULL;
  PyObject *__pyx_t_22 = NULL;
  PyObject *__pyx_t_23 = NULL;
  PyObject *__pyx_t_24 = NULL;
  PyObject *__pyx_t_25 = NULL;
  int __pyx_t_26;
  char const *__pyx_t_27;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__init__", 0);

  
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_file_data, __pyx_v_file_data) < 0) __PYX_ERR(0, 109, __pyx_L1_error)

  
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_hash_type, __pyx_v_hash_type) < 0) __PYX_ERR(0, 110, __pyx_L1_error)

  
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_custom_data, Py_None) < 0) __PYX_ERR(0, 111, __pyx_L1_error)

  
  if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_custom_eval_data, Py_None) < 0) __PYX_ERR(0, 112, __pyx_L1_error)

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_CONFIG); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_get); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyDict_NewPresized(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_cast, ((PyObject*)&PyBool_Type)) < 0) __PYX_ERR(0, 114, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_default, Py_False) < 0) __PYX_ERR(0, 114, __pyx_L1_error)
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__6, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__pyx_t_4) {

    
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_dict); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_n_u_EXIT, __pyx_n_s_lower); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_1 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_1)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_1);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

    
  }

  
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__7, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_ALGORITHOMS); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 118, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (likely(PyList_CheckExact(__pyx_t_3)) || PyTuple_CheckExact(__pyx_t_3)) {
    __pyx_t_5 = __pyx_t_3; __Pyx_INCREF(__pyx_t_5); __pyx_t_7 = 0;
    __pyx_t_8 = NULL;
  } else {
    __pyx_t_7 = -1; __pyx_t_5 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 118, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_8 = Py_TYPE(__pyx_t_5)->tp_iternext; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 118, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  for (;;) {
    if (likely(!__pyx_t_8)) {
      if (likely(PyList_CheckExact(__pyx_t_5))) {
        if (__pyx_t_7 >= PyList_GET_SIZE(__pyx_t_5)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyList_GET_ITEM(__pyx_t_5, __pyx_t_7); __Pyx_INCREF(__pyx_t_3); __pyx_t_7++; if (unlikely(0 < 0)) __PYX_ERR(0, 118, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_5, __pyx_t_7); __pyx_t_7++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 118, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      } else {
        if (__pyx_t_7 >= PyTuple_GET_SIZE(__pyx_t_5)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_5, __pyx_t_7); __Pyx_INCREF(__pyx_t_3); __pyx_t_7++; if (unlikely(0 < 0)) __PYX_ERR(0, 118, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_5, __pyx_t_7); __pyx_t_7++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 118, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      }
    } else {
      __pyx_t_3 = __pyx_t_8(__pyx_t_5);
      if (unlikely(!__pyx_t_3)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 118, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_3);
    }
    __Pyx_XDECREF_SET(__pyx_v_algogithom, __pyx_t_3);
    __pyx_t_3 = 0;

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
      __Pyx_XGOTREF(__pyx_t_9);
      __Pyx_XGOTREF(__pyx_t_10);
      __Pyx_XGOTREF(__pyx_t_11);
       {

        
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_getattribute); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 120, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_algogithom, __pyx_n_s_replace); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 120, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_6);
        __pyx_t_12 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__10, NULL); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 120, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_12);
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __pyx_t_6 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_6)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_6);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_1 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_6, __pyx_t_12) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_12);
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 120, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
          __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
          if (likely(__pyx_t_2)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
            __Pyx_INCREF(__pyx_t_2);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_1, function);
          }
        }
        __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 120, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_file_data, __pyx_t_3) < 0) __PYX_ERR(0, 120, __pyx_L6_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

        
        __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 122, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_13 = 0;
        __pyx_t_14 = 127;
        __Pyx_INCREF(__pyx_kp_u_1_32m);
        __pyx_t_13 += 9;
        __Pyx_GIVEREF(__pyx_kp_u_1_32m);
        PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_1_32m);
        __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_v_algogithom, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 122, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_14;
        __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_t_1);
        __pyx_t_1 = 0;
        __Pyx_INCREF(__pyx_kp_u_0m);
        __pyx_t_14 = (65535 > __pyx_t_14) ? 65535 : __pyx_t_14;
        __pyx_t_13 += 6;
        __Pyx_GIVEREF(__pyx_kp_u_0m);
        PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u_0m);
        __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_3, 3, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 122, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = PyTuple_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 122, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_GIVEREF(__pyx_t_1);
        PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
        __pyx_t_1 = 0;
        __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 122, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_1);
        if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_end, __pyx_kp_u__11) < 0) __PYX_ERR(0, 122, __pyx_L6_error)
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 122, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_type); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 123, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_get); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 123, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_1)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_1);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_1, __pyx_v_algogithom) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_v_algogithom);
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 123, __pyx_L6_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 123, __pyx_L6_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (__pyx_t_4) {

          
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_type); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 124, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_t_2, __pyx_v_algogithom); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 124, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = __Pyx_PyInt_AddObjC(__pyx_t_3, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 124, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_type); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 124, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_3);
          if (unlikely(PyObject_SetItem(__pyx_t_3, __pyx_v_algogithom, __pyx_t_2) < 0)) __PYX_ERR(0, 124, __pyx_L6_error)
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
          goto __pyx_L14;
        }

        
         {
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_type); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 126, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_2);
          if (unlikely(PyObject_SetItem(__pyx_t_2, __pyx_v_algogithom, __pyx_int_1) < 0)) __PYX_ERR(0, 126, __pyx_L6_error)
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        }
        __pyx_L14:;

        
      }
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      goto __pyx_L13_try_end;
      __pyx_L6_error:;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

      
      __pyx_t_15 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
      if (__pyx_t_15) {
        __Pyx_AddTraceback("decode.DecodingAlgorithms.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
        if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_1) < 0) __PYX_ERR(0, 128, __pyx_L8_except_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_INCREF(__pyx_t_3);
        __pyx_v_err = __pyx_t_3;
         {

          
          __Pyx_GetModuleGlobalName(__pyx_t_12, __pyx_n_s_DEBUG_MODE); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 129, __pyx_L20_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_12); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 129, __pyx_L20_error)
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          if (__pyx_t_4) {

            
            __pyx_t_12 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_v_err); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 130, __pyx_L20_error)
            __Pyx_GOTREF(__pyx_t_12);
            __pyx_t_13 = __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12); if (unlikely(__pyx_t_13 == ((Py_ssize_t)-1))) __PYX_ERR(0, 130, __pyx_L20_error)
            __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
            __pyx_t_4 = ((__pyx_t_13 > 0x3E8) != 0);
            if (__pyx_t_4) {

              
              __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_console); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 131, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_6);
              __pyx_t_16 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_log); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 131, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_16);
              __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
              __pyx_t_6 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_v_err); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 131, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_6);
              __pyx_t_13 = __Pyx_PyUnicode_GET_LENGTH(__pyx_t_6); if (unlikely(__pyx_t_13 == ((Py_ssize_t)-1))) __PYX_ERR(0, 131, __pyx_L20_error)
              __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
              __pyx_t_6 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_13, 0, ' ', 'd'); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 131, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_6);
              __pyx_t_17 = __Pyx_PyUnicode_Concat(__pyx_kp_u_ERROR_length, __pyx_t_6); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 131, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_17);
              __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
              __pyx_t_6 = NULL;
              if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_16))) {
                __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_16);
                if (likely(__pyx_t_6)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_16);
                  __Pyx_INCREF(__pyx_t_6);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_16, function);
                }
              }
              __pyx_t_12 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_16, __pyx_t_6, __pyx_t_17) : __Pyx_PyObject_CallOneArg(__pyx_t_16, __pyx_t_17);
              __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
              __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
              if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 131, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_12);
              __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
              __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;

              
              __pyx_t_12 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_v_err); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_12);
              __pyx_t_16 = __Pyx_PyUnicode_Substring(__pyx_t_12, 0, 0xC8); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_16);
              __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
              __pyx_t_12 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_v_err); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_12);
              __pyx_t_17 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_v_err); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_17);
              __pyx_t_13 = __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17); if (unlikely(__pyx_t_13 == ((Py_ssize_t)-1))) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
              __pyx_t_17 = __Pyx_PyUnicode_Substring(__pyx_t_12, (__pyx_t_13 - 0xC8), PY_SSIZE_T_MAX); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_17);
              __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
              __pyx_t_12 = __Pyx_PyUnicode_Concat(__pyx_t_16, __pyx_t_17); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_12);
              __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
              __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
              __pyx_t_17 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_12); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 132, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_17);
              __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
              __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;

              
              goto __pyx_L23;
            }

            
             {
              __pyx_t_17 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_v_err); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 134, __pyx_L20_error)
              __Pyx_GOTREF(__pyx_t_17);
              __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            }
            __pyx_L23:;

            
          }

          
          __pyx_t_17 = PyTuple_New(3); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 135, __pyx_L20_error)
          __Pyx_GOTREF(__pyx_t_17);
          __pyx_t_13 = 0;
          __pyx_t_14 = 127;
          __Pyx_INCREF(__pyx_kp_u_1_31m);
          __pyx_t_13 += 9;
          __Pyx_GIVEREF(__pyx_kp_u_1_31m);
          PyTuple_SET_ITEM(__pyx_t_17, 0, __pyx_kp_u_1_31m);
          __pyx_t_12 = __Pyx_PyObject_FormatSimple(__pyx_v_algogithom, __pyx_empty_unicode); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 135, __pyx_L20_error)
          __Pyx_GOTREF(__pyx_t_12);
          __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_12) : __pyx_t_14;
          __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_12);
          __Pyx_GIVEREF(__pyx_t_12);
          PyTuple_SET_ITEM(__pyx_t_17, 1, __pyx_t_12);
          __pyx_t_12 = 0;
          __Pyx_INCREF(__pyx_kp_u_0m_2);
          __pyx_t_13 += 4;
          __Pyx_GIVEREF(__pyx_kp_u_0m_2);
          PyTuple_SET_ITEM(__pyx_t_17, 2, __pyx_kp_u_0m_2);
          __pyx_t_12 = __Pyx_PyUnicode_Join(__pyx_t_17, 3, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 135, __pyx_L20_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
          __pyx_t_17 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_12); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 135, __pyx_L20_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;

          
          goto __pyx_L17_continue;
        }

        
         {
          __pyx_L20_error:;
          {
            __Pyx_PyThreadState_declare
            __Pyx_PyThreadState_assign
            __pyx_t_20 = 0; __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_25 = 0;
            __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
            __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_23, &__pyx_t_24, &__pyx_t_25);
            if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_20, &__pyx_t_21, &__pyx_t_22) < 0)) __Pyx_ErrFetch(&__pyx_t_20, &__pyx_t_21, &__pyx_t_22);
            __Pyx_XGOTREF(__pyx_t_20);
            __Pyx_XGOTREF(__pyx_t_21);
            __Pyx_XGOTREF(__pyx_t_22);
            __Pyx_XGOTREF(__pyx_t_23);
            __Pyx_XGOTREF(__pyx_t_24);
            __Pyx_XGOTREF(__pyx_t_25);
            __pyx_t_15 = __pyx_lineno; __pyx_t_18 = __pyx_clineno; __pyx_t_19 = __pyx_filename;
            {
              __Pyx_DECREF(__pyx_v_err);
              __pyx_v_err = NULL;
            }
            if (PY_MAJOR_VERSION >= 3) {
              __Pyx_XGIVEREF(__pyx_t_23);
              __Pyx_XGIVEREF(__pyx_t_24);
              __Pyx_XGIVEREF(__pyx_t_25);
              __Pyx_ExceptionReset(__pyx_t_23, __pyx_t_24, __pyx_t_25);
            }
            __Pyx_XGIVEREF(__pyx_t_20);
            __Pyx_XGIVEREF(__pyx_t_21);
            __Pyx_XGIVEREF(__pyx_t_22);
            __Pyx_ErrRestore(__pyx_t_20, __pyx_t_21, __pyx_t_22);
            __pyx_t_20 = 0; __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_25 = 0;
            __pyx_lineno = __pyx_t_15; __pyx_clineno = __pyx_t_18; __pyx_filename = __pyx_t_19;
            goto __pyx_L8_except_error;
          }
          __pyx_L17_continue: {
            __Pyx_DECREF(__pyx_v_err);
            __pyx_v_err = NULL;
            goto __pyx_L16_except_continue;
          }
        }
        __pyx_L16_except_continue:;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        goto __pyx_L12_try_continue;
      }
      goto __pyx_L8_except_error;
      __pyx_L8_except_error:;

      
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_11);
      __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
      goto __pyx_L1_error;
      __pyx_L12_try_continue:;
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_11);
      __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
      goto __pyx_L4_continue;
      __pyx_L13_try_end:;
    }

    
    __pyx_t_4 = (__Pyx_PySequence_ContainsTF(__pyx_n_u_filter, __pyx_v_algogithom, Py_EQ)); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 138, __pyx_L1_error)
    __pyx_t_26 = (__pyx_t_4 != 0);
    if (__pyx_t_26) {

      
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 139, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      
      goto __pyx_L4_continue;

      
    }

    
    __Pyx_INCREF(__pyx_int_0);
    __pyx_v_layers = __pyx_int_0;

    
    while (1) {

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_11, &__pyx_t_10, &__pyx_t_9);
        __Pyx_XGOTREF(__pyx_t_11);
        __Pyx_XGOTREF(__pyx_t_10);
        __Pyx_XGOTREF(__pyx_t_9);
         {

          
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_getattribute); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 145, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_17 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
            __pyx_t_17 = PyMethod_GET_SELF(__pyx_t_2);
            if (likely(__pyx_t_17)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
              __Pyx_INCREF(__pyx_t_17);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_2, function);
            }
          }
          __pyx_t_3 = (__pyx_t_17) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_17, __pyx_v_algogithom) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_algogithom);
          __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 145, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_2)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_2);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 145, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (__Pyx_PyObject_SetAttrStr(__pyx_v_self, __pyx_n_s_file_data, __pyx_t_1) < 0) __PYX_ERR(0, 145, __pyx_L31_error)
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_type); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 146, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_t_1, __pyx_v_algogithom); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyInt_AddObjC(__pyx_t_3, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 146, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_hash_type); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          if (unlikely(PyObject_SetItem(__pyx_t_3, __pyx_v_algogithom, __pyx_t_1) < 0)) __PYX_ERR(0, 146, __pyx_L31_error)
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_1 = __Pyx_PyInt_AddObjC(__pyx_v_layers, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 147, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF_SET(__pyx_v_layers, __pyx_t_1);
          __pyx_t_1 = 0;

          
          __pyx_t_1 = PyTuple_New(5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 148, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_13 = 0;
          __pyx_t_14 = 127;
          __Pyx_INCREF(__pyx_kp_u_1_32m);
          __pyx_t_13 += 9;
          __Pyx_GIVEREF(__pyx_kp_u_1_32m);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_1_32m);
          __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_v_algogithom, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 148, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) : __pyx_t_14;
          __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_3);
          __Pyx_GIVEREF(__pyx_t_3);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
          __pyx_t_3 = 0;
          __Pyx_INCREF(__pyx_kp_u_layers);
          __pyx_t_13 += 8;
          __Pyx_GIVEREF(__pyx_kp_u_layers);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u_layers);
          __pyx_t_3 = __Pyx_PyObject_FormatSimple(__pyx_v_layers, __pyx_empty_unicode); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 148, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_3) : __pyx_t_14;
          __pyx_t_13 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_3);
          __Pyx_GIVEREF(__pyx_t_3);
          PyTuple_SET_ITEM(__pyx_t_1, 3, __pyx_t_3);
          __pyx_t_3 = 0;
          __Pyx_INCREF(__pyx_kp_u_0m);
          __pyx_t_14 = (65535 > __pyx_t_14) ? 65535 : __pyx_t_14;
          __pyx_t_13 += 6;
          __Pyx_GIVEREF(__pyx_kp_u_0m);
          PyTuple_SET_ITEM(__pyx_t_1, 4, __pyx_kp_u_0m);
          __pyx_t_3 = __Pyx_PyUnicode_Join(__pyx_t_1, 5, __pyx_t_13, __pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 148, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = PyTuple_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 148, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GIVEREF(__pyx_t_3);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
          __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 148, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_end, __pyx_kp_u__11) < 0) __PYX_ERR(0, 148, __pyx_L31_error)
          __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 148, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 149, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_strip); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 149, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
            __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
            if (likely(__pyx_t_3)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
              __Pyx_INCREF(__pyx_t_3);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_1, function);
            }
          }
          __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 149, __pyx_L31_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_26 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_26 < 0)) __PYX_ERR(0, 149, __pyx_L31_error)
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_4 = ((!__pyx_t_26) != 0);
          if (unlikely(__pyx_t_4)) {

            
            __pyx_t_2 = __Pyx_PyObject_CallNoArg(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0]))); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 150, __pyx_L31_error)
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_Raise(__pyx_t_2, 0, 0, 0);
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            __PYX_ERR(0, 150, __pyx_L31_error)

            
          }

          
        }
        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        goto __pyx_L38_try_end;
        __pyx_L31_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

        
        __pyx_t_18 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
        if (__pyx_t_18) {
          __Pyx_AddTraceback("decode.DecodingAlgorithms.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_1, &__pyx_t_3) < 0) __PYX_ERR(0, 151, __pyx_L33_except_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_3);

          
          __pyx_t_17 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__14, NULL); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 152, __pyx_L33_except_error)
          __Pyx_GOTREF(__pyx_t_17);
          __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;

          
          goto __pyx_L40_except_break;
          __pyx_L40_except_break:;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          goto __pyx_L36_try_break;
        }
        goto __pyx_L33_except_error;
        __pyx_L33_except_error:;

        
        __Pyx_XGIVEREF(__pyx_t_11);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_10, __pyx_t_9);
        goto __pyx_L1_error;
        __pyx_L36_try_break:;
        __Pyx_XGIVEREF(__pyx_t_11);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_10, __pyx_t_9);
        goto __pyx_L30_break;
        __pyx_L38_try_end:;
      }
    }
    __pyx_L30_break:;

    
    goto __pyx_L5_break;

    
    __pyx_L4_continue:;
  }
  __pyx_L5_break:;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
    __Pyx_XGOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_t_10);
    __Pyx_XGOTREF(__pyx_t_11);
     {

      
       {
        __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 156, __pyx_L42_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_INCREF(__pyx_v_save_file);
        __Pyx_GIVEREF(__pyx_v_save_file);
        PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_v_save_file);
        __Pyx_INCREF(__pyx_n_u_w);
        __Pyx_GIVEREF(__pyx_n_u_w);
        PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_n_u_w);
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_5, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 156, __pyx_L42_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_t_25 = __Pyx_PyObject_LookupSpecial(__pyx_t_3, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_25)) __PYX_ERR(0, 156, __pyx_L42_error)
        __Pyx_GOTREF(__pyx_t_25);
        __pyx_t_1 = __Pyx_PyObject_LookupSpecial(__pyx_t_3, __pyx_n_s_enter); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 156, __pyx_L48_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_2 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
          __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
          if (likely(__pyx_t_2)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
            __Pyx_INCREF(__pyx_t_2);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_1, function);
          }
        }
        __pyx_t_5 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 156, __pyx_L48_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_1 = __pyx_t_5;
        __pyx_t_5 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
         {
          {
            __Pyx_PyThreadState_declare
            __Pyx_PyThreadState_assign
            __Pyx_ExceptionSave(&__pyx_t_24, &__pyx_t_23, &__pyx_t_22);
            __Pyx_XGOTREF(__pyx_t_24);
            __Pyx_XGOTREF(__pyx_t_23);
            __Pyx_XGOTREF(__pyx_t_22);
             {
              __pyx_v_file = __pyx_t_1;
              __pyx_t_1 = 0;

              
              __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_COPYRIGHT); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 157, __pyx_L52_error)
              __Pyx_GOTREF(__pyx_t_1);
              __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 157, __pyx_L52_error)
              __Pyx_GOTREF(__pyx_t_3);
              __pyx_t_4 = (__Pyx_PySequence_ContainsTF(__pyx_t_1, __pyx_t_3, Py_NE)); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 157, __pyx_L52_error)
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
              __pyx_t_26 = (__pyx_t_4 != 0);
              if (__pyx_t_26) {

                
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_5 = PyTuple_New(3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_5);
                __pyx_t_7 = 0;
                __pyx_t_14 = 127;
                __Pyx_INCREF(__pyx_kp_u_encoding);
                __pyx_t_7 += 12;
                __Pyx_GIVEREF(__pyx_kp_u_encoding);
                PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_kp_u_encoding);
                __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_2);
                __pyx_t_17 = __Pyx_PyObject_FormatSimple(__pyx_t_2, __pyx_empty_unicode); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_17);
                __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                __pyx_t_14 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) > __pyx_t_14) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_17) : __pyx_t_14;
                __pyx_t_7 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_17);
                __Pyx_GIVEREF(__pyx_t_17);
                PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_17);
                __pyx_t_17 = 0;
                __Pyx_INCREF(__pyx_kp_u__15);
                __pyx_t_7 += 1;
                __Pyx_GIVEREF(__pyx_kp_u__15);
                PyTuple_SET_ITEM(__pyx_t_5, 2, __pyx_kp_u__15);
                __pyx_t_17 = __Pyx_PyUnicode_Join(__pyx_t_5, 3, __pyx_t_7, __pyx_t_14); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_17);
                __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
                __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_COPYRIGHT); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_5);
                __pyx_t_2 = PyNumber_Add(__pyx_t_17, __pyx_t_5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_2);
                __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
                __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
                __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_5);
                __pyx_t_17 = PyNumber_Add(__pyx_t_2, __pyx_t_5); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_17);
                __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
                __pyx_t_5 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
                  __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_1);
                  if (likely(__pyx_t_5)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                    __Pyx_INCREF(__pyx_t_5);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_1, function);
                  }
                }
                __pyx_t_3 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_5, __pyx_t_17) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_17);
                __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
                if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 158, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_3);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

                
                goto __pyx_L58;
              }

              
               {
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_write); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 160, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_17 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 160, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_17);
                __pyx_t_5 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
                  __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_1);
                  if (likely(__pyx_t_5)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                    __Pyx_INCREF(__pyx_t_5);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_1, function);
                  }
                }
                __pyx_t_3 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_5, __pyx_t_17) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_17);
                __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
                __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
                if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 160, __pyx_L52_error)
                __Pyx_GOTREF(__pyx_t_3);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
              }
              __pyx_L58:;

              
            }
            __Pyx_XDECREF(__pyx_t_24); __pyx_t_24 = 0;
            __Pyx_XDECREF(__pyx_t_23); __pyx_t_23 = 0;
            __Pyx_XDECREF(__pyx_t_22); __pyx_t_22 = 0;
            goto __pyx_L57_try_end;
            __pyx_L52_error:;
            __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
            __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
            __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
            __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
            __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
            __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
             {
              __Pyx_AddTraceback("decode.DecodingAlgorithms.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
              if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_1, &__pyx_t_17) < 0) __PYX_ERR(0, 156, __pyx_L54_except_error)
              __Pyx_GOTREF(__pyx_t_3);
              __Pyx_GOTREF(__pyx_t_1);
              __Pyx_GOTREF(__pyx_t_17);
              __pyx_t_5 = PyTuple_Pack(3, __pyx_t_3, __pyx_t_1, __pyx_t_17); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 156, __pyx_L54_except_error)
              __Pyx_GOTREF(__pyx_t_5);
              __pyx_t_21 = __Pyx_PyObject_Call(__pyx_t_25, __pyx_t_5, NULL);
              __Pyx_DECREF(__pyx_t_25); __pyx_t_25 = 0;
              __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
              if (unlikely(!__pyx_t_21)) __PYX_ERR(0, 156, __pyx_L54_except_error)
              __Pyx_GOTREF(__pyx_t_21);
              __pyx_t_26 = __Pyx_PyObject_IsTrue(__pyx_t_21);
              __Pyx_DECREF(__pyx_t_21); __pyx_t_21 = 0;
              if (__pyx_t_26 < 0) __PYX_ERR(0, 156, __pyx_L54_except_error)
              __pyx_t_4 = ((!(__pyx_t_26 != 0)) != 0);
              if (__pyx_t_4) {
                __Pyx_GIVEREF(__pyx_t_3);
                __Pyx_GIVEREF(__pyx_t_1);
                __Pyx_XGIVEREF(__pyx_t_17);
                __Pyx_ErrRestoreWithState(__pyx_t_3, __pyx_t_1, __pyx_t_17);
                __pyx_t_3 = 0; __pyx_t_1 = 0; __pyx_t_17 = 0; 
                __PYX_ERR(0, 156, __pyx_L54_except_error)
              }
              __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
              goto __pyx_L53_exception_handled;
            }
            __pyx_L54_except_error:;
            __Pyx_XGIVEREF(__pyx_t_24);
            __Pyx_XGIVEREF(__pyx_t_23);
            __Pyx_XGIVEREF(__pyx_t_22);
            __Pyx_ExceptionReset(__pyx_t_24, __pyx_t_23, __pyx_t_22);
            goto __pyx_L42_error;
            __pyx_L53_exception_handled:;
            __Pyx_XGIVEREF(__pyx_t_24);
            __Pyx_XGIVEREF(__pyx_t_23);
            __Pyx_XGIVEREF(__pyx_t_22);
            __Pyx_ExceptionReset(__pyx_t_24, __pyx_t_23, __pyx_t_22);
            __pyx_L57_try_end:;
          }
        }
         {
          {
            if (__pyx_t_25) {
              __pyx_t_22 = __Pyx_PyObject_Call(__pyx_t_25, __pyx_tuple__16, NULL);
              __Pyx_DECREF(__pyx_t_25); __pyx_t_25 = 0;
              if (unlikely(!__pyx_t_22)) __PYX_ERR(0, 156, __pyx_L42_error)
              __Pyx_GOTREF(__pyx_t_22);
              __Pyx_DECREF(__pyx_t_22); __pyx_t_22 = 0;
            }
            goto __pyx_L51;
          }
          __pyx_L51:;
        }
        goto __pyx_L62;
        __pyx_L48_error:;
        __Pyx_DECREF(__pyx_t_25); __pyx_t_25 = 0;
        goto __pyx_L42_error;
        __pyx_L62:;
      }

      
    }
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    goto __pyx_L47_try_end;
    __pyx_L42_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
    __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

    
    __pyx_t_18 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_18) {
      __Pyx_AddTraceback("decode.DecodingAlgorithms.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_17, &__pyx_t_1, &__pyx_t_3) < 0) __PYX_ERR(0, 161, __pyx_L44_except_error)
      __Pyx_GOTREF(__pyx_t_17);
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_1);
      __pyx_v_e = __pyx_t_1;
       {

        
        __pyx_t_5 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__17, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 162, __pyx_L68_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      }

      
       {
        {
          __Pyx_DECREF(__pyx_v_e);
          __pyx_v_e = NULL;
          goto __pyx_L69;
        }
        __pyx_L68_error:;
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __pyx_t_25 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_21 = 0; __pyx_t_20 = 0;
          __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
          if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_24, &__pyx_t_21, &__pyx_t_20);
          if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_25, &__pyx_t_22, &__pyx_t_23) < 0)) __Pyx_ErrFetch(&__pyx_t_25, &__pyx_t_22, &__pyx_t_23);
          __Pyx_XGOTREF(__pyx_t_25);
          __Pyx_XGOTREF(__pyx_t_22);
          __Pyx_XGOTREF(__pyx_t_23);
          __Pyx_XGOTREF(__pyx_t_24);
          __Pyx_XGOTREF(__pyx_t_21);
          __Pyx_XGOTREF(__pyx_t_20);
          __pyx_t_18 = __pyx_lineno; __pyx_t_15 = __pyx_clineno; __pyx_t_27 = __pyx_filename;
          {
            __Pyx_DECREF(__pyx_v_e);
            __pyx_v_e = NULL;
          }
          if (PY_MAJOR_VERSION >= 3) {
            __Pyx_XGIVEREF(__pyx_t_24);
            __Pyx_XGIVEREF(__pyx_t_21);
            __Pyx_XGIVEREF(__pyx_t_20);
            __Pyx_ExceptionReset(__pyx_t_24, __pyx_t_21, __pyx_t_20);
          }
          __Pyx_XGIVEREF(__pyx_t_25);
          __Pyx_XGIVEREF(__pyx_t_22);
          __Pyx_XGIVEREF(__pyx_t_23);
          __Pyx_ErrRestore(__pyx_t_25, __pyx_t_22, __pyx_t_23);
          __pyx_t_25 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_21 = 0; __pyx_t_20 = 0;
          __pyx_lineno = __pyx_t_18; __pyx_clineno = __pyx_t_15; __pyx_filename = __pyx_t_27;
          goto __pyx_L44_except_error;
        }
        __pyx_L69:;
      }
      __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      goto __pyx_L43_exception_handled;
    }
    goto __pyx_L44_except_error;
    __pyx_L44_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    goto __pyx_L1_error;
    __pyx_L43_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_10);
    __Pyx_XGIVEREF(__pyx_t_11);
    __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
    __pyx_L47_try_end:;
  }

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_XDECREF(__pyx_t_17);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.__init__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_algogithom);
  __Pyx_XDECREF(__pyx_v_err);
  __Pyx_XDECREF(__pyx_v_layers);
  __Pyx_XDECREF(__pyx_v_file);
  __Pyx_XDECREF(__pyx_v_e);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_3eval_filter(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_3eval_filter = {"eval_filter", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_3eval_filter, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_3eval_filter(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("eval_filter (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_2eval_filter(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_11eval_filter_1root_search(PyObject *__pyx_self, PyObject *__pyx_v_all_eval_functions); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_11eval_filter_1root_search = {"root_search", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_11eval_filter_1root_search, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_11eval_filter_1root_search(PyObject *__pyx_self, PyObject *__pyx_v_all_eval_functions) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("root_search (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_11eval_filter_root_search(__pyx_self, ((PyObject *)__pyx_v_all_eval_functions));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_11eval_filter_root_search(PyObject *__pyx_self, PyObject *__pyx_v_all_eval_functions) {
  struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *__pyx_cur_scope;
  struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *__pyx_outer_scope;
  PyObject *__pyx_v_func = NULL;
  PyObject *__pyx_v_exceptions = NULL;
  PyObject *__pyx_v_eval_f = NULL;
  PyObject *__pyx_v_eval_body = NULL;
  PyObject *__pyx_v_bad_functions = NULL;
  int __pyx_v_is_in;
  PyObject *__pyx_v_function = NULL;
  PyObject *__pyx_v_eval_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *(*__pyx_t_3)(PyObject *);
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  Py_ssize_t __pyx_t_14;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  PyObject *__pyx_t_19 = NULL;
  Py_UCS4 __pyx_t_20;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("root_search", 0);
  __pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  
  if (likely(PyList_CheckExact(__pyx_v_all_eval_functions)) || PyTuple_CheckExact(__pyx_v_all_eval_functions)) {
    __pyx_t_1 = __pyx_v_all_eval_functions; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_all_eval_functions); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 166, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 166, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 166, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 166, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 166, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 166, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 166, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XDECREF_SET(__pyx_v_func, __pyx_t_4);
    __pyx_t_4 = 0;

    
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_func, __pyx_n_s_strip); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 167, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_6 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_5, function);
      }
    }
    __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_5);
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 167, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 167, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_8 = ((!__pyx_t_7) != 0);
    if (__pyx_t_8) {

      
      __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_all_eval_functions, __pyx_n_s_remove); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 168, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_6 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
        __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
        if (likely(__pyx_t_6)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
          __Pyx_INCREF(__pyx_t_6);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_5, function);
        }
      }
      __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_6, __pyx_v_func) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_v_func);
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 168, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      
    }

    
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_INCREF(__pyx_int_0);
  __pyx_v_exceptions = __pyx_int_0;

  
  if (likely(PyList_CheckExact(__pyx_v_all_eval_functions)) || PyTuple_CheckExact(__pyx_v_all_eval_functions)) {
    __pyx_t_1 = __pyx_v_all_eval_functions; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_all_eval_functions); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 171, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 171, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 171, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 171, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 171, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 171, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 171, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XDECREF_SET(__pyx_v_eval_f, __pyx_t_4);
    __pyx_t_4 = 0;

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_9, &__pyx_t_10, &__pyx_t_11);
      __Pyx_XGOTREF(__pyx_t_9);
      __Pyx_XGOTREF(__pyx_t_10);
      __Pyx_XGOTREF(__pyx_t_11);
       {

        
        __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_re); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 173, __pyx_L8_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_findall); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 173, __pyx_L8_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_t_5 = NULL;
        __pyx_t_12 = 0;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
          __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_6);
          if (likely(__pyx_t_5)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
            __Pyx_INCREF(__pyx_t_5);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_6, function);
            __pyx_t_12 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_6)) {
          PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_kp_u__18, __pyx_v_eval_f};
          __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 173, __pyx_L8_error)
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_GOTREF(__pyx_t_4);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
          PyObject *__pyx_temp[3] = {__pyx_t_5, __pyx_kp_u__18, __pyx_v_eval_f};
          __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 173, __pyx_L8_error)
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_GOTREF(__pyx_t_4);
        } else
        #endif
        {
          __pyx_t_13 = PyTuple_New(2+__pyx_t_12); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 173, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_13);
          if (__pyx_t_5) {
            __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_5); __pyx_t_5 = NULL;
          }
          __Pyx_INCREF(__pyx_kp_u__18);
          __Pyx_GIVEREF(__pyx_kp_u__18);
          PyTuple_SET_ITEM(__pyx_t_13, 0+__pyx_t_12, __pyx_kp_u__18);
          __Pyx_INCREF(__pyx_v_eval_f);
          __Pyx_GIVEREF(__pyx_v_eval_f);
          PyTuple_SET_ITEM(__pyx_t_13, 1+__pyx_t_12, __pyx_v_eval_f);
          __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_13, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 173, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
        }
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __pyx_t_6 = __Pyx_GetItemInt(__pyx_t_4, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 173, __pyx_L8_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_XDECREF_SET(__pyx_v_eval_body, __pyx_t_6);
        __pyx_t_6 = 0;

        
        __pyx_t_6 = PyList_New(2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 174, __pyx_L8_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_INCREF(__pyx_n_u_eval);
        __Pyx_GIVEREF(__pyx_n_u_eval);
        PyList_SET_ITEM(__pyx_t_6, 0, __pyx_n_u_eval);
        __Pyx_INCREF(__pyx_n_u_exec);
        __Pyx_GIVEREF(__pyx_n_u_exec);
        PyList_SET_ITEM(__pyx_t_6, 1, __pyx_n_u_exec);
        __Pyx_XDECREF_SET(__pyx_v_bad_functions, ((PyObject*)__pyx_t_6));
        __pyx_t_6 = 0;

        
        __pyx_v_is_in = 0;

        
        __pyx_t_6 = __pyx_v_bad_functions; __Pyx_INCREF(__pyx_t_6); __pyx_t_14 = 0;
        for (;;) {
          if (__pyx_t_14 >= PyList_GET_SIZE(__pyx_t_6)) break;
          #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
          __pyx_t_4 = PyList_GET_ITEM(__pyx_t_6, __pyx_t_14); __Pyx_INCREF(__pyx_t_4); __pyx_t_14++; if (unlikely(0 < 0)) __PYX_ERR(0, 176, __pyx_L8_error)
          #else
          __pyx_t_4 = PySequence_ITEM(__pyx_t_6, __pyx_t_14); __pyx_t_14++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 176, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_4);
          #endif
          __Pyx_XDECREF_SET(__pyx_v_function, __pyx_t_4);
          __pyx_t_4 = 0;

          
          __pyx_t_8 = (__Pyx_PySequence_ContainsTF(__pyx_v_function, __pyx_v_eval_body, Py_EQ)); if (unlikely(__pyx_t_8 < 0)) __PYX_ERR(0, 177, __pyx_L8_error)
          __pyx_t_7 = (__pyx_t_8 != 0);
          if (__pyx_t_7) {

            
            __pyx_v_is_in = 1;

            
          }

          
        }
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

        
        __pyx_t_7 = (__pyx_v_is_in != 0);
        if (__pyx_t_7) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 180, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_4);
          __pyx_t_13 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_function); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 180, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_13);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __pyx_t_4 = NULL;
          __pyx_t_12 = 0;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_13))) {
            __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_13);
            if (likely(__pyx_t_4)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_13);
              __Pyx_INCREF(__pyx_t_4);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_13, function);
              __pyx_t_12 = 1;
            }
          }
          #if CYTHON_FAST_PYCALL
          if (PyFunction_Check(__pyx_t_13)) {
            PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_v_eval_body, __pyx_n_u_eval};
            __pyx_t_6 = __Pyx_PyFunction_FastCall(__pyx_t_13, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 180, __pyx_L8_error)
            __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
            __Pyx_GOTREF(__pyx_t_6);
          } else
          #endif
          #if CYTHON_FAST_PYCCALL
          if (__Pyx_PyFastCFunction_Check(__pyx_t_13)) {
            PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_v_eval_body, __pyx_n_u_eval};
            __pyx_t_6 = __Pyx_PyCFunction_FastCall(__pyx_t_13, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 180, __pyx_L8_error)
            __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
            __Pyx_GOTREF(__pyx_t_6);
          } else
          #endif
          {
            __pyx_t_5 = PyTuple_New(2+__pyx_t_12); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 180, __pyx_L8_error)
            __Pyx_GOTREF(__pyx_t_5);
            if (__pyx_t_4) {
              __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_4); __pyx_t_4 = NULL;
            }
            __Pyx_INCREF(__pyx_v_eval_body);
            __Pyx_GIVEREF(__pyx_v_eval_body);
            PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_12, __pyx_v_eval_body);
            __Pyx_INCREF(__pyx_n_u_eval);
            __Pyx_GIVEREF(__pyx_n_u_eval);
            PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_12, __pyx_n_u_eval);
            __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_13, __pyx_t_5, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 180, __pyx_L8_error)
            __Pyx_GOTREF(__pyx_t_6);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
          }
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
          __pyx_t_13 = PySequence_List(__pyx_t_6); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 180, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_13);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __pyx_t_6 = PySet_New(__pyx_t_13); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 180, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
          __pyx_t_13 = PySequence_List(__pyx_t_6); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 180, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_13);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          if (unlikely(!__pyx_cur_scope->__pyx_v_root_search)) { __Pyx_RaiseClosureNameError("root_search"); __PYX_ERR(0, 180, __pyx_L8_error) }
          __pyx_t_6 = __pyx_pf_6decode_18DecodingAlgorithms_11eval_filter_root_search(__pyx_cur_scope->__pyx_v_root_search, __pyx_t_13); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 180, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

          
          __pyx_t_6 = __Pyx_PyInt_AddObjC(__pyx_v_exceptions, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 181, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF_SET(__pyx_v_exceptions, __pyx_t_6);
          __pyx_t_6 = 0;

          
          goto __pyx_L14_try_continue;

          
        }

        
      }
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      goto __pyx_L15_try_end;
      __pyx_L8_error:;
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

      
      __pyx_t_12 = __Pyx_PyErr_ExceptionMatches(__pyx_builtin_IndexError);
      if (__pyx_t_12) {
        __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_filter.root_search", __pyx_clineno, __pyx_lineno, __pyx_filename);
        if (__Pyx_GetException(&__pyx_t_6, &__pyx_t_13, &__pyx_t_5) < 0) __PYX_ERR(0, 183, __pyx_L10_except_error)
        __Pyx_GOTREF(__pyx_t_6);
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_GOTREF(__pyx_t_5);

        
        goto __pyx_L21_except_continue;
        __pyx_L21_except_continue:;
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        goto __pyx_L14_try_continue;
      }
      goto __pyx_L10_except_error;
      __pyx_L10_except_error:;

      
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_11);
      __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
      goto __pyx_L1_error;
      __pyx_L14_try_continue:;
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_11);
      __Pyx_ExceptionReset(__pyx_t_9, __pyx_t_10, __pyx_t_11);
      goto __pyx_L6_continue;
      __pyx_L15_try_end:;
    }

    
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_11, &__pyx_t_10, &__pyx_t_9);
      __Pyx_XGOTREF(__pyx_t_11);
      __Pyx_XGOTREF(__pyx_t_10);
      __Pyx_XGOTREF(__pyx_t_9);
       {

        
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17);
          __Pyx_XGOTREF(__pyx_t_15);
          __Pyx_XGOTREF(__pyx_t_16);
          __Pyx_XGOTREF(__pyx_t_17);
           {

            
            __pyx_t_13 = __Pyx_PyObject_FormatSimple(__pyx_v_eval_body, __pyx_empty_unicode); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_13);
            __pyx_t_6 = __Pyx_PyUnicode_Concat(__pyx_n_u_b, __pyx_t_13); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_6);
            __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
            __pyx_t_13 = __Pyx_Globals(); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_13);
            __pyx_t_4 = __Pyx_PyDict_NewPresized(10); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_4);
            if (__pyx_v_all_eval_functions) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_all_eval_functions, __pyx_v_all_eval_functions) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            if (__pyx_v_bad_functions) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_bad_functions, __pyx_v_bad_functions) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            if (__pyx_v_eval_body) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_eval_body, __pyx_v_eval_body) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            if (__pyx_v_eval_data) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_eval_data, __pyx_v_eval_data) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            if (__pyx_v_eval_f) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_eval_f, __pyx_v_eval_f) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            if (__pyx_v_exceptions) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_exceptions, __pyx_v_exceptions) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            if (__pyx_v_func) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_func, __pyx_v_func) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            if (__pyx_v_function) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_function, __pyx_v_function) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            __pyx_t_18 = __Pyx_PyBool_FromLong(__pyx_v_is_in); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_18);
            if (__pyx_t_18) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_is_in, __pyx_t_18) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
            if (__pyx_cur_scope->__pyx_v_root_search) {
              if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_root_search, __pyx_cur_scope->__pyx_v_root_search) < 0) __PYX_ERR(0, 188, __pyx_L30_error)
            }
            __pyx_t_18 = PyTuple_New(3); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_18);
            __Pyx_GIVEREF(__pyx_t_6);
            PyTuple_SET_ITEM(__pyx_t_18, 0, __pyx_t_6);
            __Pyx_GIVEREF(__pyx_t_13);
            PyTuple_SET_ITEM(__pyx_t_18, 1, __pyx_t_13);
            __Pyx_GIVEREF(__pyx_t_4);
            PyTuple_SET_ITEM(__pyx_t_18, 2, __pyx_t_4);
            __pyx_t_6 = 0;
            __pyx_t_13 = 0;
            __pyx_t_4 = 0;
            __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_eval, __pyx_t_18, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_4);
            __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
            __pyx_t_18 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_18);
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
            __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_4);
            __pyx_t_13 = NULL;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_18))) {
              __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_18);
              if (likely(__pyx_t_13)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_18);
                __Pyx_INCREF(__pyx_t_13);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_18, function);
              }
            }
            __pyx_t_5 = (__pyx_t_13) ? __Pyx_PyObject_Call2Args(__pyx_t_18, __pyx_t_13, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_18, __pyx_t_4);
            __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
            __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
            if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 188, __pyx_L30_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
            __Pyx_XDECREF_SET(__pyx_v_eval_data, __pyx_t_5);
            __pyx_t_5 = 0;

            
          }
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
          __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
          goto __pyx_L37_try_end;
          __pyx_L30_error:;
          __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

          
          __pyx_t_12 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
          if (__pyx_t_12) {
            __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_filter.root_search", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_18, &__pyx_t_4) < 0) __PYX_ERR(0, 189, __pyx_L32_except_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_GOTREF(__pyx_t_18);
            __Pyx_GOTREF(__pyx_t_4);

            
            __pyx_t_13 = __Pyx_Globals(); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 190, __pyx_L32_except_error)
            __Pyx_GOTREF(__pyx_t_13);
            __pyx_t_6 = __Pyx_PyDict_NewPresized(10); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 190, __pyx_L32_except_error)
            __Pyx_GOTREF(__pyx_t_6);
            if (__pyx_v_all_eval_functions) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_all_eval_functions, __pyx_v_all_eval_functions) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            if (__pyx_v_bad_functions) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_bad_functions, __pyx_v_bad_functions) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            if (__pyx_v_eval_body) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_eval_body, __pyx_v_eval_body) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            if (__pyx_v_eval_data) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_eval_data, __pyx_v_eval_data) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            if (__pyx_v_eval_f) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_eval_f, __pyx_v_eval_f) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            if (__pyx_v_exceptions) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_exceptions, __pyx_v_exceptions) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            if (__pyx_v_func) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_func, __pyx_v_func) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            if (__pyx_v_function) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_function, __pyx_v_function) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            __pyx_t_19 = __Pyx_PyBool_FromLong(__pyx_v_is_in); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 190, __pyx_L32_except_error)
            __Pyx_GOTREF(__pyx_t_19);
            if (__pyx_t_19) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_is_in, __pyx_t_19) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
            if (__pyx_cur_scope->__pyx_v_root_search) {
              if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_root_search, __pyx_cur_scope->__pyx_v_root_search) < 0) __PYX_ERR(0, 190, __pyx_L32_except_error)
            }
            __pyx_t_19 = PyTuple_New(3); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 190, __pyx_L32_except_error)
            __Pyx_GOTREF(__pyx_t_19);
            __Pyx_INCREF(__pyx_v_eval_body);
            __Pyx_GIVEREF(__pyx_v_eval_body);
            PyTuple_SET_ITEM(__pyx_t_19, 0, __pyx_v_eval_body);
            __Pyx_GIVEREF(__pyx_t_13);
            PyTuple_SET_ITEM(__pyx_t_19, 1, __pyx_t_13);
            __Pyx_GIVEREF(__pyx_t_6);
            PyTuple_SET_ITEM(__pyx_t_19, 2, __pyx_t_6);
            __pyx_t_13 = 0;
            __pyx_t_6 = 0;
            __pyx_t_6 = __Pyx_PyObject_Call(__pyx_builtin_eval, __pyx_t_19, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 190, __pyx_L32_except_error)
            __Pyx_GOTREF(__pyx_t_6);
            __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
            __Pyx_XDECREF_SET(__pyx_v_eval_data, __pyx_t_6);
            __pyx_t_6 = 0;
            __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
            __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
            __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
            goto __pyx_L31_exception_handled;
          }
          goto __pyx_L32_except_error;
          __pyx_L32_except_error:;

          
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          goto __pyx_L22_error;
          __pyx_L31_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          __pyx_L37_try_end:;
        }

        
        if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 191, __pyx_L22_error) }
        __pyx_t_18 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 191, __pyx_L22_error)
        __Pyx_GOTREF(__pyx_t_18);
        __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_18, __pyx_n_s_replace); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 191, __pyx_L22_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
        __pyx_t_18 = NULL;
        __pyx_t_12 = 0;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_5))) {
          __pyx_t_18 = PyMethod_GET_SELF(__pyx_t_5);
          if (likely(__pyx_t_18)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
            __Pyx_INCREF(__pyx_t_18);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_5, function);
            __pyx_t_12 = 1;
          }
        }
        #if CYTHON_FAST_PYCALL
        if (PyFunction_Check(__pyx_t_5)) {
          PyObject *__pyx_temp[3] = {__pyx_t_18, __pyx_v_eval_f, __pyx_v_eval_data};
          __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 191, __pyx_L22_error)
          __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
          __Pyx_GOTREF(__pyx_t_4);
        } else
        #endif
        #if CYTHON_FAST_PYCCALL
        if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
          PyObject *__pyx_temp[3] = {__pyx_t_18, __pyx_v_eval_f, __pyx_v_eval_data};
          __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 191, __pyx_L22_error)
          __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
          __Pyx_GOTREF(__pyx_t_4);
        } else
        #endif
        {
          __pyx_t_6 = PyTuple_New(2+__pyx_t_12); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 191, __pyx_L22_error)
          __Pyx_GOTREF(__pyx_t_6);
          if (__pyx_t_18) {
            __Pyx_GIVEREF(__pyx_t_18); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_18); __pyx_t_18 = NULL;
          }
          __Pyx_INCREF(__pyx_v_eval_f);
          __Pyx_GIVEREF(__pyx_v_eval_f);
          PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_12, __pyx_v_eval_f);
          __Pyx_INCREF(__pyx_v_eval_data);
          __Pyx_GIVEREF(__pyx_v_eval_data);
          PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_12, __pyx_v_eval_data);
          __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_6, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 191, __pyx_L22_error)
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        }
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 191, __pyx_L22_error) }
        if (__Pyx_PyObject_SetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_file_data, __pyx_t_4) < 0) __PYX_ERR(0, 191, __pyx_L22_error)
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

        
      }
      __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      goto __pyx_L29_try_end;
      __pyx_L22_error:;
      __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
      __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
      __Pyx_XDECREF(__pyx_t_19); __pyx_t_19 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;

      
      __pyx_t_12 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
      if (__pyx_t_12) {
        __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_filter.root_search", __pyx_clineno, __pyx_lineno, __pyx_filename);
        if (__Pyx_GetException(&__pyx_t_4, &__pyx_t_5, &__pyx_t_6) < 0) __PYX_ERR(0, 192, __pyx_L24_except_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_GOTREF(__pyx_t_6);

        
        __pyx_t_18 = __Pyx_PyInt_AddObjC(__pyx_v_exceptions, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 193, __pyx_L24_except_error)
        __Pyx_GOTREF(__pyx_t_18);
        __Pyx_DECREF_SET(__pyx_v_exceptions, __pyx_t_18);
        __pyx_t_18 = 0;
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        goto __pyx_L23_exception_handled;
      }
      goto __pyx_L24_except_error;
      __pyx_L24_except_error:;

      
      __Pyx_XGIVEREF(__pyx_t_11);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_10, __pyx_t_9);
      goto __pyx_L1_error;
      __pyx_L23_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_11);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_10, __pyx_t_9);
      __pyx_L29_try_end:;
    }

    
    __pyx_L6_continue:;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_2 = PyObject_Length(__pyx_v_all_eval_functions); if (unlikely(__pyx_t_2 == ((Py_ssize_t)-1))) __PYX_ERR(0, 194, __pyx_L1_error)
  __pyx_t_1 = PyInt_FromSsize_t(__pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = PyObject_RichCompare(__pyx_v_exceptions, __pyx_t_1, Py_EQ); __Pyx_XGOTREF(__pyx_t_6); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_7 = __Pyx_PyObject_IsTrue(__pyx_t_6); if (unlikely(__pyx_t_7 < 0)) __PYX_ERR(0, 194, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(__pyx_t_7)) {

    
    __pyx_t_6 = PyTuple_New(4); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 196, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_2 = 0;
    __pyx_t_20 = 127;
    __Pyx_INCREF(__pyx_kp_u_Exception_exceptions);
    __pyx_t_2 += 22;
    __Pyx_GIVEREF(__pyx_kp_u_Exception_exceptions);
    PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_kp_u_Exception_exceptions);
    __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_v_exceptions, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 196, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_20 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) > __pyx_t_20) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_1) : __pyx_t_20;
    __pyx_t_2 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_t_1);
    __pyx_t_1 = 0;
    __Pyx_INCREF(__pyx_kp_u_len_all_eval_functions);
    __pyx_t_2 += 28;
    __Pyx_GIVEREF(__pyx_kp_u_len_all_eval_functions);
    PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_kp_u_len_all_eval_functions);
    __pyx_t_14 = PyObject_Length(__pyx_v_all_eval_functions); if (unlikely(__pyx_t_14 == ((Py_ssize_t)-1))) __PYX_ERR(0, 196, __pyx_L1_error)
    __pyx_t_1 = __Pyx_PyUnicode_From_Py_ssize_t(__pyx_t_14, 0, ' ', 'd'); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 196, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_6, 3, __pyx_t_1);
    __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_6, 4, __pyx_t_2, __pyx_t_20); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 196, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

    
    __pyx_t_6 = __Pyx_PyObject_CallOneArg(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])), __pyx_t_1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 195, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_Raise(__pyx_t_6, 0, 0, 0);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __PYX_ERR(0, 195, __pyx_L1_error)

    
  }

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_18);
  __Pyx_XDECREF(__pyx_t_19);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_filter.root_search", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_func);
  __Pyx_XDECREF(__pyx_v_exceptions);
  __Pyx_XDECREF(__pyx_v_eval_f);
  __Pyx_XDECREF(__pyx_v_eval_body);
  __Pyx_XDECREF(__pyx_v_bad_functions);
  __Pyx_XDECREF(__pyx_v_function);
  __Pyx_XDECREF(__pyx_v_eval_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_2eval_filter(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("eval_filter", 0);
  __pyx_cur_scope = (struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *)__pyx_tp_new_6decode___pyx_scope_struct_2_eval_filter(__pyx_ptype_6decode___pyx_scope_struct_2_eval_filter, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 164, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_self = __pyx_v_self;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_self);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_self);

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_11eval_filter_1root_search, 0, __pyx_n_s_DecodingAlgorithms_eval_filter_l, ((PyObject*)__pyx_cur_scope), __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__20)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 165, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_root_search = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_function); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = NULL;
  __pyx_t_5 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
      __pyx_t_5 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_n_u_eval};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
    PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_n_u_eval};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  } else
  #endif
  {
    __pyx_t_6 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 198, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    if (__pyx_t_4) {
      __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_4); __pyx_t_4 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_2);
    PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_5, __pyx_t_2);
    __Pyx_INCREF(__pyx_n_u_eval);
    __Pyx_GIVEREF(__pyx_n_u_eval);
    PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_5, __pyx_n_u_eval);
    __pyx_t_2 = 0;
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PySequence_List(__pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PySet_New(__pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PySequence_List(__pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __pyx_pf_6decode_18DecodingAlgorithms_11eval_filter_root_search(__pyx_cur_scope->__pyx_v_root_search, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 198, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 199, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 199, __pyx_L1_error)
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_filter", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_5zlib(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_5zlib = {"zlib", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_5zlib, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_5zlib(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("zlib (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_4zlib(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_4zlib(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("zlib", 0);

  
  __Pyx_XDECREF(__pyx_r);

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_zlib); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_decompress); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_object); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 203, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 203, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 203, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 203, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_7) {
      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_5);
    __Pyx_INCREF(((PyObject *)(&PyBytes_Type)));
    __Pyx_GIVEREF(((PyObject *)(&PyBytes_Type)));
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, ((PyObject *)(&PyBytes_Type)));
    __pyx_t_5 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 203, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 202, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 204, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 204, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 204, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 204, __pyx_L1_error)
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.zlib", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_7zlib_base64(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_7zlib_base64 = {"zlib_base64", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_7zlib_base64, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_7zlib_base64(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("zlib_base64 (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_6zlib_base64(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_6zlib_base64(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_t_10;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("zlib_base64", 0);

  
  __Pyx_XDECREF(__pyx_r);

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_zlib); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_decompress); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_base64); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_b64decode); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_object); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 209, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_9 = NULL;
  __pyx_t_10 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_8);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_8, function);
      __pyx_t_10 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_7, ((PyObject *)(&PyUnicode_Type))};
    __pyx_t_5 = __Pyx_PyFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_10, 2+__pyx_t_10); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 209, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_8)) {
    PyObject *__pyx_temp[3] = {__pyx_t_9, __pyx_t_7, ((PyObject *)(&PyUnicode_Type))};
    __pyx_t_5 = __Pyx_PyCFunction_FastCall(__pyx_t_8, __pyx_temp+1-__pyx_t_10, 2+__pyx_t_10); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 209, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  } else
  #endif
  {
    __pyx_t_11 = PyTuple_New(2+__pyx_t_10); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 209, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_11);
    if (__pyx_t_9) {
      __Pyx_GIVEREF(__pyx_t_9); PyTuple_SET_ITEM(__pyx_t_11, 0, __pyx_t_9); __pyx_t_9 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_7);
    PyTuple_SET_ITEM(__pyx_t_11, 0+__pyx_t_10, __pyx_t_7);
    __Pyx_INCREF(((PyObject *)(&PyUnicode_Type)));
    __Pyx_GIVEREF(((PyObject *)(&PyUnicode_Type)));
    PyTuple_SET_ITEM(__pyx_t_11, 1+__pyx_t_10, ((PyObject *)(&PyUnicode_Type)));
    __pyx_t_7 = 0;
    __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_11, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 209, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
  }
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  __pyx_t_8 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_8)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_8);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_3 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_6, __pyx_t_8, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_5);
  __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 208, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 207, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 211, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 211, __pyx_L1_error)
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.zlib_base64", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_9codecs_bz2_codec(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_9codecs_bz2_codec = {"codecs_bz2_codec", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_9codecs_bz2_codec, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_9codecs_bz2_codec(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("codecs_bz2_codec (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_8codecs_bz2_codec(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_8codecs_bz2_codec(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("codecs_bz2_codec", 0);

  
  __Pyx_XDECREF(__pyx_r);

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_codecs); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 214, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_object); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 215, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_7) {
      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_5);
    __Pyx_INCREF(((PyObject *)(&PyBytes_Type)));
    __Pyx_GIVEREF(((PyObject *)(&PyBytes_Type)));
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, ((PyObject *)(&PyBytes_Type)));
    __pyx_t_5 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 215, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_3, __pyx_n_u_bz2_codec};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_3, __pyx_n_u_bz2_codec};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_3);
    __Pyx_INCREF(__pyx_n_u_bz2_codec);
    __Pyx_GIVEREF(__pyx_n_u_bz2_codec);
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, __pyx_n_u_bz2_codec);
    __pyx_t_3 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_9, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 214, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_9 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_9)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_9);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_9) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_9, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 217, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 217, __pyx_L1_error)
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.codecs_bz2_codec", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_11base16(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_11base16 = {"base16", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_11base16, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_11base16(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("base16 (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_10base16(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_10base16(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("base16", 0);

  
  __Pyx_XDECREF(__pyx_r);

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_base64); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 220, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_b16decode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 220, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 221, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_object); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 221, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 221, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_7) {
      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_5);
    __Pyx_INCREF(((PyObject *)(&PyBytes_Type)));
    __Pyx_GIVEREF(((PyObject *)(&PyBytes_Type)));
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, ((PyObject *)(&PyBytes_Type)));
    __pyx_t_5 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 221, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 220, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 222, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 222, __pyx_L1_error)
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.base16", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13base32(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13base32 = {"base32", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_13base32, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13base32(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("base32 (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_12base32(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_12base32(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("base32", 0);

  
  __Pyx_XDECREF(__pyx_r);

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_base64); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_b32decode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_object); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 226, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 226, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 226, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 226, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_7) {
      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_5);
    __Pyx_INCREF(((PyObject *)(&PyBytes_Type)));
    __Pyx_GIVEREF(((PyObject *)(&PyBytes_Type)));
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, ((PyObject *)(&PyBytes_Type)));
    __pyx_t_5 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 226, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 225, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 227, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 227, __pyx_L1_error)
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.base32", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_15base64(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_15base64 = {"base64", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_15base64, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_15base64(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("base64 (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_14base64(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_14base64(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  int __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("base64", 0);

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_t_2);
    __Pyx_XGOTREF(__pyx_t_3);
     {

      
      __Pyx_XDECREF(__pyx_r);
      __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_to_string); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 231, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_base64); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 231, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_8 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_b64decode); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 231, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_9, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 232, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_10 = __Pyx_PyObject_GetAttrStr(__pyx_t_9, __pyx_n_s_object); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 232, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 232, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_9);
      __pyx_t_11 = NULL;
      __pyx_t_12 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_10))) {
        __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_10);
        if (likely(__pyx_t_11)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_10);
          __Pyx_INCREF(__pyx_t_11);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_10, function);
          __pyx_t_12 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_10)) {
        PyObject *__pyx_temp[3] = {__pyx_t_11, __pyx_t_9, ((PyObject *)(&PyBytes_Type))};
        __pyx_t_7 = __Pyx_PyFunction_FastCall(__pyx_t_10, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 232, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_10)) {
        PyObject *__pyx_temp[3] = {__pyx_t_11, __pyx_t_9, ((PyObject *)(&PyBytes_Type))};
        __pyx_t_7 = __Pyx_PyCFunction_FastCall(__pyx_t_10, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 232, __pyx_L3_error)
        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      } else
      #endif
      {
        __pyx_t_13 = PyTuple_New(2+__pyx_t_12); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 232, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_13);
        if (__pyx_t_11) {
          __Pyx_GIVEREF(__pyx_t_11); PyTuple_SET_ITEM(__pyx_t_13, 0, __pyx_t_11); __pyx_t_11 = NULL;
        }
        __Pyx_GIVEREF(__pyx_t_9);
        PyTuple_SET_ITEM(__pyx_t_13, 0+__pyx_t_12, __pyx_t_9);
        __Pyx_INCREF(((PyObject *)(&PyBytes_Type)));
        __Pyx_GIVEREF(((PyObject *)(&PyBytes_Type)));
        PyTuple_SET_ITEM(__pyx_t_13, 1+__pyx_t_12, ((PyObject *)(&PyBytes_Type)));
        __pyx_t_9 = 0;
        __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_10, __pyx_t_13, NULL); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 232, __pyx_L3_error)
        __Pyx_GOTREF(__pyx_t_7);
        __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      }
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      __pyx_t_10 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_8))) {
        __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_8);
        if (likely(__pyx_t_10)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_8);
          __Pyx_INCREF(__pyx_t_10);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_8, function);
        }
      }
      __pyx_t_6 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_8, __pyx_t_10, __pyx_t_7) : __Pyx_PyObject_CallOneArg(__pyx_t_8, __pyx_t_7);
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 231, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __pyx_t_8 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
        __pyx_t_8 = PyMethod_GET_SELF(__pyx_t_5);
        if (likely(__pyx_t_8)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
          __Pyx_INCREF(__pyx_t_8);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_5, function);
        }
      }
      __pyx_t_4 = (__pyx_t_8) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_8, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_t_6);
      __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 231, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

      
      if (!(likely(PyUnicode_CheckExact(__pyx_t_4))||((__pyx_t_4) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_4)->tp_name), 0))) __PYX_ERR(0, 231, __pyx_L3_error)
      __pyx_r = ((PyObject*)__pyx_t_4);
      __pyx_t_4 = 0;
      goto __pyx_L7_try_return;

      
    }
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
    __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
    __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

    
     {
      __Pyx_AddTraceback("decode.DecodingAlgorithms.base64", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_4, &__pyx_t_5, &__pyx_t_6) < 0) __PYX_ERR(0, 234, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GOTREF(__pyx_t_6);

      
      __Pyx_XDECREF(__pyx_r);
      __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_to_string); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 235, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GetModuleGlobalName(__pyx_t_13, __pyx_n_s_base64); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 235, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_13);
      __pyx_t_9 = __Pyx_PyObject_GetAttrStr(__pyx_t_13, __pyx_n_s_b64decode); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 235, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_9);
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 236, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_11);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_11, __pyx_n_s_object); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 236, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 236, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_11);
      __pyx_t_15 = NULL;
      __pyx_t_12 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
        __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_14);
        if (likely(__pyx_t_15)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
          __Pyx_INCREF(__pyx_t_15);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_14, function);
          __pyx_t_12 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_14)) {
        PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_t_11, ((PyObject *)(&PyUnicode_Type))};
        __pyx_t_13 = __Pyx_PyFunction_FastCall(__pyx_t_14, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 236, __pyx_L5_except_error)
        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_14)) {
        PyObject *__pyx_temp[3] = {__pyx_t_15, __pyx_t_11, ((PyObject *)(&PyUnicode_Type))};
        __pyx_t_13 = __Pyx_PyCFunction_FastCall(__pyx_t_14, __pyx_temp+1-__pyx_t_12, 2+__pyx_t_12); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 236, __pyx_L5_except_error)
        __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      } else
      #endif
      {
        __pyx_t_16 = PyTuple_New(2+__pyx_t_12); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 236, __pyx_L5_except_error)
        __Pyx_GOTREF(__pyx_t_16);
        if (__pyx_t_15) {
          __Pyx_GIVEREF(__pyx_t_15); PyTuple_SET_ITEM(__pyx_t_16, 0, __pyx_t_15); __pyx_t_15 = NULL;
        }
        __Pyx_GIVEREF(__pyx_t_11);
        PyTuple_SET_ITEM(__pyx_t_16, 0+__pyx_t_12, __pyx_t_11);
        __Pyx_INCREF(((PyObject *)(&PyUnicode_Type)));
        __Pyx_GIVEREF(((PyObject *)(&PyUnicode_Type)));
        PyTuple_SET_ITEM(__pyx_t_16, 1+__pyx_t_12, ((PyObject *)(&PyUnicode_Type)));
        __pyx_t_11 = 0;
        __pyx_t_13 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_t_16, NULL); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 236, __pyx_L5_except_error)
        __Pyx_GOTREF(__pyx_t_13);
        __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
      }
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_9))) {
        __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_9);
        if (likely(__pyx_t_14)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_14);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_9, function);
        }
      }
      __pyx_t_10 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_9, __pyx_t_14, __pyx_t_13) : __Pyx_PyObject_CallOneArg(__pyx_t_9, __pyx_t_13);
      __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
      if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 235, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_10);
      __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
      __pyx_t_9 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
        __pyx_t_9 = PyMethod_GET_SELF(__pyx_t_7);
        if (likely(__pyx_t_9)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
          __Pyx_INCREF(__pyx_t_9);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_7, function);
        }
      }
      __pyx_t_8 = (__pyx_t_9) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_9, __pyx_t_10) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_t_10);
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
      if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 235, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

      
      if (!(likely(PyUnicode_CheckExact(__pyx_t_8))||((__pyx_t_8) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_8)->tp_name), 0))) __PYX_ERR(0, 235, __pyx_L5_except_error)
      __pyx_r = ((PyObject*)__pyx_t_8);
      __pyx_t_8 = 0;
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L6_except_return;
    }
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L7_try_return:;
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L0;
    __pyx_L6_except_return:;
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L0;
  }

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.base64", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_17base85(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_17base85 = {"base85", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_17base85, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_17base85(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("base85 (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_16base85(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_16base85(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("base85", 0);

  
  __Pyx_XDECREF(__pyx_r);

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_base64); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_b85decode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_object); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 241, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_7 = NULL;
  __pyx_t_8 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_7)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_7);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
      __pyx_t_8 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 241, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_6)) {
    PyObject *__pyx_temp[3] = {__pyx_t_7, __pyx_t_5, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_6, __pyx_temp+1-__pyx_t_8, 2+__pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 241, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  } else
  #endif
  {
    __pyx_t_9 = PyTuple_New(2+__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 241, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    if (__pyx_t_7) {
      __Pyx_GIVEREF(__pyx_t_7); PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7); __pyx_t_7 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_9, 0+__pyx_t_8, __pyx_t_5);
    __Pyx_INCREF(((PyObject *)(&PyBytes_Type)));
    __Pyx_GIVEREF(((PyObject *)(&PyBytes_Type)));
    PyTuple_SET_ITEM(__pyx_t_9, 1+__pyx_t_8, ((PyObject *)(&PyBytes_Type)));
    __pyx_t_5 = 0;
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_9, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 241, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  }
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 240, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 242, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 242, __pyx_L1_error)
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.base85", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_19marshal(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_19marshal = {"marshal", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_19marshal, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_19marshal(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("marshal (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_18marshal(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_18marshal(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_out = NULL;
  PyObject *__pyx_v_version = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_t_9;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("marshal", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_marshal); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_loads); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_CodeSearchAlgorithms); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_object); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_5)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_4, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_5)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_t_4, ((PyObject *)(&PyBytes_Type))};
    __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_5, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  } else
  #endif
  {
    __pyx_t_8 = PyTuple_New(2+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_GIVEREF(__pyx_t_4);
    PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_t_4);
    __Pyx_INCREF(((PyObject *)(&PyBytes_Type)));
    __Pyx_GIVEREF(((PyObject *)(&PyBytes_Type)));
    PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, ((PyObject *)(&PyBytes_Type)));
    __pyx_t_4 = 0;
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_8, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 245, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  }
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_5, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 245, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_bytecode = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_io); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_StringIO); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 246, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_out = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 247, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = PyObject_RichCompare(__pyx_t_2, __pyx_float_3_9, Py_LT); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 247, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 247, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__pyx_t_9) {
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 247, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = 0;
  } else {
    __Pyx_INCREF(__pyx_float_3_8);
    __pyx_t_1 = __pyx_float_3_8;
  }
  __pyx_v_version = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_decompile); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 248, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 248, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_v_version);
  __Pyx_GIVEREF(__pyx_v_version);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_version);
  __Pyx_INCREF(__pyx_v_bytecode);
  __Pyx_GIVEREF(__pyx_v_bytecode);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_v_bytecode);
  __Pyx_INCREF(__pyx_v_out);
  __Pyx_GIVEREF(__pyx_v_out);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_v_out);
  __pyx_t_2 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 248, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_t_2, __pyx_n_s_showast, Py_False) < 0) __PYX_ERR(0, 248, __pyx_L1_error)
  __pyx_t_5 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_3, __pyx_t_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 248, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_out, __pyx_n_s_getvalue); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_split); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_5 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_kp_u__15) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_u__15);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetSlice(__pyx_t_5, 4, 0, NULL, NULL, &__pyx_slice__21, 1, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = PyUnicode_Join(__pyx_kp_u__15, __pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyUnicode_Concat(__pyx_t_5, __pyx_kp_u__15); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_r = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.marshal", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_out);
  __Pyx_XDECREF(__pyx_v_version);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_21machine_code(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_21machine_code = {"machine_code", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_21machine_code, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_21machine_code(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("machine_code (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_20machine_code(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_20machine_code(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_out = NULL;
  PyObject *__pyx_v_version = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("machine_code", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_marshal); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_loads); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = __Pyx_PyObject_GetSlice(__pyx_t_2, 16, 0, NULL, NULL, &__pyx_slice__22, 1, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_bytecode = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_io); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 253, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_StringIO); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 253, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 253, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_v_out = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = PyObject_RichCompare(__pyx_t_4, __pyx_float_3_9, Py_LT); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 254, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__pyx_t_5) {
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 254, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = __pyx_t_3;
    __pyx_t_3 = 0;
  } else {
    __Pyx_INCREF(__pyx_float_3_8);
    __pyx_t_1 = __pyx_float_3_8;
  }
  __pyx_v_version = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_decompile); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_INCREF(__pyx_v_version);
  __Pyx_GIVEREF(__pyx_v_version);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_version);
  __Pyx_INCREF(__pyx_v_bytecode);
  __Pyx_GIVEREF(__pyx_v_bytecode);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_v_bytecode);
  __Pyx_INCREF(__pyx_v_out);
  __Pyx_GIVEREF(__pyx_v_out);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_v_out);
  __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_showast, Py_False) < 0) __PYX_ERR(0, 255, __pyx_L1_error)
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 255, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_out, __pyx_n_s_getvalue); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyNumber_Add(__pyx_t_2, __pyx_kp_u__15); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 256, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_data = __pyx_t_4;
  __pyx_t_4 = 0;

  
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 257, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = PyObject_RichCompare(__pyx_t_4, __pyx_v_data, Py_EQ); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 257, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 257, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(__pyx_t_5)) {

    
    __pyx_t_2 = __Pyx_PyObject_CallNoArg(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0]))); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 258, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_Raise(__pyx_t_2, 0, 0, 0);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __PYX_ERR(0, 258, __pyx_L1_error)

    
  }

  
  __Pyx_XDECREF(__pyx_r);
  if (!(likely(PyUnicode_CheckExact(__pyx_v_data))||((__pyx_v_data) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_v_data)->tp_name), 0))) __PYX_ERR(0, 259, __pyx_L1_error)
  __Pyx_INCREF(__pyx_v_data);
  __pyx_r = ((PyObject*)__pyx_v_data);
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.machine_code", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_out);
  __Pyx_XDECREF(__pyx_v_version);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_23machine_code_py2(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_23machine_code_py2 = {"machine_code_py2", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_23machine_code_py2, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_23machine_code_py2(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("machine_code_py2 (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_22machine_code_py2(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_22machine_code_py2(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_file_name = NULL;
  PyObject *__pyx_v_file = NULL;
  PyObject *__pyx_v_out = NULL;
  PyObject *__pyx_v_err = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  int __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  int __pyx_t_16;
  char const *__pyx_t_17;
  PyObject *__pyx_t_18 = NULL;
  PyObject *__pyx_t_19 = NULL;
  PyObject *__pyx_t_20 = NULL;
  PyObject *__pyx_t_21 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("machine_code_py2", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_sys); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_argv); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_4, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_endswith); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
    }
  }
  __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_kp_u_pyc) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_kp_u_pyc);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 262, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_5) {
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sys); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_argv); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_4, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyNumber_Add(__pyx_kp_u__23, __pyx_t_2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_1 = __pyx_t_4;
    __pyx_t_4 = 0;
  } else {
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_sys); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_argv); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_GetItemInt(__pyx_t_2, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = PyNumber_Add(__pyx_kp_u__23, __pyx_t_4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyNumber_Add(__pyx_t_2, __pyx_kp_u_pyc); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 262, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_1 = __pyx_t_4;
    __pyx_t_4 = 0;
  }
  __pyx_v_file_name = __pyx_t_1;
  __pyx_t_1 = 0;

  
   {
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 263, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_file_name);
    __Pyx_GIVEREF(__pyx_v_file_name);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_file_name);
    __Pyx_INCREF(__pyx_n_u_wb);
    __Pyx_GIVEREF(__pyx_n_u_wb);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_wb);
    __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_1, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 263, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_6 = __Pyx_PyObject_LookupSpecial(__pyx_t_4, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 263, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_2 = __Pyx_PyObject_LookupSpecial(__pyx_t_4, __pyx_n_s_enter); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 263, __pyx_L3_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_3)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_3);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 263, __pyx_L3_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __pyx_t_1;
    __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
     {
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_7, &__pyx_t_8, &__pyx_t_9);
        __Pyx_XGOTREF(__pyx_t_7);
        __Pyx_XGOTREF(__pyx_t_8);
        __Pyx_XGOTREF(__pyx_t_9);
         {
          __pyx_v_file = __pyx_t_2;
          __pyx_t_2 = 0;

          
          __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_write); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 264, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_4);
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 264, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_3 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
            __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
            if (likely(__pyx_t_3)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
              __Pyx_INCREF(__pyx_t_3);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_4, function);
            }
          }
          __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_1);
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 264, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
        }
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        goto __pyx_L12_try_end;
        __pyx_L7_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
         {
          __Pyx_AddTraceback("decode.DecodingAlgorithms.machine_code_py2", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_4, &__pyx_t_1) < 0) __PYX_ERR(0, 263, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_GOTREF(__pyx_t_4);
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_3 = PyTuple_Pack(3, __pyx_t_2, __pyx_t_4, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 263, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_10 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_3, NULL);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 263, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          if (__pyx_t_5 < 0) __PYX_ERR(0, 263, __pyx_L9_except_error)
          __pyx_t_11 = ((!(__pyx_t_5 != 0)) != 0);
          if (__pyx_t_11) {
            __Pyx_GIVEREF(__pyx_t_2);
            __Pyx_GIVEREF(__pyx_t_4);
            __Pyx_XGIVEREF(__pyx_t_1);
            __Pyx_ErrRestoreWithState(__pyx_t_2, __pyx_t_4, __pyx_t_1);
            __pyx_t_2 = 0; __pyx_t_4 = 0; __pyx_t_1 = 0; 
            __PYX_ERR(0, 263, __pyx_L9_except_error)
          }
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          goto __pyx_L8_exception_handled;
        }
        __pyx_L9_except_error:;
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_7, __pyx_t_8, __pyx_t_9);
        goto __pyx_L1_error;
        __pyx_L8_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_7, __pyx_t_8, __pyx_t_9);
        __pyx_L12_try_end:;
      }
    }
     {
      {
        if (__pyx_t_6) {
          __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__16, NULL);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 263, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        }
        goto __pyx_L6;
      }
      __pyx_L6:;
    }
    goto __pyx_L16;
    __pyx_L3_error:;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    goto __pyx_L1_error;
    __pyx_L16:;
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_io); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_StringIO); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_4)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_4);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 265, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_out = __pyx_t_1;
  __pyx_t_1 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_9, &__pyx_t_8);
    __Pyx_XGOTREF(__pyx_t_6);
    __Pyx_XGOTREF(__pyx_t_9);
    __Pyx_XGOTREF(__pyx_t_8);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_decompile_file); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 267, __pyx_L17_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_2 = PyTuple_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 267, __pyx_L17_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_INCREF(__pyx_v_file_name);
      __Pyx_GIVEREF(__pyx_v_file_name);
      PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_file_name);
      __pyx_t_4 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 267, __pyx_L17_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_t_4, __pyx_n_s_outstream, __pyx_v_out) < 0) __PYX_ERR(0, 267, __pyx_L17_error)
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 267, __pyx_L17_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_os); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 268, __pyx_L17_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_remove); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 268, __pyx_L17_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
        __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
        if (likely(__pyx_t_4)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
          __Pyx_INCREF(__pyx_t_4);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_2, function);
        }
      }
      __pyx_t_3 = (__pyx_t_4) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_4, __pyx_v_file_name) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_file_name);
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 268, __pyx_L17_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
    __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
    goto __pyx_L22_try_end;
    __pyx_L17_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;

    
    __pyx_t_12 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_12) {
      __Pyx_AddTraceback("decode.DecodingAlgorithms.machine_code_py2", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_2, &__pyx_t_4) < 0) __PYX_ERR(0, 269, __pyx_L19_except_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_2);
      __pyx_v_err = __pyx_t_2;
       {

        
        __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_DEBUG_MODE); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 270, __pyx_L28_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_11 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_11 < 0)) __PYX_ERR(0, 270, __pyx_L28_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        if (__pyx_t_11) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_13, __pyx_n_s_console); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 271, __pyx_L28_error)
          __Pyx_GOTREF(__pyx_t_13);
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_13, __pyx_n_s_log); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 271, __pyx_L28_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
          __pyx_t_13 = __Pyx_PyObject_FormatSimple(__pyx_v_err, __pyx_empty_unicode); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 271, __pyx_L28_error)
          __Pyx_GOTREF(__pyx_t_13);
          __pyx_t_15 = __Pyx_PyUnicode_Concat(__pyx_kp_u_ERROR, __pyx_t_13); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 271, __pyx_L28_error)
          __Pyx_GOTREF(__pyx_t_15);
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
          __pyx_t_13 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_13)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_13);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
            }
          }
          __pyx_t_1 = (__pyx_t_13) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_13, __pyx_t_15) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_15);
          __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
          if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 271, __pyx_L28_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
        }

        
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_os); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 272, __pyx_L28_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_15 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_remove); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 272, __pyx_L28_error)
        __Pyx_GOTREF(__pyx_t_15);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_14 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_15))) {
          __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_15);
          if (likely(__pyx_t_14)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_15);
            __Pyx_INCREF(__pyx_t_14);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_15, function);
          }
        }
        __pyx_t_1 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_15, __pyx_t_14, __pyx_v_file_name) : __Pyx_PyObject_CallOneArg(__pyx_t_15, __pyx_v_file_name);
        __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 272, __pyx_L28_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

        
        __pyx_t_1 = __Pyx_PyObject_CallOneArg(((PyObject *)(&PyUnicode_Type)), __pyx_v_err); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 273, __pyx_L28_error)
        __Pyx_GOTREF(__pyx_t_1);
        __pyx_t_15 = __Pyx_PyObject_CallOneArg(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])), __pyx_t_1); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 273, __pyx_L28_error)
        __Pyx_GOTREF(__pyx_t_15);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_Raise(__pyx_t_15, 0, 0, 0);
        __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
        __PYX_ERR(0, 273, __pyx_L28_error)
      }

      
       {
        __pyx_L28_error:;
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __pyx_t_7 = 0; __pyx_t_10 = 0; __pyx_t_18 = 0; __pyx_t_19 = 0; __pyx_t_20 = 0; __pyx_t_21 = 0;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
          if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_19, &__pyx_t_20, &__pyx_t_21);
          if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_7, &__pyx_t_10, &__pyx_t_18) < 0)) __Pyx_ErrFetch(&__pyx_t_7, &__pyx_t_10, &__pyx_t_18);
          __Pyx_XGOTREF(__pyx_t_7);
          __Pyx_XGOTREF(__pyx_t_10);
          __Pyx_XGOTREF(__pyx_t_18);
          __Pyx_XGOTREF(__pyx_t_19);
          __Pyx_XGOTREF(__pyx_t_20);
          __Pyx_XGOTREF(__pyx_t_21);
          __pyx_t_12 = __pyx_lineno; __pyx_t_16 = __pyx_clineno; __pyx_t_17 = __pyx_filename;
          {
            __Pyx_DECREF(__pyx_v_err);
            __pyx_v_err = NULL;
          }
          if (PY_MAJOR_VERSION >= 3) {
            __Pyx_XGIVEREF(__pyx_t_19);
            __Pyx_XGIVEREF(__pyx_t_20);
            __Pyx_XGIVEREF(__pyx_t_21);
            __Pyx_ExceptionReset(__pyx_t_19, __pyx_t_20, __pyx_t_21);
          }
          __Pyx_XGIVEREF(__pyx_t_7);
          __Pyx_XGIVEREF(__pyx_t_10);
          __Pyx_XGIVEREF(__pyx_t_18);
          __Pyx_ErrRestore(__pyx_t_7, __pyx_t_10, __pyx_t_18);
          __pyx_t_7 = 0; __pyx_t_10 = 0; __pyx_t_18 = 0; __pyx_t_19 = 0; __pyx_t_20 = 0; __pyx_t_21 = 0;
          __pyx_lineno = __pyx_t_12; __pyx_clineno = __pyx_t_16; __pyx_filename = __pyx_t_17;
          goto __pyx_L19_except_error;
        }
      }
    }
    goto __pyx_L19_except_error;
    __pyx_L19_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_6);
    __Pyx_XGIVEREF(__pyx_t_9);
    __Pyx_XGIVEREF(__pyx_t_8);
    __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_9, __pyx_t_8);
    goto __pyx_L1_error;
    __pyx_L22_try_end:;
  }

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_out, __pyx_n_s_getvalue); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_15 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_15 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_15)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_15);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_2 = (__pyx_t_15) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_15) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_split); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_4 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_kp_u__15) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_u__15);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetSlice(__pyx_t_4, 4, 0, NULL, NULL, &__pyx_slice__21, 1, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = PyUnicode_Join(__pyx_kp_u__15, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyUnicode_Concat(__pyx_t_4, __pyx_kp_u__15); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 274, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_r = ((PyObject*)__pyx_t_3);
  __pyx_t_3 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.machine_code_py2", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_file_name);
  __Pyx_XDECREF(__pyx_v_file);
  __Pyx_XDECREF(__pyx_v_out);
  __Pyx_XDECREF(__pyx_v_err);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_25zip_code(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_25zip_code = {"zip_code", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_25zip_code, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_25zip_code(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("zip_code (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_24zip_code(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_24zip_code(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_zip_ref = NULL;
  PyObject *__pyx_v_file = NULL;
  PyObject *__pyx_v_f = NULL;
  PyObject *__pyx_v_output = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  Py_ssize_t __pyx_t_11;
  PyObject *(*__pyx_t_12)(PyObject *);
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  int __pyx_t_19;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("zip_code", 0);

  
   {
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_zipfile); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_ZipFile); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = NULL;
    __pyx_t_5 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
        __pyx_t_5 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_3)) {
      PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_n_u_r};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 277, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
      PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_2, __pyx_n_u_r};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 277, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    } else
    #endif
    {
      __pyx_t_6 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 277, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      if (__pyx_t_4) {
        __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_t_4); __pyx_t_4 = NULL;
      }
      __Pyx_GIVEREF(__pyx_t_2);
      PyTuple_SET_ITEM(__pyx_t_6, 0+__pyx_t_5, __pyx_t_2);
      __Pyx_INCREF(__pyx_n_u_r);
      __Pyx_GIVEREF(__pyx_n_u_r);
      PyTuple_SET_ITEM(__pyx_t_6, 1+__pyx_t_5, __pyx_n_u_r);
      __pyx_t_2 = 0;
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 277, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    }
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_7 = __Pyx_PyObject_LookupSpecial(__pyx_t_1, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 277, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __pyx_t_6 = __Pyx_PyObject_LookupSpecial(__pyx_t_1, __pyx_n_s_enter); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 277, __pyx_L3_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_6);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_6, function);
      }
    }
    __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 277, __pyx_L3_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __pyx_t_6 = __pyx_t_3;
    __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
     {
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_8, &__pyx_t_9, &__pyx_t_10);
        __Pyx_XGOTREF(__pyx_t_8);
        __Pyx_XGOTREF(__pyx_t_9);
        __Pyx_XGOTREF(__pyx_t_10);
         {
          __pyx_v_zip_ref = __pyx_t_6;
          __pyx_t_6 = 0;

          
          __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_zip_ref, __pyx_n_s_infolist); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 278, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_3 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
            __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_1);
            if (likely(__pyx_t_3)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
              __Pyx_INCREF(__pyx_t_3);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_1, function);
            }
          }
          __pyx_t_6 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 278, __pyx_L7_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (likely(PyList_CheckExact(__pyx_t_6)) || PyTuple_CheckExact(__pyx_t_6)) {
            __pyx_t_1 = __pyx_t_6; __Pyx_INCREF(__pyx_t_1); __pyx_t_11 = 0;
            __pyx_t_12 = NULL;
          } else {
            __pyx_t_11 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 278, __pyx_L7_error)
            __Pyx_GOTREF(__pyx_t_1);
            __pyx_t_12 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 278, __pyx_L7_error)
          }
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          for (;;) {
            if (likely(!__pyx_t_12)) {
              if (likely(PyList_CheckExact(__pyx_t_1))) {
                if (__pyx_t_11 >= PyList_GET_SIZE(__pyx_t_1)) break;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                __pyx_t_6 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_11); __Pyx_INCREF(__pyx_t_6); __pyx_t_11++; if (unlikely(0 < 0)) __PYX_ERR(0, 278, __pyx_L7_error)
                #else
                __pyx_t_6 = PySequence_ITEM(__pyx_t_1, __pyx_t_11); __pyx_t_11++; if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 278, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_6);
                #endif
              } else {
                if (__pyx_t_11 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                __pyx_t_6 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_11); __Pyx_INCREF(__pyx_t_6); __pyx_t_11++; if (unlikely(0 < 0)) __PYX_ERR(0, 278, __pyx_L7_error)
                #else
                __pyx_t_6 = PySequence_ITEM(__pyx_t_1, __pyx_t_11); __pyx_t_11++; if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 278, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_6);
                #endif
              }
            } else {
              __pyx_t_6 = __pyx_t_12(__pyx_t_1);
              if (unlikely(!__pyx_t_6)) {
                PyObject* exc_type = PyErr_Occurred();
                if (exc_type) {
                  if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                  else __PYX_ERR(0, 278, __pyx_L7_error)
                }
                break;
              }
              __Pyx_GOTREF(__pyx_t_6);
            }
            __Pyx_XDECREF_SET(__pyx_v_file, __pyx_t_6);
            __pyx_t_6 = 0;

            
            __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_filename); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 279, __pyx_L7_error)
            __Pyx_GOTREF(__pyx_t_6);
            __pyx_t_13 = (__Pyx_PyUnicode_Equals(__pyx_t_6, __pyx_kp_u_main___py, Py_EQ)); if (unlikely(__pyx_t_13 < 0)) __PYX_ERR(0, 279, __pyx_L7_error)
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (__pyx_t_13) {

              
              __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_zip_ref, __pyx_n_s_extract); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 280, __pyx_L7_error)
              __Pyx_GOTREF(__pyx_t_3);
              __pyx_t_2 = NULL;
              __pyx_t_5 = 0;
              if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
                __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
                if (likely(__pyx_t_2)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
                  __Pyx_INCREF(__pyx_t_2);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_3, function);
                  __pyx_t_5 = 1;
                }
              }
              #if CYTHON_FAST_PYCALL
              if (PyFunction_Check(__pyx_t_3)) {
                PyObject *__pyx_temp[3] = {__pyx_t_2, __pyx_v_file, __pyx_kp_u__23};
                __pyx_t_6 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 280, __pyx_L7_error)
                __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                __Pyx_GOTREF(__pyx_t_6);
              } else
              #endif
              #if CYTHON_FAST_PYCCALL
              if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
                PyObject *__pyx_temp[3] = {__pyx_t_2, __pyx_v_file, __pyx_kp_u__23};
                __pyx_t_6 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_5, 2+__pyx_t_5); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 280, __pyx_L7_error)
                __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                __Pyx_GOTREF(__pyx_t_6);
              } else
              #endif
              {
                __pyx_t_4 = PyTuple_New(2+__pyx_t_5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 280, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_4);
                if (__pyx_t_2) {
                  __Pyx_GIVEREF(__pyx_t_2); PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_2); __pyx_t_2 = NULL;
                }
                __Pyx_INCREF(__pyx_v_file);
                __Pyx_GIVEREF(__pyx_v_file);
                PyTuple_SET_ITEM(__pyx_t_4, 0+__pyx_t_5, __pyx_v_file);
                __Pyx_INCREF(__pyx_kp_u__23);
                __Pyx_GIVEREF(__pyx_kp_u__23);
                PyTuple_SET_ITEM(__pyx_t_4, 1+__pyx_t_5, __pyx_kp_u__23);
                __pyx_t_6 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_4, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 280, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_6);
                __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
              }
              __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
              __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;

              
               {
                __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_filename); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 281, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_6);
                __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 281, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_3);
                __Pyx_GIVEREF(__pyx_t_6);
                PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_6);
                __Pyx_INCREF(__pyx_n_u_r);
                __Pyx_GIVEREF(__pyx_n_u_r);
                PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_n_u_r);
                __pyx_t_6 = 0;
                __pyx_t_6 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_3, NULL); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 281, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_6);
                __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
                __pyx_t_14 = __Pyx_PyObject_LookupSpecial(__pyx_t_6, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 281, __pyx_L7_error)
                __Pyx_GOTREF(__pyx_t_14);
                __pyx_t_4 = __Pyx_PyObject_LookupSpecial(__pyx_t_6, __pyx_n_s_enter); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 281, __pyx_L16_error)
                __Pyx_GOTREF(__pyx_t_4);
                __pyx_t_2 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
                  __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
                  if (likely(__pyx_t_2)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
                    __Pyx_INCREF(__pyx_t_2);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_4, function);
                  }
                }
                __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_4);
                __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 281, __pyx_L16_error)
                __Pyx_GOTREF(__pyx_t_3);
                __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
                __pyx_t_4 = __pyx_t_3;
                __pyx_t_3 = 0;
                __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
                 {
                  {
                    __Pyx_PyThreadState_declare
                    __Pyx_PyThreadState_assign
                    __Pyx_ExceptionSave(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17);
                    __Pyx_XGOTREF(__pyx_t_15);
                    __Pyx_XGOTREF(__pyx_t_16);
                    __Pyx_XGOTREF(__pyx_t_17);
                     {
                      __pyx_v_f = __pyx_t_4;
                      __pyx_t_4 = 0;

                      
                      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_f, __pyx_n_s_read); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 282, __pyx_L22_error)
                      __Pyx_GOTREF(__pyx_t_6);
                      __pyx_t_3 = NULL;
                      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_6))) {
                        __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_6);
                        if (likely(__pyx_t_3)) {
                          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
                          __Pyx_INCREF(__pyx_t_3);
                          __Pyx_INCREF(function);
                          __Pyx_DECREF_SET(__pyx_t_6, function);
                        }
                      }
                      __pyx_t_4 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
                      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 282, __pyx_L22_error)
                      __Pyx_GOTREF(__pyx_t_4);
                      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
                      __pyx_v_output = __pyx_t_4;
                      __pyx_t_4 = 0;

                      
                    }
                    __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
                    __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
                    __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
                    goto __pyx_L29_try_end;
                    __pyx_L22_error:;
                    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
                    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
                     {
                      __Pyx_AddTraceback("decode.DecodingAlgorithms.zip_code", __pyx_clineno, __pyx_lineno, __pyx_filename);
                      if (__Pyx_GetException(&__pyx_t_4, &__pyx_t_6, &__pyx_t_3) < 0) __PYX_ERR(0, 281, __pyx_L24_except_error)
                      __Pyx_GOTREF(__pyx_t_4);
                      __Pyx_GOTREF(__pyx_t_6);
                      __Pyx_GOTREF(__pyx_t_3);
                      __pyx_t_2 = PyTuple_Pack(3, __pyx_t_4, __pyx_t_6, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 281, __pyx_L24_except_error)
                      __Pyx_GOTREF(__pyx_t_2);
                      __pyx_t_18 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_t_2, NULL);
                      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
                      if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 281, __pyx_L24_except_error)
                      __Pyx_GOTREF(__pyx_t_18);
                      __pyx_t_13 = __Pyx_PyObject_IsTrue(__pyx_t_18);
                      __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
                      if (__pyx_t_13 < 0) __PYX_ERR(0, 281, __pyx_L24_except_error)
                      __pyx_t_19 = ((!(__pyx_t_13 != 0)) != 0);
                      if (__pyx_t_19) {
                        __Pyx_GIVEREF(__pyx_t_4);
                        __Pyx_GIVEREF(__pyx_t_6);
                        __Pyx_XGIVEREF(__pyx_t_3);
                        __Pyx_ErrRestoreWithState(__pyx_t_4, __pyx_t_6, __pyx_t_3);
                        __pyx_t_4 = 0; __pyx_t_6 = 0; __pyx_t_3 = 0; 
                        __PYX_ERR(0, 281, __pyx_L24_except_error)
                      }
                      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
                      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
                      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                      goto __pyx_L23_exception_handled;
                    }
                    __pyx_L24_except_error:;
                    __Pyx_XGIVEREF(__pyx_t_15);
                    __Pyx_XGIVEREF(__pyx_t_16);
                    __Pyx_XGIVEREF(__pyx_t_17);
                    __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
                    goto __pyx_L7_error;
                    __pyx_L23_exception_handled:;
                    __Pyx_XGIVEREF(__pyx_t_15);
                    __Pyx_XGIVEREF(__pyx_t_16);
                    __Pyx_XGIVEREF(__pyx_t_17);
                    __Pyx_ExceptionReset(__pyx_t_15, __pyx_t_16, __pyx_t_17);
                    __pyx_L29_try_end:;
                  }
                }
                 {
                  {
                    if (__pyx_t_14) {
                      __pyx_t_17 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_tuple__16, NULL);
                      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                      if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 281, __pyx_L7_error)
                      __Pyx_GOTREF(__pyx_t_17);
                      __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
                    }
                    goto __pyx_L21;
                  }
                  __pyx_L21:;
                }
                goto __pyx_L33;
                __pyx_L16_error:;
                __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                goto __pyx_L7_error;
                __pyx_L33:;
              }

              
              __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_os); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 283, __pyx_L7_error)
              __Pyx_GOTREF(__pyx_t_6);
              __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_remove); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 283, __pyx_L7_error)
              __Pyx_GOTREF(__pyx_t_4);
              __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
              __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_filename); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 283, __pyx_L7_error)
              __Pyx_GOTREF(__pyx_t_6);
              __pyx_t_2 = NULL;
              if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
                __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_4);
                if (likely(__pyx_t_2)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
                  __Pyx_INCREF(__pyx_t_2);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_4, function);
                }
              }
              __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_2, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_t_6);
              __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
              __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
              if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 283, __pyx_L7_error)
              __Pyx_GOTREF(__pyx_t_3);
              __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
              __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

              
              goto __pyx_L14_break;

              
            }

            
          }
          __pyx_L14_break:;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
        }
        __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        goto __pyx_L12_try_end;
        __pyx_L7_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
         {
          __Pyx_AddTraceback("decode.DecodingAlgorithms.zip_code", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_1, &__pyx_t_3, &__pyx_t_4) < 0) __PYX_ERR(0, 277, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GOTREF(__pyx_t_4);
          __pyx_t_6 = PyTuple_Pack(3, __pyx_t_1, __pyx_t_3, __pyx_t_4); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 277, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_t_6, NULL);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 277, __pyx_L9_except_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_19 = __Pyx_PyObject_IsTrue(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (__pyx_t_19 < 0) __PYX_ERR(0, 277, __pyx_L9_except_error)
          __pyx_t_13 = ((!(__pyx_t_19 != 0)) != 0);
          if (__pyx_t_13) {
            __Pyx_GIVEREF(__pyx_t_1);
            __Pyx_GIVEREF(__pyx_t_3);
            __Pyx_XGIVEREF(__pyx_t_4);
            __Pyx_ErrRestoreWithState(__pyx_t_1, __pyx_t_3, __pyx_t_4);
            __pyx_t_1 = 0; __pyx_t_3 = 0; __pyx_t_4 = 0; 
            __PYX_ERR(0, 277, __pyx_L9_except_error)
          }
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          goto __pyx_L8_exception_handled;
        }
        __pyx_L9_except_error:;
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
        goto __pyx_L1_error;
        __pyx_L8_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
        __pyx_L12_try_end:;
      }
    }
     {
      {
        if (__pyx_t_7) {
          __pyx_t_10 = __Pyx_PyObject_Call(__pyx_t_7, __pyx_tuple__16, NULL);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 277, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        }
        goto __pyx_L6;
      }
      __pyx_L6:;
    }
    goto __pyx_L37;
    __pyx_L3_error:;
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    goto __pyx_L1_error;
    __pyx_L37:;
  }

  
  __Pyx_XDECREF(__pyx_r);
  if (unlikely(!__pyx_v_output)) { __Pyx_RaiseUnboundLocalError("output"); __PYX_ERR(0, 285, __pyx_L1_error) }
  if (!(likely(PyUnicode_CheckExact(__pyx_v_output))||((__pyx_v_output) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_v_output)->tp_name), 0))) __PYX_ERR(0, 285, __pyx_L1_error)
  __Pyx_INCREF(__pyx_v_output);
  __pyx_r = ((PyObject*)__pyx_v_output);
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.zip_code", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_zip_ref);
  __Pyx_XDECREF(__pyx_v_file);
  __Pyx_XDECREF(__pyx_v_f);
  __Pyx_XDECREF(__pyx_v_output);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_27abdullah_encrypt(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_27abdullah_encrypt = {"abdullah_encrypt", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_27abdullah_encrypt, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_27abdullah_encrypt(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("abdullah_encrypt (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_26abdullah_encrypt(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_26abdullah_encrypt(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_v_const = NULL;
  PyObject *__pyx_v_in_source = NULL;
  PyObject *__pyx_v_source = NULL;
  PyObject *__pyx_v_char1 = NULL;
  PyObject *__pyx_v_char2 = NULL;
  PyObject *__pyx_v_err = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *(*__pyx_t_4)(PyObject *);
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  Py_ssize_t __pyx_t_9;
  Py_ssize_t __pyx_t_10;
  int __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  int __pyx_t_14;
  int __pyx_t_15;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  PyObject *__pyx_t_19 = NULL;
  char const *__pyx_t_20;
  PyObject *__pyx_t_21 = NULL;
  PyObject *__pyx_t_22 = NULL;
  PyObject *__pyx_t_23 = NULL;
  PyObject *__pyx_t_24 = NULL;
  PyObject *__pyx_t_25 = NULL;
  PyObject *__pyx_t_26 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("abdullah_encrypt", 0);

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 288, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 288, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_string);
  __Pyx_GIVEREF(__pyx_n_u_string);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_n_u_string);
  __Pyx_INCREF(__pyx_n_u_exec);
  __Pyx_GIVEREF(__pyx_n_u_exec);
  PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_n_u_exec);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 288, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_bytecode = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(52); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 290, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__24, __pyx_n_u_q) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__25, __pyx_n_u_Q) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__26, __pyx_n_u_w) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__27, __pyx_n_u_W) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__28, __pyx_n_u_e) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__29, __pyx_n_u_E) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__30, __pyx_n_u_r) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__31, __pyx_n_u_R) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__32, __pyx_n_u_t) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__33, __pyx_n_u_T) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__34, __pyx_n_u_y) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__35, __pyx_n_u_Y) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__36, __pyx_n_u_u) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__37, __pyx_n_u_U) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__38, __pyx_n_u_i) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__39, __pyx_n_u_I) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__40, __pyx_n_u_o) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__41, __pyx_n_u_O) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__42, __pyx_n_u_p) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__43, __pyx_n_u_P) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__44, __pyx_n_u_a) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__45, __pyx_n_u_A) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__46, __pyx_n_u_s_2) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__47, __pyx_n_u_S) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__48, __pyx_n_u_d) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__49, __pyx_n_u_D) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__50, __pyx_n_u_f) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__51, __pyx_n_u_F) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__52, __pyx_n_u_g) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__53, __pyx_n_u_G) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__54, __pyx_n_u_h) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__55, __pyx_n_u_H) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__56, __pyx_n_u_j) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__57, __pyx_n_u_J) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_kp_u__58, __pyx_n_u_k) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__59, __pyx_n_u_K) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__60, __pyx_n_u_l) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__61, __pyx_n_u_L) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__62, __pyx_n_u_z) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__63, __pyx_n_u_Z) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__64, __pyx_n_u_x) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__65, __pyx_n_u_X) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__66, __pyx_n_u_c) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__67, __pyx_n_u_C) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__68, __pyx_n_u_v) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__69, __pyx_n_u_V) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__70, __pyx_n_u_b) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__71, __pyx_n_u_B) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__72, __pyx_n_u_n) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__73, __pyx_n_u_N) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__74, __pyx_n_u_m) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_u__75, __pyx_n_u_M) < 0) __PYX_ERR(0, 290, __pyx_L1_error)
  __pyx_v_data = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 343, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
    __pyx_t_4 = NULL;
  } else {
    __pyx_t_3 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 343, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 343, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_4)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 343, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 343, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_3 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 343, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 343, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_4(__pyx_t_2);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 343, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    __Pyx_XDECREF_SET(__pyx_v_const, __pyx_t_1);
    __pyx_t_1 = 0;

    
    __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_const)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 344, __pyx_L1_error)
    __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 344, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_5) {

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_7, &__pyx_t_8);
        __Pyx_XGOTREF(__pyx_t_6);
        __Pyx_XGOTREF(__pyx_t_7);
        __Pyx_XGOTREF(__pyx_t_8);
         {

          
          __Pyx_INCREF(__pyx_int_0);
          __Pyx_XDECREF_SET(__pyx_v_in_source, __pyx_int_0);

          
          __Pyx_INCREF(__pyx_v_const);
          __Pyx_XDECREF_SET(__pyx_v_source, __pyx_v_const);

          
          __pyx_t_9 = 0;
          __pyx_t_12 = __Pyx_dict_iterator(__pyx_v_data, 1, __pyx_n_s_items, (&__pyx_t_10), (&__pyx_t_11)); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 348, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_XDECREF(__pyx_t_1);
          __pyx_t_1 = __pyx_t_12;
          __pyx_t_12 = 0;
          while (1) {
            __pyx_t_14 = __Pyx_dict_iter_next(__pyx_t_1, __pyx_t_10, &__pyx_t_9, &__pyx_t_12, &__pyx_t_13, NULL, __pyx_t_11);
            if (unlikely(__pyx_t_14 == 0)) break;
            if (unlikely(__pyx_t_14 == -1)) __PYX_ERR(0, 348, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_12);
            __Pyx_GOTREF(__pyx_t_13);
            __Pyx_XDECREF_SET(__pyx_v_char1, __pyx_t_12);
            __pyx_t_12 = 0;
            __Pyx_XDECREF_SET(__pyx_v_char2, __pyx_t_13);
            __pyx_t_13 = 0;

            
            __pyx_t_5 = (__Pyx_PySequence_ContainsTF(__pyx_v_char1, __pyx_v_source, Py_EQ)); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 349, __pyx_L6_error)
            __pyx_t_15 = (__pyx_t_5 != 0);
            if (__pyx_t_15) {

              
              __pyx_t_13 = __Pyx_PyInt_AddObjC(__pyx_v_in_source, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 350, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_13);
              __Pyx_DECREF_SET(__pyx_v_in_source, __pyx_t_13);
              __pyx_t_13 = 0;

              
            }

            
            __pyx_t_12 = __Pyx_PyObject_GetAttrStr(__pyx_v_source, __pyx_n_s_replace); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 351, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_12);
            __pyx_t_16 = NULL;
            __pyx_t_14 = 0;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_12))) {
              __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_12);
              if (likely(__pyx_t_16)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_12);
                __Pyx_INCREF(__pyx_t_16);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_12, function);
                __pyx_t_14 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_12)) {
              PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_v_char1, __pyx_v_char2};
              __pyx_t_13 = __Pyx_PyFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_14, 2+__pyx_t_14); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 351, __pyx_L6_error)
              __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
              __Pyx_GOTREF(__pyx_t_13);
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_12)) {
              PyObject *__pyx_temp[3] = {__pyx_t_16, __pyx_v_char1, __pyx_v_char2};
              __pyx_t_13 = __Pyx_PyCFunction_FastCall(__pyx_t_12, __pyx_temp+1-__pyx_t_14, 2+__pyx_t_14); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 351, __pyx_L6_error)
              __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
              __Pyx_GOTREF(__pyx_t_13);
            } else
            #endif
            {
              __pyx_t_17 = PyTuple_New(2+__pyx_t_14); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 351, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_17);
              if (__pyx_t_16) {
                __Pyx_GIVEREF(__pyx_t_16); PyTuple_SET_ITEM(__pyx_t_17, 0, __pyx_t_16); __pyx_t_16 = NULL;
              }
              __Pyx_INCREF(__pyx_v_char1);
              __Pyx_GIVEREF(__pyx_v_char1);
              PyTuple_SET_ITEM(__pyx_t_17, 0+__pyx_t_14, __pyx_v_char1);
              __Pyx_INCREF(__pyx_v_char2);
              __Pyx_GIVEREF(__pyx_v_char2);
              PyTuple_SET_ITEM(__pyx_t_17, 1+__pyx_t_14, __pyx_v_char2);
              __pyx_t_13 = __Pyx_PyObject_Call(__pyx_t_12, __pyx_t_17, NULL); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 351, __pyx_L6_error)
              __Pyx_GOTREF(__pyx_t_13);
              __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            }
            __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
            __Pyx_DECREF_SET(__pyx_v_source, __pyx_t_13);
            __pyx_t_13 = 0;
          }
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 352, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_INCREF(__pyx_v_source);
          __Pyx_GIVEREF(__pyx_v_source);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_source);
          __Pyx_INCREF(__pyx_n_u_string);
          __Pyx_GIVEREF(__pyx_n_u_string);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_string);
          __Pyx_INCREF(__pyx_n_u_exec);
          __Pyx_GIVEREF(__pyx_n_u_exec);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_n_u_exec);
          __pyx_t_13 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_1, NULL); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 352, __pyx_L6_error)
          __Pyx_GOTREF(__pyx_t_13);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;

          
          __pyx_t_13 = PyObject_RichCompare(__pyx_v_in_source, __pyx_int_10, Py_GT); __Pyx_XGOTREF(__pyx_t_13); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 353, __pyx_L6_error)
          __pyx_t_15 = __Pyx_PyObject_IsTrue(__pyx_t_13); if (unlikely(__pyx_t_15 < 0)) __PYX_ERR(0, 353, __pyx_L6_error)
          __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
          if (likely(__pyx_t_15)) {

            
            __Pyx_XDECREF(__pyx_r);
            __Pyx_INCREF(__pyx_v_source);
            __pyx_r = __pyx_v_source;
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            goto __pyx_L10_try_return;

            
          }

          
           {
            __pyx_t_13 = __Pyx_PyObject_CallNoArg(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0]))); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 356, __pyx_L6_error)
            __Pyx_GOTREF(__pyx_t_13);
            __Pyx_Raise(__pyx_t_13, 0, 0, 0);
            __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
            __PYX_ERR(0, 356, __pyx_L6_error)
          }

          
        }
        __pyx_L6_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
        __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
        __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
        __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;

        
        __pyx_t_11 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
        if (__pyx_t_11) {
          __Pyx_AddTraceback("decode.DecodingAlgorithms.abdullah_encrypt", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_13, &__pyx_t_1, &__pyx_t_12) < 0) __PYX_ERR(0, 357, __pyx_L8_except_error)
          __Pyx_GOTREF(__pyx_t_13);
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_INCREF(__pyx_t_1);
          __pyx_v_err = __pyx_t_1;
           {

            
            __Pyx_GetModuleGlobalName(__pyx_t_17, __pyx_n_s_DEBUG_MODE); if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 358, __pyx_L23_error)
            __Pyx_GOTREF(__pyx_t_17);
            __pyx_t_15 = __Pyx_PyObject_IsTrue(__pyx_t_17); if (unlikely(__pyx_t_15 < 0)) __PYX_ERR(0, 358, __pyx_L23_error)
            __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;
            if (__pyx_t_15) {

              
              __Pyx_GetModuleGlobalName(__pyx_t_16, __pyx_n_s_console); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 359, __pyx_L23_error)
              __Pyx_GOTREF(__pyx_t_16);
              __pyx_t_18 = __Pyx_PyObject_GetAttrStr(__pyx_t_16, __pyx_n_s_log); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 359, __pyx_L23_error)
              __Pyx_GOTREF(__pyx_t_18);
              __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
              __pyx_t_16 = __Pyx_PyObject_FormatSimple(__pyx_v_err, __pyx_empty_unicode); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 359, __pyx_L23_error)
              __Pyx_GOTREF(__pyx_t_16);
              __pyx_t_19 = __Pyx_PyUnicode_Concat(__pyx_kp_u_ERROR, __pyx_t_16); if (unlikely(!__pyx_t_19)) __PYX_ERR(0, 359, __pyx_L23_error)
              __Pyx_GOTREF(__pyx_t_19);
              __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
              __pyx_t_16 = NULL;
              if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_18))) {
                __pyx_t_16 = PyMethod_GET_SELF(__pyx_t_18);
                if (likely(__pyx_t_16)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_18);
                  __Pyx_INCREF(__pyx_t_16);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_18, function);
                }
              }
              __pyx_t_17 = (__pyx_t_16) ? __Pyx_PyObject_Call2Args(__pyx_t_18, __pyx_t_16, __pyx_t_19) : __Pyx_PyObject_CallOneArg(__pyx_t_18, __pyx_t_19);
              __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
              __Pyx_DECREF(__pyx_t_19); __pyx_t_19 = 0;
              if (unlikely(!__pyx_t_17)) __PYX_ERR(0, 359, __pyx_L23_error)
              __Pyx_GOTREF(__pyx_t_17);
              __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
              __Pyx_DECREF(__pyx_t_17); __pyx_t_17 = 0;

              
            }
          }

          
           {
            {
              __Pyx_DECREF(__pyx_v_err);
              __pyx_v_err = NULL;
              goto __pyx_L24;
            }
            __pyx_L23_error:;
            {
              __Pyx_PyThreadState_declare
              __Pyx_PyThreadState_assign
              __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_25 = 0; __pyx_t_26 = 0;
              __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
              __Pyx_XDECREF(__pyx_t_17); __pyx_t_17 = 0;
              __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
              __Pyx_XDECREF(__pyx_t_19); __pyx_t_19 = 0;
              if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_24, &__pyx_t_25, &__pyx_t_26);
              if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_21, &__pyx_t_22, &__pyx_t_23) < 0)) __Pyx_ErrFetch(&__pyx_t_21, &__pyx_t_22, &__pyx_t_23);
              __Pyx_XGOTREF(__pyx_t_21);
              __Pyx_XGOTREF(__pyx_t_22);
              __Pyx_XGOTREF(__pyx_t_23);
              __Pyx_XGOTREF(__pyx_t_24);
              __Pyx_XGOTREF(__pyx_t_25);
              __Pyx_XGOTREF(__pyx_t_26);
              __pyx_t_11 = __pyx_lineno; __pyx_t_14 = __pyx_clineno; __pyx_t_20 = __pyx_filename;
              {
                __Pyx_DECREF(__pyx_v_err);
                __pyx_v_err = NULL;
              }
              if (PY_MAJOR_VERSION >= 3) {
                __Pyx_XGIVEREF(__pyx_t_24);
                __Pyx_XGIVEREF(__pyx_t_25);
                __Pyx_XGIVEREF(__pyx_t_26);
                __Pyx_ExceptionReset(__pyx_t_24, __pyx_t_25, __pyx_t_26);
              }
              __Pyx_XGIVEREF(__pyx_t_21);
              __Pyx_XGIVEREF(__pyx_t_22);
              __Pyx_XGIVEREF(__pyx_t_23);
              __Pyx_ErrRestore(__pyx_t_21, __pyx_t_22, __pyx_t_23);
              __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_25 = 0; __pyx_t_26 = 0;
              __pyx_lineno = __pyx_t_11; __pyx_clineno = __pyx_t_14; __pyx_filename = __pyx_t_20;
              goto __pyx_L8_except_error;
            }
            __pyx_L24:;
          }
          __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
          goto __pyx_L7_exception_handled;
        }
        goto __pyx_L8_except_error;
        __pyx_L8_except_error:;

        
        __Pyx_XGIVEREF(__pyx_t_6);
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
        goto __pyx_L1_error;
        __pyx_L10_try_return:;
        __Pyx_XGIVEREF(__pyx_t_6);
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
        goto __pyx_L0;
        __pyx_L7_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_6);
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_7, __pyx_t_8);
      }

      
    }

    
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_Call(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])), __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 360, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_Raise(__pyx_t_2, 0, 0, 0);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __PYX_ERR(0, 360, __pyx_L1_error)

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_XDECREF(__pyx_t_17);
  __Pyx_XDECREF(__pyx_t_18);
  __Pyx_XDECREF(__pyx_t_19);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.abdullah_encrypt", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XDECREF(__pyx_v_const);
  __Pyx_XDECREF(__pyx_v_in_source);
  __Pyx_XDECREF(__pyx_v_source);
  __Pyx_XDECREF(__pyx_v_char1);
  __Pyx_XDECREF(__pyx_v_char2);
  __Pyx_XDECREF(__pyx_v_err);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_29exec_function(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_29exec_function = {"exec_function", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_29exec_function, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_29exec_function(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exec_function (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_28exec_function(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_1exec(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_1exec = {"exec", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_1exec, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_1exec(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exec (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "exec", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_exec(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_exec(PyObject *__pyx_self, PyObject *__pyx_v_args) {
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_cur_scope;
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_outer_scope;
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_commands = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  Py_ssize_t __pyx_t_8;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("exec", 0);
  __pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  
  __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 364, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 364, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_2) {

    
    __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 365, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_1)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 365, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 365, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (__pyx_t_2) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_OLD_COMPILE); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 366, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_4 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 366, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_5 = NULL;
      __pyx_t_6 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
          __pyx_t_6 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_1)) {
        PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_t_4, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 366, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
        PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_t_4, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 366, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      } else
      #endif
      {
        __pyx_t_7 = PyTuple_New(3+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 366, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        if (__pyx_t_5) {
          __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_5); __pyx_t_5 = NULL;
        }
        __Pyx_GIVEREF(__pyx_t_4);
        PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_6, __pyx_t_4);
        __Pyx_INCREF(__pyx_n_u_string);
        __Pyx_GIVEREF(__pyx_n_u_string);
        PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_6, __pyx_n_u_string);
        __Pyx_INCREF(__pyx_n_u_exec);
        __Pyx_GIVEREF(__pyx_n_u_exec);
        PyTuple_SET_ITEM(__pyx_t_7, 2+__pyx_t_6, __pyx_n_u_exec);
        __pyx_t_4 = 0;
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_7, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 366, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      }
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_v_bytecode = __pyx_t_3;
      __pyx_t_3 = 0;

      
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 367, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_v_commands = __pyx_t_3;
      __pyx_t_3 = 0;

      
      __pyx_t_8 = PyObject_Length(__pyx_v_commands); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 368, __pyx_L1_error)
      __pyx_t_2 = ((__pyx_t_8 > 1) != 0);
      if (__pyx_t_2) {

        
        __pyx_t_3 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 369, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 369, __pyx_L1_error) }
        if (__Pyx_PyObject_SetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data, __pyx_t_3) < 0) __PYX_ERR(0, 369, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

        
      }

      
      goto __pyx_L4;
    }

    
    __pyx_t_3 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 370, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_3)), ((PyObject *)(&PyBytes_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 370, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 370, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_2) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_OLD_COMPILE); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 371, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_7 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 371, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_4 = NULL;
      __pyx_t_6 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_4)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_4);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
          __pyx_t_6 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_3)) {
        PyObject *__pyx_temp[4] = {__pyx_t_4, __pyx_t_7, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 371, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
        PyObject *__pyx_temp[4] = {__pyx_t_4, __pyx_t_7, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 371, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      } else
      #endif
      {
        __pyx_t_5 = PyTuple_New(3+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 371, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        if (__pyx_t_4) {
          __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_4); __pyx_t_4 = NULL;
        }
        __Pyx_GIVEREF(__pyx_t_7);
        PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_t_7);
        __Pyx_INCREF(__pyx_n_u_string);
        __Pyx_GIVEREF(__pyx_n_u_string);
        PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_n_u_string);
        __Pyx_INCREF(__pyx_n_u_exec);
        __Pyx_GIVEREF(__pyx_n_u_exec);
        PyTuple_SET_ITEM(__pyx_t_5, 2+__pyx_t_6, __pyx_n_u_exec);
        __pyx_t_7 = 0;
        __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 371, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      }
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_bytecode = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 372, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_v_commands = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __pyx_t_8 = PyObject_Length(__pyx_v_commands); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 373, __pyx_L1_error)
      __pyx_t_2 = ((__pyx_t_8 > 1) != 0);
      if (__pyx_t_2) {

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_to_string); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 374, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_5 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 374, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_7 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_7, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_5);
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 374, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 374, __pyx_L1_error) }
        if (__Pyx_PyObject_SetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data, __pyx_t_1) < 0) __PYX_ERR(0, 374, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

        
      }

      
      goto __pyx_L4;
    }

    
    __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 375, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_CodeType); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 375, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_5 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_1)), __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_5); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 375, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 375, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (__pyx_t_2) {

      
      __pyx_t_5 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 376, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 376, __pyx_L1_error) }
      if (__Pyx_PyObject_SetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data, __pyx_t_5) < 0) __PYX_ERR(0, 376, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

      
    }
    __pyx_L4:;

    
  }

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_5 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 377, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_r = __pyx_t_5;
  __pyx_t_5 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.exec_function.exec", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_commands);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_3compile = {"compile", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_3compile, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("compile (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "compile", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_2compile(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_2compile(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_args) {
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("compile", 0);

  
  __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 380, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_data = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_data)), ((PyObject *)(&PyBytes_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 381, __pyx_L1_error)
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 381, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_2) {

    
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_data, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 382, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 382, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_1);
    __pyx_t_1 = 0;

    
  }

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_data);
  __pyx_r = __pyx_v_data;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.exec_function.compile", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_5print(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_5print = {"print", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_5print, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_5print(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("print (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "print", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_4print(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_4print(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("print", 0);

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_7input(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_7input = {"input", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_7input, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_7input(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("input (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "input", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_6input(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_6input(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("input", 0);

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_n_u_text);
  __pyx_r = __pyx_n_u_text;
  goto __pyx_L0;

  

  
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_9exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_9exit = {"exit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_9exit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_9exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "exit", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8exit(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit", 0);

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_1exec(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_8builtins_1exec = {"exec", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_1exec, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_1exec(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exec (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "exec", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_exec(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_exec(PyObject *__pyx_self, PyObject *__pyx_v_args) {
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_cur_scope;
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_outer_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("exec", 0);
  __pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  
  if (unlikely(!__pyx_cur_scope->__pyx_v_exec)) { __Pyx_RaiseClosureNameError("exec"); __PYX_ERR(0, 396, __pyx_L1_error) }
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_cur_scope->__pyx_v_exec, __pyx_v_args, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 396, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.exec_function.builtins.exec", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_8builtins_3compile = {"compile", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_3compile, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("compile (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "compile", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_2compile(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_2compile(PyObject *__pyx_self, PyObject *__pyx_v_args) {
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_cur_scope;
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_outer_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("compile", 0);
  __pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  
  if (unlikely(!__pyx_cur_scope->__pyx_v_compile)) { __Pyx_RaiseClosureNameError("compile"); __PYX_ERR(0, 399, __pyx_L1_error) }
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_cur_scope->__pyx_v_compile, __pyx_v_args, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 399, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.exec_function.builtins.compile", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_5exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_8builtins_5exit = {"exit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_5exit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13exec_function_8builtins_5exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "exit", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_4exit(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13exec_function_8builtins_4exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit", 0);

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_28exec_function(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_cur_scope;
  CYTHON_UNUSED PyObject *__pyx_v_print = 0;
  CYTHON_UNUSED PyObject *__pyx_v_input = 0;
  CYTHON_UNUSED PyObject *__pyx_v_exit = 0;
  PyObject *__pyx_v_builtins = NULL;
  PyObject *__pyx_v_err = NULL;
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_out = NULL;
  PyObject *__pyx_v_version = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  int __pyx_t_9;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  char const *__pyx_t_14;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  PyObject *__pyx_t_19 = NULL;
  PyObject *__pyx_t_20 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("exec_function", 0);
  __pyx_cur_scope = (struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *)__pyx_tp_new_6decode___pyx_scope_struct_3_exec_function(__pyx_ptype_6decode___pyx_scope_struct_3_exec_function, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 362, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_self = __pyx_v_self;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_self);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_self);

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_1exec, 0, __pyx_n_s_DecodingAlgorithms_exec_function, ((PyObject*)__pyx_cur_scope), __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__77)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 363, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_exec = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_3compile, 0, __pyx_n_s_DecodingAlgorithms_exec_function_2, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__79)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 379, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_compile = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_5print, 0, __pyx_n_s_DecodingAlgorithms_exec_function_3, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__81)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 385, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_print = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_7input, 0, __pyx_n_s_DecodingAlgorithms_exec_function_4, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__83)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 388, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_input = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_9exit, 0, __pyx_n_s_DecodingAlgorithms_exec_function_5, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__85)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 391, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_exit = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_builtins, __pyx_n_s_DecodingAlgorithms_exec_function_6, (PyObject *) NULL, __pyx_kp_s_decode_2, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 394, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_8builtins_1exec, 0, __pyx_n_s_DecodingAlgorithms_exec_function_7, ((PyObject*)__pyx_cur_scope), __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__87)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 395, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_exec, __pyx_t_2) < 0) __PYX_ERR(0, 395, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_8builtins_3compile, 0, __pyx_n_s_DecodingAlgorithms_exec_function_8, ((PyObject*)__pyx_cur_scope), __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__89)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 398, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_compile, __pyx_t_2) < 0) __PYX_ERR(0, 398, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13exec_function_8builtins_5exit, 0, __pyx_n_s_DecodingAlgorithms_exec_function_9, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__91)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 401, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_exit, __pyx_t_2) < 0) __PYX_ERR(0, 401, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_builtins, __pyx_empty_tuple, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 394, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_builtins = __pyx_t_2;
  __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 404, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_modules); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 404, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(PyObject_SetItem(__pyx_t_2, __pyx_n_u_builtins, __pyx_v_builtins) < 0)) __PYX_ERR(0, 404, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_3, &__pyx_t_4, &__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_OLD_EXEC); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 407, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 407, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_7 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_7, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_6);
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 407, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
    __pyx_t_8 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_8) {
      __Pyx_AddTraceback("decode.DecodingAlgorithms.exec_function", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_1, &__pyx_t_6) < 0) __PYX_ERR(0, 408, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_1);
      __pyx_v_err = __pyx_t_1;
       {

        
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_DEBUG_MODE); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 409, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 409, __pyx_L14_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_9) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_console); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 410, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_log); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 410, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_11);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_v_err, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 410, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_12 = __Pyx_PyUnicode_Concat(__pyx_kp_u_ERROR_2, __pyx_t_10); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 410, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __pyx_t_10 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
            __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_11);
            if (likely(__pyx_t_10)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
              __Pyx_INCREF(__pyx_t_10);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_11, function);
            }
          }
          __pyx_t_7 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_11, __pyx_t_10, __pyx_t_12) : __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_12);
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 410, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

          
        }
      }

      
       {
        {
          __Pyx_DECREF(__pyx_v_err);
          __pyx_v_err = NULL;
          goto __pyx_L15;
        }
        __pyx_L14_error:;
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __pyx_t_15 = 0; __pyx_t_16 = 0; __pyx_t_17 = 0; __pyx_t_18 = 0; __pyx_t_19 = 0; __pyx_t_20 = 0;
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_18, &__pyx_t_19, &__pyx_t_20);
          if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17) < 0)) __Pyx_ErrFetch(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17);
          __Pyx_XGOTREF(__pyx_t_15);
          __Pyx_XGOTREF(__pyx_t_16);
          __Pyx_XGOTREF(__pyx_t_17);
          __Pyx_XGOTREF(__pyx_t_18);
          __Pyx_XGOTREF(__pyx_t_19);
          __Pyx_XGOTREF(__pyx_t_20);
          __pyx_t_8 = __pyx_lineno; __pyx_t_13 = __pyx_clineno; __pyx_t_14 = __pyx_filename;
          {
            __Pyx_DECREF(__pyx_v_err);
            __pyx_v_err = NULL;
          }
          if (PY_MAJOR_VERSION >= 3) {
            __Pyx_XGIVEREF(__pyx_t_18);
            __Pyx_XGIVEREF(__pyx_t_19);
            __Pyx_XGIVEREF(__pyx_t_20);
            __Pyx_ExceptionReset(__pyx_t_18, __pyx_t_19, __pyx_t_20);
          }
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ErrRestore(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          __pyx_t_15 = 0; __pyx_t_16 = 0; __pyx_t_17 = 0; __pyx_t_18 = 0; __pyx_t_19 = 0; __pyx_t_20 = 0;
          __pyx_lineno = __pyx_t_8; __pyx_clineno = __pyx_t_13; __pyx_filename = __pyx_t_14;
          goto __pyx_L5_except_error;
        }
        __pyx_L15:;
      }
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L4_exception_handled;
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    __pyx_L8_try_end:;
  }

  
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 412, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_6)), ((PyObject *)(&PyBytes_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 412, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 412, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_9) {

    
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 413, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 413, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 413, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_7, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_6);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 413, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 413, __pyx_L1_error)
    __pyx_r = ((PyObject*)__pyx_t_1);
    __pyx_t_1 = 0;
    goto __pyx_L0;

    
  }

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 414, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_1)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 414, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 414, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_9) {

    
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 415, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (!(likely(PyUnicode_CheckExact(__pyx_t_2))||((__pyx_t_2) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_2)->tp_name), 0))) __PYX_ERR(0, 415, __pyx_L1_error)
    __pyx_r = ((PyObject*)__pyx_t_2);
    __pyx_t_2 = 0;
    goto __pyx_L0;

    
  }

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 417, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_bytecode = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_io); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 418, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_StringIO); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 418, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 418, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_out = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 419, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_1 = PyObject_RichCompare(__pyx_t_6, __pyx_float_3_9, Py_LT); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 419, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 419, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_9) {
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 419, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_t_1;
    __pyx_t_1 = 0;
  } else {
    __Pyx_INCREF(__pyx_float_3_8);
    __pyx_t_2 = __pyx_float_3_8;
  }
  __pyx_v_version = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_decompile); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 420, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 420, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_version);
  __Pyx_GIVEREF(__pyx_v_version);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_version);
  __Pyx_INCREF(__pyx_v_bytecode);
  __Pyx_GIVEREF(__pyx_v_bytecode);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_v_bytecode);
  __Pyx_INCREF(__pyx_v_out);
  __Pyx_GIVEREF(__pyx_v_out);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_v_out);
  __pyx_t_6 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 420, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_showast, Py_False) < 0) __PYX_ERR(0, 420, __pyx_L1_error)
  __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_1, __pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 420, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_out, __pyx_n_s_getvalue); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 421, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_6 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 421, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 421, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_7 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_6, __pyx_kp_u__15) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u__15);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 421, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_t_7, 4, 0, NULL, NULL, &__pyx_slice__21, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 421, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = PyUnicode_Join(__pyx_kp_u__15, __pyx_t_1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 421, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Concat(__pyx_t_7, __pyx_kp_u__15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 421, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.exec_function", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_print);
  __Pyx_XDECREF(__pyx_v_input);
  __Pyx_XDECREF(__pyx_v_exit);
  __Pyx_XDECREF(__pyx_v_builtins);
  __Pyx_XDECREF(__pyx_v_err);
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_out);
  __Pyx_XDECREF(__pyx_v_version);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_31eval_function(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_31eval_function = {"eval_function", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_31eval_function, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_31eval_function(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("eval_function (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_30eval_function(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_1eval(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_1eval = {"eval", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_1eval, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_1eval(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("eval (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "eval", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_eval(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_eval(PyObject *__pyx_self, PyObject *__pyx_v_args) {
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *__pyx_cur_scope;
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *__pyx_outer_scope;
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_commands = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  Py_ssize_t __pyx_t_8;
  int __pyx_t_9;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("eval", 0);
  __pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  
  __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 425, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 425, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_2) {

    
    __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 426, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_1)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 426, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 426, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    if (__pyx_t_2) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_OLD_COMPILE); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 427, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_4 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 427, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_5 = NULL;
      __pyx_t_6 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_5)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_5);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
          __pyx_t_6 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_1)) {
        PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_t_4, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_3 = __Pyx_PyFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 427, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_1)) {
        PyObject *__pyx_temp[4] = {__pyx_t_5, __pyx_t_4, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_3 = __Pyx_PyCFunction_FastCall(__pyx_t_1, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 427, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      } else
      #endif
      {
        __pyx_t_7 = PyTuple_New(3+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 427, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_7);
        if (__pyx_t_5) {
          __Pyx_GIVEREF(__pyx_t_5); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_5); __pyx_t_5 = NULL;
        }
        __Pyx_GIVEREF(__pyx_t_4);
        PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_6, __pyx_t_4);
        __Pyx_INCREF(__pyx_n_u_string);
        __Pyx_GIVEREF(__pyx_n_u_string);
        PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_6, __pyx_n_u_string);
        __Pyx_INCREF(__pyx_n_u_exec);
        __Pyx_GIVEREF(__pyx_n_u_exec);
        PyTuple_SET_ITEM(__pyx_t_7, 2+__pyx_t_6, __pyx_n_u_exec);
        __pyx_t_4 = 0;
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_t_7, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 427, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      }
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_v_bytecode = __pyx_t_3;
      __pyx_t_3 = 0;

      
      __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 428, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_v_commands = __pyx_t_3;
      __pyx_t_3 = 0;

      
      __pyx_t_8 = PyObject_Length(__pyx_v_commands); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 429, __pyx_L1_error)
      __pyx_t_2 = ((__pyx_t_8 > 1) != 0);
      if (__pyx_t_2) {

        
        __pyx_t_3 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 430, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 430, __pyx_L1_error) }
        if (__Pyx_PyObject_SetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data, __pyx_t_3) < 0) __PYX_ERR(0, 430, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

        
      }

      
      goto __pyx_L4;
    }

    
    __pyx_t_3 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 431, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_3)), ((PyObject *)(&PyBytes_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 431, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 431, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_2) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_OLD_COMPILE); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 432, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_7 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 432, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __pyx_t_4 = NULL;
      __pyx_t_6 = 0;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_4)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_4);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
          __pyx_t_6 = 1;
        }
      }
      #if CYTHON_FAST_PYCALL
      if (PyFunction_Check(__pyx_t_3)) {
        PyObject *__pyx_temp[4] = {__pyx_t_4, __pyx_t_7, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      } else
      #endif
      #if CYTHON_FAST_PYCCALL
      if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
        PyObject *__pyx_temp[4] = {__pyx_t_4, __pyx_t_7, __pyx_n_u_string, __pyx_n_u_exec};
        __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_6, 3+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
        __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      } else
      #endif
      {
        __pyx_t_5 = PyTuple_New(3+__pyx_t_6); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 432, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        if (__pyx_t_4) {
          __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_4); __pyx_t_4 = NULL;
        }
        __Pyx_GIVEREF(__pyx_t_7);
        PyTuple_SET_ITEM(__pyx_t_5, 0+__pyx_t_6, __pyx_t_7);
        __Pyx_INCREF(__pyx_n_u_string);
        __Pyx_GIVEREF(__pyx_n_u_string);
        PyTuple_SET_ITEM(__pyx_t_5, 1+__pyx_t_6, __pyx_n_u_string);
        __Pyx_INCREF(__pyx_n_u_exec);
        __Pyx_GIVEREF(__pyx_n_u_exec);
        PyTuple_SET_ITEM(__pyx_t_5, 2+__pyx_t_6, __pyx_n_u_exec);
        __pyx_t_7 = 0;
        __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_5, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 432, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      }
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_bytecode = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 433, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_v_commands = __pyx_t_1;
      __pyx_t_1 = 0;

      
      __pyx_t_8 = PyObject_Length(__pyx_v_commands); if (unlikely(__pyx_t_8 == ((Py_ssize_t)-1))) __PYX_ERR(0, 434, __pyx_L1_error)
      __pyx_t_2 = ((__pyx_t_8 > 1) != 0);
      if (__pyx_t_2) {

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_to_string); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 435, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_5 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 435, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_7 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_7)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_7);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_7, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_5);
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 435, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 435, __pyx_L1_error) }
        if (__Pyx_PyObject_SetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data, __pyx_t_1) < 0) __PYX_ERR(0, 435, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

        
      }

      
      goto __pyx_L4;
    }

    
    __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 436, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_HasAttr(__pyx_t_1, __pyx_n_u_co_code); if (unlikely(__pyx_t_2 == ((int)-1))) __PYX_ERR(0, 436, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_9 = (__pyx_t_2 != 0);
    if (__pyx_t_9) {

      
      __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 437, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      if (unlikely(!__pyx_cur_scope->__pyx_v_self)) { __Pyx_RaiseClosureNameError("self"); __PYX_ERR(0, 437, __pyx_L1_error) }
      if (__Pyx_PyObject_SetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data, __pyx_t_1) < 0) __PYX_ERR(0, 437, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

      
    }
    __pyx_L4:;

    
  }

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 438, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_function.eval", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_commands);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_3compile = {"compile", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_3compile, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("compile (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "compile", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_2compile(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_2compile(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_args) {
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("compile", 0);

  
  __pyx_t_1 = __Pyx_GetItemInt_Tuple(__pyx_v_args, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 441, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_data = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_data)), ((PyObject *)(&PyBytes_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 442, __pyx_L1_error)
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 442, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_2) {

    
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_data, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 443, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_1 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 443, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_1);
    __pyx_t_1 = 0;

    
  }

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_v_data);
  __pyx_r = __pyx_v_data;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_function.compile", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_5print(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_5print = {"print", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_5print, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_5print(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("print (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "print", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_4print(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_4print(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("print", 0);

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_7input(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_7input = {"input", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_7input, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_7input(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("input (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "input", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_6input(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_6input(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("input", 0);

  
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(__pyx_n_u_text);
  __pyx_r = __pyx_n_u_text;
  goto __pyx_L0;

  

  
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_9exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_9exit = {"exit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_9exit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_9exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "exit", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8exit(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit", 0);

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_1exec(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_8builtins_1exec = {"exec", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_1exec, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_1exec(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exec (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "exec", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_exec(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_exec(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("exec", 0);

  
  __pyx_t_1 = __Pyx_GetBuiltinName(__pyx_n_s_exec); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 457, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_1, __pyx_v_args, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 457, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_function.builtins.exec", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_8builtins_3compile = {"compile", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_3compile, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_3compile(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("compile (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "compile", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_2compile(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_2compile(PyObject *__pyx_self, PyObject *__pyx_v_args) {
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *__pyx_cur_scope;
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *__pyx_outer_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("compile", 0);
  __pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  
  if (unlikely(!__pyx_cur_scope->__pyx_v_compile)) { __Pyx_RaiseClosureNameError("compile"); __PYX_ERR(0, 460, __pyx_L1_error) }
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_cur_scope->__pyx_v_compile, __pyx_v_args, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 460, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_function.builtins.compile", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_5exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_8builtins_5exit = {"exit", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_5exit, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_13eval_function_8builtins_5exit(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  CYTHON_UNUSED PyObject *__pyx_v_args = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit (wrapper)", 0);
  if (unlikely(__pyx_kwds) && unlikely(PyDict_Size(__pyx_kwds) > 0) && unlikely(!__Pyx_CheckKeywordStrings(__pyx_kwds, "exit", 0))) return NULL;
  __Pyx_INCREF(__pyx_args);
  __pyx_v_args = __pyx_args;
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_4exit(__pyx_self, __pyx_v_args);

  
  __Pyx_XDECREF(__pyx_v_args);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_13eval_function_8builtins_4exit(CYTHON_UNUSED PyObject *__pyx_self, CYTHON_UNUSED PyObject *__pyx_v_args) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("exit", 0);

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_30eval_function(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *__pyx_cur_scope;
  CYTHON_UNUSED PyObject *__pyx_v_eval = 0;
  CYTHON_UNUSED PyObject *__pyx_v_print = 0;
  CYTHON_UNUSED PyObject *__pyx_v_input = 0;
  CYTHON_UNUSED PyObject *__pyx_v_exit = 0;
  PyObject *__pyx_v_builtins = NULL;
  PyObject *__pyx_v_err = NULL;
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_out = NULL;
  PyObject *__pyx_v_version = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_t_8;
  int __pyx_t_9;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  char const *__pyx_t_14;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  PyObject *__pyx_t_17 = NULL;
  PyObject *__pyx_t_18 = NULL;
  PyObject *__pyx_t_19 = NULL;
  PyObject *__pyx_t_20 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("eval_function", 0);
  __pyx_cur_scope = (struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *)__pyx_tp_new_6decode___pyx_scope_struct_4_eval_function(__pyx_ptype_6decode___pyx_scope_struct_4_eval_function, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 423, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_v_self = __pyx_v_self;
  __Pyx_INCREF(__pyx_cur_scope->__pyx_v_self);
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_v_self);

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_1eval, 0, __pyx_n_s_DecodingAlgorithms_eval_function, ((PyObject*)__pyx_cur_scope), __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__93)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 424, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_eval = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_3compile, 0, __pyx_n_s_DecodingAlgorithms_eval_function_2, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__95)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 440, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GIVEREF(__pyx_t_1);
  __pyx_cur_scope->__pyx_v_compile = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_5print, 0, __pyx_n_s_DecodingAlgorithms_eval_function_3, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__97)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 446, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_print = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_7input, 0, __pyx_n_s_DecodingAlgorithms_eval_function_4, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__99)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 449, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_input = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_9exit, 0, __pyx_n_s_DecodingAlgorithms_eval_function_5, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__101)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 452, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_v_exit = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_builtins, __pyx_n_s_DecodingAlgorithms_eval_function_6, (PyObject *) NULL, __pyx_kp_s_decode_2, (PyObject *) NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 455, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_8builtins_1exec, 0, __pyx_n_s_DecodingAlgorithms_eval_function_7, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__103)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 456, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_exec, __pyx_t_2) < 0) __PYX_ERR(0, 456, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_8builtins_3compile, 0, __pyx_n_s_DecodingAlgorithms_eval_function_8, ((PyObject*)__pyx_cur_scope), __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__105)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 459, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_compile, __pyx_t_2) < 0) __PYX_ERR(0, 459, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13eval_function_8builtins_5exit, 0, __pyx_n_s_DecodingAlgorithms_eval_function_9, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__107)); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 462, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (__Pyx_SetNameInClass(__pyx_t_1, __pyx_n_s_exit, __pyx_t_2) < 0) __PYX_ERR(0, 462, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_builtins, __pyx_empty_tuple, __pyx_t_1, NULL, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 455, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_builtins = __pyx_t_2;
  __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 465, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_modules); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 465, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(PyObject_SetItem(__pyx_t_2, __pyx_n_u_builtins, __pyx_v_builtins) < 0)) __PYX_ERR(0, 465, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_3, &__pyx_t_4, &__pyx_t_5);
    __Pyx_XGOTREF(__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_4);
    __Pyx_XGOTREF(__pyx_t_5);
     {

      
      __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_OLD_EXEC); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 468, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 468, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_6);
      __pyx_t_7 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
        __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_1);
        if (likely(__pyx_t_7)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
          __Pyx_INCREF(__pyx_t_7);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_1, function);
        }
      }
      __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_7, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_6);
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 468, __pyx_L3_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

      
    }
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

    
    __pyx_t_8 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_8) {
      __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_function", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_1, &__pyx_t_6) < 0) __PYX_ERR(0, 469, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_1);
      __pyx_v_err = __pyx_t_1;
       {

        
        __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_DEBUG_MODE); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 470, __pyx_L14_error)
        __Pyx_GOTREF(__pyx_t_7);
        __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_7); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 470, __pyx_L14_error)
        __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
        if (__pyx_t_9) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_console); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 471, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_log); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 471, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_11);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_v_err, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 471, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_12 = __Pyx_PyUnicode_Concat(__pyx_kp_u_ERROR_2, __pyx_t_10); if (unlikely(!__pyx_t_12)) __PYX_ERR(0, 471, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __pyx_t_10 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
            __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_11);
            if (likely(__pyx_t_10)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
              __Pyx_INCREF(__pyx_t_10);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_11, function);
            }
          }
          __pyx_t_7 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_11, __pyx_t_10, __pyx_t_12) : __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_12);
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_DECREF(__pyx_t_12); __pyx_t_12 = 0;
          if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 471, __pyx_L14_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

          
        }
      }

      
       {
        {
          __Pyx_DECREF(__pyx_v_err);
          __pyx_v_err = NULL;
          goto __pyx_L15;
        }
        __pyx_L14_error:;
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __pyx_t_15 = 0; __pyx_t_16 = 0; __pyx_t_17 = 0; __pyx_t_18 = 0; __pyx_t_19 = 0; __pyx_t_20 = 0;
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_18, &__pyx_t_19, &__pyx_t_20);
          if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17) < 0)) __Pyx_ErrFetch(&__pyx_t_15, &__pyx_t_16, &__pyx_t_17);
          __Pyx_XGOTREF(__pyx_t_15);
          __Pyx_XGOTREF(__pyx_t_16);
          __Pyx_XGOTREF(__pyx_t_17);
          __Pyx_XGOTREF(__pyx_t_18);
          __Pyx_XGOTREF(__pyx_t_19);
          __Pyx_XGOTREF(__pyx_t_20);
          __pyx_t_8 = __pyx_lineno; __pyx_t_13 = __pyx_clineno; __pyx_t_14 = __pyx_filename;
          {
            __Pyx_DECREF(__pyx_v_err);
            __pyx_v_err = NULL;
          }
          if (PY_MAJOR_VERSION >= 3) {
            __Pyx_XGIVEREF(__pyx_t_18);
            __Pyx_XGIVEREF(__pyx_t_19);
            __Pyx_XGIVEREF(__pyx_t_20);
            __Pyx_ExceptionReset(__pyx_t_18, __pyx_t_19, __pyx_t_20);
          }
          __Pyx_XGIVEREF(__pyx_t_15);
          __Pyx_XGIVEREF(__pyx_t_16);
          __Pyx_XGIVEREF(__pyx_t_17);
          __Pyx_ErrRestore(__pyx_t_15, __pyx_t_16, __pyx_t_17);
          __pyx_t_15 = 0; __pyx_t_16 = 0; __pyx_t_17 = 0; __pyx_t_18 = 0; __pyx_t_19 = 0; __pyx_t_20 = 0;
          __pyx_lineno = __pyx_t_8; __pyx_clineno = __pyx_t_13; __pyx_filename = __pyx_t_14;
          goto __pyx_L5_except_error;
        }
        __pyx_L15:;
      }
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      goto __pyx_L4_exception_handled;
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    goto __pyx_L1_error;
    __pyx_L4_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_XGIVEREF(__pyx_t_4);
    __Pyx_XGIVEREF(__pyx_t_5);
    __Pyx_ExceptionReset(__pyx_t_3, __pyx_t_4, __pyx_t_5);
    __pyx_L8_try_end:;
  }

  
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 473, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_6)), ((PyObject *)(&PyBytes_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 473, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 473, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_9) {

    
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 474, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 474, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 474, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_7, __pyx_t_6) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_6);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 474, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (!(likely(PyUnicode_CheckExact(__pyx_t_1))||((__pyx_t_1) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_1)->tp_name), 0))) __PYX_ERR(0, 474, __pyx_L1_error)
    __pyx_r = ((PyObject*)__pyx_t_1);
    __pyx_t_1 = 0;
    goto __pyx_L0;

    
  }

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 475, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_1)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 475, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 475, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_9) {

    
    __Pyx_XDECREF(__pyx_r);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 476, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    if (!(likely(PyUnicode_CheckExact(__pyx_t_2))||((__pyx_t_2) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_t_2)->tp_name), 0))) __PYX_ERR(0, 476, __pyx_L1_error)
    __pyx_r = ((PyObject*)__pyx_t_2);
    __pyx_t_2 = 0;
    goto __pyx_L0;

    
  }

  
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_cur_scope->__pyx_v_self, __pyx_n_s_custom_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 478, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_v_bytecode = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_io); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 479, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_6 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_StringIO); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 479, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_6))) {
    __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_6);
    if (likely(__pyx_t_1)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_6);
      __Pyx_INCREF(__pyx_t_1);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_6, function);
    }
  }
  __pyx_t_2 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_6, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 479, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_v_out = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_6, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 480, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __pyx_t_1 = PyObject_RichCompare(__pyx_t_6, __pyx_float_3_9, Py_LT); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 480, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_9 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_9 < 0)) __PYX_ERR(0, 480, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_9) {
    __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 480, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __pyx_t_1;
    __pyx_t_1 = 0;
  } else {
    __Pyx_INCREF(__pyx_float_3_8);
    __pyx_t_2 = __pyx_float_3_8;
  }
  __pyx_v_version = __pyx_t_2;
  __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_decompile); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 481, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 481, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_version);
  __Pyx_GIVEREF(__pyx_v_version);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_version);
  __Pyx_INCREF(__pyx_v_bytecode);
  __Pyx_GIVEREF(__pyx_v_bytecode);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_v_bytecode);
  __Pyx_INCREF(__pyx_v_out);
  __Pyx_GIVEREF(__pyx_v_out);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_v_out);
  __pyx_t_6 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 481, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  if (PyDict_SetItem(__pyx_t_6, __pyx_n_s_showast, Py_False) < 0) __PYX_ERR(0, 481, __pyx_L1_error)
  __pyx_t_7 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_1, __pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 481, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_out, __pyx_n_s_getvalue); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 482, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_6 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 482, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_6);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_6, __pyx_n_s_split); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 482, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_1);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_1, function);
    }
  }
  __pyx_t_7 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_6, __pyx_kp_u__15) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_kp_u__15);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 482, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_t_7, 4, 0, NULL, NULL, &__pyx_slice__21, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 482, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = PyUnicode_Join(__pyx_kp_u__15, __pyx_t_1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 482, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyUnicode_Concat(__pyx_t_7, __pyx_kp_u__15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 482, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_r = ((PyObject*)__pyx_t_1);
  __pyx_t_1 = 0;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.eval_function", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_eval);
  __Pyx_XDECREF(__pyx_v_print);
  __Pyx_XDECREF(__pyx_v_input);
  __Pyx_XDECREF(__pyx_v_exit);
  __Pyx_XDECREF(__pyx_v_builtins);
  __Pyx_XDECREF(__pyx_v_err);
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_out);
  __Pyx_XDECREF(__pyx_v_version);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_33bytes_list(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_33bytes_list = {"bytes_list", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_33bytes_list, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_33bytes_list(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("bytes_list (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_32bytes_list(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
static PyObject *__pyx_gb_6decode_18DecodingAlgorithms_10bytes_list_2generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value); 



static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_10bytes_list_genexpr(PyObject *__pyx_self) {
  struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *__pyx_cur_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("genexpr", 0);
  __pyx_cur_scope = (struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *)__pyx_tp_new_6decode___pyx_scope_struct_6_genexpr(__pyx_ptype_6decode___pyx_scope_struct_6_genexpr, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 489, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }
  __pyx_cur_scope->__pyx_outer_scope = (struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *) __pyx_self;
  __Pyx_INCREF(((PyObject *)__pyx_cur_scope->__pyx_outer_scope));
  __Pyx_GIVEREF(__pyx_cur_scope->__pyx_outer_scope);
  {
    __pyx_CoroutineObject *gen = __Pyx_Generator_New((__pyx_coroutine_body_t) __pyx_gb_6decode_18DecodingAlgorithms_10bytes_list_2generator1, NULL, (PyObject *) __pyx_cur_scope, __pyx_n_s_genexpr, __pyx_n_s_DecodingAlgorithms_bytes_list_lo, __pyx_kp_s_decode_2); if (unlikely(!gen)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_DECREF(__pyx_cur_scope);
    __Pyx_RefNannyFinishContext();
    return (PyObject *) gen;
  }

  
  __pyx_L1_error:;
  __Pyx_AddTraceback("decode.DecodingAlgorithms.bytes_list.genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_gb_6decode_18DecodingAlgorithms_10bytes_list_2generator1(__pyx_CoroutineObject *__pyx_generator, CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject *__pyx_sent_value) 
{
  struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *__pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *)__pyx_generator->closure);
  PyObject *__pyx_r = NULL;
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *(*__pyx_t_3)(PyObject *);
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("genexpr", 0);
  switch (__pyx_generator->resume_label) {
    case 0: goto __pyx_L3_first_run;
    default: 
    __Pyx_RefNannyFinishContext();
    return NULL;
  }
  __pyx_L3_first_run:;
  if (unlikely(!__pyx_sent_value)) __PYX_ERR(0, 489, __pyx_L1_error)
  __pyx_r = PyList_New(0); if (unlikely(!__pyx_r)) __PYX_ERR(0, 489, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_r);
  if (unlikely(!__pyx_cur_scope->__pyx_outer_scope->__pyx_v_const)) { __Pyx_RaiseClosureNameError("const"); __PYX_ERR(0, 489, __pyx_L1_error) }
  if (likely(PyList_CheckExact(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_const)) || PyTuple_CheckExact(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_const)) {
    __pyx_t_1 = __pyx_cur_scope->__pyx_outer_scope->__pyx_v_const; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_cur_scope->__pyx_outer_scope->__pyx_v_const); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 489, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 489, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 489, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 489, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 489, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 489, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_i);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_i, __pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_cur_scope->__pyx_v_i, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = __Pyx_PyUnicode_Concat(__pyx_kp_u_0b, __pyx_t_4); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = PyTuple_New(2); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_4, 0, __pyx_t_5);
    __Pyx_INCREF(__pyx_int_2);
    __Pyx_GIVEREF(__pyx_int_2);
    PyTuple_SET_ITEM(__pyx_t_4, 1, __pyx_int_2);
    __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_Call(((PyObject *)(&PyInt_Type)), __pyx_t_4, NULL); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = __Pyx_PyObject_CallOneArg(__pyx_builtin_chr, __pyx_t_5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_5 = PyList_New(1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_GIVEREF(__pyx_t_4);
    PyList_SET_ITEM(__pyx_t_5, 0, __pyx_t_4);
    __pyx_t_4 = 0;
    __pyx_t_4 = PyUnicode_Join(__pyx_kp_u__12, __pyx_t_5); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    if (unlikely(__Pyx_ListComp_Append(__pyx_r, (PyObject*)__pyx_t_4))) __PYX_ERR(0, 489, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  CYTHON_MAYBE_UNUSED_VAR(__pyx_cur_scope);

  
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_r); __pyx_r = 0;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("genexpr", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  #if !CYTHON_USE_EXC_INFO_STACK
  __Pyx_Coroutine_ResetAndClearException(__pyx_generator);
  #endif
  __pyx_generator->resume_label = -1;
  __Pyx_Coroutine_clear((PyObject*)__pyx_generator);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}



static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_32bytes_list(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *__pyx_cur_scope;
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_source = NULL;
  PyObject *__pyx_v_err = NULL;
  PyObject *__pyx_gb_6decode_18DecodingAlgorithms_10bytes_list_2generator1 = 0;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *(*__pyx_t_4)(PyObject *);
  int __pyx_t_5;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  int __pyx_t_17;
  char const *__pyx_t_18;
  PyObject *__pyx_t_19 = NULL;
  PyObject *__pyx_t_20 = NULL;
  PyObject *__pyx_t_21 = NULL;
  PyObject *__pyx_t_22 = NULL;
  PyObject *__pyx_t_23 = NULL;
  PyObject *__pyx_t_24 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("bytes_list", 0);
  __pyx_cur_scope = (struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *)__pyx_tp_new_6decode___pyx_scope_struct_5_bytes_list(__pyx_ptype_6decode___pyx_scope_struct_5_bytes_list, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 484, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 485, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 485, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_string);
  __Pyx_GIVEREF(__pyx_n_u_string);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_n_u_string);
  __Pyx_INCREF(__pyx_n_u_exec);
  __Pyx_GIVEREF(__pyx_n_u_exec);
  PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_n_u_exec);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 485, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_bytecode = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 486, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
    __pyx_t_4 = NULL;
  } else {
    __pyx_t_3 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 486, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 486, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_4)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 486, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 486, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_3 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 486, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 486, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_4(__pyx_t_2);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 486, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_const);
    __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_const, __pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_1);
    __pyx_t_1 = 0;

    
    __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_cur_scope->__pyx_v_const)), ((PyObject *)(&PyList_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 487, __pyx_L1_error)
    __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 487, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (!__pyx_t_6) {
    } else {
      __pyx_t_5 = __pyx_t_6;
      goto __pyx_L6_bool_binop_done;
    }
    __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_cur_scope->__pyx_v_const)), ((PyObject *)(&PyTuple_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 487, __pyx_L1_error)
    __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 487, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_5 = __pyx_t_6;
    __pyx_L6_bool_binop_done:;
    if (__pyx_t_5) {

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_7, &__pyx_t_8, &__pyx_t_9);
        __Pyx_XGOTREF(__pyx_t_7);
        __Pyx_XGOTREF(__pyx_t_8);
        __Pyx_XGOTREF(__pyx_t_9);
         {

          
          __pyx_t_1 = __pyx_pf_6decode_18DecodingAlgorithms_10bytes_list_genexpr(((PyObject*)__pyx_cur_scope)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 489, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_10 = __Pyx_Generator_Next(__pyx_t_1); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 489, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = PyUnicode_Join(__pyx_kp_u__12, __pyx_t_10); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 489, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_XDECREF_SET(__pyx_v_source, ((PyObject*)__pyx_t_1));
          __pyx_t_1 = 0;

          
          __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 490, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_INCREF(__pyx_v_source);
          __Pyx_GIVEREF(__pyx_v_source);
          PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_source);
          __Pyx_INCREF(__pyx_n_u_string);
          __Pyx_GIVEREF(__pyx_n_u_string);
          PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_string);
          __Pyx_INCREF(__pyx_n_u_exec);
          __Pyx_GIVEREF(__pyx_n_u_exec);
          PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_n_u_exec);
          __pyx_t_10 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_1, NULL); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 490, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;

          
          __Pyx_XDECREF(__pyx_r);
          __Pyx_INCREF(__pyx_v_source);
          __pyx_r = __pyx_v_source;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          goto __pyx_L12_try_return;

          
        }
        __pyx_L8_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;

        
        __pyx_t_11 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
        if (__pyx_t_11) {
          __Pyx_AddTraceback("decode.DecodingAlgorithms.bytes_list", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_10, &__pyx_t_1, &__pyx_t_12) < 0) __PYX_ERR(0, 492, __pyx_L10_except_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_12);
          __Pyx_INCREF(__pyx_t_1);
          __pyx_v_err = __pyx_t_1;
           {

            
            __Pyx_GetModuleGlobalName(__pyx_t_13, __pyx_n_s_DEBUG_MODE); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 493, __pyx_L21_error)
            __Pyx_GOTREF(__pyx_t_13);
            __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_13); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 493, __pyx_L21_error)
            __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
            if (__pyx_t_5) {

              
              __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_console); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 494, __pyx_L21_error)
              __Pyx_GOTREF(__pyx_t_14);
              __pyx_t_15 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_log); if (unlikely(!__pyx_t_15)) __PYX_ERR(0, 494, __pyx_L21_error)
              __Pyx_GOTREF(__pyx_t_15);
              __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
              __pyx_t_14 = __Pyx_PyObject_FormatSimple(__pyx_v_err, __pyx_empty_unicode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 494, __pyx_L21_error)
              __Pyx_GOTREF(__pyx_t_14);
              __pyx_t_16 = __Pyx_PyUnicode_Concat(__pyx_kp_u_ERROR, __pyx_t_14); if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 494, __pyx_L21_error)
              __Pyx_GOTREF(__pyx_t_16);
              __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
              __pyx_t_14 = NULL;
              if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_15))) {
                __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_15);
                if (likely(__pyx_t_14)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_15);
                  __Pyx_INCREF(__pyx_t_14);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_15, function);
                }
              }
              __pyx_t_13 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_15, __pyx_t_14, __pyx_t_16) : __Pyx_PyObject_CallOneArg(__pyx_t_15, __pyx_t_16);
              __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
              __Pyx_DECREF(__pyx_t_16); __pyx_t_16 = 0;
              if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 494, __pyx_L21_error)
              __Pyx_GOTREF(__pyx_t_13);
              __Pyx_DECREF(__pyx_t_15); __pyx_t_15 = 0;
              __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;

              
            }
          }

          
           {
            {
              __Pyx_DECREF(__pyx_v_err);
              __pyx_v_err = NULL;
              goto __pyx_L22;
            }
            __pyx_L21_error:;
            {
              __Pyx_PyThreadState_declare
              __Pyx_PyThreadState_assign
              __pyx_t_19 = 0; __pyx_t_20 = 0; __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0;
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
              __Pyx_XDECREF(__pyx_t_15); __pyx_t_15 = 0;
              __Pyx_XDECREF(__pyx_t_16); __pyx_t_16 = 0;
              if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_22, &__pyx_t_23, &__pyx_t_24);
              if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_19, &__pyx_t_20, &__pyx_t_21) < 0)) __Pyx_ErrFetch(&__pyx_t_19, &__pyx_t_20, &__pyx_t_21);
              __Pyx_XGOTREF(__pyx_t_19);
              __Pyx_XGOTREF(__pyx_t_20);
              __Pyx_XGOTREF(__pyx_t_21);
              __Pyx_XGOTREF(__pyx_t_22);
              __Pyx_XGOTREF(__pyx_t_23);
              __Pyx_XGOTREF(__pyx_t_24);
              __pyx_t_11 = __pyx_lineno; __pyx_t_17 = __pyx_clineno; __pyx_t_18 = __pyx_filename;
              {
                __Pyx_DECREF(__pyx_v_err);
                __pyx_v_err = NULL;
              }
              if (PY_MAJOR_VERSION >= 3) {
                __Pyx_XGIVEREF(__pyx_t_22);
                __Pyx_XGIVEREF(__pyx_t_23);
                __Pyx_XGIVEREF(__pyx_t_24);
                __Pyx_ExceptionReset(__pyx_t_22, __pyx_t_23, __pyx_t_24);
              }
              __Pyx_XGIVEREF(__pyx_t_19);
              __Pyx_XGIVEREF(__pyx_t_20);
              __Pyx_XGIVEREF(__pyx_t_21);
              __Pyx_ErrRestore(__pyx_t_19, __pyx_t_20, __pyx_t_21);
              __pyx_t_19 = 0; __pyx_t_20 = 0; __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0;
              __pyx_lineno = __pyx_t_11; __pyx_clineno = __pyx_t_17; __pyx_filename = __pyx_t_18;
              goto __pyx_L10_except_error;
            }
            __pyx_L22:;
          }
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
          goto __pyx_L9_exception_handled;
        }
        goto __pyx_L10_except_error;
        __pyx_L10_except_error:;

        
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_7, __pyx_t_8, __pyx_t_9);
        goto __pyx_L1_error;
        __pyx_L12_try_return:;
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_7, __pyx_t_8, __pyx_t_9);
        goto __pyx_L0;
        __pyx_L9_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_7);
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_ExceptionReset(__pyx_t_7, __pyx_t_8, __pyx_t_9);
      }

      
    }

    
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_Call(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])), __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 495, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_Raise(__pyx_t_2, 0, 0, 0);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __PYX_ERR(0, 495, __pyx_L1_error)

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_XDECREF(__pyx_t_15);
  __Pyx_XDECREF(__pyx_t_16);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.bytes_list", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_source);
  __Pyx_XDECREF(__pyx_v_err);
  __Pyx_XDECREF(__pyx_gb_6decode_18DecodingAlgorithms_10bytes_list_2generator1);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_35math_sqrt(PyObject *__pyx_self, PyObject *__pyx_v_self); 
static PyMethodDef __pyx_mdef_6decode_18DecodingAlgorithms_35math_sqrt = {"math_sqrt", (PyCFunction)__pyx_pw_6decode_18DecodingAlgorithms_35math_sqrt, METH_O, 0};
static PyObject *__pyx_pw_6decode_18DecodingAlgorithms_35math_sqrt(PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("math_sqrt (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_18DecodingAlgorithms_34math_sqrt(__pyx_self, ((PyObject *)__pyx_v_self));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_18DecodingAlgorithms_34math_sqrt(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_self) {
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_v_const = NULL;
  PyObject *__pyx_v_source = NULL;
  PyObject *__pyx_v_err = NULL;
  PyObject *__pyx_8genexpr1__pyx_v_i = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  Py_ssize_t __pyx_t_3;
  PyObject *(*__pyx_t_4)(PyObject *);
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  Py_ssize_t __pyx_t_7;
  PyObject *(*__pyx_t_8)(PyObject *);
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  long __pyx_t_12;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  PyObject *__pyx_t_15 = NULL;
  PyObject *__pyx_t_16 = NULL;
  int __pyx_t_17;
  PyObject *__pyx_t_18 = NULL;
  int __pyx_t_19;
  char const *__pyx_t_20;
  PyObject *__pyx_t_21 = NULL;
  PyObject *__pyx_t_22 = NULL;
  PyObject *__pyx_t_23 = NULL;
  PyObject *__pyx_t_24 = NULL;
  PyObject *__pyx_t_25 = NULL;
  PyObject *__pyx_t_26 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("math_sqrt", 0);

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_self, __pyx_n_s_file_data); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 498, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyTuple_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 498, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_t_1);
  __Pyx_INCREF(__pyx_n_u_string);
  __Pyx_GIVEREF(__pyx_n_u_string);
  PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_n_u_string);
  __Pyx_INCREF(__pyx_n_u_exec);
  __Pyx_GIVEREF(__pyx_n_u_exec);
  PyTuple_SET_ITEM(__pyx_t_2, 2, __pyx_n_u_exec);
  __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 498, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_bytecode = __pyx_t_1;
  __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 499, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (likely(PyList_CheckExact(__pyx_t_1)) || PyTuple_CheckExact(__pyx_t_1)) {
    __pyx_t_2 = __pyx_t_1; __Pyx_INCREF(__pyx_t_2); __pyx_t_3 = 0;
    __pyx_t_4 = NULL;
  } else {
    __pyx_t_3 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 499, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_4 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 499, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  for (;;) {
    if (likely(!__pyx_t_4)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_3 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 499, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 499, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      } else {
        if (__pyx_t_3 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_1 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_3); __Pyx_INCREF(__pyx_t_1); __pyx_t_3++; if (unlikely(0 < 0)) __PYX_ERR(0, 499, __pyx_L1_error)
        #else
        __pyx_t_1 = PySequence_ITEM(__pyx_t_2, __pyx_t_3); __pyx_t_3++; if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 499, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        #endif
      }
    } else {
      __pyx_t_1 = __pyx_t_4(__pyx_t_2);
      if (unlikely(!__pyx_t_1)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 499, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_1);
    }
    __Pyx_XDECREF_SET(__pyx_v_const, __pyx_t_1);
    __pyx_t_1 = 0;

    
    __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_const)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 500, __pyx_L1_error)
    __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 500, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    if (__pyx_t_5) {

      
      { 
        __pyx_t_1 = PyList_New(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 501, __pyx_L8_error)
        __Pyx_GOTREF(__pyx_t_1);
        if (likely(PyList_CheckExact(__pyx_v_const)) || PyTuple_CheckExact(__pyx_v_const)) {
          __pyx_t_6 = __pyx_v_const; __Pyx_INCREF(__pyx_t_6); __pyx_t_7 = 0;
          __pyx_t_8 = NULL;
        } else {
          __pyx_t_7 = -1; __pyx_t_6 = PyObject_GetIter(__pyx_v_const); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_6);
          __pyx_t_8 = Py_TYPE(__pyx_t_6)->tp_iternext; if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 501, __pyx_L8_error)
        }
        for (;;) {
          if (likely(!__pyx_t_8)) {
            if (likely(PyList_CheckExact(__pyx_t_6))) {
              if (__pyx_t_7 >= PyList_GET_SIZE(__pyx_t_6)) break;
              #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
              __pyx_t_9 = PyList_GET_ITEM(__pyx_t_6, __pyx_t_7); __Pyx_INCREF(__pyx_t_9); __pyx_t_7++; if (unlikely(0 < 0)) __PYX_ERR(0, 501, __pyx_L8_error)
              #else
              __pyx_t_9 = PySequence_ITEM(__pyx_t_6, __pyx_t_7); __pyx_t_7++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 501, __pyx_L8_error)
              __Pyx_GOTREF(__pyx_t_9);
              #endif
            } else {
              if (__pyx_t_7 >= PyTuple_GET_SIZE(__pyx_t_6)) break;
              #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
              __pyx_t_9 = PyTuple_GET_ITEM(__pyx_t_6, __pyx_t_7); __Pyx_INCREF(__pyx_t_9); __pyx_t_7++; if (unlikely(0 < 0)) __PYX_ERR(0, 501, __pyx_L8_error)
              #else
              __pyx_t_9 = PySequence_ITEM(__pyx_t_6, __pyx_t_7); __pyx_t_7++; if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 501, __pyx_L8_error)
              __Pyx_GOTREF(__pyx_t_9);
              #endif
            }
          } else {
            __pyx_t_9 = __pyx_t_8(__pyx_t_6);
            if (unlikely(!__pyx_t_9)) {
              PyObject* exc_type = PyErr_Occurred();
              if (exc_type) {
                if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
                else __PYX_ERR(0, 501, __pyx_L8_error)
              }
              break;
            }
            __Pyx_GOTREF(__pyx_t_9);
          }
          __Pyx_XDECREF_SET(__pyx_8genexpr1__pyx_v_i, __pyx_t_9);
          __pyx_t_9 = 0;
          __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_math); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_sqrt); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_11);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          __pyx_t_12 = __Pyx_PyObject_Ord(__pyx_8genexpr1__pyx_v_i); if (unlikely(__pyx_t_12 == ((long)(long)(Py_UCS4)-1))) __PYX_ERR(0, 501, __pyx_L8_error)
          __pyx_t_10 = __Pyx_PyInt_From_long(__pyx_t_12); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_10);
          __pyx_t_13 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_11))) {
            __pyx_t_13 = PyMethod_GET_SELF(__pyx_t_11);
            if (likely(__pyx_t_13)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_11);
              __Pyx_INCREF(__pyx_t_13);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_11, function);
            }
          }
          __pyx_t_9 = (__pyx_t_13) ? __Pyx_PyObject_Call2Args(__pyx_t_11, __pyx_t_13, __pyx_t_10) : __Pyx_PyObject_CallOneArg(__pyx_t_11, __pyx_t_10);
          __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
          if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
          __pyx_t_11 = __Pyx_PyNumber_Int(__pyx_t_9); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_11);
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
          __pyx_t_9 = __Pyx_PyObject_CallOneArg(__pyx_builtin_chr, __pyx_t_11); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
          if (unlikely(__Pyx_ListComp_Append(__pyx_t_1, (PyObject*)__pyx_t_9))) __PYX_ERR(0, 501, __pyx_L8_error)
          __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
        }
        __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_i); __pyx_8genexpr1__pyx_v_i = 0;
        goto __pyx_L11_exit_scope;
        __pyx_L8_error:;
        __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_i); __pyx_8genexpr1__pyx_v_i = 0;
        goto __pyx_L1_error;
        __pyx_L11_exit_scope:;
      } 
      __pyx_t_6 = PyUnicode_Join(__pyx_kp_u__12, __pyx_t_1); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 501, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF_SET(__pyx_v_source, ((PyObject*)__pyx_t_6));
      __pyx_t_6 = 0;

      
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_14, &__pyx_t_15, &__pyx_t_16);
        __Pyx_XGOTREF(__pyx_t_14);
        __Pyx_XGOTREF(__pyx_t_15);
        __Pyx_XGOTREF(__pyx_t_16);
         {

          
          __pyx_t_6 = PyTuple_New(3); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 503, __pyx_L12_error)
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_INCREF(__pyx_v_source);
          __Pyx_GIVEREF(__pyx_v_source);
          PyTuple_SET_ITEM(__pyx_t_6, 0, __pyx_v_source);
          __Pyx_INCREF(__pyx_n_u_string);
          __Pyx_GIVEREF(__pyx_n_u_string);
          PyTuple_SET_ITEM(__pyx_t_6, 1, __pyx_n_u_string);
          __Pyx_INCREF(__pyx_n_u_exec);
          __Pyx_GIVEREF(__pyx_n_u_exec);
          PyTuple_SET_ITEM(__pyx_t_6, 2, __pyx_n_u_exec);
          __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_6, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 503, __pyx_L12_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

          
          __Pyx_XDECREF(__pyx_r);
          __Pyx_INCREF(__pyx_v_source);
          __pyx_r = __pyx_v_source;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          goto __pyx_L16_try_return;

          
        }
        __pyx_L12_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
        __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;

        
        __pyx_t_17 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
        if (__pyx_t_17) {
          __Pyx_AddTraceback("decode.DecodingAlgorithms.math_sqrt", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_1, &__pyx_t_6, &__pyx_t_9) < 0) __PYX_ERR(0, 505, __pyx_L14_except_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_GOTREF(__pyx_t_6);
          __Pyx_GOTREF(__pyx_t_9);
          __Pyx_INCREF(__pyx_t_6);
          __pyx_v_err = __pyx_t_6;
           {

            
            __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_DEBUG_MODE); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 506, __pyx_L25_error)
            __Pyx_GOTREF(__pyx_t_11);
            __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_11); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 506, __pyx_L25_error)
            __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
            if (__pyx_t_5) {

              
              __Pyx_GetModuleGlobalName(__pyx_t_10, __pyx_n_s_console); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 507, __pyx_L25_error)
              __Pyx_GOTREF(__pyx_t_10);
              __pyx_t_13 = __Pyx_PyObject_GetAttrStr(__pyx_t_10, __pyx_n_s_log); if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 507, __pyx_L25_error)
              __Pyx_GOTREF(__pyx_t_13);
              __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
              __pyx_t_10 = __Pyx_PyObject_FormatSimple(__pyx_v_err, __pyx_empty_unicode); if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 507, __pyx_L25_error)
              __Pyx_GOTREF(__pyx_t_10);
              __pyx_t_18 = __Pyx_PyUnicode_Concat(__pyx_kp_u_ERROR, __pyx_t_10); if (unlikely(!__pyx_t_18)) __PYX_ERR(0, 507, __pyx_L25_error)
              __Pyx_GOTREF(__pyx_t_18);
              __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
              __pyx_t_10 = NULL;
              if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_13))) {
                __pyx_t_10 = PyMethod_GET_SELF(__pyx_t_13);
                if (likely(__pyx_t_10)) {
                  PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_13);
                  __Pyx_INCREF(__pyx_t_10);
                  __Pyx_INCREF(function);
                  __Pyx_DECREF_SET(__pyx_t_13, function);
                }
              }
              __pyx_t_11 = (__pyx_t_10) ? __Pyx_PyObject_Call2Args(__pyx_t_13, __pyx_t_10, __pyx_t_18) : __Pyx_PyObject_CallOneArg(__pyx_t_13, __pyx_t_18);
              __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
              __Pyx_DECREF(__pyx_t_18); __pyx_t_18 = 0;
              if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 507, __pyx_L25_error)
              __Pyx_GOTREF(__pyx_t_11);
              __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;

              
            }
          }

          
           {
            {
              __Pyx_DECREF(__pyx_v_err);
              __pyx_v_err = NULL;
              goto __pyx_L26;
            }
            __pyx_L25_error:;
            {
              __Pyx_PyThreadState_declare
              __Pyx_PyThreadState_assign
              __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_25 = 0; __pyx_t_26 = 0;
              __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
              __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              __Pyx_XDECREF(__pyx_t_18); __pyx_t_18 = 0;
              if (PY_MAJOR_VERSION >= 3) __Pyx_ExceptionSwap(&__pyx_t_24, &__pyx_t_25, &__pyx_t_26);
              if ((PY_MAJOR_VERSION < 3) || unlikely(__Pyx_GetException(&__pyx_t_21, &__pyx_t_22, &__pyx_t_23) < 0)) __Pyx_ErrFetch(&__pyx_t_21, &__pyx_t_22, &__pyx_t_23);
              __Pyx_XGOTREF(__pyx_t_21);
              __Pyx_XGOTREF(__pyx_t_22);
              __Pyx_XGOTREF(__pyx_t_23);
              __Pyx_XGOTREF(__pyx_t_24);
              __Pyx_XGOTREF(__pyx_t_25);
              __Pyx_XGOTREF(__pyx_t_26);
              __pyx_t_17 = __pyx_lineno; __pyx_t_19 = __pyx_clineno; __pyx_t_20 = __pyx_filename;
              {
                __Pyx_DECREF(__pyx_v_err);
                __pyx_v_err = NULL;
              }
              if (PY_MAJOR_VERSION >= 3) {
                __Pyx_XGIVEREF(__pyx_t_24);
                __Pyx_XGIVEREF(__pyx_t_25);
                __Pyx_XGIVEREF(__pyx_t_26);
                __Pyx_ExceptionReset(__pyx_t_24, __pyx_t_25, __pyx_t_26);
              }
              __Pyx_XGIVEREF(__pyx_t_21);
              __Pyx_XGIVEREF(__pyx_t_22);
              __Pyx_XGIVEREF(__pyx_t_23);
              __Pyx_ErrRestore(__pyx_t_21, __pyx_t_22, __pyx_t_23);
              __pyx_t_21 = 0; __pyx_t_22 = 0; __pyx_t_23 = 0; __pyx_t_24 = 0; __pyx_t_25 = 0; __pyx_t_26 = 0;
              __pyx_lineno = __pyx_t_17; __pyx_clineno = __pyx_t_19; __pyx_filename = __pyx_t_20;
              goto __pyx_L14_except_error;
            }
            __pyx_L26:;
          }
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
          goto __pyx_L13_exception_handled;
        }
        goto __pyx_L14_except_error;
        __pyx_L14_except_error:;

        
        __Pyx_XGIVEREF(__pyx_t_14);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_ExceptionReset(__pyx_t_14, __pyx_t_15, __pyx_t_16);
        goto __pyx_L1_error;
        __pyx_L16_try_return:;
        __Pyx_XGIVEREF(__pyx_t_14);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_ExceptionReset(__pyx_t_14, __pyx_t_15, __pyx_t_16);
        goto __pyx_L0;
        __pyx_L13_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_14);
        __Pyx_XGIVEREF(__pyx_t_15);
        __Pyx_XGIVEREF(__pyx_t_16);
        __Pyx_ExceptionReset(__pyx_t_14, __pyx_t_15, __pyx_t_16);
      }

      
    }

    
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_Call(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])), __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 508, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_Raise(__pyx_t_2, 0, 0, 0);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __PYX_ERR(0, 508, __pyx_L1_error)

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_9);
  __Pyx_XDECREF(__pyx_t_10);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_13);
  __Pyx_XDECREF(__pyx_t_18);
  __Pyx_AddTraceback("decode.DecodingAlgorithms.math_sqrt", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_const);
  __Pyx_XDECREF(__pyx_v_source);
  __Pyx_XDECREF(__pyx_v_err);
  __Pyx_XDECREF(__pyx_8genexpr1__pyx_v_i);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_1to_string(PyObject *__pyx_self, PyObject *__pyx_v_data); 
static PyMethodDef __pyx_mdef_6decode_1to_string = {"to_string", (PyCFunction)__pyx_pw_6decode_1to_string, METH_O, 0};
static PyObject *__pyx_pw_6decode_1to_string(PyObject *__pyx_self, PyObject *__pyx_v_data) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("to_string (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_to_string(__pyx_self, ((PyObject *)__pyx_v_data));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_to_string(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_data) {
  PyObject *__pyx_v_bytecode = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("to_string", 0);
  __Pyx_INCREF(__pyx_v_data);

  
  __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_v_data)), ((PyObject *)(&PyBytes_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 512, __pyx_L1_error)
  __pyx_t_2 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_2 < 0)) __PYX_ERR(0, 512, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_2) {

    
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_data, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 513, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_ENCODEING); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 513, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_5)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_5);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_1 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_5, __pyx_t_4) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4);
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 513, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_1);
    __pyx_t_1 = 0;

    
  }

  
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 514, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_v_data);
  __Pyx_GIVEREF(__pyx_v_data);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_data);
  __Pyx_INCREF(__pyx_n_u_string);
  __Pyx_GIVEREF(__pyx_n_u_string);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_string);
  __Pyx_INCREF(__pyx_n_u_exec);
  __Pyx_GIVEREF(__pyx_n_u_exec);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_n_u_exec);
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_compile, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 514, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_v_bytecode = __pyx_t_3;
  __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_v_bytecode, __pyx_n_s_co_consts); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 515, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_6 = PyObject_Length(__pyx_t_3); if (unlikely(__pyx_t_6 == ((Py_ssize_t)-1))) __PYX_ERR(0, 515, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_2 = ((__pyx_t_6 > 1) != 0);
  if (likely(__pyx_t_2)) {

    
    __Pyx_XDECREF(__pyx_r);
    if (!(likely(PyUnicode_CheckExact(__pyx_v_data))||((__pyx_v_data) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "unicode", Py_TYPE(__pyx_v_data)->tp_name), 0))) __PYX_ERR(0, 516, __pyx_L1_error)
    __Pyx_INCREF(__pyx_v_data);
    __pyx_r = ((PyObject*)__pyx_v_data);
    goto __pyx_L0;

    
  }

  
   {
    __pyx_t_3 = __Pyx_PyObject_CallNoArg(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0]))); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 518, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_Raise(__pyx_t_3, 0, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __PYX_ERR(0, 518, __pyx_L1_error)
  }

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_AddTraceback("decode.to_string", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bytecode);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_3data(PyObject *__pyx_self, PyObject *__pyx_v_filename); 
static PyMethodDef __pyx_mdef_6decode_3data = {"data", (PyCFunction)__pyx_pw_6decode_3data, METH_O, 0};
static PyObject *__pyx_pw_6decode_3data(PyObject *__pyx_self, PyObject *__pyx_v_filename) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("data (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_2data(__pyx_self, ((PyObject *)__pyx_v_filename));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_2data(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_filename) {
  PyObject *__pyx_v_bfile = NULL;
  PyObject *__pyx_v_content = NULL;
  PyObject *__pyx_v_file_type = NULL;
  PyObject *__pyx_v_output = NULL;
  PyObject *__pyx_v_file = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  PyObject *__pyx_t_13 = NULL;
  PyObject *__pyx_t_14 = NULL;
  int __pyx_t_15;
  Py_ssize_t __pyx_t_16;
  Py_UCS4 __pyx_t_17;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("data", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_os); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 525, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_path); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 525, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_isfile); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 525, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_v_filename) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_filename);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 525, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 525, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_5 = ((!__pyx_t_4) != 0);
  if (__pyx_t_5) {

    
    __pyx_t_1 = __Pyx_PyObject_FormatSimple(__pyx_v_filename, __pyx_empty_unicode); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 526, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_2 = __Pyx_PyUnicode_Concat(__pyx_kp_u_file_not_found, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 526, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_exit, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 526, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
  }

  
   {
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 528, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_filename);
    __Pyx_GIVEREF(__pyx_v_filename);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_filename);
    __Pyx_INCREF(__pyx_n_u_rb);
    __Pyx_GIVEREF(__pyx_n_u_rb);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_rb);
    __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_1, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 528, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_6 = __Pyx_PyObject_LookupSpecial(__pyx_t_2, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 528, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_6);
    __pyx_t_3 = __Pyx_PyObject_LookupSpecial(__pyx_t_2, __pyx_n_s_enter); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 528, __pyx_L4_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_7 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_7)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_7);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_1 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
    __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 528, __pyx_L4_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __pyx_t_1;
    __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
     {
      {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        __Pyx_ExceptionSave(&__pyx_t_8, &__pyx_t_9, &__pyx_t_10);
        __Pyx_XGOTREF(__pyx_t_8);
        __Pyx_XGOTREF(__pyx_t_9);
        __Pyx_XGOTREF(__pyx_t_10);
         {
          __pyx_v_bfile = __pyx_t_3;
          __pyx_t_3 = 0;

          
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_bfile, __pyx_n_s_read); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 529, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_1 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
            __pyx_t_1 = PyMethod_GET_SELF(__pyx_t_2);
            if (likely(__pyx_t_1)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
              __Pyx_INCREF(__pyx_t_1);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_2, function);
            }
          }
          __pyx_t_3 = (__pyx_t_1) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_1) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 529, __pyx_L8_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_v_content = __pyx_t_3;
          __pyx_t_3 = 0;

          
        }
        __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
        __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
        __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
        goto __pyx_L13_try_end;
        __pyx_L8_error:;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
         {
          __Pyx_AddTraceback("decode.data", __pyx_clineno, __pyx_lineno, __pyx_filename);
          if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_2, &__pyx_t_1) < 0) __PYX_ERR(0, 528, __pyx_L10_except_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_7 = PyTuple_Pack(3, __pyx_t_3, __pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 528, __pyx_L10_except_error)
          __Pyx_GOTREF(__pyx_t_7);
          __pyx_t_11 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_t_7, NULL);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 528, __pyx_L10_except_error)
          __Pyx_GOTREF(__pyx_t_11);
          __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_11);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
          if (__pyx_t_5 < 0) __PYX_ERR(0, 528, __pyx_L10_except_error)
          __pyx_t_4 = ((!(__pyx_t_5 != 0)) != 0);
          if (__pyx_t_4) {
            __Pyx_GIVEREF(__pyx_t_3);
            __Pyx_GIVEREF(__pyx_t_2);
            __Pyx_XGIVEREF(__pyx_t_1);
            __Pyx_ErrRestoreWithState(__pyx_t_3, __pyx_t_2, __pyx_t_1);
            __pyx_t_3 = 0; __pyx_t_2 = 0; __pyx_t_1 = 0; 
            __PYX_ERR(0, 528, __pyx_L10_except_error)
          }
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          goto __pyx_L9_exception_handled;
        }
        __pyx_L10_except_error:;
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
        goto __pyx_L1_error;
        __pyx_L9_exception_handled:;
        __Pyx_XGIVEREF(__pyx_t_8);
        __Pyx_XGIVEREF(__pyx_t_9);
        __Pyx_XGIVEREF(__pyx_t_10);
        __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
        __pyx_L13_try_end:;
      }
    }
     {
      {
        if (__pyx_t_6) {
          __pyx_t_10 = __Pyx_PyObject_Call(__pyx_t_6, __pyx_tuple__16, NULL);
          __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
          if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 528, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_10);
          __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
        }
        goto __pyx_L7;
      }
      __pyx_L7:;
    }
    goto __pyx_L17;
    __pyx_L4_error:;
    __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
    goto __pyx_L1_error;
    __pyx_L17:;
  }

  
  if (unlikely(!__pyx_v_content)) { __Pyx_RaiseUnboundLocalError("content"); __PYX_ERR(0, 531, __pyx_L1_error) }
  __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_v_content, 0, 4, NULL, NULL, &__pyx_slice__108, 0, 1, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_MAGIC_NUMBERS); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = (__Pyx_PySequence_ContainsTF(__pyx_t_1, __pyx_t_2, Py_EQ)); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_5 = (__pyx_t_4 != 0);
  if (__pyx_t_5) {

    
    __Pyx_INCREF(__pyx_n_u_pyc_2);
    __pyx_v_file_type = __pyx_n_u_pyc_2;

    
    if (unlikely(!__pyx_v_content)) { __Pyx_RaiseUnboundLocalError("content"); __PYX_ERR(0, 533, __pyx_L1_error) }
    __Pyx_INCREF(__pyx_v_content);
    __pyx_v_output = __pyx_v_content;

    
    goto __pyx_L18;
  }

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_ZIP_MAGIC_NUMBER); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 535, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (unlikely(!__pyx_v_content)) { __Pyx_RaiseUnboundLocalError("content"); __PYX_ERR(0, 535, __pyx_L1_error) }
  __pyx_t_5 = (__Pyx_PySequence_ContainsTF(__pyx_t_2, __pyx_v_content, Py_EQ)); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 535, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_4 = (__pyx_t_5 != 0);
  if (__pyx_t_4) {

    
    __Pyx_INCREF(__pyx_n_u_zip);
    __pyx_v_file_type = __pyx_n_u_zip;

    
    __Pyx_INCREF(__pyx_v_filename);
    __pyx_v_output = __pyx_v_filename;

    
    goto __pyx_L18;
  }

  
   {
    {
      __Pyx_PyThreadState_declare
      __Pyx_PyThreadState_assign
      __Pyx_ExceptionSave(&__pyx_t_6, &__pyx_t_10, &__pyx_t_9);
      __Pyx_XGOTREF(__pyx_t_6);
      __Pyx_XGOTREF(__pyx_t_10);
      __Pyx_XGOTREF(__pyx_t_9);
       {

        
         {
          __pyx_t_2 = PyTuple_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 541, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_INCREF(__pyx_v_filename);
          __Pyx_GIVEREF(__pyx_v_filename);
          PyTuple_SET_ITEM(__pyx_t_2, 0, __pyx_v_filename);
          __Pyx_INCREF(__pyx_n_u_r);
          __Pyx_GIVEREF(__pyx_n_u_r);
          PyTuple_SET_ITEM(__pyx_t_2, 1, __pyx_n_u_r);
          __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_open, __pyx_t_2, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 541, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_8 = __Pyx_PyObject_LookupSpecial(__pyx_t_1, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 541, __pyx_L19_error)
          __Pyx_GOTREF(__pyx_t_8);
          __pyx_t_3 = __Pyx_PyObject_LookupSpecial(__pyx_t_1, __pyx_n_s_enter); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 541, __pyx_L25_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_7 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_7) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 541, __pyx_L25_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __pyx_t_2;
          __pyx_t_2 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
           {
            {
              __Pyx_PyThreadState_declare
              __Pyx_PyThreadState_assign
              __Pyx_ExceptionSave(&__pyx_t_11, &__pyx_t_12, &__pyx_t_13);
              __Pyx_XGOTREF(__pyx_t_11);
              __Pyx_XGOTREF(__pyx_t_12);
              __Pyx_XGOTREF(__pyx_t_13);
               {
                __pyx_v_file = __pyx_t_3;
                __pyx_t_3 = 0;

                
                __Pyx_INCREF(__pyx_n_u_py);
                __pyx_v_file_type = __pyx_n_u_py;

                
                __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_file, __pyx_n_s_read); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 543, __pyx_L29_error)
                __Pyx_GOTREF(__pyx_t_1);
                __pyx_t_2 = NULL;
                if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_1))) {
                  __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_1);
                  if (likely(__pyx_t_2)) {
                    PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                    __Pyx_INCREF(__pyx_t_2);
                    __Pyx_INCREF(function);
                    __Pyx_DECREF_SET(__pyx_t_1, function);
                  }
                }
                __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_1);
                __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 543, __pyx_L29_error)
                __Pyx_GOTREF(__pyx_t_3);
                __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
                __pyx_v_output = __pyx_t_3;
                __pyx_t_3 = 0;

                
              }
              __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
              __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
              __Pyx_XDECREF(__pyx_t_13); __pyx_t_13 = 0;
              goto __pyx_L34_try_end;
              __pyx_L29_error:;
              __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
              __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
              __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
               {
                __Pyx_AddTraceback("decode.data", __pyx_clineno, __pyx_lineno, __pyx_filename);
                if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_1, &__pyx_t_2) < 0) __PYX_ERR(0, 541, __pyx_L31_except_error)
                __Pyx_GOTREF(__pyx_t_3);
                __Pyx_GOTREF(__pyx_t_1);
                __Pyx_GOTREF(__pyx_t_2);
                __pyx_t_7 = PyTuple_Pack(3, __pyx_t_3, __pyx_t_1, __pyx_t_2); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 541, __pyx_L31_except_error)
                __Pyx_GOTREF(__pyx_t_7);
                __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_t_7, NULL);
                __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
                __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
                if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 541, __pyx_L31_except_error)
                __Pyx_GOTREF(__pyx_t_14);
                __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_14);
                __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
                if (__pyx_t_4 < 0) __PYX_ERR(0, 541, __pyx_L31_except_error)
                __pyx_t_5 = ((!(__pyx_t_4 != 0)) != 0);
                if (__pyx_t_5) {
                  __Pyx_GIVEREF(__pyx_t_3);
                  __Pyx_GIVEREF(__pyx_t_1);
                  __Pyx_XGIVEREF(__pyx_t_2);
                  __Pyx_ErrRestoreWithState(__pyx_t_3, __pyx_t_1, __pyx_t_2);
                  __pyx_t_3 = 0; __pyx_t_1 = 0; __pyx_t_2 = 0; 
                  __PYX_ERR(0, 541, __pyx_L31_except_error)
                }
                __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
                __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
                __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
                goto __pyx_L30_exception_handled;
              }
              __pyx_L31_except_error:;
              __Pyx_XGIVEREF(__pyx_t_11);
              __Pyx_XGIVEREF(__pyx_t_12);
              __Pyx_XGIVEREF(__pyx_t_13);
              __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_12, __pyx_t_13);
              goto __pyx_L19_error;
              __pyx_L30_exception_handled:;
              __Pyx_XGIVEREF(__pyx_t_11);
              __Pyx_XGIVEREF(__pyx_t_12);
              __Pyx_XGIVEREF(__pyx_t_13);
              __Pyx_ExceptionReset(__pyx_t_11, __pyx_t_12, __pyx_t_13);
              __pyx_L34_try_end:;
            }
          }
           {
            {
              if (__pyx_t_8) {
                __pyx_t_13 = __Pyx_PyObject_Call(__pyx_t_8, __pyx_tuple__16, NULL);
                __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
                if (unlikely(!__pyx_t_13)) __PYX_ERR(0, 541, __pyx_L19_error)
                __Pyx_GOTREF(__pyx_t_13);
                __Pyx_DECREF(__pyx_t_13); __pyx_t_13 = 0;
              }
              goto __pyx_L28;
            }
            __pyx_L28:;
          }
          goto __pyx_L38;
          __pyx_L25_error:;
          __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
          goto __pyx_L19_error;
          __pyx_L38:;
        }

        
      }
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
      __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
      goto __pyx_L24_try_end;
      __pyx_L19_error:;
      __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
      __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

      
      __pyx_t_15 = __Pyx_PyErr_ExceptionMatches(__pyx_builtin_UnicodeDecodeError);
      if (__pyx_t_15) {
        __Pyx_AddTraceback("decode.data", __pyx_clineno, __pyx_lineno, __pyx_filename);
        if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_1, &__pyx_t_3) < 0) __PYX_ERR(0, 544, __pyx_L21_except_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_GOTREF(__pyx_t_3);

        
        __Pyx_INCREF(__pyx_kp_u__109);
        __Pyx_XDECREF_SET(__pyx_v_file_type, __pyx_kp_u__109);

        
        __Pyx_INCREF(Py_None);
        __Pyx_XDECREF_SET(__pyx_v_output, Py_None);
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        goto __pyx_L20_exception_handled;
      }
      goto __pyx_L21_except_error;
      __pyx_L21_except_error:;

      
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_10, __pyx_t_9);
      goto __pyx_L1_error;
      __pyx_L20_exception_handled:;
      __Pyx_XGIVEREF(__pyx_t_6);
      __Pyx_XGIVEREF(__pyx_t_10);
      __Pyx_XGIVEREF(__pyx_t_9);
      __Pyx_ExceptionReset(__pyx_t_6, __pyx_t_10, __pyx_t_9);
      __pyx_L24_try_end:;
    }
  }
  __pyx_L18:;

  
  __pyx_t_3 = PyTuple_New(3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_16 = 0;
  __pyx_t_17 = 127;
  __Pyx_INCREF(__pyx_kp_u_File_type);
  __pyx_t_16 += 12;
  __Pyx_GIVEREF(__pyx_kp_u_File_type);
  PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_kp_u_File_type);
  if (unlikely(!__pyx_v_file_type)) { __Pyx_RaiseUnboundLocalError("file_type"); __PYX_ERR(0, 548, __pyx_L1_error) }
  __Pyx_INCREF(__pyx_v_file_type);
  __pyx_t_17 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_v_file_type) > __pyx_t_17) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_v_file_type) : __pyx_t_17;
  __pyx_t_16 += __Pyx_PyUnicode_GET_LENGTH(__pyx_v_file_type);
  __Pyx_GIVEREF(__pyx_v_file_type);
  PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_v_file_type);
  __Pyx_INCREF(__pyx_kp_u__110);
  __pyx_t_16 += 2;
  __Pyx_GIVEREF(__pyx_kp_u__110);
  PyTuple_SET_ITEM(__pyx_t_3, 2, __pyx_kp_u__110);
  __pyx_t_1 = __Pyx_PyUnicode_Join(__pyx_t_3, 3, __pyx_t_16, __pyx_t_17); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 548, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_XDECREF(__pyx_r);
  if (unlikely(!__pyx_v_output)) { __Pyx_RaiseUnboundLocalError("output"); __PYX_ERR(0, 549, __pyx_L1_error) }
  __Pyx_INCREF(__pyx_v_output);
  __pyx_r = __pyx_v_output;
  goto __pyx_L0;

  

  
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("decode.data", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_bfile);
  __Pyx_XDECREF(__pyx_v_content);
  __Pyx_XDECREF(__pyx_v_file_type);
  __Pyx_XDECREF(__pyx_v_output);
  __Pyx_XDECREF(__pyx_v_file);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_5show_code(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); 
static PyMethodDef __pyx_mdef_6decode_5show_code = {"show_code", (PyCFunction)__pyx_pw_6decode_5show_code, METH_NOARGS, 0};
static PyObject *__pyx_pw_6decode_5show_code(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("show_code (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_4show_code(__pyx_self);

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_4show_code(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_v_syntax = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  int __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("show_code", 0);

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_decoding_algorithms); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 553, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_file_data); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 553, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_2)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 553, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_3 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_3 < 0)) __PYX_ERR(0, 553, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__pyx_t_3) {

    
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 554, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_Syntax); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 555, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_decoding_algorithms); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 555, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_file_data); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 555, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_4 = NULL;
    __pyx_t_6 = 0;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
        __pyx_t_6 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_5, __pyx_n_u_python};
      __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 555, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_4, __pyx_t_5, __pyx_n_u_python};
      __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_6, 2+__pyx_t_6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 555, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    } else
    #endif
    {
      __pyx_t_7 = PyTuple_New(2+__pyx_t_6); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 555, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      if (__pyx_t_4) {
        __Pyx_GIVEREF(__pyx_t_4); PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_4); __pyx_t_4 = NULL;
      }
      __Pyx_GIVEREF(__pyx_t_5);
      PyTuple_SET_ITEM(__pyx_t_7, 0+__pyx_t_6, __pyx_t_5);
      __Pyx_INCREF(__pyx_n_u_python);
      __Pyx_GIVEREF(__pyx_n_u_python);
      PyTuple_SET_ITEM(__pyx_t_7, 1+__pyx_t_6, __pyx_n_u_python);
      __pyx_t_5 = 0;
      __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 555, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_v_syntax = __pyx_t_1;
    __pyx_t_1 = 0;

    
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_console); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 556, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_print); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 556, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_7);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_7))) {
      __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_7);
      if (likely(__pyx_t_2)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_7);
        __Pyx_INCREF(__pyx_t_2);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_7, function);
      }
    }
    __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_7, __pyx_t_2, __pyx_v_syntax) : __Pyx_PyObject_CallOneArg(__pyx_t_7, __pyx_v_syntax);
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 556, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

    
  }

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_AddTraceback("decode.show_code", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_syntax);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}




static PyObject *__pyx_pw_6decode_7show_file_size(PyObject *__pyx_self, PyObject *__pyx_v_file); 
static PyMethodDef __pyx_mdef_6decode_7show_file_size = {"show_file_size", (PyCFunction)__pyx_pw_6decode_7show_file_size, METH_O, 0};
static PyObject *__pyx_pw_6decode_7show_file_size(PyObject *__pyx_self, PyObject *__pyx_v_file) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("show_file_size (wrapper)", 0);
  __pyx_r = __pyx_pf_6decode_6show_file_size(__pyx_self, ((PyObject *)__pyx_v_file));

  
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6decode_6show_file_size(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_file) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  Py_UCS4 __pyx_t_3;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("show_file_size", 0);

  
  __pyx_t_1 = PyTuple_New(3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_3 = 127;
  __Pyx_INCREF(__pyx_kp_u_1_32msize);
  __pyx_t_2 += 15;
  __Pyx_GIVEREF(__pyx_kp_u_1_32msize);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_1_32msize);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_SIZE); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __pyx_t_6 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_5))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_5);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_5);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_5, function);
    }
  }
  __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_5, __pyx_t_6, __pyx_v_file) : __Pyx_PyObject_CallOneArg(__pyx_t_5, __pyx_v_file);
  __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
  if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_5 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_size); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_FormatSimple(__pyx_t_5, __pyx_empty_unicode); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
  __pyx_t_3 = (__Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) > __pyx_t_3) ? __Pyx_PyUnicode_MAX_CHAR_VALUE(__pyx_t_4) : __pyx_t_3;
  __pyx_t_2 += __Pyx_PyUnicode_GET_LENGTH(__pyx_t_4);
  __Pyx_GIVEREF(__pyx_t_4);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_4);
  __pyx_t_4 = 0;
  __Pyx_INCREF(__pyx_kp_u_0m_2);
  __pyx_t_2 += 4;
  __Pyx_GIVEREF(__pyx_kp_u_0m_2);
  PyTuple_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u_0m_2);
  __pyx_t_4 = __Pyx_PyUnicode_Join(__pyx_t_1, 3, __pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_4); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 560, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  

  
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_AddTraceback("decode.show_file_size", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static struct __pyx_obj_6decode___pyx_scope_struct__object *__pyx_freelist_6decode___pyx_scope_struct__object[8];
static int __pyx_freecount_6decode___pyx_scope_struct__object = 0;

static PyObject *__pyx_tp_new_6decode___pyx_scope_struct__object(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6decode___pyx_scope_struct__object > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct__object)))) {
    o = (PyObject*)__pyx_freelist_6decode___pyx_scope_struct__object[--__pyx_freecount_6decode___pyx_scope_struct__object];
    memset(o, 0, sizeof(struct __pyx_obj_6decode___pyx_scope_struct__object));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6decode___pyx_scope_struct__object(PyObject *o) {
  struct __pyx_obj_6decode___pyx_scope_struct__object *p = (struct __pyx_obj_6decode___pyx_scope_struct__object *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_consts_walker);
  Py_CLEAR(p->__pyx_v_object_type);
  Py_CLEAR(p->__pyx_v_store_length);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6decode___pyx_scope_struct__object < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct__object)))) {
    __pyx_freelist_6decode___pyx_scope_struct__object[__pyx_freecount_6decode___pyx_scope_struct__object++] = ((struct __pyx_obj_6decode___pyx_scope_struct__object *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_6decode___pyx_scope_struct__object(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6decode___pyx_scope_struct__object *p = (struct __pyx_obj_6decode___pyx_scope_struct__object *)o;
  if (p->__pyx_v_consts_walker) {
    e = (*v)(p->__pyx_v_consts_walker, a); if (e) return e;
  }
  if (p->__pyx_v_object_type) {
    e = (*v)(p->__pyx_v_object_type, a); if (e) return e;
  }
  if (p->__pyx_v_store_length) {
    e = (*v)(p->__pyx_v_store_length, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_6decode___pyx_scope_struct__object(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_6decode___pyx_scope_struct__object *p = (struct __pyx_obj_6decode___pyx_scope_struct__object *)o;
  tmp = ((PyObject*)p->__pyx_v_consts_walker);
  p->__pyx_v_consts_walker = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_object_type);
  p->__pyx_v_object_type = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_store_length);
  p->__pyx_v_store_length = ((PyObject*)Py_None); Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_6decode___pyx_scope_struct__object = {
  PyVarObject_HEAD_INIT(0, 0)
  "decode.__pyx_scope_struct__object", 
  sizeof(struct __pyx_obj_6decode___pyx_scope_struct__object), 
  0, 
  __pyx_tp_dealloc_6decode___pyx_scope_struct__object, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_6decode___pyx_scope_struct__object, 
  __pyx_tp_clear_6decode___pyx_scope_struct__object, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_6decode___pyx_scope_struct__object, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_6decode___pyx_scope_struct_1_function *__pyx_freelist_6decode___pyx_scope_struct_1_function[8];
static int __pyx_freecount_6decode___pyx_scope_struct_1_function = 0;

static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_1_function(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6decode___pyx_scope_struct_1_function > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_1_function)))) {
    o = (PyObject*)__pyx_freelist_6decode___pyx_scope_struct_1_function[--__pyx_freecount_6decode___pyx_scope_struct_1_function];
    memset(o, 0, sizeof(struct __pyx_obj_6decode___pyx_scope_struct_1_function));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6decode___pyx_scope_struct_1_function(PyObject *o) {
  struct __pyx_obj_6decode___pyx_scope_struct_1_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_1_function *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v__chr);
  Py_CLEAR(p->__pyx_v_func_pos);
  Py_CLEAR(p->__pyx_v_func_poss);
  Py_CLEAR(p->__pyx_v_function_body);
  Py_CLEAR(p->__pyx_v_function_name);
  Py_CLEAR(p->__pyx_v_open_brackets);
  Py_CLEAR(p->__pyx_v_pattern);
  Py_CLEAR(p->__pyx_v_string);
  Py_CLEAR(p->__pyx_t_0);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6decode___pyx_scope_struct_1_function < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_1_function)))) {
    __pyx_freelist_6decode___pyx_scope_struct_1_function[__pyx_freecount_6decode___pyx_scope_struct_1_function++] = ((struct __pyx_obj_6decode___pyx_scope_struct_1_function *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_6decode___pyx_scope_struct_1_function(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6decode___pyx_scope_struct_1_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_1_function *)o;
  if (p->__pyx_v__chr) {
    e = (*v)(p->__pyx_v__chr, a); if (e) return e;
  }
  if (p->__pyx_v_func_pos) {
    e = (*v)(p->__pyx_v_func_pos, a); if (e) return e;
  }
  if (p->__pyx_v_func_poss) {
    e = (*v)(p->__pyx_v_func_poss, a); if (e) return e;
  }
  if (p->__pyx_v_function_name) {
    e = (*v)(p->__pyx_v_function_name, a); if (e) return e;
  }
  if (p->__pyx_v_open_brackets) {
    e = (*v)(p->__pyx_v_open_brackets, a); if (e) return e;
  }
  if (p->__pyx_t_0) {
    e = (*v)(p->__pyx_t_0, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_6decode___pyx_scope_struct_1_function = {
  PyVarObject_HEAD_INIT(0, 0)
  "decode.__pyx_scope_struct_1_function", 
  sizeof(struct __pyx_obj_6decode___pyx_scope_struct_1_function), 
  0, 
  __pyx_tp_dealloc_6decode___pyx_scope_struct_1_function, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_6decode___pyx_scope_struct_1_function, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_6decode___pyx_scope_struct_1_function, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *__pyx_freelist_6decode___pyx_scope_struct_2_eval_filter[8];
static int __pyx_freecount_6decode___pyx_scope_struct_2_eval_filter = 0;

static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_2_eval_filter(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6decode___pyx_scope_struct_2_eval_filter > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter)))) {
    o = (PyObject*)__pyx_freelist_6decode___pyx_scope_struct_2_eval_filter[--__pyx_freecount_6decode___pyx_scope_struct_2_eval_filter];
    memset(o, 0, sizeof(struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6decode___pyx_scope_struct_2_eval_filter(PyObject *o) {
  struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *p = (struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_root_search);
  Py_CLEAR(p->__pyx_v_self);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6decode___pyx_scope_struct_2_eval_filter < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter)))) {
    __pyx_freelist_6decode___pyx_scope_struct_2_eval_filter[__pyx_freecount_6decode___pyx_scope_struct_2_eval_filter++] = ((struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_6decode___pyx_scope_struct_2_eval_filter(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *p = (struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *)o;
  if (p->__pyx_v_root_search) {
    e = (*v)(p->__pyx_v_root_search, a); if (e) return e;
  }
  if (p->__pyx_v_self) {
    e = (*v)(p->__pyx_v_self, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_6decode___pyx_scope_struct_2_eval_filter(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *p = (struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter *)o;
  tmp = ((PyObject*)p->__pyx_v_root_search);
  p->__pyx_v_root_search = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_self);
  p->__pyx_v_self = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_6decode___pyx_scope_struct_2_eval_filter = {
  PyVarObject_HEAD_INIT(0, 0)
  "decode.__pyx_scope_struct_2_eval_filter", 
  sizeof(struct __pyx_obj_6decode___pyx_scope_struct_2_eval_filter), 
  0, 
  __pyx_tp_dealloc_6decode___pyx_scope_struct_2_eval_filter, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_6decode___pyx_scope_struct_2_eval_filter, 
  __pyx_tp_clear_6decode___pyx_scope_struct_2_eval_filter, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_6decode___pyx_scope_struct_2_eval_filter, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *__pyx_freelist_6decode___pyx_scope_struct_3_exec_function[8];
static int __pyx_freecount_6decode___pyx_scope_struct_3_exec_function = 0;

static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_3_exec_function(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6decode___pyx_scope_struct_3_exec_function > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function)))) {
    o = (PyObject*)__pyx_freelist_6decode___pyx_scope_struct_3_exec_function[--__pyx_freecount_6decode___pyx_scope_struct_3_exec_function];
    memset(o, 0, sizeof(struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6decode___pyx_scope_struct_3_exec_function(PyObject *o) {
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_compile);
  Py_CLEAR(p->__pyx_v_exec);
  Py_CLEAR(p->__pyx_v_self);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6decode___pyx_scope_struct_3_exec_function < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function)))) {
    __pyx_freelist_6decode___pyx_scope_struct_3_exec_function[__pyx_freecount_6decode___pyx_scope_struct_3_exec_function++] = ((struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_6decode___pyx_scope_struct_3_exec_function(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *)o;
  if (p->__pyx_v_compile) {
    e = (*v)(p->__pyx_v_compile, a); if (e) return e;
  }
  if (p->__pyx_v_exec) {
    e = (*v)(p->__pyx_v_exec, a); if (e) return e;
  }
  if (p->__pyx_v_self) {
    e = (*v)(p->__pyx_v_self, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_6decode___pyx_scope_struct_3_exec_function(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function *)o;
  tmp = ((PyObject*)p->__pyx_v_compile);
  p->__pyx_v_compile = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_exec);
  p->__pyx_v_exec = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_self);
  p->__pyx_v_self = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_6decode___pyx_scope_struct_3_exec_function = {
  PyVarObject_HEAD_INIT(0, 0)
  "decode.__pyx_scope_struct_3_exec_function", 
  sizeof(struct __pyx_obj_6decode___pyx_scope_struct_3_exec_function), 
  0, 
  __pyx_tp_dealloc_6decode___pyx_scope_struct_3_exec_function, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_6decode___pyx_scope_struct_3_exec_function, 
  __pyx_tp_clear_6decode___pyx_scope_struct_3_exec_function, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_6decode___pyx_scope_struct_3_exec_function, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *__pyx_freelist_6decode___pyx_scope_struct_4_eval_function[8];
static int __pyx_freecount_6decode___pyx_scope_struct_4_eval_function = 0;

static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_4_eval_function(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6decode___pyx_scope_struct_4_eval_function > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function)))) {
    o = (PyObject*)__pyx_freelist_6decode___pyx_scope_struct_4_eval_function[--__pyx_freecount_6decode___pyx_scope_struct_4_eval_function];
    memset(o, 0, sizeof(struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6decode___pyx_scope_struct_4_eval_function(PyObject *o) {
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_compile);
  Py_CLEAR(p->__pyx_v_self);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6decode___pyx_scope_struct_4_eval_function < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function)))) {
    __pyx_freelist_6decode___pyx_scope_struct_4_eval_function[__pyx_freecount_6decode___pyx_scope_struct_4_eval_function++] = ((struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_6decode___pyx_scope_struct_4_eval_function(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *)o;
  if (p->__pyx_v_compile) {
    e = (*v)(p->__pyx_v_compile, a); if (e) return e;
  }
  if (p->__pyx_v_self) {
    e = (*v)(p->__pyx_v_self, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_6decode___pyx_scope_struct_4_eval_function(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *p = (struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function *)o;
  tmp = ((PyObject*)p->__pyx_v_compile);
  p->__pyx_v_compile = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  tmp = ((PyObject*)p->__pyx_v_self);
  p->__pyx_v_self = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_6decode___pyx_scope_struct_4_eval_function = {
  PyVarObject_HEAD_INIT(0, 0)
  "decode.__pyx_scope_struct_4_eval_function", 
  sizeof(struct __pyx_obj_6decode___pyx_scope_struct_4_eval_function), 
  0, 
  __pyx_tp_dealloc_6decode___pyx_scope_struct_4_eval_function, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_6decode___pyx_scope_struct_4_eval_function, 
  __pyx_tp_clear_6decode___pyx_scope_struct_4_eval_function, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_6decode___pyx_scope_struct_4_eval_function, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *__pyx_freelist_6decode___pyx_scope_struct_5_bytes_list[8];
static int __pyx_freecount_6decode___pyx_scope_struct_5_bytes_list = 0;

static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_5_bytes_list(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6decode___pyx_scope_struct_5_bytes_list > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list)))) {
    o = (PyObject*)__pyx_freelist_6decode___pyx_scope_struct_5_bytes_list[--__pyx_freecount_6decode___pyx_scope_struct_5_bytes_list];
    memset(o, 0, sizeof(struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6decode___pyx_scope_struct_5_bytes_list(PyObject *o) {
  struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *p = (struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_v_const);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6decode___pyx_scope_struct_5_bytes_list < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list)))) {
    __pyx_freelist_6decode___pyx_scope_struct_5_bytes_list[__pyx_freecount_6decode___pyx_scope_struct_5_bytes_list++] = ((struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_6decode___pyx_scope_struct_5_bytes_list(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *p = (struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *)o;
  if (p->__pyx_v_const) {
    e = (*v)(p->__pyx_v_const, a); if (e) return e;
  }
  return 0;
}

static int __pyx_tp_clear_6decode___pyx_scope_struct_5_bytes_list(PyObject *o) {
  PyObject* tmp;
  struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *p = (struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list *)o;
  tmp = ((PyObject*)p->__pyx_v_const);
  p->__pyx_v_const = Py_None; Py_INCREF(Py_None);
  Py_XDECREF(tmp);
  return 0;
}

static PyTypeObject __pyx_type_6decode___pyx_scope_struct_5_bytes_list = {
  PyVarObject_HEAD_INIT(0, 0)
  "decode.__pyx_scope_struct_5_bytes_list", 
  sizeof(struct __pyx_obj_6decode___pyx_scope_struct_5_bytes_list), 
  0, 
  __pyx_tp_dealloc_6decode___pyx_scope_struct_5_bytes_list, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_6decode___pyx_scope_struct_5_bytes_list, 
  __pyx_tp_clear_6decode___pyx_scope_struct_5_bytes_list, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_6decode___pyx_scope_struct_5_bytes_list, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
};

static struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *__pyx_freelist_6decode___pyx_scope_struct_6_genexpr[8];
static int __pyx_freecount_6decode___pyx_scope_struct_6_genexpr = 0;

static PyObject *__pyx_tp_new_6decode___pyx_scope_struct_6_genexpr(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6decode___pyx_scope_struct_6_genexpr > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr)))) {
    o = (PyObject*)__pyx_freelist_6decode___pyx_scope_struct_6_genexpr[--__pyx_freecount_6decode___pyx_scope_struct_6_genexpr];
    memset(o, 0, sizeof(struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr));
    (void) PyObject_INIT(o, t);
    PyObject_GC_Track(o);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6decode___pyx_scope_struct_6_genexpr(PyObject *o) {
  struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *p = (struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *)o;
  PyObject_GC_UnTrack(o);
  Py_CLEAR(p->__pyx_outer_scope);
  Py_CLEAR(p->__pyx_v_i);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6decode___pyx_scope_struct_6_genexpr < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr)))) {
    __pyx_freelist_6decode___pyx_scope_struct_6_genexpr[__pyx_freecount_6decode___pyx_scope_struct_6_genexpr++] = ((struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static int __pyx_tp_traverse_6decode___pyx_scope_struct_6_genexpr(PyObject *o, visitproc v, void *a) {
  int e;
  struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *p = (struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr *)o;
  if (p->__pyx_outer_scope) {
    e = (*v)(((PyObject *)p->__pyx_outer_scope), a); if (e) return e;
  }
  if (p->__pyx_v_i) {
    e = (*v)(p->__pyx_v_i, a); if (e) return e;
  }
  return 0;
}

static PyTypeObject __pyx_type_6decode___pyx_scope_struct_6_genexpr = {
  PyVarObject_HEAD_INIT(0, 0)
  "decode.__pyx_scope_struct_6_genexpr", 
  sizeof(struct __pyx_obj_6decode___pyx_scope_struct_6_genexpr), 
  0, 
  __pyx_tp_dealloc_6decode___pyx_scope_struct_6_genexpr, 
  #if PY_VERSION_HEX < 0x030800b4
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4
  0, 
  #endif
  0, 
  0, 
  #if PY_MAJOR_VERSION < 3
  0, 
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, 
  #endif
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER|Py_TPFLAGS_HAVE_GC, 
  0, 
  __pyx_tp_traverse_6decode___pyx_scope_struct_6_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  __pyx_tp_new_6decode___pyx_scope_struct_6_genexpr, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  0, 
  #if PY_VERSION_HEX >= 0x030400a1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, 
  #endif
  #if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
  0, 
  #endif
};

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); 
static int __pyx_pymod_exec_decode(PyObject* module); 
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_decode},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "decode",
    0, 
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, 
  #else
    -1, 
  #endif
    __pyx_methods ,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, 
  #else
    NULL, 
  #endif
    NULL, 
    NULL, 
    NULL 
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_u_0b, __pyx_k_0b, sizeof(__pyx_k_0b), 0, 1, 0, 0},
  {&__pyx_kp_u_0m, __pyx_k_0m, sizeof(__pyx_k_0m), 0, 1, 0, 0},
  {&__pyx_kp_u_0m_2, __pyx_k_0m_2, sizeof(__pyx_k_0m_2), 0, 1, 0, 0},
  {&__pyx_kp_u_1_31m, __pyx_k_1_31m, sizeof(__pyx_k_1_31m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_31mFailed_to_decode_the_file, __pyx_k_1_31mFailed_to_decode_the_file, sizeof(__pyx_k_1_31mFailed_to_decode_the_file), 0, 1, 0, 0},
  {&__pyx_kp_u_1_31mstopped_0m, __pyx_k_1_31mstopped_0m, sizeof(__pyx_k_1_31mstopped_0m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_32m, __pyx_k_1_32m, sizeof(__pyx_k_1_32m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_32mDONE_0m, __pyx_k_1_32mDONE_0m, sizeof(__pyx_k_1_32mDONE_0m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_32msize, __pyx_k_1_32msize, sizeof(__pyx_k_1_32msize), 0, 1, 0, 0},
  {&__pyx_kp_u_1_33mcan_t_show_the_code_becaus, __pyx_k_1_33mcan_t_show_the_code_becaus, sizeof(__pyx_k_1_33mcan_t_show_the_code_becaus), 0, 1, 0, 0},
  {&__pyx_n_u_A, __pyx_k_A, sizeof(__pyx_k_A), 0, 1, 0, 1},
  {&__pyx_n_s_ALGORITHOMS, __pyx_k_ALGORITHOMS, sizeof(__pyx_k_ALGORITHOMS), 0, 0, 1, 1},
  {&__pyx_n_u_B, __pyx_k_B, sizeof(__pyx_k_B), 0, 1, 0, 1},
  {&__pyx_n_u_C, __pyx_k_C, sizeof(__pyx_k_C), 0, 1, 0, 1},
  {&__pyx_n_s_CONFIG, __pyx_k_CONFIG, sizeof(__pyx_k_CONFIG), 0, 0, 1, 1},
  {&__pyx_n_s_COPYRIGHT, __pyx_k_COPYRIGHT, sizeof(__pyx_k_COPYRIGHT), 0, 0, 1, 1},
  {&__pyx_n_s_CodeSearchAlgorithms, __pyx_k_CodeSearchAlgorithms, sizeof(__pyx_k_CodeSearchAlgorithms), 0, 0, 1, 1},
  {&__pyx_n_s_CodeSearchAlgorithms_function, __pyx_k_CodeSearchAlgorithms_function, sizeof(__pyx_k_CodeSearchAlgorithms_function), 0, 0, 1, 1},
  {&__pyx_n_s_CodeSearchAlgorithms_object, __pyx_k_CodeSearchAlgorithms_object, sizeof(__pyx_k_CodeSearchAlgorithms_object), 0, 0, 1, 1},
  {&__pyx_n_s_CodeSearchAlgorithms_object_loca, __pyx_k_CodeSearchAlgorithms_object_loca, sizeof(__pyx_k_CodeSearchAlgorithms_object_loca), 0, 0, 1, 1},
  {&__pyx_n_s_CodeType, __pyx_k_CodeType, sizeof(__pyx_k_CodeType), 0, 0, 1, 1},
  {&__pyx_n_s_Config, __pyx_k_Config, sizeof(__pyx_k_Config), 0, 0, 1, 1},
  {&__pyx_n_s_Console, __pyx_k_Console, sizeof(__pyx_k_Console), 0, 0, 1, 1},
  {&__pyx_n_u_D, __pyx_k_D, sizeof(__pyx_k_D), 0, 1, 0, 1},
  {&__pyx_n_u_DEBUG, __pyx_k_DEBUG, sizeof(__pyx_k_DEBUG), 0, 1, 0, 1},
  {&__pyx_n_s_DEBUG_MODE, __pyx_k_DEBUG_MODE, sizeof(__pyx_k_DEBUG_MODE), 0, 0, 1, 1},
  {&__pyx_kp_u_Decoded_by_HackerMode_tool_Copy, __pyx_k_Decoded_by_HackerMode_tool_Copy, sizeof(__pyx_k_Decoded_by_HackerMode_tool_Copy), 0, 1, 0, 0},
  {&__pyx_n_s_DecodingAlgorithms, __pyx_k_DecodingAlgorithms, sizeof(__pyx_k_DecodingAlgorithms), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms___init, __pyx_k_DecodingAlgorithms___init, sizeof(__pyx_k_DecodingAlgorithms___init), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_abdullah_encr, __pyx_k_DecodingAlgorithms_abdullah_encr, sizeof(__pyx_k_DecodingAlgorithms_abdullah_encr), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_base16, __pyx_k_DecodingAlgorithms_base16, sizeof(__pyx_k_DecodingAlgorithms_base16), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_base32, __pyx_k_DecodingAlgorithms_base32, sizeof(__pyx_k_DecodingAlgorithms_base32), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_base64, __pyx_k_DecodingAlgorithms_base64, sizeof(__pyx_k_DecodingAlgorithms_base64), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_base85, __pyx_k_DecodingAlgorithms_base85, sizeof(__pyx_k_DecodingAlgorithms_base85), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_bytes_list, __pyx_k_DecodingAlgorithms_bytes_list, sizeof(__pyx_k_DecodingAlgorithms_bytes_list), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_bytes_list_lo, __pyx_k_DecodingAlgorithms_bytes_list_lo, sizeof(__pyx_k_DecodingAlgorithms_bytes_list_lo), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_codecs_bz2_co, __pyx_k_DecodingAlgorithms_codecs_bz2_co, sizeof(__pyx_k_DecodingAlgorithms_codecs_bz2_co), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_filter, __pyx_k_DecodingAlgorithms_eval_filter, sizeof(__pyx_k_DecodingAlgorithms_eval_filter), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_filter_l, __pyx_k_DecodingAlgorithms_eval_filter_l, sizeof(__pyx_k_DecodingAlgorithms_eval_filter_l), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function, __pyx_k_DecodingAlgorithms_eval_function, sizeof(__pyx_k_DecodingAlgorithms_eval_function), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_10, __pyx_k_DecodingAlgorithms_eval_function_10, sizeof(__pyx_k_DecodingAlgorithms_eval_function_10), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_2, __pyx_k_DecodingAlgorithms_eval_function_2, sizeof(__pyx_k_DecodingAlgorithms_eval_function_2), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_3, __pyx_k_DecodingAlgorithms_eval_function_3, sizeof(__pyx_k_DecodingAlgorithms_eval_function_3), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_4, __pyx_k_DecodingAlgorithms_eval_function_4, sizeof(__pyx_k_DecodingAlgorithms_eval_function_4), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_5, __pyx_k_DecodingAlgorithms_eval_function_5, sizeof(__pyx_k_DecodingAlgorithms_eval_function_5), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_6, __pyx_k_DecodingAlgorithms_eval_function_6, sizeof(__pyx_k_DecodingAlgorithms_eval_function_6), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_7, __pyx_k_DecodingAlgorithms_eval_function_7, sizeof(__pyx_k_DecodingAlgorithms_eval_function_7), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_8, __pyx_k_DecodingAlgorithms_eval_function_8, sizeof(__pyx_k_DecodingAlgorithms_eval_function_8), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_eval_function_9, __pyx_k_DecodingAlgorithms_eval_function_9, sizeof(__pyx_k_DecodingAlgorithms_eval_function_9), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function, __pyx_k_DecodingAlgorithms_exec_function, sizeof(__pyx_k_DecodingAlgorithms_exec_function), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_10, __pyx_k_DecodingAlgorithms_exec_function_10, sizeof(__pyx_k_DecodingAlgorithms_exec_function_10), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_2, __pyx_k_DecodingAlgorithms_exec_function_2, sizeof(__pyx_k_DecodingAlgorithms_exec_function_2), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_3, __pyx_k_DecodingAlgorithms_exec_function_3, sizeof(__pyx_k_DecodingAlgorithms_exec_function_3), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_4, __pyx_k_DecodingAlgorithms_exec_function_4, sizeof(__pyx_k_DecodingAlgorithms_exec_function_4), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_5, __pyx_k_DecodingAlgorithms_exec_function_5, sizeof(__pyx_k_DecodingAlgorithms_exec_function_5), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_6, __pyx_k_DecodingAlgorithms_exec_function_6, sizeof(__pyx_k_DecodingAlgorithms_exec_function_6), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_7, __pyx_k_DecodingAlgorithms_exec_function_7, sizeof(__pyx_k_DecodingAlgorithms_exec_function_7), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_8, __pyx_k_DecodingAlgorithms_exec_function_8, sizeof(__pyx_k_DecodingAlgorithms_exec_function_8), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_exec_function_9, __pyx_k_DecodingAlgorithms_exec_function_9, sizeof(__pyx_k_DecodingAlgorithms_exec_function_9), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_machine_code, __pyx_k_DecodingAlgorithms_machine_code, sizeof(__pyx_k_DecodingAlgorithms_machine_code), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_machine_code_2, __pyx_k_DecodingAlgorithms_machine_code_2, sizeof(__pyx_k_DecodingAlgorithms_machine_code_2), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_marshal, __pyx_k_DecodingAlgorithms_marshal, sizeof(__pyx_k_DecodingAlgorithms_marshal), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_math_sqrt, __pyx_k_DecodingAlgorithms_math_sqrt, sizeof(__pyx_k_DecodingAlgorithms_math_sqrt), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_zip_code, __pyx_k_DecodingAlgorithms_zip_code, sizeof(__pyx_k_DecodingAlgorithms_zip_code), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_zlib, __pyx_k_DecodingAlgorithms_zlib, sizeof(__pyx_k_DecodingAlgorithms_zlib), 0, 0, 1, 1},
  {&__pyx_n_s_DecodingAlgorithms_zlib_base64, __pyx_k_DecodingAlgorithms_zlib_base64, sizeof(__pyx_k_DecodingAlgorithms_zlib_base64), 0, 0, 1, 1},
  {&__pyx_n_u_E, __pyx_k_E, sizeof(__pyx_k_E), 0, 1, 0, 1},
  {&__pyx_n_s_ENCODEING, __pyx_k_ENCODEING, sizeof(__pyx_k_ENCODEING), 0, 0, 1, 1},
  {&__pyx_kp_u_ERROR, __pyx_k_ERROR, sizeof(__pyx_k_ERROR), 0, 1, 0, 0},
  {&__pyx_kp_u_ERROR_2, __pyx_k_ERROR_2, sizeof(__pyx_k_ERROR_2), 0, 1, 0, 0},
  {&__pyx_kp_u_ERROR_length, __pyx_k_ERROR_length, sizeof(__pyx_k_ERROR_length), 0, 1, 0, 0},
  {&__pyx_n_u_EXIT, __pyx_k_EXIT, sizeof(__pyx_k_EXIT), 0, 1, 0, 1},
  {&__pyx_kp_u_Exception_exceptions, __pyx_k_Exception_exceptions, sizeof(__pyx_k_Exception_exceptions), 0, 1, 0, 0},
  {&__pyx_n_u_F, __pyx_k_F, sizeof(__pyx_k_F), 0, 1, 0, 1},
  {&__pyx_kp_u_File_type, __pyx_k_File_type, sizeof(__pyx_k_File_type), 0, 1, 0, 0},
  {&__pyx_kp_u_Finding_the_best_algorithm, __pyx_k_Finding_the_best_algorithm, sizeof(__pyx_k_Finding_the_best_algorithm), 0, 1, 0, 0},
  {&__pyx_n_u_G, __pyx_k_G, sizeof(__pyx_k_G), 0, 1, 0, 1},
  {&__pyx_n_u_H, __pyx_k_H, sizeof(__pyx_k_H), 0, 1, 0, 1},
  {&__pyx_n_u_I, __pyx_k_I, sizeof(__pyx_k_I), 0, 1, 0, 1},
  {&__pyx_n_s_IndexError, __pyx_k_IndexError, sizeof(__pyx_k_IndexError), 0, 0, 1, 1},
  {&__pyx_n_u_J, __pyx_k_J, sizeof(__pyx_k_J), 0, 1, 0, 1},
  {&__pyx_n_u_K, __pyx_k_K, sizeof(__pyx_k_K), 0, 1, 0, 1},
  {&__pyx_n_s_KeyboardInterrupt, __pyx_k_KeyboardInterrupt, sizeof(__pyx_k_KeyboardInterrupt), 0, 0, 1, 1},
  {&__pyx_n_u_L, __pyx_k_L, sizeof(__pyx_k_L), 0, 1, 0, 1},
  {&__pyx_n_s_List, __pyx_k_List, sizeof(__pyx_k_List), 0, 0, 1, 1},
  {&__pyx_n_u_M, __pyx_k_M, sizeof(__pyx_k_M), 0, 1, 0, 1},
  {&__pyx_n_s_MAGIC_NUMBER, __pyx_k_MAGIC_NUMBER, sizeof(__pyx_k_MAGIC_NUMBER), 0, 0, 1, 1},
  {&__pyx_n_s_MAGIC_NUMBERS, __pyx_k_MAGIC_NUMBERS, sizeof(__pyx_k_MAGIC_NUMBERS), 0, 0, 1, 1},
  {&__pyx_n_u_N, __pyx_k_N, sizeof(__pyx_k_N), 0, 1, 0, 1},
  {&__pyx_n_u_O, __pyx_k_O, sizeof(__pyx_k_O), 0, 1, 0, 1},
  {&__pyx_n_s_OLD_COMPILE, __pyx_k_OLD_COMPILE, sizeof(__pyx_k_OLD_COMPILE), 0, 0, 1, 1},
  {&__pyx_n_s_OLD_EVAL, __pyx_k_OLD_EVAL, sizeof(__pyx_k_OLD_EVAL), 0, 0, 1, 1},
  {&__pyx_n_s_OLD_EXEC, __pyx_k_OLD_EXEC, sizeof(__pyx_k_OLD_EXEC), 0, 0, 1, 1},
  {&__pyx_n_u_P, __pyx_k_P, sizeof(__pyx_k_P), 0, 1, 0, 1},
  {&__pyx_kp_b_PK, __pyx_k_PK, sizeof(__pyx_k_PK), 0, 0, 0, 0},
  {&__pyx_n_s_PYTHON_VERSION, __pyx_k_PYTHON_VERSION, sizeof(__pyx_k_PYTHON_VERSION), 0, 0, 1, 1},
  {&__pyx_kp_u_Press_enter_to_continue_or_n_to, __pyx_k_Press_enter_to_continue_or_n_to, sizeof(__pyx_k_Press_enter_to_continue_or_n_to), 0, 1, 0, 0},
  {&__pyx_n_s_Process, __pyx_k_Process, sizeof(__pyx_k_Process), 0, 0, 1, 1},
  {&__pyx_n_u_Q, __pyx_k_Q, sizeof(__pyx_k_Q), 0, 1, 0, 1},
  {&__pyx_n_u_R, __pyx_k_R, sizeof(__pyx_k_R), 0, 1, 0, 1},
  {&__pyx_n_u_S, __pyx_k_S, sizeof(__pyx_k_S), 0, 1, 0, 1},
  {&__pyx_n_s_SIZE, __pyx_k_SIZE, sizeof(__pyx_k_SIZE), 0, 0, 1, 1},
  {&__pyx_n_s_Size, __pyx_k_Size, sizeof(__pyx_k_Size), 0, 0, 1, 1},
  {&__pyx_n_s_StringIO, __pyx_k_StringIO, sizeof(__pyx_k_StringIO), 0, 0, 1, 1},
  {&__pyx_n_s_Syntax, __pyx_k_Syntax, sizeof(__pyx_k_Syntax), 0, 0, 1, 1},
  {&__pyx_n_u_T, __pyx_k_T, sizeof(__pyx_k_T), 0, 1, 0, 1},
  {&__pyx_n_u_U, __pyx_k_U, sizeof(__pyx_k_U), 0, 1, 0, 1},
  {&__pyx_kp_u_USAGE_decode_file_py_output_py_d, __pyx_k_USAGE_decode_file_py_output_py_d, sizeof(__pyx_k_USAGE_decode_file_py_output_py_d), 0, 1, 0, 0},
  {&__pyx_kp_b_U_2, __pyx_k_U_2, sizeof(__pyx_k_U_2), 0, 0, 0, 0},
  {&__pyx_n_s_UnicodeDecodeError, __pyx_k_UnicodeDecodeError, sizeof(__pyx_k_UnicodeDecodeError), 0, 0, 1, 1},
  {&__pyx_n_u_V, __pyx_k_V, sizeof(__pyx_k_V), 0, 1, 0, 1},
  {&__pyx_n_u_VIRTUAL_ENV, __pyx_k_VIRTUAL_ENV, sizeof(__pyx_k_VIRTUAL_ENV), 0, 1, 0, 1},
  {&__pyx_n_u_W, __pyx_k_W, sizeof(__pyx_k_W), 0, 1, 0, 1},
  {&__pyx_n_u_X, __pyx_k_X, sizeof(__pyx_k_X), 0, 1, 0, 1},
  {&__pyx_n_u_Y, __pyx_k_Y, sizeof(__pyx_k_Y), 0, 1, 0, 1},
  {&__pyx_n_u_Z, __pyx_k_Z, sizeof(__pyx_k_Z), 0, 1, 0, 1},
  {&__pyx_n_s_ZIP_MAGIC_NUMBER, __pyx_k_ZIP_MAGIC_NUMBER, sizeof(__pyx_k_ZIP_MAGIC_NUMBER), 0, 0, 1, 1},
  {&__pyx_n_s_ZipFile, __pyx_k_ZipFile, sizeof(__pyx_k_ZipFile), 0, 0, 1, 1},
  {&__pyx_kp_u__109, __pyx_k__109, sizeof(__pyx_k__109), 0, 1, 0, 0},
  {&__pyx_kp_u__11, __pyx_k__11, sizeof(__pyx_k__11), 0, 1, 0, 0},
  {&__pyx_kp_u__110, __pyx_k__110, sizeof(__pyx_k__110), 0, 1, 0, 0},
  {&__pyx_kp_b__111, __pyx_k__111, sizeof(__pyx_k__111), 0, 0, 0, 0},
  {&__pyx_kp_u__12, __pyx_k__12, sizeof(__pyx_k__12), 0, 1, 0, 0},
  {&__pyx_kp_u__15, __pyx_k__15, sizeof(__pyx_k__15), 0, 1, 0, 0},
  {&__pyx_kp_u__18, __pyx_k__18, sizeof(__pyx_k__18), 0, 1, 0, 0},
  {&__pyx_kp_u__23, __pyx_k__23, sizeof(__pyx_k__23), 0, 1, 0, 0},
  {&__pyx_n_u__24, __pyx_k__24, sizeof(__pyx_k__24), 0, 1, 0, 1},
  {&__pyx_n_u__25, __pyx_k__25, sizeof(__pyx_k__25), 0, 1, 0, 1},
  {&__pyx_n_u__26, __pyx_k__26, sizeof(__pyx_k__26), 0, 1, 0, 1},
  {&__pyx_n_u__27, __pyx_k__27, sizeof(__pyx_k__27), 0, 1, 0, 1},
  {&__pyx_n_u__28, __pyx_k__28, sizeof(__pyx_k__28), 0, 1, 0, 1},
  {&__pyx_n_u__29, __pyx_k__29, sizeof(__pyx_k__29), 0, 1, 0, 1},
  {&__pyx_n_u__30, __pyx_k__30, sizeof(__pyx_k__30), 0, 1, 0, 1},
  {&__pyx_n_u__31, __pyx_k__31, sizeof(__pyx_k__31), 0, 1, 0, 1},
  {&__pyx_n_u__32, __pyx_k__32, sizeof(__pyx_k__32), 0, 1, 0, 1},
  {&__pyx_n_u__33, __pyx_k__33, sizeof(__pyx_k__33), 0, 1, 0, 1},
  {&__pyx_n_u__34, __pyx_k__34, sizeof(__pyx_k__34), 0, 1, 0, 1},
  {&__pyx_n_u__35, __pyx_k__35, sizeof(__pyx_k__35), 0, 1, 0, 1},
  {&__pyx_n_u__36, __pyx_k__36, sizeof(__pyx_k__36), 0, 1, 0, 1},
  {&__pyx_n_u__37, __pyx_k__37, sizeof(__pyx_k__37), 0, 1, 0, 1},
  {&__pyx_n_u__38, __pyx_k__38, sizeof(__pyx_k__38), 0, 1, 0, 1},
  {&__pyx_n_u__39, __pyx_k__39, sizeof(__pyx_k__39), 0, 1, 0, 1},
  {&__pyx_kp_u__4, __pyx_k__4, sizeof(__pyx_k__4), 0, 1, 0, 0},
  {&__pyx_n_u__40, __pyx_k__40, sizeof(__pyx_k__40), 0, 1, 0, 1},
  {&__pyx_n_u__41, __pyx_k__41, sizeof(__pyx_k__41), 0, 1, 0, 1},
  {&__pyx_n_u__42, __pyx_k__42, sizeof(__pyx_k__42), 0, 1, 0, 1},
  {&__pyx_n_u__43, __pyx_k__43, sizeof(__pyx_k__43), 0, 1, 0, 1},
  {&__pyx_n_u__44, __pyx_k__44, sizeof(__pyx_k__44), 0, 1, 0, 1},
  {&__pyx_n_u__45, __pyx_k__45, sizeof(__pyx_k__45), 0, 1, 0, 1},
  {&__pyx_n_u__46, __pyx_k__46, sizeof(__pyx_k__46), 0, 1, 0, 1},
  {&__pyx_n_u__47, __pyx_k__47, sizeof(__pyx_k__47), 0, 1, 0, 1},
  {&__pyx_n_u__48, __pyx_k__48, sizeof(__pyx_k__48), 0, 1, 0, 1},
  {&__pyx_n_u__49, __pyx_k__49, sizeof(__pyx_k__49), 0, 1, 0, 1},
  {&__pyx_kp_u__5, __pyx_k__5, sizeof(__pyx_k__5), 0, 1, 0, 0},
  {&__pyx_n_u__50, __pyx_k__50, sizeof(__pyx_k__50), 0, 1, 0, 1},
  {&__pyx_n_u__51, __pyx_k__51, sizeof(__pyx_k__51), 0, 1, 0, 1},
  {&__pyx_n_u__52, __pyx_k__52, sizeof(__pyx_k__52), 0, 1, 0, 1},
  {&__pyx_n_u__53, __pyx_k__53, sizeof(__pyx_k__53), 0, 1, 0, 1},
  {&__pyx_n_u__54, __pyx_k__54, sizeof(__pyx_k__54), 0, 1, 0, 1},
  {&__pyx_n_u__55, __pyx_k__55, sizeof(__pyx_k__55), 0, 1, 0, 1},
  {&__pyx_n_u__56, __pyx_k__56, sizeof(__pyx_k__56), 0, 1, 0, 1},
  {&__pyx_n_u__57, __pyx_k__57, sizeof(__pyx_k__57), 0, 1, 0, 1},
  {&__pyx_kp_u__58, __pyx_k__58, sizeof(__pyx_k__58), 0, 1, 0, 0},
  {&__pyx_n_u__59, __pyx_k__59, sizeof(__pyx_k__59), 0, 1, 0, 1},
  {&__pyx_n_u__60, __pyx_k__60, sizeof(__pyx_k__60), 0, 1, 0, 1},
  {&__pyx_n_u__61, __pyx_k__61, sizeof(__pyx_k__61), 0, 1, 0, 1},
  {&__pyx_n_u__62, __pyx_k__62, sizeof(__pyx_k__62), 0, 1, 0, 1},
  {&__pyx_n_u__63, __pyx_k__63, sizeof(__pyx_k__63), 0, 1, 0, 1},
  {&__pyx_n_u__64, __pyx_k__64, sizeof(__pyx_k__64), 0, 1, 0, 1},
  {&__pyx_n_u__65, __pyx_k__65, sizeof(__pyx_k__65), 0, 1, 0, 1},
  {&__pyx_n_u__66, __pyx_k__66, sizeof(__pyx_k__66), 0, 1, 0, 1},
  {&__pyx_n_u__67, __pyx_k__67, sizeof(__pyx_k__67), 0, 1, 0, 1},
  {&__pyx_n_u__68, __pyx_k__68, sizeof(__pyx_k__68), 0, 1, 0, 1},
  {&__pyx_n_u__69, __pyx_k__69, sizeof(__pyx_k__69), 0, 1, 0, 1},
  {&__pyx_n_u__70, __pyx_k__70, sizeof(__pyx_k__70), 0, 1, 0, 1},
  {&__pyx_n_u__71, __pyx_k__71, sizeof(__pyx_k__71), 0, 1, 0, 1},
  {&__pyx_n_u__72, __pyx_k__72, sizeof(__pyx_k__72), 0, 1, 0, 1},
  {&__pyx_n_u__73, __pyx_k__73, sizeof(__pyx_k__73), 0, 1, 0, 1},
  {&__pyx_n_u__74, __pyx_k__74, sizeof(__pyx_k__74), 0, 1, 0, 1},
  {&__pyx_n_u__75, __pyx_k__75, sizeof(__pyx_k__75), 0, 1, 0, 1},
  {&__pyx_kp_u__8, __pyx_k__8, sizeof(__pyx_k__8), 0, 1, 0, 0},
  {&__pyx_n_u__9, __pyx_k__9, sizeof(__pyx_k__9), 0, 1, 0, 1},
  {&__pyx_n_u_a, __pyx_k_a, sizeof(__pyx_k_a), 0, 1, 0, 1},
  {&__pyx_kp_b_a_2, __pyx_k_a_2, sizeof(__pyx_k_a_2), 0, 0, 0, 0},
  {&__pyx_kp_u_abdullah_encrypt, __pyx_k_abdullah_encrypt, sizeof(__pyx_k_abdullah_encrypt), 0, 1, 0, 0},
  {&__pyx_n_s_abdullah_encrypt_2, __pyx_k_abdullah_encrypt_2, sizeof(__pyx_k_abdullah_encrypt_2), 0, 0, 1, 1},
  {&__pyx_n_u_actions, __pyx_k_actions, sizeof(__pyx_k_actions), 0, 1, 0, 1},
  {&__pyx_n_s_algogithom, __pyx_k_algogithom, sizeof(__pyx_k_algogithom), 0, 0, 1, 1},
  {&__pyx_n_s_all_eval_functions, __pyx_k_all_eval_functions, sizeof(__pyx_k_all_eval_functions), 0, 0, 1, 1},
  {&__pyx_n_s_args, __pyx_k_args, sizeof(__pyx_k_args), 0, 0, 1, 1},
  {&__pyx_n_s_argv, __pyx_k_argv, sizeof(__pyx_k_argv), 0, 0, 1, 1},
  {&__pyx_n_u_b, __pyx_k_b, sizeof(__pyx_k_b), 0, 1, 0, 1},
  {&__pyx_n_s_b16decode, __pyx_k_b16decode, sizeof(__pyx_k_b16decode), 0, 0, 1, 1},
  {&__pyx_n_s_b32decode, __pyx_k_b32decode, sizeof(__pyx_k_b32decode), 0, 0, 1, 1},
  {&__pyx_n_s_b64decode, __pyx_k_b64decode, sizeof(__pyx_k_b64decode), 0, 0, 1, 1},
  {&__pyx_n_s_b85decode, __pyx_k_b85decode, sizeof(__pyx_k_b85decode), 0, 0, 1, 1},
  {&__pyx_n_s_bad_functions, __pyx_k_bad_functions, sizeof(__pyx_k_bad_functions), 0, 0, 1, 1},
  {&__pyx_n_s_base16, __pyx_k_base16, sizeof(__pyx_k_base16), 0, 0, 1, 1},
  {&__pyx_n_u_base16, __pyx_k_base16, sizeof(__pyx_k_base16), 0, 1, 0, 1},
  {&__pyx_n_s_base32, __pyx_k_base32, sizeof(__pyx_k_base32), 0, 0, 1, 1},
  {&__pyx_n_u_base32, __pyx_k_base32, sizeof(__pyx_k_base32), 0, 1, 0, 1},
  {&__pyx_n_s_base64, __pyx_k_base64, sizeof(__pyx_k_base64), 0, 0, 1, 1},
  {&__pyx_n_u_base64, __pyx_k_base64, sizeof(__pyx_k_base64), 0, 1, 0, 1},
  {&__pyx_n_s_base85, __pyx_k_base85, sizeof(__pyx_k_base85), 0, 0, 1, 1},
  {&__pyx_n_u_base85, __pyx_k_base85, sizeof(__pyx_k_base85), 0, 1, 0, 1},
  {&__pyx_n_s_bfile, __pyx_k_bfile, sizeof(__pyx_k_bfile), 0, 0, 1, 1},
  {&__pyx_n_s_builtins, __pyx_k_builtins, sizeof(__pyx_k_builtins), 0, 0, 1, 1},
  {&__pyx_n_u_builtins, __pyx_k_builtins, sizeof(__pyx_k_builtins), 0, 1, 0, 1},
  {&__pyx_n_s_builtins_2, __pyx_k_builtins_2, sizeof(__pyx_k_builtins_2), 0, 0, 1, 1},
  {&__pyx_n_s_bytecode, __pyx_k_bytecode, sizeof(__pyx_k_bytecode), 0, 0, 1, 1},
  {&__pyx_kp_u_bytes_list, __pyx_k_bytes_list, sizeof(__pyx_k_bytes_list), 0, 1, 0, 0},
  {&__pyx_n_s_bytes_list_2, __pyx_k_bytes_list_2, sizeof(__pyx_k_bytes_list_2), 0, 0, 1, 1},
  {&__pyx_n_u_bz2_codec, __pyx_k_bz2_codec, sizeof(__pyx_k_bz2_codec), 0, 1, 0, 1},
  {&__pyx_n_u_c, __pyx_k_c, sizeof(__pyx_k_c), 0, 1, 0, 1},
  {&__pyx_n_s_cast, __pyx_k_cast, sizeof(__pyx_k_cast), 0, 0, 1, 1},
  {&__pyx_n_s_char1, __pyx_k_char1, sizeof(__pyx_k_char1), 0, 0, 1, 1},
  {&__pyx_n_s_char2, __pyx_k_char2, sizeof(__pyx_k_char2), 0, 0, 1, 1},
  {&__pyx_n_s_chr, __pyx_k_chr, sizeof(__pyx_k_chr), 0, 0, 1, 1},
  {&__pyx_n_s_chr_2, __pyx_k_chr_2, sizeof(__pyx_k_chr_2), 0, 0, 1, 1},
  {&__pyx_n_u_clear, __pyx_k_clear, sizeof(__pyx_k_clear), 0, 1, 0, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_close, __pyx_k_close, sizeof(__pyx_k_close), 0, 0, 1, 1},
  {&__pyx_n_u_co_code, __pyx_k_co_code, sizeof(__pyx_k_co_code), 0, 1, 0, 1},
  {&__pyx_n_s_co_consts, __pyx_k_co_consts, sizeof(__pyx_k_co_consts), 0, 0, 1, 1},
  {&__pyx_n_u_co_consts, __pyx_k_co_consts, sizeof(__pyx_k_co_consts), 0, 1, 0, 1},
  {&__pyx_n_s_codecs, __pyx_k_codecs, sizeof(__pyx_k_codecs), 0, 0, 1, 1},
  {&__pyx_kp_u_codecs_bz2_codec, __pyx_k_codecs_bz2_codec, sizeof(__pyx_k_codecs_bz2_codec), 0, 1, 0, 0},
  {&__pyx_n_s_codecs_bz2_codec_2, __pyx_k_codecs_bz2_codec_2, sizeof(__pyx_k_codecs_bz2_codec_2), 0, 0, 1, 1},
  {&__pyx_n_s_codeobj, __pyx_k_codeobj, sizeof(__pyx_k_codeobj), 0, 0, 1, 1},
  {&__pyx_n_s_commands, __pyx_k_commands, sizeof(__pyx_k_commands), 0, 0, 1, 1},
  {&__pyx_n_s_compile, __pyx_k_compile, sizeof(__pyx_k_compile), 0, 0, 1, 1},
  {&__pyx_n_u_config, __pyx_k_config, sizeof(__pyx_k_config), 0, 1, 0, 1},
  {&__pyx_n_s_console, __pyx_k_console, sizeof(__pyx_k_console), 0, 0, 1, 1},
  {&__pyx_n_s_const, __pyx_k_const, sizeof(__pyx_k_const), 0, 0, 1, 1},
  {&__pyx_n_s_consts, __pyx_k_consts, sizeof(__pyx_k_consts), 0, 0, 1, 1},
  {&__pyx_n_s_consts_walker, __pyx_k_consts_walker, sizeof(__pyx_k_consts_walker), 0, 0, 1, 1},
  {&__pyx_n_s_content, __pyx_k_content, sizeof(__pyx_k_content), 0, 0, 1, 1},
  {&__pyx_n_s_copy, __pyx_k_copy, sizeof(__pyx_k_copy), 0, 0, 1, 1},
  {&__pyx_n_s_custom_data, __pyx_k_custom_data, sizeof(__pyx_k_custom_data), 0, 0, 1, 1},
  {&__pyx_n_s_custom_eval_data, __pyx_k_custom_eval_data, sizeof(__pyx_k_custom_eval_data), 0, 0, 1, 1},
  {&__pyx_n_u_d, __pyx_k_d, sizeof(__pyx_k_d), 0, 1, 0, 1},
  {&__pyx_n_s_data, __pyx_k_data, sizeof(__pyx_k_data), 0, 0, 1, 1},
  {&__pyx_kp_u_decode, __pyx_k_decode, sizeof(__pyx_k_decode), 0, 1, 0, 0},
  {&__pyx_kp_s_decode_2, __pyx_k_decode_2, sizeof(__pyx_k_decode_2), 0, 0, 1, 0},
  {&__pyx_n_s_decoding_algorithms, __pyx_k_decoding_algorithms, sizeof(__pyx_k_decoding_algorithms), 0, 0, 1, 1},
  {&__pyx_n_s_decompile, __pyx_k_decompile, sizeof(__pyx_k_decompile), 0, 0, 1, 1},
  {&__pyx_n_s_decompile_file, __pyx_k_decompile_file, sizeof(__pyx_k_decompile_file), 0, 0, 1, 1},
  {&__pyx_n_s_decompress, __pyx_k_decompress, sizeof(__pyx_k_decompress), 0, 0, 1, 1},
  {&__pyx_n_s_default, __pyx_k_default, sizeof(__pyx_k_default), 0, 0, 1, 1},
  {&__pyx_n_s_dict, __pyx_k_dict, sizeof(__pyx_k_dict), 0, 0, 1, 1},
  {&__pyx_n_u_dict_2, __pyx_k_dict_2, sizeof(__pyx_k_dict_2), 0, 1, 0, 1},
  {&__pyx_n_s_doc, __pyx_k_doc, sizeof(__pyx_k_doc), 0, 0, 1, 1},
  {&__pyx_n_s_e, __pyx_k_e, sizeof(__pyx_k_e), 0, 0, 1, 1},
  {&__pyx_n_u_e, __pyx_k_e, sizeof(__pyx_k_e), 0, 1, 0, 1},
  {&__pyx_kp_u_encoding, __pyx_k_encoding, sizeof(__pyx_k_encoding), 0, 1, 0, 0},
  {&__pyx_n_s_end, __pyx_k_end, sizeof(__pyx_k_end), 0, 0, 1, 1},
  {&__pyx_n_s_endswith, __pyx_k_endswith, sizeof(__pyx_k_endswith), 0, 0, 1, 1},
  {&__pyx_n_s_enter, __pyx_k_enter, sizeof(__pyx_k_enter), 0, 0, 1, 1},
  {&__pyx_n_s_enumerate, __pyx_k_enumerate, sizeof(__pyx_k_enumerate), 0, 0, 1, 1},
  {&__pyx_n_s_environ, __pyx_k_environ, sizeof(__pyx_k_environ), 0, 0, 1, 1},
  {&__pyx_n_s_err, __pyx_k_err, sizeof(__pyx_k_err), 0, 0, 1, 1},
  {&__pyx_n_s_eval, __pyx_k_eval, sizeof(__pyx_k_eval), 0, 0, 1, 1},
  {&__pyx_n_u_eval, __pyx_k_eval, sizeof(__pyx_k_eval), 0, 1, 0, 1},
  {&__pyx_n_s_eval_body, __pyx_k_eval_body, sizeof(__pyx_k_eval_body), 0, 0, 1, 1},
  {&__pyx_n_s_eval_data, __pyx_k_eval_data, sizeof(__pyx_k_eval_data), 0, 0, 1, 1},
  {&__pyx_n_s_eval_f, __pyx_k_eval_f, sizeof(__pyx_k_eval_f), 0, 0, 1, 1},
  {&__pyx_kp_u_eval_filter, __pyx_k_eval_filter, sizeof(__pyx_k_eval_filter), 0, 1, 0, 0},
  {&__pyx_n_s_eval_filter_2, __pyx_k_eval_filter_2, sizeof(__pyx_k_eval_filter_2), 0, 0, 1, 1},
  {&__pyx_kp_u_eval_function, __pyx_k_eval_function, sizeof(__pyx_k_eval_function), 0, 1, 0, 0},
  {&__pyx_n_s_eval_function_2, __pyx_k_eval_function_2, sizeof(__pyx_k_eval_function_2), 0, 0, 1, 1},
  {&__pyx_n_s_exceptions, __pyx_k_exceptions, sizeof(__pyx_k_exceptions), 0, 0, 1, 1},
  {&__pyx_n_s_exec, __pyx_k_exec, sizeof(__pyx_k_exec), 0, 0, 1, 1},
  {&__pyx_n_u_exec, __pyx_k_exec, sizeof(__pyx_k_exec), 0, 1, 0, 1},
  {&__pyx_kp_u_exec_function, __pyx_k_exec_function, sizeof(__pyx_k_exec_function), 0, 1, 0, 0},
  {&__pyx_n_s_exec_function_2, __pyx_k_exec_function_2, sizeof(__pyx_k_exec_function_2), 0, 0, 1, 1},
  {&__pyx_n_s_exit, __pyx_k_exit, sizeof(__pyx_k_exit), 0, 0, 1, 1},
  {&__pyx_n_s_exit_2, __pyx_k_exit_2, sizeof(__pyx_k_exit_2), 0, 0, 1, 1},
  {&__pyx_n_s_extract, __pyx_k_extract, sizeof(__pyx_k_extract), 0, 0, 1, 1},
  {&__pyx_n_s_f, __pyx_k_f, sizeof(__pyx_k_f), 0, 0, 1, 1},
  {&__pyx_n_u_f, __pyx_k_f, sizeof(__pyx_k_f), 0, 1, 0, 1},
  {&__pyx_n_s_file, __pyx_k_file, sizeof(__pyx_k_file), 0, 0, 1, 1},
  {&__pyx_n_s_file_data, __pyx_k_file_data, sizeof(__pyx_k_file_data), 0, 0, 1, 1},
  {&__pyx_n_s_file_name, __pyx_k_file_name, sizeof(__pyx_k_file_name), 0, 0, 1, 1},
  {&__pyx_kp_u_file_not_found, __pyx_k_file_not_found, sizeof(__pyx_k_file_not_found), 0, 1, 0, 0},
  {&__pyx_n_s_file_type, __pyx_k_file_type, sizeof(__pyx_k_file_type), 0, 0, 1, 1},
  {&__pyx_n_s_filename, __pyx_k_filename, sizeof(__pyx_k_filename), 0, 0, 1, 1},
  {&__pyx_n_u_filter, __pyx_k_filter, sizeof(__pyx_k_filter), 0, 1, 0, 1},
  {&__pyx_n_s_findall, __pyx_k_findall, sizeof(__pyx_k_findall), 0, 0, 1, 1},
  {&__pyx_n_s_func, __pyx_k_func, sizeof(__pyx_k_func), 0, 0, 1, 1},
  {&__pyx_n_s_func_pos, __pyx_k_func_pos, sizeof(__pyx_k_func_pos), 0, 0, 1, 1},
  {&__pyx_n_s_func_poss, __pyx_k_func_poss, sizeof(__pyx_k_func_poss), 0, 0, 1, 1},
  {&__pyx_n_s_function, __pyx_k_function, sizeof(__pyx_k_function), 0, 0, 1, 1},
  {&__pyx_n_s_function_body, __pyx_k_function_body, sizeof(__pyx_k_function_body), 0, 0, 1, 1},
  {&__pyx_n_s_function_name, __pyx_k_function_name, sizeof(__pyx_k_function_name), 0, 0, 1, 1},
  {&__pyx_n_u_g, __pyx_k_g, sizeof(__pyx_k_g), 0, 1, 0, 1},
  {&__pyx_n_s_genexpr, __pyx_k_genexpr, sizeof(__pyx_k_genexpr), 0, 0, 1, 1},
  {&__pyx_n_s_get, __pyx_k_get, sizeof(__pyx_k_get), 0, 0, 1, 1},
  {&__pyx_n_s_getattribute, __pyx_k_getattribute, sizeof(__pyx_k_getattribute), 0, 0, 1, 1},
  {&__pyx_n_s_getvalue, __pyx_k_getvalue, sizeof(__pyx_k_getvalue), 0, 0, 1, 1},
  {&__pyx_n_u_h, __pyx_k_h, sizeof(__pyx_k_h), 0, 1, 0, 1},
  {&__pyx_n_s_hash_type, __pyx_k_hash_type, sizeof(__pyx_k_hash_type), 0, 0, 1, 1},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_u_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 1, 0, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_importlib, __pyx_k_importlib, sizeof(__pyx_k_importlib), 0, 0, 1, 1},
  {&__pyx_n_s_in_source, __pyx_k_in_source, sizeof(__pyx_k_in_source), 0, 0, 1, 1},
  {&__pyx_n_s_index, __pyx_k_index, sizeof(__pyx_k_index), 0, 0, 1, 1},
  {&__pyx_n_s_infolist, __pyx_k_infolist, sizeof(__pyx_k_infolist), 0, 0, 1, 1},
  {&__pyx_n_s_init, __pyx_k_init, sizeof(__pyx_k_init), 0, 0, 1, 1},
  {&__pyx_n_s_input, __pyx_k_input, sizeof(__pyx_k_input), 0, 0, 1, 1},
  {&__pyx_n_s_insert, __pyx_k_insert, sizeof(__pyx_k_insert), 0, 0, 1, 1},
  {&__pyx_n_s_io, __pyx_k_io, sizeof(__pyx_k_io), 0, 0, 1, 1},
  {&__pyx_n_s_is_alive, __pyx_k_is_alive, sizeof(__pyx_k_is_alive), 0, 0, 1, 1},
  {&__pyx_n_s_is_in, __pyx_k_is_in, sizeof(__pyx_k_is_in), 0, 0, 1, 1},
  {&__pyx_n_s_isfile, __pyx_k_isfile, sizeof(__pyx_k_isfile), 0, 0, 1, 1},
  {&__pyx_n_s_items, __pyx_k_items, sizeof(__pyx_k_items), 0, 0, 1, 1},
  {&__pyx_n_u_j, __pyx_k_j, sizeof(__pyx_k_j), 0, 1, 0, 1},
  {&__pyx_n_s_join, __pyx_k_join, sizeof(__pyx_k_join), 0, 0, 1, 1},
  {&__pyx_n_u_k, __pyx_k_k, sizeof(__pyx_k_k), 0, 1, 0, 1},
  {&__pyx_n_s_keys, __pyx_k_keys, sizeof(__pyx_k_keys), 0, 0, 1, 1},
  {&__pyx_n_s_kill, __pyx_k_kill, sizeof(__pyx_k_kill), 0, 0, 1, 1},
  {&__pyx_n_u_l, __pyx_k_l, sizeof(__pyx_k_l), 0, 1, 0, 1},
  {&__pyx_kp_u_layers, __pyx_k_layers, sizeof(__pyx_k_layers), 0, 1, 0, 0},
  {&__pyx_n_s_layers_2, __pyx_k_layers_2, sizeof(__pyx_k_layers_2), 0, 0, 1, 1},
  {&__pyx_kp_u_len_all_eval_functions, __pyx_k_len_all_eval_functions, sizeof(__pyx_k_len_all_eval_functions), 0, 1, 0, 0},
  {&__pyx_kp_u_lib, __pyx_k_lib, sizeof(__pyx_k_lib), 0, 1, 0, 0},
  {&__pyx_n_s_loads, __pyx_k_loads, sizeof(__pyx_k_loads), 0, 0, 1, 1},
  {&__pyx_n_s_log, __pyx_k_log, sizeof(__pyx_k_log), 0, 0, 1, 1},
  {&__pyx_n_s_lower, __pyx_k_lower, sizeof(__pyx_k_lower), 0, 0, 1, 1},
  {&__pyx_n_s_lstrip, __pyx_k_lstrip, sizeof(__pyx_k_lstrip), 0, 0, 1, 1},
  {&__pyx_n_u_m, __pyx_k_m, sizeof(__pyx_k_m), 0, 1, 0, 1},
  {&__pyx_kp_u_machine_code, __pyx_k_machine_code, sizeof(__pyx_k_machine_code), 0, 1, 0, 0},
  {&__pyx_n_s_machine_code_2, __pyx_k_machine_code_2, sizeof(__pyx_k_machine_code_2), 0, 0, 1, 1},
  {&__pyx_kp_u_machine_code_py2, __pyx_k_machine_code_py2, sizeof(__pyx_k_machine_code_py2), 0, 1, 0, 0},
  {&__pyx_n_s_machine_code_py2_2, __pyx_k_machine_code_py2_2, sizeof(__pyx_k_machine_code_py2_2), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_u_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 1, 0, 1},
  {&__pyx_kp_u_main___py, __pyx_k_main___py, sizeof(__pyx_k_main___py), 0, 1, 0, 0},
  {&__pyx_n_s_marshal, __pyx_k_marshal, sizeof(__pyx_k_marshal), 0, 0, 1, 1},
  {&__pyx_n_u_marshal, __pyx_k_marshal, sizeof(__pyx_k_marshal), 0, 1, 0, 1},
  {&__pyx_n_s_math, __pyx_k_math, sizeof(__pyx_k_math), 0, 0, 1, 1},
  {&__pyx_kp_u_math_sqrt, __pyx_k_math_sqrt, sizeof(__pyx_k_math_sqrt), 0, 1, 0, 0},
  {&__pyx_n_s_math_sqrt_2, __pyx_k_math_sqrt_2, sizeof(__pyx_k_math_sqrt_2), 0, 0, 1, 1},
  {&__pyx_n_s_metaclass, __pyx_k_metaclass, sizeof(__pyx_k_metaclass), 0, 0, 1, 1},
  {&__pyx_n_s_module, __pyx_k_module, sizeof(__pyx_k_module), 0, 0, 1, 1},
  {&__pyx_n_s_modules, __pyx_k_modules, sizeof(__pyx_k_modules), 0, 0, 1, 1},
  {&__pyx_n_s_multiprocessing, __pyx_k_multiprocessing, sizeof(__pyx_k_multiprocessing), 0, 0, 1, 1},
  {&__pyx_n_u_n, __pyx_k_n, sizeof(__pyx_k_n), 0, 1, 0, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_u_o, __pyx_k_o, sizeof(__pyx_k_o), 0, 1, 0, 1},
  {&__pyx_n_s_object, __pyx_k_object, sizeof(__pyx_k_object), 0, 0, 1, 1},
  {&__pyx_n_s_object_type, __pyx_k_object_type, sizeof(__pyx_k_object_type), 0, 0, 1, 1},
  {&__pyx_n_s_open, __pyx_k_open, sizeof(__pyx_k_open), 0, 0, 1, 1},
  {&__pyx_n_s_open_brackets, __pyx_k_open_brackets, sizeof(__pyx_k_open_brackets), 0, 0, 1, 1},
  {&__pyx_n_s_os, __pyx_k_os, sizeof(__pyx_k_os), 0, 0, 1, 1},
  {&__pyx_n_s_out, __pyx_k_out, sizeof(__pyx_k_out), 0, 0, 1, 1},
  {&__pyx_n_s_output, __pyx_k_output, sizeof(__pyx_k_output), 0, 0, 1, 1},
  {&__pyx_n_s_outstream, __pyx_k_outstream, sizeof(__pyx_k_outstream), 0, 0, 1, 1},
  {&__pyx_n_s_p, __pyx_k_p, sizeof(__pyx_k_p), 0, 0, 1, 1},
  {&__pyx_n_u_p, __pyx_k_p, sizeof(__pyx_k_p), 0, 1, 0, 1},
  {&__pyx_n_s_path, __pyx_k_path, sizeof(__pyx_k_path), 0, 0, 1, 1},
  {&__pyx_n_s_pattern, __pyx_k_pattern, sizeof(__pyx_k_pattern), 0, 0, 1, 1},
  {&__pyx_n_s_prepare, __pyx_k_prepare, sizeof(__pyx_k_prepare), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_kp_u_psh_team, __pyx_k_psh_team, sizeof(__pyx_k_psh_team), 0, 1, 0, 0},
  {&__pyx_kp_u_psh_team_developer_mode_total_l, __pyx_k_psh_team_developer_mode_total_l, sizeof(__pyx_k_psh_team_developer_mode_total_l), 0, 1, 0, 0},
  {&__pyx_n_u_py, __pyx_k_py, sizeof(__pyx_k_py), 0, 1, 0, 1},
  {&__pyx_kp_u_pyc, __pyx_k_pyc, sizeof(__pyx_k_pyc), 0, 1, 0, 0},
  {&__pyx_n_u_pyc_2, __pyx_k_pyc_2, sizeof(__pyx_k_pyc_2), 0, 1, 0, 1},
  {&__pyx_n_u_python, __pyx_k_python, sizeof(__pyx_k_python), 0, 1, 0, 1},
  {&__pyx_n_u_q, __pyx_k_q, sizeof(__pyx_k_q), 0, 1, 0, 1},
  {&__pyx_n_s_qualname, __pyx_k_qualname, sizeof(__pyx_k_qualname), 0, 0, 1, 1},
  {&__pyx_n_u_r, __pyx_k_r, sizeof(__pyx_k_r), 0, 1, 0, 1},
  {&__pyx_n_u_rb, __pyx_k_rb, sizeof(__pyx_k_rb), 0, 1, 0, 1},
  {&__pyx_n_s_re, __pyx_k_re, sizeof(__pyx_k_re), 0, 0, 1, 1},
  {&__pyx_n_s_read, __pyx_k_read, sizeof(__pyx_k_read), 0, 0, 1, 1},
  {&__pyx_n_s_remove, __pyx_k_remove, sizeof(__pyx_k_remove), 0, 0, 1, 1},
  {&__pyx_n_s_replace, __pyx_k_replace, sizeof(__pyx_k_replace), 0, 0, 1, 1},
  {&__pyx_n_s_return, __pyx_k_return, sizeof(__pyx_k_return), 0, 0, 1, 1},
  {&__pyx_n_s_rich_console, __pyx_k_rich_console, sizeof(__pyx_k_rich_console), 0, 0, 1, 1},
  {&__pyx_n_s_rich_syntax, __pyx_k_rich_syntax, sizeof(__pyx_k_rich_syntax), 0, 0, 1, 1},
  {&__pyx_n_s_root_search, __pyx_k_root_search, sizeof(__pyx_k_root_search), 0, 0, 1, 1},
  {&__pyx_kp_u_s, __pyx_k_s, sizeof(__pyx_k_s), 0, 1, 0, 0},
  {&__pyx_n_u_s_2, __pyx_k_s_2, sizeof(__pyx_k_s_2), 0, 1, 0, 1},
  {&__pyx_n_s_save_file, __pyx_k_save_file, sizeof(__pyx_k_save_file), 0, 0, 1, 1},
  {&__pyx_n_s_self, __pyx_k_self, sizeof(__pyx_k_self), 0, 0, 1, 1},
  {&__pyx_n_s_send, __pyx_k_send, sizeof(__pyx_k_send), 0, 0, 1, 1},
  {&__pyx_n_s_show_code, __pyx_k_show_code, sizeof(__pyx_k_show_code), 0, 0, 1, 1},
  {&__pyx_n_s_show_file_size, __pyx_k_show_file_size, sizeof(__pyx_k_show_file_size), 0, 0, 1, 1},
  {&__pyx_n_s_showast, __pyx_k_showast, sizeof(__pyx_k_showast), 0, 0, 1, 1},
  {&__pyx_n_s_size, __pyx_k_size, sizeof(__pyx_k_size), 0, 0, 1, 1},
  {&__pyx_n_u_size, __pyx_k_size, sizeof(__pyx_k_size), 0, 1, 0, 1},
  {&__pyx_n_s_source, __pyx_k_source, sizeof(__pyx_k_source), 0, 0, 1, 1},
  {&__pyx_n_s_split, __pyx_k_split, sizeof(__pyx_k_split), 0, 0, 1, 1},
  {&__pyx_n_s_sqrt, __pyx_k_sqrt, sizeof(__pyx_k_sqrt), 0, 0, 1, 1},
  {&__pyx_n_s_start, __pyx_k_start, sizeof(__pyx_k_start), 0, 0, 1, 1},
  {&__pyx_n_s_staticmethod, __pyx_k_staticmethod, sizeof(__pyx_k_staticmethod), 0, 0, 1, 1},
  {&__pyx_n_s_store_length, __pyx_k_store_length, sizeof(__pyx_k_store_length), 0, 0, 1, 1},
  {&__pyx_n_s_string, __pyx_k_string, sizeof(__pyx_k_string), 0, 0, 1, 1},
  {&__pyx_n_u_string, __pyx_k_string, sizeof(__pyx_k_string), 0, 1, 0, 1},
  {&__pyx_n_s_strip, __pyx_k_strip, sizeof(__pyx_k_strip), 0, 0, 1, 1},
  {&__pyx_n_s_syntax, __pyx_k_syntax, sizeof(__pyx_k_syntax), 0, 0, 1, 1},
  {&__pyx_n_s_sys, __pyx_k_sys, sizeof(__pyx_k_sys), 0, 0, 1, 1},
  {&__pyx_n_s_system, __pyx_k_system, sizeof(__pyx_k_system), 0, 0, 1, 1},
  {&__pyx_n_u_t, __pyx_k_t, sizeof(__pyx_k_t), 0, 1, 0, 1},
  {&__pyx_n_s_target, __pyx_k_target, sizeof(__pyx_k_target), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_u_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 1, 0, 1},
  {&__pyx_n_s_throw, __pyx_k_throw, sizeof(__pyx_k_throw), 0, 0, 1, 1},
  {&__pyx_n_s_to_string, __pyx_k_to_string, sizeof(__pyx_k_to_string), 0, 0, 1, 1},
  {&__pyx_kp_u_tools_decode, __pyx_k_tools_decode, sizeof(__pyx_k_tools_decode), 0, 1, 0, 0},
  {&__pyx_n_s_total_layers, __pyx_k_total_layers, sizeof(__pyx_k_total_layers), 0, 0, 1, 1},
  {&__pyx_n_s_types, __pyx_k_types, sizeof(__pyx_k_types), 0, 0, 1, 1},
  {&__pyx_n_s_typing, __pyx_k_typing, sizeof(__pyx_k_typing), 0, 0, 1, 1},
  {&__pyx_n_u_u, __pyx_k_u, sizeof(__pyx_k_u), 0, 1, 0, 1},
  {&__pyx_n_s_uncompyle6, __pyx_k_uncompyle6, sizeof(__pyx_k_uncompyle6), 0, 0, 1, 1},
  {&__pyx_n_s_uncompyle6_main, __pyx_k_uncompyle6_main, sizeof(__pyx_k_uncompyle6_main), 0, 0, 1, 1},
  {&__pyx_n_u_unicode, __pyx_k_unicode, sizeof(__pyx_k_unicode), 0, 1, 0, 1},
  {&__pyx_kp_u_utf_8, __pyx_k_utf_8, sizeof(__pyx_k_utf_8), 0, 1, 0, 0},
  {&__pyx_n_s_util, __pyx_k_util, sizeof(__pyx_k_util), 0, 0, 1, 1},
  {&__pyx_n_u_v, __pyx_k_v, sizeof(__pyx_k_v), 0, 1, 0, 1},
  {&__pyx_n_s_version, __pyx_k_version, sizeof(__pyx_k_version), 0, 0, 1, 1},
  {&__pyx_n_u_w, __pyx_k_w, sizeof(__pyx_k_w), 0, 1, 0, 1},
  {&__pyx_n_u_wb, __pyx_k_wb, sizeof(__pyx_k_wb), 0, 1, 0, 1},
  {&__pyx_n_s_write, __pyx_k_write, sizeof(__pyx_k_write), 0, 0, 1, 1},
  {&__pyx_n_u_x, __pyx_k_x, sizeof(__pyx_k_x), 0, 1, 0, 1},
  {&__pyx_n_u_y, __pyx_k_y, sizeof(__pyx_k_y), 0, 1, 0, 1},
  {&__pyx_n_u_z, __pyx_k_z, sizeof(__pyx_k_z), 0, 1, 0, 1},
  {&__pyx_n_u_zip, __pyx_k_zip, sizeof(__pyx_k_zip), 0, 1, 0, 1},
  {&__pyx_kp_u_zip_code, __pyx_k_zip_code, sizeof(__pyx_k_zip_code), 0, 1, 0, 0},
  {&__pyx_n_s_zip_code_2, __pyx_k_zip_code_2, sizeof(__pyx_k_zip_code_2), 0, 0, 1, 1},
  {&__pyx_n_s_zip_ref, __pyx_k_zip_ref, sizeof(__pyx_k_zip_ref), 0, 0, 1, 1},
  {&__pyx_n_s_zipfile, __pyx_k_zipfile, sizeof(__pyx_k_zipfile), 0, 0, 1, 1},
  {&__pyx_n_s_zlib, __pyx_k_zlib, sizeof(__pyx_k_zlib), 0, 0, 1, 1},
  {&__pyx_n_u_zlib, __pyx_k_zlib, sizeof(__pyx_k_zlib), 0, 1, 0, 1},
  {&__pyx_kp_u_zlib_base64, __pyx_k_zlib_base64, sizeof(__pyx_k_zlib_base64), 0, 1, 0, 0},
  {&__pyx_n_s_zlib_base64_2, __pyx_k_zlib_base64_2, sizeof(__pyx_k_zlib_base64_2), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin___import__ = __Pyx_GetBuiltinName(__pyx_n_s_import); if (!__pyx_builtin___import__) __PYX_ERR(0, 39, __pyx_L1_error)
  __pyx_builtin_eval = __Pyx_GetBuiltinName(__pyx_n_s_eval); if (!__pyx_builtin_eval) __PYX_ERR(0, 42, __pyx_L1_error)
  __pyx_builtin_compile = __Pyx_GetBuiltinName(__pyx_n_s_compile); if (!__pyx_builtin_compile) __PYX_ERR(0, 43, __pyx_L1_error)
  __pyx_builtin_staticmethod = __Pyx_GetBuiltinName(__pyx_n_s_staticmethod); if (!__pyx_builtin_staticmethod) __PYX_ERR(0, 71, __pyx_L1_error)
  __pyx_builtin_print = __Pyx_GetBuiltinName(__pyx_n_s_print); if (!__pyx_builtin_print) __PYX_ERR(0, 569, __pyx_L1_error)
  __pyx_builtin_KeyboardInterrupt = __Pyx_GetBuiltinName(__pyx_n_s_KeyboardInterrupt); if (!__pyx_builtin_KeyboardInterrupt) __PYX_ERR(0, 578, __pyx_L1_error)
  __pyx_builtin_input = __Pyx_GetBuiltinName(__pyx_n_s_input); if (!__pyx_builtin_input) __PYX_ERR(0, 595, __pyx_L1_error)
  __pyx_builtin_enumerate = __Pyx_GetBuiltinName(__pyx_n_s_enumerate); if (!__pyx_builtin_enumerate) __PYX_ERR(0, 77, __pyx_L1_error)
  __pyx_builtin_open = __Pyx_GetBuiltinName(__pyx_n_s_open); if (!__pyx_builtin_open) __PYX_ERR(0, 156, __pyx_L1_error)
  __pyx_builtin_IndexError = __Pyx_GetBuiltinName(__pyx_n_s_IndexError); if (!__pyx_builtin_IndexError) __PYX_ERR(0, 183, __pyx_L1_error)
  __pyx_builtin_chr = __Pyx_GetBuiltinName(__pyx_n_s_chr); if (!__pyx_builtin_chr) __PYX_ERR(0, 489, __pyx_L1_error)
  __pyx_builtin_exit = __Pyx_GetBuiltinName(__pyx_n_s_exit); if (!__pyx_builtin_exit) __PYX_ERR(0, 526, __pyx_L1_error)
  __pyx_builtin_UnicodeDecodeError = __Pyx_GetBuiltinName(__pyx_n_s_UnicodeDecodeError); if (!__pyx_builtin_UnicodeDecodeError) __PYX_ERR(0, 544, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  
  __pyx_tuple_ = PyTuple_Pack(3, __pyx_n_s_consts, __pyx_n_s_index, __pyx_n_s_const); if (unlikely(!__pyx_tuple_)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple_);
  __Pyx_GIVEREF(__pyx_tuple_);
  __pyx_codeobj__2 = (PyObject*)__Pyx_PyCode_New(1, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple_, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_consts_walker, 76, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__2)) __PYX_ERR(0, 76, __pyx_L1_error)

  
  __pyx_tuple__6 = PyTuple_Pack(2, __pyx_n_u_actions, __pyx_n_u_DEBUG); if (unlikely(!__pyx_tuple__6)) __PYX_ERR(0, 114, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__6);
  __Pyx_GIVEREF(__pyx_tuple__6);

  
  __pyx_tuple__7 = PyTuple_Pack(1, __pyx_kp_u_Finding_the_best_algorithm); if (unlikely(!__pyx_tuple__7)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__7);
  __Pyx_GIVEREF(__pyx_tuple__7);

  
  __pyx_tuple__10 = PyTuple_Pack(2, __pyx_kp_u__8, __pyx_n_u__9); if (unlikely(!__pyx_tuple__10)) __PYX_ERR(0, 120, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__10);
  __Pyx_GIVEREF(__pyx_tuple__10);

  
  __pyx_tuple__13 = PyTuple_Pack(1, __pyx_kp_u__12); if (unlikely(!__pyx_tuple__13)) __PYX_ERR(0, 139, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__13);
  __Pyx_GIVEREF(__pyx_tuple__13);

  
  __pyx_tuple__14 = PyTuple_Pack(1, __pyx_kp_u_1_32mDONE_0m); if (unlikely(!__pyx_tuple__14)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__14);
  __Pyx_GIVEREF(__pyx_tuple__14);

  
  __pyx_tuple__16 = PyTuple_Pack(3, Py_None, Py_None, Py_None); if (unlikely(!__pyx_tuple__16)) __PYX_ERR(0, 156, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__16);
  __Pyx_GIVEREF(__pyx_tuple__16);

  
  __pyx_tuple__17 = PyTuple_Pack(1, __pyx_kp_u_1_31mFailed_to_decode_the_file); if (unlikely(!__pyx_tuple__17)) __PYX_ERR(0, 162, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__17);
  __Pyx_GIVEREF(__pyx_tuple__17);

  
  __pyx_tuple__19 = PyTuple_Pack(9, __pyx_n_s_all_eval_functions, __pyx_n_s_func, __pyx_n_s_exceptions, __pyx_n_s_eval_f, __pyx_n_s_eval_body, __pyx_n_s_bad_functions, __pyx_n_s_is_in, __pyx_n_s_function, __pyx_n_s_eval_data); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 165, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);
  __pyx_codeobj__20 = (PyObject*)__Pyx_PyCode_New(1, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__19, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_root_search, 165, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__20)) __PYX_ERR(0, 165, __pyx_L1_error)

  
  __pyx_slice__21 = PySlice_New(__pyx_int_4, Py_None, Py_None); if (unlikely(!__pyx_slice__21)) __PYX_ERR(0, 249, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__21);
  __Pyx_GIVEREF(__pyx_slice__21);

  
  __pyx_slice__22 = PySlice_New(__pyx_int_16, Py_None, Py_None); if (unlikely(!__pyx_slice__22)) __PYX_ERR(0, 252, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__22);
  __Pyx_GIVEREF(__pyx_slice__22);

  
  __pyx_tuple__76 = PyTuple_Pack(3, __pyx_n_s_args, __pyx_n_s_bytecode, __pyx_n_s_commands); if (unlikely(!__pyx_tuple__76)) __PYX_ERR(0, 363, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__76);
  __Pyx_GIVEREF(__pyx_tuple__76);
  __pyx_codeobj__77 = (PyObject*)__Pyx_PyCode_New(0, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__76, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exec, 363, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__77)) __PYX_ERR(0, 363, __pyx_L1_error)

  
  __pyx_tuple__78 = PyTuple_Pack(2, __pyx_n_s_args, __pyx_n_s_data); if (unlikely(!__pyx_tuple__78)) __PYX_ERR(0, 379, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__78);
  __Pyx_GIVEREF(__pyx_tuple__78);
  __pyx_codeobj__79 = (PyObject*)__Pyx_PyCode_New(0, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__78, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_compile, 379, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__79)) __PYX_ERR(0, 379, __pyx_L1_error)

  
  __pyx_tuple__80 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__80)) __PYX_ERR(0, 385, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__80);
  __Pyx_GIVEREF(__pyx_tuple__80);
  __pyx_codeobj__81 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__80, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_print, 385, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__81)) __PYX_ERR(0, 385, __pyx_L1_error)

  
  __pyx_tuple__82 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__82)) __PYX_ERR(0, 388, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__82);
  __Pyx_GIVEREF(__pyx_tuple__82);
  __pyx_codeobj__83 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__82, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_input, 388, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__83)) __PYX_ERR(0, 388, __pyx_L1_error)

  
  __pyx_tuple__84 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__84)) __PYX_ERR(0, 391, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__84);
  __Pyx_GIVEREF(__pyx_tuple__84);
  __pyx_codeobj__85 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__84, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exit, 391, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__85)) __PYX_ERR(0, 391, __pyx_L1_error)

  
  __pyx_tuple__86 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__86)) __PYX_ERR(0, 395, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__86);
  __Pyx_GIVEREF(__pyx_tuple__86);
  __pyx_codeobj__87 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__86, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exec, 395, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__87)) __PYX_ERR(0, 395, __pyx_L1_error)

  
  __pyx_tuple__88 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__88)) __PYX_ERR(0, 398, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__88);
  __Pyx_GIVEREF(__pyx_tuple__88);
  __pyx_codeobj__89 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__88, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_compile, 398, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__89)) __PYX_ERR(0, 398, __pyx_L1_error)

  
  __pyx_tuple__90 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__90)) __PYX_ERR(0, 401, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__90);
  __Pyx_GIVEREF(__pyx_tuple__90);
  __pyx_codeobj__91 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__90, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exit, 401, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__91)) __PYX_ERR(0, 401, __pyx_L1_error)

  
  __pyx_tuple__92 = PyTuple_Pack(3, __pyx_n_s_args, __pyx_n_s_bytecode, __pyx_n_s_commands); if (unlikely(!__pyx_tuple__92)) __PYX_ERR(0, 424, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__92);
  __Pyx_GIVEREF(__pyx_tuple__92);
  __pyx_codeobj__93 = (PyObject*)__Pyx_PyCode_New(0, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__92, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_eval, 424, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__93)) __PYX_ERR(0, 424, __pyx_L1_error)

  
  __pyx_tuple__94 = PyTuple_Pack(2, __pyx_n_s_args, __pyx_n_s_data); if (unlikely(!__pyx_tuple__94)) __PYX_ERR(0, 440, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__94);
  __Pyx_GIVEREF(__pyx_tuple__94);
  __pyx_codeobj__95 = (PyObject*)__Pyx_PyCode_New(0, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__94, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_compile, 440, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__95)) __PYX_ERR(0, 440, __pyx_L1_error)

  
  __pyx_tuple__96 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__96)) __PYX_ERR(0, 446, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__96);
  __Pyx_GIVEREF(__pyx_tuple__96);
  __pyx_codeobj__97 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__96, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_print, 446, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__97)) __PYX_ERR(0, 446, __pyx_L1_error)

  
  __pyx_tuple__98 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__98)) __PYX_ERR(0, 449, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__98);
  __Pyx_GIVEREF(__pyx_tuple__98);
  __pyx_codeobj__99 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__98, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_input, 449, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__99)) __PYX_ERR(0, 449, __pyx_L1_error)

  
  __pyx_tuple__100 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__100)) __PYX_ERR(0, 452, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__100);
  __Pyx_GIVEREF(__pyx_tuple__100);
  __pyx_codeobj__101 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__100, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exit, 452, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__101)) __PYX_ERR(0, 452, __pyx_L1_error)

  
  __pyx_tuple__102 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__102)) __PYX_ERR(0, 456, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__102);
  __Pyx_GIVEREF(__pyx_tuple__102);
  __pyx_codeobj__103 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__102, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exec, 456, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__103)) __PYX_ERR(0, 456, __pyx_L1_error)

  
  __pyx_tuple__104 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__104)) __PYX_ERR(0, 459, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__104);
  __Pyx_GIVEREF(__pyx_tuple__104);
  __pyx_codeobj__105 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__104, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_compile, 459, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__105)) __PYX_ERR(0, 459, __pyx_L1_error)

  
  __pyx_tuple__106 = PyTuple_Pack(1, __pyx_n_s_args); if (unlikely(!__pyx_tuple__106)) __PYX_ERR(0, 462, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__106);
  __Pyx_GIVEREF(__pyx_tuple__106);
  __pyx_codeobj__107 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS|CO_VARARGS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__106, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exit, 462, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__107)) __PYX_ERR(0, 462, __pyx_L1_error)

  
  __pyx_slice__108 = PySlice_New(Py_None, __pyx_int_4, Py_None); if (unlikely(!__pyx_slice__108)) __PYX_ERR(0, 531, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__108);
  __Pyx_GIVEREF(__pyx_slice__108);

  
  __pyx_tuple__112 = PyTuple_Pack(1, __pyx_n_u_config); if (unlikely(!__pyx_tuple__112)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__112);
  __Pyx_GIVEREF(__pyx_tuple__112);

  
  __pyx_tuple__113 = PyTuple_Pack(6, __pyx_n_s_string, __pyx_n_s_object_type, __pyx_n_s_codeobj, __pyx_n_s_store_length, __pyx_n_s_consts_walker, __pyx_n_s_consts_walker); if (unlikely(!__pyx_tuple__113)) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__113);
  __Pyx_GIVEREF(__pyx_tuple__113);
  __pyx_codeobj__114 = (PyObject*)__Pyx_PyCode_New(2, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__113, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_object, 72, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__114)) __PYX_ERR(0, 72, __pyx_L1_error)

  
  __pyx_tuple__115 = PyTuple_Pack(8, __pyx_n_s_string, __pyx_n_s_function_name, __pyx_n_s_pattern, __pyx_n_s_func_poss, __pyx_n_s_func_pos, __pyx_n_s_function_body, __pyx_n_s_open_brackets, __pyx_n_s_chr_2); if (unlikely(!__pyx_tuple__115)) __PYX_ERR(0, 87, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__115);
  __Pyx_GIVEREF(__pyx_tuple__115);
  __pyx_codeobj__3 = (PyObject*)__Pyx_PyCode_New(2, 0, 8, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__115, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_function, 87, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__3)) __PYX_ERR(0, 87, __pyx_L1_error)

  
  __pyx_tuple__116 = PyTuple_Pack(9, __pyx_n_s_self, __pyx_n_s_file_data, __pyx_n_s_save_file, __pyx_n_s_hash_type, __pyx_n_s_algogithom, __pyx_n_s_err, __pyx_n_s_layers_2, __pyx_n_s_file, __pyx_n_s_e); if (unlikely(!__pyx_tuple__116)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__116);
  __Pyx_GIVEREF(__pyx_tuple__116);
  __pyx_codeobj__117 = (PyObject*)__Pyx_PyCode_New(4, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__116, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_init, 108, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__117)) __PYX_ERR(0, 108, __pyx_L1_error)

  
  __pyx_tuple__118 = PyTuple_Pack(3, __pyx_n_s_self, __pyx_n_s_root_search, __pyx_n_s_root_search); if (unlikely(!__pyx_tuple__118)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__118);
  __Pyx_GIVEREF(__pyx_tuple__118);
  __pyx_codeobj__119 = (PyObject*)__Pyx_PyCode_New(1, 0, 3, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__118, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_eval_filter_2, 164, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__119)) __PYX_ERR(0, 164, __pyx_L1_error)

  
  __pyx_tuple__120 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__120)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__120);
  __Pyx_GIVEREF(__pyx_tuple__120);
  __pyx_codeobj__121 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__120, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_zlib, 201, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__121)) __PYX_ERR(0, 201, __pyx_L1_error)

  
  __pyx_tuple__122 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__122)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__122);
  __Pyx_GIVEREF(__pyx_tuple__122);
  __pyx_codeobj__123 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__122, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_zlib_base64_2, 206, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__123)) __PYX_ERR(0, 206, __pyx_L1_error)

  
  __pyx_tuple__124 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__124)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__124);
  __Pyx_GIVEREF(__pyx_tuple__124);
  __pyx_codeobj__125 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__124, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_codecs_bz2_codec_2, 213, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__125)) __PYX_ERR(0, 213, __pyx_L1_error)

  
  __pyx_tuple__126 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__126)) __PYX_ERR(0, 219, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__126);
  __Pyx_GIVEREF(__pyx_tuple__126);
  __pyx_codeobj__127 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__126, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_base16, 219, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__127)) __PYX_ERR(0, 219, __pyx_L1_error)

  
  __pyx_tuple__128 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__128)) __PYX_ERR(0, 224, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__128);
  __Pyx_GIVEREF(__pyx_tuple__128);
  __pyx_codeobj__129 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__128, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_base32, 224, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__129)) __PYX_ERR(0, 224, __pyx_L1_error)

  
  __pyx_tuple__130 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__130)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__130);
  __Pyx_GIVEREF(__pyx_tuple__130);
  __pyx_codeobj__131 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__130, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_base64, 229, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__131)) __PYX_ERR(0, 229, __pyx_L1_error)

  
  __pyx_tuple__132 = PyTuple_Pack(1, __pyx_n_s_self); if (unlikely(!__pyx_tuple__132)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__132);
  __Pyx_GIVEREF(__pyx_tuple__132);
  __pyx_codeobj__133 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__132, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_base85, 239, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__133)) __PYX_ERR(0, 239, __pyx_L1_error)

  
  __pyx_tuple__134 = PyTuple_Pack(4, __pyx_n_s_self, __pyx_n_s_bytecode, __pyx_n_s_out, __pyx_n_s_version); if (unlikely(!__pyx_tuple__134)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__134);
  __Pyx_GIVEREF(__pyx_tuple__134);
  __pyx_codeobj__135 = (PyObject*)__Pyx_PyCode_New(1, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__134, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_marshal, 244, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__135)) __PYX_ERR(0, 244, __pyx_L1_error)

  
  __pyx_tuple__136 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_bytecode, __pyx_n_s_out, __pyx_n_s_version, __pyx_n_s_data); if (unlikely(!__pyx_tuple__136)) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__136);
  __Pyx_GIVEREF(__pyx_tuple__136);
  __pyx_codeobj__137 = (PyObject*)__Pyx_PyCode_New(1, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__136, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_machine_code_2, 251, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__137)) __PYX_ERR(0, 251, __pyx_L1_error)

  
  __pyx_tuple__138 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_file_name, __pyx_n_s_file, __pyx_n_s_out, __pyx_n_s_err); if (unlikely(!__pyx_tuple__138)) __PYX_ERR(0, 261, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__138);
  __Pyx_GIVEREF(__pyx_tuple__138);
  __pyx_codeobj__139 = (PyObject*)__Pyx_PyCode_New(1, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__138, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_machine_code_py2_2, 261, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__139)) __PYX_ERR(0, 261, __pyx_L1_error)

  
  __pyx_tuple__140 = PyTuple_Pack(5, __pyx_n_s_self, __pyx_n_s_zip_ref, __pyx_n_s_file, __pyx_n_s_f, __pyx_n_s_output); if (unlikely(!__pyx_tuple__140)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__140);
  __Pyx_GIVEREF(__pyx_tuple__140);
  __pyx_codeobj__141 = (PyObject*)__Pyx_PyCode_New(1, 0, 5, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__140, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_zip_code_2, 276, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__141)) __PYX_ERR(0, 276, __pyx_L1_error)

  
  __pyx_tuple__142 = PyTuple_Pack(9, __pyx_n_s_self, __pyx_n_s_bytecode, __pyx_n_s_data, __pyx_n_s_const, __pyx_n_s_in_source, __pyx_n_s_source, __pyx_n_s_char1, __pyx_n_s_char2, __pyx_n_s_err); if (unlikely(!__pyx_tuple__142)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__142);
  __Pyx_GIVEREF(__pyx_tuple__142);
  __pyx_codeobj__143 = (PyObject*)__Pyx_PyCode_New(1, 0, 9, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__142, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_abdullah_encrypt_2, 287, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__143)) __PYX_ERR(0, 287, __pyx_L1_error)

  
  __pyx_tuple__144 = PyTuple_Pack(16, __pyx_n_s_self, __pyx_n_s_exec, __pyx_n_s_exec, __pyx_n_s_compile, __pyx_n_s_compile, __pyx_n_s_print, __pyx_n_s_print, __pyx_n_s_input, __pyx_n_s_input, __pyx_n_s_exit, __pyx_n_s_exit, __pyx_n_s_builtins, __pyx_n_s_err, __pyx_n_s_bytecode, __pyx_n_s_out, __pyx_n_s_version); if (unlikely(!__pyx_tuple__144)) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__144);
  __Pyx_GIVEREF(__pyx_tuple__144);
  __pyx_codeobj__145 = (PyObject*)__Pyx_PyCode_New(1, 0, 16, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__144, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_exec_function_2, 362, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__145)) __PYX_ERR(0, 362, __pyx_L1_error)

  
  __pyx_tuple__146 = PyTuple_Pack(16, __pyx_n_s_self, __pyx_n_s_eval, __pyx_n_s_eval, __pyx_n_s_compile, __pyx_n_s_compile, __pyx_n_s_print, __pyx_n_s_print, __pyx_n_s_input, __pyx_n_s_input, __pyx_n_s_exit, __pyx_n_s_exit, __pyx_n_s_builtins, __pyx_n_s_err, __pyx_n_s_bytecode, __pyx_n_s_out, __pyx_n_s_version); if (unlikely(!__pyx_tuple__146)) __PYX_ERR(0, 423, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__146);
  __Pyx_GIVEREF(__pyx_tuple__146);
  __pyx_codeobj__147 = (PyObject*)__Pyx_PyCode_New(1, 0, 16, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__146, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_eval_function_2, 423, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__147)) __PYX_ERR(0, 423, __pyx_L1_error)

  
  __pyx_tuple__148 = PyTuple_Pack(7, __pyx_n_s_self, __pyx_n_s_bytecode, __pyx_n_s_const, __pyx_n_s_source, __pyx_n_s_err, __pyx_n_s_genexpr, __pyx_n_s_genexpr); if (unlikely(!__pyx_tuple__148)) __PYX_ERR(0, 484, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__148);
  __Pyx_GIVEREF(__pyx_tuple__148);
  __pyx_codeobj__149 = (PyObject*)__Pyx_PyCode_New(1, 0, 7, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__148, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_bytes_list_2, 484, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__149)) __PYX_ERR(0, 484, __pyx_L1_error)

  
  __pyx_tuple__150 = PyTuple_Pack(6, __pyx_n_s_self, __pyx_n_s_bytecode, __pyx_n_s_const, __pyx_n_s_source, __pyx_n_s_err, __pyx_n_s_i); if (unlikely(!__pyx_tuple__150)) __PYX_ERR(0, 497, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__150);
  __Pyx_GIVEREF(__pyx_tuple__150);
  __pyx_codeobj__151 = (PyObject*)__Pyx_PyCode_New(1, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__150, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_math_sqrt_2, 497, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__151)) __PYX_ERR(0, 497, __pyx_L1_error)

  
  __pyx_tuple__152 = PyTuple_Pack(2, __pyx_n_s_data, __pyx_n_s_bytecode); if (unlikely(!__pyx_tuple__152)) __PYX_ERR(0, 511, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__152);
  __Pyx_GIVEREF(__pyx_tuple__152);
  __pyx_codeobj__153 = (PyObject*)__Pyx_PyCode_New(1, 0, 2, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__152, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_to_string, 511, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__153)) __PYX_ERR(0, 511, __pyx_L1_error)

  
  __pyx_tuple__154 = PyTuple_Pack(1, __pyx_n_u_size); if (unlikely(!__pyx_tuple__154)) __PYX_ERR(0, 520, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__154);
  __Pyx_GIVEREF(__pyx_tuple__154);

  
  __pyx_tuple__155 = PyTuple_Pack(6, __pyx_n_s_filename, __pyx_n_s_bfile, __pyx_n_s_content, __pyx_n_s_file_type, __pyx_n_s_output, __pyx_n_s_file); if (unlikely(!__pyx_tuple__155)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__155);
  __Pyx_GIVEREF(__pyx_tuple__155);
  __pyx_codeobj__156 = (PyObject*)__Pyx_PyCode_New(1, 0, 6, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__155, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_data, 524, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__156)) __PYX_ERR(0, 524, __pyx_L1_error)

  
  __pyx_tuple__157 = PyTuple_Pack(1, __pyx_n_s_syntax); if (unlikely(!__pyx_tuple__157)) __PYX_ERR(0, 552, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__157);
  __Pyx_GIVEREF(__pyx_tuple__157);
  __pyx_codeobj__158 = (PyObject*)__Pyx_PyCode_New(0, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__157, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_show_code, 552, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__158)) __PYX_ERR(0, 552, __pyx_L1_error)

  
  __pyx_tuple__159 = PyTuple_Pack(1, __pyx_n_s_file); if (unlikely(!__pyx_tuple__159)) __PYX_ERR(0, 559, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__159);
  __Pyx_GIVEREF(__pyx_tuple__159);
  __pyx_codeobj__160 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__159, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_decode_2, __pyx_n_s_show_file_size, 559, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__160)) __PYX_ERR(0, 559, __pyx_L1_error)

  
  __pyx_tuple__161 = PyTuple_Pack(1, __pyx_n_u_clear); if (unlikely(!__pyx_tuple__161)) __PYX_ERR(0, 564, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__161);
  __Pyx_GIVEREF(__pyx_tuple__161);

  
  __pyx_tuple__162 = PyTuple_Pack(1, __pyx_kp_u_1_31mstopped_0m); if (unlikely(!__pyx_tuple__162)) __PYX_ERR(0, 579, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__162);
  __Pyx_GIVEREF(__pyx_tuple__162);

  
  __pyx_tuple__163 = PyTuple_Pack(1, __pyx_kp_u_1_33mcan_t_show_the_code_becaus); if (unlikely(!__pyx_tuple__163)) __PYX_ERR(0, 591, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__163);
  __Pyx_GIVEREF(__pyx_tuple__163);

  
  __pyx_tuple__164 = PyTuple_Pack(1, __pyx_kp_u_Press_enter_to_continue_or_n_to); if (unlikely(!__pyx_tuple__164)) __PYX_ERR(0, 595, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__164);
  __Pyx_GIVEREF(__pyx_tuple__164);

  
  __pyx_tuple__165 = PyTuple_Pack(1, __pyx_kp_u_USAGE_decode_file_py_output_py_d); if (unlikely(!__pyx_tuple__165)) __PYX_ERR(0, 602, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__165);
  __Pyx_GIVEREF(__pyx_tuple__165);
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  __pyx_umethod_PyDict_Type_keys.type = (PyObject*)&PyDict_Type;
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_float_3_8 = PyFloat_FromDouble(3.8); if (unlikely(!__pyx_float_3_8)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_float_3_9 = PyFloat_FromDouble(3.9); if (unlikely(!__pyx_float_3_9)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_2 = PyInt_FromLong(2); if (unlikely(!__pyx_int_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4 = PyInt_FromLong(4); if (unlikely(!__pyx_int_4)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_10 = PyInt_FromLong(10); if (unlikely(!__pyx_int_10)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_16 = PyInt_FromLong(16); if (unlikely(!__pyx_int_16)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); 
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); 

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  
  if (PyType_Ready(&__pyx_type_6decode___pyx_scope_struct__object) < 0) __PYX_ERR(0, 72, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6decode___pyx_scope_struct__object.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6decode___pyx_scope_struct__object.tp_dictoffset && __pyx_type_6decode___pyx_scope_struct__object.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6decode___pyx_scope_struct__object.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6decode___pyx_scope_struct__object = &__pyx_type_6decode___pyx_scope_struct__object;
  if (PyType_Ready(&__pyx_type_6decode___pyx_scope_struct_1_function) < 0) __PYX_ERR(0, 87, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6decode___pyx_scope_struct_1_function.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6decode___pyx_scope_struct_1_function.tp_dictoffset && __pyx_type_6decode___pyx_scope_struct_1_function.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6decode___pyx_scope_struct_1_function.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6decode___pyx_scope_struct_1_function = &__pyx_type_6decode___pyx_scope_struct_1_function;
  if (PyType_Ready(&__pyx_type_6decode___pyx_scope_struct_2_eval_filter) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6decode___pyx_scope_struct_2_eval_filter.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6decode___pyx_scope_struct_2_eval_filter.tp_dictoffset && __pyx_type_6decode___pyx_scope_struct_2_eval_filter.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6decode___pyx_scope_struct_2_eval_filter.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6decode___pyx_scope_struct_2_eval_filter = &__pyx_type_6decode___pyx_scope_struct_2_eval_filter;
  if (PyType_Ready(&__pyx_type_6decode___pyx_scope_struct_3_exec_function) < 0) __PYX_ERR(0, 362, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6decode___pyx_scope_struct_3_exec_function.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6decode___pyx_scope_struct_3_exec_function.tp_dictoffset && __pyx_type_6decode___pyx_scope_struct_3_exec_function.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6decode___pyx_scope_struct_3_exec_function.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6decode___pyx_scope_struct_3_exec_function = &__pyx_type_6decode___pyx_scope_struct_3_exec_function;
  if (PyType_Ready(&__pyx_type_6decode___pyx_scope_struct_4_eval_function) < 0) __PYX_ERR(0, 423, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6decode___pyx_scope_struct_4_eval_function.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6decode___pyx_scope_struct_4_eval_function.tp_dictoffset && __pyx_type_6decode___pyx_scope_struct_4_eval_function.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6decode___pyx_scope_struct_4_eval_function.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6decode___pyx_scope_struct_4_eval_function = &__pyx_type_6decode___pyx_scope_struct_4_eval_function;
  if (PyType_Ready(&__pyx_type_6decode___pyx_scope_struct_5_bytes_list) < 0) __PYX_ERR(0, 484, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6decode___pyx_scope_struct_5_bytes_list.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6decode___pyx_scope_struct_5_bytes_list.tp_dictoffset && __pyx_type_6decode___pyx_scope_struct_5_bytes_list.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6decode___pyx_scope_struct_5_bytes_list.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6decode___pyx_scope_struct_5_bytes_list = &__pyx_type_6decode___pyx_scope_struct_5_bytes_list;
  if (PyType_Ready(&__pyx_type_6decode___pyx_scope_struct_6_genexpr) < 0) __PYX_ERR(0, 489, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6decode___pyx_scope_struct_6_genexpr.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6decode___pyx_scope_struct_6_genexpr.tp_dictoffset && __pyx_type_6decode___pyx_scope_struct_6_genexpr.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6decode___pyx_scope_struct_6_genexpr.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6decode___pyx_scope_struct_6_genexpr = &__pyx_type_6decode___pyx_scope_struct_6_genexpr;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initdecode(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC initdecode(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_decode(void) CYTHON_SMALL_CODE; 
__Pyx_PyMODINIT_FUNC PyInit_decode(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_decode(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  Py_ssize_t __pyx_t_5;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  PyObject *__pyx_t_11 = NULL;
  PyObject *__pyx_t_12 = NULL;
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'decode' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_decode(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  
  
  #if defined(WITH_THREAD) && PY_VERSION_HEX < 0x030700F0 && defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  PyEval_InitThreads();
  #endif
  
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("decode", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_decode) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "decode")) {
      if (unlikely(PyDict_SetItemString(modules, "decode", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  if (unlikely(__Pyx_modinit_type_init_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_io, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_io, __pyx_t_1) < 0) __PYX_ERR(0, 5, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_re, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_re, __pyx_t_1) < 0) __PYX_ERR(0, 6, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_os, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_os, __pyx_t_1) < 0) __PYX_ERR(0, 7, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_sys, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sys, __pyx_t_1) < 0) __PYX_ERR(0, 8, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_zlib, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_zlib, __pyx_t_1) < 0) __PYX_ERR(0, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_math, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_math, __pyx_t_1) < 0) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_codecs, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_codecs, __pyx_t_1) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_base64, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_base64, __pyx_t_1) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_marshal, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_marshal, __pyx_t_1) < 0) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_zipfile, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_zipfile, __pyx_t_1) < 0) __PYX_ERR(0, 14, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_importlib, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_importlib, __pyx_t_1) < 0) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_multiprocessing, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_multiprocessing, __pyx_t_1) < 0) __PYX_ERR(0, 16, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_CodeType);
  __Pyx_GIVEREF(__pyx_n_s_CodeType);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_CodeType);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_types, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_CodeType); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CodeType, __pyx_t_1) < 0) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sys); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_path); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_insert); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_os); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_environ); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_3, __pyx_n_u_VIRTUAL_ENV); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_lib); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
  __Pyx_GIVEREF(__pyx_t_3);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_3);
  __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_1, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_sys); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_path); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_insert); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_os); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_environ); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_Dict_GetItem(__pyx_t_2, __pyx_n_u_VIRTUAL_ENV); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_tools_decode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_int_0);
  __Pyx_GIVEREF(__pyx_int_0);
  PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_int_0);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_t_2);
  __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_1, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_List);
  __Pyx_GIVEREF(__pyx_n_s_List);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_List);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_typing, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_List); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_List, __pyx_t_2) < 0) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_PYTHON_VERSION);
  __Pyx_GIVEREF(__pyx_n_s_PYTHON_VERSION);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_PYTHON_VERSION);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_uncompyle6, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_PYTHON_VERSION); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_PYTHON_VERSION, __pyx_t_1) < 0) __PYX_ERR(0, 23, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_decompile);
  __Pyx_GIVEREF(__pyx_n_s_decompile);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_decompile);
  __Pyx_INCREF(__pyx_n_s_decompile_file);
  __Pyx_GIVEREF(__pyx_n_s_decompile_file);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_n_s_decompile_file);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_uncompyle6_main, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_decompile); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_decompile, __pyx_t_2) < 0) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_decompile_file); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_decompile_file, __pyx_t_2) < 0) __PYX_ERR(0, 24, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = PyList_New(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_n_s_Console);
  __Pyx_GIVEREF(__pyx_n_s_Console);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_n_s_Console);
  __pyx_t_2 = __Pyx_Import(__pyx_n_s_rich_console, __pyx_t_1, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_ImportFrom(__pyx_t_2, __pyx_n_s_Console); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Console, __pyx_t_1) < 0) __PYX_ERR(0, 25, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_n_s_Syntax);
  __Pyx_GIVEREF(__pyx_n_s_Syntax);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_n_s_Syntax);
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_rich_syntax, __pyx_t_2, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_ImportFrom(__pyx_t_1, __pyx_n_s_Syntax); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Syntax, __pyx_t_2) < 0) __PYX_ERR(0, 26, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_DEBUG_MODE, Py_False) < 0) __PYX_ERR(0, 29, __pyx_L1_error)

  
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Console); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_console, __pyx_t_2) < 0) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_importlib); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_util); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_MAGIC_NUMBER); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MAGIC_NUMBER, __pyx_t_2) < 0) __PYX_ERR(0, 32, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyList_New(3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 33, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_INCREF(__pyx_kp_b_U_2);
  __Pyx_GIVEREF(__pyx_kp_b_U_2);
  PyList_SET_ITEM(__pyx_t_2, 0, __pyx_kp_b_U_2);
  __Pyx_INCREF(__pyx_kp_b_a_2);
  __Pyx_GIVEREF(__pyx_kp_b_a_2);
  PyList_SET_ITEM(__pyx_t_2, 1, __pyx_kp_b_a_2);
  __Pyx_INCREF(__pyx_kp_b__111);
  __Pyx_GIVEREF(__pyx_kp_b__111);
  PyList_SET_ITEM(__pyx_t_2, 2, __pyx_kp_b__111);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_MAGIC_NUMBERS, __pyx_t_2) < 0) __PYX_ERR(0, 33, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ZIP_MAGIC_NUMBER, __pyx_kp_b_PK) < 0) __PYX_ERR(0, 38, __pyx_L1_error)

  
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin___import__, __pyx_tuple__112, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Config); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CONFIG, __pyx_t_1) < 0) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ENCODEING, __pyx_kp_u_utf_8) < 0) __PYX_ERR(0, 40, __pyx_L1_error)

  
  __pyx_t_1 = __Pyx_GetBuiltinName(__pyx_n_s_exec); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_OLD_EXEC, __pyx_t_1) < 0) __PYX_ERR(0, 41, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_OLD_EVAL, __pyx_builtin_eval) < 0) __PYX_ERR(0, 42, __pyx_L1_error)

  
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_OLD_COMPILE, __pyx_builtin_compile) < 0) __PYX_ERR(0, 43, __pyx_L1_error)

  
  __pyx_t_1 = PyList_New(17); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_INCREF(__pyx_kp_u_eval_filter);
  __Pyx_GIVEREF(__pyx_kp_u_eval_filter);
  PyList_SET_ITEM(__pyx_t_1, 0, __pyx_kp_u_eval_filter);
  __Pyx_INCREF(__pyx_n_u_zlib);
  __Pyx_GIVEREF(__pyx_n_u_zlib);
  PyList_SET_ITEM(__pyx_t_1, 1, __pyx_n_u_zlib);
  __Pyx_INCREF(__pyx_kp_u_zlib_base64);
  __Pyx_GIVEREF(__pyx_kp_u_zlib_base64);
  PyList_SET_ITEM(__pyx_t_1, 2, __pyx_kp_u_zlib_base64);
  __Pyx_INCREF(__pyx_kp_u_codecs_bz2_codec);
  __Pyx_GIVEREF(__pyx_kp_u_codecs_bz2_codec);
  PyList_SET_ITEM(__pyx_t_1, 3, __pyx_kp_u_codecs_bz2_codec);
  __Pyx_INCREF(__pyx_n_u_base16);
  __Pyx_GIVEREF(__pyx_n_u_base16);
  PyList_SET_ITEM(__pyx_t_1, 4, __pyx_n_u_base16);
  __Pyx_INCREF(__pyx_n_u_base32);
  __Pyx_GIVEREF(__pyx_n_u_base32);
  PyList_SET_ITEM(__pyx_t_1, 5, __pyx_n_u_base32);
  __Pyx_INCREF(__pyx_n_u_base64);
  __Pyx_GIVEREF(__pyx_n_u_base64);
  PyList_SET_ITEM(__pyx_t_1, 6, __pyx_n_u_base64);
  __Pyx_INCREF(__pyx_n_u_base85);
  __Pyx_GIVEREF(__pyx_n_u_base85);
  PyList_SET_ITEM(__pyx_t_1, 7, __pyx_n_u_base85);
  __Pyx_INCREF(__pyx_n_u_marshal);
  __Pyx_GIVEREF(__pyx_n_u_marshal);
  PyList_SET_ITEM(__pyx_t_1, 8, __pyx_n_u_marshal);
  __Pyx_INCREF(__pyx_kp_u_machine_code);
  __Pyx_GIVEREF(__pyx_kp_u_machine_code);
  PyList_SET_ITEM(__pyx_t_1, 9, __pyx_kp_u_machine_code);
  __Pyx_INCREF(__pyx_kp_u_machine_code_py2);
  __Pyx_GIVEREF(__pyx_kp_u_machine_code_py2);
  PyList_SET_ITEM(__pyx_t_1, 10, __pyx_kp_u_machine_code_py2);
  __Pyx_INCREF(__pyx_kp_u_zip_code);
  __Pyx_GIVEREF(__pyx_kp_u_zip_code);
  PyList_SET_ITEM(__pyx_t_1, 11, __pyx_kp_u_zip_code);
  __Pyx_INCREF(__pyx_kp_u_abdullah_encrypt);
  __Pyx_GIVEREF(__pyx_kp_u_abdullah_encrypt);
  PyList_SET_ITEM(__pyx_t_1, 12, __pyx_kp_u_abdullah_encrypt);
  __Pyx_INCREF(__pyx_kp_u_exec_function);
  __Pyx_GIVEREF(__pyx_kp_u_exec_function);
  PyList_SET_ITEM(__pyx_t_1, 13, __pyx_kp_u_exec_function);
  __Pyx_INCREF(__pyx_kp_u_eval_function);
  __Pyx_GIVEREF(__pyx_kp_u_eval_function);
  PyList_SET_ITEM(__pyx_t_1, 14, __pyx_kp_u_eval_function);
  __Pyx_INCREF(__pyx_kp_u_bytes_list);
  __Pyx_GIVEREF(__pyx_kp_u_bytes_list);
  PyList_SET_ITEM(__pyx_t_1, 15, __pyx_kp_u_bytes_list);
  __Pyx_INCREF(__pyx_kp_u_math_sqrt);
  __Pyx_GIVEREF(__pyx_kp_u_math_sqrt);
  PyList_SET_ITEM(__pyx_t_1, 16, __pyx_kp_u_math_sqrt);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_ALGORITHOMS, __pyx_t_1) < 0) __PYX_ERR(0, 44, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_kp_u_Decoded_by_HackerMode_tool_Copy, __pyx_n_s_lstrip); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 68, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 68, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_COPYRIGHT, __pyx_t_2) < 0) __PYX_ERR(0, 64, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_CodeSearchAlgorithms, __pyx_n_s_CodeSearchAlgorithms, (PyObject *) NULL, __pyx_kp_s_decode_2, (PyObject *) NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_string, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 72, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_20CodeSearchAlgorithms_1object, __Pyx_CYFUNCTION_STATICMETHOD, __pyx_n_s_CodeSearchAlgorithms_object, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__114)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_staticmethod, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 71, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_object, __pyx_t_1) < 0) __PYX_ERR(0, 72, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 87, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_string, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 87, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_20CodeSearchAlgorithms_3function, __Pyx_CYFUNCTION_STATICMETHOD, __pyx_n_s_CodeSearchAlgorithms_function, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__3)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 87, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_staticmethod, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_function, __pyx_t_1) < 0) __PYX_ERR(0, 87, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_CodeSearchAlgorithms, __pyx_empty_tuple, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_CodeSearchAlgorithms, __pyx_t_1) < 0) __PYX_ERR(0, 70, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_Py3MetaclassPrepare((PyObject *) NULL, __pyx_empty_tuple, __pyx_n_s_DecodingAlgorithms, __pyx_n_s_DecodingAlgorithms, (PyObject *) NULL, __pyx_kp_s_decode_2, (PyObject *) NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_hash_type, __pyx_n_u_dict_2) < 0) __PYX_ERR(0, 108, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_1__init__, 0, __pyx_n_s_DecodingAlgorithms___init, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__117)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_init, __pyx_t_3) < 0) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_3eval_filter, 0, __pyx_n_s_DecodingAlgorithms_eval_filter, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__119)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_1, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_eval_filter_2, __pyx_t_1) < 0) __PYX_ERR(0, 164, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 201, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_5zlib, 0, __pyx_n_s_DecodingAlgorithms_zlib, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__121)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_zlib, __pyx_t_3) < 0) __PYX_ERR(0, 201, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 206, __pyx_L1_error)
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_7zlib_base64, 0, __pyx_n_s_DecodingAlgorithms_zlib_base64, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__123)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_1, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_zlib_base64_2, __pyx_t_1) < 0) __PYX_ERR(0, 206, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 213, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_9codecs_bz2_codec, 0, __pyx_n_s_DecodingAlgorithms_codecs_bz2_co, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__125)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_codecs_bz2_codec_2, __pyx_t_3) < 0) __PYX_ERR(0, 213, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 219, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 219, __pyx_L1_error)
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_11base16, 0, __pyx_n_s_DecodingAlgorithms_base16, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__127)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 219, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_1, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_base16, __pyx_t_1) < 0) __PYX_ERR(0, 219, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 224, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 224, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_13base32, 0, __pyx_n_s_DecodingAlgorithms_base32, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__129)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 224, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_base32, __pyx_t_3) < 0) __PYX_ERR(0, 224, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 229, __pyx_L1_error)
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_15base64, 0, __pyx_n_s_DecodingAlgorithms_base64, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__131)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_1, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_base64, __pyx_t_1) < 0) __PYX_ERR(0, 229, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 239, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_17base85, 0, __pyx_n_s_DecodingAlgorithms_base85, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__133)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_base85, __pyx_t_3) < 0) __PYX_ERR(0, 239, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 244, __pyx_L1_error)
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_19marshal, 0, __pyx_n_s_DecodingAlgorithms_marshal, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__135)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_1, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_marshal, __pyx_t_1) < 0) __PYX_ERR(0, 244, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 251, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_21machine_code, 0, __pyx_n_s_DecodingAlgorithms_machine_code, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__137)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_machine_code_2, __pyx_t_3) < 0) __PYX_ERR(0, 251, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 261, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 261, __pyx_L1_error)
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_23machine_code_py2, 0, __pyx_n_s_DecodingAlgorithms_machine_code_2, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__139)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 261, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_1, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_machine_code_py2_2, __pyx_t_1) < 0) __PYX_ERR(0, 261, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 276, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_25zip_code, 0, __pyx_n_s_DecodingAlgorithms_zip_code, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__141)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_zip_code_2, __pyx_t_3) < 0) __PYX_ERR(0, 276, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_27abdullah_encrypt, 0, __pyx_n_s_DecodingAlgorithms_abdullah_encr, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__143)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_abdullah_encrypt_2, __pyx_t_3) < 0) __PYX_ERR(0, 287, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 362, __pyx_L1_error)
  __pyx_t_1 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_29exec_function, 0, __pyx_n_s_DecodingAlgorithms_exec_function_10, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__145)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_1, __pyx_t_3);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_exec_function_2, __pyx_t_1) < 0) __PYX_ERR(0, 362, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  
  __pyx_t_1 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 423, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_t_1, __pyx_n_s_return, __pyx_n_u_unicode) < 0) __PYX_ERR(0, 423, __pyx_L1_error)
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_31eval_function, 0, __pyx_n_s_DecodingAlgorithms_eval_function_10, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__147)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 423, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_CyFunction_SetAnnotationsDict(__pyx_t_3, __pyx_t_1);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_eval_function_2, __pyx_t_3) < 0) __PYX_ERR(0, 423, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_33bytes_list, 0, __pyx_n_s_DecodingAlgorithms_bytes_list, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__149)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 484, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_bytes_list_2, __pyx_t_3) < 0) __PYX_ERR(0, 484, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_CyFunction_New(&__pyx_mdef_6decode_18DecodingAlgorithms_35math_sqrt, 0, __pyx_n_s_DecodingAlgorithms_math_sqrt, NULL, __pyx_kp_s_decode_2, __pyx_d, ((PyObject *)__pyx_codeobj__151)); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 497, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (__Pyx_SetNameInClass(__pyx_t_2, __pyx_n_s_math_sqrt_2, __pyx_t_3) < 0) __PYX_ERR(0, 497, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __pyx_t_3 = __Pyx_Py3ClassCreate(((PyObject*)&__Pyx_DefaultClassType), __pyx_n_s_DecodingAlgorithms, __pyx_empty_tuple, __pyx_t_2, NULL, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_DecodingAlgorithms, __pyx_t_3) < 0) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_NewEx(&__pyx_mdef_6decode_1to_string, NULL, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 511, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_to_string, __pyx_t_2) < 0) __PYX_ERR(0, 511, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin___import__, __pyx_tuple__154, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 520, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_Size); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 520, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_SIZE, __pyx_t_3) < 0) __PYX_ERR(0, 520, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Console); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 521, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = __Pyx_PyObject_CallNoArg(__pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 521, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_console, __pyx_t_2) < 0) __PYX_ERR(0, 521, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_NewEx(&__pyx_mdef_6decode_3data, NULL, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_data, __pyx_t_2) < 0) __PYX_ERR(0, 524, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_NewEx(&__pyx_mdef_6decode_5show_code, NULL, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 552, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_show_code, __pyx_t_2) < 0) __PYX_ERR(0, 552, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __pyx_t_2 = PyCFunction_NewEx(&__pyx_mdef_6decode_7show_file_size, NULL, __pyx_kp_s_decode_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 559, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_show_file_size, __pyx_t_2) < 0) __PYX_ERR(0, 559, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_name); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 562, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_4 = (__Pyx_PyUnicode_Equals(__pyx_t_2, __pyx_n_u_main, Py_EQ)); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 562, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (__pyx_t_4) {

    
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sys); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_argv); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_5 = PyObject_Length(__pyx_t_3); if (unlikely(__pyx_t_5 == ((Py_ssize_t)-1))) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_6 = ((__pyx_t_5 == 4) != 0);
    if (__pyx_t_6) {
    } else {
      __pyx_t_4 = __pyx_t_6;
      goto __pyx_L4_bool_binop_done;
    }
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_sys); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_argv); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_2, 3, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_lower); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_3 = __Pyx_PyObject_CallNoArg(__pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_6 = (__Pyx_PyUnicode_Equals(__pyx_t_3, __pyx_kp_u_psh_team, Py_EQ)); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 563, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_4 = __pyx_t_6;
    __pyx_L4_bool_binop_done:;
    if (__pyx_t_4) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_os); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 564, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_system); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 564, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_tuple__161, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 564, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_total_layers, __pyx_int_0) < 0) __PYX_ERR(0, 565, __pyx_L1_error)

      
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_copy, Py_False) < 0) __PYX_ERR(0, 566, __pyx_L1_error)

      
      __pyx_t_3 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 567, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_hash_type, __pyx_t_3) < 0) __PYX_ERR(0, 567, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

      
      while (1) {

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_total_layers); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 569, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_2 = __Pyx_PyObject_FormatSimple(__pyx_t_3, __pyx_empty_unicode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 569, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyUnicode_Concat(__pyx_kp_u_psh_team_developer_mode_total_l, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 569, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 569, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_copy); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 570, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_4 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_4 < 0)) __PYX_ERR(0, 570, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_6 = ((!__pyx_t_4) != 0);
        if (__pyx_t_6) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_data); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 571, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 571, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_argv); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 571, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_7, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 571, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_7, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1);
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 571, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (PyDict_SetItem(__pyx_d, __pyx_n_s_content, __pyx_t_2) < 0) __PYX_ERR(0, 571, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
          if (PyDict_SetItem(__pyx_d, __pyx_n_s_copy, Py_True) < 0) __PYX_ERR(0, 572, __pyx_L1_error)

          
          goto __pyx_L8;
        }

        
         {
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_data); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 574, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_sys); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 574, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_argv); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 574, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_7);
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_GetItemInt(__pyx_t_7, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 574, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
          __pyx_t_7 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_7 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_7)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_7);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_2 = (__pyx_t_7) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_7, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1);
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 574, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          if (PyDict_SetItem(__pyx_d, __pyx_n_s_content, __pyx_t_2) < 0) __PYX_ERR(0, 574, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        }
        __pyx_L8:;

        
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_8, &__pyx_t_9, &__pyx_t_10);
          __Pyx_XGOTREF(__pyx_t_8);
          __Pyx_XGOTREF(__pyx_t_9);
          __Pyx_XGOTREF(__pyx_t_10);
           {

            
            __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_DecodingAlgorithms); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 577, __pyx_L9_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_content); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 577, __pyx_L9_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_sys); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 577, __pyx_L9_error)
            __Pyx_GOTREF(__pyx_t_7);
            __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_argv); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 577, __pyx_L9_error)
            __Pyx_GOTREF(__pyx_t_11);
            __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
            __pyx_t_7 = __Pyx_GetItemInt(__pyx_t_11, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 577, __pyx_L9_error)
            __Pyx_GOTREF(__pyx_t_7);
            __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
            __Pyx_GetModuleGlobalName(__pyx_t_11, __pyx_n_s_hash_type); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 577, __pyx_L9_error)
            __Pyx_GOTREF(__pyx_t_11);
            __pyx_t_12 = NULL;
            __pyx_t_13 = 0;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
              __pyx_t_12 = PyMethod_GET_SELF(__pyx_t_3);
              if (likely(__pyx_t_12)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
                __Pyx_INCREF(__pyx_t_12);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_3, function);
                __pyx_t_13 = 1;
              }
            }
            #if CYTHON_FAST_PYCALL
            if (PyFunction_Check(__pyx_t_3)) {
              PyObject *__pyx_temp[4] = {__pyx_t_12, __pyx_t_1, __pyx_t_7, __pyx_t_11};
              __pyx_t_2 = __Pyx_PyFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 577, __pyx_L9_error)
              __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
              __Pyx_GOTREF(__pyx_t_2);
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
              __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
            } else
            #endif
            #if CYTHON_FAST_PYCCALL
            if (__Pyx_PyFastCFunction_Check(__pyx_t_3)) {
              PyObject *__pyx_temp[4] = {__pyx_t_12, __pyx_t_1, __pyx_t_7, __pyx_t_11};
              __pyx_t_2 = __Pyx_PyCFunction_FastCall(__pyx_t_3, __pyx_temp+1-__pyx_t_13, 3+__pyx_t_13); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 577, __pyx_L9_error)
              __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
              __Pyx_GOTREF(__pyx_t_2);
              __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
              __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
              __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
            } else
            #endif
            {
              __pyx_t_14 = PyTuple_New(3+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 577, __pyx_L9_error)
              __Pyx_GOTREF(__pyx_t_14);
              if (__pyx_t_12) {
                __Pyx_GIVEREF(__pyx_t_12); PyTuple_SET_ITEM(__pyx_t_14, 0, __pyx_t_12); __pyx_t_12 = NULL;
              }
              __Pyx_GIVEREF(__pyx_t_1);
              PyTuple_SET_ITEM(__pyx_t_14, 0+__pyx_t_13, __pyx_t_1);
              __Pyx_GIVEREF(__pyx_t_7);
              PyTuple_SET_ITEM(__pyx_t_14, 1+__pyx_t_13, __pyx_t_7);
              __Pyx_GIVEREF(__pyx_t_11);
              PyTuple_SET_ITEM(__pyx_t_14, 2+__pyx_t_13, __pyx_t_11);
              __pyx_t_1 = 0;
              __pyx_t_7 = 0;
              __pyx_t_11 = 0;
              __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_3, __pyx_t_14, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 577, __pyx_L9_error)
              __Pyx_GOTREF(__pyx_t_2);
              __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
            }
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            if (PyDict_SetItem(__pyx_d, __pyx_n_s_decoding_algorithms, __pyx_t_2) < 0) __PYX_ERR(0, 577, __pyx_L9_error)
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

            
          }
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
          __Pyx_XDECREF(__pyx_t_10); __pyx_t_10 = 0;
          goto __pyx_L16_try_end;
          __pyx_L9_error:;
          __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_XDECREF(__pyx_t_12); __pyx_t_12 = 0;
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;

          
          __pyx_t_13 = __Pyx_PyErr_ExceptionMatches(__pyx_builtin_KeyboardInterrupt);
          if (__pyx_t_13) {
            __Pyx_AddTraceback("decode", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_2, &__pyx_t_3, &__pyx_t_14) < 0) __PYX_ERR(0, 578, __pyx_L11_except_error)
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GOTREF(__pyx_t_14);

            
            __pyx_t_11 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__162, NULL); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 579, __pyx_L11_except_error)
            __Pyx_GOTREF(__pyx_t_11);
            __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;

            
            goto __pyx_L17_except_break;
            __pyx_L17_except_break:;
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
            goto __pyx_L14_try_break;
          }
          goto __pyx_L11_except_error;
          __pyx_L11_except_error:;

          
          __Pyx_XGIVEREF(__pyx_t_8);
          __Pyx_XGIVEREF(__pyx_t_9);
          __Pyx_XGIVEREF(__pyx_t_10);
          __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
          goto __pyx_L1_error;
          __pyx_L14_try_break:;
          __Pyx_XGIVEREF(__pyx_t_8);
          __Pyx_XGIVEREF(__pyx_t_9);
          __Pyx_XGIVEREF(__pyx_t_10);
          __Pyx_ExceptionReset(__pyx_t_8, __pyx_t_9, __pyx_t_10);
          goto __pyx_L7_break;
          __pyx_L16_try_end:;
        }

        
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_total_layers); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 582, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_3 = __Pyx_PyInt_AddObjC(__pyx_t_14, __pyx_int_1, 1, 1, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 582, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        if (PyDict_SetItem(__pyx_d, __pyx_n_s_total_layers, __pyx_t_3) < 0) __PYX_ERR(0, 582, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_decoding_algorithms); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 583, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_file_data); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 583, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = PyObject_RichCompare(((PyObject *)Py_TYPE(__pyx_t_14)), ((PyObject *)(&PyUnicode_Type)), Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 583, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 583, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (__pyx_t_6) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_show_file_size); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 584, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sys); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 584, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_argv); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 584, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_11);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_11, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 584, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
          __pyx_t_11 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_11)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_11);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
            }
          }
          __pyx_t_3 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_11, __pyx_t_2) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_2);
          __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 584, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          
        }

        
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_Console); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 585, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_2 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
          __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_14);
          if (likely(__pyx_t_2)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
            __Pyx_INCREF(__pyx_t_2);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_14, function);
          }
        }
        __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_14);
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 585, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        if (PyDict_SetItem(__pyx_d, __pyx_n_s_console, __pyx_t_3) < 0) __PYX_ERR(0, 585, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_multiprocessing); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 586, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_Process); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 586, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyDict_NewPresized(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 586, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_show_code); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 586, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        if (PyDict_SetItem(__pyx_t_3, __pyx_n_s_target, __pyx_t_2) < 0) __PYX_ERR(0, 586, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_t_14, __pyx_empty_tuple, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 586, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (PyDict_SetItem(__pyx_d, __pyx_n_s_p, __pyx_t_2) < 0) __PYX_ERR(0, 586, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_p); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 587, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_start); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 587, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_14);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_14, function);
          }
        }
        __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_14);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 587, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_p); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 588, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_join); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 588, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_14 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_14)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_14);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_2 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_14, __pyx_int_2) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_int_2);
        __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 588, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_p); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 589, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_is_alive); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 589, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_14);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_14, function);
          }
        }
        __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_14);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 589, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_2); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 589, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (__pyx_t_6) {

          
          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_p); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 590, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_kill); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 590, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
            __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_3);
            if (likely(__pyx_t_14)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
              __Pyx_INCREF(__pyx_t_14);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_3, function);
            }
          }
          __pyx_t_2 = (__pyx_t_14) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_14) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 590, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
          __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__163, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 591, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

          
        }

        
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 592, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_decoding_algorithms); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 593, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_file_data); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 593, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_content); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 593, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_14 = PyObject_RichCompare(__pyx_t_3, __pyx_t_2, Py_EQ); __Pyx_XGOTREF(__pyx_t_14); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 593, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_14); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 593, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        if (__pyx_t_6) {

          
          goto __pyx_L7_break;

          
        }

        
        __pyx_t_2 = __Pyx_PyObject_Call(__pyx_builtin_input, __pyx_tuple__164, NULL); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 595, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_lower); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 595, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
          __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
          if (likely(__pyx_t_2)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
            __Pyx_INCREF(__pyx_t_2);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_3, function);
          }
        }
        __pyx_t_14 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
        __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 595, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_6 = (__Pyx_PyUnicode_Equals(__pyx_t_14, __pyx_n_u_n, Py_EQ)); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(0, 595, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        if (__pyx_t_6) {

          
          goto __pyx_L7_break;

          
        }

        
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_os); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 597, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_system); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 597, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_n_u_clear) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_n_u_clear);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 597, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      }
      __pyx_L7_break:;

      
      goto __pyx_L3;
    }

    
    __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_sys); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_14);
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_argv); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    __pyx_t_5 = PyObject_Length(__pyx_t_2); if (unlikely(__pyx_t_5 == ((Py_ssize_t)-1))) __PYX_ERR(0, 598, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_6 = ((__pyx_t_5 == 3) != 0);
    if (__pyx_t_6) {

      
      __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_DecodingAlgorithms); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_data); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_sys); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_11 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_argv); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_11);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_11, 1, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_11); __pyx_t_11 = 0;
      __pyx_t_11 = __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_3); if (unlikely(!__pyx_t_11)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_11);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_sys); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_argv); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_GetItemInt(__pyx_t_14, 2, long, 1, __Pyx_PyInt_From_long, 0, 0, 1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
      __pyx_t_14 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __pyx_t_7 = PyTuple_New(3); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_7);
      __Pyx_GIVEREF(__pyx_t_11);
      PyTuple_SET_ITEM(__pyx_t_7, 0, __pyx_t_11);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_7, 1, __pyx_t_3);
      __Pyx_GIVEREF(__pyx_t_14);
      PyTuple_SET_ITEM(__pyx_t_7, 2, __pyx_t_14);
      __pyx_t_11 = 0;
      __pyx_t_3 = 0;
      __pyx_t_14 = 0;
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_7, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 599, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

      
      goto __pyx_L3;
    }

    
     {
      __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__165, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 602, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    }
    __pyx_L3:;

    
  }

  
  __pyx_t_14 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_14);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_14) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

  

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_11);
  __Pyx_XDECREF(__pyx_t_12);
  __Pyx_XDECREF(__pyx_t_14);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init decode", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init decode");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}



#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif


static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}


static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}


static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}


static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}


static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact)
{
    if (unlikely(!type)) {
        PyErr_SetString(PyExc_SystemError, "Missing type object");
        return 0;
    }
    else if (exact) {
        #if PY_MAJOR_VERSION == 2
        if ((type == &PyBaseString_Type) && likely(__Pyx_PyBaseString_CheckExact(obj))) return 1;
        #endif
    }
    else {
        if (likely(__Pyx_TypeCheck(obj, type))) return 1;
    }
    PyErr_Format(PyExc_TypeError,
        "Argument '%.200s' has incorrect type (expected %.200s, got %.200s)",
        name, type->tp_name, Py_TYPE(obj)->tp_name);
    return 0;
}


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a + b);
            if (likely((x^a) >= 0 || (x^b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_add(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_add(op1, op2);
            }
        }
                x = a + b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla + llb;
            return PyLong_FromLongLong(llx);
#endif
        
        
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("add", return NULL)
            result = ((double)a) + (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceAdd : PyNumber_Add)(op1, op2);
}
#endif


static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname) {
    PyErr_Format(PyExc_NameError, "free variable '%s' referenced before assignment in enclosing scope", varname);
}


static CYTHON_INLINE PyObject *__Pyx_GetAttr(PyObject *o, PyObject *n) {
#if CYTHON_USE_TYPE_SLOTS
#if PY_MAJOR_VERSION >= 3
    if (likely(PyUnicode_Check(n)))
#else
    if (likely(PyString_Check(n)))
#endif
        return __Pyx_PyObject_GetAttrStr(o, n);
#endif
    return PyObject_GetAttr(o, n);
}


static CYTHON_INLINE int __Pyx_HasAttr(PyObject *o, PyObject *n) {
    PyObject *r;
    if (unlikely(!__Pyx_PyBaseString_Check(n))) {
        PyErr_SetString(PyExc_TypeError,
                        "hasattr(): attribute name must be string");
        return -1;
    }
    r = __Pyx_GetAttr(o, n);
    if (unlikely(!r)) {
        PyErr_Clear();
        return 0;
    } else {
        Py_DECREF(r);
        return 1;
    }
}


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = Py_TYPE(func)->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}


#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    Py_INCREF(m->func_qualname);
    return m->func_qualname;
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_Init(__pyx_CyFunctionObject *op, PyMethodDef *ml, int flags, PyObject* qualname,
                                       PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    if (unlikely(op == NULL))
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults_size = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
#if PY_MAJOR_VERSION < 3
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
#endif
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    m->defaults_size = size;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}


static PyObject *__Pyx_CyFunction_New(PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    PyObject *op = __Pyx_CyFunction_Init(
        PyObject_GC_New(__pyx_CyFunctionObject, __pyx_CyFunctionType),
        ml, flags, qualname, closure, module, globals, code
    );
    if (likely(op)) {
        PyObject_GC_Track(op);
    }
    return op;
}


static int __Pyx_TryUnpackUnboundCMethod(__Pyx_CachedCFunction* target) {
    PyObject *method;
    method = __Pyx_PyObject_GetAttrStr(target->type, *target->method_name);
    if (unlikely(!method))
        return -1;
    target->method = method;
#if CYTHON_COMPILING_IN_CPYTHON
    #if PY_MAJOR_VERSION >= 3
    if (likely(__Pyx_TypeCheck(method, &PyMethodDescr_Type)))
    #endif
    {
        PyMethodDescrObject *descr = (PyMethodDescrObject*) method;
        target->func = descr->d_method->ml_meth;
        target->flag = descr->d_method->ml_flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_STACKLESS);
    }
#endif
    return 0;
}


static PyObject* __Pyx__CallUnboundCMethod0(__Pyx_CachedCFunction* cfunc, PyObject* self) {
    PyObject *args, *result = NULL;
    if (unlikely(!cfunc->method) && unlikely(__Pyx_TryUnpackUnboundCMethod(cfunc) < 0)) return NULL;
#if CYTHON_ASSUME_SAFE_MACROS
    args = PyTuple_New(1);
    if (unlikely(!args)) goto bad;
    Py_INCREF(self);
    PyTuple_SET_ITEM(args, 0, self);
#else
    args = PyTuple_Pack(1, self);
    if (unlikely(!args)) goto bad;
#endif
    result = __Pyx_PyObject_Call(cfunc->method, args, NULL);
    Py_DECREF(args);
bad:
    return result;
}


static CYTHON_INLINE PyObject* __Pyx_PyDict_Keys(PyObject* d) {
    if (PY_MAJOR_VERSION >= 3)
        return __Pyx_CallUnboundCMethod0(&__pyx_umethod_PyDict_Type_keys, d);
    else
        return PyDict_Keys(d);
}


static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}


#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key) {
    PyObject *value;
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (!PyErr_Occurred()) {
            if (unlikely(PyTuple_Check(key))) {
                PyObject* args = PyTuple_Pack(1, key);
                if (likely(args)) {
                    PyErr_SetObject(PyExc_KeyError, args);
                    Py_DECREF(args);
                }
            } else {
                PyErr_SetObject(PyExc_KeyError, key);
            }
        }
        return NULL;
    }
    Py_INCREF(value);
    return value;
}
#endif


#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif


#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}


#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif


#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#ifdef __Pyx_CyFunction_USED
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif


#if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb,
                        CYTHON_UNUSED PyObject *cause) {
    __Pyx_PyThreadState_declare
    Py_XINCREF(type);
    if (!value || value == Py_None)
        value = NULL;
    else
        Py_INCREF(value);
    if (!tb || tb == Py_None)
        tb = NULL;
    else {
        Py_INCREF(tb);
        if (!PyTraceBack_Check(tb)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: arg 3 must be a traceback or None");
            goto raise_error;
        }
    }
    if (PyType_Check(type)) {
#if CYTHON_COMPILING_IN_PYPY
        if (!value) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#endif
        PyErr_NormalizeException(&type, &value, &tb);
    } else {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        value = type;
        type = (PyObject*) Py_TYPE(type);
        Py_INCREF(type);
        if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: exception class must be a subclass of BaseException");
            goto raise_error;
        }
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}
#else
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#else
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}
#endif


static CYTHON_INLINE PyObject* __Pyx_PyUnicode_Substring(
            PyObject* text, Py_ssize_t start, Py_ssize_t stop) {
    Py_ssize_t length;
    if (unlikely(__Pyx_PyUnicode_READY(text) == -1)) return NULL;
    length = __Pyx_PyUnicode_GET_LENGTH(text);
    if (start < 0) {
        start += length;
        if (start < 0)
            start = 0;
    }
    if (stop < 0)
        stop += length;
    else if (stop > length)
        stop = length;
    if (stop <= start)
        return __Pyx_NewRef(__pyx_empty_unicode);
#if CYTHON_PEP393_ENABLED
    return PyUnicode_FromKindAndData(PyUnicode_KIND(text),
        PyUnicode_1BYTE_DATA(text) + start*PyUnicode_KIND(text), stop-start);
#else
    return PyUnicode_FromUnicode(PyUnicode_AS_UNICODE(text)+start, stop-start);
#endif
}


static CYTHON_INLINE int __Pyx_init_unicode_iteration(
    PyObject* ustring, Py_ssize_t *length, void** data, int *kind) {
#if CYTHON_PEP393_ENABLED
    if (unlikely(__Pyx_PyUnicode_READY(ustring) < 0)) return -1;
    *kind   = PyUnicode_KIND(ustring);
    *length = PyUnicode_GET_LENGTH(ustring);
    *data   = PyUnicode_DATA(ustring);
#else
    *kind   = 0;
    *length = PyUnicode_GET_SIZE(ustring);
    *data   = (void*)PyUnicode_AS_UNICODE(ustring);
#endif
    return 0;
}


static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
    if (s1 == s2) {
        return (equals == Py_EQ);
    } else if (PyBytes_CheckExact(s1) & PyBytes_CheckExact(s2)) {
        const char *ps1, *ps2;
        Py_ssize_t length = PyBytes_GET_SIZE(s1);
        if (length != PyBytes_GET_SIZE(s2))
            return (equals == Py_NE);
        ps1 = PyBytes_AS_STRING(s1);
        ps2 = PyBytes_AS_STRING(s2);
        if (ps1[0] != ps2[0]) {
            return (equals == Py_NE);
        } else if (length == 1) {
            return (equals == Py_EQ);
        } else {
            int result;
#if CYTHON_USE_UNICODE_INTERNALS
            Py_hash_t hash1, hash2;
            hash1 = ((PyBytesObject*)s1)->ob_shash;
            hash2 = ((PyBytesObject*)s2)->ob_shash;
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                return (equals == Py_NE);
            }
#endif
            result = memcmp(ps1, ps2, (size_t)length);
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & PyBytes_CheckExact(s2)) {
        return (equals == Py_NE);
    } else if ((s2 == Py_None) & PyBytes_CheckExact(s1)) {
        return (equals == Py_NE);
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
#endif
}


static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
#if PY_MAJOR_VERSION < 3
    PyObject* owned_ref = NULL;
#endif
    int s1_is_unicode, s2_is_unicode;
    if (s1 == s2) {
        goto return_eq;
    }
    s1_is_unicode = PyUnicode_CheckExact(s1);
    s2_is_unicode = PyUnicode_CheckExact(s2);
#if PY_MAJOR_VERSION < 3
    if ((s1_is_unicode & (!s2_is_unicode)) && PyString_CheckExact(s2)) {
        owned_ref = PyUnicode_FromObject(s2);
        if (unlikely(!owned_ref))
            return -1;
        s2 = owned_ref;
        s2_is_unicode = 1;
    } else if ((s2_is_unicode & (!s1_is_unicode)) && PyString_CheckExact(s1)) {
        owned_ref = PyUnicode_FromObject(s1);
        if (unlikely(!owned_ref))
            return -1;
        s1 = owned_ref;
        s1_is_unicode = 1;
    } else if (((!s2_is_unicode) & (!s1_is_unicode))) {
        return __Pyx_PyBytes_Equals(s1, s2, equals);
    }
#endif
    if (s1_is_unicode & s2_is_unicode) {
        Py_ssize_t length;
        int kind;
        void *data1, *data2;
        if (unlikely(__Pyx_PyUnicode_READY(s1) < 0) || unlikely(__Pyx_PyUnicode_READY(s2) < 0))
            return -1;
        length = __Pyx_PyUnicode_GET_LENGTH(s1);
        if (length != __Pyx_PyUnicode_GET_LENGTH(s2)) {
            goto return_ne;
        }
#if CYTHON_USE_UNICODE_INTERNALS
        {
            Py_hash_t hash1, hash2;
        #if CYTHON_PEP393_ENABLED
            hash1 = ((PyASCIIObject*)s1)->hash;
            hash2 = ((PyASCIIObject*)s2)->hash;
        #else
            hash1 = ((PyUnicodeObject*)s1)->hash;
            hash2 = ((PyUnicodeObject*)s2)->hash;
        #endif
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                goto return_ne;
            }
        }
#endif
        kind = __Pyx_PyUnicode_KIND(s1);
        if (kind != __Pyx_PyUnicode_KIND(s2)) {
            goto return_ne;
        }
        data1 = __Pyx_PyUnicode_DATA(s1);
        data2 = __Pyx_PyUnicode_DATA(s2);
        if (__Pyx_PyUnicode_READ(kind, data1, 0) != __Pyx_PyUnicode_READ(kind, data2, 0)) {
            goto return_ne;
        } else if (length == 1) {
            goto return_eq;
        } else {
            int result = memcmp(data1, data2, (size_t)(length * kind));
            #if PY_MAJOR_VERSION < 3
            Py_XDECREF(owned_ref);
            #endif
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & s2_is_unicode) {
        goto return_ne;
    } else if ((s2 == Py_None) & s1_is_unicode) {
        goto return_ne;
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        #if PY_MAJOR_VERSION < 3
        Py_XDECREF(owned_ref);
        #endif
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
return_eq:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_EQ);
return_ne:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_NE);
#endif
}


#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_SubtractObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a - b);
            if (likely((x^a) >= 0 || (x^~b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_subtract(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_subtract(op1, op2);
            }
        }
                x = a - b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla - llb;
            return PyLong_FromLongLong(llx);
#endif
        
        
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("subtract", return NULL)
            result = ((double)a) - (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceSubtract : PyNumber_Subtract)(op1, op2);
}
#endif


static CYTHON_INLINE PyObject* __Pyx_PyInt_EqObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, CYTHON_UNUSED long inplace) {
    if (op1 == op2) {
        Py_RETURN_TRUE;
    }
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long a = PyInt_AS_LONG(op1);
        if (a == b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        int unequal;
        unsigned long uintval;
        Py_ssize_t size = Py_SIZE(op1);
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        if (intval == 0) {
            if (size == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
        } else if (intval < 0) {
            if (size >= 0)
                Py_RETURN_FALSE;
            intval = -intval;
            size = -size;
        } else {
            if (size <= 0)
                Py_RETURN_FALSE;
        }
        uintval = (unsigned long) intval;
#if PyLong_SHIFT * 4 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 4)) {
            unequal = (size != 5) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[4] != ((uintval >> (4 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 3 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 3)) {
            unequal = (size != 4) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[3] != ((uintval >> (3 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 2 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 2)) {
            unequal = (size != 3) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK)) | (digits[2] != ((uintval >> (2 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
#if PyLong_SHIFT * 1 < SIZEOF_LONG*8
        if (uintval >> (PyLong_SHIFT * 1)) {
            unequal = (size != 2) || (digits[0] != (uintval & (unsigned long) PyLong_MASK))
                 | (digits[1] != ((uintval >> (1 * PyLong_SHIFT)) & (unsigned long) PyLong_MASK));
        } else
#endif
            unequal = (size != 1) || (((unsigned long) digits[0]) != (uintval & (unsigned long) PyLong_MASK));
        if (unequal == 0) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
        if ((double)a == (double)b) Py_RETURN_TRUE; else Py_RETURN_FALSE;
    }
    return (
        PyObject_RichCompare(op1, op2, Py_EQ));
}


#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE int __Pyx_PyObject_SetAttrStr(PyObject* obj, PyObject* attr_name, PyObject* value) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_setattro))
        return tp->tp_setattro(obj, attr_name, value);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_setattr))
        return tp->tp_setattr(obj, PyString_AS_STRING(attr_name), value);
#endif
    return PyObject_SetAttr(obj, attr_name, value);
}
#endif


#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (__Pyx_PyFastCFunction_Check(func)) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif


#if CYTHON_USE_TYPE_SLOTS
static PyObject *__Pyx_PyObject_GetIndex(PyObject *obj, PyObject* index) {
    PyObject *runerr;
    Py_ssize_t key_value;
    PySequenceMethods *m = Py_TYPE(obj)->tp_as_sequence;
    if (unlikely(!(m && m->sq_item))) {
        PyErr_Format(PyExc_TypeError, "'%.200s' object is not subscriptable", Py_TYPE(obj)->tp_name);
        return NULL;
    }
    key_value = __Pyx_PyIndex_AsSsize_t(index);
    if (likely(key_value != -1 || !(runerr = PyErr_Occurred()))) {
        return __Pyx_GetItemInt_Fast(obj, key_value, 0, 1, 1);
    }
    if (PyErr_GivenExceptionMatches(runerr, PyExc_OverflowError)) {
        PyErr_Clear();
        PyErr_Format(PyExc_IndexError, "cannot fit '%.200s' into an index-sized integer", Py_TYPE(index)->tp_name);
    }
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key) {
    PyMappingMethods *m = Py_TYPE(obj)->tp_as_mapping;
    if (likely(m && m->mp_subscript)) {
        return m->mp_subscript(obj, key);
    }
    return __Pyx_PyObject_GetIndex(obj, key);
}
#endif


static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}


static PyObject* __Pyx_PyUnicode_Join(PyObject* value_tuple, Py_ssize_t value_count, Py_ssize_t result_ulength,
                                      CYTHON_UNUSED Py_UCS4 max_char) {
#if CYTHON_USE_UNICODE_INTERNALS && CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    PyObject *result_uval;
    int result_ukind;
    Py_ssize_t i, char_pos;
    void *result_udata;
#if CYTHON_PEP393_ENABLED
    result_uval = PyUnicode_New(result_ulength, max_char);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = (max_char <= 255) ? PyUnicode_1BYTE_KIND : (max_char <= 65535) ? PyUnicode_2BYTE_KIND : PyUnicode_4BYTE_KIND;
    result_udata = PyUnicode_DATA(result_uval);
#else
    result_uval = PyUnicode_FromUnicode(NULL, result_ulength);
    if (unlikely(!result_uval)) return NULL;
    result_ukind = sizeof(Py_UNICODE);
    result_udata = PyUnicode_AS_UNICODE(result_uval);
#endif
    char_pos = 0;
    for (i=0; i < value_count; i++) {
        int ukind;
        Py_ssize_t ulength;
        void *udata;
        PyObject *uval = PyTuple_GET_ITEM(value_tuple, i);
        if (unlikely(__Pyx_PyUnicode_READY(uval)))
            goto bad;
        ulength = __Pyx_PyUnicode_GET_LENGTH(uval);
        if (unlikely(!ulength))
            continue;
        if (unlikely(char_pos + ulength < 0))
            goto overflow;
        ukind = __Pyx_PyUnicode_KIND(uval);
        udata = __Pyx_PyUnicode_DATA(uval);
        if (!CYTHON_PEP393_ENABLED || ukind == result_ukind) {
            memcpy((char *)result_udata + char_pos * result_ukind, udata, (size_t) (ulength * result_ukind));
        } else {
            #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030300F0 || defined(_PyUnicode_FastCopyCharacters)
            _PyUnicode_FastCopyCharacters(result_uval, char_pos, uval, 0, ulength);
            #else
            Py_ssize_t j;
            for (j=0; j < ulength; j++) {
                Py_UCS4 uchar = __Pyx_PyUnicode_READ(ukind, udata, j);
                __Pyx_PyUnicode_WRITE(result_ukind, result_udata, char_pos+j, uchar);
            }
            #endif
        }
        char_pos += ulength;
    }
    return result_uval;
overflow:
    PyErr_SetString(PyExc_OverflowError, "join() result is too long for a Python string");
bad:
    Py_DECREF(result_uval);
    return NULL;
#else
    result_ulength++;
    value_count++;
    return PyUnicode_Join(__pyx_empty_unicode, value_tuple);
#endif
}


#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx_PyErr_ExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        if (__Pyx_PyErr_GivenExceptionMatches(exc_type, PyTuple_GET_ITEM(tuple, i))) return 1;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err) {
    PyObject *exc_type = tstate->curexc_type;
    if (exc_type == err) return 1;
    if (unlikely(!exc_type)) return 0;
    if (unlikely(PyTuple_Check(err)))
        return __Pyx_PyErr_ExceptionMatchesTuple(exc_type, err);
    return __Pyx_PyErr_GivenExceptionMatches(exc_type, err);
}
#endif


#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}


static const char DIGIT_PAIRS_10[2*10*10+1] = {
    "00010203040506070809"
    "10111213141516171819"
    "20212223242526272829"
    "30313233343536373839"
    "40414243444546474849"
    "50515253545556575859"
    "60616263646566676869"
    "70717273747576777879"
    "80818283848586878889"
    "90919293949596979899"
};
static const char DIGIT_PAIRS_8[2*8*8+1] = {
    "0001020304050607"
    "1011121314151617"
    "2021222324252627"
    "3031323334353637"
    "4041424344454647"
    "5051525354555657"
    "6061626364656667"
    "7071727374757677"
};
static const char DIGITS_HEX[2*16+1] = {
    "0123456789abcdef"
    "0123456789ABCDEF"
};


static PyObject* __Pyx_PyUnicode_BuildFromAscii(Py_ssize_t ulength, char* chars, int clength,
                                                int prepend_sign, char padding_char) {
    PyObject *uval;
    Py_ssize_t uoffset = ulength - clength;
#if CYTHON_USE_UNICODE_INTERNALS
    Py_ssize_t i;
#if CYTHON_PEP393_ENABLED
    void *udata;
    uval = PyUnicode_New(ulength, 127);
    if (unlikely(!uval)) return NULL;
    udata = PyUnicode_DATA(uval);
#else
    Py_UNICODE *udata;
    uval = PyUnicode_FromUnicode(NULL, ulength);
    if (unlikely(!uval)) return NULL;
    udata = PyUnicode_AS_UNICODE(uval);
#endif
    if (uoffset > 0) {
        i = 0;
        if (prepend_sign) {
            __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, 0, '-');
            i++;
        }
        for (; i < uoffset; i++) {
            __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, i, padding_char);
        }
    }
    for (i=0; i < clength; i++) {
        __Pyx_PyUnicode_WRITE(PyUnicode_1BYTE_KIND, udata, uoffset+i, chars[i]);
    }
#else
    {
        PyObject *sign = NULL, *padding = NULL;
        uval = NULL;
        if (uoffset > 0) {
            prepend_sign = !!prepend_sign;
            if (uoffset > prepend_sign) {
                padding = PyUnicode_FromOrdinal(padding_char);
                if (likely(padding) && uoffset > prepend_sign + 1) {
                    PyObject *tmp;
                    PyObject *repeat = PyInt_FromSize_t(uoffset - prepend_sign);
                    if (unlikely(!repeat)) goto done_or_error;
                    tmp = PyNumber_Multiply(padding, repeat);
                    Py_DECREF(repeat);
                    Py_DECREF(padding);
                    padding = tmp;
                }
                if (unlikely(!padding)) goto done_or_error;
            }
            if (prepend_sign) {
                sign = PyUnicode_FromOrdinal('-');
                if (unlikely(!sign)) goto done_or_error;
            }
        }
        uval = PyUnicode_DecodeASCII(chars, clength, NULL);
        if (likely(uval) && padding) {
            PyObject *tmp = PyNumber_Add(padding, uval);
            Py_DECREF(uval);
            uval = tmp;
        }
        if (likely(uval) && sign) {
            PyObject *tmp = PyNumber_Add(sign, uval);
            Py_DECREF(uval);
            uval = tmp;
        }
done_or_error:
        Py_XDECREF(padding);
        Py_XDECREF(sign);
    }
#endif
    return uval;
}


#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned short    uint16_t;
        #else
           typedef unsigned __int16  uint16_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_From_Py_ssize_t(Py_ssize_t value, Py_ssize_t width, char padding_char, char format_char) {
    char digits[sizeof(Py_ssize_t)*3+2];
    char *dpos, *end = digits + sizeof(Py_ssize_t)*3+2;
    const char *hex_digits = DIGITS_HEX;
    Py_ssize_t length, ulength;
    int prepend_sign, last_one_off;
    Py_ssize_t remaining;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const Py_ssize_t neg_one = (Py_ssize_t) -1, const_zero = (Py_ssize_t) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (format_char == 'X') {
        hex_digits += 16;
        format_char = 'x';
    }
    remaining = value;
    last_one_off = 0;
    dpos = end;
    do {
        int digit_pos;
        switch (format_char) {
        case 'o':
            digit_pos = abs((int)(remaining % (8*8)));
            remaining = (Py_ssize_t) (remaining / (8*8));
            dpos -= 2;
            *(uint16_t*)dpos = ((const uint16_t*)DIGIT_PAIRS_8)[digit_pos];
            last_one_off = (digit_pos < 8);
            break;
        case 'd':
            digit_pos = abs((int)(remaining % (10*10)));
            remaining = (Py_ssize_t) (remaining / (10*10));
            dpos -= 2;
            *(uint16_t*)dpos = ((const uint16_t*)DIGIT_PAIRS_10)[digit_pos];
            last_one_off = (digit_pos < 10);
            break;
        case 'x':
            *(--dpos) = hex_digits[abs((int)(remaining % 16))];
            remaining = (Py_ssize_t) (remaining / 16);
            break;
        default:
            assert(0);
            break;
        }
    } while (unlikely(remaining != 0));
    if (last_one_off) {
        assert(*dpos == '0');
        dpos++;
    }
    length = end - dpos;
    ulength = length;
    prepend_sign = 0;
    if (!is_unsigned && value <= neg_one) {
        if (padding_char == ' ' || width <= length + 1) {
            *(--dpos) = '-';
            ++length;
        } else {
            prepend_sign = 1;
        }
        ++ulength;
    }
    if (width > ulength) {
        ulength = width;
    }
    if (ulength == 1) {
        return PyUnicode_FromOrdinal(*dpos);
    }
    return __Pyx_PyUnicode_BuildFromAscii(ulength, dpos, (int) length, prepend_sign, padding_char);
}


#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSwap(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = *type;
    exc_info->exc_value = *value;
    exc_info->exc_traceback = *tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = *type;
    tstate->exc_value = *value;
    tstate->exc_traceback = *tb;
    #endif
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#else
static CYTHON_INLINE void __Pyx_ExceptionSwap(PyObject **type, PyObject **value, PyObject **tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    PyErr_GetExcInfo(&tmp_type, &tmp_value, &tmp_tb);
    PyErr_SetExcInfo(*type, *value, *tb);
    *type = tmp_type;
    *value = tmp_value;
    *tb = tmp_tb;
}
#endif


static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(PyObject* obj,
        Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** _py_start, PyObject** _py_stop, PyObject** _py_slice,
        int has_cstart, int has_cstop, CYTHON_UNUSED int wraparound) {
#if CYTHON_USE_TYPE_SLOTS
    PyMappingMethods* mp;
#if PY_MAJOR_VERSION < 3
    PySequenceMethods* ms = Py_TYPE(obj)->tp_as_sequence;
    if (likely(ms && ms->sq_slice)) {
        if (!has_cstart) {
            if (_py_start && (*_py_start != Py_None)) {
                cstart = __Pyx_PyIndex_AsSsize_t(*_py_start);
                if ((cstart == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstart = 0;
        }
        if (!has_cstop) {
            if (_py_stop && (*_py_stop != Py_None)) {
                cstop = __Pyx_PyIndex_AsSsize_t(*_py_stop);
                if ((cstop == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstop = PY_SSIZE_T_MAX;
        }
        if (wraparound && unlikely((cstart < 0) | (cstop < 0)) && likely(ms->sq_length)) {
            Py_ssize_t l = ms->sq_length(obj);
            if (likely(l >= 0)) {
                if (cstop < 0) {
                    cstop += l;
                    if (cstop < 0) cstop = 0;
                }
                if (cstart < 0) {
                    cstart += l;
                    if (cstart < 0) cstart = 0;
                }
            } else {
                if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                    goto bad;
                PyErr_Clear();
            }
        }
        return ms->sq_slice(obj, cstart, cstop);
    }
#endif
    mp = Py_TYPE(obj)->tp_as_mapping;
    if (likely(mp && mp->mp_subscript))
#endif
    {
        PyObject* result;
        PyObject *py_slice, *py_start, *py_stop;
        if (_py_slice) {
            py_slice = *_py_slice;
        } else {
            PyObject* owned_start = NULL;
            PyObject* owned_stop = NULL;
            if (_py_start) {
                py_start = *_py_start;
            } else {
                if (has_cstart) {
                    owned_start = py_start = PyInt_FromSsize_t(cstart);
                    if (unlikely(!py_start)) goto bad;
                } else
                    py_start = Py_None;
            }
            if (_py_stop) {
                py_stop = *_py_stop;
            } else {
                if (has_cstop) {
                    owned_stop = py_stop = PyInt_FromSsize_t(cstop);
                    if (unlikely(!py_stop)) {
                        Py_XDECREF(owned_start);
                        goto bad;
                    }
                } else
                    py_stop = Py_None;
            }
            py_slice = PySlice_New(py_start, py_stop, Py_None);
            Py_XDECREF(owned_start);
            Py_XDECREF(owned_stop);
            if (unlikely(!py_slice)) goto bad;
        }
#if CYTHON_USE_TYPE_SLOTS
        result = mp->mp_subscript(obj, py_slice);
#else
        result = PyObject_GetItem(obj, py_slice);
#endif
        if (!_py_slice) {
            Py_DECREF(py_slice);
        }
        return result;
    }
    PyErr_Format(PyExc_TypeError,
        "'%.200s' object is unsliceable", Py_TYPE(obj)->tp_name);
bad:
    return NULL;
}


static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname) {
    PyErr_Format(PyExc_UnboundLocalError, "local variable '%s' referenced before assignment", varname);
}


static CYTHON_INLINE int __Pyx_IterFinish(void) {
#if CYTHON_FAST_THREAD_STATE
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject* exc_type = tstate->curexc_type;
    if (unlikely(exc_type)) {
        if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) {
            PyObject *exc_value, *exc_tb;
            exc_value = tstate->curexc_value;
            exc_tb = tstate->curexc_traceback;
            tstate->curexc_type = 0;
            tstate->curexc_value = 0;
            tstate->curexc_traceback = 0;
            Py_DECREF(exc_type);
            Py_XDECREF(exc_value);
            Py_XDECREF(exc_tb);
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#else
    if (unlikely(PyErr_Occurred())) {
        if (likely(PyErr_ExceptionMatches(PyExc_StopIteration))) {
            PyErr_Clear();
            return 0;
        } else {
            return -1;
        }
    }
    return 0;
#endif
}


static int __Pyx_PyObject_GetMethod(PyObject *obj, PyObject *name, PyObject **method) {
    PyObject *attr;
#if CYTHON_UNPACK_METHODS && CYTHON_COMPILING_IN_CPYTHON && CYTHON_USE_PYTYPE_LOOKUP
    PyTypeObject *tp = Py_TYPE(obj);
    PyObject *descr;
    descrgetfunc f = NULL;
    PyObject **dictptr, *dict;
    int meth_found = 0;
    assert (*method == NULL);
    if (unlikely(tp->tp_getattro != PyObject_GenericGetAttr)) {
        attr = __Pyx_PyObject_GetAttrStr(obj, name);
        goto try_unpack;
    }
    if (unlikely(tp->tp_dict == NULL) && unlikely(PyType_Ready(tp) < 0)) {
        return 0;
    }
    descr = _PyType_Lookup(tp, name);
    if (likely(descr != NULL)) {
        Py_INCREF(descr);
#if PY_MAJOR_VERSION >= 3
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr) || (Py_TYPE(descr) == &PyMethodDescr_Type)))
        #endif
#else
        #ifdef __Pyx_CyFunction_USED
        if (likely(PyFunction_Check(descr) || __Pyx_CyFunction_Check(descr)))
        #else
        if (likely(PyFunction_Check(descr)))
        #endif
#endif
        {
            meth_found = 1;
        } else {
            f = Py_TYPE(descr)->tp_descr_get;
            if (f != NULL && PyDescr_IsData(descr)) {
                attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
                Py_DECREF(descr);
                goto try_unpack;
            }
        }
    }
    dictptr = _PyObject_GetDictPtr(obj);
    if (dictptr != NULL && (dict = *dictptr) != NULL) {
        Py_INCREF(dict);
        attr = __Pyx_PyDict_GetItemStr(dict, name);
        if (attr != NULL) {
            Py_INCREF(attr);
            Py_DECREF(dict);
            Py_XDECREF(descr);
            goto try_unpack;
        }
        Py_DECREF(dict);
    }
    if (meth_found) {
        *method = descr;
        return 1;
    }
    if (f != NULL) {
        attr = f(descr, obj, (PyObject *)Py_TYPE(obj));
        Py_DECREF(descr);
        goto try_unpack;
    }
    if (descr != NULL) {
        *method = descr;
        return 0;
    }
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(name));
#endif
    return 0;
#else
    attr = __Pyx_PyObject_GetAttrStr(obj, name);
    goto try_unpack;
#endif
try_unpack:
#if CYTHON_UNPACK_METHODS
    if (likely(attr) && PyMethod_Check(attr) && likely(PyMethod_GET_SELF(attr) == obj)) {
        PyObject *function = PyMethod_GET_FUNCTION(attr);
        Py_INCREF(function);
        Py_DECREF(attr);
        *method = function;
        return 1;
    }
#endif
    *method = attr;
    return 0;
}


static PyObject* __Pyx_PyObject_CallMethod0(PyObject* obj, PyObject* method_name) {
    PyObject *method = NULL, *result = NULL;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_CallOneArg(method, obj);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) goto bad;
    result = __Pyx_PyObject_CallNoArg(method);
    Py_DECREF(method);
bad:
    return result;
}


static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
    PyErr_Format(PyExc_ValueError,
                 "need more than %" CYTHON_FORMAT_SSIZE_T "d value%.1s to unpack",
                 index, (index == 1) ? "" : "s");
}


static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected) {
    PyErr_Format(PyExc_ValueError,
                 "too many values to unpack (expected %" CYTHON_FORMAT_SSIZE_T "d)", expected);
}


static int __Pyx_IternextUnpackEndCheck(PyObject *retval, Py_ssize_t expected) {
    if (unlikely(retval)) {
        Py_DECREF(retval);
        __Pyx_RaiseTooManyValuesError(expected);
        return -1;
    } else {
        return __Pyx_IterFinish();
    }
    return 0;
}


static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
}


static void __Pyx_UnpackTupleError(PyObject *t, Py_ssize_t index) {
    if (t == Py_None) {
      __Pyx_RaiseNoneNotIterableError();
    } else if (PyTuple_GET_SIZE(t) < index) {
      __Pyx_RaiseNeedMoreValuesError(PyTuple_GET_SIZE(t));
    } else {
      __Pyx_RaiseTooManyValuesError(index);
    }
}


static CYTHON_INLINE int __Pyx_unpack_tuple2_exact(
        PyObject* tuple, PyObject** pvalue1, PyObject** pvalue2, int decref_tuple) {
    PyObject *value1 = NULL, *value2 = NULL;
#if CYTHON_COMPILING_IN_PYPY
    value1 = PySequence_ITEM(tuple, 0);  if (unlikely(!value1)) goto bad;
    value2 = PySequence_ITEM(tuple, 1);  if (unlikely(!value2)) goto bad;
#else
    value1 = PyTuple_GET_ITEM(tuple, 0);  Py_INCREF(value1);
    value2 = PyTuple_GET_ITEM(tuple, 1);  Py_INCREF(value2);
#endif
    if (decref_tuple) {
        Py_DECREF(tuple);
    }
    *pvalue1 = value1;
    *pvalue2 = value2;
    return 0;
#if CYTHON_COMPILING_IN_PYPY
bad:
    Py_XDECREF(value1);
    Py_XDECREF(value2);
    if (decref_tuple) { Py_XDECREF(tuple); }
    return -1;
#endif
}
static int __Pyx_unpack_tuple2_generic(PyObject* tuple, PyObject** pvalue1, PyObject** pvalue2,
                                       int has_known_size, int decref_tuple) {
    Py_ssize_t index;
    PyObject *value1 = NULL, *value2 = NULL, *iter = NULL;
    iternextfunc iternext;
    iter = PyObject_GetIter(tuple);
    if (unlikely(!iter)) goto bad;
    if (decref_tuple) { Py_DECREF(tuple); tuple = NULL; }
    iternext = Py_TYPE(iter)->tp_iternext;
    value1 = iternext(iter); if (unlikely(!value1)) { index = 0; goto unpacking_failed; }
    value2 = iternext(iter); if (unlikely(!value2)) { index = 1; goto unpacking_failed; }
    if (!has_known_size && unlikely(__Pyx_IternextUnpackEndCheck(iternext(iter), 2))) goto bad;
    Py_DECREF(iter);
    *pvalue1 = value1;
    *pvalue2 = value2;
    return 0;
unpacking_failed:
    if (!has_known_size && __Pyx_IterFinish() == 0)
        __Pyx_RaiseNeedMoreValuesError(index);
bad:
    Py_XDECREF(iter);
    Py_XDECREF(value1);
    Py_XDECREF(value2);
    if (decref_tuple) { Py_XDECREF(tuple); }
    return -1;
}


static CYTHON_INLINE PyObject* __Pyx_dict_iterator(PyObject* iterable, int is_dict, PyObject* method_name,
                                                   Py_ssize_t* p_orig_length, int* p_source_is_dict) {
    is_dict = is_dict || likely(PyDict_CheckExact(iterable));
    *p_source_is_dict = is_dict;
    if (is_dict) {
#if !CYTHON_COMPILING_IN_PYPY
        *p_orig_length = PyDict_Size(iterable);
        Py_INCREF(iterable);
        return iterable;
#elif PY_MAJOR_VERSION >= 3
        static PyObject *py_items = NULL, *py_keys = NULL, *py_values = NULL;
        PyObject **pp = NULL;
        if (method_name) {
            const char *name = PyUnicode_AsUTF8(method_name);
            if (strcmp(name, "iteritems") == 0) pp = &py_items;
            else if (strcmp(name, "iterkeys") == 0) pp = &py_keys;
            else if (strcmp(name, "itervalues") == 0) pp = &py_values;
            if (pp) {
                if (!*pp) {
                    *pp = PyUnicode_FromString(name + 4);
                    if (!*pp)
                        return NULL;
                }
                method_name = *pp;
            }
        }
#endif
    }
    *p_orig_length = 0;
    if (method_name) {
        PyObject* iter;
        iterable = __Pyx_PyObject_CallMethod0(iterable, method_name);
        if (!iterable)
            return NULL;
#if !CYTHON_COMPILING_IN_PYPY
        if (PyTuple_CheckExact(iterable) || PyList_CheckExact(iterable))
            return iterable;
#endif
        iter = PyObject_GetIter(iterable);
        Py_DECREF(iterable);
        return iter;
    }
    return PyObject_GetIter(iterable);
}
static CYTHON_INLINE int __Pyx_dict_iter_next(
        PyObject* iter_obj, CYTHON_NCP_UNUSED Py_ssize_t orig_length, CYTHON_NCP_UNUSED Py_ssize_t* ppos,
        PyObject** pkey, PyObject** pvalue, PyObject** pitem, int source_is_dict) {
    PyObject* next_item;
#if !CYTHON_COMPILING_IN_PYPY
    if (source_is_dict) {
        PyObject *key, *value;
        if (unlikely(orig_length != PyDict_Size(iter_obj))) {
            PyErr_SetString(PyExc_RuntimeError, "dictionary changed size during iteration");
            return -1;
        }
        if (unlikely(!PyDict_Next(iter_obj, ppos, &key, &value))) {
            return 0;
        }
        if (pitem) {
            PyObject* tuple = PyTuple_New(2);
            if (unlikely(!tuple)) {
                return -1;
            }
            Py_INCREF(key);
            Py_INCREF(value);
            PyTuple_SET_ITEM(tuple, 0, key);
            PyTuple_SET_ITEM(tuple, 1, value);
            *pitem = tuple;
        } else {
            if (pkey) {
                Py_INCREF(key);
                *pkey = key;
            }
            if (pvalue) {
                Py_INCREF(value);
                *pvalue = value;
            }
        }
        return 1;
    } else if (PyTuple_CheckExact(iter_obj)) {
        Py_ssize_t pos = *ppos;
        if (unlikely(pos >= PyTuple_GET_SIZE(iter_obj))) return 0;
        *ppos = pos + 1;
        next_item = PyTuple_GET_ITEM(iter_obj, pos);
        Py_INCREF(next_item);
    } else if (PyList_CheckExact(iter_obj)) {
        Py_ssize_t pos = *ppos;
        if (unlikely(pos >= PyList_GET_SIZE(iter_obj))) return 0;
        *ppos = pos + 1;
        next_item = PyList_GET_ITEM(iter_obj, pos);
        Py_INCREF(next_item);
    } else
#endif
    {
        next_item = PyIter_Next(iter_obj);
        if (unlikely(!next_item)) {
            return __Pyx_IterFinish();
        }
    }
    if (pitem) {
        *pitem = next_item;
    } else if (pkey && pvalue) {
        if (__Pyx_unpack_tuple2(next_item, pkey, pvalue, source_is_dict, source_is_dict, 1))
            return -1;
    } else if (pkey) {
        *pkey = next_item;
    } else {
        *pvalue = next_item;
    }
    return 1;
}


static int __Pyx_CheckKeywordStrings(
    PyObject *kwdict,
    const char* function_name,
    int kw_allowed)
{
    PyObject* key = 0;
    Py_ssize_t pos = 0;
#if CYTHON_COMPILING_IN_PYPY
    if (!kw_allowed && PyDict_Next(kwdict, &pos, &key, 0))
        goto invalid_keyword;
    return 1;
#else
    while (PyDict_Next(kwdict, &pos, &key, 0)) {
        #if PY_MAJOR_VERSION < 3
        if (unlikely(!PyString_Check(key)))
        #endif
            if (unlikely(!PyUnicode_Check(key)))
                goto invalid_keyword_type;
    }
    if ((!kw_allowed) && unlikely(key))
        goto invalid_keyword;
    return 1;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    return 0;
#endif
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
    return 0;
}


static PyObject *__Pyx_CalculateMetaclass(PyTypeObject *metaclass, PyObject *bases) {
    Py_ssize_t i, nbases = PyTuple_GET_SIZE(bases);
    for (i=0; i < nbases; i++) {
        PyTypeObject *tmptype;
        PyObject *tmp = PyTuple_GET_ITEM(bases, i);
        tmptype = Py_TYPE(tmp);
#if PY_MAJOR_VERSION < 3
        if (tmptype == &PyClass_Type)
            continue;
#endif
        if (!metaclass) {
            metaclass = tmptype;
            continue;
        }
        if (PyType_IsSubtype(metaclass, tmptype))
            continue;
        if (PyType_IsSubtype(tmptype, metaclass)) {
            metaclass = tmptype;
            continue;
        }
        PyErr_SetString(PyExc_TypeError,
                        "metaclass conflict: "
                        "the metaclass of a derived class "
                        "must be a (non-strict) subclass "
                        "of the metaclasses of all its bases");
        return NULL;
    }
    if (!metaclass) {
#if PY_MAJOR_VERSION < 3
        metaclass = &PyClass_Type;
#else
        metaclass = &PyType_Type;
#endif
    }
    Py_INCREF((PyObject*) metaclass);
    return (PyObject*) metaclass;
}


static PyObject *__Pyx_Py3MetaclassPrepare(PyObject *metaclass, PyObject *bases, PyObject *name,
                                           PyObject *qualname, PyObject *mkw, PyObject *modname, PyObject *doc) {
    PyObject *ns;
    if (metaclass) {
        PyObject *prep = __Pyx_PyObject_GetAttrStr(metaclass, __pyx_n_s_prepare);
        if (prep) {
            PyObject *pargs = PyTuple_Pack(2, name, bases);
            if (unlikely(!pargs)) {
                Py_DECREF(prep);
                return NULL;
            }
            ns = PyObject_Call(prep, pargs, mkw);
            Py_DECREF(prep);
            Py_DECREF(pargs);
        } else {
            if (unlikely(!PyErr_ExceptionMatches(PyExc_AttributeError)))
                return NULL;
            PyErr_Clear();
            ns = PyDict_New();
        }
    } else {
        ns = PyDict_New();
    }
    if (unlikely(!ns))
        return NULL;
    if (unlikely(PyObject_SetItem(ns, __pyx_n_s_module, modname) < 0)) goto bad;
    if (unlikely(PyObject_SetItem(ns, __pyx_n_s_qualname, qualname) < 0)) goto bad;
    if (unlikely(doc && PyObject_SetItem(ns, __pyx_n_s_doc, doc) < 0)) goto bad;
    return ns;
bad:
    Py_DECREF(ns);
    return NULL;
}
static PyObject *__Pyx_Py3ClassCreate(PyObject *metaclass, PyObject *name, PyObject *bases,
                                      PyObject *dict, PyObject *mkw,
                                      int calculate_metaclass, int allow_py2_metaclass) {
    PyObject *result, *margs;
    PyObject *owned_metaclass = NULL;
    if (allow_py2_metaclass) {
        owned_metaclass = PyObject_GetItem(dict, __pyx_n_s_metaclass);
        if (owned_metaclass) {
            metaclass = owned_metaclass;
        } else if (likely(PyErr_ExceptionMatches(PyExc_KeyError))) {
            PyErr_Clear();
        } else {
            return NULL;
        }
    }
    if (calculate_metaclass && (!metaclass || PyType_Check(metaclass))) {
        metaclass = __Pyx_CalculateMetaclass((PyTypeObject*) metaclass, bases);
        Py_XDECREF(owned_metaclass);
        if (unlikely(!metaclass))
            return NULL;
        owned_metaclass = metaclass;
    }
    margs = PyTuple_Pack(3, name, bases, dict);
    if (unlikely(!margs)) {
        result = NULL;
    } else {
        result = PyObject_Call(metaclass, margs, mkw);
        Py_DECREF(margs);
    }
    Py_XDECREF(owned_metaclass);
    return result;
}


static CYTHON_INLINE PyObject* __Pyx_PyExec2(PyObject* o, PyObject* globals) {
    return __Pyx_PyExec3(o, globals, NULL);
}
static PyObject* __Pyx_PyExec3(PyObject* o, PyObject* globals, PyObject* locals) {
    PyObject* result;
    PyObject* s = 0;
    char *code = 0;
    if (!globals || globals == Py_None) {
        globals = __pyx_d;
    } else if (!PyDict_Check(globals)) {
        PyErr_Format(PyExc_TypeError, "exec() arg 2 must be a dict, not %.200s",
                     Py_TYPE(globals)->tp_name);
        goto bad;
    }
    if (!locals || locals == Py_None) {
        locals = globals;
    }
    if (__Pyx_PyDict_GetItemStr(globals, __pyx_n_s_builtins_2) == NULL) {
        if (PyDict_SetItem(globals, __pyx_n_s_builtins_2, PyEval_GetBuiltins()) < 0)
            goto bad;
    }
    if (PyCode_Check(o)) {
        if (__Pyx_PyCode_HasFreeVars((PyCodeObject *)o)) {
            PyErr_SetString(PyExc_TypeError,
                "code object passed to exec() may not contain free variables");
            goto bad;
        }
        #if CYTHON_COMPILING_IN_PYPY || PY_VERSION_HEX < 0x030200B1
        result = PyEval_EvalCode((PyCodeObject *)o, globals, locals);
        #else
        result = PyEval_EvalCode(o, globals, locals);
        #endif
    } else {
        PyCompilerFlags cf;
        cf.cf_flags = 0;
#if PY_VERSION_HEX >= 0x030800A3
        cf.cf_feature_version = PY_MINOR_VERSION;
#endif
        if (PyUnicode_Check(o)) {
            cf.cf_flags = PyCF_SOURCE_IS_UTF8;
            s = PyUnicode_AsUTF8String(o);
            if (!s) goto bad;
            o = s;
        #if PY_MAJOR_VERSION >= 3
        } else if (!PyBytes_Check(o)) {
        #else
        } else if (!PyString_Check(o)) {
        #endif
            PyErr_Format(PyExc_TypeError,
                "exec: arg 1 must be string, bytes or code object, got %.200s",
                Py_TYPE(o)->tp_name);
            goto bad;
        }
        #if PY_MAJOR_VERSION >= 3
        code = PyBytes_AS_STRING(o);
        #else
        code = PyString_AS_STRING(o);
        #endif
        if (PyEval_MergeCompilerFlags(&cf)) {
            result = PyRun_StringFlags(code, Py_file_input, globals, locals, &cf);
        } else {
            result = PyRun_String(code, Py_file_input, globals, locals);
        }
        Py_XDECREF(s);
    }
    return result;
bad:
    Py_XDECREF(s);
    return 0;
}


static CYTHON_INLINE Py_UCS4 __Pyx_PyUnicode_AsPy_UCS4(PyObject* x) {
   Py_ssize_t length;
   #if CYTHON_PEP393_ENABLED
   length = PyUnicode_GET_LENGTH(x);
   if (likely(length == 1)) {
       return PyUnicode_READ_CHAR(x, 0);
   }
   #else
   length = PyUnicode_GET_SIZE(x);
   if (likely(length == 1)) {
       return PyUnicode_AS_UNICODE(x)[0];
   }
   #if Py_UNICODE_SIZE == 2
   else if (PyUnicode_GET_SIZE(x) == 2) {
       Py_UCS4 high_val = PyUnicode_AS_UNICODE(x)[0];
       if (high_val >= 0xD800 && high_val <= 0xDBFF) {
           Py_UCS4 low_val = PyUnicode_AS_UNICODE(x)[1];
           if (low_val >= 0xDC00 && low_val <= 0xDFFF) {
               return 0x10000 + (((high_val & ((1<<10)-1)) << 10) | (low_val & ((1<<10)-1)));
           }
       }
   }
   #endif
   #endif
   PyErr_Format(PyExc_ValueError,
                "only single character unicode strings can be converted to Py_UCS4, "
                "got length %" CYTHON_FORMAT_SSIZE_T "d", length);
   return (Py_UCS4)-1;
}


static long __Pyx__PyObject_Ord(PyObject* c) {
    Py_ssize_t size;
    if (PyBytes_Check(c)) {
        size = PyBytes_GET_SIZE(c);
        if (likely(size == 1)) {
            return (unsigned char) PyBytes_AS_STRING(c)[0];
        }
#if PY_MAJOR_VERSION < 3
    } else if (PyUnicode_Check(c)) {
        return (long)__Pyx_PyUnicode_AsPy_UCS4(c);
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    } else if (PyByteArray_Check(c)) {
        size = PyByteArray_GET_SIZE(c);
        if (likely(size == 1)) {
            return (unsigned char) PyByteArray_AS_STRING(c)[0];
        }
#endif
    } else {
        PyErr_Format(PyExc_TypeError,
            "ord() expected string of length 1, but %.200s found", Py_TYPE(c)->tp_name);
        return (long)(Py_UCS4)-1;
    }
    PyErr_Format(PyExc_TypeError,
        "ord() expected a character, but string of length %zd found", size);
    return (long)(Py_UCS4)-1;
}


#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject *__Pyx_RaiseGenericGetAttributeError(PyTypeObject *tp, PyObject *attr_name) {
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, attr_name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(attr_name));
#endif
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name) {
    PyObject *descr;
    PyTypeObject *tp = Py_TYPE(obj);
    if (unlikely(!PyString_Check(attr_name))) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    assert(!tp->tp_dictoffset);
    descr = _PyType_Lookup(tp, attr_name);
    if (unlikely(!descr)) {
        return __Pyx_RaiseGenericGetAttributeError(tp, attr_name);
    }
    Py_INCREF(descr);
    #if PY_MAJOR_VERSION < 3
    if (likely(PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)))
    #endif
    {
        descrgetfunc f = Py_TYPE(descr)->tp_descr_get;
        if (unlikely(f)) {
            PyObject *res = f(descr, obj, (PyObject *)tp);
            Py_DECREF(descr);
            return res;
        }
    }
    return descr;
}
#endif


static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}


static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name) {
    PyObject* value = __Pyx_PyObject_GetAttrStr(module, name);
    if (unlikely(!value) && PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Format(PyExc_ImportError,
        #if PY_MAJOR_VERSION < 3
            "cannot import name %.230s", PyString_AS_STRING(name));
        #else
            "cannot import name %S", name);
        #endif
    }
    return value;
}


#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_NCP_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif


static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}


#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        __pyx_empty_tuple, 
        py_srcfile,   
        py_funcname,  
        py_line,
        __pyx_empty_bytes  
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            
        py_code,           
        __pyx_d,    
        0                  
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}


#ifdef __FreeBSD__
#include <floatingpoint.h>
#endif
#if PY_MAJOR_VERSION < 3
int main(int argc, char** argv) {
#elif defined(WIN32) || defined(MS_WINDOWS)
int wmain(int argc, wchar_t **argv) {
#else
static int __Pyx_main(int argc, wchar_t **argv) {
#endif
    
#ifdef __FreeBSD__
    fp_except_t m;
    m = fpgetmask();
    fpsetmask(m & ~FP_X_OFL);
#endif
    if (argc && argv)
        Py_SetProgramName(argv[0]);
    Py_Initialize();
    if (argc && argv)
        PySys_SetArgv(argc, argv);
    {
      PyObject* m = NULL;
      __pyx_module_is_main_decode = 1;
      #if PY_MAJOR_VERSION < 3
          initdecode();
      #elif CYTHON_PEP489_MULTI_PHASE_INIT
          m = PyInit_decode();
          if (!PyModule_Check(m)) {
              PyModuleDef *mdef = (PyModuleDef *) m;
              PyObject *modname = PyUnicode_FromString("__main__");
              m = NULL;
              if (modname) {
                  m = PyModule_NewObject(modname);
                  Py_DECREF(modname);
                  if (m) PyModule_ExecDef(m, mdef);
              }
          }
      #else
          m = PyInit_decode();
      #endif
      if (PyErr_Occurred()) {
          PyErr_Print();
          #if PY_MAJOR_VERSION < 3
          if (Py_FlushLine()) PyErr_Clear();
          #endif
          return 1;
      }
      Py_XDECREF(m);
    }
#if PY_VERSION_HEX < 0x03060000
    Py_Finalize();
#else
    if (Py_FinalizeEx() < 0)
        return 2;
#endif
    return 0;
}
#if PY_MAJOR_VERSION >= 3 && !defined(WIN32) && !defined(MS_WINDOWS)
#include <locale.h>
static wchar_t*
__Pyx_char2wchar(char* arg)
{
    wchar_t *res;
#ifdef HAVE_BROKEN_MBSTOWCS
    
    size_t argsize = strlen(arg);
#else
    size_t argsize = mbstowcs(NULL, arg, 0);
#endif
    size_t count;
    unsigned char *in;
    wchar_t *out;
#ifdef HAVE_MBRTOWC
    mbstate_t mbs;
#endif
    if (argsize != (size_t)-1) {
        res = (wchar_t *)malloc((argsize+1)*sizeof(wchar_t));
        if (!res)
            goto oom;
        count = mbstowcs(res, arg, argsize+1);
        if (count != (size_t)-1) {
            wchar_t *tmp;
            
            for (tmp = res; *tmp != 0 &&
                     (*tmp < 0xd800 || *tmp > 0xdfff); tmp++)
                ;
            if (*tmp == 0)
                return res;
        }
        free(res);
    }
#ifdef HAVE_MBRTOWC
    
    argsize = strlen(arg) + 1;
    res = (wchar_t *)malloc(argsize*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    memset(&mbs, 0, sizeof mbs);
    while (argsize) {
        size_t converted = mbrtowc(out, (char*)in, argsize, &mbs);
        if (converted == 0)
            break;
        if (converted == (size_t)-2) {
            
            fprintf(stderr, "unexpected mbrtowc result -2\\n");
            free(res);
            return NULL;
        }
        if (converted == (size_t)-1) {
            
            *out++ = 0xdc00 + *in++;
            argsize--;
            memset(&mbs, 0, sizeof mbs);
            continue;
        }
        if (*out >= 0xd800 && *out <= 0xdfff) {
            
            argsize -= converted;
            while (converted--)
                *out++ = 0xdc00 + *in++;
            continue;
        }
        in += converted;
        argsize -= converted;
        out++;
    }
#else
    
    res = (wchar_t *)malloc((strlen(arg)+1)*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    while(*in)
        if(*in < 128)
            *out++ = *in++;
        else
            *out++ = 0xdc00 + *in++;
    *out = 0;
#endif
    return res;
oom:
    fprintf(stderr, "out of memory\\n");
    return NULL;
}
int
main(int argc, char **argv)
{
    if (!argc) {
        return __Pyx_main(0, NULL);
    }
    else {
        int i, res;
        wchar_t **argv_copy = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        wchar_t **argv_copy2 = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        char *oldloc = strdup(setlocale(LC_ALL, NULL));
        if (!argv_copy || !argv_copy2 || !oldloc) {
            fprintf(stderr, "out of memory\\n");
            free(argv_copy);
            free(argv_copy2);
            free(oldloc);
            return 1;
        }
        res = 0;
        setlocale(LC_ALL, "");
        for (i = 0; i < argc; i++) {
            argv_copy2[i] = argv_copy[i] = __Pyx_char2wchar(argv[i]);
            if (!argv_copy[i]) res = 1;
        }
        setlocale(LC_ALL, oldloc);
        free(oldloc);
        if (res == 0)
            res = __Pyx_main(argc, argv_copy);
        for (i = 0; i < argc; i++) {
#if PY_VERSION_HEX < 0x03050000
            free(argv_copy2[i]);
#else
            PyMem_RawFree(argv_copy2[i]);
#endif
        }
        free(argv_copy);
        free(argv_copy2);
        return res;
    }
}
#endif


    static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}


    static PyObject* __Pyx_Globals(void) {
    Py_ssize_t i;
    PyObject *names;
    PyObject *globals = __pyx_d;
    Py_INCREF(globals);
    names = PyObject_Dir(__pyx_m);
    if (!names)
        goto bad;
    for (i = PyList_GET_SIZE(names)-1; i >= 0; i--) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject* name = PySequence_ITEM(names, i);
        if (!name)
            goto bad;
#else
        PyObject* name = PyList_GET_ITEM(names, i);
#endif
        if (!PyDict_Contains(globals, name)) {
            PyObject* value = __Pyx_GetAttr(__pyx_m, name);
            if (!value) {
#if CYTHON_COMPILING_IN_PYPY
                Py_DECREF(name);
#endif
                goto bad;
            }
            if (PyDict_SetItem(globals, name, value) < 0) {
#if CYTHON_COMPILING_IN_PYPY
                Py_DECREF(name);
#endif
                Py_DECREF(value);
                goto bad;
            }
        }
#if CYTHON_COMPILING_IN_PYPY
        Py_DECREF(name);
#endif
    }
    Py_DECREF(names);
    return globals;
bad:
    Py_XDECREF(names);
    Py_XDECREF(globals);
    return NULL;
}


    #define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }


    static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const long neg_one = (long) -1, const_zero = (long) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}


    static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    const int neg_one = (int) -1, const_zero = (int) 0;
#ifdef __Pyx_HAS_GCC_DIAGNOSTIC
#pragma GCC diagnostic pop
#endif
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}


    #if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif


    static PyObject* __Pyx__PyObject_CallMethod1(PyObject* method, PyObject* arg) {
    PyObject *result = __Pyx_PyObject_CallOneArg(method, arg);
    Py_DECREF(method);
    return result;
}
static PyObject* __Pyx_PyObject_CallMethod1(PyObject* obj, PyObject* method_name, PyObject* arg) {
    PyObject *method = NULL, *result;
    int is_method = __Pyx_PyObject_GetMethod(obj, method_name, &method);
    if (likely(is_method)) {
        result = __Pyx_PyObject_Call2Args(method, obj, arg);
        Py_DECREF(method);
        return result;
    }
    if (unlikely(!method)) return NULL;
    return __Pyx__PyObject_CallMethod1(method, arg);
}


    #include <structmember.h>
#include <frameobject.h>
#define __Pyx_Coroutine_Undelegate(gen) Py_CLEAR((gen)->yieldfrom)
static int __Pyx_PyGen__FetchStopIterationValue(CYTHON_UNUSED PyThreadState *__pyx_tstate, PyObject **pvalue) {
    PyObject *et, *ev, *tb;
    PyObject *value = NULL;
    __Pyx_ErrFetch(&et, &ev, &tb);
    if (!et) {
        Py_XDECREF(tb);
        Py_XDECREF(ev);
        Py_INCREF(Py_None);
        *pvalue = Py_None;
        return 0;
    }
    if (likely(et == PyExc_StopIteration)) {
        if (!ev) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#if PY_VERSION_HEX >= 0x030300A0
        else if (Py_TYPE(ev) == (PyTypeObject*)PyExc_StopIteration) {
            value = ((PyStopIterationObject *)ev)->value;
            Py_INCREF(value);
            Py_DECREF(ev);
        }
#endif
        else if (unlikely(PyTuple_Check(ev))) {
            if (PyTuple_GET_SIZE(ev) >= 1) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                value = PyTuple_GET_ITEM(ev, 0);
                Py_INCREF(value);
#else
                value = PySequence_ITEM(ev, 0);
#endif
            } else {
                Py_INCREF(Py_None);
                value = Py_None;
            }
            Py_DECREF(ev);
        }
        else if (!__Pyx_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration)) {
            value = ev;
        }
        if (likely(value)) {
            Py_XDECREF(tb);
            Py_DECREF(et);
            *pvalue = value;
            return 0;
        }
    } else if (!__Pyx_PyErr_GivenExceptionMatches(et, PyExc_StopIteration)) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    PyErr_NormalizeException(&et, &ev, &tb);
    if (unlikely(!PyObject_TypeCheck(ev, (PyTypeObject*)PyExc_StopIteration))) {
        __Pyx_ErrRestore(et, ev, tb);
        return -1;
    }
    Py_XDECREF(tb);
    Py_DECREF(et);
#if PY_VERSION_HEX >= 0x030300A0
    value = ((PyStopIterationObject *)ev)->value;
    Py_INCREF(value);
    Py_DECREF(ev);
#else
    {
        PyObject* args = __Pyx_PyObject_GetAttrStr(ev, __pyx_n_s_args);
        Py_DECREF(ev);
        if (likely(args)) {
            value = PySequence_GetItem(args, 0);
            Py_DECREF(args);
        }
        if (unlikely(!value)) {
            __Pyx_ErrRestore(NULL, NULL, NULL);
            Py_INCREF(Py_None);
            value = Py_None;
        }
    }
#endif
    *pvalue = value;
    return 0;
}
static CYTHON_INLINE
void __Pyx_Coroutine_ExceptionClear(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *t, *v, *tb;
    t = exc_state->exc_type;
    v = exc_state->exc_value;
    tb = exc_state->exc_traceback;
    exc_state->exc_type = NULL;
    exc_state->exc_value = NULL;
    exc_state->exc_traceback = NULL;
    Py_XDECREF(t);
    Py_XDECREF(v);
    Py_XDECREF(tb);
}
#define __Pyx_Coroutine_AlreadyRunningError(gen)  (__Pyx__Coroutine_AlreadyRunningError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyRunningError(CYTHON_UNUSED __pyx_CoroutineObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check((PyObject*)gen)) {
        msg = "coroutine already executing";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact((PyObject*)gen)) {
        msg = "async generator already executing";
    #endif
    } else {
        msg = "generator already executing";
    }
    PyErr_SetString(PyExc_ValueError, msg);
}
#define __Pyx_Coroutine_NotStartedError(gen)  (__Pyx__Coroutine_NotStartedError(gen), (PyObject*)NULL)
static void __Pyx__Coroutine_NotStartedError(CYTHON_UNUSED PyObject *gen) {
    const char *msg;
    if ((0)) {
    #ifdef __Pyx_Coroutine_USED
    } else if (__Pyx_Coroutine_Check(gen)) {
        msg = "can't send non-None value to a just-started coroutine";
    #endif
    #ifdef __Pyx_AsyncGen_USED
    } else if (__Pyx_AsyncGen_CheckExact(gen)) {
        msg = "can't send non-None value to a just-started async generator";
    #endif
    } else {
        msg = "can't send non-None value to a just-started generator";
    }
    PyErr_SetString(PyExc_TypeError, msg);
}
#define __Pyx_Coroutine_AlreadyTerminatedError(gen, value, closing)  (__Pyx__Coroutine_AlreadyTerminatedError(gen, value, closing), (PyObject*)NULL)
static void __Pyx__Coroutine_AlreadyTerminatedError(CYTHON_UNUSED PyObject *gen, PyObject *value, CYTHON_UNUSED int closing) {
    #ifdef __Pyx_Coroutine_USED
    if (!closing && __Pyx_Coroutine_Check(gen)) {
        PyErr_SetString(PyExc_RuntimeError, "cannot reuse already awaited coroutine");
    } else
    #endif
    if (value) {
        #ifdef __Pyx_AsyncGen_USED
        if (__Pyx_AsyncGen_CheckExact(gen))
            PyErr_SetNone(__Pyx_PyExc_StopAsyncIteration);
        else
        #endif
        PyErr_SetNone(PyExc_StopIteration);
    }
}
static
PyObject *__Pyx_Coroutine_SendEx(__pyx_CoroutineObject *self, PyObject *value, int closing) {
    __Pyx_PyThreadState_declare
    PyThreadState *tstate;
    __Pyx_ExcInfoStruct *exc_state;
    PyObject *retval;
    assert(!self->is_running);
    if (unlikely(self->resume_label == 0)) {
        if (unlikely(value && value != Py_None)) {
            return __Pyx_Coroutine_NotStartedError((PyObject*)self);
        }
    }
    if (unlikely(self->resume_label == -1)) {
        return __Pyx_Coroutine_AlreadyTerminatedError((PyObject*)self, value, closing);
    }
#if CYTHON_FAST_THREAD_STATE
    __Pyx_PyThreadState_assign
    tstate = __pyx_tstate;
#else
    tstate = __Pyx_PyThreadState_Current;
#endif
    exc_state = &self->gi_exc_state;
    if (exc_state->exc_type) {
        #if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
        #else
        if (exc_state->exc_traceback) {
            PyTracebackObject *tb = (PyTracebackObject *) exc_state->exc_traceback;
            PyFrameObject *f = tb->tb_frame;
            Py_XINCREF(tstate->frame);
            assert(f->f_back == NULL);
            f->f_back = tstate->frame;
        }
        #endif
    }
#if CYTHON_USE_EXC_INFO_STACK
    exc_state->previous_item = tstate->exc_info;
    tstate->exc_info = exc_state;
#else
    if (exc_state->exc_type) {
        __Pyx_ExceptionSwap(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    } else {
        __Pyx_Coroutine_ExceptionClear(exc_state);
        __Pyx_ExceptionSave(&exc_state->exc_type, &exc_state->exc_value, &exc_state->exc_traceback);
    }
#endif
    self->is_running = 1;
    retval = self->body((PyObject *) self, tstate, value);
    self->is_running = 0;
#if CYTHON_USE_EXC_INFO_STACK
    exc_state = &self->gi_exc_state;
    tstate->exc_info = exc_state->previous_item;
    exc_state->previous_item = NULL;
    __Pyx_Coroutine_ResetFrameBackpointer(exc_state);
#endif
    return retval;
}
static CYTHON_INLINE void __Pyx_Coroutine_ResetFrameBackpointer(__Pyx_ExcInfoStruct *exc_state) {
    PyObject *exc_tb = exc_state->exc_traceback;
    if (likely(exc_tb)) {
#if CYTHON_COMPILING_IN_PYPY || CYTHON_COMPILING_IN_PYSTON
#else
        PyTracebackObject *tb = (PyTracebackObject *) exc_tb;
        PyFrameObject *f = tb->tb_frame;
        Py_CLEAR(f->f_back);
#endif
    }
}
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_MethodReturn(CYTHON_UNUSED PyObject* gen, PyObject *retval) {
    if (unlikely(!retval)) {
        __Pyx_PyThreadState_declare
        __Pyx_PyThreadState_assign
        if (!__Pyx_PyErr_Occurred()) {
            PyObject *exc = PyExc_StopIteration;
            #ifdef __Pyx_AsyncGen_USED
            if (__Pyx_AsyncGen_CheckExact(gen))
                exc = __Pyx_PyExc_StopAsyncIteration;
            #endif
            __Pyx_PyErr_SetNone(exc);
        }
    }
    return retval;
}
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
static CYTHON_INLINE
PyObject *__Pyx_PyGen_Send(PyGenObject *gen, PyObject *arg) {
#if PY_VERSION_HEX <= 0x030A00A1
    return _PyGen_Send(gen, arg);
#else
    PyObject *result;
    if (PyIter_Send((PyObject*)gen, arg ? arg : Py_None, &result) == PYGEN_RETURN) {
        if (PyAsyncGen_CheckExact(gen)) {
            assert(result == Py_None);
            PyErr_SetNone(PyExc_StopAsyncIteration);
        }
        else if (result == Py_None) {
            PyErr_SetNone(PyExc_StopIteration);
        }
        else {
            _PyGen_SetStopIterationValue(result);
        }
        Py_CLEAR(result);
    }
    return result;
#endif
}
#endif
static CYTHON_INLINE
PyObject *__Pyx_Coroutine_FinishDelegation(__pyx_CoroutineObject *gen) {
    PyObject *ret;
    PyObject *val = NULL;
    __Pyx_Coroutine_Undelegate(gen);
    __Pyx_PyGen__FetchStopIterationValue(__Pyx_PyThreadState_Current, &val);
    ret = __Pyx_Coroutine_SendEx(gen, val, 0);
    Py_XDECREF(val);
    return ret;
}
static PyObject *__Pyx_Coroutine_Send(PyObject *self, PyObject *value) {
    PyObject *retval;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, value);
        } else
        #endif
        #ifdef __Pyx_AsyncGen_USED
        if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
            ret = __Pyx_async_gen_asend_send(yf, value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03050000 && defined(PyCoro_CheckExact) && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyCoro_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, value == Py_None ? NULL : value);
        } else
        #endif
        {
            if (value == Py_None)
                ret = Py_TYPE(yf)->tp_iternext(yf);
            else
                ret = __Pyx_PyObject_CallMethod1(yf, __pyx_n_s_send, value);
        }
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        retval = __Pyx_Coroutine_FinishDelegation(gen);
    } else {
        retval = __Pyx_Coroutine_SendEx(gen, value, 0);
    }
    return __Pyx_Coroutine_MethodReturn(self, retval);
}
static int __Pyx_Coroutine_CloseIter(__pyx_CoroutineObject *gen, PyObject *yf) {
    PyObject *retval = NULL;
    int err = 0;
    #ifdef __Pyx_Generator_USED
    if (__Pyx_Generator_CheckExact(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_Coroutine_USED
    if (__Pyx_Coroutine_Check(yf)) {
        retval = __Pyx_Coroutine_Close(yf);
        if (!retval)
            return -1;
    } else
    if (__Pyx_CoroutineAwait_CheckExact(yf)) {
        retval = __Pyx_CoroutineAwait_Close((__pyx_CoroutineAwaitObject*)yf, NULL);
        if (!retval)
            return -1;
    } else
    #endif
    #ifdef __Pyx_AsyncGen_USED
    if (__pyx_PyAsyncGenASend_CheckExact(yf)) {
        retval = __Pyx_async_gen_asend_close(yf, NULL);
    } else
    if (__pyx_PyAsyncGenAThrow_CheckExact(yf)) {
        retval = __Pyx_async_gen_athrow_close(yf, NULL);
    } else
    #endif
    {
        PyObject *meth;
        gen->is_running = 1;
        meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_close);
        if (unlikely(!meth)) {
            if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                PyErr_WriteUnraisable(yf);
            }
            PyErr_Clear();
        } else {
            retval = PyObject_CallFunction(meth, NULL);
            Py_DECREF(meth);
            if (!retval)
                err = -1;
        }
        gen->is_running = 0;
    }
    Py_XDECREF(retval);
    return err;
}
static PyObject *__Pyx_Generator_Next(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject*) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        gen->is_running = 1;
        #ifdef __Pyx_Generator_USED
        if (__Pyx_Generator_CheckExact(yf)) {
            ret = __Pyx_Generator_Next(yf);
        } else
        #endif
        #if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x03030000 && (defined(__linux__) || PY_VERSION_HEX >= 0x030600B3)
        if (PyGen_CheckExact(yf)) {
            ret = __Pyx_PyGen_Send((PyGenObject*)yf, NULL);
        } else
        #endif
        #ifdef __Pyx_Coroutine_USED
        if (__Pyx_Coroutine_Check(yf)) {
            ret = __Pyx_Coroutine_Send(yf, Py_None);
        } else
        #endif
            ret = Py_TYPE(yf)->tp_iternext(yf);
        gen->is_running = 0;
        if (likely(ret)) {
            return ret;
        }
        return __Pyx_Coroutine_FinishDelegation(gen);
    }
    return __Pyx_Coroutine_SendEx(gen, Py_None, 0);
}
static PyObject *__Pyx_Coroutine_Close_Method(PyObject *self, CYTHON_UNUSED PyObject *arg) {
    return __Pyx_Coroutine_Close(self);
}
static PyObject *__Pyx_Coroutine_Close(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *retval, *raised_exception;
    PyObject *yf = gen->yieldfrom;
    int err = 0;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        Py_INCREF(yf);
        err = __Pyx_Coroutine_CloseIter(gen, yf);
        __Pyx_Coroutine_Undelegate(gen);
        Py_DECREF(yf);
    }
    if (err == 0)
        PyErr_SetNone(PyExc_GeneratorExit);
    retval = __Pyx_Coroutine_SendEx(gen, NULL, 1);
    if (unlikely(retval)) {
        const char *msg;
        Py_DECREF(retval);
        if ((0)) {
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_Coroutine_Check(self)) {
            msg = "coroutine ignored GeneratorExit";
        #endif
        #ifdef __Pyx_AsyncGen_USED
        } else if (__Pyx_AsyncGen_CheckExact(self)) {
#if PY_VERSION_HEX < 0x03060000
            msg = "async generator ignored GeneratorExit - might require Python 3.6+ finalisation (PEP 525)";
#else
            msg = "async generator ignored GeneratorExit";
#endif
        #endif
        } else {
            msg = "generator ignored GeneratorExit";
        }
        PyErr_SetString(PyExc_RuntimeError, msg);
        return NULL;
    }
    raised_exception = PyErr_Occurred();
    if (likely(!raised_exception || __Pyx_PyErr_GivenExceptionMatches2(raised_exception, PyExc_GeneratorExit, PyExc_StopIteration))) {
        if (raised_exception) PyErr_Clear();
        Py_INCREF(Py_None);
        return Py_None;
    }
    return NULL;
}
static PyObject *__Pyx__Coroutine_Throw(PyObject *self, PyObject *typ, PyObject *val, PyObject *tb,
                                        PyObject *args, int close_on_genexit) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject *yf = gen->yieldfrom;
    if (unlikely(gen->is_running))
        return __Pyx_Coroutine_AlreadyRunningError(gen);
    if (yf) {
        PyObject *ret;
        Py_INCREF(yf);
        if (__Pyx_PyErr_GivenExceptionMatches(typ, PyExc_GeneratorExit) && close_on_genexit) {
            int err = __Pyx_Coroutine_CloseIter(gen, yf);
            Py_DECREF(yf);
            __Pyx_Coroutine_Undelegate(gen);
            if (err < 0)
                return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
            goto throw_here;
        }
        gen->is_running = 1;
        if (0
        #ifdef __Pyx_Generator_USED
            || __Pyx_Generator_CheckExact(yf)
        #endif
        #ifdef __Pyx_Coroutine_USED
            || __Pyx_Coroutine_Check(yf)
        #endif
            ) {
            ret = __Pyx__Coroutine_Throw(yf, typ, val, tb, args, close_on_genexit);
        #ifdef __Pyx_Coroutine_USED
        } else if (__Pyx_CoroutineAwait_CheckExact(yf)) {
            ret = __Pyx__Coroutine_Throw(((__pyx_CoroutineAwaitObject*)yf)->coroutine, typ, val, tb, args, close_on_genexit);
        #endif
        } else {
            PyObject *meth = __Pyx_PyObject_GetAttrStr(yf, __pyx_n_s_throw);
            if (unlikely(!meth)) {
                Py_DECREF(yf);
                if (!PyErr_ExceptionMatches(PyExc_AttributeError)) {
                    gen->is_running = 0;
                    return NULL;
                }
                PyErr_Clear();
                __Pyx_Coroutine_Undelegate(gen);
                gen->is_running = 0;
                goto throw_here;
            }
            if (likely(args)) {
                ret = PyObject_CallObject(meth, args);
            } else {
                ret = PyObject_CallFunctionObjArgs(meth, typ, val, tb, NULL);
            }
            Py_DECREF(meth);
        }
        gen->is_running = 0;
        Py_DECREF(yf);
        if (!ret) {
            ret = __Pyx_Coroutine_FinishDelegation(gen);
        }
        return __Pyx_Coroutine_MethodReturn(self, ret);
    }
throw_here:
    __Pyx_Raise(typ, val, tb, NULL);
    return __Pyx_Coroutine_MethodReturn(self, __Pyx_Coroutine_SendEx(gen, NULL, 0));
}
static PyObject *__Pyx_Coroutine_Throw(PyObject *self, PyObject *args) {
    PyObject *typ;
    PyObject *val = NULL;
    PyObject *tb = NULL;
    if (!PyArg_UnpackTuple(args, (char *)"throw", 1, 3, &typ, &val, &tb))
        return NULL;
    return __Pyx__Coroutine_Throw(self, typ, val, tb, args, 1);
}
static CYTHON_INLINE int __Pyx_Coroutine_traverse_excstate(__Pyx_ExcInfoStruct *exc_state, visitproc visit, void *arg) {
    Py_VISIT(exc_state->exc_type);
    Py_VISIT(exc_state->exc_value);
    Py_VISIT(exc_state->exc_traceback);
    return 0;
}
static int __Pyx_Coroutine_traverse(__pyx_CoroutineObject *gen, visitproc visit, void *arg) {
    Py_VISIT(gen->closure);
    Py_VISIT(gen->classobj);
    Py_VISIT(gen->yieldfrom);
    return __Pyx_Coroutine_traverse_excstate(&gen->gi_exc_state, visit, arg);
}
static int __Pyx_Coroutine_clear(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    Py_CLEAR(gen->closure);
    Py_CLEAR(gen->classobj);
    Py_CLEAR(gen->yieldfrom);
    __Pyx_Coroutine_ExceptionClear(&gen->gi_exc_state);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        Py_CLEAR(((__pyx_PyAsyncGenObject*)gen)->ag_finalizer);
    }
#endif
    Py_CLEAR(gen->gi_code);
    Py_CLEAR(gen->gi_frame);
    Py_CLEAR(gen->gi_name);
    Py_CLEAR(gen->gi_qualname);
    Py_CLEAR(gen->gi_modulename);
    return 0;
}
static void __Pyx_Coroutine_dealloc(PyObject *self) {
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    PyObject_GC_UnTrack(gen);
    if (gen->gi_weakreflist != NULL)
        PyObject_ClearWeakRefs(self);
    if (gen->resume_label >= 0) {
        PyObject_GC_Track(self);
#if PY_VERSION_HEX >= 0x030400a1 && CYTHON_USE_TP_FINALIZE
        if (PyObject_CallFinalizerFromDealloc(self))
#else
        Py_TYPE(gen)->tp_del(self);
        if (Py_REFCNT(self) > 0)
#endif
        {
            return;
        }
        PyObject_GC_UnTrack(self);
    }
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        
        Py_CLEAR(((__pyx_PyAsyncGenObject*)self)->ag_finalizer);
    }
#endif
    __Pyx_Coroutine_clear(self);
    PyObject_GC_Del(gen);
}
static void __Pyx_Coroutine_del(PyObject *self) {
    PyObject *error_type, *error_value, *error_traceback;
    __pyx_CoroutineObject *gen = (__pyx_CoroutineObject *) self;
    __Pyx_PyThreadState_declare
    if (gen->resume_label < 0) {
        return;
    }
#if !CYTHON_USE_TP_FINALIZE
    assert(self->ob_refcnt == 0);
    __Pyx_SET_REFCNT(self, 1);
#endif
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&error_type, &error_value, &error_traceback);
#ifdef __Pyx_AsyncGen_USED
    if (__Pyx_AsyncGen_CheckExact(self)) {
        __pyx_PyAsyncGenObject *agen = (__pyx_PyAsyncGenObject*)self;
        PyObject *finalizer = agen->ag_finalizer;
        if (finalizer && !agen->ag_closed) {
            PyObject *res = __Pyx_PyObject_CallOneArg(finalizer, self);
            if (unlikely(!res)) {
                PyErr_WriteUnraisable(self);
            } else {
                Py_DECREF(res);
            }
            __Pyx_ErrRestore(error_type, error_value, error_traceback);
            return;
        }
    }
#endif
    if (unlikely(gen->resume_label == 0 && !error_value)) {
#ifdef __Pyx_Coroutine_USED
#ifdef __Pyx_Generator_USED
    if (!__Pyx_Generator_CheckExact(self))
#endif
        {
        PyObject_GC_UnTrack(self);
#if PY_MAJOR_VERSION >= 3  || defined(PyErr_WarnFormat)
        if (unlikely(PyErr_WarnFormat(PyExc_RuntimeWarning, 1, "coroutine '%.50S' was never awaited", gen->gi_qualname) < 0))
            PyErr_WriteUnraisable(self);
#else
        {PyObject *msg;
        char *cmsg;
        #if CYTHON_COMPILING_IN_PYPY
        msg = NULL;
        cmsg = (char*) "coroutine was never awaited";
        #else
        char *cname;
        PyObject *qualname;
        qualname = gen->gi_qualname;
        cname = PyString_AS_STRING(qualname);
        msg = PyString_FromFormat("coroutine '%.50s' was never awaited", cname);
        if (unlikely(!msg)) {
            PyErr_Clear();
            cmsg = (char*) "coroutine was never awaited";
        } else {
            cmsg = PyString_AS_STRING(msg);
        }
        #endif
        if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, cmsg, 1) < 0))
            PyErr_WriteUnraisable(self);
        Py_XDECREF(msg);}
#endif
        PyObject_GC_Track(self);
        }
#endif
    } else {
        PyObject *res = __Pyx_Coroutine_Close(self);
        if (unlikely(!res)) {
            if (PyErr_Occurred())
                PyErr_WriteUnraisable(self);
        } else {
            Py_DECREF(res);
        }
    }
    __Pyx_ErrRestore(error_type, error_value, error_traceback);
#if !CYTHON_USE_TP_FINALIZE
    assert(Py_REFCNT(self) > 0);
    if (--self->ob_refcnt == 0) {
        return;
    }
    {
        Py_ssize_t refcnt = Py_REFCNT(self);
        _Py_NewReference(self);
        __Pyx_SET_REFCNT(self, refcnt);
    }
#if CYTHON_COMPILING_IN_CPYTHON
    assert(PyType_IS_GC(Py_TYPE(self)) &&
           _Py_AS_GC(self)->gc.gc_refs != _PyGC_REFS_UNTRACKED);
    _Py_DEC_REFTOTAL;
#endif
#ifdef COUNT_ALLOCS
    --Py_TYPE(self)->tp_frees;
    --Py_TYPE(self)->tp_allocs;
#endif
#endif
}
static PyObject *
__Pyx_Coroutine_get_name(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_name;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_name(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_name;
    Py_INCREF(value);
    self->gi_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_qualname(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *name = self->gi_qualname;
    if (unlikely(!name)) name = Py_None;
    Py_INCREF(name);
    return name;
}
static int
__Pyx_Coroutine_set_qualname(__pyx_CoroutineObject *self, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = self->gi_qualname;
    Py_INCREF(value);
    self->gi_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_Coroutine_get_frame(__pyx_CoroutineObject *self, CYTHON_UNUSED void *context)
{
    PyObject *frame = self->gi_frame;
    if (!frame) {
        if (unlikely(!self->gi_code)) {
            Py_RETURN_NONE;
        }
        frame = (PyObject *) PyFrame_New(
            PyThreadState_Get(),            
            (PyCodeObject*) self->gi_code,  
            __pyx_d,                 
            0                               
        );
        if (unlikely(!frame))
            return NULL;
        self->gi_frame = frame;
    }
    Py_INCREF(frame);
    return frame;
}
static __pyx_CoroutineObject *__Pyx__Coroutine_New(
            PyTypeObject* type, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    __pyx_CoroutineObject *gen = PyObject_GC_New(__pyx_CoroutineObject, type);
    if (unlikely(!gen))
        return NULL;
    return __Pyx__Coroutine_NewInit(gen, body, code, closure, name, qualname, module_name);
}
static __pyx_CoroutineObject *__Pyx__Coroutine_NewInit(
            __pyx_CoroutineObject *gen, __pyx_coroutine_body_t body, PyObject *code, PyObject *closure,
            PyObject *name, PyObject *qualname, PyObject *module_name) {
    gen->body = body;
    gen->closure = closure;
    Py_XINCREF(closure);
    gen->is_running = 0;
    gen->resume_label = 0;
    gen->classobj = NULL;
    gen->yieldfrom = NULL;
    gen->gi_exc_state.exc_type = NULL;
    gen->gi_exc_state.exc_value = NULL;
    gen->gi_exc_state.exc_traceback = NULL;
#if CYTHON_USE_EXC_INFO_STACK
    gen->gi_exc_state.previous_item = NULL;
#endif
    gen->gi_weakreflist = NULL;
    Py_XINCREF(qualname);
    gen->gi_qualname = qualname;
    Py_XINCREF(name);
    gen->gi_name = name;
    Py_XINCREF(module_name);
    gen->gi_modulename = module_name;
    Py_XINCREF(code);
    gen->gi_code = code;
    gen->gi_frame = NULL;
    PyObject_GC_Track(gen);
    return gen;
}


    static PyObject* __Pyx_Coroutine_patch_module(PyObject* module, const char* py_code) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    int result;
    PyObject *globals, *result_obj;
    globals = PyDict_New();  if (unlikely(!globals)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_coroutine_type",
    #ifdef __Pyx_Coroutine_USED
        (PyObject*)__pyx_CoroutineType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    result = PyDict_SetItemString(globals, "_cython_generator_type",
    #ifdef __Pyx_Generator_USED
        (PyObject*)__pyx_GeneratorType);
    #else
        Py_None);
    #endif
    if (unlikely(result < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "_module", module) < 0)) goto ignore;
    if (unlikely(PyDict_SetItemString(globals, "__builtins__", __pyx_b) < 0)) goto ignore;
    result_obj = PyRun_String(py_code, Py_file_input, globals, globals);
    if (unlikely(!result_obj)) goto ignore;
    Py_DECREF(result_obj);
    Py_DECREF(globals);
    return module;
ignore:
    Py_XDECREF(globals);
    PyErr_WriteUnraisable(module);
    if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning, "Cython module failed to patch module with custom type", 1) < 0)) {
        Py_DECREF(module);
        module = NULL;
    }
#else
    py_code++;
#endif
    return module;
}


    #ifndef CYTHON_REGISTER_ABCS
#define CYTHON_REGISTER_ABCS 1
#endif
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
static PyObject* __Pyx_patch_abc_module(PyObject *module);
static PyObject* __Pyx_patch_abc_module(PyObject *module) {
    module = __Pyx_Coroutine_patch_module(
        module, ""
"if _cython_generator_type is not None:\n"
"    try: Generator = _module.Generator\n"
"    except AttributeError: pass\n"
"    else: Generator.register(_cython_generator_type)\n"
"if _cython_coroutine_type is not None:\n"
"    try: Coroutine = _module.Coroutine\n"
"    except AttributeError: pass\n"
"    else: Coroutine.register(_cython_coroutine_type)\n"
    );
    return module;
}
#endif
static int __Pyx_patch_abc(void) {
#if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
    static int abc_patched = 0;
    if (CYTHON_REGISTER_ABCS && !abc_patched) {
        PyObject *module;
        module = PyImport_ImportModule((PY_MAJOR_VERSION >= 3) ? "collections.abc" : "collections");
        if (!module) {
            PyErr_WriteUnraisable(NULL);
            if (unlikely(PyErr_WarnEx(PyExc_RuntimeWarning,
                    ((PY_MAJOR_VERSION >= 3) ?
                        "Cython module failed to register with collections.abc module" :
                        "Cython module failed to register with collections module"), 1) < 0)) {
                return -1;
            }
        } else {
            module = __Pyx_patch_abc_module(module);
            abc_patched = 1;
            if (unlikely(!module))
                return -1;
            Py_DECREF(module);
        }
        module = PyImport_ImportModule("backports_abc");
        if (module) {
            module = __Pyx_patch_abc_module(module);
            Py_XDECREF(module);
        }
        if (!module) {
            PyErr_Clear();
        }
    }
#else
    if ((0)) __Pyx_Coroutine_patch_module(NULL, NULL);
#endif
    return 0;
}


    static PyMethodDef __pyx_Generator_methods[] = {
    {"send", (PyCFunction) __Pyx_Coroutine_Send, METH_O,
     (char*) PyDoc_STR("send(arg) -> send 'arg' into generator,\nreturn next yielded value or raise StopIteration.")},
    {"throw", (PyCFunction) __Pyx_Coroutine_Throw, METH_VARARGS,
     (char*) PyDoc_STR("throw(typ[,val[,tb]]) -> raise exception in generator,\nreturn next yielded value or raise StopIteration.")},
    {"close", (PyCFunction) __Pyx_Coroutine_Close_Method, METH_NOARGS,
     (char*) PyDoc_STR("close() -> raise GeneratorExit inside generator.")},
    {0, 0, 0, 0}
};
static PyMemberDef __pyx_Generator_memberlist[] = {
    {(char *) "gi_running", T_BOOL, offsetof(__pyx_CoroutineObject, is_running), READONLY, NULL},
    {(char*) "gi_yieldfrom", T_OBJECT, offsetof(__pyx_CoroutineObject, yieldfrom), READONLY,
     (char*) PyDoc_STR("object being iterated by 'yield from', or None")},
    {(char*) "gi_code", T_OBJECT, offsetof(__pyx_CoroutineObject, gi_code), READONLY, NULL},
    {0, 0, 0, 0, 0}
};
static PyGetSetDef __pyx_Generator_getsets[] = {
    {(char *) "__name__", (getter)__Pyx_Coroutine_get_name, (setter)__Pyx_Coroutine_set_name,
     (char*) PyDoc_STR("name of the generator"), 0},
    {(char *) "__qualname__", (getter)__Pyx_Coroutine_get_qualname, (setter)__Pyx_Coroutine_set_qualname,
     (char*) PyDoc_STR("qualified name of the generator"), 0},
    {(char *) "gi_frame", (getter)__Pyx_Coroutine_get_frame, NULL,
     (char*) PyDoc_STR("Frame of the generator"), 0},
    {0, 0, 0, 0, 0}
};
static PyTypeObject __pyx_GeneratorType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "generator",
    sizeof(__pyx_CoroutineObject),
    0,
    (destructor) __Pyx_Coroutine_dealloc,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC | Py_TPFLAGS_HAVE_FINALIZE,
    0,
    (traverseproc) __Pyx_Coroutine_traverse,
    0,
    0,
    offsetof(__pyx_CoroutineObject, gi_weakreflist),
    0,
    (iternextfunc) __Pyx_Generator_Next,
    __pyx_Generator_methods,
    __pyx_Generator_memberlist,
    __pyx_Generator_getsets,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if CYTHON_USE_TP_FINALIZE
    0,
#else
    __Pyx_Coroutine_del,
#endif
    0,
#if CYTHON_USE_TP_FINALIZE
    __Pyx_Coroutine_del,
#elif PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b4 && PY_VERSION_HEX < 0x03090000
    0,
#endif
};
static int __pyx_Generator_init(void) {
    __pyx_GeneratorType_type.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
    __pyx_GeneratorType_type.tp_iter = PyObject_SelfIter;
    __pyx_GeneratorType = __Pyx_FetchCommonType(&__pyx_GeneratorType_type);
    if (unlikely(!__pyx_GeneratorType)) {
        return -1;
    }
    return 0;
}


    static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}


    static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif 
