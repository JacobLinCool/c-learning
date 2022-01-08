all: pre
	gcc fin01.c -lm -o fin01
	gcc fin02.c go.o -lm -o fin02
	gcc fin03.c frac.o -lm -o fin03
	gcc fin04.c mem.o -lm -o fin04

pre:
	gcc go.c -c -o go.o
	gcc frac.c -c -o frac.o
	gcc mem.c -c -o mem.o

zip:
	zip fin *.c *.h *.pdf Makefile

clean:
	-rm fin01 fin02 fin03 fin04 fin.zip
