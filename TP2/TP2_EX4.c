#include <stdio.h>

int main(void)
{
    printf("Tapez un nombre :");
    fflush(stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=(2*n-1);j++)
        {
            if(j>(n-i) && j<(n+i)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
