#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jetrikotno(int st){
	if(st==1)
		return 1;
	for (int i=0; i<st; i++){
		if((i*(i+1))/2==st){
			return 1;
		}
	}
	return 0;
}


int main(int argc, char *argv[]){

	FILE *files;
	files = fopen(argv[1],"r");
	if (files==NULL){
		printf("Datoteka ne obstaja \n");
		exit(1);
	}
	printf("je trikotno %d  => %d",55,jetrikotno(55));
	
	char beseda[30];
	int st=0;
	while(!feof(files)){
		fscanf(files, "%s", beseda );
		int sum=0;
		
		for(int i=0; i<strlen(beseda); i++){
			sum+=beseda[i]-'A'+1;	
		}
		st+=jetrikotno(sum);
		
	}	
	printf("\n St trikotnih besed je %d", st);

	return 0;
}
