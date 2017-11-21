#include <stdio.h>
#include <malloc.h>
#include "memory.h"

void debug_memory( memory_block * memory_head ) {
  memory_block * cur = memory_head;
  int index = 0;
  while( cur->next_data != NULL ) {
    printf( "-- memory at index %d --\n", index );
    printf("used = %d\n", cur->used );
    printf("data = %lu\n", cur->data );
    printf("next_data = %lu\n", cur->next_data );
    index += 1;
    cur = cur->next_data;
  }
}

memory_block * make_memory_head( size_t amount_of_memory ) {
  memory_block * to_return = NULL;
  memory_block * cur;
  to_return = malloc( sizeof *to_return );
  if( to_return == NULL ) {
    fprintf( stderr, "Malloc failed at %d\n", __LINE__ );
  }
  to_return->next_data = NULL;
  cur = to_return;
  for( size_t i = 0; i < amount_of_memory; i++ ) {
    cur->data = NULL;
    cur->next_data = malloc( sizeof *cur );
    if( cur->next_data == NULL ) {
      fprintf( stderr, "Malloc failed at %d\n", __LINE__ );
    }
    cur = cur->next_data;
  }
  to_return->used = true;
  return to_return;
}

void * make_memory( memory_block * memory_head, size_t memory_size ) {
  memory_block * cur = memory_head;
  while( cur->next_data != NULL ) {
    cur = cur->next_data;
  }
  
}
