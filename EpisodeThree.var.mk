# Makefiles common variables

PROJECT=OUTATIME
PROJECTPATH=$(realpath .)

CONFIG=Debug
#CONFIG=Release

BINDIR=bin
OUTDIR=$(BINDIR)/$(CONFIG)
INTDIR=$(OUTDIR)/out
EXEC=OUTATIME
OUTFILE=$(abspath $(OUTDIR))/$(EXEC)

INCLUDEDIRS=-I/usr/include -I/usr/local/include -I$(PROJECTPATH)/include
LIBDIRS=-L/usr/lib -L/usr/local/lib
LIBS=/usr/lib/libsfml-system.so /usr/lib/libsfml-window.so /usr/lib/libsfml-graphics.so /usr/lib/libsfml-audio.so \
/usr/local/lib/libtmxparser.so

CC=gcc
CXX=g++

CGLOBALFLAGS=-Wall -Wextra -fexceptions -std=c17 -pedantic
CXXGLOBALFLAGS=-fexceptions -std=c++17 -pedantic \
-Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wfloat-equal -Wwrite-strings -Wpointer-arith -Wcast-qual \
-Wcast-align -Wconversion -Wshadow -Wredundant-decls -Wdouble-promotion -Winit-self -Wswitch-default \
-Wswitch-enum -Wundef -Wlogical-op -Winline

LINKFLAGS=-m64

ifeq ($(CONFIG),Debug)
	CFLAGS=$(CGLOBALFLAGS) -g -O0 -m64
	CXXFLAGS=$(CXXGLOBALFLAGS) -g -O0 -m64
	DEFINES=-D_DEBUG
else ifeq ($(CONFIG),Release)
	CFLAGS=$(CGLOBALFLAGS) -O2 -m64
	CXXFLAGS=$(CXXGLOBALFLAGS) -O2 -m64
	DEFINES=
endif

#TODO PCH

# Find every .cpp file inside src/
SRC=$(notdir $(shell find src -name *.cpp))
OBJ=$(SRC:%.cpp=$(INTDIR)/%.o)
DEPS=$(SRC:%.cpp=$(INTDIR)/%.d)

# Configure VPATH as every absolute path of the project containing .cpps
VPATH=$(dir $(realpath $(shell find . -name *.cpp)))
