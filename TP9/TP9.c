#include "image.h"
#include "ti.h"


int main(void)
{
    tImage image,image2,image3,image4,image5;
    image = ImLire("paysage.pgm");
    image2 = Rotation(image);
    ImEcrire(image2,"paysage2.pgm");
    unsigned char Tab[256];
    RemplirTableInversion(Tab);
    image3 = AppliquerTable(Tab,image);
    ImEcrire(image3,"paysage3.pgm");   
    RemplirTableGamma(0.4,Tab);
    image4 = AppliquerTable(Tab,image);
    ImEcrire(image4,"paysage4.pgm");   
    RemplirTableGamma(2.5,Tab);
    image5 = AppliquerTable(Tab,image);
    ImEcrire(image5,"paysage5.pgm");  
    ImLiberer(&image);
    ImLiberer(&image2);
    ImLiberer(&image3);
    ImLiberer(&image4);
    ImLiberer(&image5);
    return 0;
}