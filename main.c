#include "arbre.h"
#include "liste.h"
#include "outils.h"
#include "pile.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{	
	ArbreABR * arbre = creer_abr();
	NoeudABR * noeud1 = creer_noeud("Hopital");
	NoeudABR * noeud2 = creer_noeud("armoIre");
	NoeudABR * noeud3 = creer_noeud("zoo");
	NoeudABR * noeud4 = creer_noeud("mars");
	NoeudABR * noeud5 = creer_noeud("haricot");
	NoeudABR * noeud6 = creer_noeud("football");

	ajouter_noeud(arbre, noeud1);
	ajouter_noeud(arbre, noeud2);
	ajouter_noeud(arbre, noeud3);
	ajouter_noeud(arbre, noeud4);
	ajouter_noeud(arbre, noeud5);
	ajouter_noeud(arbre, noeud6);

	afficher_arbre(arbre);

	return 0;
}