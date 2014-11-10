void afficher_graphe(int ** graphe, int nb_sommet);
void initialiser_graphe(int ** graphe, int nb_sommet);
void saisie_graphe(int ** graphe, int nb_sommet);
int trouver_arrete_poid_min(int ** graphe, int nb_sommet, int * sommetapm, int * sommetbpm);
void definir_arrete(int ** graphe, int nb_sommet, int * sommetapm, int * sommetbpm, int poid);
void initialiser_tableau_marque(int * marque, int nb_sommet);
int recherche_cycle(int ** graphe, int sommetinit, int nb_sommet);
int **create_table(int nb_sommet);
void free_table(int **table);
