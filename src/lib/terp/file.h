#ifndef H_FILE
#define H_FILE

typedef struct _FILE FILE;

//char * get_file( const char * file_path );

size_t get_bytecode_len( int * in_bytes );

int * get_file_bytestream( const char * file_path );

unsigned int get_file_len( FILE * in_fp );

#endif
