#include "image.h"
#include <stdio.h>

int main(void)
{
    tImage image,image2;
    image = ImLire("dragon.pgm");

    image2 = ImAllouer(ImNbCol(image), ImNbLig(image));
    
    for (int i=0; i<ImNbLig(image); i++) for (int j=0; j<ImNbCol(image);j++) ImNivGris(image2)[ImNbCol(image)-j-1][i]=ImNivGris(image)[i][j];
    ImEcrire(image2,"dragon2.pgm");
    ImLiberer(&image);
    ImLiberer(&image2);
    return 0;
}