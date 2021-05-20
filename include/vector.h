#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* _items;
    int size;
} vector;

vector createVector(int init) {
    vector v;
    v._items = (int*) malloc(sizeof(int));
    v._items[0] = init;
    v.size = 1;
    return v;
}

void add(vector* v, int item) {
    v->_items = realloc(v->_items, (v->size + 1) * sizeof(int));
    // int* ptr = (int*) malloc((v->size + 1) * sizeof(int));
    if (v->_items == NULL) {
        printf("Fail to allocate memory, halting process.");
        exit(0);
    }

    //for (int i = 0; i < v->size; ++i) {
        //ptr[i] = v->_items[i];
    //}

    ++v->size;

    v->_items[v->size - 1] = item;
}

#endif
