#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "terp/error.h"
#include "terp/variables.h"

variable_block * create_vars() {
  variable_block * to_return = malloc( sizeof *to_return );
  to_return->data = NULL;
  const char * to_append = "head_variable";
  to_return->var_name = malloc( strlen(to_append)+1 );
  for( size_t i = 0; i < strlen(to_append); i++ ) {
    to_return->var_name[i] = to_append[i];
  }
  to_return->var_name[strlen(to_append)] = '\0';
  to_return->next_variable = NULL;
  to_return->previous_variable = NULL;
  return to_return;
}

void free_variable( variable_block * vars, char * var_name ) {
  variable_block * cur = vars;
  bool found_variable = false;
  while( cur->next_variable == NULL ) {
    if( strcmp(cur->var_name, var_name) == 0 ) {
      found_variable = true;
      break;
    } else {
      cur = cur->next_variable;
    }
  }
  if( !found_variable ) {
    if( strcmp(cur->var_name, var_name) == 0 ) {
      found_variable = true;
    } else {
       error( "variable not found" );
       return;
    }
  } else {

    free(cur);
  }
}

void create_variable_int( variable_block * vars, int data, char * in_var_name ) {
  variable_block * to_append = malloc( sizeof *to_append );
  int * to_data = malloc( sizeof(int) );
  *to_data = data;
  to_append->data = to_data;
  to_append->var_name = in_var_name;
  variable_block * cur = vars;

  while( cur->next_variable != NULL ) {
    cur = cur->next_variable;
  }
  to_append->previous_variable = cur;
  cur->next_variable = to_append;
  return;
}

void * get_variable_val_int( variable_block * vars, char * var_name ) {
  variable_block * cur = vars;
  bool found_var = false;
  while( cur->next_variable != NULL ) {
    if( strcmp( cur->var_name, var_name ) == 0 ) {
      found_var = true;
      break;
    }
  }
  if( strcmp( cur->var_name, var_name ) == 0 ) {
    found_var = true;
  }
  if( found_var ) {
    return *(int*)cur->data;
  } else {
    error( "couldn't find variable" );
    return NULL;
  }
}

void debug_variables( variable_block * vars ) {
  variable_block * cur = vars;
  while( cur->next_variable != NULL ) {
    if( cur->var_name == NULL ) {
      fatal_error( "name was null" );
    }
    if( cur->next_variable == NULL ) {
      error( "next variabe was null" );
    }
    if( cur->previous_variable == NULL ) {
      error( "previous variable was null" );
    }
    if(  cur->data == NULL ) {
      error( "data was null" );
    }
    cur = cur->next_variable;
  }
  if( cur->previous_variable == NULL ) {
    error( "previous variable was null" );
  }
  if(  cur->data == NULL ) {
    error( "data was null" );
  }
  if( cur->var_name == NULL ) {
    fatal_error( "name was null" );
  }
}
