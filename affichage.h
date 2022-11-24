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
void typeRoute( CASE** tabCase, int x, int y);
void affichageBattiment(Texture2D Battiment, CASE** tabCase);
void afficherBarreOutils(animationBarre* boiteOutils, int seconde, Texture2D monnaie, Texture2D temps, Texture2D eau, Texture2D elec,
                         Texture2D souris, Texture2D calendrier, int min, int argent, int heure, int mois, int annee, Texture2D moinsAccel, Texture2D plusAccel, Texture2D route, Texture2D maison, Texture2D centrale, Texture2D puit, Texture2D caserne);
void construireBat(int categorieConstruction, int posXMouse, int posYMouse, Texture2D building);
#endif //ECE_CITY_3_Z_AFFICHAGE_H
