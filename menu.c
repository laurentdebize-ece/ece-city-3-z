//
// Created by Ilayda Kocer on 04/11/2022.
//

#include "menu.h"


void initialiserMenu(Menu* mainMenu, float width, float height) {
    mainMenu->ecran.width = width ;
    mainMenu->ecran.height = height ;
    mainMenu->gameMode = MENU;
    mainMenu->playRect = 0;
    mainMenu->rulesRect = 0;
    mainMenu->teamRect = 0;
    mainMenu->arc.startTheta = 0;
    mainMenu->arc.endTheta = 2 * PI;
    mainMenu->arc.currentTheta = 0;
    mainMenu->arc.currentEndTheta = 2 * PI;
}


void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT* gameFont, ALLEGRO_FONT* gameFont1, ALLEGRO_BITMAP* kirbyIcone, ALLEGRO_BITMAP* pacmanIcone, ALLEGRO_BITMAP* peachIcone, ALLEGRO_BITMAP* marioIcone, ALLEGRO_BITMAP* donkey_kongIcone) {
    int police = 2 * width / 55;
    int policeRegles = 40;
    float thickness = (5 * height / 6 - height / 6) / 40;
    ALLEGRO_COLOR gameColor = al_map_rgb(20, 20, 20);

    ///FOND D'ECRAN GRISATRE
    al_draw_filled_rectangle(0, 0, width, height, al_map_rgba(150, 150, 150, 150));

    ///ON FAIT SURBRILLER LES CASES RETURN ET LES BOUTONS SI LA SOURIS SE TROUVE DESSUS
    if ((float) mouse_x < 5 * width / 32 && mouse_x > width / 384 && (float) mouse_y < 2 * height / 27 &&
        mouse_y > height / 216) {
        al_draw_filled_rectangle(width / 384, height / 216, 5 * width / 32, 2 * height / 27, al_map_rgb(200, 200, 200));
    } else
        al_draw_filled_rectangle(width / 384, height / 216, 5 * width / 32, 2 * height / 27, al_map_rgb(250, 250, 250));
    if (*pages < RULESPAGEMAX) {
        if ((mouse_x - 13 * width / 15) * (mouse_x - 13 * width / 15) +
            (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < width / 38.4 * width / 38.4) {
            al_draw_filled_circle(13 * width / 15, 11 * height / 13, width / 38.4, al_map_rgb(200, 200, 200));
        } else al_draw_filled_circle(13 * width / 15, 11 * height / 13, width / 38.4, al_map_rgb(250, 250, 250));
    }
    if (*pages > 1) {
        if ((mouse_x - 2 * width / 15) * (mouse_x - 2 * width / 15) +
            (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < width / 38.4 * width / 38.4) {
            al_draw_filled_circle(2 * width / 15, 11 * height / 13, width / 38.4, al_map_rgb(200, 200, 200));
        } else al_draw_filled_circle(2 * width / 15, 11 * height / 13, width / 38.4, al_map_rgb(250, 250, 250));
    }

    ///GRAND RECTANGLE AU MILIEU
    al_draw_filled_rectangle(width / 5, height / 6, 4 * (width / 5), 5 * (height / 6), al_map_rgba(219, 112, 147, 200));

    ///FLECHE DROITE
    if (*pages < RULESPAGEMAX) {
        al_draw_circle(13 * width / 15, 11 * height / 13, width / 38.4, gameColor, 4);
        al_draw_line(13 * width / 15 - width / 64, 11 * height / 13, 13 * width / 15 + width / 64, 11 * height / 13,
                     gameColor, 3);
        al_draw_line(13 * width / 15 + width / 64, 11 * height / 13, 13 * width / 15 + width / 192,
                     11 * height / 13 - height / 43.2, gameColor, 3);
        al_draw_line(13 * width / 15 + width / 64, 11 * height / 13, 13 * width / 15 + width / 192,
                     11 * height / 13 + height / 43.2, gameColor, 3);
    }

    ///FLECHE GAUCHE
    if (*pages > 1) {
        al_draw_circle(2 * width / 15, 11 * height / 13, width / 38.4, gameColor, 4);
        al_draw_line(2 * width / 15 - width / 64, 11 * height / 13, 2 * width / 15 + width / 64, 11 * height / 13,
                     gameColor, 3);
        al_draw_line(2 * width / 15 - width / 64, 11 * height / 13, 2 * width / 15 - width / 192,
                     11 * height / 13 - height / 43.2, gameColor, 3);
        al_draw_line(2 * width / 15 - width / 64, 11 * height / 13, 2 * width / 15 - width / 192,
                     11 * height / 13 + height / 43.2, gameColor, 3);
    }

    al_draw_filled_circle(7.46 * width / 15, 11 * height / 13 + 1.5 * height / 18, police, al_map_rgb(250, 250, 250));
    al_draw_circle(7.46 * width / 15, 11 * height / 13 + 1.5 * height / 18, police, gameColor, 3);
}