//
// Created by Théophile Dutrey on 03/11/2022.
//

#ifndef ECE_CITY_3_Z_AFFICHAGE_H
#define ECE_CITY_3_Z_AFFICHAGE_H
void affichageGrille(VECTEUR mouseIso, Texture2D texture);
void affichageRoute(Texture2D Routes, CASE** tabCase, int niveau);
void affichageTerrain(Texture2D Terrain, CASE** tabCase);
int typeRoute( CASE** tabCase, int x, int y);
void affichageBattiment(Texture2D Battiment, CASE** tabCase);
void enregistrerPartie(CASE** tabCase);
void recommencerPartie(CASE** tabCase, COMPTEUR* compteur);
void initialisationOrdre(CASE** tabCase, int ordre, int x, int y, COMPTEUR* compteur);

#endif //ECE_CITY_3_Z_AFFICHAGE_H
