cc=gcc
exe=test

test : test.c node.o bst.o
	$(cc) test.c node.o bst.o -o test

node.o : node.c node.h
	$(cc) node.c -c

bst.o : bst.c bst.h
	$(cc) bst.c -c

clean : 
	rm -f *.o