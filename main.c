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
short estBissextile(int anne_a_convertir)
{
    int quatre =  anne_a_convertir / 4, cent = anne_a_convertir / 100;
    int divisible4 = 0, divisible100 = 0, reste_quatre = anne_a_convertir % 4, reste_cent = anne_a_convertir % 100;
    //int nombrejour = 0;

    /* quatre vaudra le quotient de l'année à divisé */

    printf("Quatre : %ld -- Cent : %ld\n\n", quatre, cent);
    /* Après cette ligne on voit si il est divisible ou pas */
    /* on le fait dans le sens inverse */
    divisible4 = 4 * quatre + reste_quatre; divisible100 = 100 * cent + reste_cent;

    /* si divisible par 100 donc PAS bissextile !!!
       ex : pour 2000 non car 20 * 100 = 2000 mais par 4 c'est correct !!*/
    if ( divisible100 == anne_a_convertir )
    {
        printf("Est pas bissextile !!!\n\n");

        return 0;
    }
    else
    {
        printf("Est bissextile !\n\n");
        return 1;
    }
}

/* Cette fonction est pour le moi de février */
int moisFevrier(int annee_convertir)
{
    int quatre = annee_convertir / 4 , cent = annee_convertir / 100, divisible100 = 0;
    int reste_cent = annee_convertir % 100;

    divisible100 = 100 * cent + reste_cent;

    if( divisible100 == annee_convertir )
    {
        return 28;
    }
    else
    {
        return 29;
    }
}

/* Cette fonction prends comme paramètre l'année de l'utilsateur et si il est bissextile ou pas,
   le mois et le jour de la personne ET aussi l'année, le mois, jour d'aujourd'hui */
int parcourAnnee(short bissextile, int annee,            int mois,            int jour,
                                    int annee_maintenant, int mois_maintenant, int jour_maintenant)
{
    short janvier[31] = {1}, fevrier[29] = {0}, mars[31] = {1}, avril[30] = {1}, mai[31] = {1};
    short juin[30] = {1}, juillet[31] = {1}, aout[31] = {1}, septembre[30] = {1}, octobre[31] = {1};
    short novembre[30] = {1}, decembre[31] = {1};

    int compteur_jour = 0, i_mois = 0, i_ans = 0, i_jour;

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

    if( mois == 1 ) // si le mois est janvier
    {
        /* cette boucle sert pour les jours dans le mois de janvier */
        for( i = jour ; i < 32 ; i++ )
        {
            if( janvier[i+1] == 1 ) /* pourquoi +1 car c'est pour le jour prochain */
            {
                compteur_jour++;
            }
        }

        /* Cette boucle concerne le mois de février */
        for( i = 0     ; i < 29 ; i++ )
        {
            if( fevrier[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de mars */
        for( i = 0      ; i < 31 ; i++ )
        {
            if( mars[i]    == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois d'avril */
        for( i = 0     ; i < 30 ; i++ )
        {
            if( avril[i]  == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de mai */
        for( i = 0     ; i < 31; i ++ )
        {
            if( mai[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de juin */
        for( i = 0     ; i < 29 ; i++ )
        {
            if( juin[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de juillet  */

        for( i = 0     ; i < 31 ;  i++ )
        {
            if( juillet[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de août */
        for( i = 0     ; i < 31 ; i++ )
        {
            if( aout[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de septembre */
        for( i = 0     ; i < 30 ; i++ )
        {
            if( septembre[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois d'octobre */
        for( i = 0     ; i < 30 ; i++ )
        {
            if( octobre[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de novembre */
        for( i = 0     ; i < 30 ; i++ )
        {
            if( novembre[i] == 1 )
            {
                compteur_jour++;
            }
        }

        /* mois de décembre */
        for( i = 0     ; i < 30 ; i++ )
        {
            if( decembre[i] == 1 )
            {
                compteur_jour++;
            }

        }

    }
    // fin de condition pour le mois de janvier

    if( mois == 2 ) // si le mois est février
    {
        // cette boucle concerne le mois de février
        for( i = jour  ; i < 30 ; i++ )
        {
            if( fevrier[i+1] == 1 )
            {
                compteur_jour++;
            }
        }

        // cette boucle est pour le mois de mars
        for( i = 0     ; i < 31 ; i ++)
        {
            if( mars[i] == 1 )
            {
                compteur_jour++;
            }
        }

        // pour le mois d'avril
        for( i = 0     ; i < 30 ; i++ )
        {
            if( avril[i] == 1 )
            {
                compteur_jour++;
            }
        }

        // pour le mois de mai
        for( i = 0      ; i < 31 ; i++ )
        {
            if( mai[i] == 1 )
            {
                compteur_jour++;
            }
        }

        // pour le mois de juin
        for( i = 0     ; i <  30 ; i++ )
        {
            if( juin[i] == 1 )
            {
                compteur_jour++;
            }
        }

        // pour le mois de juillet
        for( i = 0     ; i < 31 ; i++ )
        {
            if( juillet[i] == 1)
            {
                compteur_jour++;
            }
        }

        // pour le mois d'aout
        for( i = 0      ; i < 31 ; i++ )
        {
            if( aout[i] == 1 )
            {
                compteur_jour++;
            }
        }

        // pour le mois de septembre
        for( i = 0     ; i < 30 ; i++ )
        {
            if( septembre[i] == 1)
            {
                compteur_jour++;
            }
        }

        // pour le mois d'octobre
        for( i = 0     ; i < 31 ; i++ )
        {
            if( octobre[i] == 1 )
            {
                compteur_jour++;
            }
        }

        // pour le mois de novembre
        for( i = 0     ; i < 30 ; i++ )
        {
            if( novembre[i] == 1 )
            {
                compteur_jour++;
            }
        }

        // pour le mois de décembre
        for( i = 0     ; i < 31 ; i++ )
        {
            if( decembre[i] == 1 )
            {
                compteur_jour++;
            }
        }

    }
    // fin de condition pour le mois de février

    switch(mois) /* simplification avec un switch */
    {
        case 3: // si le mois est mars
            for( i = jour ; i < 31 ; i++)
            {
                if( mars[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'avril
            for( i = 0    ; i < 30 ; i++)
            {
                if( avril[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de mai
            for( i = 0    ; i < 31 ; i++ )
            {
                if( mai[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de juin
            for( i = 0    ; i < 30 ; i++)
            {
                if( juin[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de juillet
            for( i = 0    ; i < 31 ; i++ )
            {
                if( juillet[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'aout
            for( i = 0    ; i < 31 ; i++ )
            {
                if( aout[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de septembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( septembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de octobre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( octobre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois dé décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 4: // si le mois est avril
            for( i = jour ; i < 30 ; i++ )
            {
                if( avril[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de mai
            for( i = 0    ; i < 31 ; i++ )
            {
                if( mai[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois juin
            for( i = 0    ; i < 30 ; i++ )
            {
                if( juin[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de juillet
            for( i = 0    ; i < 31 ; i++ )
            {
                if( juillet[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'aout
            for( i = 0    ; i < 31 ; i++ )
            {
                if( aout[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de septembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( septembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'octobre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( octobre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 5: // si le mois est mai
            for( i = jour ; i < 31 ; i++ )
            {
                if( mai[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois juin
            for( i = 0    ; i < 30 ; i++ )
            {
                if( juin[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de juillet
            for( i = 0    ; i < 31 ; i++ )
            {
                if( juillet[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'aout
            for( i = 0    ; i < 31 ; i++ )
            {
                if( aout[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de septembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( septembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'octobre
            for( i = 0    ; i < 31 ; i++ )
            {
                if ( octobre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 6: // si le mois est juin
            for( i = jour ; i < 30 ; i++ )
            {
                if( juin[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de juillet
            for( i = 0    ; i < 31 ; i++ )
            {
                if( juillet[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'aout
            for( i = 0   ; i < 31 ; i++)
            {
                if( aout[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de septembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if ( septembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'octobre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( octobre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 7: // si le mois est juillet
            for( i = jour ; i < 31 ; i++ )
            {
                if( juillet[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'aout
            for( i = 0    ; i < 31 ; i++ )
            {
                if( aout[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de septembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( septembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de decembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 8: // si le mois est aout
            for( i = jour ; i < 31 ; i++ )
            {
                if( aout[i+1] == 1)
                {
                    compteur_jour++;
                }
            }

            // pour le mois de septembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( septembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'octobre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( octobre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 9: // si le mois est septembre
            for( i = jour ; i < 30 ; i++ )
            {
                if( septembre[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois d'octobre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( octobre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 10: // si le mois est octobre
            for ( i = jour ; i < 31 ; i++ )
            {
                if( octobre[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de novembre
            for( i = 0    ; i < 30 ; i++ )
            {
                if( novembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

        case 11: // si le mois est novembre
            for( i = jour ; i < 30 ; i++ )
            {
                if( novembre[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }

            // pour le mois de décembre
            for( i = 0    ; i < 31 ; i++ )
            {
                if( decembre[i] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;
        case 12: // si le mois est decembre
            for( i = jour ; i < 31 ; i++ )
            {
                if( decembre[i+1] == 1 )
                {
                    compteur_jour++;
                }
            }
        break;

    }
    /* Maintenant qu'on à fait pour la première année on peux faire les années suivant */

    //i_ans = annee + 1; // ici c'est pour deuxième année

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


/* La fonction main va prendre un argument dans l'avenir ...*/
int main(int argc, char *argv[])
{
    /*la variable choix va être le choix de quitte le programme ou faire une nouvelle
    conversion , annee pour l'annee de l'utilisateur*/
    int choix = 0, annee = 2019, mois = 11, jour = 20 , anneeEnCour = 2020, moisEnCours = 5, jourEnCours = 6;
    int totalJours = 0;
    /* Ici nous disons une petit message de bienvenue à l'utilisateur,
    on demande l'annee en cours, le mois en cours, et le jours en cour et une PAUSE, on attends que l'utilisateur appuie sur une touche et
    on efface le console puis viens la boucle do */
    printf("Bienvienue sur ce petit programme de convertion d'annee en jours! \n");

 /*   printf("Quel est l'annee en cour : ");
    scanf("%d", &anneeEnCour);
    printf("Quel est le mois en cour : ");
    scanf("%d", &moisEnCours);
    printf("Quel est jour en cour : ");
    scanf("%d", &jourEnCours);

    system("PAUSE");
    system("cls");
*/
    do
    {
        /* Affichage du menu et le choix de l'utilisateur */
        printf("\t\t\t ==== Convertion d'annee ==== \n\n\n");
        printf("\t 1 -> Nouvelle convertion \n");
        printf("\t 2 -> Quitte \n\n\n");
        printf("\tNombre Jour : %d\tDate Actuel : %d-%d-%d\n\n",totalJours, jourEnCours, moisEnCours, anneeEnCour);
        scanf("%d", &choix);
        switch(choix) // Début des condition
        {
            case 1: // si choix vaut 1 -> l'utilisateur veux faire une conversion
            {
                /* Affiche le message Veuillez entree votre annee puis saisi l'annee et
                va dans la fonction convertir_annee */
                /*printf("Veuillez entree votre ANNEE de naissance : ");
                scanf("%d", &annee);
                printf("Veuillez entree MOIS de naissance : ");
                scanf("%d", &mois);
                printf("Veuillez entree votre JOURS de naissance : ");
                scanf("%d", &jour);*/
                /* situé quel est le mois pour le nombre de jour */
                short bissextile = estBissextile(annee);
                totalJours = parcourAnnee(bissextile, annee, mois, jour,  anneeEnCour, moisEnCours, jourEnCours);

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


    return 0;
}
