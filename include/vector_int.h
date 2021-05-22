#ifndef VECTOR_INT_H_
#define VECTOR_INT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* _items;
    int size;
} vectorInt;

typedef int* iteratorInt;

vectorInt createVectorInt(int init) {
    vectorInt v;
    v._items = (int*) malloc(sizeof(int));
    v._items[0] = init;
    v.size = 1;
    return v;
}

int sizeInt(vectorInt* v) {
    return v->size;
}

int frontInt(vectorInt* v) {
    return v->_items[0];
}

int backInt(vectorInt* v) {
    return v->_items[v->size - 1];
}

int getAtInt(vectorInt* v, int pos) {
    return v->_items[pos];
}

void setAtInt(vectorInt* v, int pos, int n) {
    v->_items[pos] = n;
}

void pushInt(vectorInt* v, int item) {
    v->_items = (int*) realloc(v->_items, (v->size + 1) * sizeof(int));
    if (v->_items == NULL) {
        printf("Fail to allocate memory, halting process.");
        exit(0);
    }

    ++v->size;

    v->_items[v->size - 1] = item;
}

void popInt(vectorInt* v) {
   v->_items = (int*) realloc(v->_items, (v->size - 1) * sizeof(int));
   if (v->_items == NULL) {
       printf("Fail to reallocate memory, halting process.");
       exit(0);
   }

   --v->size;
}

void eraseInt(vectorInt* v, int pos1, int pos2) {
    for (int i = pos1; i <= pos2; ++i) {
        v->_items[i] = 0;
    }
}

void clearInt(vectorInt* v) {
    v->_items = (int*) realloc(v->_items, sizeof(int));
    if (v->_items == NULL) {
        printf("Fail to reallocate memory, halting process.");
        exit(0);
    }

    v->_items[0] = 0;
    v->size = 1;
}

iteratorInt beginInt(vectorInt* v) {
    return v->_items;
}

iteratorInt endInt(vectorInt* v) {
    return v->_items + v->size;
}

#endif
