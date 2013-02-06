#include <stdio.h>

#define N 10

int main(int argc, char *argv[])
{
	//FILE *f;
	//f = fopen("c:\\test.txt","r"); // r  w  a
	//fgets prebere niz iz datoteke
	//fgetc  prebere znak
	//fscanf
	//fputc zapise en znak
	//fprintf(f,"%d",x); 
	
	char niz[N+1];  //N == konstanta
	FILE *vhod;
	vhod = fopen("test.txt","r");
	
	if(vhod==NULL){
		printf("napaka pri odpiranju datoteke");
		exit (1);
	}

	while(feof(vhod) == 0){
		fgets(niz,N,vhod);
		printf("%s",niz);
	}

	fclose(vhod);
	return 0;
}
