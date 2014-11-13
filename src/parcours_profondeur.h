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

#ifndef __PARCOURS_PROFONDEUR_H__
#define __PARCOURS_PROFONDEUR_H__

#include "graphes.h"

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

void parcours_profondeur(int * marques, int * visites, graphe graphe_input, int nb_sommet, sommet sommet_depart);
void initialiser_tableau_visites(int * visites, int nb_sommet);
void initialiser_tableau_marque_dfs(int * marques, int nb_sommet);
void marquer_sommet(int * marques, int sommet);
void nouveau_sommet_visite(int * visites, int nb_sommet, int sommet_visite);
void selection_premier_sommet(int * sommet_depart, graphe graphe_ouput, int nb_sommet);
void afficher_tableau_sommet_visite(int * visites, int  nb_sommet);
void lister_voisin(graphe graphe_input, int * voisins, int nb_sommet, sommet sommet_courant);

#endif
