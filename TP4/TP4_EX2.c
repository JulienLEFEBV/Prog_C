#include <stdio.h>

void convertion1(int valeur, int *heure, int *minute, int *seconde);
void convertion2(int valeur, int Tab[]);

int main(void)
{
    int valeur,heure=0,minute=0,seconde=0,Tab[3];
    printf("Entrez une valeur en secondes : ");
    fflush(stdout);
    scanf("%d",&valeur);
    convertion1(valeur,&heure,&minute,&seconde);
    printf("%d h %d m %d s\n",heure,minute,seconde);
    convertion2(valeur,Tab);
    printf("%d h %d m %d s\n",Tab[0],Tab[1],Tab[2]);
}

void convertion1(int valeur, int *heure, int *minute, int *seconde)
{
    *seconde=valeur%60;
    *minute=valeur/60;
    *heure=*minute/60;
    *minute=*minute%60;
}

void convertion2(int valeur, int Tab[])
{
    Tab[2]=valeur%60;
    Tab[1]=valeur/60;
    Tab[0]=Tab[1]/60;
    Tab[1]=Tab[1]%60;
}