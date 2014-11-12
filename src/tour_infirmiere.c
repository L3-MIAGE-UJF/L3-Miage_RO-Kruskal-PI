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
	sommet sommet_depart;

	graphe graphe_input;
	graphe graphe_output;

	graphe_input=create_table(nb_sommet);

	initialiser_graphe(graphe_input, nb_sommet);

	saisie_graphe(graphe_input, nb_sommet);

	sommet_depart=1;//choisir sommet a

	graphe_output=trouver_arbre_couvrant_poid_min(graphe_input, nb_sommet, sommet_depart);

	//construire tableau L pour qu'il contienne resultat du dfs

	afficher_graphe(graphe_output, nb_sommet);

	free_table(graphe_input);

	return 0;
}
