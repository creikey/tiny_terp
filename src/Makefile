#Makes everything

libfolder=lib
lib_data_name=terp
compiler_folder=compiler
exec_name=tiny_terp

.PHONY: clean

all:
	cd $(libfolder) && make
	echo "Removing compiler folder"
	-rm -r $(compiler_folder)/$(lib_data_name)
	mv $(lib_data_name) $(compiler_folder)
	cd $(compiler_folder) && make

clean:
	cd $(libfolder) && make clean
	cd $(compiler_folder) && make clean
	-rm $(exec_name)
