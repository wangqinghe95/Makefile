edit : common.o main.o utils.o
	cc -o edit main.o common.o utils.o

main.o : main.c
	cc -c main.c

common.o : common.c common.h
	cc -c common.c 

utils.o : utils.c utils.h
	cc -c utils.c

clean : 
	rm edit common.o main.o utils.o