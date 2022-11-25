//
// Created by Théophile Dutrey on 03/11/2022.
//
#include <raylib.h>
#include "bibliotheque.h"


void construireBat(int categorieConstruction, int posXMouse, int posYMouse, Texture2D building, Texture2D route) {
    switch (categorieConstruction) {
        case 0 :
            DrawTextureRec(route, (Rectangle){5*35, 0, 34, 18}, (Vector2){posXMouse-10, posYMouse-5}, GREEN);
            break;
        case 1 :
            DrawTexture(building, posXMouse - 15, posYMouse - 25, GREEN);
            break;
    }
}

void affichageGrille(VECTEUR mouseIso, Texture2D texture) {

    Vector2 positionSprite;
    Rectangle sprite;
    sprite.width = LARGEUR_TUILE_ISO;
    sprite.height = HAUTEUR_TUILE_ISO;
    sprite.x = 0;
    sprite.y = 4 * HAUTEUR_TUILE_ISO;
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x =
                    x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y =
                    x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;
            Color t = WHITE;
            if (mouseIso.x == x && mouseIso.y == y) {
                t = BLACK;
            }
            DrawTextureRec(texture, sprite, positionSprite, t);

        }
    }
}

void affichageRoute(Texture2D Routes, CASE **tabCase, int niveau) {
    Vector2 positionSprite;
    Rectangle route;
    route.width = LARGEUR_TUILE_ISO;
    route.height = HAUTEUR_TUILE_ISO;
    int TypeRoute;

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x =
                    x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y =
                    x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;
            if (tabCase[x][y].type == 1) {
                TypeRoute = typeRoute(tabCase, x, y);
                if (niveau == 0) {
                    for (int i = 0; i <= 15; i++) {
                        if (TypeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = 0;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
                if (niveau == 1) {
                    for (int i = 0; i <= 15; i++) {
                        if (TypeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = HAUTEUR_TUILE_ISO;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
                if (niveau == 2) {
                    for (int i = 0; i <= 15; i++) {
                        if (TypeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = 2 * HAUTEUR_TUILE_ISO;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
            }
        }
    }
}

void affichageTerrain(Texture2D Terrain, CASE **tabCase, Texture2D terrainVague, Texture2D cabane, Texture2D maison, Texture2D hotel, Texture2D gratteCiel) {
    Vector2 positionSprite;
    Rectangle terrain;
    terrain.width = LARGEUR_TUILE_ISO;
    terrain.height = HAUTEUR_TUILE_ISO;
    terrain.x = 0;
    terrain.y = 6 * HAUTEUR_TUILE_ISO;


    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x =
                    x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y =
                    x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;

            if (tabCase[x][y].affichage == 1) {
                switch (tabCase[x][y].type) {
                    case 5 :
                        DrawTexture(terrainVague, positionSprite.x, positionSprite.y - 19, WHITE);
                        break;
                    case 6 :
                        DrawTexture(cabane, positionSprite.x, positionSprite.y - 19, WHITE);
                        break;
                    case 7 :
                        DrawTexture(maison, positionSprite.x, positionSprite.y - 19, WHITE);
                        break;
                    case 8 :
                        DrawTexture(hotel, positionSprite.x, positionSprite.y - 19, WHITE);
                        break;
                    case 9 :
                        DrawTexture(gratteCiel, positionSprite.x, positionSprite.y - 19, WHITE);
                        break;
                }
            }
        }
    }
}

void affichageBattiment(Texture2D Battiment, CASE **tabCase) {
    Vector2 positionSprite;
    Rectangle battiment;
    battiment.width = LARGEUR_TUILE_ISO;
    battiment.height = HAUTEUR_TUILE_ISO;
    battiment.x = 0;
    battiment.y = 3 * HAUTEUR_TUILE_ISO;

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x =
                    x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y =
                    x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;
            if (tabCase[x][y].type == 3) {
                DrawTextureRec(Battiment, battiment, positionSprite, WHITE);
            }
            if (tabCase[x][y].type == 2) {
                DrawTextureRec(Battiment, battiment, positionSprite, WHITE);
            }
        }
    }
}

int typeRoute(CASE **tabCase, int x, int y) {
    int compteurTypeRoute = 0;
    if (x - 1 >= 0 && tabCase[x - 1][y].type == 1) {
        compteurTypeRoute = compteurTypeRoute + 1;
    }
    if (y + 1 < LIGNES && tabCase[x][y + 1].type == 1) {
        compteurTypeRoute = compteurTypeRoute + 2;
    }
    if (x + 1 < COLONNES && tabCase[x + 1][y].type == 1) {
        compteurTypeRoute = compteurTypeRoute + 4;
    }
    if (y - 1 >= 0 && tabCase[x][y - 1].type == 1) {
        compteurTypeRoute = compteurTypeRoute + 8;
    }
    return compteurTypeRoute;
}


void enregistrerPartie(CASE **tabCase) {
    FILE *n = fopen("../map.txt", "w+");
    FILE *d = fopen("../ordreConstruction.txt", "w+");
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fprintf(n, "%d ", tabCase[x][y].type);
            fprintf(d, "%d ", tabCase[x][y].identite);
        }
        fputs("\n", n);
        fputs("\n", d);
    }
}

void recommencerPartie(CASE **tabCase, COMPTEUR *compteur) {
    FILE *n = fopen("../map.txt", "w+");
    compteur->nbChateauO = 0;
    compteur->nbHab = 0;
    compteur->nbRues = 0;
    compteur->nbUsines = 0;
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fprintf(n, "%d ", 0);
            tabCase[x][y].type = 0;
            tabCase[x][y].identite = 0;
        }
        fputs("\n", n);
    }
}

void initialisationOrdre(CASE **tabCase, int ordre, int x, int y, COMPTEUR *compteur) {

    if (tabCase[x][y].type == 1) {
        tabCase[x][y].identite = ordre;
        if (ordre > compteur->nbRues) {
            compteur->nbRues = ordre;
        }
    }
    if (tabCase[x][y].type == 2) {
        tabCase[x][y].identite = ordre;
        if (ordre > compteur->nbUsines) {
            compteur->nbUsines = ordre;
        }
    }
    if (tabCase[x][y].type == 3) {
        tabCase[x][y].identite = ordre;
        if (ordre > compteur->nbChateauO) {
            compteur->nbChateauO = ordre;
        }
    }

    if (tabCase[x][y].type >= 5) {
        tabCase[x][y].identite = ordre;
        if (ordre > compteur->nbHab) {
            compteur->nbHab = ordre;
        }
    }

}