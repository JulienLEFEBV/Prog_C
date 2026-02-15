#include <stdio.h>
#include <math.h>


int main(void)
{
    printf("Ordre de la matrice : ");
    fflush(stdout);
    int n;
    scanf("%d",&n);
    double matrice[10][10];
    double v;
    for(int i=0; i<n; i++)
    {
        printf("Ligne %d : ",i);
        fflush(stdout);
        for(int j=0; j<n; j++)
        {
            scanf("%lf",&v);
            matrice[i][j]=v;
        }
    }
    int verif=1;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) if (verif==1) verif=fabs(matrice[i][j]-matrice[j][i])<0.0000000001;
    if (verif==1) printf("Cette matrice est symétrique\n");
    else printf("Cette matrice n'est pas symétrique\n");

    return 0;
}
