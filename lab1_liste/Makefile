EXEC = list

build: $(EXEC).c
	gcc $(EXEC).c -o $(EXEC) -std=gnu99

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)

pack:
	zip lab1-skel.zip *.c *.h Makefile