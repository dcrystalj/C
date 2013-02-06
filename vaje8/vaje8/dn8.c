#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

void izpisNavodil(void){
	printf("\n 1 ... Dodaj število na sklad (push)\n 2 ... Vzemi in izpiši število s sklada (pop)\n 3 ... Ali je sklad prazen? \n 4 ... Sprazni sklad \n 5 ... Izhod iz programa \n");
}

int main(int argc, char *argv[])
{
	int sklad [atoi(argv[1])];
	int *pSklad;
	pSklad = &sklad[0];
	pSklad--;
	int in = 0;
	int push = 0;
	while (in!=5){
		izpisNavodil();
		scanf("%d",&in);
		
		if(in==1){ //push
			if(&sklad[0]<=pSklad-atoi(argv[1])+1){
				printf("sklad je poln");
				printf("\a");
			}else{
				printf("\nvpisi stevilo\n");
				scanf("%d",&push);
				pSklad++;
				*pSklad = push;
			}
		}
		else if(in==2){ //pop
			if(&sklad[0]>pSklad){
				printf("nic za pop");
			}
			else{
				printf("vrh skalda -> %d", *pSklad);
				pSklad--;
			}
		}
		else if(in==3){ //isEmpty
			if(&sklad[0]>pSklad)
				printf("0");
			else
				printf("1");
		}
		else if(in==4){ //make empty
			pSklad = &sklad[0];
			pSklad--;
		}
	}

}

