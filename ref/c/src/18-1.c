#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    int (* p)(int, int) = &max;
    int a, b, c, d;

    printf("please enter three number: ");
    scanf("%d %d %d", &a, &b, &c);

    d = p(p(a, b), c);

    printf("the max number is : %d\n", d);

    return 0;
}
