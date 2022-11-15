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
    if(x+LONGUEURE_TERRAIN_VAGUE <= COLONNES && y+LARGEUR_TERRAIN_VAGUE <= LIGNES && possibiliteDeConstruire(tabCase,x,y,LONGUEURE_TERRAIN_VAGUE,LARGEUR_TERRAIN_VAGUE)==0){
        if(presenceRoute(tabCase, x, y, LONGUEURE_TERRAIN_VAGUE, LARGEUR_TERRAIN_VAGUE) != 0) {
            (*compteur)++;
            for (int a = 0; a < LONGUEURE_TERRAIN_VAGUE; a++) {
                for (int b = 0; b < LARGEUR_TERRAIN_VAGUE; b++) {
                    tabCase[x + a][y + b].construction.type = 5;
                    tabCase[x + a][y + b].construction.identite = *compteur;
                }
            }
        }
    }
}
int possibiliteDeConstruire(CASE** tabCase, int x, int y, int dimensionX, int dimensionY){
    int compteur = 0;
    for(int a = 0; a<dimensionX; a++){
        for(int b = 0; b<dimensionY; b++){
            if(tabCase[x+a][y+b].construction.type != 0) {
                compteur++;
            }
        }
    }
    return compteur;
}

int presenceRoute(CASE** tabCase, int x, int y, int dimensionX, int dimensionY){
    int compteur = 0;
        for (int a = 0; a < dimensionX; a++) {
            if (tabCase[x + a][y - 1].construction.type == 1) {
                compteur++;
            }
        }
        for (int a = 0; a < dimensionX; a++) {
            if (tabCase[x + a][y + (dimensionY)].construction.type == 1) {
                compteur++;
            }
        }
        for (int a = 0; a < dimensionY; a++) {

                if (x - 1 >= 0 && tabCase[x - 1][y + a].construction.type == 1) {
                    compteur++;
                }

        }
        for (int a = 0; a < dimensionY; a++) {

                if (x + dimensionX < COLONNES && tabCase[x + dimensionX][y + a].construction.type == 1) {
                    compteur++;
                }

        }

    return compteur;
}
void batiment (CASE** tabCase, int x, int y, int* compteur, int typeBatiment){
    if(x+LONGUEURE_BATTIMENT <= COLONNES && y+LARGEUR_BATTIMENT <= LIGNES && possibiliteDeConstruire(tabCase,x,y,LONGUEURE_BATTIMENT,LARGEUR_BATTIMENT)==0){
        if(presenceRoute(tabCase, x, y, LONGUEURE_BATTIMENT, LARGEUR_BATTIMENT) != 0) {
            (*compteur)++;
            for (int a = 0; a < LONGUEURE_BATTIMENT; a++) {
                for (int b = 0; b < LARGEUR_BATTIMENT; b++) {
                    tabCase[x + a][y + b].construction.type = typeBatiment;
                    tabCase[x + a][y + b].construction.identite = *compteur;
                }
            }
        }
    }
}

void routeApercu (CASE** tabCase, int x, int y){
    tabCase[x][y].construction.apercu = 1;
}

void habitationApercu (CASE** tabCase, int x, int y){

}
void batimentApercu(CASE** tabCase, int x, int y, int typeBatiment){

}

