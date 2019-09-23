#include <stdio.h>

int main()
{
    unsigned int a = 60;
    unsigned int b = 13;
    printf("a = %d, b = %d", a, b);
    printf("\n");

    a = a^b;
    b = a^b;
    a = a^b;

    printf("a = %d, b = %d", a, b);
    printf("\n");
}
