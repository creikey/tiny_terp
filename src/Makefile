CFILES=tiny_terp.c main.c console.c memory.c
OFILES=tiny_terp.o main.o console.o memory.o

.PHONY: clean

tiny_terp: $(OFILES)
	gcc $(OFILES) -o tiny_terp

tiny_terp.o: tiny_terp.c
	gcc -c tiny_terp.c

memory.o: memory.c memory.h
	gcc -c memory.c

main.o: main.c
	gcc -c main.c

console.o: console.c
	gcc -c console.c

clean:
		-rm tiny_terp
		-rm *.o
