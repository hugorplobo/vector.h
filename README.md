# vector.h
A simple header that provide a based C++ vector structure in C

## How it works
The library uses dynamic memory allocation to create a container structure that resize itself based on its elements.

### Limitations
Since it's build in C, there are no classes, templates or overloading, so there are 4 headers, one for each primitive type (_char, int, float, double_). I have plans to implement a generic version using void ponters and type casting them.

## Installation

Just add the `vector_*.h` (pick the types you need) from `include/vector/vector*.h` file to your project's include folder.

- Example with gcc

`gcc test.c - o build/test -Iinclude`

## Usage

The headers contain declaration for:

1. A struct representing the vector
2. A iterator type
3. Some functions

Just `#include` the header you need and create a new Vector as shown below:

```c
#include <vector/vector_int.h>

int main() {
    VectorInt numbers = createVectorInt(0);
    return 0;
}
```

**Important:** If your project doesn't have a include folder, use the `#include "vector_*.h"` directive instead!

## Ok, but what can I do with this thing?

As mentioned above, there are 4 four types of vector: char, int, float and double. All the funcions below are defined for all types, you just need to add the type as a sufixe, like that: `pushInt`, `pushChar`, `pushFloat`, `pushDouble`. All the examples uses int, so don't forget to change it to your type.

1. `VectorInt createVectorInt(int initValue)`
> Returns a new vector of that type

```c
VectorInt vector = createVectorInt(100); // A new vector whose first element is 100
```

2. `int sizeInt(VectorInt*)`
> Returns the vector's size

```c
int size = sizeInt(&vector); // Receives a vector pointer and return its size;
```

3. `int frontInt(VectorInt*)`
> Returns the vector's first element

```c
int element = frontInt(&vector);
```

4. `int backInt(VectorInt*)`
> Returns the vector's last element

```c
int anotherElement = backInt(&vector);
```

5. `int getAtInt(VectorInt*, int position)`
> Returns the element at this position (Array-like indexes)

```c
int thirdElement = getAtInt(&vector, 2);
```

6. `void setAtInt(VectorInt*, int position, int value)`
> Set a value at that position (Array-like indexes)

```c
setAtInt(&vector, 3, 9876);
```

7. `void pushInt(VectorInt*, int value)`
> Add the value as the last element (Resizes the vector)

```c
VectorInt list = CreateVectorInt(5); // [5]
pushInt(&list, 4); // [5, 4]
pushInt(&list, 3); // [5, 4, 3]
pushInt(&list, 2); // [5, 4, 3 ,2]
pushInt(&list, 1); // [5, 4, 3, 2, 1]
```

8. `void popInt(VectorInt*)`
> Removes the last vector's element (Resizes the vector)

```c
// list is the same vector above [5, 4, 3, 2, 1]
popInt(&list); // [5, 4, 3, 2]
popInt(&list); // [5, 4, 3]
```

9. `void eraseInt(VectorInt*, int firstPosition, int lastPosition)`
> Set all elements inside range in 0 or ' '

```c
// list is [5, 4, 3, 2, 1]
eraseInt(&list, 1, 4); // [5, 0, 0, 0, 0]
```

10. `void clearInt(VectorInt*)`
> Set all elements to 0 or ' '

```c
// you know list [5, 4, 3, 2, 1]
clearInt(&list); // [0, 0, 0, 0, 0]
```

11. `IteratorInt beginInt(VectorInt*)`
> Returns a pointer to the first element (The example will be in the next function)

12. `IteratorInt endInt(VectorInt*)`
> Returns a pointe to the first element

```c
VectorInt numbers = createVectorInt(0);

for (int i = 1; i <= 5; ++i) {
    pushInt(&numbers, i);
}

for (IteratorInt i = beginInt(&numbers); i != endInt(&numbers); ++i) {
    printf("%d", *i); // The iterator is a pointer
}
```

-----

Thanks for visiting my repository!
