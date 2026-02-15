#include <stdio.h>

int main(void)
{
    printf("Entrez le nombre de valeurs : ");
    fflush(stdout);
    int nb;
    scanf("%d",&nb);
    double tab[nb];
    double moyenne=0,v;
    printf("Entrez les valeurs :\n");
    for(int i=0; i<nb; i++)
    {
        scanf("%lf",&v);
        moyenne+=v;
        tab[i]=v;
    }
    moyenne=moyenne/nb;
    printf("La moyenne est : %f\n",moyenne);
    printf("Les valeurs strictement supérieurs à la moyenne sont : \n");
    for(int i=0; i<nb; i++) if(tab[i]>moyenne) printf("%f\n",tab[i]);
    return 0;
}
