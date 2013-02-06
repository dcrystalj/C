#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]){
	int ura=0;
	int min=0;
	int sec=0;
	int i=0;
	int j=0;
	if (argc>1){
		int a=atoi(argv[1]);
		if (a==1 && argc>3){
			int i=atoi(argv[2]);
			int j=atoi(argv[3]);
			for(i;i<=j;i++){
				ura=i/3600;
				min=i/60;
				sec=i-(min*60+ura*3600);
				printf("%d sekund je %d ur, %d minut, %d sekund \n",i,ura,min,sec);
			}
		}
		else if (a==2&& argc>2){
			int i=atoi(argv[2]);
			ura=i/3600;
			min=i/60;
			sec=i-(min*60+ura*3600);
			printf("%d sekund je %d ur, %d minut, %d sekund \n",i,ura,min,sec);
		
		}

		else if (a==3&& argc>4){
			ura=atoi(argv[2]);
			min=atoi(argv[3]);
			sec=atoi(argv[4]);
			int tmp=ura*3600+min*60+sec;
			printf("%d ura, %d minut, %d sekund je %d sekund \n",ura,min,sec,tmp);
		}

	}
	else{ //d 
		int a;
		printf("katero akcijo naj izvedem?");
		scanf("%d", &a);
		
		if (a==1){
			printf("Vpisi zacetek tabele");
			scanf("%d", &i);

			printf("Vpisi konec tabele");
			scanf("%d", &j);
			for(i;i<=j;i++){
				ura=i/3600;
				min=i/60;
				sec=i-(min*60+ura*3600);
				printf("%d sekund je %d ur, %d minut, %d sekund \n",i,ura,min,sec);
			}
		}
		else if (a==2){
			printf("Vpisi sekunde");
			scanf("%d", &i);
			ura=i/3600;
			min=i/60;
			sec=i-(min*60+ura*3600);
			printf("%d sekund je %d ur, %d minut, %d sekund \n",i,ura,min,sec);
		
		}

		else if (a==3){
			printf("Vpisi uro");
			scanf("%d", &ura);
			printf("Vpisi minute");
			scanf("%d", &min);
			printf("Vpisi sekunde");
			scanf("%d", &sec);
			int tmp=ura*3600+min*60+sec;
			printf("%d ura, %d minut, %d sekund je %d sekund \n",ura,min,sec,tmp);
		}
	}
	return 0;
}
