#ifndef H_FILE
#define H_FILE

#include <stdio.h>

//char * get_file( const char * file_path );

typedef struct _program_bytecode {
  int * byte_stream;
  unsigned int bytes_len;
} program_bytecode;

size_t get_bytecode_len( int * in_bytes );

program_bytecode get_file_bytestream( const char * file_path );

unsigned int get_file_len( FILE * in_fp );

#endif
