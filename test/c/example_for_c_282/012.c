#include <stdio.h>

int main() {
    int n = 2, day = 0;
    float money = 0, ave;
    while (n < 100) {
        money += n * 0.8;
        day++;
        n *= 2;
    }
    ave = money / day;
    printf("The result is %0.6f.\n", ave);

    return 0;
}