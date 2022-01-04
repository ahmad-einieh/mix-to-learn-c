test: mat.o tset.o
	gcc mat.o tset.o -o test
mat.o: mat.c mat.h
	gcc mat.c -c -ansi -Wall
tset.o: tset.c mat.h
	gcc tset.c -c -ansi -Wall
