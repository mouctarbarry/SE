procesus: compile1
	./execProcess
compile1: procesus.o
	gcc procesus.o -o execProcess
procesus.o: procesus.c
	gcc -c -Wall procesus.c

argument: compile2
	./execArg 
compile2: argument.o
	gcc argument.o -o execArg
argument.o: argument.c
	gcc -c -Wall argument.c

clean:
	rm -f execProcess
	rm -f execArg
	rm -f *.o