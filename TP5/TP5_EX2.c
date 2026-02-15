#include <stdio.h>
#include <stdlib.h>

double *CreerTableau(int NbElts)
{
    double *tab;
    tab=malloc(NbElts*sizeof(double));
    return tab;
}

void SaisirTableau(double *Tab, int NbElts)
{
    for (int i=0;i<NbElts;i++) scanf("%lf",&Tab[i]);
}

void AfficherTableau(double *Tab, int NbElts)
{
   for (int i=0;i<NbElts;i++) printf("%f ",Tab[i]); 
   printf("\n");
}

void LibererTableau(double *Tab)
{
    free(Tab);
}

int main(void)
{
    double *Tab;
    int NbElts;
    printf("Entrer la taille du tableau : ");
    fflush(stdout);
    scanf("%d",&NbElts);
    Tab=CreerTableau(NbElts);
    printf("Entrer les éléments du tableau : \n");
    SaisirTableau(Tab, NbElts);
    AfficherTableau(Tab, NbElts);
    LibererTableau(Tab);
}