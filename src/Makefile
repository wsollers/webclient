
CFLAGS=-std=c++23 -O3 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-private-field

# Debugging flags
NDEBUG=1

# Logging flags
VERBOSE_LOGGING=1

LDFLAGS= -D VERBOSE_LOGGING=$(VERBOSE_LOGGING) 

LIBS=-lssl -lcrypto

GCC=g++
CLANG=clang++

CURRENT_COMPILER=$(CLANG)

default: main

main: 
	$(CURRENT_COMPILER) $(CFLAGS) $(LDFLAGS) -o webclient main.cpp http/Connection.cpp $(LIBS)

clean:
	rm -f webclient

.PHONY: clean

test: main
	./webclient www.google.com
