#Builds tiny terp libraries
objects = error.o file.o expressions.o variables.o bytecode.o parse.o
output_lib=libterp.a
include_folder=terp

.PHONY: clean

lib: $(objects)
	ar rvs $(output_lib) $(objects)
	mv $(output_lib) terp
	cp -r $(include_folder) ..

expressions.o: expressions.c $(include_folder)/expressions.h
	gcc -c expressions.c

parse.o: parse.c $(include_folder)/parse.h
	gcc -c parse.c

bytecode.o: bytecode.c $(include_folder)/bytecode.h
	gcc -c bytecode.c

variables.o: variables.c $(include_folder)/variables.h
	gcc -c variables.c

error.o: error.c $(include_folder)/error.h
	gcc -c error.c

file.o: file.c $(include_folder)/file.h
	gcc -c file.c

clean:
	-rm $(objects)
	-rm $(include_folder)/$(output_lib)
