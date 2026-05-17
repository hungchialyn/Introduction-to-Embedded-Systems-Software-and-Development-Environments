/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 */

#include "memory.h"
#include <stdlib.h>

/***********************************************************
 Function Definitions
***********************************************************/

void set_value(char * ptr, unsigned int index, char value) {
  *(ptr + index) = value;
}

void clear_value(char * ptr, unsigned int index) {
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index) {
  return *(ptr + index);
}

void set_all(char * ptr, char value, unsigned int size) {
  unsigned int i;

  for (i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size) {
  set_all(ptr, 0, size);
}

/***********************************************************
 Course 1 Final Assessment Memory Functions
***********************************************************/

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
  uint8_t *dst_start = dst;

  if (src == dst || length == 0) {
    return dst_start;
  }

  /*
   * If dst starts inside the source region, copy backward.
   * This prevents overwriting source bytes before they are copied.
   */
  if ((dst > src) && (dst < (src + length))) {
    src += length;
    dst += length;

    while (length > 0) {
      src--;
      dst--;
      *dst = *src;
      length--;
    }
  } else {
    while (length > 0) {
      *dst = *src;
      dst++;
      src++;
      length--;
    }
  }

  return dst_start;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
  uint8_t *dst_start = dst;

  while (length > 0) {
    *dst = *src;
    dst++;
    src++;
    length--;
  }

  return dst_start;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
  uint8_t *src_start = src;

  while (length > 0) {
    *src = value;
    src++;
    length--;
  }

  return src_start;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
  uint8_t *src_start = src;

  while (length > 0) {
    *src = 0;
    src++;
    length--;
  }

  return src_start;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
  uint8_t *src_start = src;
  uint8_t *left = src;
  uint8_t *right;
  uint8_t temp;

  if (length == 0) {
    return src_start;
  }

  right = src + length - 1;

  while (left < right) {
    temp = *left;
    *left = *right;
    *right = temp;

    left++;
    right--;
  }

  return src_start;
}

int32_t * reserve_words(size_t length) {
  int32_t *ptr;

  ptr = (int32_t *) malloc(length * sizeof(int32_t));

  if (ptr == NULL) {
    return NULL;
  }

  return ptr;
}

void free_words(int32_t * src) {
  free(src);
}
