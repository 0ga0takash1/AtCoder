#################
#  Makefile  #
#################

## source, header, object and executable files
EXES 	= a b c d e f useful_func

## commands and options
CC      = gcc
PP      = g++
CFLAGS  =

## make rules
all:	$(EXES)

clean:
	rm -f $(EXES) a.out core *~

## suffix rules
.SUFFIXES: .cpp
.cpp.o:
	$(PP) $(CFLAGS) $<

## dependence of objejt, source and header files
