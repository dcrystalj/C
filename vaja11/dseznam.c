#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bes {
  char niz[50];
  struct bes *nasl;
  struct bes *naslCrka;
  struct bes *drugaCrka;
} beseda;

typedef int fIskanje(beseda *, char *);

// naredim in vrnem novo skatlo
beseda * novaBeseda(char *niz) {
  beseda *nov = malloc(sizeof(beseda));
  nov->nasl=NULL;
  nov->naslCrka=NULL;
  nov->drugaCrka=NULL;
  strcpy(nov->niz, niz);
  return nov;
}

// dodajanje na urejeno mesto v seznam
// vrne: kazalec na nov zacetek
beseda * dodajU(beseda *zacetek, beseda *nov) {
  if (zacetek == NULL) {
    return nov;
  } else {
    // vstavljam na zacetek seznama
    if (strcmp(nov->niz, zacetek->niz) < 0) {
      nov->nasl = zacetek;
      return nov;   
    } else { // vstavljam nekam vmes
      beseda *tmp = zacetek;
      while (tmp -> nasl != NULL &&
        strcmp(tmp->nasl->niz, nov->niz)<=0)
        tmp = tmp ->nasl;
      if (strcmp(nov->niz, tmp->niz)!=0) {
        nov->nasl = tmp->nasl;
        tmp->nasl = nov;
      }
      return zacetek;
    }
  }
}

// pravilno nastavi kazalce naslCrka
void dopolniSeznam(beseda *zacetek) {
  beseda *tr=zacetek, *tmp=zacetek, *druga=zacetek;
  while (tr!=NULL) {
    while(tmp!=NULL && tr->niz[0] == tmp->niz[0])
      {
        tmp=tmp->nasl;
      }
      tr->naslCrka = tmp;
      tr = tmp;
    while(druga!=NULL && tmp!=NULL && tr->niz[0] == tmp->niz[0] && druga->niz[1] == tmp->niz[1])
      {
        tmp=tmp->nasl;
      } 
      druga->drugaCrka=tmp;
      druga = tmp;
    
  }
}

void izpisiSeznam(beseda *zacetek) {
  int i=0;
  while(zacetek!=NULL) {
    printf("%d %s\n", i++, zacetek->niz);
    zacetek=zacetek->nasl;
  }
}

// v seznamu poiscem niz in vrnem stevilo
// skokov, oziroma -1, ce niza ne najdem
int poisci(beseda *zacetek, char *niz) {
  int i=0; // stevec skokov
  beseda *tmp = zacetek;
  while(tmp!=NULL && strcmp(tmp->niz, niz)<0) {
    tmp = tmp -> nasl;
    i++;
  }

  if (tmp!=NULL && strcmp(tmp->niz, niz)==0)
    return i;
  else 
    return -1;
}

int poisciNajHitreje(beseda *zacetek, char *niz) {
  int i=0; // stevec skokov
  beseda *tmp = zacetek;
  while(tmp!=NULL && strcmp(tmp->niz, niz)<0) {
    if (tmp->niz[0] != niz[0])
      tmp = tmp -> naslCrka;
    else
      if(tmp->niz[1] != niz[1])
        tmp = tmp->drugaCrka; 
      else
        tmp = tmp -> nasl;
    i++;
  }
  if (tmp!=NULL && strcmp(tmp->niz, niz)==0)
    return i;
  else 
    return -1;
}



// v seznamu poiscem niz in vrnem stevilo
// skokov, oziroma -1, ce niza ne najdem
// pri iskanju uporabim preskakovanje 
// po prvi crki
int poisciHitreje(beseda *zacetek, char *niz) {
  int i=0; // stevec skokov
  beseda *tmp = zacetek;
  while(tmp!=NULL && strcmp(tmp->niz, niz)<0) {
    if (tmp->niz[0] != niz[0])
      tmp = tmp -> naslCrka;
    else 
      tmp = tmp -> nasl;
    i++;
  }

  if (tmp!=NULL && strcmp(tmp->niz, niz)==0)
    return i;
  else 
    return -1;
}

int povprecnoIskanje(beseda *zac, fIskanje *isci) {
  int vsota = 0; // vsota vseh iskanj
  int n=0;       // vse besede

  beseda *tmp = zac;
  while(tmp!=NULL) {
    vsota += (*isci)(zac, tmp->niz);
    n++;
    tmp = tmp->nasl;
  }
  return vsota/n;
}


int main(int argc, char **args) {

  beseda *zacetek = NULL;

  FILE *f = fopen(args[1], "r");
  if (f != NULL) {
    char b[50];
    int k;
    do {
      k = fscanf(f, "%s", b);
      if (k==1) {// branje ene besede je uspelo
        //printf("%s\n", b);
        zacetek = dodajU(zacetek, novaBeseda(b));
      }
    } while (k == 1);

    fclose(f);

    dopolniSeznam(zacetek);

    //izpisiSeznam(zacetek);

    //while (1) {
      //scanf("%s", b);
      //printf("%d\n", poisci(zacetek, b));
      //printf("%d\n", poisciHitreje(zacetek, b));
    //}

    //izpisiSeznam(zacetek);
    printf("Povprecje 'poisci': %d\n", povprecnoIskanje(zacetek, poisci));
    printf("Povprecje 'poisciHitreje': %d\n", povprecnoIskanje(zacetek, poisciHitreje));
    printf("Povprecje 'poisciNajHitreje': %d\n", povprecnoIskanje(zacetek, poisciNajHitreje));

  } else {
    fprintf(stderr, "Napaka - datoteka ne obstaja\n");
  }

  return 0;
}
