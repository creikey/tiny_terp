#ifndef H_MEMORY
#define H_MEMORY

typedef struct _memory_block {
  void * data;
  bool used;
  struct _memory_block * next_data;
} memory_block;

void debug_memory( memory_block * memory_head );

memory_block * make_memory_head( size_t amount_of_memory );

void * make_memory( memory_block * memory_head, size_t memory_size );

void free_unused_memory( memory_block * memory_head );

#endif
