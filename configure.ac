AC_INIT([Template], [v1.0.0], [dan.gordon@nicta.com.au], [Template])
AC_CONFIG_SRCDIR([src/helloworld.cc])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_ARG_WITH([feature],
            [AS_HELP_STRING([--with-feature], [use feature])],
            [],
            [with_feature=no])
AC_SUBST([with_feature])
AM_CONDITIONAL([WITH_FEATURE], [test x$with_feature = xyes])
AS_IF([test x$with_feature == xyes],
      [AC_DEFINE([WITH_FEATURE], [], [use feature])])

AC_PROG_CC([clang gcc])
AC_PROG_CXX([clang++ g++])
#AC_PROG_OBJCXX([clang]) # Unfortunately it is an autoconf error to make this macro conditional.

LT_INIT([disable-shared]) # disable-shared doesn't seem to be working: autoconf bug?

AC_LANG([C++])
AX_CXX_COMPILE_STDCXX_11([noext])
AX_CHECK_COMPILE_FLAG([-ftemplate-depth=160], [AM_CXXFLAGS="$AM_CXXFLAGS -ftemplate-depth=160"])
AC_SUBST([AM_CXXFLAGS], ["$AM_CXXFLAGS -Wall"])

# See above comments for AC_PROG_OBJCXX
#AC_LANG([Objective C++])
#AX_CHECK_COMPILE_FLAG([-std=c++11], [AC_SUBST([AM_OBJCXXFLAGS], ["-std=c++11"])])

AC_CHECK_PROG([HAVE_DOT], [dot], ["YES"], ["NO"])
AC_CHECK_PROGS([DOXYGEN], [doxygen])
AC_CHECK_PROGS([MAKEINDEX], [makeindex])
AC_CHECK_PROGS([PDFLATEX], [pdflatex])

if test -z "$DOXYGEN";
    then AC_MSG_WARN([Doxygen not found - continuing without Doxygen support])
fi
AM_CONDITIONAL([HAVE_DOXYGEN], [test -n "$DOXYGEN"])

if test -z "$PDFLATEX" || test -z "$MAKEINDEX";
    then AC_MSG_WARN([pdflatex and/or makeindex not found - continuing without pdflatex support])
fi
AM_CONDITIONAL([HAVE_PDFLATEX], [test -n "$PDFLATEX" && test -n "$MAKEINDEX"])

AC_CONFIG_HEADERS([Template/config.h])
AC_CONFIG_FILES([Makefile Template/Makefile src/Makefile tests/Makefile docs/Makefile])
AM_COND_IF(
           [HAVE_DOXYGEN],
           [AC_CONFIG_FILES([docs/Doxyfile])]
           )

AC_SUBST([AM_CPPFLAGS], ["$AM_CPPFLAGS -I.."])

AC_OUTPUT
