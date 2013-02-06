#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[]){
	int n=100;
	if (argc>1)
		n=atoi(argv[1]);
	srand(time(NULL));
	int x = rand() % n +1;
	int upStevilo;
	int stPoskusov=0;
	do{
		stPoskusov++;
		printf("vpisi stevilo: ");
		scanf("%d", &upStevilo);
		if(upStevilo>x){
			printf("Vpisali ste preveliko stevilko \n");
		}
		if(upStevilo<x){
			printf("Vpisali ste premajhno stevilko \n");
		}
	
	}while(upStevilo!=x);

	printf("Bravo, pravilno si uganil v %d poskusih",stPoskusov);
	return 0;
}
