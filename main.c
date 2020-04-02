/* Nom de projet : Years_calculator
   Année : 2020
   Description : Avec cette application sous dos vous
   pouvez savoir le nombre de jour convertie depuis le nombre d'année
   pour par exemple votre date de naissance
   Ecrit : Skywashi
   License : licence libre  */
#include <stdio.h>

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
                va dans la fonction convertir_annee
                printf("Veuillez entree votre annee : ");
                scanf("%d", &annee);


    return 0;
}
