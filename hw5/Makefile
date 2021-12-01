all: pre
	gcc hw0501.c poker.o -lm -o hw0501
	gcc hw0502.c data.o -lm -o hw0502
	gcc hw0503.c polynomial.o -lm -o hw0503
	gcc hw0504.c banqi.o -lm -o hw0504
	rm -f *.o

pre:
	gcc poker.c -c -o poker.o
	gcc data.c -c -o data.o
	gcc polynomial.c -c -o polynomial.o
	gcc banqi.c -c -o banqi.o

clean:
	rm -f *.o hw0501
