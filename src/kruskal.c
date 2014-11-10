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

#include "kruskal.h"
#include "fcts_kruskal.h"

/* Corps du programme */

// Fonctionne pour un graphe ayant plusieurs composantes non connexes entre elles, mais les sommets isolés ne seront pas recopiés.

int main(int argc, char* argv[]) {
	
	int nb_sommet;

	int nbarrete = 0;
	
	int sommetapm, sommetbpm, poidmin;
	
	/* Definitions des graphes */
	
	int **graphe, **couvrantmin;

	fprintf(stdout, "Implantation de l'Algorithme de Kruskal \n");
    
	fscanf(stdin, " %d", &nb_sommet);

	/* Allocation des zones mémoires aux graphes */
	
	graphe=create_table(nb_sommet);
	couvrantmin=create_table(nb_sommet);

	initialiser_graphe(graphe, nb_sommet);
	initialiser_graphe(couvrantmin, nb_sommet);
	
	/* Saisie du graphe */
	
	saisie_graphe(graphe, nb_sommet);

	/* Tant que l'on a des arretes dans le graphe d'origine on va tenter de les mettres dans l'arbre couvrant de poid min.
	Nous recherchons l'arrete de poid le plus faible dans le graphe d'origine.
	Puis nous vérifions si nous n'avons pas créé un cycle en faisant ceci.
	Si c'est le cas nous la supprimons. Nous passons alors a la suivante jusqu'à ce qu'il n'y en ai plus dans l'arbre couvrant de poid min.
	*/

	while (nbarrete < nb_sommet-1) {

		// on trouve l'arrete dans le graph de poids min

		poidmin=trouver_arrete_poid_min(graphe, nb_sommet, &sommetapm, &sommetbpm);
	
		// On la créé dans le graphe de destination puis on la supprime du graphe d'origine
		definir_arrete(couvrantmin, nb_sommet, &sommetapm, &sommetbpm, poidmin);
		
		definir_arrete(graphe, nb_sommet, &sommetapm, &sommetbpm, COUTMAX);

		// Recherche d'un cycle dans couvrantmin

		if (recherche_cycle(couvrantmin, sommetapm, nb_sommet)) {
			// Si on détecte un cyle on enleve l'arete que l'on vient de rajouter
			definir_arrete(couvrantmin, nb_sommet, &sommetapm, &sommetbpm, COUTMAX);
		}
		else {
			// Sinon on garde l'arrete et on va passer a la suivante si elle existe
			nbarrete++;
		}
	}

	afficher_graphe(couvrantmin, nb_sommet);
	
	free_table(graphe);
	free_table(couvrantmin);
	
	return 0;
}
