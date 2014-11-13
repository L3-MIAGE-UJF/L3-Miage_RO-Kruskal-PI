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
#include "graphes.h"

/* Fonctions relatives à la création des matrices contenant les graphes */

graphe trouver_arbre_couvrant_poid_min(graphe graphe_origin, int nb_sommet) { // A modifier prend en parametre un graphe et renvoie un graphe int ** & int **

	int nbarrete = 0;
	
	int sommetapm, sommetbpm, poidmin;
	
	/* Definitions des graphes */
	
	int **couvrantmin;

	/* Allocation des zones mémoires aux graphes */
	
	couvrantmin=create_table(nb_sommet);

	initialiser_graphe(couvrantmin, nb_sommet);

	/* Tant que l'on a des arretes dans le graphe d'origine on va tenter de les mettres dans l'arbre couvrant de poid min.
	Nous recherchons l'arrete de poid le plus faible dans le graphe d'origine.
	Puis nous vérifions si nous n'avons pas créé un cycle en faisant ceci.
	Si c'est le cas nous la supprimons. Nous passons alors a la suivante jusqu'à ce qu'il n'y en ai plus dans l'arbre couvrant de poid min.
	*/

	while (nbarrete < nb_sommet-1) {
		// on trouve l'arrete dans le graph de poids min

		poidmin=trouver_arrete_poid_min(graphe_origin, nb_sommet, &sommetapm, &sommetbpm);

		// On la créé dans le graphe de destination puis on la supprime du graphe d'origine
		definir_arrete(couvrantmin, nb_sommet, &sommetapm, &sommetbpm, poidmin);

		definir_arrete(graphe_origin, nb_sommet, &sommetapm, &sommetbpm, COUTMAX);

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

	return couvrantmin;
}

int trouver_arrete_poid_min(int ** graphe, int nb_sommet, int * sommetapm, int * sommetbpm) {
	int poidmin, i, j;
	
	poidmin=COUTMAX;
		
	for (i=0;i<nb_sommet;i++){
		for(j=0;j<nb_sommet;j++){
			if(graphe[i][j]<poidmin){
				poidmin=graphe[i][j];
				*sommetapm=i;
				*sommetbpm=j;
			}
		}
	}
	return poidmin;
}

void definir_arrete(int ** graphe, int nb_sommet, int * sommetapm, int * sommetbpm, int poid) {
	graphe[*sommetapm][*sommetbpm]=poid;
	graphe[*sommetbpm][*sommetapm]=poid;
}

void initialiser_tableau_marque(int * marque, int nb_sommet) {
	int i;

	for (i=0; i < nb_sommet; i++){
		marque[i]=0;
	}
}

int recherche_cycle(int ** graphe, int sommetinit, int nb_sommet) {
	/*
	BFS
	si on trouve un sommet déja marqué qui n'est pas le père de u
	Alors il y a un cycle
	*/
	
	int detection_cycle, taille_file;
	
	int voisin, sommetv, indice, file[nb_sommet], marque[nb_sommet], pere[nb_sommet];
	
	detection_cycle=0;
	taille_file=0;

	initialiser_tableau_marque(marque, nb_sommet);

	// On rajoute le sommet d'init dans la file, on le défini comme son propre père et on commence.
	file[taille_file++]=sommetinit;
	pere[sommetinit]=sommetinit;


	//pere[i]= pere du sommet i
	while (taille_file!=0&&detection_cycle==0) {

		//On selectionne le premier élément dans la file
		sommetv=file[0];
		
		// On décale toute la file d'un cramp a gauche pour conserver le premier element a 0
		for (indice=1;indice<=taille_file; indice++) {
			file[indice-1]=file[indice]; // decalage file on tasse
		}
		
		//On a traité le premier element, on diminue la taille de la file.
		taille_file--;

		marque[sommetv]=1; // on marque le sommet v car on le traite

		// recuperation de la liste des voisins de v
		for(voisin=0;voisin<nb_sommet;voisin++){
			if(voisin!=sommetv) {
				if(graphe[sommetv][voisin]!=COUTMAX) {
					//pour tout voisin de sommetv
					if (marque[voisin]==0) {

						file[taille_file++]=voisin; // ajout du voisin dans la file
						pere[voisin]=sommetv; // definition de sommetv comme étant le père du voisin en cours !						
			
					}
					else {	
						// Si on trouve un voisin deja marque qui n'est pas pere[sommetv] alors on a un cycle
						if(pere[sommetv]!=voisin){
							detection_cycle=1;
						}
					}
				}
			}
		}

	}
	return detection_cycle;
}
