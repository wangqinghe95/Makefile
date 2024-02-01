objects = common.o main.o utils.o
edit : $(objects)
	cc -o edit $(objects)

main.o : main.c

common.o : common.c common.h

utils.o : utils.c utils.h

clean : 
	rm edit common.o main.o utils.o