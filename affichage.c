//
// Created by Théophile Dutrey on 03/11/2022.
//

#include "bibliotheque.h"
void affichageGrille(VECTEUR mouseIso, Texture2D texture){

    Vector2 positionSprite;
    Rectangle sprite;
    sprite.width= LARGEUR_TUILE_ISO;
    sprite.height = HAUTEUR_TUILE_ISO;
    sprite.x = 0;
    sprite.y = 4*HAUTEUR_TUILE_ISO;
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x = x*(LARGEUR_TUILE_ISO/2) + y*(LARGEUR_TUILE_ISO/2) + LARGEUR_TUILE_ISO*ISO_DECALAGE_X;
            positionSprite.y = x*(HAUTEUR_TUILE_ISO/2) - y*(HAUTEUR_TUILE_ISO/2) + HAUTEUR_TUILE_ISO*ISO_DECALAGE_Y;
            Color t = WHITE;
            if (mouseIso.x == x && mouseIso.y == y) {
                t = BLACK;
            }

            DrawTextureRec(texture,sprite, positionSprite,t);

        }
    }
}

void affichageRoute(Texture2D Routes, CASE** tabCase, int niveau){
    Vector2 positionSprite;
    Rectangle route;
    route.width= LARGEUR_TUILE_ISO;
    route.height = HAUTEUR_TUILE_ISO;

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x = x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y = x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;
            if (tabCase[x][y].construction.type == 1) {
                typeRoute(tabCase, x , y);
                if (niveau == 0) {
                    for(int i = 0; i<=15; i++) {
                        if (tabCase[x][y].typeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = 0;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
                if (niveau == 1) {
                    for(int i = 0; i<=15; i++) {
                        if (tabCase[x][y].typeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = HAUTEUR_TUILE_ISO;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
                if (niveau == 2) {
                    for(int i = 0; i<=15; i++) {
                        if (tabCase[x][y].typeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = 2*HAUTEUR_TUILE_ISO;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
            }
        }
    }
}

void affichageTerrain(Texture2D Terrain, CASE** tabCase){
    Vector2 positionSprite;
    Rectangle terrain;
    terrain.width= LARGEUR_TUILE_ISO;
    terrain.height = HAUTEUR_TUILE_ISO;
    terrain.x = 0;
    terrain.y = 6 * HAUTEUR_TUILE_ISO;

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x =
                    x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y =
                    x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;
            if (tabCase[x][y].construction.type == 5) {
                DrawTextureRec(Terrain, terrain, positionSprite, WHITE);
            }
        }
    }
}

void affichageBattiment(Texture2D Battiment, CASE** tabCase){
    Vector2 positionSprite;
    Rectangle battiment;
    battiment.width= LARGEUR_TUILE_ISO;
    battiment.height = HAUTEUR_TUILE_ISO;
    battiment.x = 0;
    battiment.y = 3 * HAUTEUR_TUILE_ISO;

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x =
                    x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y =
                    x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;
            if (tabCase[x][y].construction.type == 3) {
                DrawTextureRec(Battiment, battiment, positionSprite, WHITE);
            }
        }
    }
}

void typeRoute(CASE **tabCase, int x, int y) {

    if (x - 1 >= 0 && x + 1 < COLONNES && y - 1 >= 0 && y + 1 < LIGNES) {

        if (tabCase[x - 1][y].construction.type == 1) {
            tabCase[x - 1][y].route = 1;
        } else {
            tabCase[x - 1][y].route = 0;
        }
        if (tabCase[x][y + 1].construction.type == 1) {
            tabCase[x][y + 1].route = 2;
        } else {
            tabCase[x][y + 1].route = 0;
        }
        if (tabCase[x + 1][y].construction.type == 1) {
            tabCase[x + 1][y].route = 4;
        } else {
            tabCase[x + 1][y].route = 0;
        }
        if (tabCase[x][y - 1].construction.type == 1) {
            tabCase[x][y - 1].route = 8;
        } else {
            tabCase[x][y - 1].route = 0;
        }
        tabCase[x][y].typeRoute = tabCase[x - 1][y].route + tabCase[x][y - 1].route + tabCase[x + 1][y].route + tabCase[x][y + 1].route;
    }
}


