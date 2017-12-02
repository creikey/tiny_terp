#ifndef H_VARIABLES
#define H_VARIABLES

typedef enum variable_data {
  integer,
  floating,
  strn
} var_type;

extern const char * data_types[];
extern const int amount_data_types;

typedef struct _variable_block {
  var_type data_type;
  void * data;
  char * var_name;
  struct _variable_block * next_variable;
  struct _variable_block * previous_variable;
} variable_block;

void * get_variable_val_int( variable_block * vars, char * var_name );

variable_block * create_vars();

void free_variable( variable_block * vars, char * var_name );

void debug_variable( variable_block * in_var, int var_index );

void debug_variables( variable_block * vars );

#endif
