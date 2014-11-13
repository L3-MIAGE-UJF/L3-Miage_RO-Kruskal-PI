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

#ifndef __FCTS_KRUSKAL_H__
#define __FCTS_KRUSKAL_H__

#include "graphes.h"

graphe trouver_arbre_couvrant_poid_min(graphe graphe_origin, int nb_sommet);
int trouver_arrete_poid_min(int ** graphe, int nb_sommet, int * sommetapm, int * sommetbpm);
void definir_arrete(int ** graphe, int nb_sommet, int * sommetapm, int * sommetbpm, int poid);
void initialiser_tableau_marque(int * marque, int nb_sommet);
int recherche_cycle(int ** graphe, int sommetinit, int nb_sommet);

#endif
