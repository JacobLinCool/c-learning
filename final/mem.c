// Copyright (c) JacobLinCool
#include "mem.h"

void* my_malloc(size_t size, size_t front_size, size_t* available_front_size) {
    if (available_front_size == NULL) {
        void* ptr = malloc(size);
        return ptr;
    }
    else {
        void* ptr = malloc(size + front_size);
        *available_front_size = front_size;
        return ptr + front_size;
    }
}

void my_push(void** ptr, size_t size, size_t* available_front_size) {
    if (available_front_size == NULL) {
        return;
    }

    size_t offset = size < *available_front_size ? size : *available_front_size;

    *ptr = *ptr - offset;
    *available_front_size -= offset;

    return;
}

void my_free(void* ptr, size_t available_front_size) {
    if (available_front_size == 0) {
        free(ptr);
    }
    else {
        ptr -= available_front_size;
        free(ptr);
    }

    return;
}

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
