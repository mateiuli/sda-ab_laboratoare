EXEC=graph
GCC=gcc
CARGS=-std=gnu99

build: graph

graph: queue.o stack.o graph.o list.o
	$(GCC) $(CARGS) $^ -o $@

%.o: %.c
	$(GCC) -c $(CARGS) $^ -o $@

clean:
	rm -f *.o ~* $(EXEC)

run:
	./$(EXEC)
