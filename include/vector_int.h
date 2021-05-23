#ifndef VECTOR_INT_H_
#define VECTOR_INT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* _items;
    int size;
} VectorInt;

typedef int* IteratorInt;

VectorInt createVectorInt(int init) {
    VectorInt v;
    v._items = (int*) malloc(sizeof(int));
    v._items[0] = init;
    v.size = 1;
    return v;
}

int sizeInt(VectorInt* v) {
    return v->size;
}

int frontInt(VectorInt* v) {
    return v->_items[0];
}

int backInt(VectorInt* v) {
    return v->_items[v->size - 1];
}

int getAtInt(VectorInt* v, int pos) {
    return v->_items[pos];
}

void setAtInt(VectorInt* v, int pos, int n) {
    v->_items[pos] = n;
}

void pushInt(VectorInt* v, int item) {
    v->_items = (int*) realloc(v->_items, (v->size + 1) * sizeof(int));
    if (v->_items == NULL) {
        printf("Fail to allocate memory, halting process.");
        exit(0);
    }

    ++v->size;

    v->_items[v->size - 1] = item;
}

void popInt(VectorInt* v) {
   v->_items = (int*) realloc(v->_items, (v->size - 1) * sizeof(int));
   if (v->_items == NULL) {
       printf("Fail to reallocate memory, halting process.");
       exit(0);
   }

   --v->size;
}

void eraseInt(VectorInt* v, int pos1, int pos2) {
    for (int i = pos1; i <= pos2; ++i) {
        v->_items[i] = 0;
    }
}

void clearInt(VectorInt* v) {
    v->_items = (int*) realloc(v->_items, sizeof(int));
    if (v->_items == NULL) {
        printf("Fail to reallocate memory, halting process.");
        exit(0);
    }

    v->_items[0] = 0;
    v->size = 1;
}

IteratorInt beginInt(VectorInt* v) {
    return v->_items;
}

IteratorInt endInt(VectorInt* v) {
    return v->_items + v->size;
}

#endif
