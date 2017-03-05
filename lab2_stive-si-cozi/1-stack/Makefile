CC = gcc
CFLAGS = -std=gnu99 -g

build: stack

stack: stack.c
	$(CC) $(CFLAGS) -o $@ $^

run:
	./stack

clean:
	rm -f stack
