#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char c;  
	FILE *vhod;
	vhod = fopen("a.txt","r");
	
	if(vhod==NULL){
		printf("napaka pri odpiranju datoteke");
		exit(0);
	}
	int stevec = 0;
	int wc = 0;
	int lines = 0;
	int chars = 0;

	while(feof(vhod) == 0){
		c = fgetc(vhod);
		if(isspace(c) != 0){ 
			
			if(c=='\n'){
				lines++;
			}
			stevec=1;
		}
		else{
			if(stevec==1){
				stevec=0;
				wc++;
			}
		}
		chars++;

		if(c==EOF){
			if(isspace(c) == 0){ 
				lines++;
				wc++;
			}
			break;
		}
	}
	printf("chars %d wc %d lines %d ",chars, wc, lines);

	fclose(vhod);
	return 0;
}
