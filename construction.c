//
// Created by Théophile Dutrey on 03/11/2022.
//

#include "bibliotheque.h"
void route (CASE** tabCase, int x, int y, int* compteur){
    tabCase[x][y].construction.type = 1;
    (*compteur)++;
    tabCase[x][y].construction.identite = *compteur;
}

void habitation (CASE** tabCase, int x, int y, int* compteur){
    if(x-1 >= 0 && x+1 < COLONNES && y-1 >= 0 && y+1 < LIGNES && tabCase[x - 1][y].construction.type == 0 && tabCase[x + 1][y].construction.type == 0 && tabCase[x][y - 1].construction.type == 0 && tabCase[x][y + 1].construction.type == 0 && tabCase[x - 1][y - 1].construction.type == 0 && tabCase[x + 1][y + 1].construction.type == 0 && tabCase[x + 1][y - 1].construction.type == 0 && tabCase[x - 1][y + 1].construction.type == 0) {
        (*compteur)++;

        tabCase[x][y].construction.type = 5;
        tabCase[x][y].construction.identite = *compteur;

        tabCase[x - 1][y].construction.type = 5;
        tabCase[x - 1][y].construction.identite = *compteur;

        tabCase[x + 1][y].construction.type = 5;
        tabCase[x + 1][y].construction.identite = *compteur;

        tabCase[x][y - 1].construction.type = 5;
        tabCase[x][y - 1].construction.identite = *compteur;

        tabCase[x][y + 1].construction.type = 5;
        tabCase[x][y + 1].construction.identite = *compteur;

        tabCase[x - 1][y - 1].construction.type = 5;
        tabCase[x - 1][y - 1].construction.identite = *compteur;

        tabCase[x + 1][y + 1].construction.type = 5;
        tabCase[x + 1][y + 1].construction.identite = *compteur;

        tabCase[x + 1][y - 1].construction.type = 5;
        tabCase[x + 1][y - 1].construction.identite = *compteur;

        tabCase[x - 1][y + 1].construction.type = 5;
        tabCase[x - 1][y + 1].construction.identite = *compteur;
    }
}
int possibiliteDeConstruire(CASE** tabCase, int x, int y){
    int compteur = 0;
    for(int a = 0; a<4; a++){
        for(int b = 0; b<6; b++){
            if(tabCase[x+a][y+b].construction.type != 0) {
                compteur++;
            }
        }
    }
    return compteur;
}
void batiment (CASE** tabCase, int x, int y, int* compteur, int typeBatiment){
    if(x >= 0 && x+3 < COLONNES && y >= 0 && y+5 < LIGNES && possibiliteDeConstruire(tabCase,x,y)==0){
        (*compteur)++;
        for(int a = 0; a<4; a++){
            for(int b = 0; b<6; b++){
                tabCase[x+a][y+b].construction.type = typeBatiment;
                tabCase[x+a][y+b].construction.identite = *compteur;
            }
        }
    }
}

