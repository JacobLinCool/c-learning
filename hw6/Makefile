all: pre
	gcc hw0601.c mirror.o -lm -o hw0601
	gcc hw0602.c ext.o -lm -o hw0602
	gcc hw0603.c -lm -o hw0603
	# gcc hw0604.c xxx.o -lm -o hw0604
	# gcc hw0605.c xxx.o -lm -o hw0605
	rm -f *.o

pre:
	gcc mirror.c -c -o mirror.o
	gcc ext.c -c -o ext.o

clean:
	rm -f *.o
