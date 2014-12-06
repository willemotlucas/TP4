#include "liste.h"

ListePosition * creer_liste_positions()
{
	ListePosition * listeP = malloc(sizeof(ListePosition));

	if(listeP != NULL)
	{
		listeP->debut = NULL;
		int nb_elements = 0;
	}

	return listeP;
}