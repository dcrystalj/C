#include <stdio.h>

#define N 10

int main(int argc, char *argv[])
{
	char niz[N+1];  //N == konstanta
	FILE *vhod;
	vhod = fopen("mandela.txt","r");
	
	if(vhod==NULL){
		printf("napaka pri odpiranju datoteke");
		exit (1);
	}
	int stevec = 0;
	while(feof(vhod) == 0){
		fgets(niz,N,vhod);
		//printf("%s",niz);
		int i;
		for(i=0; i<N-1; i++){
			if(niz[i]!='(' && niz[i]!=')' && niz[i]!='.' && niz[i]!='\n'){
				if(niz[i]==' '){
					if(niz[i]==' ' && stevec==1){
						// ce je ves presledkov skupaj
					}else{
					printf("\n");
					stevec++;
					}
				}else{
					printf("%c", niz[i]);
					stevec=0;
				}
			}
		}

	}

	fclose(vhod);
	return 0;
}
