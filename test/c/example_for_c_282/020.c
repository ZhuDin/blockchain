#include <stdio.h>

int shsort(int s[], int n) {
    int i, j, d;
    d = n / 2;
    while (d >= 1) {
        for (i=d+1; i<=n; i++) {
            s[0] = s[i];
            j = i - d;
            while ((j > 0) && (s[0] < s[j])) {
                s[j + d] = s[j];
                j = j - d;
            }
            s[j + d] = s[0];
        }
        d = d / 2;
    }
}

int main() {
    int a[11], i;
    printf("please enter 10 number: \n");
    for (i = 1; i <= 10; i++) {
        scanf("%d", &a[i]);
    }
    shsort(a, 10);
    printf("after shsort the sequence is : \n");
    for (i = 1; i <= 10; i++) {
        printf("%5d", a[i]);
    }
    printf("\n");
    
    return 0;
}