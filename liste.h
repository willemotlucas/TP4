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

Position * init_position(int ligne, int ordre, int num_phrase);

int ajouter_position(ListePosition * listeP, int ligne, int ordre, int num_phrase);

void afficher_position(ListePosition * listeP);

/*
 * MEMO du fonctionnement de la lecture d'un fichier
 * 
 * On lit les mots un par un. Pour chaque mot, on créé une liste de positions initialisée
 * avec la position actuelle du curseur. Puis on créé un nouveau
 * noeud contenant le mot, et la liste de positions associée, qui ne contient
 * donc qu'une seule position. Ensuite, on ajoute le noeud dans l'arbre.
 * Si le mot existe déjà, on va simplement mettre à jour la liste de positions
 * du noeud déjà existant dans l'arbre en ajoutant la seule position contenu dans la
 * liste position du noeud à ajouter (donc passé en parametre)
 */