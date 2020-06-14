/* Nom de projet : Years_calculator
   Année : 2020
   Dernière mise à jour : mai 2020
   Description : Avec cette application sous console vous
   pouvez savoir le nombre de jour convertie depuis le nombre d'année
   pour par exemple votre date de naissance.
   Pour savoir si une annee est bissextile on utilise la condition si il est
   divisible par 4 et non divisible par 100. (rf.wikipedia)
   Exemple 4 : divisible par 4 : 4, 8, 12, 16, 20, 24 , 28, 32, etc...
   Exemple : divisible par 100 : x00 et pas divisible : différent de x00 ->
   99 pas divisible par 100 !!!
   Ecrit : Skywashi
   Contact : contactpro.reunion@gmail.com
   License : licence libre  */


#include <stdio.h>
#include <stdlib.h>
#include "collecte_information.c"
#include "affichage.c"
#include "mois.c"
#include "annee.c"


void fonctionConversion(int *pointeurAnnee,       int *pointeurMois,        int *pointeurJour, int *pointeurTotalJours,
                        int *pointeurJourEnCours, int *pointeurMoisEnCours, int *pointeurAnneeEnCours)
{
    short bissextile = 0;
    /*Demande l'annee les information sur l'utilisateur */
    demandeJourDeNaissance(pointeurJour);

    demandeMoisDeNaissance(pointeurMois);

    demandeAnneeDeNaissance(pointeurAnnee);
    /* situé quel est le mois pour le nombre de jour */
    estBissextile(pointeurAnnee, &bissextile);

    *pointeurTotalJours = parcourAnnee(bissextile, pointeurAnnee, pointeurMois, pointeurAnnee,  pointeurAnneeEnCours, pointeurMoisEnCours, pointeurJourEnCours);
}


/* La fonction main va prendre un argument dans l'avenir ...*/
int main(int argc, char *argv[])
{
    /*la variable choix va être le choix de quitte le programme ou faire une nouvelle
    conversion , annee pour l'annee de l'utilisateur*/
    int choix = 0, annee = 2019, mois = 11, jour = 20,
    int anneeEnCour = 2020, moisEnCours = 5, jourEnCours = 6;
    int totalJours = 0;
    /* Ici nous disons une petit message de bienvenue à l'utilisateur,
       appel de la fonction demandeJourMoisAnneeActuel et une PAUSE,
       on attends que l'utilisateur appuie sur une touche et on efface le console puis viens la boucle do */
    printf("Bienvenue sur ce petit programme de convertion d'annee en jours! \n");

    /*Quel est la date actuel */
    demandeJourActuel(&jourEnCours);
    demandeMoisActuel(&moisEnCours);
    demandeAnneeActuel(&anneeEnCour);

    system("PAUSE");
    system("cls");

    do
    {
        menu();

        printf("\tNombre Jour : %d\t",totalJours);

        printf("Date actuel : %d-", jourEnCours);
        printf("%d-", moisEnCours);
        printf("%d\n\n", anneeEnCour);

        scanf("%d", &choix);

        switch(choix) // Début des condition
        {
            case 1: // si choix vaut 1 -> l'utilisateur veux faire une conversion
            {
                fonctionConversion(&annee, &mois, &jour, &totalJours, &jourEnCours, &moisEnCours, &anneeEnCour);

                break;
            }
            case 2: // si l'utilisateur veux quittée le programme
            {
                system("CLS");
                printf("Merci d'avoir utilisee le programme");
                break;
            }
            default:
            {
                printf("Vous avez saisi un mauvais chiffre \n");
                break;
            }
        }
    }while(choix != 2);


    return EXIT_SUCCESS;
}
