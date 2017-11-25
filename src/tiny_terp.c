#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>
#include <stdbool.h>
#include "bytecode.h"
#include "memory.h"

bool ends_with(const char *str, const char *suffix) {
    if (!str || !suffix)
        return false;
    size_t lenstr = strlen(str);
    size_t lensuffix = strlen(suffix);
    if (lensuffix >  lenstr)
        return false;
    return strncmp(str + lenstr - lensuffix, suffix, lensuffix) == 0;
}

char * get_bytecode( char * bytecode_path ) {
  FILE * bytecode_data;
  bytecode_data =  fopen( bytecode_path, "r" );
  if( bytecode_data == NULL ) {
    fprintf( stderr, "ERROR: bytecode was null\n" );
    return NULL;
  }
  fseek( bytecode_data, 0, SEEK_END );
  long byte_size = ftell( bytecode_data );
  char * to_return = calloc( 1, byte_size );
  rewind( bytecode_data );
  for( int i = 0; i < byte_size; i++ ) {
typedef int size_t;
    to_return[i] = fgetc( bytecode_data );
  }
  return to_return;
}

int expression_interpret( char * bytecode_stream, size_t position, size_t max_file_size ) {
  size_t expression_size = 0;
  int expression_type = -1;
  while( bytecode_stream[position+expression_size] != END_EXPRESSION ) {
    expression_size += 1;
    switch( bytecode_stream[position+expression_size] ) {
      case GREATER_THAN:
        expression_type = GREATER_THAN;
        break;
      case LESS_THAN:
        expression_type = LESS_THAN;
        break;
      case EQUAL_TO:
        expression_type = EQUAL_TO;
        break;
      }
    }
    if( expression_type == -1 ) {
      // No expression type
      return -2;
    }
    if( position+expression_size > max_file_size ) {
      // No end of expression
      return -1;
    }
  }
  return 0;
}

void interpret( char * bytecode ) {
  size_t byte_size = strlen( bytecode );
  memory_block * program_memory = make_memory_head( 10 );
  debug_memory( program_memory );
  bool is_in_string = false;
  for( size_t i = 0; i < byte_size; i++ ) {
    switch( bytecode[i] ) {
      case END_OF_STRING:
        if( is_in_string == false ) {
          fprintf( stderr, "ERROR: string closed but not opened at bytecode %lu\n", i );
        } else  {

        }
        break;
      default:
        fprintf( stderr, "ERROR: token not found at bytecode %lu\n", i  );
        break;
    }
  }
}

void compile( char * filepath ) {
  return;
}

char * find_bytecode( char * to_search ) {
  printf("Searching for bytecode in directory %s\n", to_search );
  DIR * dir;
  char * to_return;
  struct dirent * ent;
  if( (dir = opendir(to_search) ) != NULL ) {
    while( (ent = readdir( dir ) ) != NULL ) {
      if( ends_with(ent->d_name, ".ttc") ) {
        if( (ent->d_name)[0] == '.' ) {
          to_return = calloc(1, strlen(to_search) + strlen(ent->d_name) + 1 );
          strcpy( to_return, to_search );
          strcat( to_return, ent->d_name );
          printf( "Found bytecode in %s\n", to_return );
          return to_return;
        } else {
          //to_return = calloc(1, strlen( ent->d_name )-1);
          //memcpy( to_return, ent->d_name, strlen(ent->d_name)-1 );
          to_return = malloc( strlen( ent->d_name ) + 1 );
          memcpy(to_return, ent->d_name, strlen( ent->d_name ) + 1 );
          printf( "Found bytecode in %s\n", to_return );
          return to_return;
        }
      }
    }
  }
}
