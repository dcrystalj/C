#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
	int st;
	struct element *nasl;

}elt;

elt * newElement(int i){
	elt *nov  = malloc(sizeof(elt));
	nov->nasl =NULL;
	nov->st=i;
	return nov;
}

void izpisiSeznam(elt *z){
	while(z!=NULL){
		printf("%d\n", z->st);
		z=z->nasl;
	}
}


void sprostiElement(elt *e){
	free(e);
}

elt *  brisi(elt *z, int i){
	if(z==NULL){
		return NULL;
	}
	//prvi
	if(z->st == i){  
		if(z->nasl==NULL)
			return NULL;
		else
			return z->nasl;
	}

	elt *zac = z;
	while(z->nasl!=NULL){
		if(z->nasl->st==i){
			elt *novi = z->nasl;
			z->nasl = z->nasl->nasl;
			sprostiElement(novi);
			return zac;
		}
		z = z->nasl;
	}
	if(z->st==i)
		z==NULL;
	return zac;
}

elt * dodajZ(elt *z, elt *e){
	e->nasl =z;
	return e;
}


elt * dodajU(elt *z, elt *e){
	if(z==NULL){
		return e;
	}
	if(z->st >= e->st){  //doda na zacetek
		e->nasl =z;
		return e;
	}
	else{
		elt *zac = z;
		while(z->nasl!=NULL){
			if(z->nasl->st > e->st){  //doda umes
				e->nasl=z->nasl;
				z->nasl=e;
				return zac;
			}
			z = z->nasl;
		}
		if(z->st < e->st){  //doda na konec
			z->nasl=e;
		}
		return zac;
	}

}
int main(int argc, char *argv[])
{
	elt *z;
	z=NULL;

	z = dodajU(z,newElement(4));
	z = dodajU(z,newElement(7));
	z = dodajU(z,newElement(1));
	z = dodajU(z,newElement(9));
	z = dodajU(z,newElement(3));
	z = dodajU(z,newElement(2));
	z = brisi(z,1);
	z = brisi(z,7);
	izpisiSeznam(z);

	return 0;
}
