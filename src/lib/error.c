#include <stdio.h>
#include "terp/error.h"

void print_error( const char * to_print, const char * filename, int line ) {
  fprintf( stderr, "\033[1;31mERROR ON LINE %d IN FILE %s: %s\033[0m\n", line, filename, to_print );
  return;
}
