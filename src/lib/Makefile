#Builds tiny terp libraries
objects = error.o
output_lib=libterp.a
include_folder=terp

.PHONY: clean

lib: $(objects)
	ar rvs $(output_lib) $(objects)
	mv $(output_lib) terp
	cp -r $(include_folder) ..

error.o: error.c $(include_folder)/error.h
	gcc -c error.c

clean:
	-rm $(objects)
	-rm $(include_folder)/$(output_lib)
