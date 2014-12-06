struct noeudABR
{
	char * mot;
	struct listePosition * positions;
	struct noeudABR * filsGauche;
	struct noeudABR * filsDroit;
};

typedef struct noeudABR NoeudABR;

struct arbreABR
{
	struct noeudABR * racine;
	int nb_mots_differents;
	int nb_mots_total;
};

typedef struct arbreABR ArbreABR;

ArbreABR * creer_abr();

NoeudABR * creer_noeud();

int ajouter_noeud(ArbreABR * arbre, NoeudABR * noeud);

int charger_fichier(ArbreABR * arbre, char * filename);

NoeudABR * rechercher_noeud(ArbreABR * arbre, char * mot);

void afficher_arbre(ArbreABR * arbre);

