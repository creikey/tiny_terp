#include <stdio.h>
#include "terp/error.h"

void print_error( const char * to_print, const char * filename, int line ) {
  fprintf( stderr, "\033[1;31mERROR ON LINE \033[1;33m\033[4m%d\033[0m \033[1;31mIN FILE \033[1;33m\033[4m%s\033[0m:\033[21;37m %s\033[0m\n", line, filename, to_print );
  return;
}

void print_fatal_error( const char * to_print, const char * filename, int line ) {
  fprintf( stderr, "\033[1;33m\033[4m⚠ FATAL ERROR⚠ - \033[0m\033[1;31mERROR ON LINE %d IN FILE %s:\033[21;37m %s\033[0m\n", line, filename, to_print );
  return;
}
