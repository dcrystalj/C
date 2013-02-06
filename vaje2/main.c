/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

int main(int argc, char *argv[])
{
    printf("Hello, world!\n");
	printf("%d", RAND_MAX);
	srand(123); //seme za random
	srand(time(NULL)); //seme glede na cas
	int i;
	for(i=0; i<10;i++){
		int x = rand();
		printf("%d \n", x);
	}
	//loto listek
	for(i=1; i<=7;i++){
		int x = rand() % 39 + 1;
		printf("%d \n", x);
	}

	//cas
	printf("time %d",time(NULL));
	return 0;
}

