
#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    printf("%d",sizeof(char));
    printf("%d",sizeof(int));
    printf("%d",sizeof(float));
    printf("%d",sizeof(long));
    printf("%d",sizeof(double));
	printf("INT_MAX: %d", INT_MAX);
	printf("%c",7);
    return 0;
}

