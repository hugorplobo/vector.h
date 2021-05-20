#include <stdio.h>
#include "vector.h"

int main() {
    vector teste = createVector(78);
    add(&teste, 5);
    add(&teste, 10);
    add(&teste, 98);
    for (int i = 0; i < teste.size; ++i) {
        printf("%d ", teste._items[i]);
    }
    return 0;
}
