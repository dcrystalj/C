
#include <stdio.h>
#include <limits.h>

char tab[3][3];
int igralec;
void brisi(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			tab[i][j]=' ';
		}
	}
}


void izpisi(){
	printf(" ");
	for(int j=0; j<3; j++){
		printf("%d",j+1);
	}

		printf("\n");
	for(int i=0; i<3; i++){
		printf("%d",i+1);
		for(int j=0; j<3; j++){
			printf("%c",tab[i][j]);
		}
		printf("\n");
	}
}

int konecigre(){
	int c;
	int enako=0;

	//vrstice
	for(int i=0; i<3; i++){

		if(tab[i][0]==' '){
			c=11;
		}
		else{
			c=tab[i][0];
		}
		enako=0;
		for(int j=0; j<3; j++){
			if(tab[i][j]==c){
				enako++;
			}
		}
		if(enako==3)
			return 1;
	}
 	
	//stolpci
	for(int i=0; i<3; i++){
		if(tab[0][i]!=' ')
			c=tab[0][i];
		else
			c=11;

		enako=0;
		for(int j=0; j<3; j++){
			if(tab[j][i]==c){
				enako++;
			}
		}
		if(enako==3)
			return 1;
	}
	//diagoni

	enako=0;
	if(tab[0][0]!=' ')
		c=tab[0][0];
	else
		c=11;
	for(int i=0; i<3; i++){
		if(tab[i][i]==c)
			enako++;
	}
	if(enako==3)
		return 1;

	enako=0;
	if(tab[0][3]!=' ')
		c=tab[0][3];
	else
		c=11;
	for(int i=0; i<3; i++){
		if(tab[i][3-i]==c)
			enako++;
	}
	if(enako==3)
		return 1;

	return 0;
}

int main(int argc, char *argv[])
{
	brisi(); 
	igralec = 0;
	int x;
	int y;
	while(!konecigre()){
		izpisi();
		printf("\n \n vpisi koordinate igralec x y %d \n \n", igralec);
		scanf("%d %d", &x,&y);
		printf("\n\n");
		while((x>3 || x<1) || (y>3 || y<1)){
			printf("\n \n ponovno vpisi pravilne koordinate igralec x y %d \n \n", igralec);
			scanf("%d %d", &x,&y);
			printf("\n\n");
		}
		if(igralec)
			tab[y-1][x-1]='X';
		else
			tab[y-1][x-1]='O';
		igralec = 1-igralec;

	}
	printf("cestitam igralec %d", igralec );

}
