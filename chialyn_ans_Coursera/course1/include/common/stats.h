/******************************************************************************
 * Copyright (C) 2026 by Hung Chia Lyn
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Header file for statistical analytics functions
 *
 * This file contains the declarations and documentation for functions
 * that perform statistical analysis on an array of unsigned char data.
 *
 * @author Hung Chia Lyn
 * @date 2026-April-19
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array
 *
 * Given an array and its length, prints the minimum, maximum,
 * mean, and median values to the screen.
 *
 * @param arr  Pointer to the unsigned char data array
 * @param n    Length of the array
 * @return     void
 */
void print_statistics(unsigned char *arr, unsigned int n);

/**
 * @brief Prints all elements of an array
 *
 * @param arr  Pointer to the unsigned char data array
 * @param n    Length of the array
 * @return     void
 */
void print_array(unsigned char *arr, unsigned int n);

/**
 * @brief Finds the median value of an array
 *
 * @param arr  Pointer to the unsigned char data array
 * @param n    Length of the array
 * @return     Median value as unsigned char
 */
unsigned char find_median(unsigned char *arr, unsigned int n);

/**
 * @brief Finds the mean value of an array
 *
 * @param arr  Pointer to the unsigned char data array
 * @param n    Length of the array
 * @return     Mean value as unsigned char (rounded down)
 */
unsigned char find_mean(unsigned char *arr, unsigned int n);

/**
 * @brief Finds the maximum value of an array
 *
 * @param arr  Pointer to the unsigned char data array
 * @param n    Length of the array
 * @return     Maximum value as unsigned char
 */
unsigned char find_maximum(unsigned char *arr, unsigned int n);

/**
 * @brief Finds the minimum value of an array
 *
 * @param arr  Pointer to the unsigned char data array
 * @param n    Length of the array
 * @return     Minimum value as unsigned char
 */
unsigned char find_minimum(unsigned char *arr, unsigned int n);

/**
 * @brief Sorts array from largest to smallest
 *
 * Index 0 will be the largest value, index (n-1) the smallest.
 *
 * @param arr  Pointer to the unsigned char data array
 * @param n    Length of the array
 * @return     void
 */
void sort_array(unsigned char *arr, unsigned int n);


#endif /* __STATS_H__ */
