//
// Created by Théophile Dutrey on 03/11/2022.
//

#ifndef ECE_CITY_3_Z_CONSTRUCTION_H
#define ECE_CITY_3_Z_CONSTRUCTION_H
#include "bibliotheque.h"
void route (CASE** tabCase, int x, int y, int* compteur, int detruire);
void habitation (CASE** tabCase, int x, int y, int* compteur, int detruire);
void batiment (CASE** tabCase, int x, int y, int* compteur, int typeBatiment, int roation, int detruire);
int possibiliteDeConstruire(CASE** tabCase, int x, int y, int dimensionX, int dimensionY);
int presenceRoute(CASE** tabCase, int x, int y, int dimensionX, int dimensionY);
void routeApercu (CASE** tabCase, int x, int y);
void habitationApercu (CASE** tabCase, int x, int y);
void batimentApercu(CASE** tabCase, int x, int y, int typeBatiment);
void constructionSouris(VECTEUR* mouseIso, int categorieConstruction, int* niveau, CASE** tabCase, int* CompteEnBanque, COMPTEUR* compteur, int rotationBattiment, int detruire);
void detruireConstruction(VECTEUR* mouseIso, CASE** tabCase, COMPTEUR* compteur, int rotationBattiment, int detruire);
void compteurTempsDuBat (CASE** tabCase, int x, int y, float* tempsEcoule) ;
void evolutionBat (CASE** tabCase, float* tempsEcoule, ECECITY* JEU) ;
#endif //ECE_CITY_3_Z_CONSTRUCTION_H
