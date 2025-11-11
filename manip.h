#ifndef MANIP_H
#define MANIP_H

#define b 20

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "abstract.h"

void recherche(TNOF *F, int key, bool *trv, int *i, int *j) {
    Bloc buf;
    bool conti = true;
    *trv = false;
    *i = 1;
    int nbBlock = ReadEntete(F, 1);

    while (*i <= nbBlock && conti) {
        LireDir(F, *i, &buf);
        for (*j = 0; *j < buf.NB; (*j)++) {
            if (buf.tab[*j].key == key) {
                *trv = true;
                conti = false;
                break;
            }
        }
        if (conti) (*i)++;
    }

    if (!(*trv)) { *i = -1; *j = -1; }
}


void PhisycalDelete(bool* deleted,int key){
    TNOF* F;
    Bloc buf1, buf2;
    int i, j;
    bool trouv;

    F = ouvrir("file.dat",'A');
    recherche(F,key,&trouv,&i,&j);

    if(!trouv) {
        printf("---MAKAYEN MA TDELETI ---");
    }
    else{
        LireDir(F,i,&buf1);
        LireDir(F, ReadEntete(F,1), &buf2);
        buf1.tab[j] = buf2.tab[buf2.NB];
        buf2.NB = buf2.NB - 1;
        EcrireDir(F,i,buf1);
        EcrireDir(F,ReadEntete(F,1),buf2);
        if(buf2.NB==0){
            Aff_Entete(F,1,ReadEntete(F,1)-1);
        }
    }
    fermer(F);
}

#endif