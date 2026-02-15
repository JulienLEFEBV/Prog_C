#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "image.h"
#include "matrice.h"


struct sImage
{
int NbLig ; // Nombre de lignes de l ’ image
int NbCol ; // Nombre de colonnes de l ’ image
tType Type ; // Type de l ’ image : Gris ou Couleur
tMatrice NivRouge ; // Matrice des niveaux de rouge ou des niveaux de gris
tMatrice NivVert ; // Matrice des niveaux de vert
tMatrice NivBleu ; // Matrice des niveaux de bleu
};

tImage ImAllouer(int NbLignes, int NbColonnes)
{
    tImage *image;
    image = malloc(sizeof(tImage));
    *image = malloc(sizeof(struct sImage));
    if(image==NULL) return NULL;
    (*image)->Type=Gris;
    (*image)->NbLig=NbLignes;
    (*image)->NbCol=NbColonnes;
    (*image)->NivRouge=MatAllouer(NbLignes,NbColonnes);
    if((*image)->NivRouge==NULL) return NULL;
    return *image;
}

tImage ImAllouerCoul(int NbLignes, int NbColonnes)
{
    tImage *image;
    image = malloc(sizeof(tImage));
    *image = malloc(sizeof(struct sImage));
    if(image==NULL) return NULL;
    (*image)->Type=Couleur;
    (*image)->NbLig=NbLignes;
    (*image)->NbCol=NbColonnes;
    (*image)->NivRouge=MatAllouer(NbLignes,NbColonnes);
    if((*image)->NivRouge==NULL) return NULL;
    (*image)->NivVert=MatAllouer(NbLignes,NbColonnes);
    if((*image)->NivVert==NULL) return NULL;
    (*image)->NivBleu=MatAllouer(NbLignes,NbColonnes);
    if((*image)->NivBleu==NULL) return NULL;
    return *image;
}

void ImLiberer(tImage *pIm)
{

    if ((*pIm)->Type==Gris) MatLiberer(&((*pIm)->NivRouge));
    else
    {
        MatLiberer(&((*pIm)->NivRouge));
        MatLiberer(&((*pIm)->NivVert));
        MatLiberer(&((*pIm)->NivBleu));
    }
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
    return Im->NivRouge;
}

tMatrice ImNivRouge(tImage Im)
{
    return Im->NivRouge;
}

tMatrice ImNivBleu(tImage Im)
{
    return Im->NivBleu;
}

tMatrice ImNivVert(tImage Im)
{
    return Im->NivVert;
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
    if(type[1]=='3' || type[1]=='6') image=ImAllouerCoul(lignes, colonnes);
    else image = ImAllouer(lignes, colonnes);
    if(image==NULL) return NULL;
    if(type[0]=='P' && type[1]=='6')
    {  
        for(int i=0;i<lignes; i++) for(int j=0;j<colonnes; j++)
        {
            fread(&(image->NivRouge[i][j]),sizeof(unsigned char),sizeof(unsigned char),image_fichier);
            fread(&(image->NivVert[i][j]),sizeof(unsigned char),sizeof(unsigned char),image_fichier);
            fread(&(image->NivBleu[i][j]),sizeof(unsigned char),sizeof(unsigned char),image_fichier);
        }
        fclose(image_fichier);
    }
     if(type[0]=='P' && type[1]=='3')
    {
        int val;
        for(int i=0;i<lignes; i++) for(int j=0;j<colonnes; j++)
        {
            fscanf(image_fichier,"%d",&val);
            image->NivRouge[i][j]=round(255.0*val/niveaux_gris);
            fscanf(image_fichier,"%d",&val);
            image->NivVert[i][j]=round(255.0*val/niveaux_gris);
            fscanf(image_fichier,"%d",&val);
            image->NivBleu[i][j]=round(255.0*val/niveaux_gris);
        }
        fclose(image_fichier);
    }
    if(type[0]=='P' && type[1]=='5')
    {  
        for(int i=0;i<lignes; i++)
        {
            fread(image->NivRouge[i],sizeof(unsigned char),colonnes*sizeof(unsigned char),image_fichier);
        }
        fclose(image_fichier);
    }
    if(type[0]=='P' && type[1]=='2')
    {
        int val;
        for(int i=0;i<lignes; i++) for(int j=0;j<colonnes; j++)
        {
            fscanf(image_fichier,"%d",&val);
            image->NivRouge[i][j]=round(255.0*val/niveaux_gris);
        }
        fclose(image_fichier);
    }
    return image;
}

void ImEcrireBin(tImage Im, char NomFichier[])
{
    FILE *image_fichier;
    image_fichier=fopen(NomFichier,"wt");
    fprintf(image_fichier,"%s","P5\n");
    fprintf(image_fichier,"%d ",Im->NbCol);
    fprintf(image_fichier,"%d\n",Im->NbLig);
    fprintf(image_fichier,"%d\n",255);
    fclose(image_fichier);
    image_fichier=fopen(NomFichier,"ab");
    for(int i=0;i<Im->NbLig; i++) 
    {
        fwrite(Im->NivRouge[i], sizeof(unsigned char), Im->NbCol*sizeof(unsigned char), image_fichier);
    }
    fclose(image_fichier);
}

void ImEcrire(tImage Im, char NomFichier[])
{
    FILE *image_fichier;
    image_fichier=fopen(NomFichier,"wt");
    if(Im->Type==Gris)
    {
    fprintf(image_fichier,"%s","P2\n");
    fprintf(image_fichier,"%d ",Im->NbCol);
    fprintf(image_fichier,"%d\n",Im->NbLig);
    fprintf(image_fichier,"%d\n",255);
    for(int i=0;i<Im->NbLig; i++) 
    {
        for(int j=0;j<Im->NbCol; j++) fprintf(image_fichier,"%d ",Im->NivRouge[i][j]);
        fprintf(image_fichier,"\n");
    }
    }
    else
    {
    fprintf(image_fichier,"%s","P3\n");
    fprintf(image_fichier,"%d ",Im->NbCol);
    fprintf(image_fichier,"%d\n",Im->NbLig);
    fprintf(image_fichier,"%d\n",255);
    for(int i=0;i<Im->NbLig; i++) 
    {
        for(int j=0;j<Im->NbCol; j++) fprintf(image_fichier,"%d ",Im->NivRouge[i][j]);
        fprintf(image_fichier," ");
        for(int j=0;j<Im->NbCol; j++) fprintf(image_fichier,"%d ",Im->NivVert[i][j]);
        fprintf(image_fichier," ");
        for(int j=0;j<Im->NbCol; j++) fprintf(image_fichier,"%d ",Im->NivBleu[i][j]);
        fprintf(image_fichier,"\n");
    }
    }
    fclose(image_fichier);
}
