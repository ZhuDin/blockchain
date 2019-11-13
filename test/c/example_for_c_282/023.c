#include <stdio.h>

int main() {
    int i, j, t, a[11];
    printf("please enter 10 number\n");
    for(i=1;i<11;i++) {
        scanf("%d", &a[i]);
    }
    for(i=1;i<=9;i++) {
        for(j=1+i;j<=10;j++) {
            if(a[i]>a[j]) {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    printf("after rearrange the order is:\n");
    for(i=1;i<=10;i++) {
        printf("%5d", a[i]);
    }
    printf("\n");
}