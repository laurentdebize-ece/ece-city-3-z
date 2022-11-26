//
// Created by Théophile Dutrey on 03/11/2022.
//

#ifndef ECE_CITY_3_Z_AFFICHAGE_H
#define ECE_CITY_3_Z_AFFICHAGE_H
enum etat_boite{OUVERT, FERME};
typedef struct {
    enum etat_boite etat;
    int temps;
}animationBarre;
void affichageGrille(VECTEUR mouseIso, Texture2D texture);
void affichageRoute(Texture2D Routes, CASE** tabCase, int niveau);
void affichageTerrain(Texture2D Terrain, CASE** tabCase);
int typeRoute( CASE** tabCase, int x, int y);
void affichageBattiment(Texture2D Battiment, CASE** tabCase);
void enregistrerPartie(CASE** tabCase, int temps);
void recommencerPartie(CASE** tabCase, COMPTEUR* compteur, int* temps, int* cycle);
void initialisationOrdre(CASE** tabCase, int ordre, int x, int y, COMPTEUR* compteur, ECECITY* JEU);
void temps(int* lastT, int* tempsVirtuelle, int* cycle, int accelerateurTemps, int* seconde, int* minute, int* mois, int* annee);
void construireBat(int categorieConstruction, int posXMouse, int posYMouse, Texture2D building);
void tempsJeu(float* lastT, int* tempsVirtuelle, int* cycle, float accelerateurTemps, int* seconde, int* minute, int* mois, int* annee);
#endif //ECE_CITY_3_Z_AFFICHAGE_H
