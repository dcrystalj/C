
#include <stdio.h>
#include <stdlib.h>

#define W 80
#define H 25


char zaslon[H][W];

void izpisi(){
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			printf("%c",zaslon[i][j]);
		}
	}
}

void brisi(){
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			zaslon[i][j]=' ';
		}
	}
}

void funkcija(){

	double x1 = -3.14;
	double x2 = 3.14;
	double y1 = -1;
	double y2 = 1 ;

	int i,j;

	for(i=0; i<W; i++){
		double x  = i *(x2-x1)/W + x1;
		double y = sin(x);
		j = (y-y1)/(y2-y1)*H;

		zaslon[j][i] = '*';
	}
}

void narisiKoordinatniSistem(){
	int i,j;
	for(i=0; i<H; i++){
		zaslon[i][W/2] = '|';
	}
	for(j=0; j<W; j++){
		zaslon[H/2][j] = '-';
	}
	zaslon[H/2][W/2] = '+';
	
}
int main(int argc, char *argv[])
{

	brisi();
	narisiKoordinatniSistem();
	funkcija();
	izpisi();

}


