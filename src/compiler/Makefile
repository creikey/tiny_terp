#Builds tiny terp compiler
tiny_terp_lib=terp
objects = main.o
output_exec=tiny_terp

.PHONY: clean

main: $(objects)
	gcc -o $(output_exec) $(objects) -L$(tiny_terp_lib) -l$(tiny_terp_lib)
	cp $(output_exec) ..

debug: $(objects)
	gcc -o $(output_exec) $(objects) -L$(tiny_terp_lib) -l$(tiny_terp_lib) -g
	cp $(output_exec) ..

main.o: main.c
	gcc -c main.c

clean:
	-rm $(objects)
	-rm $(output_exec)
