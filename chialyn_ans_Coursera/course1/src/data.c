/******************************************************************************
 * @file data.c
 * @brief Data manipulation functions
 *****************************************************************************/

#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  uint8_t *start = ptr;
  uint8_t *end;
  uint8_t temp;
  uint8_t length = 0;
  uint8_t negative = 0;
  uint32_t value;
  uint32_t digit;

  if (base < 2 || base > 16) {
    *ptr = '\0';
    return 1;
  }

  if (data < 0) {
    negative = 1;
    value = (uint32_t)(-data);
  } else {
    value = (uint32_t)data;
  }

  do {
    digit = value % base;

    if (digit < 10) {
      *ptr = (uint8_t)('0' + digit);
    } else {
      *ptr = (uint8_t)('A' + (digit - 10));
    }

    ptr++;
    length++;
    value = value / base;

  } while (value != 0);

  if (negative) {
    *ptr = '-';
    ptr++;
    length++;
  }

  *ptr = '\0';
  length++;

  end = ptr - 1;

  while (start < end) {
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }

  return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
  int32_t result = 0;
  int32_t sign = 1;
  uint8_t current;
  uint32_t value;
  uint8_t count = 0;

  if (base < 2 || base > 16) {
    return 0;
  }

  if (*ptr == '-') {
    sign = -1;
    ptr++;
    count++;
  }

  while (count < digits - 1) {
    current = *ptr;

    if (current >= '0' && current <= '9') {
      value = (uint32_t)(current - '0');
    } else if (current >= 'A' && current <= 'F') {
      value = (uint32_t)(current - 'A' + 10);
    } else if (current >= 'a' && current <= 'f') {
      value = (uint32_t)(current - 'a' + 10);
    } else {
      value = 0;
    }

    result = (result * (int32_t)base) + (int32_t)value;

    ptr++;
    count++;
  }

  return result * sign;
}
