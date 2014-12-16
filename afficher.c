void afficher_arbre(ArbreABR * arbre)
{
	//Ici on choisit d'effectuer un parcours de type infixe pour 
	//afficher les mots par ordre alphabétique
	NoeudABR * racine = arbre->racine;
	Pile * p = creer_pile();

	printf("==========================================\n");
	printf("%-10s","Mot");
	printf("%-10s","| Ligne");
	printf("%-10s","| Ordre");
	printf("%-10s","| Numéro phrase |\n");

	while(racine != NULL || pile_vide(p) == 0)
	{
		while(racine != NULL)
		{
			empiler(p,racine);
			racine = racine->filsGauche;
		}

		racine = depiler(p);
		printf("%-10s|", racine->mot);
		afficher_positions(racine->positions);
		printf("\n");
		printf("-------------------------------------------\n");
		racine = racine->filsDroit;
	}
}