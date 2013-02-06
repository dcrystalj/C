#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *files;
	files = fopen(strcat(argv[3],".txt"),"r");
	
	if (files==NULL){
		printf("Datoteka ne obstaja \n");
		exit(1);
	}

	char str[200];
	while(fgets(str,sizeof(str),files) != NULL){
		//printf("\n%s", str);
		char locila[] = ":";
		char *name; char *path; char *rez;


		name = strtok(str, locila);
		strtok(NULL, locila);
		int min = atoi(strtok(NULL, locila));
		
		if(min>=atoi(argv[1]) && min<=atoi(argv[2])){
			path=strtok(NULL, locila);
			while(path != NULL){
				rez=path;
				path=strtok(NULL, locila);
			}
			printf("%s - %s \n", name,rez);
		}
		
	/*
		while(rezultat != NULL){
		
			printf("rezultat : %s", rezultat);
			rezultat = strtok(NULL, locila);
		}
		rezultat = strtok(vrstica, locila);
		printf("rezultat : %s", rezultat);*/
	}
	
}
