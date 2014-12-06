#include "arbre.h"

#include <stdio.h>
#include <stdlib.h>

ArbreABR * creer_abr()
{
	ArbreABR * abr = malloc(sizeof(ArbreABR));
	
	if(abr != NULL)
	{
		abr->racine = NULL;
		abr->nb_mots_differents = 0;
		abr->nb_mots_total = 0;
	}

	return abr;
}
