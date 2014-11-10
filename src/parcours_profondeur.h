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

int * parcours_profondeur(graphe G, int nb_sommet, sommet sommet_depart);
void initialiser_tableau_marque(int * marques, int nb_sommet);
void marquer_sommet(int * marques, int sommet);
void lister_voisin(graphe G, int * voisins, int nb_sommet, sommet sommet_courant);

#endif