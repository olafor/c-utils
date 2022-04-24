#include "array.h"

void initArray(Array *arr, size_t initSize) {
    arr->array = malloc(INIT_SIZE * sizeof(int));
    arr->used = 0;
    arr->size = INIT_SIZE;
}

void appendArray(Array *arr, int element) {
    if (arr->used == arr->size) {
        arr->size *= 2;
        arr->array = realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

void freeArray(Array *arr) {
    free(arr->array);
    arr->array = NULL;
    arr->used = arr->size = 0;
}


