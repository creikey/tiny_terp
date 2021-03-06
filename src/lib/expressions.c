// Parses bytecode expressions
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include "terp/error.h"
#include "terp/expressions.h"
#include "terp/bytecode.h"
#include "terp/variables.h"

int parse_expression( variable_block * vars, int * byte_stream, int position ) {
  int expr_type = -1;
  bool end_of_expr = false;
  int cur_pos = 0;
  int left_var;
  int right_var;
  // For searching for vars
  bool found_var;
  // Loop for the expression
  while( end_of_expr == false ) {
    switch( byte_stream[position+cur_pos] ) {
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
        // If there's another expression
      case BEGIN_EXPR:
        // Recursively call it
        if( expr_type == -1 ) {
          left_var = parse_expression(vars, byte_stream, position+cur_pos);
        } else {
          right_var = parse_expression( vars, byte_stream, position+cur_pos );
        }
      // If there's a clause to get a variable
      case GET_VARIABLE:
        // If it's found the var yet
        found_var = false;
        // The cursor that's searching for the end of the var
        int varpos = position+cur_pos;
        // The starting position of the variable's string to pull
        int varstart = position+cur_pos+1;
        // The size of the variable's string to pull
        size_t name_size = 0;
        // Makes sure the variable isn't found
        found_var = false;
        // While it hasn't found the var
        while( found_var == false ) {
          // If it isn't a variable_start
          if( byte_stream[varpos] != VARIABLE_START ) {
            // If it's a variable end
            if( byte_stream[varpos] == VARIABLE_END ) {
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
        // Scroll through the variable int stuff
        for( int i = 0; i < name_size-1; i++ ) {
          if( byte_stream[varstart+i] > 256 ) {
            fatal_error( "not a string on bytecode  ", false )
            eg_i( cur_pos );
            eg_close();
          }
          to_var[i] = (char)byte_stream[varstart+i];
        }
        // Add a null terminator
        to_var[name_size] = '\0';
        void * var_test = get_variable_val_int( vars, to_var );
        if( var_test == NULL ) {
          fatal_error( "couldn't find variable for expression, vars: ", OPEN );
          debug_variables(vars);
          eg_close();
          break;
        } else {
          if( expr_type == -1 ) {
            left_var = *(int*)var_test;
          } else {
            right_var = *(int*)var_test;
          }
        }
        break;
    }
    cur_pos += 1;
  }
}
