objects = qolib.o qlist.o
test : test.c $(objects)
	gcc -std=c11 -g -o test test.c qolib.o qlist.o -I.

install : $(objects)
	ar -cq libqolib.a $(objects)
	mv libqolib.a /usr/lib/

qolib.o : qolib.c qolib.h constants.h
	gcc -std=c11 -c qolib.c

qlist.o : qlist.c qlist.h qolib.h
	gcc -std=c11 -c qlist.c

qonet.o : qonet.c qonet.h
	gcc -std=c11 -c qonet.c

.PHONY : clean
clean :
	-rm test *.o
