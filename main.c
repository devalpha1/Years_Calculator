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
   License : licence libre  */


#include <stdio.h>
#include <stdlib.h>

/* Retourne valeur de type int  et prends 2
Paramètre de type int */
int convertir_annee(int anne_a_convertir, int anneeEnCours)
{
    int quatre =  anne_a_convertir / 4, cent = anne_a_convertir / 100;
    int divisible4 = 0, divisible100 = 0;
    int nombrejour = 0;

    printf("Quatre : %ld -- Cent : %ld\n\n", quatre, cent);
    /* Après cette ligne on voit si il est divisible ou pas */
    /* on le fait dans le sens inverse */
    divisible4 = 4 * quatre; divisible100 = 100 * cent;

    /* si divisible par 100 donc pas bissextile !!!
       ex : pour 2000 non car 20 * 100 = 2000 mais par 4 c'est correct !!*/
    if ( divisible100 == anne_a_convertir ) { printf("Est pas bissextile !!!\n\n"); return 0; }
    else
    {
        printf("Est bissextile !\n\n");
    }
    return 0;
}

/* La fonction main va prendre un argument dans l'avenir ...*/
int main(int argc, char *argv[])
{
    /*la variable choix va être le choix de quitte le programme ou faire une nouvelle
    conversion , annee pour l'annee de l'utilisateur*/
    short choix = 0, annee = 0, anneeEnCour = 0;
    /* Ici nous disons une petit message de bienvenue à l'utilisateur,
    puis on demande l'annee en cours et une PAUSE, on attends que l'utilisateur appuie sur une touche et
    on efface le console puis viens la boucle do */
    printf("Bienvienue sur ce petit programme de convertion d'annee en jours! \n");
    printf("Quel est l'annee en cour : ");
    scanf("%d", &anneeEnCour);
    system("PAUSE");
    system("cls");

    do
    {
        /* Affichage du menu et le choix de l'utilisateur */
        printf("\t\t\t ==== Convertion d'annee ==== \n\n\n");
        printf("\t 1 -> Nouvelle convertion \n");
        printf("\t 2 -> Quitte \n");
        printf("\t\t Annee Actuel : %d\n\n", anneeEnCour);
        scanf("%d", &choix);

        switch(choix) // Début des condition
        {
            case 1: // si choix vaut 1
            {
                /* Affiche le message Veuillez entree votre annee puis saisi l'annee et
                va dans la fonction convertir_annee */
                printf("Veuillez entree votre annee de naissance : ");
                scanf("%d", &annee);

                convertir_annee(annee, anneeEnCour);
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
