#ifndef ECE_CITY_3_Z_GRAPHE_H
#define ECE_CITY_3_Z_GRAPHE_H


/////////////////////Bibiliotheques////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////Les macros/////////////////////////////



////////////////////// Les enums utilisés///////////////////

//Le .h ou on mettra toutes les fonctions en lien avec le graphe et le déroulement du jeu
enum construction{terrainVague, cabane, maison, immeuble, gratteCiel};
//                   0             1       2      3          4





////////////Fonction pour la creation et la lecturedu graphe////////////////

Graphe* CreerGraphe(int ordre);
Graphe * lire_graphe(char * nomFichier);



#endif //ECE_CITY_3_Z_GRAPHE_H
