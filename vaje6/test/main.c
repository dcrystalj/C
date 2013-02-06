#include <stdio.h>
char tab[7][7];
char un = 'X';
int sts = 0;
int stv = 0;

int good(){
    int i;
    for(i=0; i<7; i++){
        int j;
        for(j=0; j<7; j++){
            if(tab[i][j]==' '){
            return 1;
            }
        }
    }
    return 0;
}

int winner(){
    int i;
    for(i=0; i<7; i++){
        int j;
        for(j=0; j<7-3; j++){
            int n;
            int lo=1;
            int ol=1;
            for(n=i; n<i+4; n++){
                if(tab[j][n]!=un){
                    lo=0;
                }
                if(tab[n][j]!=un){
                    ol=0;
                }
            }
            if(lo || ol){
                return 1;
            }
        }
    }
    for(i=0; i<7-3; i++){
        int j;
        for(j=0; j<7-3; j++){
            int n;
            int lo=1;
            int ol=1;
            for(n=0; n<4; n++){
                if(tab[i+n][j+n]!=un){
                    lo=0;
                }
                if(tab[i+n][j+(3-n)]!=un){
                    ol=0;
                }    
            }
            if(lo || ol){
                return 1;
            }
        }
    }
    return 0;    
}

void izpis(){
    int i;
    printf("  ");
    for(i=0; i<7; i++){
        printf(" %d",i+1);
    }
    printf("\n");
    for(i=0; i<7; i++){
        int j;
        printf("%d ",i+1);
        for(j=0; j<7; j++){
            printf(" %c",tab[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{    
    int i;
    for(i=0; i<7; i++){
        int j;
        for(j=0; j<7; j++){
            tab[i][j]=' ';
        }
    }
    while(good()){
        izpis();
        printf("Na vrsti je %c: \n    vnesi stolpec [0-6]: ", un);
        scanf("%d", &sts);
        printf("\n    vnesi vrstico [0-6]: ");
        scanf("%d", &stv);
		sts--;
		stv--;
        if(sts < 7 && sts > -1 && stv < 7 && stv > -1 && tab[stv][sts]==' '){
                tab[stv][sts]=un;
                if(winner()){
                    printf("\n\nZmagal je %c!!!\n\n", un);
                    return 0;
                }
                if(un == 'X'){
                    un = 'O';
                }else{
                    un = 'X';
                }
        }else{
            printf("Napacen vnos!\n");
        }   
    }
    return 0;
}
