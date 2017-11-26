#include <stdio.h>
#include "terp/error.h"
#include "terp/file.h"

int main( int argc, char ** argv ) {
  printf( "Hello, world\n" );
  char * to_print = get_file( "Makefile" );
  error( "bruh" );
  printf( "File is: %s\n", to_print );
}
