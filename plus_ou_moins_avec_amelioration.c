#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menuPrincipal () //on crée la fonction qui permetra de chiosir entre le mode 1 ou 2 joueurs
{

    printf("\n----MENU-----\n");
    printf(" 1- mode 1 joueur\n");
    printf(" 2- mode 2 joueurs\n");
    printf(" choisissez le mode en tapant 1 ou 2\t");
}

long menu () //on crée la fonction qui permet de choisir le niveau de difficulté dans le mode 1 joueur
{
    long choixNiveau = 0;

    do
       { 
        printf("vous avez choisis le mode 1 joueur\n");
        printf("choix du niveau\n");
        printf("niveau 1:de 1 a 100\n");
        printf("niveau 2:de 1 a 1000\n");
        printf("niveau 3:de 1 a 10 000\n");
        printf("choississez un niveau\t");
        scanf("%ld", &choixNiveau);
    }while(choixNiveau < 1 && choixNiveau > 3);
    return choixNiveau;
}




int main(int argc, char *argv[]) //fonction main
{
    long nombreEntre = 0,compteur = 0,continuer = 0, choixMode = 2, prenom[100]; //les variables qui sont utilisées pour des actions
    long nombreMystere = 0,nombreMax = 100, MIN = 0, nombreMax1 = 1000, nombreMax2 = 10000; //les variables pour les differents nombres qui sont utilsées dans le jeu

    srand(time(NULL)); //important:cette ligne ne peut apparaitre qu'une seule fois par code
    nombreMystere = (rand() % (nombreMax - MIN + 1)) + MIN; //fonction qui gere le nombre aleatoire

    do
    {
        menuPrincipal(); //appel de la fonction menuprincipal
        scanf("%ld", &choixMode);
        if( choixMode == 1)//condition pour entrer dans le mode 1 joueur
        {

            switch (menu())// switch permettant de gere et lancer les differents niveaux dans le mode 1 joueur
            {
                case 1:
               nombreMystere = (rand() % (nombreMax - MIN + 1)) + MIN; //niveau 1
                printf("vous avez choisi le niveau 1\n");
                break;

                case 2:
                nombreMystere = (rand() % (nombreMax1 - MIN + 1)) + MIN; //niveau 2
                printf("vous avez choisi le niveau 2\n");
                break;

                case 3:
                nombreMystere = (rand() % (nombreMax2 - MIN + 1)) + MIN; //niveau 3
                printf("vous avez choisi le niveau 3\n");
                break;
            }
            do// boucle qui genere et compare le nombre entre et le nombre mystere
            {
                compteur++; //genere le compteur de coup
                printf("quelle est ce nombre ?\n");
                scanf("%ld", &nombreEntre);

                if( nombreMystere > nombreEntre)
                printf("c'est plus\n");

                else if( nombreMystere < nombreEntre)
                printf("c'est moins\n");

                else
                printf("bravo vous avez gagnez en %ld coups\n", compteur);

            } while(nombreMystere != nombreEntre);


        }
        else if(choixMode == 2) //condition pour le mode 2 joueur
        {
            printf("vous avez choisi le mode 2 joueur\n");
            printf("comment vous appellez vous ?\t");
            scanf("%s", prenom);
            printf("veuiller saisir un nombre mystere entre 1 et ...\t\t\t");
            scanf("%ld", &nombreMystere);
            system("cls");
            do // boucle qui gere et compare le nombre entre et le nombre mystere
            {
                compteur++;//gere le compteur de coup
                printf("quelle est ce nombre ?\n");
                scanf("%ld",&nombreEntre);

                if( nombreMystere > nombreEntre)
                printf("c'est plus\n");

                else if( nombreMystere < nombreEntre)
                printf("c'est moins\n");

                else
                printf("bravo %s, vous avez gagnez en %ld coups\n", prenom, compteur);

            }while(nombreMystere != nombreEntre);
        }

        compteur = 0;
        printf("voulez vous recommencer OUI:1,NON:0\t");
        scanf("%ld", &continuer);
    } while(continuer == 1); //boucle qui demande a l'utilisateur de recomencer le programme ou non

    system("PAUSE"); //pause
    return 0;
} //fin du programme  :)
