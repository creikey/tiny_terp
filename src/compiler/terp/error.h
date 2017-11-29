#ifndef H_ERROR
#define H_ERROR

void print_error( const char * to_print, const char * filename, int line );

void print_fatal_error( const char * to_print, const char * filename, int line );

void print_partial_fatal_error( const char * to_print, const char * filename, int line );

void end_error();

void print_message( const char * to_print, const char * filename, int line );

void print_partial_message( const char * to_print, const char * filename, int line );

void continue_partial_message_float( float to_print );

void continue_partial_message_integer( int to_print );

void continue_partial_message( const char * to_print );

void end_partial_message();

#define append_fatal_error(x) printf( x );

#define fatal_error(x) print_fatal_error(x, __FILE__, __LINE__)

#define format_fatal_error(x) print_partial_fatal_error(x, __FILE__, __LINE__)

#define error(x) print_error(x, __FILE__, __LINE__ )

#define capt_log(x) print_message(x, __FILE__, __LINE__ )

#define open_capt_log(x), print_partial_message(x, __FILE__, __LINE__ )

#define cont_capt_log(x), continue_partial_message(x)

#define int_capt_log(x), continue_partial_message_integer(x)

#define end_capt_log(), end_partial_message()

#endif
