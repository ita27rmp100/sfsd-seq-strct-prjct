#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "abstract.h"
#include "manip.h"

#define B 9

int main() {
    TNOF* F;
    Bloc buf;
    TypeEnreg e;
    int i, j, n;

    // Initial loading

    printf("---- THE PROGRAM HAS BEEN STARTED ----\n");
    F = ouvrir("file.dat", 'N');

    printf("How many blocks you want to insert ? ");
    scanf("%i", &n);

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
    EcrireDir(F, i, buf);
    Aff_Entete(F, 1, i + 1);
    Aff_Entete(F, 2, n);
    fermer(F);

    // Test initialization through testing recherche and Physical deleteion functions

    F = ouvrir("file.dat", 'A');

    bool dlt = false;
    PhisycalDelete(F, &dlt, 3);

    bool trv;
    int x, y;
    recherche(F, 3, &trv, &x, &y);

    printf("\nDelete status: %d", dlt);
    printf("\nSearch after delete: trv=%d, (%d,%d)\n", trv, x, y);

    fermer(F);
    
    return 0;
}