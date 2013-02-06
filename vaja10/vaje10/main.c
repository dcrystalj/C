#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
	char *ime;
	struct element *nasl;

}elt;

elt * newElement(char *ime){
	elt *nov  = malloc(sizeof(elt));
	nov->nasl =NULL;
	nov->ime  =malloc((strlen(ime)+1)*sizeof(char));
	strcpy(nov->ime,ime);
	return nov;
}

void izpisiElement(elt *e){
	printf("ime : %s\n", e->ime);
}

void izpisiSeznam(elt *z){
	while(z!=NULL){
		printf("%s\n", z->ime);
		z=z->nasl;
	}
}

//vraca kazalec na nov zacetek
elt * dodajZ(elt *z, elt *e){
	e->nasl =z;
	return e;
}

elt * dodajK(elt *z, elt *e){
	if(z==NULL){
		return e;
	}
	else{
		elt *t = z;
		while(t->nasl != NULL){
			t=t->nasl;
		}
		t->nasl=e;
		return z;
	}
}


void sprostiElement(elt *e){
	free(e->ime);
	free(e);
}
//brisi prvega
elt * pop(elt *z){
	if(z==NULL){
		return NULL;
	}
	else{
		elt* nZ = z->nasl;
		sprostiElement(z);
		return nZ;
	}

}
//brisi na ime
elt * brisi(elt *z, char *ime){
	if(z==NULL){
		return NULL;
	}
	if(strcmp(z->ime, ime)==0){
		elt *nZ = z->nasl;
		sprostiElement(z);
		return nZ;
	}
	else{
		elt *t = z;
		while(t->nasl !=NULL){
			if (strcmp(t->nasl->ime,ime)==0){ //najdemo element za pobrisat
				elt *p = t->nasl;
				t->nasl=t->nasl->nasl;
				sprostiElement(p);
			}else{
				t=t->nasl;
			}
		}
		return z;
	}
}
int main(int argc, char *argv[])
{
	elt *z;
	z=NULL;

	elt *e1 = newElement("Lojze");
	elt *e2 = newElement("Micka");
	elt *e3 = newElement("Pepe");
	

	z = dodajZ(z,e1);
	z = dodajZ(z,e2);

	
	z = dodajZ(z,e3);
	z = dodajZ(z,newElement("A"));
	z = dodajZ(z,newElement("B"));
	z = dodajZ(z,newElement("C"));
	z = dodajZ(z,newElement("D"));
	z = dodajZ(z,newElement("E"));
	z= brisi(z,"B");
	izpisiElement(e1);
	izpisiElement(e2);

	izpisiSeznam(z);
		 
	return 0;
}
