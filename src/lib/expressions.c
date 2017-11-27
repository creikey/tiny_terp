// Parses bytecode expressions
#include <stdio.h>
#include "terp/expressions.h"
#include "terp/bytecode.h"
#include "terp/variables.h"

int parse_expression( variable_block * vars, char * byte_stream, int position ) {
  int expr_type = -1;
  bool end_of_expr = false;
  int curchar = 0
  int left_var = -1;
  int right_var = -1;
  while( end_of_expr == false ) {
    switch( byte_stream[position+curchar] ) {
      case END_EXPR:
        end_of_expr = true;
        break;
      case LESS_THAN:
        expr_type = LESS_THAN;
        break;
      case GREATER_THAN:
        expr_type = GREATER_THAN;
        break;
      case EQUAL_TO:
        expr_type = EQUAL_TO;
        break;
      // If there's a clause to get a variable
      case GET_VARIABLE:
        // If it's found the var yet
        bool found_var = false;
        // The cursor that's searching for the end of the var
        int varchar = position+cur;
        // The starting position of the variable's string to pull
        int varstart = position+cur+1;
        // The size of the variable's string to pull
        size_t name_size = 0;
        // While it hasn't found the var
        while( found_var == false ) {
          // If it isn't a variable_start
          if( byte_stream[varchar] != VARIABLE_START ) {
            // If it's a variable end
            if( byte_stream[varchar] == VARIABLE_END ) {
              // Stop counting
              found_var = true;
            } else {
              // Increase the variable's string size
              name_size += 1;
            }
          }
        }
        // The variable's name soon to be filled
        char * to_var = malloc( name_size + 1 );
        // Scroll through the variable string
        for( int i = 0; i < name_size-1; i++ ) {
          to_var[i] = byte_stream[varstart+i];
        }
        // Add a null terminator
        to_var[name_size] = '\0';
        void * var_test = get_variable_val_int( vars, to_var );
        if( var_test == NULL ) {
          fatal_error( "variable wasn't an integer" );
          break;
        } else {
          if( expr_type == -1 ) {
            left_var = *var_test;
          } else {
            right_var = *var_test;
          }
        }
        break;
    }
    curchar += 1;
  }
}