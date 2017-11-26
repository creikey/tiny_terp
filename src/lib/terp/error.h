#ifndef H_ERROR
#define H_ERROR

void print_error( const char * to_print, const char * filename, int line );

void print_fatal_error( const char * to_print, const char * filename, int line );

#define fatal_error(x) print_fatal_error(x, __FILE__, __LINE__)

#define error(x) print_error(x, __FILE__, __LINE__ )

#endif
