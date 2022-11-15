//
// Created by Théophile Dutrey on 03/11/2022.
//

#ifndef ECE_CITY_3_Z_CONSTRUCTION_H
#define ECE_CITY_3_Z_CONSTRUCTION_H
#include "bibliotheque.h"
void route (CASE** tabCase, int x, int y, int* compteur);
void habitation (CASE** tabCase, int x, int y, int* compteur);
void batiment (CASE** tabCase, int x, int y, int* compteur, int typeBatiment);
int possibiliteDeConstruire(CASE** tabCase, int x, int y, int dimensionX, int dimensionY);
int presenceRoute(CASE** tabCase, int x, int y, int dimensionX, int dimensionY);
void routeApercu (CASE** tabCase, int x, int y);
void habitationApercu (CASE** tabCase, int x, int y);
void batimentApercu(CASE** tabCase, int x, int y, int typeBatiment);
#endif //ECE_CITY_3_Z_CONSTRUCTION_H
