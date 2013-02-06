#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *args[]) {
	
	int x = 0;
	int a;
	int b; 
	int c;
	int y;
	if (argc>1){
		y = atoi(args[1]);
		
		int i;
		for (i=0; i<y; i++){
			if (i%3==0&&i%5==0){
				x+=i;
			}

		}
	// pitagorejski trojcek
		int tmp;
		for(a=1; a<1000;a++){
			for(b=1;b<1000;b++){
				tmp = a*a+b*b;
				c=sqrt(tmp);
				if(a+b+c==1000 && a*a+b*b==c*c)
					printf("%d %d %d %d \n",a,b,c,x);
			}
		}
	}
	else{
		printf("Napaka argumenta");
	}
	return 0;
}
