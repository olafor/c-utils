#ifndef ARRAY
#define ARRAY

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void initArray(Array*, size_t);
void appendArray(Array*, int);
void freeArray(Array*);

#endif
