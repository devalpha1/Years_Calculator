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


/* Retourne valeur de type sort  et prends
   un paramètre de type int
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

/* Cette fonction est pour le moi de février */
int moisFevrier(int annee_convertir,int *compteur_jour, int jour )
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

void calculeAnnee(int *tableauAnnee, int *compteur_jour)
{
    int i = 0, addition = 0;

    while( tableauAnnee[i] != -1 )
    {
        if (tableauAnnee[i] == 0)
        {
            addition = addition + 365;
        }
        else
        {
            addition = addition + 366;
        }
        i++;
    }

    *compteur_jour = addition;
}

void moisActuel(short *mois, int *premierMois, int *jour, int *compteur_jour )
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

    if(*premierMois == 1)
    {
        *compteur_jour = nombreDeJourAParcourir - *jour;
    }

}

void anneeSuivant(int *annee_maintenant, int *annee, int *compteur_jour)
{
    int tableauAnnee[200] = {-1}, i = 0, stockAnnee = annee;

    int *pTableauAnnee = NULL;

    short bissextile = 0;

    stockAnnee++;

    for( i = 0 ; i < 200 ; i++ )
    {
        tableauAnnee[i] = -1;
    }

    i = 0;

    pTableauAnnee = tableauAnnee;

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

    calculeAnnee(pTableauAnnee, compteur_jour);

}

void soustractionDerniereAnnee(int *annee_maintenant, int *mois_maintenant, int *jour_maintenant,
                               int *resultat_addition)
{
    /* pour savoir si la dernière année est bissextile */
    int bissextile = 0, i = 0, j = 0, nombreDeJourARajoute = 0;

    estBissextile(annee_maintenant, bissextile);

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
        else if( i == 4 || i == 6 || i = 9 || i == 11 )
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
    short janvier[31] = {1}, fevrier[29] = {0}, mars[31] = {1}, avril[30] = {1}, mai[31] = {1};
    short juin[30] = {1}, juillet[31] = {1}, aout[31] = {1}, septembre[30] = {1}, octobre[31] = {1};
    short novembre[30] = {1}, decembre[31] = {1};

    int compteur_jour = 0, i_mois = 0, i_ans = 0, i_jour, resultat_addition;

    int i = 0; // pour le mois de février

    if ( bissextile )
    {
        for ( i = 0 ; i < 30 ; i++ )
        {
            fevrier[i] = 1;
        }
    }
    else
    {
        for ( i = 0 ; i < 28 ; i++ )
        {
            fevrier[i] = 1;
        }
    }

    for ( i = 0 ; i < 31 ; i++ ) /* initialisation de janvier, mars, mai, juillet ... */
    {
        janvier[i] = 1;
        mars[i] = 1;
        mai[i] = 1;
        juillet[i] = 1;
        octobre[i] = 1;
        decembre[i] = 1;
    }

    for( i = 0 ; i < 30 ; i++ )
    {
        avril[i] = 1;
        juin[i] = 1;
        septembre[i] = 1;
        novembre[i] = 1;
    }

    switch(*mois)
    {
        case 1:
            moisActuel(mois, 1, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 2:
            moisFevrier(annee, &compteur_jour, jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 3: // si le mois est mars
            moisActuel(mois, 1, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 4: // si le mois est avril
            moisActuel(mois, 1, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 5: // si le mois est mai
            moisActuel(mois, 1, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 6: // si le mois est juin
            moisActuel(mois, 1, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 7: // si le mois est juillet
            moisActuel(*mois, 1, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 8: // si le mois est aout
            moisActuel(mois, 1, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 9: // si le mois est septembre
            moisActuel(mois, 1, jour, &compteur_jour);
            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 10: // si le mois est octobre
            moisActuel(mois, 1, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 11: // si le mois est novembre
            moisActuel(mois, 1, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
        case 12: // si le mois est decembre
            moisActuel(mois, 1, jour, &compteur_jour);

            for( i_mois = *mois+1 ; i_mois < 13 ; i_mois++)
            {
                moisActuel(&i_mois, 0, jour, &compteur_jour);
            }
        break;
    }
    /* Maintenant qu'on à fait pour la première année on peux faire les années suivant */

    anneeSuivant(annee_maintenant, annee, compteur_jour);

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

void fonctionConversion(int *pointeurAnnee,       int *pointeurMois,        int *pointeurJour, int *pointeurTotalJours,
                        int *pointeurJourEnCours, int *pointeurMoisEnCours, int *pointeurAnneeEnCours)
{
    short bissextile = 0;
    /* Affiche le message Veuillez entree votre annee puis saisi l'annee et
    va dans la fonction convertir_annee */
    printf("Veuillez entree votre ANNEE de naissance : ");
    scanf("%d", pointeurAnnee);
    printf("Veuillez entree MOIS de naissance : ");
    scanf("%d", pointeurMois);
    printf("Veuillez entree votre JOURS de naissance : ");
    scanf("%d", pointeurJour);
    /* situé quel est le mois pour le nombre de jour */
    estBissextile(pointeurAnnee, &bissextile);

    *pointeurTotalJours = parcourAnnee(bissextile, pointeurAnnee, pointeurMois, pointeurAnnee,  pointeurAnneeEnCours, pointeurMoisEnCours, pointeurJourEnCours);
}

void demandeJourMoisAnneeActuel(int *pointeurAnneeEnCour,int *pointeurMoisEnCours,int *pointeurJourEnCours)
{
    /*on demande l'annee en cours, le mois en cours, et le jours en cour*/
    printf("Quel est l'annee en cour : ");
    scanf("%d", pointeurAnneeEnCour);
    printf("Quel est le mois en cour : ");
    scanf("%d", pointeurMoisEnCours);
    printf("Quel est jour en cour : ");
    scanf("%d", pointeurJourEnCours);
}

void menu()
{
    /* Affichage du menu et le choix de l'utilisateur */
    printf("\t\t\t ==== Convertion d'annee ==== \n\n\n");
    printf("\t 1 -> Nouvelle convertion \n");
    printf("\t 2 -> Quitte \n\n\n");
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
    demandeJourMoisAnneeActuel(&anneeEnCour, &moisEnCours, &jourEnCours);

    system("PAUSE");
    system("cls");

    do
    {
        menu();

        printf("\tNombre Jour : %d\t",totalJours);
        printf("Date Actuel : %d-%d-%d\n\n", jourEnCours, moisEnCours, anneeEnCour);
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
