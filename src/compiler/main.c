#include <stdio.h>
#include "terp/error.h"
#include "terp/file.h"

int main( int argc, char ** argv ) {
  if( argv > 1 ) { 
    char * to_read = argv[1];
  }
  char * to_print = get_file( to_read );
}
