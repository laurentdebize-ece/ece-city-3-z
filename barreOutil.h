//
// Created by Théophile Dutrey on 25/11/2022.
//

#ifndef ECE_CITY_3_Z_BARREOUTIL_H
#define ECE_CITY_3_Z_BARREOUTIL_H
void barreOutilSouris(int PosXMouse, int PosYMouse,  animationBarre* barre, int* categorieConstruction);
void afficherBarreOutils(animationBarre* boiteOutils, int seconde, Texture2D monnaie, Texture2D temps, Texture2D eau, Texture2D elec,
                         Texture2D souris, Texture2D calendrier, int min, int argent, int heure, int mois, int annee, Texture2D moinsAccel,
                         Texture2D plusAccel, Texture2D route, Texture2D maison, Texture2D centrale, Texture2D puit, Texture2D caserne,
                         Texture2D rotation, Texture2D enregistrer, Texture2D demolition, int construire, int detruire, Texture2D cosntruireOn,
                         Texture2D cosntruireOff, Texture2D demolitionOff, Texture2D plage, Texture2D plage2);
#endif //ECE_CITY_3_Z_BARREOUTIL_H
