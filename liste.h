struct position
{
	int numero_ligne;
	int ordre;
	int numero_phrase;
	struct position * suivant;
};

typedef struct position Position;

struct listePosition
{
	struct position * debut;
	int nb_elements;
};

typedef struct listePosition ListePosition;

ListePosition * creer_liste_positions();

int ajouter_position(ListePosition * listeP, int ligne, int ordre, int num_phrase);