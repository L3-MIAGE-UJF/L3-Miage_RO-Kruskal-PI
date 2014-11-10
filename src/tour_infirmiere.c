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

	int **create_table(int nb_sommet);

	void initialiser_graphe(int ** graphe, int nb_sommet);

	void saisie_graphe(int ** graphe, int nb_sommet);

	//choisir sommet a

	int ** trouver_arbre_couvrant_poid_min(int **graphe, int nb_sommet);

	//construire tableau L pour qu'il contienne resultat du dfs

	void afficher_graphe(int ** graphe, int nb_sommet);

	void free_table(int **table);

	return 0;
}