/* Nom de projet : Years_calculator
   Année : 2020
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
    int nombrejour = 0;

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

void moisJanvier(int *janvier, short premier, int annee_maintenant)
{ }

void parcourMois(int *janvier, int *fevrier, int *mars)
{

    printf("fonction parcoursMois");
}

/* Cette fonction prends comme paramètre l'année de l'utilsateur et si il est bissextile ou pas,
   le mois et le jour de la personne ET aussi l'année, le mois, jour d'aujourd'hui */
void parcourAnnee(short bissextile, int annee,            int mois,            int jour,
                                    int annee_maintenant, int mois_maintenant, int jour_maintenant)
{
    short janvier[31] = {1}, fevrier[29] = {0}, mars[31] = {1}, avril[30] = {1}, mai[31] = {1};
    short juin[30] = {1}, juillet[31] = {1}, aout[31] = {1}, septembre[30] = {1}, octobre[31] = {1};
    short novembre[30] = {1}, decembre[31] = {1};

    int compteur_jour = 0, i_mois = 0, i_ans = 0;

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
        // cette boucle concerne le le mois de février
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
                compteur_jour++:
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
                    compteur_jour++:
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

        case 4:
        break;

        case 5:
        break;

        case 6:
        break;

        case 7:
        break;

        case 8:
        break;

        case 9:
        break;

        case 10:
        break;

        case 11:
        break;

        case 12:
        break;

    }

}



/* La fonction main va prendre un argument dans l'avenir ...*/
int main(int argc, char *argv[])
{
    /*la variable choix va être le choix de quitte le programme ou faire une nouvelle
    conversion , annee pour l'annee de l'utilisateur*/
    int choix = 0, annee = 0, mois = 0, jour = 0 , anneeEnCour = 0, moisEnCours = 0, jourEnCours = 0;
    int totalJours = 0;
    /* Ici nous disons une petit message de bienvenue à l'utilisateur,
    on demande l'annee en cours, le mois en cours, et le jours en cour et une PAUSE, on attends que l'utilisateur appuie sur une touche et
    on efface le console puis viens la boucle do */
    printf("Bienvienue sur ce petit programme de convertion d'annee en jours! \n");

    printf("Quel est l'annee en cour : ");
    scanf("%d", &anneeEnCour);
    printf("Quel est le mois en cour : ");
    scanf("%d", &moisEnCours);
    printf("Quel est jour en cour : ");
    scanf("%d", &jourEnCours);

    system("PAUSE");
    system("cls");

    do
    {
        /* Affichage du menu et le choix de l'utilisateur */
        printf("\t\t\t ==== Convertion d'annee ==== \n\n\n");
        printf("\t 1 -> Nouvelle convertion \n");
        printf("\t 2 -> Quitte \n\n\n");
        printf("\t\t Date Actuel : %d-%d-%d\n\n",jourEnCours, moisEnCours, anneeEnCour);
        scanf("%d", &choix);
        switch(choix) // Début des condition
        {
            case 1: // si choix vaut 1 -> l'utilisateur veux faire une conversion
            {
                /* Affiche le message Veuillez entree votre annee puis saisi l'annee et
                va dans la fonction convertir_annee */
                printf("Veuillez entree votre annee de naissance : ");
                scanf("%d", &annee);
                printf("Veuillez entree mois de naissance : ");
                scanf("%d", &mois);
                printf("Veuillez entree votre jours de naissance : ");
                scanf("%d", &jour);
                /* situé quel est le mois pour le nombre de jour */
                short bissextile = estBissextile(annee);
                parcourAnnee(bissextile, annee, mois, jour,  anneeEnCour, moisEnCours, jourEnCours);

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
