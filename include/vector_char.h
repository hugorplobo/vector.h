#ifndef VECTOR_CHAR_H_
#define VECTOR_CHAR_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* _items;
    int size;
} vectorChar;

typedef char* iteratorChar;

vectorChar createVectorChar(char init) {
    vectorChar v;
    v._items = (char*) malloc(sizeof(char));
    v._items[0] = init;
    v.size = 1;
    return v;
}

int sizeChar(vectorChar* v) {
    return v->size;
}

char frontChar(vectorChar* v) {
    return v->_items[0];
}

char backChar(vectorChar* v) {
    return v->_items[v->size - 1];
}

char getAtChar(vectorChar* v, int pos) {
    return v->_items[pos];
}

void setAtChar(vectorChar* v, int pos, char n) {
    v->_items[pos] = n;
}

void pushChar(vectorChar* v, char item) {
    v->_items = (char*) realloc(v->_items, (v->size + 1) * sizeof(char));
    if (v->_items == NULL) {
        printf("Fail to allocate memory, halting process.");
        exit(0);
    }

    ++v->size;

    v->_items[v->size - 1] = item;
}

void popChar(vectorChar* v) {
   v->_items = (char*) realloc(v->_items, (v->size - 1) * sizeof(char));
   if (v->_items == NULL) {
       printf("Fail to reallocate memory, halting process.");
       exit(0);
   }

   --v->size;
}

void eraseChar(vectorChar* v, int pos1, int pos2) {
    for (int i = pos1; i <= pos2; ++i) {
        v->_items[i] = ' ';
    }
}

void clearChar(vectorChar* v) {
    v->_items = (char*) realloc(v->_items, sizeof(char));
    if (v->_items == NULL) {
        printf("Fail to reallocate memory, halting process.");
        exit(0);
    }

    v->_items[0] = ' ';
    v->size = 1;
}

iteratorChar beginChar(vectorChar* v) {
    return v->_items;
}

iteratorChar endChar(vectorChar* v) {
    return v->_items + v->size;
}

#endif
