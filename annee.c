#include "annee.h"
#include "definition.h"
#include "mois.h"
#include <stdio.h>

/* erreur c'est tableau Annee car on ne peux que Modifier une seul case dans un tableau */
void calculeAnnee(int *tableauAnnee, int *compteur_jour)
{
    int i = 0;

    if( *tableauAnnee == 0 )
    {
        *compteur_jour += 365;
    }
    else if ( *tableauAnnee == 1)
    {
        *compteur_jour += 366;
    }

}
/* calcule pour les autres ann�e de la date d'anniversaire */
void lesAnneeSuivant(int *annee_maintenant, int *annee, int *compteur_jour)
{
    int tableauAnnee[200] = {-1}, i = 0, stockAnnee = *annee;
    int difference = *annee_maintenant - *annee;


    short bissextile = 0;

    stockAnnee++;

    /* initilisation de tableauAnnee */
    for( i = 0 ; i < 200 ; i++ )
    {
        tableauAnnee[i] = -1;
    }

    i = 0;

    /* va d�termint� si la deuxi�me ann�e est bossextile */
    estBissextile(&stockAnnee, &bissextile);

    /* 1 pour dire il est bissextile et 0 pour dire que c'est pas
       bissextile */
    if ( bissextile )
    {
        tableauAnnee[i] = 1;
    }
    else
    {
        tableauAnnee[i] = 0;
    }

    i++;
    stockAnnee++;

    /* pour les ann�ee suivant affectation de la valeur binaire 1 ou
       0 pour les ann�es suivant */

    while( stockAnnee != *annee_maintenant )
    {
        estBissextile(&stockAnnee, &bissextile);

        if ( bissextile )
        {
            tableauAnnee[i] = 1;
        }
        else
        {
            tableauAnnee[i] = 0;
        }

        i++;
        stockAnnee++;
    }

    /* faire le total des jours */
    i = 0;
    while( tableauAnnee[i] != -1 )
    {
        calculeAnnee(&tableauAnnee[i], compteur_jour);
        i++;
    }

}

void soustractionDerniereAnnee(int *annee_maintenant, int *mois_maintenant, int *jour_maintenant,
                               int *resultat_addition)
{
    /* pour savoir si la derni�re ann�e est bissextile */
    int i = 0, j = 0, nombreDeJourARajoute = 0;
    short bissextile = 0;

    estBissextile(annee_maintenant, &bissextile);

    for ( i = 1 ; i < *mois_maintenant ; i++ )
    {
        if( i == 1 || i == 3 || i == 5 || i == 7 ||
            i == 10 || i == 12 )
        {
            for( j = 1 ; j < 31+1 ; j++, nombreDeJourARajoute++ )
            {
                if( *mois_maintenant == i && *jour_maintenant == j )
                {
                    break;
                }
            }
        }
        else if( i == 4 || i == 6 || i == 9 || i == 11 )
        {
            for( j = 1 ; j < 30+1 ; j++, nombreDeJourARajoute++ )
            {
                if( *mois_maintenant == i && *jour_maintenant == j )
                {
                    break;
                }
            }
        }
        else if( i == 2 )
        {
            if ( bissextile )
            {
                for( j = 1 ; j < 29+1 ; j++, nombreDeJourARajoute++ )
                {
                    if( *mois_maintenant == i && *jour_maintenant == j )
                    {
                        break;
                    }
                }
            }
            else
            {
                for( j = 1 ; j < 28+1 ; j++, nombreDeJourARajoute++ )
                {
                    if( *mois_maintenant == i && *jour_maintenant == j )
                    {
                        break;
                    }
                }
            }
        }
    }
    *resultat_addition = nombreDeJourARajoute;
}


/* Cette fonction prends comme param�tre l'ann�e de l'utilsateur et si il est bissextile ou pas,
   le mois et le jour de la personne ET aussi l'ann�e, le mois, jour d'aujourd'hui */
int parcourAnnee(short *bissextile, int *annee,            int *mois,            int *jour,
                                    int *annee_maintenant, int *mois_maintenant, int *jour_maintenant)
{

    int compteur_jour = 0, i_mois = 0, i_ans = 0, i_jour, resultat_addition;

    int i = 0; // pour le mois de f�vrier


    /* en fonction du premier mois de naissance de l'utilisateur */
    if( fevrier == *mois)
    {
        moisFevrier(annee,  &compteur_jour, jour);

    }
    else
    {
        moisActuel(&i_mois, jour, &compteur_jour);
    }

    compteur_jour = *jour - compteur_jour;

    /* ajoute au compteur de jour le nombre de jour - sur le
    total du mois de l'utilisateur puis ajoute pour les mois suivant
    jusqu'au mois de d�cembre */

    for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
    {
        moisActuel(&i_mois, jour, &compteur_jour);
    }

    /* Maintenant qu'on � fait pour la premi�re ann�e on peux faire les ann�es suivant */

    lesAnneeSuivant(annee_maintenant, annee, &compteur_jour);

    soustractionDerniereAnnee(annee_maintenant, mois_maintenant, jour_maintenant, &resultat_addition);

    compteur_jour = resultat_addition + compteur_jour;

    printf("Vous avez %ld jours", compteur_jour);

    printf("Merci d'avoir utilisee le programme\n");

    return compteur_jour;
}

