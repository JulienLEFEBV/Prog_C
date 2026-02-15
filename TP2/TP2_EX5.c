#include <stdio.h>

int main(void)
{ 
    int f;
    printf("Entrez une valeur entre 0 et 18 : ");
    fflush(stdout);
    scanf("%d",&f);
    while(f<0 || f>18)
    {
        printf("Valeur invalide entrez une valeur entre 0 et 18 : ");
        fflush(stdout);
        scanf("%d",&f);
    }
    printf(" x |");
    for(int i=0; i<=f; i++) printf("%4d",i);
    printf("\n");
    for(int i=0; i<((f+2)*4); i++) printf("-");
    printf("\n");
    for(int i=0; i<=f; i++)
    {
        printf("%2d |",i);
        for(int j=0; j<=f; j++) printf("%4d",i*j);
        printf("\n");
    }
    return 0;
}
