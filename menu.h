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


///Déclaration importantes

enum gameMode {PLAY, RULES, TEAM, MENU, END};

#define PI 3.141592
#define RULESPAGEMAX 10

///STRUCTURE QU'ON PEUT METTRE EN PARAMETRES DE FONCTION POUR EVITER TROP DE PARAMETRES
typedef struct {
    int mouse_x, mouse_y ;
    double height, width ;
} InfoEcran;


typedef struct {
    float startTheta, endTheta, currentTheta, currentEndTheta ;
} ArcDeCercle ;

typedef struct {
    int playRect, rulesRect, teamRect, gameMode, persoRect;
    ArcDeCercle arc ;
    InfoEcran ecran ;
} Menu;

typedef struct {
    int pages;
    InfoEcran ecran ;
} Rules;

//Peut supprimer cette structure (je ne sais pas encore si je vais l'utiliser

typedef struct {
    double x, y, width, height ;
} Image ;


void initialiserMenu(Menu* mainMenu, float width, float height) ;
void drawMenuV2(Menu* mainMenu, ALLEGRO_FONT *gameFont);
void menuSouris(Menu* mainMenu, InfoEcran ecran) ;
void moveGameModeArc(Menu** mainMenu) ;
void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT* gameFont, ALLEGRO_FONT* gameFont1, ALLEGRO_BITMAP* kirbyIcone, ALLEGRO_BITMAP* pacmanIcone, ALLEGRO_BITMAP* peachIcone, ALLEGRO_BITMAP* marioIcone, ALLEGRO_BITMAP* donkey_kongIcone);
void afficherPages(int pages, ALLEGRO_FONT* gameFontRegles, ALLEGRO_COLOR gameColor, float height, float width, ALLEGRO_BITMAP* kirbyIcone, ALLEGRO_BITMAP* pacmanIcone, ALLEGRO_BITMAP* peachIcone, ALLEGRO_BITMAP* marioIcone, ALLEGRO_BITMAP* donkey_kongIcone) ;
void drawTeam(float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT *gameFont, ALLEGRO_BITMAP* team);




void initialiserMenu(Menu* mainMenu, float width, float height);








#endif //ECE_CITY_3_Z_MENU_H
