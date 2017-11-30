#include <stdio.h>
#include <malloc.h>
#include "terp/error.h"
#include "terp/file.h"



/*char * get_file( const char * file_path ) {
  // Declares the file pointer
  FILE * to_open = NULL;
  // Opens it
  to_open = fopen( file_path, "r" );
  // Checks if the file exists
  if( to_open == NULL ) {
    fatal_error( "file was null in get_file" );
    return NULL;
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
}*/

int * get_file_bytestream( const char * file_path ) {
  // The variables
  int * to_return; // the bytestream to return
  int file_len; // the length of the input file
  FILE * to_open; // the file pointer to open
  // Opens it
  to_open = fopen( file_path, "r" );
  // Gets file length
  file_len = get_file_len( to_open );
  // Mallocs the memory needed to return
  to_return = malloc( sizeof(int) * file_len );
  return to_return;
}

unsigned int get_file_len( FILE * in_fp ) {
  if( in_fp == NULL ) {
    // No file given
    fatal_error( "in file was null", false );
    return 0;
  } else {
    // Go to the end
    fseek( in_fp, 0, SEEK_END );
    // Get file length
    unsigned int to_return = ftell( in_fp );
    // Go to the beginning
    rewind( in_fp );
    // Return file length
    return to_return;
  }
}
