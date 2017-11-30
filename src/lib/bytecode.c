#include <stdio.h>
#include <stdbool.h>
#include "terp/bytecode.h"

const int possible_bytes[] = { BEGIN_EXPR, END_EXPR, VARIABLE_START, VARIABLE_END, GET_VARIABLE, GREATER_THAN, LESS_THAN, EQUAL_TO, SET_VARIABLE };

bool is_bytecode( int in_byte ) {
  size_t bytecode_size = sizeof(possible_bytes);
  for( size_t i = 0; i < bytecode_size; i++ ) {
    if( possible_bytes[i] == in_byte ) {
      return true;
    }
  }
  return false;
}
