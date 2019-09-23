#include <stdio.h>
#include <errno.h>
#include <string.h>

extern int errno;

int main()
{
    FILE * pf;
    int errnum;
    pf = fopen("unexist.txt", "rb");
    if (pf == NULL)
    {
        errnum = errno;
	fprintf(stderr, "errno is : %d\n", errno);
	perror("the detail of perror is : ");
	fprintf(stderr, "error info : %s\n", strerror(errnum));
    } else {
        fclose(pf);
    }
    return 0;
}    
