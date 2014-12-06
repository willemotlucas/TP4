#include "outils.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * formatage_mot(char * chaine)
{
	char * copy = malloc(strlen(chaine)+1 * sizeof(char));

	if(copy != NULL)
	{
		int i;
		strcpy(copy,chaine);

		for(i = 0; i < strlen(chaine); i++)
		{
			copy[i] = tolower(chaine[i]);
		}

		return copy;
	}

	free(copy);
	return NULL;		
}