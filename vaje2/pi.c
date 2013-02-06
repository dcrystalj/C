#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("%5c %15c\n----------------------------\n",'n','PI');
	int n;
	for(n=10; n<1000000000; n*=10){
		
		int vKrogu = 0; //inicializacija = deklaracija+ definicija..

		int i;
		for(i=0; i<n; i++){
			float x = (float) rand() / RAND_MAX;
			float y = (float) rand() / RAND_MAX;
			if(x*x+y*y<=1)
				vKrogu++;

		}
		printf("%-10d %.10f \n",n,(double)4*vKrogu/n);
	   
	}
	return 0;
}
