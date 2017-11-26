#Builds tiny terp libraries
objects = error.o file.o
output_lib=libterp.a
include_folder=terp

.PHONY: clean

lib: $(objects)
	ar rvs $(output_lib) $(objects)
	mv $(output_lib) terp
	cp -r $(include_folder) ..

error.o: error.c $(include_folder)/error.h
	gcc -c error.c

file.o: file.c $(include_folder)/file.h
	gcc -c file.c

clean:
	-rm $(objects)
	-rm $(include_folder)/$(output_lib)
