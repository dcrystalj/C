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

int main(int argc, char *argv[])
{	
	FILE *files;
	files = fopen("datlsla.txt","r");
	if (files==NULL){
		printf("Datoteka ne obstaja \n");
		exit(1);
	}
	
	char n1[30], n2[30], n3[30];
	char vrstica[200];
	int s1, s2;
	int vsota =0, n=0;
	while(!feof(files)){
		int p = fscanf(files, "%s%d%s%s%d", n1, &s1, n2, n3, &s2);
		if(p == 5) {
			fgets(vrstica,200,files);
			printf("%d\n",s2);
			vsota = vsota + s2;
			n++;
		}
	}
	int pov=1.0*vsota/n;
	printf("povprecna dolzina je %d", pov);
	
	fclose(files);


	files = fopen("datlsla.txt","r");
	if (files==NULL){
		printf("Datoteka ne obstaja \n");
		exit(1);
	}

	while(!feof(files)){
		int p = fscanf(files, "%s%d%s%s%d", n1, &s1, n2, n3, &s2);
		int razlika = abs(pov-s2);
		fgets(vrstica,200,files);
		if(razlika>0.2*pov){	
			printf("%d %s",s2, vrstica);
		}
		
		
	}
	fclose(files);
    return 0;
}

