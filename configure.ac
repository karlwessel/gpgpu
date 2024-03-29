AC_INIT([gpgpu], [0.1], [karlroyen@posteo.net])

AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CC
AC_PROG_CXX
AC_OPENMP
AC_SUBST(AM_CFLAGS,"$OPENMP_CFLAGS")
AC_SUBST(AM_CXXFLAGS,"$OPENMP_CXXFLAGS")

AC_ARG_ENABLE([opencl],
    AS_HELP_STRING([--disable-opencl], [Disable feature OpenCL examples]))

AS_IF([test "x$enable_opencl" != "xno"], [
  AC_SEARCH_LIBS([clGetPlatformIDs], [OpenCL], [hasopencl=yes], [])
])
AM_CONDITIONAL([USE_OPENCL], [test "x$hasopencl" = "xyes"])

AC_CONFIG_FILES([
	Makefile])

AC_OUTPUT
