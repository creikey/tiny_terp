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

// Without the ending, used to print variables
void print_partial_fatal_error( const char * to_print, const char * filename, int line ) {
  fprintf( stderr, "\033[1;33m\033[4m⚠ FATAL ERROR⚠ - \033[0m\033[1;31mERROR ON LINE %d IN FILE %s:\033[21;37m %s", line, filename, to_print );
  return;
}

void end_error() {
  printf("\033[0m\n");
}

void print_message( const char * to_print, const char * filename, int line ) {
  fprintf( stderr, "\033[1;33mnon-fatal log at %d in %s:\033[0m %s\n", line, filename, to_print );
  return;
}

void print_partial_message( const char * to_print, const char * filename, int line ) {
  fprintf( stderr, "\033[1;33mnon-fatal log at %d in %s:\033[0m %s", line, filename, to_print );
  return;
}

void continue_partial_message( const char * to_print ) {
  fprintf( stderr, "%s" );
  return;
}

void end_partial_message() {
  fprintf( stderr, "\n" );
}
