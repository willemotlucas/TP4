#include "liste.h"
#include "arbre.h"
#include "outils.h"
#include "pile.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{	
	ArbreABR * arbre = creer_abr();

	printf("Nombre de mot du fichier : %d\n", charger_fichier(arbre, "test.txt"));
	afficher_arbre(arbre);

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