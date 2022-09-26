#include <memory.h>
#include <stdbool.h>

// header file defines the types and functions needed to work with our simple fixed‑size memory pool.

#ifndef MEM_POOL_MANAGER_H
#define MEM_POOL_MANAGER_H

typedef struct MemoryPoolBlock {
    void* data; // pointer
    bool is_alloc; // status whether it is allocated or not
    size_t size; // size of the block in bytes
    struct MemoryPoolBlock *next;
} MemoryPoolBlock;

// MemoryPool is implemented using the concept of data structure : Linked List
// MemoryPoolBlock is like the node of linked list


typedef struct MemoryPoolManager {
    size_t pool_size; // size of the pool in bytes
    size_t mem_block_size; // size of each block of memory in the pool
    u_int32_t mem_block_count; // number of blocks
    MemoryPoolBlock *head; // pointer pointing to the 1st block in the pool
} MemoryPoolManager;

// MemoryPoolManager structure is similar to the Linked List structure


typedef enum {
    MEMORY_POOL_INIT_ERROR,
    MEMORY_POOL_DESTROY_ERROR,
    MEMORY_POOL_ALLOC_ERROR,
    MEMORY_POOL_OK
} MemoryPoolError;

// enum help with returning error codes.


// the below lines are : functional interface of our MemoryPoolManager.

MemoryPoolError mem_pool_init(MemoryPoolManager **pool, size_t mem_block_size, u_int32_t mem_block_count);

MemoryPoolError mem_pool_destroy(MemoryPoolManager *pool);

MemoryPoolError mem_pool_alloc(MemoryPoolManager *pool, MemoryPoolBlock **block);

MemoryPoolError mem_pool_free(MemoryPoolManager *pool, MemoryPoolBlock *block);

void print_mem_blocks(MemoryPoolManager *pool);

void print_block(MemoryPoolBlock *block);

#endif
