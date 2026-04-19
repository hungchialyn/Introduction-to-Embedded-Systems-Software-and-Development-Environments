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
 * @file stats.c
 * @brief Implementation of statistical analytics functions
 *
 * This file implements functions to analyze an array of unsigned char data,
 * reporting maximum, minimum, mean, and median. Data is sorted largest to
 * smallest. All statistics are rounded down to the nearest integer.
 *
 * @author Hung Chia Lyn
 * @date 2026-April-19
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* ========== main ========== */

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

    printf("=== Original Array ===\n");
    print_array(test, SIZE);

    printf("\n=== Sorting Array (Large to Small) ===\n");
    sort_array(test, SIZE);
    print_array(test, SIZE);

    printf("\n=== Statistics ===\n");
    print_statistics(test, SIZE);


}

/* ========== print_statistics ========== */

void print_statistics(unsigned char *arr, unsigned int n) {
    printf("  Minimum : %d\n", find_minimum(arr, n));
    printf("  Maximum : %d\n", find_maximum(arr, n));
    printf("  Mean    : %d\n", find_mean(arr, n));
    printf("  Median  : %d\n", find_median(arr, n));
}

/* ========== print_array ========== */

void print_array(unsigned char *arr, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        printf("  [%2d] = %3d", i, arr[i]);
        /* 每 4 個換一行，排版整齊 */
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

/* ========== sort_array（氣泡排序，大到小）========== */

void sort_array(unsigned char *arr, unsigned int n) {
    for (unsigned int i = 0; i < n - 1; i++) {
        for (unsigned int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                /* 交換 */
                unsigned char temp = arr[j];
                arr[j]     = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* ========== find_median ========== */

unsigned char find_median(unsigned char *arr, unsigned int n) {
    /*
     * 注意：find_median 會對陣列做排序
     * 若不想動到原始陣列，先複製一份
     */
    unsigned char temp[n];
    for (unsigned int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    sort_array(temp, n);

    if (n % 2 == 0) {
        /* 偶數個元素：取中間兩個的平均，無條件捨去 */
        return (unsigned char)((temp[n / 2 - 1] + temp[n / 2]) / 2);
    } else {
        /* 奇數個元素：直接取中間 */
        return temp[n / 2];
    }
}

/* ========== find_mean ========== */

unsigned char find_mean(unsigned char *arr, unsigned int n) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i < n; i++) {
        sum += arr[i];
    }
    /* 整數除法自動無條件捨去 */
    return (unsigned char)(sum / n);
}

/* ========== find_maximum ========== */

unsigned char find_maximum(unsigned char *arr, unsigned int n) {
    unsigned char max = arr[0];
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

/* ========== find_minimum ========== */

unsigned char find_minimum(unsigned char *arr, unsigned int n) {
    unsigned char min = arr[0];
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


/* Add other Implementation File Code Here */
