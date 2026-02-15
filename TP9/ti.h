#include "image.h"
#ifndef TI_H
#define TI_H
extern tImage Rotation(tImage Im);
extern tImage AppliquerTable(unsigned char Table[256], tImage Im);
extern void RemplirTableInversion(unsigned char Table[256]);
extern void RemplirTableGamma(double Gamma, unsigned char Table[256]);
#endif