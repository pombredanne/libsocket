.SUFFIXES: .cpp .c .o .so

OBJECTS=libinetsocket.o libunixsocket.o
SHARED_OBJECT=libsocket.so
STATICLIB=libsocket.a

LIBPATH=/usr/lib

#CC=gcc
CPP=g++
# -DVERBOSE to enable verbosity from libinetsocket/libunixsocket
CFLAGS=

.c.o:
	$(CC) $(CFLAGS) -fPIC -c $<

static: $(OBJECTS)
	ar rs ../$(STATICLIB) $(OBJECTS)

so: static
	$(CC) -shared -o ../$(SHARED_OBJECT) -Wl,--whole-archive ../$(STATICLIB) -Wl,--no-whole-archive


install: so
	install ../$(SHARED_OBJECT) $(LIBPATH) ; \
	ldconfig

obj: $(OBJECTS)

clean:
	rm -f *.o
