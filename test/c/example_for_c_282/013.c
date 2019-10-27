#include <stdio.h>

int main() {
    int i, x, y, z = 1;
    printf("Please enter two number x and y (x^y):\n");
    scanf("%d%d", &x, &y);
    for (i = 1; i <= y; i++) {
        z = z * x % 1000;
    }
    if (z >= 100) {
        printf("%d^%d mod 1000 : %d\n", x, y, z);
    } else {
        printf("%d^%d mod 1000 : 0%d\n", x, y, z);
    }

    return 0;
}