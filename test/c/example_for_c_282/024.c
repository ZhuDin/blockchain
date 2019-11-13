#include <stdio.h>

void merge(int r[], int s[], int x1, int x2, int x3) {
    int i,j,k;
    i = x1;
    j = x2 + 1;
    k = x1;
    while((i<=x2)&&(j<=x3)) {
        if(r[i]<=r[j]) {
            s[k]=r[i];
            i++;
            k++;
        } else {
            s[k]=r[j];
            j++;
            k++;
        }
    }
    while(i<=x2) {
        s[k++] = r[i++];
    }
    while(i<=x3) {
        s[k++]=r[j++];
    }
}

void merge_sort(int r[], int s[], int m, int n) {
    int p;
    int t[20];
    if (m==n) {
        s[m] = r[m];
    } else {
        p=(m+n)/2;
        merge_sort(r,t,m,p);
        merge_sort(r,t,p+1,n);
        merge(t,s,m,p,n);
    }
}

int main() {
    int a[11];
    int i;
    printf("please enter 10 number\n");
    for (i=1; i<= 10; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(a,a,1,10);
    printf("after merge sort the list is :\n");
    for (i=1; i<=10; i++) {
        printf("%5d", a[i]);
    }
    printf("\n");
    return 0;
}