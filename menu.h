//
// Created by Ilayda Kocer on 04/11/2022.
//

#ifndef ECE_CITY_3_Z_MENU_H
#define ECE_CITY_3_Z_MENU_H


#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include "jeu.h"

#define PI 3.141592


/// A METTRE DANS UN FICHIER .C/.H CAR GRANDE STRUCTURE
typedef struct {
    int playRect, rulesRect, teamRect, gameMode, persoRect;
    ArcDeCercle arc ;
    InfoEcran ecran ;
} Menu;

typedef struct {
    int pages;
    InfoEcran ecran ;
} Rules;










#endif //ECE_CITY_3_Z_MENU_H
