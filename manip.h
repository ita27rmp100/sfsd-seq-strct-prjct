#ifndef MANIP_H
#define MANIP_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "abstract.h"

#define b 20

void recherche(TNOF *F, int key, bool *trv, int *i, int *j) {
    Bloc buf;
    bool conti = true;
    *trv = false;
    *i = 0;
    int nbBlock = ReadEntete(F, 1);

    while (*i < nbBlock && conti) {  
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

void PhisycalDelete(TNOF* F, bool* deleted, int key) {
    Bloc buf1, buf2;
    int i, j;
    bool trouv;

    recherche(F, key, &trouv, &i, &j);

    if (!trouv) {
        printf("---MAKAYEN MA TDELETI ---\n");
        *deleted = false;
        return;
    }

    int lastBlock = ReadEntete(F, 1) - 1;
    LireDir(F, i, &buf1);
    LireDir(F, lastBlock, &buf2);

    buf1.tab[j] = buf2.tab[buf2.NB - 1];
    buf2.NB--;

    EcrireDir(F, i, buf1);
    EcrireDir(F, lastBlock, buf2);

    if (buf2.NB == 0)
        Aff_Entete(F, 1, lastBlock);

    int totalRecords = ReadEntete(F, 2);
    Aff_Entete(F, 2, totalRecords - 1);

    *deleted = true;
}

#endif
