//
// Created by Théophile Dutrey on 01/11/2022.
//
#define LARGEUR 1024
#define HAUTEUR 768
#define COLONNES 45
#define LIGNES 35
#define TUILE 20
#ifndef ECE_CITY_3_Z_BIBLIOTHEQUE_H
#define ECE_CITY_3_Z_BIBLIOTHEQUE_H
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "graphe.h"
#include "banque.h"
#include "graphe.h"

typedef struct{
    int type;
    int route, habitation, usine, chateauEau, caserne;
    int prix;
    int etat; //0 : terrain vague 1: cabane  2: maison   3:immeuble  4:gratte-ciel
}CONSTRUCTION;

typedef struct{
    float x, y;
    CONSTRUCTION construction;
}CASE;


void allegroCreation(ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_TIMER** timer);
#endif //ECE_CITY_3_Z_BIBLIOTHEQUE_H
