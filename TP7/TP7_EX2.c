#include <stdio.h>
#include <stdlib.h>

void Trier(int Tab[], int NbElts)
{
    for(int i=NbElts-1;i>=1;i--) for(int j=0; j<i;j++) if(Tab[j+1]<Tab[j])
    {
        int sauv;
        sauv = Tab[j];
        Tab[j]=Tab[j+1];
        Tab[j+1]=sauv;
    }
}

void Aff(int Tab[], int NbElts)
{
    for(int i=0;i<NbElts;i++) printf("%d ", Tab[i]);
    printf("\n");
}

void TrierPtr(int Tab[], int NbElts, int *Ptr[])
{
    for(int i=0; i<NbElts; i++) Ptr[i]=&Tab[i];
    for(int i=NbElts-1;i>=1;i--) for(int j=0; j<i;j++) if(*Ptr[j+1]<*Ptr[j])
    {
        int *sauv;
        sauv = Ptr[j];
        Ptr[j]=Ptr[j+1];
        Ptr[j+1]=sauv;
    }
}

int ** TrierPtr2(int Tab[], int NbElts)
{
    int **Ptr;
    Ptr=malloc(NbElts*sizeof(int *));
    if(Ptr!=NULL)
    {
        for(int i=0; i<NbElts; i++) Ptr[i]=&Tab[i];
        for(int i=NbElts-1;i>=1;i--) for(int j=0; j<i;j++) if(*Ptr[j+1]<*Ptr[j])
        {
            int *sauv;
            sauv = Ptr[j];
            Ptr[j]=Ptr[j+1];
            Ptr[j+1]=sauv;
        }
    }
    return Ptr;
}

void TrierPtr3(int Tab[], int NbElts,int ***Ptr)
{
    *Ptr=malloc(NbElts*sizeof(int *));
    if(*Ptr!=NULL)
    {
        for(int i=0; i<NbElts; i++) (*Ptr)[i]=&Tab[i];
        for(int i=NbElts-1;i>=1;i--) for(int j=0; j<i;j++) if(*(*Ptr)[j+1]<*(*Ptr)[j])
        {
            int *sauv;
            sauv = (*Ptr)[j];
            (*Ptr)[j]=(*Ptr)[j+1];
            (*Ptr)[j+1]=sauv;
        }
    }
}

void AffPtr(int *TabP[], int NbElts)
{
    for(int i=0;i<NbElts;i++) printf("%d ", *TabP[i]);
    printf("\n");
}

int main(void)
{
    int Tab[10]={2,32,10,50,1,-5,8,4,9,-100},**TabP;
    TrierPtr3(Tab, 10, &TabP);
    AffPtr(TabP,10);
    free(TabP);
    TabP=NULL;
    return 0;
}

