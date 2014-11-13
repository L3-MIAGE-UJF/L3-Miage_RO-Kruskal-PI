/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "fcts_kruskal.h"
#include "parcours_profondeur.h"

void init_alea() {
	srand(time(NULL)); // initialisation de rand
}

int main(int arc, char * arv[]) {

	int nb_sommet=0;
	int * marques;
	int * visites;
	
	sommet sommet_depart;

	graphe graphe_input;
	graphe graphe_output;
	
	init_alea();
	
	// lecture du nombre de sommets
	fscanf(stdin, "%d ", &nb_sommet);

	// allocation mémoire pour le graph et le tableau des sommets marqués 
	graphe_input=create_table(nb_sommet);

	marques=malloc(sizeof(int)*nb_sommet);
	visites=malloc(sizeof(int)*nb_sommet);

	// initialisation à l'infini (COUTMAX) pour chaque sommet du graph ( nécessaire pour l'algo de Kruskal)
	initialiser_graphe(graphe_input, nb_sommet);

	// saisie du graph sous la forme de couples de sommets adjacents associés à un poids.
	saisie_graphe(graphe_input, nb_sommet);

	graphe_output=trouver_arbre_couvrant_poid_min(graphe_input, nb_sommet);

	initialiser_tableau_marque_dfs(marques, nb_sommet);
	initialiser_tableau_visites(visites, nb_sommet);

	selection_premier_sommet(&sommet_depart, graphe_output, nb_sommet);

	parcours_profondeur(marques, visites, graphe_output, nb_sommet, sommet_depart);

//	afficher_graphe(graphe_output, nb_sommet);

	afficher_tableau_sommet_visite(visites, nb_sommet);

	free_table(graphe_input);

	return 0;
}
