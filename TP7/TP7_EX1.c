#include <stdio.h>
#include <stdlib.h>

typedef unsigned char **tMatrice;

tMatrice MatAllouer(int NbLig, int NbCol)
{
    tMatrice matrice;
    unsigned char *valeur;
    matrice=malloc(NbLig*sizeof(unsigned char *));
    if(matrice!=NULL)
    {
        valeur=malloc(NbLig*NbCol*sizeof(unsigned char));
        if(valeur==NULL) matrice=NULL;
        else for(int i=0; i<NbLig; i++) matrice[i]=&valeur[i*NbCol];
    }
    return matrice;
}

void MatLiberer(tMatrice *pMat)
{
    free(**pMat);
    free(*pMat);
    *pMat=NULL;
}

tMatrice Triangle(int n)
{
    tMatrice triangle;
    triangle=MatAllouer(n,n);
    for (int i=0;i<n;i++) for (int j=0; j<i+1; j++)
    {
        if(j==0 || j==i) triangle[i][j]=1;
        else triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
    }
    return triangle;
}

void AffTriangle(tMatrice A, int NbLig)
{
    for (int i=0;i<NbLig;i++) 
    {
        for (int j=0; j<i+1; j++) printf("%d ", A[i][j]);
        printf("\n");
    }   
}

int main(void)
{
    tMatrice triangle;
    int n;
    printf("Entrez le nombre de lignes : ");
    fflush(stdout);
    scanf("%d", &n);
    triangle=Triangle(n);
    AffTriangle(triangle, n);
    MatLiberer(&triangle);
    return 0;
}