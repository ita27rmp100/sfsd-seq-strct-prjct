#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <stdio.h>
#include <stdlib.h>

#define b 20
int N_readACC = 0 ,N_writeACC=0;

// Entete declaration
typedef struct Entete{
    int nbBlock, nbEnrg;
} Entete;
// Record declaration
typedef struct TypeEnreg{
    // int efface,cle;
    // char nom[20],prenom[20];
    int key;
}TypeEnreg;
typedef struct TNOF{
    FILE *F;
    Entete Ent;
}TNOF;
// Block declaration
typedef struct Bloc{
    TypeEnreg tab[b];
    int NB;
}Bloc;
// Open function
TNOF* ouvrir(char nomfichier[],char mode){
    TNOF *fichier = malloc(sizeof(TNOF));
    if((mode=='A')||(mode=='a')){
        fichier->F = fopen(nomfichier,"r+b");
        rewind(fichier->F);
        fread(&(fichier->Ent),sizeof(Entete),1,fichier->F);
    }else{
        if((mode=='N') || (mode=='n')){
            fichier->F =fopen(nomfichier,"w+b");
            // initialisation de l'entete
            (fichier->Ent).nbBlock = 0 ;
            (fichier->Ent).nbEnrg = 0;
            rewind(fichier->F);
            fwrite(&(fichier->Ent),sizeof(Entete),1,fichier->F);
        }else{
            printf("Unrecognized opening mode");
        }
    }
    return (fichier) ;
}
// Close function
void fermer(TNOF *fichier){
    // before we close the file, we save its header
    rewind(fichier->F);
    fwrite(&(fichier->Ent),sizeof(Entete),1,fichier->F);
    fclose(fichier->F);
    free(fichier);
}
int ReadEntete(TNOF *fichier,int i){
    if(i==1) return fichier->Ent.nbBlock;
    if(i==2) return fichier->Ent.nbEnrg;
    return -1; // Error case
}
void Aff_Entete(TNOF *fichier,int i, int val){
    if(i==1) fichier->Ent.nbBlock = val;
    if(i==2) fichier->Ent.nbEnrg = val;
}
int Alloc_bloc(TNOF *fichier){
    Aff_Entete(fichier,1,ReadEntete(fichier,1)+1);
    return ReadEntete(fichier,1);
}
void LireDir(TNOF *fichier, int i,Bloc *Buf){
    if(i<=ReadEntete(fichier,1)){
        fseek(fichier->F,sizeof(Entete)+(i-1)*sizeof(Bloc),SEEK_SET);
        fread(Buf,sizeof(Bloc),1,fichier->F);
        N_readACC++;
    }
}

void EcrireDir(TNOF *fichier,int i,Bloc Buf){
    fseek(fichier->F,sizeof(Entete)+(i-1)*sizeof(Bloc),SEEK_SET);
    fwrite(&Buf,sizeof(Bloc),1,fichier->F);
    N_writeACC++;
}

#endif 