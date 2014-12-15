#include "liste.h"
#include "arbre.h"
#include "outils.h"
#include "pile.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{	
	ArbreABR * arbre = creer_abr();

	printf("Nombre de mots lus : %d\n", charger_fichier(arbre, "test.txt"));
	printf("Nombre de noeud l'arbre : %d\n", arbre->nb_mots_differents);
	printf("profondeur de l'arbre : %d\n", profondeur(arbre->racine));
	if(equilibre(arbre->racine))
		printf("L'arbre est équilibré !\n");
	else
		printf("L'arbre n'est pas équilibré ...\n");

	afficher_arbre(arbre);

	NoeudABR * recherche = rechercher_noeud(arbre, "petit");
	if(recherche != NULL)
		printf("On a trouve : %s\n", recherche->mot);
	else
		printf("On a pas trouvé le mot cherché ...\n");


	/*ListePosition * listeP1 = creer_liste_positions();
	ListePosition * listeP2 = creer_liste_positions();
	ListePosition * listeP5 = creer_liste_positions();
	ListePosition * listeP6 = creer_liste_positions();

	ajouter_position(listeP1, 1, 1, 1);
	ajouter_position(listeP2, 1, 2, 1);
	ajouter_position(listeP5, 1, 3, 1);
	ajouter_position(listeP6, 1, 4, 1);

	NoeudABR * noeud1 = creer_noeud("Hopital", listeP1);
	NoeudABR * noeud2 = creer_noeud("armoIre", listeP2);
	// NoeudABR * noeud3 = creer_noeud("zoo", NULL);
	// NoeudABR * noeud4 = creer_noeud("mars", NULL);
	NoeudABR * noeud5 = creer_noeud("haricot", listeP5);
	NoeudABR * noeud6 = creer_noeud("haricot", listeP6);

	ajouter_noeud(arbre, noeud1);
	ajouter_noeud(arbre, noeud2);
	// ajouter_noeud(arbre, noeud3);
	// ajouter_noeud(arbre, noeud4);
	ajouter_noeud(arbre, noeud5);
	ajouter_noeud(arbre, noeud6);

	afficher_arbre(arbre);*/

	return 0;
}