#include <stdio.h>
#include "terp/error.h"
#include "terp/file.h"

int main( int argc, char ** argv ) {
  char * to_read;
  if( argc > 1 ) {
    to_read = argv[1];
  } else {
    fatal_error( "you must input a file to read" );
    return -1;
  }
  char * to_print = get_file( to_read );
  printf("File is: \n%s", to_print);
  message( "Searching for expressions...", true );
  return 0;
}
