#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

typedef struct {
  char *ime;
  char *priimek;
  char *telefon;
} oseba;

int main(int argc, char *argv[])
{
	FILE *files;
	files = fopen("imenik.txt","r");
   
	
	if (files==NULL){
		printf("Datoteka ne obstaja \n");
		exit(1);
	}
	
	int st=0;
	int dolzinatabele=1;
	fscanf(files, "%d", &dolzinatabele);

	oseba *o;
	o = malloc(dolzinatabele*sizeof(oseba));
	
	st+=dolzinatabele*sizeof(oseba);

	char str[100];
	fgets(str,sizeof(str),files);
	for(int i=0; i<dolzinatabele;i++){
		fgets(str,sizeof(str),files);
	
		char locila[] = ":";
		char *ime; char *priimek; char *phone;

		ime=strtok(str, locila);
		priimek = strtok(NULL, locila);
		phone = strtok(NULL, locila);
		strtok(NULL, locila);
		(o+i)->ime= malloc(sizeof(char)* strlen(ime));
		(o+i)->priimek= malloc(sizeof(char)* strlen(priimek));
		(o+i)->telefon= malloc(sizeof(char)* strlen(phone));
		
		
		(o+i)->ime=ime;
		(o+i)->priimek=priimek;
		(o+i)->telefon = phone; //alternativni nacin

		st=st+sizeof(char)* strlen(priimek)+sizeof(char)* strlen(ime)+sizeof(char)* strlen(phone);
	}
	printf("Poraba pomnilnika je %d B",st);

}

