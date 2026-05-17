/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>

void set_value(char * ptr, unsigned int index, char value);
void clear_value(char * ptr, unsigned int index);
char get_value(char * ptr, unsigned int index);
void set_all(char * ptr, char value, unsigned int size);
void clear_all(char * ptr, unsigned int size);

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);
uint8_t * my_memzero(uint8_t * src, size_t length);
uint8_t * my_reverse(uint8_t * src, size_t length);

int32_t * reserve_words(size_t length);
void free_words(int32_t * src);

#endif

