#include <stdio.h>
#include <stdlib.h>

struct matrika {
	int n;
	int m;
	int** polje;
};

struct matrika* create_matrix(int n, int m){
    struct matrika* mat =(struct matrika *) malloc(sizeof(struct matrika));
    mat->n=n;
    mat->m=m;
    mat->polje = (int **) malloc(sizeof(n));
    int i;
    for(i=0; i<n; i++){
        mat->polje[i] = (int *) malloc(sizeof(int)*m);
    }
    return mat;
}

struct matrika* zmnozi(struct matrika A, struct matrika B, int wA, int hA, int wB){
    struct matrika* mat = create_matrix(hA,wB);
    for (int i = 0; i < hA; ++i) //rows A
    {
        for (int j = 0; j < wB; ++j) //colums B
        {
            int sum = 0;
            for (int k = 0; k < wA; ++k) //rows B
            {
                sum += A.polje[i][k] * B.polje[k][j];
            }
            mat->polje[i][j] = sum;
        }
    }
    return mat;

}

void write_matrix(struct matrika m){
    int i;
    int j;
    for(i=0;i<m.n;i++){
        for (j=0;j<m.m;j++){
            printf("%d ",m.polje[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* args[]){
    printf("Velikost strukture je %d\n",sizeof( struct matrika));
    
    struct matrika* matA =NULL;
    struct matrika* matB =NULL;
    
    int ha = 0;
    int wa = 0;
    int wb = 0;
    int hb = 0;
    int s1, s2, tmp;

    //read first matrix
    FILE *f = fopen(args[1], "r");
    if (f != NULL) {
        fscanf(f, "%d%d", &s1, &s2);
        ha = s1;
        wa = s2;
        matA = create_matrix(s1,s2);
        for (int i = 0; i < s1; ++i)
        {
            for (int j = 0; j < s2; ++j)
            {
                fscanf(f, "%d",&tmp);
                matA->polje[i][j] = tmp;
            }
        }
    }
    fclose(f);

    //read second matrix
    f = fopen(args[2], "r");
    if (f != NULL) {
        fscanf(f, "%d%d", &s1, &s2);
        hb = s1;
        wb = s2;
        matB = create_matrix(s1,s2);
        for (int i = 0; i < s1; ++i)
        {
            for (int j = 0; j < s2; ++j)
            {
                fscanf(f, "%d",&tmp);
                matB->polje[i][j] = tmp;
            }
        }
    }    
    fclose(f);

    struct matrika* result = zmnozi(*matA, *matB,wa,ha,wb);

    write_matrix(*result);
    return 0;
}

/*
ki zmnoži matriki A in B (matrika A je dimenzije hA x wA, matrika B pa dimenzije wA x wB). Podatki v tabeli A so zapisani v bloku v “row-major” vrstnem redu.

Preberi podatke o dveh matrikah iz datotek, katerih ime je zapisano v prvem in
drugem argumentu programa (recimo A.txt in B.txt), ju zmnoži s pomoèjo
funkcije zmnozi in rezultat izpiši na zaslon. V datotekah je najprej napisana
višina (h) in širina (w) matrike, nato je v h vrsticah podanih po w števil
tipa int.
*/
