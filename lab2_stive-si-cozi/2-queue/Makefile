CC = gcc
CFLAGS = -std=gnu99 -g

build: queue

queue: queue.c
	$(CC) $(CFLAGS) -o $@ $^

run:
	./queue

clean:
	rm -f queue
