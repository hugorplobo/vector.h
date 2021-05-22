#ifndef VECTOR_FLOAT_H_
#define VECTOR_FLOAT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float* _items;
    int size;
} vectorFloat;

typedef float* iteratorFloat;

vectorFloat createVectorFloat(float init) {
    vectorFloat v;
    v._items = (float*) malloc(sizeof(float));
    v._items[0] = init;
    v.size = 1;
    return v;
}

int sizeFloat(vectorFloat* v) {
    return v->size;
}

float frontFloat(vectorFloat* v) {
    return v->_items[0];
}

float backFloat(vectorFloat* v) {
    return v->_items[v->size - 1];
}

float getAtFloat(vectorFloat* v, int pos) {
    return v->_items[pos];
}

void setAtFloat(vectorFloat* v, int pos, float n) {
    v->_items[pos] = n;
}

void pushFloat(vectorFloat* v, float item) {
    v->_items = (float*) realloc(v->_items, (v->size + 1) * sizeof(float));
    if (v->_items == NULL) {
        printf("Fail to allocate memory, halting process.");
        exit(0);
    }

    ++v->size;

    v->_items[v->size - 1] = item;
}

void popFloat(vectorFloat* v) {
   v->_items = (float*) realloc(v->_items, (v->size - 1) * sizeof(float));
   if (v->_items == NULL) {
       printf("Fail to reallocate memory, halting process.");
       exit(0);
   }

   --v->size;
}

void eraseFloat(vectorFloat* v, int pos1, int pos2) {
    for (int i = pos1; i <= pos2; ++i) {
        v->_items[i] = 0.0;
    }
}

void clearFloat(vectorFloat* v) {
    v->_items = (float*) realloc(v->_items, sizeof(float));
    if (v->_items == NULL) {
        printf("Fail to reallocate memory, halting process.");
        exit(0);
    }

    v->_items[0] = 0.0;
    v->size = 1;
}

iteratorFloat beginFloat(vectorFloat* v) {
    return v->_items;
}

iteratorFloat endFloat(vectorFloat* v) {
    return v->_items + v->size;
}

#endif
