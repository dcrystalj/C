#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int jeSamoglasnik(char c){

	switch(c){
		case 'A': return 1;
		case 'E': return 1;
		case 'I': return 1;
		case 'O': return 1;
		case 'U': return 1;
		case 'a': return 1;
		case 'e': return 1;
		case 'i': return 1;
		case 'o': return 1;
		case 'u': return 1;
		default: return 0;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	while(1){
		char c;
		c= getc(stdin);
		if(c=='X' || c=='x'){
			break;
		}
		else{
			if(jeSamoglasnik(c))
				printf("DA\n");
			else
				printf("NE\n");
		}
		fflush(stdin);

	}
	
}
