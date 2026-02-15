#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "image.h"
#include "matrice.h"


struct sImage
{
int NbLig ; // Nombre de lignes de l ' image
int NbCol ; // Nombre de colonnes de l ' image
tMatrice NivGris ; // Matrice des niveaux de gris de l ' image
};

tImage ImAllouer(int NbLignes, int NbColonnes)
{
    tImage *image;
    image = malloc(sizeof(tImage));
    *image = malloc(sizeof(struct sImage));
    if(image==NULL) return NULL;
    (*image)->NbLig=NbLignes;
    (*image)->NbCol=NbColonnes;
    (*image)->NivGris=MatAllouer(NbLignes,NbColonnes);
    if((*image)->NivGris==NULL) return NULL;
    return *image;
}

void ImLiberer(tImage *pIm)
{
    MatLiberer(&((*pIm)->NivGris));
    free(*pIm);
    *pIm=NULL;
}

int ImNbLig(tImage Im)
{
    return Im->NbLig;
}

int ImNbCol(tImage Im)
{
    return Im->NbCol;
}

tMatrice ImNivGris(tImage Im)
{
    return Im->NivGris;
}

tImage ImLire(char NomFichier[])
{
    FILE *image_fichier;
    int lignes,colonnes,niveaux_gris;
    char type[3];
    image_fichier=fopen(NomFichier,"rt");
    if (image_fichier==NULL) return NULL;
    fscanf(image_fichier,"%s",type);
    fscanf(image_fichier,"%d",&colonnes);
    fscanf(image_fichier,"%d",&lignes);
    fscanf(image_fichier,"%d",&niveaux_gris);
    tImage image;
    image = ImAllouer(lignes, colonnes);
    if(image==NULL) return NULL;
    int val;
    for(int i=0;i<lignes; i++) for(int j=0;j<colonnes; j++)
    {
        fscanf(image_fichier,"%d",&val);
        image->NivGris[i][j]=round(255.0*val/niveaux_gris);
    }
    fclose(image_fichier);
    return image;
}

void ImEcrire(tImage Im, char NomFichier[])
{
    FILE *image_fichier;
    image_fichier=fopen(NomFichier,"wt");
    fprintf(image_fichier,"%s","P2\n");
    fprintf(image_fichier,"%d ",Im->NbCol);
    fprintf(image_fichier,"%d\n",Im->NbLig);
    fprintf(image_fichier,"%d\n",255);
    for(int i=0;i<Im->NbLig; i++) 
    {
        for(int j=0;j<Im->NbCol; j++) fprintf(image_fichier,"%d ",Im->NivGris[i][j]);
        fprintf(image_fichier,"\n");
    }
}
