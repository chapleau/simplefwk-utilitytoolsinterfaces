CC=g++-mp-4.8
CFLAGS=-std=c++11 -fPIC -Wall -I. -c
LDFLAGS=-std=c++11 -shared 
LDFLAGSEXTRA=-install_name @rpath/UtilityToolsInterfaces/lib/
OBJDIR=build
LIBDIR=lib

all: $(OBJDIR) $(LIBDIR) lib/libObjectHolder.so python/_ObjectHolder.so

$(OBJDIR):
	mkdir $(OBJDIR)

$(LIBDIR):
	mkdir $(LIBDIR) 

python/_ObjectHolder.so: lib/libObjectHolder.so python/ObjectHolder_wrap.o
	$(CC) $(LDFLAGS) python/ObjectHolder_wrap.o -L/opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/config -ldl -lpython2.7 -Llib/ -lObjectHolder -Xlinker -rpath -Xlinker `dirname \`pwd\`` -o python/_ObjectHolder.so

python/ObjectHolder_wrap.o: python/ObjectHolder_wrap.cxx
	$(CC) $(CFLAGS) python/ObjectHolder_wrap.cxx `python2.7-config --cflags` -o python/ObjectHolder_wrap.o

python/ObjectHolder_wrap.cxx: python/ObjectHolder.i
	swig -Wall -c++ -python python/ObjectHolder.i

lib/libObjectHolder.so: build/SingleObjectHolder.o build/VectorObjectHolder.o
	$(CC) $(LDFLAGS) $(LDFLAGSEXTRA)libObjectHolder.so build/SingleObjectHolder.o build/VectorObjectHolder.o -o lib/libObjectHolder.so

build/SingleObjectHolder.o: src/SingleObjectHolder.cxx
	$(CC) $(CFLAGS) src/SingleObjectHolder.cxx -o build/SingleObjectHolder.o

build/VectorObjectHolder.o: src/VectorObjectHolder.cxx 
	$(CC) $(CFLAGS) src/VectorObjectHolder.cxx -o build/VectorObjectHolder.o 


clean:
	rm -r build/
	rm -r lib/
	rm python/ObjectHolder_wrap.o
	rm python/_ObjectHolder.so
	rm python/ObjectHolder_wrap.cxx
