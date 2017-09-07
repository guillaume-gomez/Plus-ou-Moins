#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc,char *argv[])
{
    long nombreMystere = 0;
    long nombrEntre = 0;
    long compteur = 0;
    long nombreChoisi = 0;
    long niveauChoisi = 0;
    long valeurMaximal= 100;
    long valeurMaximal_1 = 1000;
    long valeurMaximal_2 = 10000;
    long MIN = 0;
    long continuer=0;

    do
    {
        printf("choisissez un niveau\n");
        printf("niveau1:1 a 100\n niveau2:1 a 1000\n niveau3:1 a 10000\n");
        scanf("%ld", &niveauChoisi);

        switch(niveauChoisi)
        {
        case 1:
            srand(time(NULL));
            nombreMystere = (rand() % (valeurMaximal - MIN + 1)) + MIN;
            printf("vous avez choisis le niveau 1\n");
        break;
        case 2:
            srand(time(NULL));
            nombreMystere = (rand() % (valeurMaximal_1 - MIN + 1 )) + MIN;
            printf("vous avez choisis le niveau 2\n");
        break;
        case 3:
            srand(time(NULL));
            nombreMystere = (rand() % (valeurMaximal_2 - MIN + 1 )) + MIN;
            printf("vous avez choisis le niveau 3\n");
        break;
        default:
            printf("votre choix est impossible\n");
        break;
        }

        do
        {

            printf("quelle est le nombre\n");
            scanf("%ld", &nombrEntre);
            compteur++;
            if(nombreMystere > nombrEntre)
            printf("c'est plus\n");

            else if(nombreMystere < nombrEntre)
            printf("c'est moins\n");

            else
            printf("bravo vous avez trouver en %ld coup\n", compteur);

        } while(nombrEntre != nombreMystere);
        
        printf("voulez vous continuer 0/non 1/oui\n");
        scanf("%ld", &continuer);
        compteur=0;
        system("cls");
    } while(continuer == 1);

system("pause");
return 0 ;
}





