//
// Created by Ilayda Kocer on 04/11/2022.
//

#ifndef ECE_CITY_3_Z_MENU_H
#define ECE_CITY_3_Z_MENU_H

void choixModeJeu(int* modeActuel, int* mode, float* tempsDepart, int* jeuEnCour);
void affichageMenu(Texture2D fontMenu);
void affichageRegles(Texture2D rules);
void affichageTeam(Texture2D team);
void affichageMode(Texture2D capitaliste, Texture2D communiste);
#include <stdio.h>
#include <time.h>


///Déclaration importantes

enum gameMode {PLAY, RULES, TEAM, MENU, MODE, CAPITALISTE, COMMUNISTE};



#endif //ECE_CITY_3_Z_MENU_H
