#include <stdlib.h>
#include <stdio.h>
#include "abstract.h"

#define B 9

typedef struct
{
    Entete Entete;
    TypeBloc *blocs;
}FICHIER;


int main(){
    TNOF* F;
    F.Entete.nbBlock = B;
    F.Entete.nbEnrg = 0;
    Bloc buf;

    TypeEnreg e;
    int i,j,k,n;

    ouvrir(F,"file.dat","N");
    printf("n = "); scanf("%i",&n);
    i = 1 ; j = 1;
    for (int k = 1; k < n; k++){
        printf("..%i.. : e = ",k); scanf("%i",&n);
        if(j<b*0.7){
            buf.tab[j] = e ;
            j++;
        }
        else{
            buf.NB = j-1;
            EcrireDir(F,i,buf);
            buf.tab[1] = e;
            i++;
            j = 2;
        }
    }
    buf.NB = j - 1;
    EcrireDir(F,i,buf);
    Aff_Entete(F,1,i);
    fermer(F);
    
    

    return 0;
}