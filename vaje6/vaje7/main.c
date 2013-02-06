#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#define N 7
int koliko=0;
int tabela[N];

int jezevtabeli(int x){
	for(int i=1; i<=7; i++){
		if(tabela[i]==x)
			return 1;
	}
	return 0;
}

void uredi(int t[], int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=1; j<n; j++){
			if(t[i]<t[j]){
				int tmp = t[i];
				t[i]=t[j];
				t[j]=tmp;
			}
		}
	}
}


int primerjava(const void *x, const void *y){
	return *(int*)x - *(int*)y;
}

int main(void){

	srand(time(NULL));

	for(int i=1; i<=7; i++){
		int x = rand() % 39 +1;
		if(!jezevtabeli(x))
			tabela[koliko++]=x;
	}
	//uredi(tabela,N);
	
	qsort(tabela,N,sizeof(int),primerjava);
	for(int i=1; i<=7; i++){
		printf("%d ",tabela[i]);
	}
	char vrstica[] = "abc:def:xzy";
	char locila[] = ":";
	char *rezultat;

	rezultat = strtok(vrstica, locila);
	printf("rezultat : %s", rezultat);

	

	while(rezultat != NULL){
	
		printf("rezultat : %s", rezultat);
		rezultat = strtok(NULL, locila);
	}
	rezultat = strtok(vrstica, locila);
	printf("rezultat : %s", rezultat);
}
