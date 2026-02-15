#include <stdio.h>

int main(void)
{
    printf("Entrer un text terminant par #\n");
    char c;
    scanf("%c",&c);
    int nb_l=0, nb_v=0;
    while (c!='#')
    {
        if (c>='a' && c<='z') nb_l++;
        else if(c!=' ')
        {
            printf("Le caractère %c de code %d n'est pas valide \n",c,c);
            return 0;
        }
        if (c=='a' || c=='e' || c=='y' || c=='u' || c=='i' || c=='o') nb_v++;
        scanf("%c",&c);
    }
    printf("Le nombres de lettre est %d et le nombre de voyelles est %d\n",nb_l,nb_v);
    return 0;
}
