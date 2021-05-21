#include <stdio.h>
#include "vector.h"

int main() {
    vector teste = createVector(1);

    push(&teste, 2);
    push(&teste, 3);
    push(&teste, 4);

    printf("Iterators: \n");

    for (iterator i = begin(&teste); i != end(&teste); ++i) {
        printf("%d ", *i);
    }

    printf("\n\nPop: \n");

    pop(&teste);

    printf("%d", back(&teste));

    return 0;
}
