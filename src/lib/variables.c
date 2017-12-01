#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "terp/error.h"
#include "terp/variables.h"

const char * data_types[] = {"integer","floating","strn"};
const int amount_data_types = 3;

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
       error( "variable not found", true );
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
    return *((int*)(cur->data));
  } else {
    error( "couldn't find variable", true );
    return NULL;
  }
}

void debug_variable( variable_block * in_var, int var_index ) {
  // Just prints out debuggin information, stuff like name and checks for null
  eg_cs( "-- Preparing to debug variable " );
  if( in_var->var_name == NULL ) {
    eg_cs("\n");
    fatal_error( "variable name for index ", OPEN );
    eg_i( var_index );
    eg_cs( " is null" );
    eg_close();
  } else {
    eg_s( in_var->var_name );
    eg_cs(" --\n");
  }
  if( in_var->next_variable == NULL ) {
    error( "variable block ends at variable ", OPEN );
    eg_s( in_var->var_name );
    eg_cs( ", index " );
    eg_i( var_index );
    eg_close();
  } else {
    eg_cs("Next variable isn't null\n");
  }
  if( in_var->previous_variable == NULL ) {
    error( "previous variable for variable ", OPEN );
    eg_s( in_var->var_name );
    eg_cs( ", index " );
    eg_i( var_index );
    eg_cs( " is null" );
    eg_close();
  } else {
    eg_cs("Previous variable isn't null\n");
  }
  if( in_var->data == NULL ) {
    message( "data is null for variable ", OPEN );
    eg_s( in_var->var_name );
    eg_cs( ", index " );
    eg_i( var_index );
    eg_close();
  } else {
    if( in_var->data_type < 0 || in_var->data_type > amount_data_types-1 ) {
      error( "data type out of range for variable ", OPEN );
      eg_s( in_var->var_name );
      eg_cs( ", at index " );
      eg_i( var_index );
      eg_close();
    } else {
      eg_cs("Data is of type ");
      eg_cs(data_types[in_var->data_type]);
    }
  }
}

void debug_variables( variable_block * vars ) {
  // The variables
  variable_block * cur; // the cursor to debug variables from
  int index = 0; // the index of the current variable
  // Sets the cursor equal to the input head
  cur = vars;
  // Iterates through the linked list
  while( cur->next_variable != NULL ) {
    // Debugs the current variable
    debug_variable( cur, index );
    // Goes to the next variable
    index += 1;
    cur = cur->next_variable;
  }
  // Debugs the last variable;
  debug_variable( cur, index+1 );
  return;
}
