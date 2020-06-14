#include "mois.h"


/* Cette fonction est pour le moi de février */
int moisFevrier(int annee_convertir,int *compteur_jour, int jour)
{
    int quatre = annee_convertir / 4 , cent = annee_convertir / 100, divisible100 = 0;
    int reste_cent = annee_convertir % 100;
    int nombreDeJourAParcourir = 0;

    divisible100 = 100 * cent + reste_cent;

    if( divisible100 == annee_convertir )
    {
        nombreDeJourAParcourir = 28;
    }
    else
    {
        nombreDeJourAParcourir = 29;

    }

    *compteur_jour = nombreDeJourAParcourir - jour;
}



void moisActuel(int *mois, int *jour, int *compteur_jour )
{
    int nombreDeJourAParcourir = 0;

    if( *mois == 1 || *mois == 3 || *mois == 5 || *mois == 7 ||
        *mois == 10 || *mois == 12)
    {
        nombreDeJourAParcourir = 30;
    }
    else if ( *mois == 4 || *mois == 6 || *mois == 9 || *mois == 11 )
    {
        nombreDeJourAParcourir = 29;
    }



}

/* Prends un paramètre de type int
   L'utilité de cette fonction est de savoir si une année est bissextile ou pas  */
void estBissextile(int anne_a_convertir, short *bissextile)
{
    int quatre =  anne_a_convertir / 4, cent = anne_a_convertir / 100;
    int divisible4 = 0, divisible100 = 0, reste_quatre = anne_a_convertir % 4, reste_cent = anne_a_convertir % 100;
    //int nombrejour = 0;

    /* quatre vaudra le quotient de l'année à divisé */

    printf("Quatre : %d -- Cent : %d\n\n", quatre, cent);
    /* Après cette ligne on voit si il est divisible ou pas */
    /* on le fait dans le sens inverse */
    divisible4 = 4 * quatre + reste_quatre; divisible100 = 100 * cent + reste_cent;

    /* si divisible par 100 donc PAS bissextile !!!
       ex : pour 2000 non car 20 * 100 = 2000 mais par 4 c'est correct !!*/
    if ( divisible100 == anne_a_convertir )
    {
        printf("Est pas bissextile !!!\n\n");
        *bissextile = 0;
    }
    else
    {
        printf("Est bissextile !\n\n");
        *bissextile = 1;
    }
}

