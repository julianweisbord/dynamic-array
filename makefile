dynamic: dynamic.o main.o
	gcc dynamic.o main.o -o dynamic
dynamic.o: dynamic.c
	gcc -c dynamic.c
main.o: main.c
	gcc -c main.c
clean:
	rm -rf *.o *.out *.exe
