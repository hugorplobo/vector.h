#ifndef VECTOR_DOUBLE_H_
#define VECTOR_DOUBLE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* _items;
    int size;
} VectorDouble;

typedef double* IteratorDouble;

VectorDouble createVectorDouble(double init) {
    VectorDouble v;
    v._items = (double*) malloc(sizeof(double));
    v._items[0] = init;
    v.size = 1;
    return v;
}

int sizeDouble(VectorDouble* v) {
    return v->size;
}

double frontDouble(VectorDouble* v) {
    return v->_items[0];
}

double backDouble(VectorDouble* v) {
    return v->_items[v->size - 1];
}

double getAtDouble(VectorDouble* v, int pos) {
    return v->_items[pos];
}

void setAtDouble(VectorDouble* v, int pos, double n) {
    v->_items[pos] = n;
}

void pushDouble(VectorDouble* v, double item) {
    v->_items = (double*) realloc(v->_items, (v->size + 1) * sizeof(double));
    if (v->_items == NULL) {
        printf("Fail to allocate memory, halting process.");
        exit(0);
    }

    ++v->size;

    v->_items[v->size - 1] = item;
}

void popDouble(VectorDouble* v) {
   v->_items = (double*) realloc(v->_items, (v->size - 1) * sizeof(double));
   if (v->_items == NULL) {
       printf("Fail to reallocate memory, halting process.");
       exit(0);
   }

   --v->size;
}

void eraseDouble(VectorDouble* v, int pos1, int pos2) {
    for (int i = pos1; i <= pos2; ++i) {
        v->_items[i] = 0.0;
    }
}

void clearDouble(VectorDouble* v) {
    v->_items = (double*) realloc(v->_items, sizeof(double));
    if (v->_items == NULL) {
        printf("Fail to reallocate memory, halting process.");
        exit(0);
    }

    v->_items[0] = 0.0;
    v->size = 1;
}

IteratorDouble beginDouble(VectorDouble* v) {
    return v->_items;
}

IteratorDouble endDouble(VectorDouble* v) {
    return v->_items + v->size;
}

#endif
