AUTOMAKE_OPTIONS = foreign

if WITH_FEATURE
FEATURE_H = Bar.h
FEATURE_CC = Bar.cc
else
FEATURE_H =
FEATURE_CC =
endif

libincludedir = $(includedir)/Template

lib_LTLIBRARIES = libTemplate.la

include_HEADERS = Template.h

libinclude_HEADERS = \
	Foo.h \
	$(FEATURE_H)

libTemplate_la_SOURCES = \
	Foo.h Foo.cc \
	$(FEATURE_H) $(FEATURE_CC)

libTemplate_la_LIBADD = \
	-lexternal_library \

noinst_PROGRAMS = helloworld
helloworld_SOURCES = helloworld.cc
helloworld_LDADD = -lTemplate
