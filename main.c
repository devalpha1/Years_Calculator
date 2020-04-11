/* Nom de projet : Years_calculator
   Année : 2020
   Description : Avec cette application sous console vous
   pouvez savoir le nombre de jour convertie depuis le nombre d'année
   pour par exemple votre date de naissance.
   Pour savoir si une annee est bissextille on utilise la condition si il est
   divisible par 4 et non divisible par 100. (rf.wikipedia)
   Exemple 4 : divisible par 4 : 4, 8, 12, 16, 20, 24 , 28, etc...
   Exemple : divisible par 100 : x00 et pas divisible : différent de x00 ->
   99 pas divisible par 100 !!!
   Ecrit : Skywashi
   License : licence libre  */


#include <stdio.h>

/* Retourne valeur de type int  et prends
Paramètre de type int */
int convertir_annee(int anne_a_convertir)
{
    int quatre = anne_a_convertir % 4, cent = anne_a_convertir % 100;
    short bissextile = 0; // 0 est pas bissextile 1 et bissextile
    short quotient =  ( anne_a_convertir / 100 ), division = anne_a_convertir / 100;

    printf("\quatre : %d \t\t cent = %d \t\t quotient : %d\n\n", quatre, cent, quotient );
    printf(" 100 + %d / 100 = %d\n\n", anne_a_convertir, division);

    if ( cent + ( anne_a_convertir / 100 ) == anne_a_convertir )
    {
        printf("Divisible car %d // 100 = %d + %d\n\n **** Donc non bissextile ****", anne_a_convertir, quotient, cent);
    }

    return 0;
}

/* La fonction main va prendre un argument dans l'avenir ...*/
int main(int argc, char argv[])
{
    /*la variable choix va être le choix de quitte le programme ou faire une nouvelle
    conversion , annee pour l'annee de l'utilisateur*/
    short choix = 0, annee = 0;
    /* Ici nous disons une petit message de bienvenue à l'utilisateur,
    puis une PAUSE, on attends que l'utilisateur appuie sur une touche et
    on efface le console puis viens la boucle do */
    printf("Bienvienue sur ce petit programme de convertion d'annee en jours! \n");
    system("PAUSE");
    system("cls");

    do
    {
        /* Affichage du menu et le choix de l'utilisateur */
        printf("\t\t\t ==== Convertion d'annee ==== \n\n\n");
        printf("\t 1 -> Nouvelle convertion \n");
        printf("\t 2 -> Quitte \n");
        scanf("%d", &choix);

        switch(choix) // Début des condition
        {
            case 1: // si choix vaut 1
            {
                /* Affiche le message Veuillez entree votre annee puis saisi l'annee et
                va dans la fonction convertir_annee */
                printf("Veuillez entree votre annee : ");
                scanf("%d", &annee);
                convertir_annee(annee);
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
