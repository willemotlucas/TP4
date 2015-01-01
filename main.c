#include "liste.h"
#include "arbre.h"
#include "outils.h"
#include "pile.h"

#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MOT 25

int main()
{	
	int choix = -1;

	char * filename = "test.txt";
	int fichier_charge = 0;

	char mot_a_chercher1[TAILLE_MOT];
	char mot_a_chercher2[TAILLE_MOT];
	char mot_a_chercher3[TAILLE_MOT];

	NoeudABR * noeud_trouve = NULL;
	ArbreABR * arbre = NULL;
	

	system("clear");

	do
	{
		printf("\n\n");

		printf("======= MENU PRINCIPAL =======\n");
		printf("1. Créer un ABR\n");
		printf("2. Charger un fichier\n");
		printf("3. Caractéristique de l'ABR\n");
		printf("4. Afficher les mots\n");
		printf("5. Rechercher un mot\n");
		printf("6. Rechercher une phrase contenant 2 mots\n");
		printf("7. Quitter\n\n");
		printf("Votre choix : ");
		scanf("%d", &choix);

		printf("\n\n");

		switch(choix)
		{
			case 1: 
			arbre = creer_abr();
			if(arbre != NULL)
				printf("Arbre créé avec succès.");
			else
				printf("Echec lors de la création de l'arbre.");
			break;

			case 2:
			if(arbre != NULL)
			{
				fichier_charge = 1;
				printf("Le fichier a été chargé avec succès.\n %d mots on été lus.\n", charger_fichier(arbre, filename));
			}
			else
				printf("Vous devez d'abord créer l'ABR.\n");
			break;

			case 3:
			if(arbre != NULL && fichier_charge == 1)
			{
				printf("L'arbre contient %d noeuds.\n", arbre->nb_mots_differents);
				printf("L'arbre a une hauteur de %d\n", profondeur(arbre->racine));
				
				if(equilibre(arbre->racine))
					printf("L'arbre est équilibré.");
				else
					printf("L'arbre n'est pas équilibré.");
			}
			else
				printf("Vous devez d'abord créer l'ABR et charger le fichier.\n");
			break;

			case 4:
			if(arbre != NULL && fichier_charge == 1)
			{
				afficher_arbre(arbre);
			}
			else
				printf("Vous devez d'abord créer l'ABR et charger le fichier.\n");
			break;

			case 5:
			if(arbre != NULL && fichier_charge == 1)
			{
				printf("Entrez le mot à chercher : ");
				scanf("%s", mot_a_chercher1);
				printf("Le mot à chercher est : \"%s\"\n", mot_a_chercher1);
				noeud_trouve = rechercher_noeud(arbre, mot_a_chercher1);
				if(noeud_trouve != NULL)
				{
					printf("============================================\n");
					printf("%-10s","Mot");
					printf("%-10s","| Ligne");
					printf("%-10s","| Ordre");
					printf("%-10s","| Num. phrase |\n");
					printf("============================================\n");
					printf("%-10s|", noeud_trouve->mot);
					afficher_positions(noeud_trouve->positions);
					printf("\n============================================\n");
				}
				else
					printf("Le mot \"%s\" n'est pas dans le texte.", mot_a_chercher1);
			}
			else
				printf("Vous devez d'abord créer l'ABR et charger le fichier.\n");
			break;

			case 6:
				printf("Entrez le premier mot à chercher : ");
				scanf("%s", mot_a_chercher2);
				printf("Entrez le deuxième mot à chercher : ");
				scanf("%s", mot_a_chercher3);
				printf("On cherche les phrases contenant \"%s\" et \"%s\"\n\n", mot_a_chercher2, mot_a_chercher3);
				afficher_phrases(filename, mot_a_chercher2, mot_a_chercher3);
			break;

			case 7:
			if(arbre != NULL)
			{
				int * noeud_liberes = 0;
				liberer_memoire(arbre->racine);
				free(arbre);
			}
		}
	}while(choix != 7);



	/*ArbreABR * arbre = creer_abr();

	printf("Nombre de mots lus : %d\n", charger_fichier(arbre, "test.txt"));
	printf("Nombre de noeud l'arbre : %d\n", arbre->nb_mots_differents);
	printf("profondeur de l'arbre : %d\n", profondeur(arbre->racine));
	
	if(equilibre(arbre->racine))
		printf("L'arbre est équilibré !\n");
	else
		printf("L'arbre n'est pas équilibré ...\n");

	afficher_arbre(arbre);

	char * mot_cherche = "toit";

	NoeudABR * recherche = rechercher_noeud(arbre, mot_cherche);
	printf("On cherche le mot \"%s\"\n", mot_cherche);
	if(recherche != NULL)
		printf("On a trouve : %s\n", recherche->mot);
	else
		printf("On a pas trouvé le mot cherché ...\n");


	/*ListePosition * listeP1 = creer_liste_positions();
	ListePosition * listeP2 = creer_liste_positions();
	ListePosition * listeP5 = creer_liste_positions();
	ListePosition * listeP6 = creer_liste_positions();

	ajouter_position(listeP1, 1, 1, 1);
	ajouter_position(listeP2, 1, 2, 1);
	ajouter_position(listeP5, 1, 3, 1);
	ajouter_position(listeP6, 1, 4, 1);

	NoeudABR * noeud1 = creer_noeud("Hopital", listeP1);
	NoeudABR * noeud2 = creer_noeud("armoIre", listeP2);
	// NoeudABR * noeud3 = creer_noeud("zoo", NULL);
	// NoeudABR * noeud4 = creer_noeud("mars", NULL);
	NoeudABR * noeud5 = creer_noeud("haricot", listeP5);
	NoeudABR * noeud6 = creer_noeud("haricot", listeP6);

	ajouter_noeud(arbre, noeud1);
	ajouter_noeud(arbre, noeud2);
	// ajouter_noeud(arbre, noeud3);
	// ajouter_noeud(arbre, noeud4);
	ajouter_noeud(arbre, noeud5);
	ajouter_noeud(arbre, noeud6);

	afficher_arbre(arbre);*/

	return 0;
}