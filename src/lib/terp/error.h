#ifndef H_ERROR
#define H_ERROR

void print_error( const char * to_print, const char * filename, int line );

void print_fatal_error( const char * to_print, const char * filename, int line );

void print_partial_fatal_error( const char * to_print, const char * filename, int line );

void end_error();

#define append_fatal_error(x) printf( x );

#define fatal_error(x) print_fatal_error(x, __FILE__, __LINE__)

#define format_fatal_error(x) print_partial_fatal_error(x, __FILE__, __LINE__)

#define error(x) print_error(x, __FILE__, __LINE__ )

#define capt_log(x) print_message(x, __FILE__, __LINE__ )

#define part_capt_log(x), print_partial_message(x, __FILE__, __LINE__ )

#endif
