#ifndef H_TINY_TERP
#define H_TINY_TERP

#define VERSION 1

// Interprets the bytecode
void interpret( char * bytecode );

// Compiles the source file to bytecode
void compile( char * filepath );

// Finds a path to some bytecode
char * find_bytecode( char * to_search );

// Gets bytecode to a character array
char * get_bytecode( char * bytecode_path );

#endif
