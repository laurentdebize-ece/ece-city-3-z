//
// Created by Théophile Dutrey on 03/11/2022.
//

#include "bibliotheque.h"
void route (CASE** tabCase, int x, int y, int* compteur){
    tabCase[x][y].construction.type = 1;
    (*compteur)++;
    tabCase[x][y].construction.identite = *compteur;
}

void habitaion (CASE** tabCase, int x, int y, int* compteur){
    if(x-1 >= 0 && x+1 < COLONNES && y-1 >= 0 && y+1 < LIGNES && tabCase[x - 1][y].construction.type == 0 && tabCase[x + 1][y].construction.type == 0 && tabCase[x][y - 1].construction.type == 0 && tabCase[x][y + 1].construction.type == 0 && tabCase[x - 1][y - 1].construction.type == 0 && tabCase[x + 1][y + 1].construction.type == 0 && tabCase[x + 1][y - 1].construction.type == 0 && tabCase[x - 1][y + 1].construction.type == 0) {
        (*compteur)++;

        tabCase[x][y].construction.type = 2;
        tabCase[x][y].construction.identite = *compteur;

        tabCase[x - 1][y].construction.type = 2;
        tabCase[x - 1][y].construction.identite = *compteur;

        tabCase[x + 1][y].construction.type = 2;
        tabCase[x + 1][y].construction.identite = *compteur;

        tabCase[x][y - 1].construction.type = 2;
        tabCase[x][y - 1].construction.identite = *compteur;

        tabCase[x][y + 1].construction.type = 2;
        tabCase[x][y + 1].construction.identite = *compteur;

        tabCase[x - 1][y - 1].construction.type = 2;
        tabCase[x - 1][y - 1].construction.identite = *compteur;

        tabCase[x + 1][y + 1].construction.type = 2;
        tabCase[x + 1][y + 1].construction.identite = *compteur;

        tabCase[x + 1][y - 1].construction.type = 2;
        tabCase[x + 1][y - 1].construction.identite = *compteur;

        tabCase[x - 1][y + 1].construction.type = 2;
        tabCase[x - 1][y + 1].construction.identite = *compteur;

    }
}

void batiment (CASE** tabCase, int x, int y, int* compteur){
    if(x >= 0 && x+3 < COLONNES && y >= 0 && y+5 < LIGNES){
        (*compteur)++;
        for(int a = 0; a<4; a++){
            for(int b = 0; b<6; b++){
                tabCase[x+a][y+b].construction.type = 3;
                tabCase[x+a][y+b].construction.identite = *compteur;
            }
        }
    }
}