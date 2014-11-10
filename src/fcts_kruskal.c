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

/* Fonctions relatives à la création des matrices contenant les graphes */


void afficher_graphe(int ** graphe, int nb_sommet) {
	int i, j;
	printf("\n Arbre couvrant de poid minimum : \n\n");
	printf("   0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |\n");
	for (i=0;i<nb_sommet;i++) {
		printf("%d |", i);
		for (j=0;j<nb_sommet;j++) {
			if (graphe[i][j]!=COUTMAX) {
				printf("%d |", graphe[i][j]);			
			}
			else {
				printf("_ |");
			}
		}
		printf("\n");
	}
}

void initialiser_graphe(int ** graphe, int nb_sommet) {
	int i,j;
	for (i=0;i<nb_sommet;i++) {
		for (j=0;j<nb_sommet;j++) {
			graphe[i][j]=COUTMAX;
		}
	}
}

void saisie_graphe(int ** graphe, int nb_sommet) {
	/* La saisie se termine quand le caractere q est saisi, le caractere c ou n'importe quel autre caractere permet de continuer la saisie */
	int sommeta, sommetb, poidab;
	char action;
	
	fscanf(stdin, " %c", &action);
	
	while (action!='q') {
		fscanf(stdin, " %d %d %d", &sommeta, &sommetb, &poidab);
		
		if (((sommeta>=0)&&(sommeta<nb_sommet))&&((sommetb>=0)&&(sommetb<nb_sommet))&&((poidab<COUTMAX)&&((poidab>0)))) {
			graphe[sommeta][sommetb]=poidab;
			graphe[sommetb][sommeta]=poidab;
		}
		else {
			printf("Erreur de saisie \n");
		}
		
		fscanf(stdin, " %c", &action);
	}
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

/* Creation et suppression des tables */

int **create_table(int nb_sommet) {
	int **table;
	int i;
	table = (int **)malloc(sizeof(int *) * nb_sommet);
	for (i=0;i<nb_sommet;i++) {
		table[i]= (int *)malloc(sizeof(int) * nb_sommet);
	}
	return table;
}

void free_table(int **table) {
	free(table);
}
