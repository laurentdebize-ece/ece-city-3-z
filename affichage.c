//
// Created by Théophile Dutrey on 03/11/2022.
//

#include "bibliotheque.h"
void affichageConstruction(CASE** tabCase, int x, int y,int niveau){
    if(tabCase[x][y].construction.type == 1){
        if(niveau==0) {
            al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                     tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                     al_map_rgb(255, 255, 255));
        }
        if(niveau==1) {al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                                tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                                al_map_rgb(0, 0, 255));}

        if(niveau==2) {al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                                tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                                al_map_rgb(255, 255, 0));}

    }
    if(tabCase[x][y].construction.type == 5){
        al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                 tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                 al_map_rgb(0, 255, 0));
    }
    if(tabCase[x][y].construction.type == 3){
        al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                 tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                 al_map_rgb(255, 0, 0));
    }
    if(tabCase[x][y].construction.type == 2){
        al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                 tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                 al_map_rgb(255, 0, 255));
    }
}

void apercuConstruction(CASE** tabCase, int x, int y){
    if(tabCase[x][y].construction.apercu == 1){

        al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                     tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                     al_map_rgba(255, 255, 255, 50));

    }
    if(tabCase[x][y].construction.apercu == 5){
        al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                 tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                 al_map_rgba(0, 255, 0,50));
    }
    if(tabCase[x][y].construction.apercu == 3){
        al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                 tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                 al_map_rgba(255, 0, 0,50));
    }
    if(tabCase[x][y].construction.apercu == 2){
        al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                 tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                 al_map_rgba(255, 0, 255,50));
    }
}