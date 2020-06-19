#include "collecte_information.h"

void demandeJourActuel(int *pointeurJourActuel)
{
    printf("Quel est le jour en cour : ");
    scanf("%d", pointeurJourActuel);
}

void demandeMoisActuel(int *pointeurMoisEnCour)
{
    printf("Quel est le mois en cour : ");
    scanf("%d", pointeurMoisEnCour);
}

void demandeAnneeActuel(int *pointeurAnneeActuel)
{
    printf("Quel est l'annee en cour : ");
    scanf("%d", &pointeurAnneeActuel);
}

void demandeJourDeNaissance( int *pointeurJour)
{
    printf("Veuillez entree votre JOURS de naissance : ");
    scanf("%d", pointeurJour);
}

void demandeMoisDeNaissance(int *pointeurMois)
{
    printf("Veuillez entree MOIS de naissance : ");
    scanf("%d", pointeurMois);
}

void demandeAnneeDeNaissance(int *pointeurAnnee)
{
    printf("Veuillez entree votre ANNEE de naissance : ");
    scanf("%d", pointeurAnnee);
}
