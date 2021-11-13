all: midlib
	gcc mid01.c -lm -o mid01
	gcc mid02.c -lm -o mid02
	gcc mid03.c -lm -o mid03
	gcc mid04.c -lm -o mid04
	rm midlib.o

midlib: midlib.c
	gcc -c midlib.c -lm -o midlib.o

zip:
	zip mid *.c *.pdf Makefile

clean:
	-rm mid01 mid02 mid03 mid04 mid.zip *.o
