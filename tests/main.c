#include <stdio.h>
#include "vector_int.h"
#include "vector_char.h"
#include "vector_float.h"
#include "vector_double.h"

int main() {
    vectorInt testInt = createVectorInt(1);

    pushInt(&testInt, 2);
    pushInt(&testInt, 3);
    pushInt(&testInt, 4);

    popInt(&testInt);

    getAtInt(&testInt, 2);

    clearInt(&testInt);

    vectorChar testChar = createVectorChar('H');

    pushChar(&testChar, 'u');
    pushChar(&testChar, 'g');
    pushChar(&testChar, 'o');

    popChar(&testChar);

    getAtChar(&testChar, 3);

    clearChar(&testChar);

    vectorFloat testFloat = createVectorFloat(0.0);

    pushFloat(&testFloat, 8.5);
    pushFloat(&testFloat, 76.34);
    pushFloat(&testFloat, 1987.273);

    popFloat(&testFloat);

    getAtFloat(&testFloat, 1);

    clearFloat(&testFloat);

    vectorDouble testDouble = createVectorDouble(0.0);

    pushDouble(&testDouble, 9827.28134);
    pushDouble(&testDouble, 34567.9987654);
    pushDouble(&testDouble, 12.09876543456);

    popDouble(&testDouble);

    getAtDouble(&testDouble, 0);

    clearDouble(&testDouble);

    return 0;
}
