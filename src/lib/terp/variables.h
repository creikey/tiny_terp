#ifndef H_VARIABLES
#define H_VARIABLES

typedef struct _variable_block {
  void * data;
  char * var_name;
  struct _variable_block * next_variable;
  struct _variable_block * previous_variable;
} variable_block;

void * get_variable_val_int( variable_block * vars, char * var_name );

#endif