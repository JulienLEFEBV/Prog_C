#include "matrice.h"
int main(void)
{
    tMatrice matrice,matrice2;
    int NbLig,NbCol;
    matrice = MatLire(&NbLig, &NbCol);
    MatAfficher(matrice, NbLig, NbCol);
    matrice2=MatCopier(matrice,NbLig,NbCol);
    MatAfficher(matrice2, NbLig, NbCol);
    MatLiberer(&matrice);
    MatLiberer(&matrice2);
    return 0;
}