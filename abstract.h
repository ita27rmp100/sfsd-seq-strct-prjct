#ifndef ABSTRACT
#define ABSTRACT

#include <stdio.h>
#include <stdlib.h>

#define b 20
int N_readACC,N_writeACC=0;

// Entete declaration
typedef struct Entete{
    int nbBlock,nbEnrg;
}Entete;
// Record declaration
typedef struct Etudiant{
    int efface,cle;
    char nom[20],prenom[20];
}Etudiant;
typedef struct TNOF{
    FILE *F;
    Entete Ent;
}TNOF;
// Block declaration
typedef struct Bloc{
    Etudiant tab[b];
};
// Open function
TNOF* ouvrir(char nomfichier[],char mode){
    TNOF *fichier = malloc(sizeof(TNOF));
    if((mode=='A')||(mode=='a')){
        fichier->F = fopen("students.dat","r+b");
        rewind(fichier->F);
        fread(&(fichier->Ent),sizeof(Entete),1,fichier->F);
    }else{
        if((mode='N') || (mode=='n')){
            fichier->F =fopen(nomfichierm,"w+b");
            // initialisation de l'entete
            (fichier->Ent).nbBlock = 0 ;
            (fichier->Ent).nbEnrg = 0;
            rewind(fichier->F);
            fwrite(&(fichier->Ent),sizeof(Entete),1,fichier->F);
        }else{
            printf("Unrecognized opening mode");
        }
    }
    return (fichier)
}
// Close function
void close(TNOF *fichier){
    // before we close the file, we save its header
    rewind(fichier->F)
    fwrite(&(fichier->Ent),sizeof(Entete),1,fichier.F);
    fclose(fichier->F);
    free(fichier)
}
int Entete(TNOF *fichier,int i){
    if(i==1) return (fichier->Ent).nbBloc;
    if(i==2) return (fichier->F).nbEnrg;
}
void Aff_Entete(TNOF *fichier,int i, int val){
    if(i==1) return (fichier->Ent).nbBloc=i;
    if(i==2) return (fichier->F).nbEnrg=val;
}
int Alloc_bloc(TNOF *fichier){
    Aff_Entete(fichier,1,Entete(S,1)+1);
    return Entete(fichier,1)
}
void LireDir(TNOF *fichier, int i,Bloc *Buf){
    if(i<=Entete(fichier,1)){
        fseek(fichier->F,sizeof(Entete)+(i-1)8sizeof(Bloc),1,fichier->F);
        N_readACC++;
    }
}

void EcrireDir(TNOF *fichier,int i,Bloc Buf){
    fseek(fichier->F,sizeof(Entete)+(i-1)*sizeof(Bloc),SEEK_SET);
    fwrite(&Buf,sizeof(Bloc),1,fichier->F);
    N_writeACC++;
}

#endif 