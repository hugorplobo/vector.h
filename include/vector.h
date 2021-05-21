#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* _items;
    int size;
} vector;

typedef int* iterator;

vector createVector(int init) {
    vector v;
    v._items = (int*) malloc(sizeof(int));
    v._items[0] = init;
    v.size = 1;
    return v;
}

int size(vector* v) {
    return v->size;
}

int front(vector* v) {
    return v->_items[0];
}

int back(vector* v) {
    return v->_items[v->size - 1];
}

int getAt(vector* v, int pos) {
    return v->_items[pos];
}

void setAt(vector* v, int pos, int n) {
    v->_items[pos] = n;
}

void push(vector* v, int item) {
    v->_items = (int*) realloc(v->_items, (v->size + 1) * sizeof(int));
    if (v->_items == NULL) {
        printf("Fail to allocate memory, halting process.");
        exit(0);
    }

    ++v->size;

    v->_items[v->size - 1] = item;
}

void pop(vector* v) {
   v->_items = (int*) realloc(v->_items, (v->size - 1) * sizeof(int));
   if (v->_items == NULL) {
       printf("Fail to reallocate memory, halting process.");
       exit(0);
   }

   --v->size;
}

void erase(vector* v, int pos1, int pos2) {
    for (int i = pos1; i <= pos2; ++i) {
        v->_items[i] = 0;
    }
}

void clear(vector* v) {
    v->_items = (int*) realloc(v->_items, sizeof(int));
    if (v->_items == NULL) {
        printf("Fail to reallocate memory, halting process.");
        exit(0);
    }

    v->_items[0] = 0;
    v->size = 1;
}

int* begin(vector* v) {
    return v->_items;
}

int* end(vector* v) {
    return v->_items + v->size;
}

#endif
