#include <stdio.h>
#include "tiny_terp.h"

int main( int argc, char ** argv ) {
  if( argc > 1 ) {

  } else {
    char * bytecode = find_bytecode( "." );
    if( bytecode == NULL ) {
      fprintf( stderr, "No bytecode found!\n" );
    } else {
      fprintf( stderr, "Running tiny_terp version %d\n", VERSION );
      char * to_read = get_bytecode( bytecode );
      interpret( to_read );
    }
  }
}
