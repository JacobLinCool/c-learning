// Copyright (c) JacobLinCool
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief 分數相加
 *
 * @param x 答案分子
 * @param y 答案分母
 * @param a 被加數分子
 * @param b 被加數分母
 * @param c 加數分子
 * @param d 加數分母
 * @return int32_t 合法回傳 0，非法回傳 -1
 */
int32_t frac_add(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d);

/**
 * @brief 分數相減
 *
 * @param x 答案分子
 * @param y 答案分母
 * @param a 被減數分子
 * @param b 被減數分母
 * @param c 減數分子
 * @param d 減數分母
 * @return int32_t 合法回傳 0，非法回傳 -1
 */
int32_t frac_del(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d);

/**
 * @brief 分數相乘
 *
 * @param x 答案分子
 * @param y 答案分母
 * @param a 被乘數分子
 * @param b 被乘數分母
 * @param c 乘數分子
 * @param d 乘數分母
 * @return int32_t 合法回傳 0，非法回傳 -1
 */
int32_t frac_mul(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d);

/**
 * @brief 分數相除
 *
 * @param x 答案分子
 * @param y 答案分母
 * @param a 被除數分子
 * @param b 被除數分母
 * @param c 除數分子
 * @param d 除數分母
 * @return int32_t 合法回傳 0，非法回傳 -1
 */
int32_t frac_div(int32_t* x, int32_t* y, int32_t a, int32_t b, int32_t c, int32_t d);

// Any application that can be written in JavaScript, will eventually be written in JavaScript.
