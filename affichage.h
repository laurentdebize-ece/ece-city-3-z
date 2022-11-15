//
// Created by Théophile Dutrey on 03/11/2022.
//

#ifndef ECE_CITY_3_Z_AFFICHAGE_H
#define ECE_CITY_3_Z_AFFICHAGE_H
void affichageGrille(VECTEUR mouseIso, Texture2D texture);
void affichageRoute(Texture2D Routes, CASE** tabCase, int niveau);
void affichageTerrain(Texture2D Terrain, CASE** tabCase);
void typeRoute( CASE** tabCase, int x, int y);
void affichageBattiment(Texture2D Battiment, CASE** tabCase);
#endif //ECE_CITY_3_Z_AFFICHAGE_H
