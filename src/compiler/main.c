#include <stdio.h>
#include "terp/error.h"

int main( int argc, char ** argv ) {
  printf( "Hello, world\n" );
  error( "bruh" );
}
