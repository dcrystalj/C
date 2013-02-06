#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define L 10 //dolzina tabele
#define oddo 100
int tab[L];

int getmax(int tab[], int n){
	int max = 0;
	for(int i=0; i<L; i++){
		if(tab[i]>max)
			max = tab[i];
	}
	return max;
}

int main(int argc, char *argv[]){
	int N=atoi(argv[1]);
	int M=atoi(argv[2]);

	srand(time(NULL));

	for(int i=1; i<=N; i++){
		int x = rand() % oddo +1;
		tab[x/10]++;
	}
	printf("\n");
	int max = 1;
	while(max>0){
		max = getmax(tab,L);
		if(max==0)
			break;
		if(max>M)
			max=M;
		for(int i=0; i<L; i++){
			if(tab[i]>max){
				tab[i]=max;
			}
			if(tab[i]==max){
				printf("%c \t",'o');
				tab[i]--;
			}
			else
				printf("%c \t",' ');
		}
		printf("\n");
	}
	
	printf("-------------------------------------------------------------------------- \n");
	
	for(int i=0; i<L; i++){
		printf("%d-%d \t",i*10+1,(i+1)*10);
	}
	return 0;
}
