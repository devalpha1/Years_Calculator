#include "annee.h"
#include "definition.h"

/* erreur c'est tableau Annee car on ne peux que Modifier une seul case dans un tableau */
void calculeAnnee(int *tableauAnnee, int *compteur_jour)
{
    int i = 0, addition = 0;

    if( tableauAnnee == 0 )
    {
        *compteur_jour += 365;
    }
    else if ( tableauAnnee == 1)
    {
        *compteur_jour += 366;
    }

}

void anneeSuivant(int *annee_maintenant, int *annee, int *compteur_jour)
{
    int tableauAnnee[200] = {-1}, i = 0, stockAnnee = annee;


    short bissextile = 0;

    stockAnnee++;

    for( i = 0 ; i < 200 ; i++ )
    {
        tableauAnnee[i] = -1;
    }

    i = 0;

    /* va déterminté si la deuxième année est bossextile */
    estBissextile(stockAnnee, &bissextile);

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

    while( stockAnnee != *annee_maintenant )
    {
        estBissextile(stockAnnee, &bissextile);

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

    for ( i = 0 ; i < 200; i++ )
    {
        calculeAnnee(&tableauAnnee[i], compteur_jour);
    }

}

void soustractionDerniereAnnee(int *annee_maintenant, int *mois_maintenant, int *jour_maintenant,
                               int *resultat_addition)
{
    /* pour savoir si la dernière année est bissextile */
    int i = 0, j = 0, nombreDeJourARajoute = 0;
    short bissextile = 0;

    estBissextile(*annee_maintenant, &bissextile);

    for ( i = 1 ; i < *mois_maintenant+1 ; i++ )
    {
        if( i == 1 || i == 3 || i == 5 || i == 5 || i == 7 ||
            i == 10 || i == 12 )
        {
            for( j = 1 ; j < 30+1 ; j++, nombreDeJourARajoute++ )
            {
                if( *mois_maintenant == i && *jour_maintenant == j )
                {
                    break;
                }
            }
        }
        else if( i == 4 || i == 6 || i == 9 || i == 11 )
        {
            for( j = 1 ; j < 29+1 ; j++, nombreDeJourARajoute++ )
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


/* Cette fonction prends comme paramètre l'année de l'utilsateur et si il est bissextile ou pas,
   le mois et le jour de la personne ET aussi l'année, le mois, jour d'aujourd'hui */
int parcourAnnee(short *bissextile, int *annee,            int *mois,            int *jour,
                                    int *annee_maintenant, int *mois_maintenant, int *jour_maintenant)
{

    int compteur_jour = 0, i_mois = 0, i_ans = 0, i_jour, resultat_addition;

    int i = 0; // pour le mois de février

    switch(*mois)
    {
        case janvier:
            moisActuel(mois, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case fevrier:
            moisFevrier(annee, &compteur_jour, jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case mars: // si le mois est mars
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case avril: // si le mois est avril
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case mai: // si le mois est mai
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case juin: // si le mois est juin
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case juillet: // si le mois est juillet
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case aout: // si le mois est aout
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case septembre: // si le mois est septembre
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case octobre: // si le mois est octobre
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case novembre: // si le mois est novembre
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case decembre: // si le mois est decembre
            moisActuel(mois, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
    }
    /* Maintenant qu'on à fait pour la première année on peux faire les années suivant */

    anneeSuivant(annee_maintenant, annee, &compteur_jour);

    soustractionDerniereAnnee(annee_maintenant, mois_maintenant, jour_maintenant, &resultat_addition);


    /* Tant que i_ans est plus petit que l'année de maintenant augmente de 1 pour l'année suivante */
    for( i_ans = annee + 1 ; i_ans <= annee_maintenant ; i_ans++ )
    {
        i_mois = 1;
        i_jour = 1;

        for( i = 0 ; i < 31 ; i++ ) /* pour le mois de janvier :  */
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant   )
            {
                printf("Vous avez %d jours", compteur_jour);
                // Si c'est le mois janvier et un jour spécifique au janvier donc cette CONDITION s'active
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 2; // le mois janvier est fini donc maintenant c'est au mois de février
        i_jour = 1; // réinitialisation du nombre de jour pour le mois suivant

        for( i = 0 ; i < moisFevrier(i_ans) ; i++ ) /* pour le mois de janvier : */
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  ==  annee_maintenant    )
            {
                // Si c'est le mois de février et un jour spécifique au février donc cette Condition s'active
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 3;
        i_jour = 1;

        for( i = 0 ; i < 31 ; i++ ) /* pour le mois de mars : */
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant    )
            {
                // Si c'est le mois de mars et un jour spécifique au mars dobc cette CONDITION s'active
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 4;
        i_jour = 1;

        for( i = 0 ; i < 30 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant    )
            {
                // Si c'est le mois d'avril et un jour spéicifique au avril donc cette CONDITION s'active
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 5;
        i_jour = 1;

        for( i = 0 ; i < 31 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant    )
            {
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 6;
        i_jour = 1;

        for( i = 0 ; i < 30 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant    )
            {
                //
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 7;
        i_jour = 1;

        for( i = 0 ; i < 31 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant    )
            {
                //
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 8;
        i_jour = 1;

        for( i = 0 ; i < 31 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant    )
            {
                //
                 return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 9;
        i_jour = 1;

        for( i = 0 ; i < 30 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant    )
            {
                //
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 10;
        i_jour = 1;

        for ( i = 0 ; i < 31 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant   )
            {
                //
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }

        i_mois = 11;
        i_jour = 1;

        for( i = 0 ; i < 30 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant   )
                {
                   //
                   return compteur_jour;
                }
                else
                {
                    i_jour++;
                    compteur_jour++;
                }
        }

        i_mois = 12;
        i_jour = 1;

        for( i = 0 ; i < 31 ; i++ )
        {
            if( i_mois == mois_maintenant &&
                i_jour == jour_maintenant+2 &&
                i_ans  == annee_maintenant   )
            {
                //
                return compteur_jour;
            }
            else
            {
                i_jour++;
                compteur_jour++;
            }
        }
    } // fin de condition pour un ans

    printf("Vous avez %ld jours", compteur_jour);

    printf("Merci d'avoir utilisee le programme\n");

    return compteur_jour;
}
