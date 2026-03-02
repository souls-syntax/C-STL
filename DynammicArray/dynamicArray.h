#pragma once

#include "stdio.h"
#include <stdlib.h>

#define ARRAY_INIT_CAPACITY 20


typedef struct  {
  size_t count;
  size_t capacity;
} Header ;


#define array_push(array, element)                                                                \
  do {                                                                                            \
    if (array == NULL) {                                                                          \
      Header *header = malloc((sizeof(*array)* ARRAY_INIT_CAPACITY) + sizeof(Header));            \
      header-> count = 0;                                                                         \
      header-> capacity = ARRAY_INIT_CAPACITY;                                                    \
      array = (void *)(header + 1);                                                               \
    };                                                                                            \
    Header *header = ((Header *)array - 1);                                                       \
    if(header->count >= header->capacity) {                                                       \
      header->capacity *=2;                                                                       \
      header = realloc(header, (sizeof(*array) * header->capacity) + sizeof(Header));             \
      array = (void *)(header + 1);                                                               \
    };                                                                                            \
    array[header->count++] = element;                                                             \
  } while(0)                                                                              

#define array_free(array) free((Header *)(array) - 1)

#define array_length(array) ((Header*)(array)-1)->count

