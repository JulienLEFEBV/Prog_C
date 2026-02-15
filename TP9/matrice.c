#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

typedef unsigned char **tMatrice;

tMatrice MatAllouer(int NbLig, int NbCol)
{
    tMatrice matrice;
    unsigned char *valeur;
    matrice=malloc(NbLig*sizeof(unsigned char *));
    if(matrice!=NULL)
    {
        valeur=malloc(NbLig*NbCol*sizeof(unsigned char));
        if(valeur==NULL) matrice=NULL;
        else for(int i=0; i<NbLig; i++) matrice[i]=&valeur[i*NbCol];
    }
    return matrice;
}

tMatrice MatLire(int *pNbLig, int *pNbCol)
{
    tMatrice matrice;
    printf("Saisir un nombre de lignes : ");
    fflush(stdout);
    scanf("%d",pNbLig);
    printf("Saisir un nombre de colonnes : ");
    fflush(stdout);
    scanf("%d",pNbCol);
    matrice = MatAllouer(*pNbLig, *pNbCol);
    if (matrice!=NULL)
    {
        for (int i=0; i<*pNbLig; i++)
        {
            printf("Ligne %d : ",i);
            fflush(stdout);
            unsigned char c;
            for (int j=0; j<*pNbCol; j++) 
            {
                scanf("%hhu",&c);
                matrice[i][j]=c;
            }
        } 
    }
    return matrice;
}

void MatAfficher(tMatrice Mat, int NbLig, int NbCol)
{
    for (int i=0; i<NbLig; i++) 
    {
        for (int j=0; j<NbCol; j++) printf("%3d ", Mat[i][j]);
        printf("\n");
    }
}

tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol)
{
    tMatrice matrice_copie;
    matrice_copie=MatAllouer(NbLig,NbCol);
    if (Mat!=NULL) for (int i=0; i<NbLig; i++) for (int j=0; j<NbLig; j++) matrice_copie[i][j]=Mat[i][j];
    return matrice_copie;
}

void MatLiberer(tMatrice *pMat)
{
    free(**pMat);
    free(*pMat);
    *pMat=NULL;
}
