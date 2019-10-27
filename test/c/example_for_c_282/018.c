#include <stdio.h>
#include <math.h>
// compile this file use g++ command

int main() {
    float a, b, c;
    float s, area;
    scanf("%f,%f,%f", &a, &b, &c);
    if (a+b > c && b+c > a && a+c > b) {
        s = (a+b+c) / 2;
        area = (float)sqrt(s * (s-a) * (s-b) * (s-c));
        printf("the area is: %f\n", area);

        if (a==b && a==c) {
            printf("equilateral triangle\n");
        } else if (a==b || a==c || b==c) {
            printf("isosceles triangle\n");
        } else if ((a*a+b*b==c*c) || (a*a+c*c==b*b) || (b*b+c*c==a*a)) {
            printf("right-angled triangle\n");
        } else {
            printf("ordinary triangle\n");
        }
    } else {
        printf("this is not a tringle\n");
    }

    return 0;
}