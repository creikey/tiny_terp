#ifndef H_EXPRESSIONS
#define H_EXPRESSIONS

typedef struct _variable_block variable_block;

int parse_expression( variable_block * vars, int * byte_stream, int position );

#endif
