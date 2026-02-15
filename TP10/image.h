#include "matrice.h"
#ifndef IMAGE_H
#define IMAGE_H
typedef struct sImage *tImage;
enum eType // Types possibles pour une image
{
Gris , // Image de niveaux de gris
Couleur // Image en couleur
};
typedef enum eType tType ;
extern tImage ImAllouer(int NbLignes, int NbColonnes);
extern tImage ImAllouerCoul(int NbLignes, int NbColonnes);
extern void ImLiberer(tImage *pIm);
extern int ImNbLig(tImage Im);
extern int ImNbCol(tImage Im);
extern tMatrice ImNivGris(tImage Im);
extern tMatrice ImNivRouge(tImage Im);
extern tMatrice ImNivVert(tImage Im);
extern tMatrice ImNivBleu(tImage Im);
extern tImage ImLire(char NomFichier[]);
extern void ImEcrire(tImage Im, char NomFichier[]);
#endif