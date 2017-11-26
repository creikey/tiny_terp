#include <stdio.h>
#include <malloc.h>
#include "terp/error.h"
#include "terp/file.h"

char * get_file( const char * file_path ) {
  // Declares the file pointer
  FILE * to_open = NULL;
  // Opens it
  to_open = fopen( file_path, "r" );
  // Checks if the file exists
  if( to_open == NULL ) {
    error( "file was null in get_file" );
  }
  // Goes to the end of the file and gets size
  fseek( to_open, 0, SEEK_END );
  int file_size = ftell( to_open );
  // Declares the returning variable
  char * to_return = malloc( file_size );
  // Goes to the beginning of the file
  fseek( to_open, 0, SEEK_SET );
  // Copies every character in the file into the buffer
  for( int i = 0; i < file_size; i++ ) {
    to_return[i] = fgetc( to_open );
  }
  // Closes the file
  fclose( to_open );
  // Returns the new pointer
  return to_return;
}
