#include <stdio.h>
#include "terp/error.h"
#include "terp/general_parse.h"
#include "terp/bytecode.h"

int parse_file( char * in_file ) {
  if( in_file == NULL ) {
    fatal_error( "file to parse is null", true );
    return -1;
  } else {
    return 0;
  }
}
