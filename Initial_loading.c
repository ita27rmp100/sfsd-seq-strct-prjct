#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "abstract.h"
#include "manip.h"

#define B 9


int main(){
    TNOF* F;
    Bloc buf;

    TypeEnreg e;
    int i,j,k,n;

    printf("---- THE PROGRAM HAS BEEN STARTED ----\n");

    F = ouvrir("file.dat",'N');

    F->Ent.nbBlock = B;
    F->Ent.nbEnrg = 0;

    printf("How many blocks you want to insert ? ");
    scanf("%i",&n);
    i = 0; j = 1;    
    for (int k = 0; k < n; k++){
        printf("..%i.. : e = ",k+1); scanf("%i",&e.key);
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
    Aff_Entete(F,1,i + 1); 
    Aff_Entete(F,2,n);  

    bool trv;
    int x,y;
    int status = 0;
    recherche(F,3,&trv,&x,&y);

    if (trv){status=1;}
    
    printf("The record of key %i is %i in coordinates (%i,%i).",3,status,x,y);

    fermer(F);

    return 0;
}