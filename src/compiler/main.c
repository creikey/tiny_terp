#include <stdio.h>
#include "terp/error.h"
#include "terp/variables.h"
#include "terp/file.h"

int main( int argc, char ** argv ) {
  variable_block * vars = create_vars();
  debug_variables( vars );
  char * to_read;
  if( argc > 1 ) {
    to_read = argv[1];
  } else {
    fatal_error( "you must input a file to read", CLOSE );
    return -1;
  }
  program_bytecode prg_byte = get_file_bytestream( to_read );
  printf("File is: ");
  for( unsigned int i = 0; i < prg_byte.bytes_len; i++ ) {
    printf( "%d, ", prg_byte.byte_stream[i] );
  }
  printf("\n");
  return 0;
}
