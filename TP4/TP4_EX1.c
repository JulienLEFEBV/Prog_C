#include <stdio.h>

void AfficherTab(int Tab[], int NbElt);
int Min(int Tab[], int NbElt);
void MinMax(int Tab[], int NbElt, int *pMin, int *pMax);
void MinMax2(int Tab[], int NbElt, int **pMin, int **pMax);
int SupprimerVal(int Tab[], int *pNbElt, int Val);

int main(void)
{
    int Tab[10]={0,1,2,3,4,5,6,7,8,9};
    int Tab2[10]={0,1,0,7,4,-1,85,7,45,9};
    int Tab3[10]={0,1,4,7,4,-1,4,7,4,9};
    AfficherTab(Tab, 10);
    printf("%d\n",Min(Tab, 10));
    int Max=0, min=0;
    MinMax(Tab2, 10, &min, &Max);
    printf("%d %d\n",min , Max);
    int *pMax, *pMin;
    MinMax2(Tab2, 10, &pMin, &pMax);
    printf("%d %d\n",*pMin , *pMax);
    int NbElt=10,NbSup;
    NbSup=SupprimerVal(Tab3,&NbElt,4);
    AfficherTab(Tab3,NbElt);
    printf("%d\n",NbSup);
    return 0;
}

void AfficherTab(int Tab[], int NbElt)
{
    for(int i=0; i<NbElt; i++) printf("%d ", Tab[i]);
    printf("\n");
}

int Min(int Tab[], int NbElt)
{
    int min;
    min=Tab[0];
    for(int i=0; i<NbElt; i++) if(Tab[i]<min) min=Tab[i];
    return min;
}

void MinMax(int Tab[], int NbElt, int *pMin, int *pMax)
{
    *pMin=Tab[0];
    *pMax=Tab[0];
    for (int i=0; i<NbElt; i++)
    {
        if (*pMin>Tab[i]) *pMin=Tab[i];
        if (*pMax<Tab[i]) *pMax=Tab[i];
    }
}

void MinMax2(int Tab[], int NbElt, int **pMin, int **pMax)
{
    int Max,min;
    min=Tab[0];
    Max=Tab[0];
    *pMin=Tab;
    *pMax=Tab;
    for (int i=0; i<NbElt; i++)
    {
        if (min>Tab[i]) 
        {
            min=Tab[i];
            *pMin=&Tab[i];

        }
        if (Max<Tab[i]) 
        {
            Max=Tab[i];
            *pMax=&Tab[i];
        }
    }
}

int SupprimerVal(int Tab[], int *pNbElt, int Val)
{
    int NbSup=0;
    for(int i=0; i<*pNbElt; i++) if(Tab[i]==Val)
    {
        for(int j=i+1;j<*pNbElt;j++)
        {
            Tab[j-1]=Tab[j];
        }
        Tab[*pNbElt-1]=0;
        *pNbElt-=1;
        NbSup++;
    }
    return NbSup;
}
