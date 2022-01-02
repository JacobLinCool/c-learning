// Copyright (c) JacobLinCool
#include "mymem.h"
#define BLOCK_SIZE 16UL
#define HEADER_SIZE 9UL
#define MIN_SIZE 33UL

void my_realloc(void** pptr, size_t before, size_t after) {
    // [SPEC] If ptr is NULL, realloc() is identical to a call to malloc() for size bytes.
    if (*pptr == NULL) {
        *pptr = malloc(after);
        memset(*pptr, 0, after);
        return;
    }

    // [SPEC] If size is zero and ptr is not NULL, a new, minimum sized object is allocated and the original object is freed.
    if (after == 0) {
        free(*pptr);
        *pptr = NULL;
        return;
    }

    // Size not changed
    if (before == after) {
        return;
    }

    // [SPEC] The realloc() function tries to change the size of the allocation pointed to by ptr to size, and returns ptr.
    if (before < after) {
        void* newptr = malloc(after);
        memset(newptr, 0, after);
        memcpy(newptr, *pptr, before);
        free(*pptr);
    }
    if (before > after) {
        size_t before_additional_blocks = before < 9UL ? 0UL : (before - 9UL) / BLOCK_SIZE;
        size_t after_additional_blocks = after < 9UL ? 0UL : (after - 9UL) / BLOCK_SIZE;

        if (before_additional_blocks == after_additional_blocks) {
            return;
        }

        // printf("before: 0x%lX\n", before);
        // printf("after: 0x%lX\n", after);

        size_t old_size = MIN_SIZE + before_additional_blocks * BLOCK_SIZE;
        size_t new_size = MIN_SIZE + after_additional_blocks * BLOCK_SIZE;
        // size_t diff_additional_blocks = (before - new_size) < 9UL ? 0UL : (before - new_size) / BLOCK_SIZE;

        // printf("old_size: 0x%lX\n", old_size);
        // printf("new_size: 0x%lX\n", new_size);

        // edit meta data of original pointer
        *((size_t*)(*pptr) - 1) = new_size;

        // the cleaner pointer
        void* clean_ptr = *pptr + new_size - 1UL;

        // temp data
        // void* overwritten = malloc(sizeof(size_t));
        // memcpy(overwritten, (size_t*)clean_ptr - 1, sizeof(size_t));

        // edit meta data of cleaner pointer
        // *((size_t*)clean_ptr - 1) = MIN_SIZE + diff_additional_blocks * BLOCK_SIZE - 16UL;
        *((size_t*)clean_ptr - 1) = old_size - new_size + 1UL;

        // print pointer
        // printf("[pptr - 1] %p: 0x%lX\n", (size_t*)*pptr - 1, *((size_t*)*pptr - 1));
        // printf("[pptr + 0] %p: 0x%lX\n", (size_t*)*pptr, *(size_t*)*pptr);

        // print cleaner pointer
        // printf("[clean_ptr - 1] %p: 0x%lX\n", (size_t*)clean_ptr - 1, *((size_t*)clean_ptr - 1));
        // printf("[clean_ptr + 0] %p: 0x%lX\n", (size_t*)clean_ptr, *(size_t*)clean_ptr);

        // free the cleaner pointer
        free(clean_ptr);

        // move back the overwritten data
        // memcpy((size_t*)clean_ptr - 1, overwritten, sizeof(size_t));
    }

    return;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
