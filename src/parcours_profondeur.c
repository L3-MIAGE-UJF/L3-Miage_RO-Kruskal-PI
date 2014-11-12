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

#include "parcours_profondeur.h"

int * parcours_profondeur(graphe G, int nb_sommet, sommet sommet_depart) {
  int voisins[nb_sommet];
  int marques[nb_sommet];

  int indice;

  for(indice=0;indice<nb_sommet;indice++) {
  	voisins[indice]=-1;
  }

  marquer_sommet(sommet_depart);
  
  lister_voisin(G, voisins, nb_sommet, sommet_depart)
  
  for (indice=0; indice < nb_sommet; indice++) {
  	if (voisins[indice]==1&&marques[indice]==1) { // pas marque
  		parcours_profondeur(G, nb_sommet, indice); // transmettre sommet marque ? ajout tableau retourne au courant
  	}
  }
  return
}

void initialiser_tableau_marque(int * marques, int nb_sommet) {
	int indice;
	for (indice = 0; indice < nb_sommet; indice++)
	{
		marques[indice]='0';
	}
}

void marquer_sommet(int * marques, int sommet) {
	marques[sommet]=1;
}

void lister_voisin(graphe G, int * voisins, int nb_sommet, sommet sommet_courant) {
	int indice;
	for (indice=0;indice<nb_sommet;indice++) {
		if(sommet_courant!=indice&&graphe[sommet_courant]==1) {
			voisins[indice]=1;
		}
	}
}