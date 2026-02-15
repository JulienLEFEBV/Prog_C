#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int nb_voiture_1=0,nb_voiture_2=0,NB;
pid_t pid;

void traiter_signal(int signal){
    if(signal==SIGUSR1) 
    {
        nb_voiture_1+=NB;
        printf("Père (%d) - Capteur 0 : nombre de vehicule = %d\n",NB);
    }
    if(signal==SIGUSR2){
        nb_voiture_2+=NB;
        printf("Père (%d) - Capteur 1 : nombre de vehicule = %d\n",NB);
    }
}

void erreur(void)
{
    perror("Erreur :");
    exit(1);
}

int main(int argc, char*argv[])
{
    if (argc!=3){
        fprintf(stderr,"Nombre d'argument invalide \n");
        exit(1);
    }
}