struct element
{
	struct noeudABR * donnee;
	struct element * suivant;
};

typedef struct element Element;

struct pile
{
	struct element * sommet;
	int taille;
};

typedef struct pile Pile;

Pile * creer_pile();

Element * creer_element(NoeudABR * noeud);

int pile_vide(Pile * p);

NoeudABR * depiler(Pile * p);

void empiler(Pile * p, NoeudABR * noeud);