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

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]) {
  if(argc>3){
     int a = atoi(args[1]);
	  int x = atoi(args[2]);
	  int y = atoi(args[3]);


	 if(a==1)
	  printf("%d + %d = %d\n", x, y, x+y);
	if (a==2) 
	 printf("%d - %d = %d\n", x, y, x-y);
	 if(a==3) 
		printf("%d * %d = %d\n", x, y, x*y);
	if(a==4){
	  int stdec;
	  scanf("%d", &stdec);
	  printf("%d / %d = %.*f\n", x, y, stdec, (float)x/y);
	}
	}
  return 0;
}

