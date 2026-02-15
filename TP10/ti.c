#include <math.h>
#include "image.h"
#include <stdio.h>

tImage Rotation(tImage Im)
{
    tImage image2;
    image2 = ImAllouer(ImNbCol(Im), ImNbLig(Im));
    for (int i=0; i<ImNbLig(Im); i++) for (int j=0; j<ImNbCol(Im);j++) ImNivGris(image2)[ImNbCol(Im)-j-1][i]=ImNivGris(Im)[i][j];
    return image2;
}

tImage AppliquerTable(unsigned char Table[256], tImage Im)
{
    tImage image2;
    image2 = ImAllouer(ImNbLig(Im), ImNbCol(Im));
    for (int i=0; i<ImNbLig(Im); i++) for (int j=0; j<ImNbCol(Im);j++)  ImNivGris(image2)[i][j]=Table[ImNivGris(Im)[i][j]];
    return image2;
}

void RemplirTableInversion(unsigned char Table[256])
{
    for (int i=0; i<256; i++) Table[i]=255-i;
}

void RemplirTableGamma(double Gamma, unsigned char Table[256])
{
    for (int i=0; i<256; i++) Table[i]=round(255*pow(i/255.0,Gamma));
}