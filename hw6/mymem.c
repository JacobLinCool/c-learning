// Copyright (c) JacobLinCool
#include "mymem.h"

void my_realloc(void** pptr, size_t before, size_t after) {
    // [SPEC] If ptr is NULL, realloc() is identical to a call to malloc() for size bytes.
    if (*pptr == NULL) {
        *pptr = malloc(after * sizeof(**pptr));
        memset(*pptr, 0, after * sizeof(**pptr));
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
    void* newptr = malloc(after * sizeof(**pptr));
    memset(newptr, 0, after * sizeof(**pptr));
    memcpy(newptr, *pptr, (after < before ? after : before) * sizeof(**pptr));
    free(*pptr);
    return;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
