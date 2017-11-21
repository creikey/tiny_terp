#ifndef H_MEMORY
#define H_MEMORY

typedef struct _memory_block {
  void * data;
  bool used;
  struct _memory_block * next_data;
} memory_block;

#endif
