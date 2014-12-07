#include "arbre.h"
#include "pile.h"

#include <stdio.h>
#include <stdlib.h>

Pile * creer_pile()
{
	Pile * pile = malloc(sizeof(pile));

	if(pile != NULL)
	{
		pile->sommet = NULL;
		pile->taille = 0;
		
		return pile;
	}

	return NULL;
}

Element * creer_element(NoeudABR * noeud)
{
	Element * element = malloc(sizeof(Element));

	if(element != NULL)
	{
		element->donnee = noeud;
		element->suivant = NULL;
		
		return element;
	}

	return NULL;
}

int pile_vide(Pile * p)
{
	if(p->taille == 0)
		return 1;
	else
		return 0;
}

NoeudABR * depiler(Pile * p)
{
	if(pile_vide(p))
		return NULL;

	else
	{
		NoeudABR * a_suppr = p->sommet->donnee;
		p->sommet = p->sommet->suivant;
		p->taille--;
		
		return a_suppr;
	}
}

void empiler(Pile * p, NoeudABR * n)
{
	if(pile_vide(p))
	{
		p->sommet = creer_element(n);
		p->sommet->suivant = NULL;
		p->taille++;
	}

	else
	{
		Element * e = creer_element(n);
		e->suivant = p->sommet;
		p->sommet = e;
		p->taille++;
	}
}
