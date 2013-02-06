#include <stdio.h>

extern inz zamik; //spremenljivka iz druzga fajla
extern kodiraj (char niz[]);

int main(int argc, char *argv[]){

	char niz[100];
	printf("Vpisi niz: ");
	scanf("$s", niz);

	kodiraj(niz);
	printf("Kodiran niz: %s\n", niz);

	return 0;
}
