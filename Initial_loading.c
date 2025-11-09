#include <stdlib.h>
#include <stdio.h>
#include "abstract.h"

#define B 9


int main(){
    TNOF* F;
    Bloc buf;

    TypeEnreg e;
    int i,j,k,n;

    printf("---- THE PROGRAM HAS BEEN STARTED ----");

    F = ouvrir("file.dat",'N');

    F->Ent.nbBlock = B;
    F->Ent.nbEnrg = 0;

    printf("How many blocks you want to insert ? \n ");
    scanf("%i",&n);
    i = 1 ; j = 1;
    
    for (int k = 1; k < n; k++){
        printf("..%i.. : e = ",k); scanf("%i",&e.key);
        if(j<B*0.7){
            buf.tab[j-1].key = e.key ;
            j++;
        }
        else{
            buf.NB = j-1;
            EcrireDir(F,i,buf);
            buf.tab[1].key = e.key;
            i++;
            j = 2;
        }
    }
    buf.NB = j - 1;
    EcrireDir(F,i,buf);
    Aff_Entete(F,1,i);
    Aff_Entete(F,2,n);
    fermer(F);
    
    

    return 0;
}