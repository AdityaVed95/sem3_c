#include "mem_pool_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

MemoryPoolError mem_pool_init(MemoryPoolManager **pool, size_t mem_block_size, u_int32_t mem_block_count) {
    if (mem_block_count == 0)
        return MEMORY_POOL_INIT_ERROR;

    // Allocate memory for the pool itself
    *pool = (MemoryPoolManager*)malloc(sizeof(MemoryPoolManager));

    // Allocate memory for each block
    MemoryPoolBlock *blocks = (MemoryPoolBlock*)malloc(sizeof(MemoryPoolBlock) * mem_block_count);

    // Allocate the chunk of memory to be managed by the pool
    size_t pool_size = mem_block_size * mem_block_count;
    void *start = (void*)malloc(pool_size); // requesting actual chunk of memory managed by memory pool

    if (*pool == NULL || blocks == NULL || start == NULL) {
        printf("Unable to allocate memory for the pool\n");
        return MEMORY_POOL_INIT_ERROR;
    }

    (*pool)->mem_block_count = mem_block_count;
    (*pool)->mem_block_size = mem_block_size;
    (*pool)->pool_size = pool_size;
    (*pool)->head = blocks;

    // dividing pool's memory :

    void *current = start,
            *next = NULL;

    MemoryPoolBlock *current_block = blocks,
                       *next_block = NULL;

    // Divy up our chunk of memory so that each MemoryPoolBlock manages a chunk.
    for(int i = 0; i < mem_block_count; i++) {
        current_block->data = current;

        if (i == mem_block_count - 1) {
            next = next_block = NULL;
        } else {
            next = current + mem_block_size;
            next_block = current_block + sizeof(MemoryPoolBlock);
        }
        current_block->next = next_block;
        current_block->size = mem_block_size;
        current_block->is_alloc = false;
        current = next;
        current_block = next_block;
    }

    return MEMORY_POOL_OK;
};


MemoryPoolError mem_pool_destroy(MemoryPoolManager *pool) {
    if (pool != NULL && pool->head != NULL) {
        free(pool->head->data);
        free(pool->head);
        free(pool);
        return MEMORY_POOL_OK;
    }

    return MEMORY_POOL_DESTROY_ERROR;
};


MemoryPoolError mem_pool_alloc(MemoryPoolManager *pool, MemoryPoolBlock **block) {
    if (pool == NULL || block == NULL) {
        printf("Memory Pool Alloc Error\n");
        return MEMORY_POOL_ALLOC_ERROR;
    }

    if (pool->head != NULL) {
        MemoryPoolBlock *current = pool->head;
        while (current) {
            if (current->is_alloc == false) {
                *block = current;
                current->is_alloc = true;
                return MEMORY_POOL_OK;
            } else {
                current = current->next;
            }
        }
    }

    return MEMORY_POOL_ALLOC_ERROR;
}

MemoryPoolError mem_pool_free(MemoryPoolManager *pool, MemoryPoolBlock *block) {
    MemoryPoolBlock *current = pool->head;
    while (current) {
        if (current == block) {
            current->is_alloc = false;
            memset(current->data, 0, pool->mem_block_size);
            return MEMORY_POOL_OK;
        } else {
            current = current->next;
        }
    }

    return MEMORY_POOL_DESTROY_ERROR;
}

void print_mem_blocks(MemoryPoolManager *pool) {
    if (pool == NULL)
        return;

    MemoryPoolBlock *current = pool->head;
    while (current != NULL) {
        print_block(current);
        current = current->next;
    }
    printf("\n");
}

void print_block(MemoryPoolBlock *block) {
    printf("[%td | %d] => ", block->next && block->next->data ? block->next->data - block->data : block->size, block->is_alloc);
}
