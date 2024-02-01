edit : common.o main.o utils.o
	cc -o edit main.o common.o utils.o

main.o : main.c

common.o : common.c common.h

utils.o : utils.c utils.h

clean : 
	rm edit common.o main.o utils.o