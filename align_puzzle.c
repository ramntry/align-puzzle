#include <stdio.h>
#define N 2
#define BASE 0

typedef union
{
    struct
    {
        unsigned char f;
        unsigned short s;
        unsigned int i;
        unsigned char l;
    };
    unsigned short a;
} Type;

int main()
{
    Type array[N];
    unsigned short i; 
    int capacity = sizeof(Type) / sizeof(i);
    for (i = 0; i < N*capacity; i++)
        *(&array[i / capacity].a + i % capacity) = i + BASE;
    
    for (i = 0; i < N; i++)
        printf("array[%u]:\n\tf = %u\n\ts = %u\n\ti = %u\n\tl = %u\n",
                i, array[i].f, array[i].s, array[i].i, array[i].l);
    return 0;
}

