#################
#  Makefile  #
#################

## source, header, object and executable files
EXES = $(basename $(wildcard *.cpp) )

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
	$(PP) $(CFLAGS) -o $@

## dependence of objejt, source and header files
