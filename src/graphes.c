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

#include "graphes.h"

void afficher_graphe(int ** graphe, int nb_sommet) {
	int i, j;

	printf("   ");
	for (i=0;i<nb_sommet;i++) {
		printf("%d |", i);
	}
	printf("\n");
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

	/*
	 * A modifier selon le type de fichier fourni par le prof, si il veut bien nous en fournir un en guise d'exemple
	 */

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
