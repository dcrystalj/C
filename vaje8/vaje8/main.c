#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

typedef struct tocka {
	char ime[5];
	float x;
	float y;
}tocka;

double absol(tocka t){
	float x; float y;
	x = t.x;
	y = t.y;
	return sqrt(pow(x ,2) + pow(y,2));
}

int primerjava(const void *t1, const void *t2){
	double f = absol(*(tocka*)t1)- absol(*(tocka*)t2);
	if(f>0)
		return 1;
	else if(f<0)
		return -1;
	else
		return 0;
}

int main(int argc, char *argv[])
{

	setlocale(LC_NUMERIC,"");
	FILE *files;
	files = fopen("tocke.txt","r");
	
	if (files==NULL){
		printf("Datoteka ne obstaja \n");
		exit(1);
	}
	
	int dolzinatabele=1;
	fscanf(files, "%d", &dolzinatabele);
	tocka tab[dolzinatabele];
	int i=0;
	for(i=0;i<dolzinatabele;i++){
		fscanf(files,"%s %f %f",tab[i].ime, &tab[i].x, &tab[i].y);
	}

	if(!strcmp(argv[1],"ABS")){
		for(i=0;i<dolzinatabele-1;i++){
			for(int j=i;j<dolzinatabele;j++){
				float diffx= tab[i].x-tab[j].x;
				float diffy= tab[i].y-tab[j].y;
				float razdalja = sqrt(pow(diffx,2)+pow(diffy,2));

				float cmp = 1.002*( sqrt(pow(tab[i].x,2)+pow(tab[i].y,2)) - sqrt(pow(tab[j].x,2)+pow(tab[j].y,2)) );
				if(cmp<0)
					cmp*=-1;
				if(razdalja<cmp){
					printf("%s - %s\n",tab[i].ime,tab[j].ime);
					
				}

			}
		}
	}

	if(!strcmp(argv[1],"UREDI")){
		qsort(tab,dolzinatabele,sizeof(tocka),primerjava);

		for(int j=0;j<dolzinatabele;j++){
			double absolute = absol(tab[j]);
			if(absolute>1)
				printf("%s - (%.2f, %.2f) \t%.15lf \n",tab[j].ime,tab[j].x,tab[j].y,absol(tab[j]));
		}
	}
	fclose(files);
}

