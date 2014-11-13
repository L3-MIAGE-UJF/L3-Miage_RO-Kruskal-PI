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

#include "fcts_kruskal.h"

int main(int arc, char * arv[]) {

	int nb_sommet=0;
	int * marques;

	sommet sommet_depart;

	graphe graphe_input;
	graphe graphe_output;

	fscanf(stdin, "%d ", &,n_sommet);

	graphe_input=create_table(nb_sommet);

	marques=malloc(sizeof(int)*nb_sommet);

	initialiser_tableau_marque(marques, nb_sommet);

	initialiser_graphe(graphe_input, nb_sommet);

	saisie_graphe(graphe_input, nb_sommet);

	graphe_output=trouver_arbre_couvrant_poid_min(graphe_input, nb_sommet;

	sommet_depart=1;//choisir sommet a selectionner premier sommet existant

	parcours_profondeur(marques, graphe_input, nb_sommet, sommet_depart)

	afficher_graphe(graphe_output, nb_sommet);


	//afficher marques 


	free_table(graphe_input);

	return 0;
}
