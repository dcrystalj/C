#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void vDvojisko(int x, char dvojisko[]){
	int i,j;
	for(int i=1;i<33;i++){
		if(x&(1<<(i-1)))
			dvojisko[32-i-1]='1';
		else
			dvojisko[32-i-1]='0';
	}
	j=0;
	while(j<32 && dvojisko[j]=='0'){
		j++;
	}
	for (int i = 0; i < 32; i++)
	{
		dvojisko[i]=dvojisko[j];
		j++;
		if(j==32){
			dvojisko[i]=0;
			break;
		}
	}
}

int vDesetisko(char dvojisko[]){
	int i=0,sum=0,k;
	while(dvojisko[i]!=0){
		i++;
	}
	k=i-1;
	for(int j=0; j<i; j++){
		if(dvojisko[j]==0)
			break;
		sum+=(dvojisko[j]-'0')*pow(2,k);
		k--;
	}
	return sum;
}

int main(int argc, char *args[]) {
	char dvojisko[33];
	int x=563;
	vDvojisko(x,dvojisko);
	printf("%d --> %s \n", x, dvojisko);
	
	char dvojisko1[33]="100100100";
	int y = vDesetisko(dvojisko1);
	printf("%s --> %d", dvojisko1, y);
	getchar();
}
