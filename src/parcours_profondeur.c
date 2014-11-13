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

void parcours_profondeur(int * marques, int * visites, graphe graphe_input, int nb_sommet, sommet sommet_depart) {
  int voisins[nb_sommet];
printf("hah\n");
  int indice;

  for(indice=0;indice<nb_sommet;indice++) {
  	voisins[indice]=-1;
  }

printf("bbb\n");

  marquer_sommet(marques, sommet_depart);
  
  printf("aaa\n");
  
  nouveau_sommet_visite(visites, nb_sommet, sommet_depart);
  
printf("ccc\n");

afficher_tableau_sommet_visite(visites, nb_sommet);

printf("ddd\n");

  lister_voisin(graphe_input, voisins, nb_sommet, sommet_depart);
  
  printf("eee\n");
  
  for (indice=0; indice < nb_sommet; indice++) {
	if (voisins[indice]==1&&marques[indice]==0) { // pas marque
		parcours_profondeur(marques, visites, graphe_input, nb_sommet, indice); // transmettre sommet marque ? ajout tableau retourne au courant
	}
  }
}

void initialiser_tableau_visites(int * visites, int nb_sommet) {
	int indice;
	for (indice = 0; indice < nb_sommet; indice++)
	{
		visites[indice]=-1;
	}
}

void initialiser_tableau_marque_dfs(int * marques, int nb_sommet) {
	int indice;
	for (indice = 0; indice < nb_sommet; indice++)
	{
		marques[indice]='0';
	}
}

void marquer_sommet(int * marques, int sommet) {
	marques[sommet]=1;
}

void nouveau_sommet_visite(int * visites, int nb_sommet, int sommet_visite) {
	int indice;
	while(indice<nb_sommet && visites[indice++]!=-1);
	if (indice<nb_sommet) { visites[indice]=sommet_visite; }
}

void selection_premier_sommet(int * sommet_depart, graphe graphe_ouput, int nb_sommet) {
	*sommet_depart=rand()%nb_sommet+1;
}

void afficher_tableau_sommet_visite(int * visites, int  nb_sommet) {
	int indice=0;
	fprintf(stdout,"\n Affichage des sommets a parcourir dans l'ordre \n");
	while(indice<nb_sommet&& visites[indice++]!=-1) {
		fprintf(stdout,"-> %d ", visites[indice]);
	}
	fprintf(stdout,"\n");
}

void lister_voisin(graphe graphe_input, int * voisins, int nb_sommet, sommet sommet_courant) {
	int indice;
	for (indice=0;indice<nb_sommet;indice++) {
		if(sommet_courant!=indice && graphe_input[sommet_courant][indice]==1) {
			voisins[indice]=1;
		}
	}
}
