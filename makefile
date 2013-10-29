CC=g++-mp-4.8
CFLAGS=-std=c++11 -fPIC -Wall -I. -c
LDFLAGS=-std=c++11 -shared 
LDFLAGSEXTRA=-install_name @rpath/UtilityToolsInterfaces/lib/
OBJDIR=build
LIBDIR=lib

all: $(OBJDIR) $(LIBDIR) lib/libObjectHolder.so

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBDIR):
	mkdir $(LIBDIR) 

lib/libObjectHolder.so: build/SingleObjectHolder.o build/VectorObjectHolder.o
	$(CC) $(LDFLAGS) $(LDFLAGSEXTRA)libObjectHolder.so build/SingleObjectHolder.o build/VectorObjectHolder.o -o lib/libObjectHolder.so

build/SingleObjectHolder.o: src/SingleObjectHolder.cxx
	$(CC) $(CFLAGS) src/SingleObjectHolder.cxx -o build/SingleObjectHolder.o

build/VectorObjectHolder.o: src/VectorObjectHolder.cxx 
	$(CC) $(CFLAGS) src/VectorObjectHolder.cxx -o build/VectorObjectHolder.o 


clean:
	rm -r build/
	rm -r lib/
