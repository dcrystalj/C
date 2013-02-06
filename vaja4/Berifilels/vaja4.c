#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *args[]) {
	int i=0;
	if (argc>1)
		i = atoi(args[1]);
	
	int f=0,stevec=0, vsota=0, steveckoncni=0;
	for(int j=0; j<256; j++){
		stevec=0;
		for (int e=0; e<8; e++){ //prestejem enice
			if(j&(1<<e))
				stevec++;
		}
		if(stevec==i){
			//izpis binarno
			for(f=7;f>-1;f--){
				if(j&(1<<f))
					printf("1");
				else
					printf("0");
			}
			//izpis stevila
			printf(" = %d \n",j);
			vsota+=j;
			steveckoncni++;
		}
	}
	printf("i= %d, n=%d, vsota = %d",i,steveckoncni, vsota);

}
