#include <stdio.h>

int main(void)
{
    printf("Tapez le nombre de valeur :");
    fflush(stdout);
    int nb_v;
    scanf("%d",&nb_v);
    int v;
    double moyenne=0;
    for (int i=0; i<nb_v; i++)
    {
        scanf("%d",&v);
        if (v<0 || v>20)
        {
            printf("Valeur non valide tapez une autre valeur\n");
            i--;
        }
        moyenne+=v;
    }
    moyenne = moyenne / nb_v;
    printf("La moyenne est : %lf\n", moyenne);
    return 0;
}
