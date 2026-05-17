/******************************************************************************
 * Copyright (C) 2026 by Hung Chia Lyn
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Implementation of statistical analytics functions
 */

#include "stats.h"
#include "platform.h"

/* ========== print_statistics ========== */

void print_statistics(unsigned char *arr, unsigned int n) {
    PRINTF("  Minimum : %d\n", find_minimum(arr, n));
    PRINTF("  Maximum : %d\n", find_maximum(arr, n));
    PRINTF("  Mean    : %d\n", find_mean(arr, n));
    PRINTF("  Median  : %d\n", find_median(arr, n));
}

/* ========== print_array ========== */

void print_array(unsigned char *arr, unsigned int n) {

#ifdef VERBOSE

    unsigned int i;

    for (i = 0; i < n; i++) {
        PRINTF("  [%2d] = %3d", i, *(arr + i));

        if ((i + 1) % 4 == 0) {
            PRINTF("\n");
        }
    }

    PRINTF("\n");

#endif

}

/* ========== sort_array : large to small ========== */

void sort_array(unsigned char *arr, unsigned int n) {
    unsigned int i;
    unsigned int j;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (*(arr + j) < *(arr + j + 1)) {
                unsigned char temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

/* ========== find_median ========== */

unsigned char find_median(unsigned char *arr, unsigned int n) {
    unsigned char temp[n];
    unsigned int i;

    for (i = 0; i < n; i++) {
        *(temp + i) = *(arr + i);
    }

    sort_array(temp, n);

    if (n % 2 == 0) {
        return (unsigned char)((*(temp + (n / 2 - 1)) + *(temp + (n / 2))) / 2);
    } else {
        return *(temp + (n / 2));
    }
}

/* ========== find_mean ========== */

unsigned char find_mean(unsigned char *arr, unsigned int n) {
    unsigned int sum = 0;
    unsigned int i;

    for (i = 0; i < n; i++) {
        sum += *(arr + i);
    }

    return (unsigned char)(sum / n);
}

/* ========== find_maximum ========== */

unsigned char find_maximum(unsigned char *arr, unsigned int n) {
    unsigned char max = *arr;
    unsigned int i;

    for (i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    return max;
}

/* ========== find_minimum ========== */

unsigned char find_minimum(unsigned char *arr, unsigned int n) {
    unsigned char min = *arr;
    unsigned int i;

    for (i = 1; i < n; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
    }

    return min;
}
