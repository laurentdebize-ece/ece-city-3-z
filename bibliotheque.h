//
// Created by Théophile Dutrey on 01/11/2022.
//
#define LARGEUR 1024
#define HAUTEUR 768
#define COLONNES 45
#define LIGNES 35
#define TUILE 20
#define COUT_CENTRAL 100000
#define COUT_CHATEAU_DEAU 100000
#define COUT_ROUTE 50
#define COUT_TERRAIN_VAGUE 1000
#define COUT_CASERNE 10000
#define TAXE 50
#define NBRHABITANT_CABANE 10
#define NBRHABITANT_MAISON 50
#define NBRHABITANT_IMMEUBLE 100
#define NBRHABITANT_GRATTECIEL 1000
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
#include "construction.h"
#include "banque.h"
void allegroCreation(ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_TIMER** timer);
#endif //ECE_CITY_3_Z_BIBLIOTHEQUE_H
