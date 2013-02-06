#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *files;
	files = fopen(argv[1],"r");
	if (files==NULL){
		printf("Datoteka ne obstaja \n");
		exit(1);
	}

	int pojavitve[10] = {0};
	int c;
	while(feof(files) == 0){
		c = fgetc(files);
		c = c-'0';
		if(c >=0 && c <=9){
			pojavitve[c]++;
		}
		
	}
	for (int i = 0; i < 10; i++){
		printf("%d=%d,",i,pojavitve[i]);
	}
	return 0;
}
//funkcija string v stevilo
int chtoi(char *c){
	int x = 0;
	for(int i=0; i<strlen(c); i++){
		x=10*x+(c[i]-'0');
	}
	return x;
}

