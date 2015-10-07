CC = gcc
memory_function: memory_function.o
	$(CC) $(LDFLAGS) memory_function.o -o memory_function

memory_function.o: memory_function.c
	$(CC) $(CFLAGS) -c memory_function.c

clean:
	rm -rf *.o *~ *.exe memory_function