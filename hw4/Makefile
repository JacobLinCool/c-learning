all: pre
	gcc hw0401.c hw04.o -o hw0401
	gcc hw0402-1.c hw04.o -o hw0402-1
	gcc hw0402-2.c hw04.o -o hw0402-2
	gcc hw0403.c hw04.o -o hw0403
	gcc hw0404.c hw04.o -o hw0404
	rm -f *.o

pre:
	gcc -c -o hw04.o hw04.c

zip:
	zip mid *.c *.pdf Makefile

clean:
	rm -f *.o hw0401 hw0402-1 hw0402-2 hw0403 hw0404
