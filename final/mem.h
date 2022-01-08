// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief 要求分配包含 Header 的記憶體空間
 *
 * @param size 要求的記憶體大小 
 * requested memory size.
 * @param front_size 前面額外的記憶體大小 
 * additional memory size which is in front of the requested memory block.
 * @param available_front_size 前面額外的憶體大小的可用空間 
 * used to record the available space of the front additional size. The user should setup a valid available_front_size first.
 * If the available_front_size is NULL , you should treat this as zero , which means there is no additional memory space.
 *
 * @return void* 取得的記憶體位址 The allocate memory address which does not include the front additional memory.
 */
void* my_malloc(size_t size, size_t front_size, size_t* available_front_size);

/**
 * @brief 將記憶體位址向前移
 *
 * If the size is larger than *available_front_size , the function will only use all available space. If available_front_size is NULL , then the address will not be changed.
 *
 * @param ptr 目標記憶體位址 
 * the memory address that will be changed.
 * @param size 前面額外的記憶體大小 
 * use the front memory , which implies moving the address forward.
 * @param available_front_size 前面額外的憶體大小的可用空間 
 * used to record the available spacof the front additional size.
 */
void my_push(void** ptr, size_t size, size_t* available_front_size);

/**
 * @brief 釋放記憶體
 *
 * @param ptr 目標記憶體位址 
 * the memory address that will be freed.
 * @param available_front_size 前面額外的憶體大小的可用空間 
 * the available memory space in front of the memory address. You can assume that available_front_size is valid.
 */
void my_free(void* ptr, size_t available_front_size);

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
