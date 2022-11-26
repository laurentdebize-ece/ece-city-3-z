//
// Created by Théophile Dutrey on 03/11/2022.
//

#ifndef ECE_CITY_3_Z_CONSTRUCTION_H
#define ECE_CITY_3_Z_CONSTRUCTION_H
#include "bibliotheque.h"
void route (CASE** tabCase, int x, int y, int* compteur, int detruire,ECECITY *JEU);
void habitation (CASE** tabCase, int x, int y, int* compteur, int detruire,ECECITY *JEU);
void batiment (CASE** tabCase, int x, int y, int* compteur, int typeBatiment, int roation, int detruire,ECECITY *JEU);
int possibiliteDeConstruire(CASE** tabCase, int x, int y, int dimensionX, int dimensionY);
int presenceRoute(CASE** tabCase, int x, int y, int dimensionX, int dimensionY);
void routeApercu (CASE** tabCase, int x, int y);
void habitationApercu (CASE** tabCase, int x, int y);
void batimentApercu(CASE** tabCase, int x, int y, int typeBatiment);
void constructionSouris(VECTEUR* mouseIso, int categorieConstruction, int* niveau, CASE** tabCase, int* CompteEnBanque, COMPTEUR* compteur, int rotationBattiment, int detruire,ECECITY *JEU);
void detruireConstruction(VECTEUR* mouseIso, CASE** tabCase, COMPTEUR* compteur, int rotationBattiment, int detruire,ECECITY *JEU);
void compteurTempsDuBat (CASE** tabCase, int x, int y, float* tempsEcoule) ;
void evolutionBat (CASE** tabCase, float* tempsEcoule, ECECITY* JEU,  int* cycle) ;
void demolitionBatCapitaliste (CASE** tabCase, float* tempsEcoule, ECECITY* JEU, int compteEnBanque);

#endif //ECE_CITY_3_Z_CONSTRUCTION_H
