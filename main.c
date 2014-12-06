#include "arbre.h"
#include "liste.h"
#include "outils.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{	
	ArbreABR * arbre = creer_abr();
	NoeudABR * noeud1 = creer_noeud("Hopital");
	NoeudABR * noeud2 = creer_noeud("armoIre");
	NoeudABR * noeud3 = creer_noeud("zoo");

	printf("Hello World !\n");

	return 0;
}