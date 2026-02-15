#include <stdio.h>

int main(void)
{
    char ch[81];
    char c;
    printf("Tapez une ligne de texte composée d’au plus 80 caractères, terminée par le caractère \\n \n");
    scanf("%c",&c);
    int i=0;
    while (i<80 && c!='\n')
    {
        ch[i]=c;
        scanf("%c",&c);
        i++;
    }
    ch[i]='\0';
    printf("Voici la chaine de %d caractères: %s \n",i,ch);
    int j=0;
    char ch2[81];
    while (ch[j]!='\0')
    {
        c=ch[i-1-j];
        ch2[j]=c;
        j++;
    }
    ch2[j]='\0';
    printf("Voici la chaine de caractères inversée: %s \n",ch2);
    int palin=1;
    i=0;
    j=0;
    if (ch[i]==' ') i++;
    if (ch2[j]==' ') j++;
    while(ch[i]!='\0' && ch2[j]!='\0' && palin==1)
    {
        if(ch[i]!=ch2[j]) palin=0;
        i++;
        j++;
        if (ch[i]==' ') i++;
        if (ch2[j]==' ') j++;
    }
    if (palin==1) printf("La chaine est un palindrome\n");
    else printf("La chaine n'est pas un palindrome\n");
    return 0;
}