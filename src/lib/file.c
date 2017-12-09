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

program_bytecode * get_file_bytestream( const char * file_path ) {
  // The variables
  int * to_return; // the bytestream to return
  unsigned int file_len; // the length of the input file
  FILE * to_open; // the file pointer to open
  size_t bytes_read; // the bytes read from the file
  // Opens it
  to_open = fopen( file_path, "r" );
  // Gets file length
  file_len = get_file_len( to_open );
  // Mallocs the memory needed to return
  to_return = malloc( sizeof(int) * file_len );
  // Reads the memory
  bytes_read = fread( to_return, sizeof(int), file_len, to_open );
  // Checkes the bytes read
  if( bytes_read < file_len ) {
    error( "bytes_read is ", false );
    eg_i( bytes_read );
    eg_cs( " when it should be " );
    eg_i( file_len );
    eg_close();
  }
  // Formats data into a bytecode struct
  program_bytecode * to_format = mallloc( sizeof *to_format );
  to_format->byte_stream = to_return;
  to_format->bytes_len = sizeof(int) * file_len;
  return to_format;
}

int write_bytes_to_file( const char * in_file_path, program_bytecode * code ) {
  // The variables
  FILE * fp; // file pointer to write to
  // Opens the file
  fp = fopen( in_file_path, "w" );
  if( fp == NULL ) {
    fatal_error( "fp was null for file ", OPEN );
  }
  // Writes all integers
  size_t errcheck = fwrite( code->byte_stream, sizeof *code->byte_stream, code->bytes_len, fp );
  if( errcheck != code->bytes_len ) {
    error( "Didn't write whole bytestream", CLOSE );
    return -1;
  }
  return 0;

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
