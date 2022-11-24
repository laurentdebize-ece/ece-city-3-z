//
// Created by Théophile Dutrey on 03/11/2022.
//
#include <raylib.h>
#include "bibliotheque.h"

void afficherBarreOutils(animationBarre* boiteOutils, int seconde, Texture2D monnaie, Texture2D temps, Texture2D eau, Texture2D elec, Texture2D souris, Texture2D calendrier, int min, int argent, int heure, int mois, int annee, Texture2D moinsAccel, Texture2D plusAccel, Texture2D route, Texture2D maison, Texture2D centrale, Texture2D puit, Texture2D caserne){
    //int posXRectangleRange = 1025;
    //int posXRectanglePasRange = 930;
    int const posXFlecheIni = 1520;
    int const posXFlecheFin = 1300;
    char* m[] = {"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};



    if (boiteOutils->etat == FERME){
        DrawRectangleRounded((Rectangle){1520, 340, 100, 60}, 0.2, 16, WHITE);
        DrawTriangle((Vector2){1540, 370},(Vector2){1580, 390}, (Vector2){1580, 350}, BLUE);

    }
    if (boiteOutils->etat == OUVERT){
        DrawRectangleRounded((Rectangle){1300, 340, 100, 60}, 0.2, 16, WHITE);
        DrawRectangleRounded((Rectangle){-10, -10, 500, 70}, 0.2, 16, BLUE);
        DrawTriangle((Vector2){1360, 370}, (Vector2){1320, 350}, (Vector2){1320, 390},BLUE);
        DrawRectangle(1370, 0, 280, 768, ColorAlpha(BLUE, 1));
        DrawTexture(route, 1380, 40, ColorAlpha(WHITE, 1));
        DrawTexture(maison, 1380, 190, ColorAlpha(WHITE, 1));
        DrawTexture(centrale, 1380, 340, ColorAlpha(WHITE, 1));
        DrawTexture(puit, 1380, 490, ColorAlpha(WHITE, 1));
        DrawTexture(caserne, 1380, 640, ColorAlpha(WHITE, 1));
        DrawText("Coût", 1520, 65, 20, BLACK);
        DrawText("10", 1530, 95, 20, BLACK);
        DrawText("Coût", 1520, 215, 20, BLACK);
        DrawText("1000", 1525, 245, 20, BLACK);
        DrawText("Coût", 1520, 365, 20, BLACK);
        DrawText("10000", 1518, 395, 20, BLACK);
        DrawText("Coût", 1520, 515, 20, BLACK);
        DrawText("10000", 1518, 545, 20, BLACK);
        DrawText("Coût", 1520, 665, 20, BLACK);
        DrawText("1000", 1522, 695, 20, BLACK);
    }
    DrawTriangle((Vector2){-10, -10}, (Vector2){0, 300},(Vector2){600, 0},  BLUE);
    DrawTexture(temps, 10, 15, BLUE);
    DrawTexture(monnaie, 200, 15, BLUE);
    DrawTexture(calendrier, 10, 100, BLUE);

    //DrawRectangle(10, 10, 40, 40, WHITE);
    DrawRectangleRounded((Rectangle){76, 38, 82, 24}, 0.2, 16, WHITE);
    DrawRectangleRounded((Rectangle){270, 38, 150, 24}, 0.2, 16, WHITE);
    DrawText(TextFormat("%.2d:%.2d:%.2d",heure, min, seconde), 78, 40, 20, ColorAlpha(BLACK, 1));
    DrawText(TextFormat("%d", argent), 272, 40, 20, ColorAlpha(BLACK, 1));
    DrawText(TextFormat("%s", m[mois]), 78, 110, 20, ColorAlpha(BLACK, 1));
    DrawText(TextFormat("%d", annee), 78, 140, 20, ColorAlpha(BLACK, 1));

    //DrawRectangleRounded((Rectangle){10, 200, 20, 20}, 0.2, 16, BLACK);
    DrawTexture(moinsAccel, 10, 200, BLUE);
    //DrawRectangleRounded((Rectangle){35, 190, 40, 40}, 0.2, 16, BLACK);
    //DrawRectangleRounded((Rectangle){80, 200, 20, 20}, 0.2, 16, BLACK);
    DrawTexture(plusAccel, 80, 200, BLUE);


    DrawTriangle((Vector2){0, 400}, (Vector2){0, HAUTEUR}, (Vector2){700, HAUTEUR}, BLUE);
    DrawTexture(souris, 50, 530, BLUE);
    DrawTexture(eau, 170, 585, BLUE);
    DrawTexture(elec, 240, 675, BLUE);
    DrawText("Souris :", 30, 500, 20, ColorAlpha(BLACK, 1));
    DrawText("Niveau d'Eau :", 20, 600, 20, ColorAlpha(BLACK, 1));
    DrawText("Niveau d'Electricite :", 20, 680, 20, ColorAlpha(BLACK, 1));

}
void construireBat(int categorieConstruction, int posXMouse, int posYMouse, Texture2D building){
    switch (categorieConstruction) {
        case 0 :

            break;
        case 1 :
            DrawTexture(building, posXMouse-105, posYMouse-147, GREEN);
            break;
    }
}
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
    int TypeRoute;

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            positionSprite.x = x * (LARGEUR_TUILE_ISO / 2) + y * (LARGEUR_TUILE_ISO / 2) + LARGEUR_TUILE_ISO * ISO_DECALAGE_X;
            positionSprite.y = x * (HAUTEUR_TUILE_ISO / 2) - y * (HAUTEUR_TUILE_ISO / 2) + HAUTEUR_TUILE_ISO * ISO_DECALAGE_Y;
            if (tabCase[x][y].type == 1) {
                TypeRoute = typeRoute(tabCase,x,y);
                if (niveau == 0) {
                    for(int i = 0; i<=15; i++) {
                        if (TypeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = 0;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
                if (niveau == 1) {
                    for(int i = 0; i<=15; i++) {
                        if (TypeRoute == i) {
                            route.x = i * LARGEUR_TUILE_ISO + i;
                            route.y = HAUTEUR_TUILE_ISO;
                        }
                    }
                    DrawTextureRec(Routes, route, positionSprite, WHITE);
                }
                if (niveau == 2) {
                    for(int i = 0; i<=15; i++) {
                        if (TypeRoute == i) {
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
            if (tabCase[x][y].type == 5) {
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





void enregistrerPartie(CASE** tabCase){
    FILE * n = fopen("../map.txt","w+");
    FILE * d = fopen("../ordreConstruction.txt","w+");
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fprintf(n, "%d ",tabCase[x][y].type);
            fprintf(d, "%d ", tabCase[x][y].identite);
        }
        fputs("\n",n);
        fputs("\n",d);
    }
}

void recommencerPartie(CASE** tabCase, COMPTEUR* compteur){
    FILE * n = fopen("../map.txt","w+");
    compteur->nbChateauO=0;
    compteur->nbHab=0;
    compteur->nbRues=0;
    compteur->nbUsines=0;
    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fprintf(n, "%d ",0);
            tabCase[x][y].type = 0;
            tabCase[x][y].identite = 0;
        }
        fputs("\n",n);
    }
}

void initialisationOrdre(CASE** tabCase, int ordre, int x, int y, COMPTEUR* compteur){

    if(tabCase[x][y].type == 1) {
        tabCase[x][y].identite = ordre;
        if(ordre>compteur->nbRues){
            compteur->nbRues = ordre;
        }
    }
    if(tabCase[x][y].type == 2) {
        tabCase[x][y].identite = ordre;
        if(ordre>compteur->nbUsines){
            compteur->nbUsines = ordre;
        }
    }
    if(tabCase[x][y].type == 3) {
        tabCase[x][y].identite = ordre;
        if(ordre>compteur->nbChateauO){
            compteur->nbChateauO = ordre;
        }
    }

    if(tabCase[x][y].type >= 5) {
        tabCase[x][y].identite = ordre;
        if(ordre>compteur->nbHab){
            compteur->nbHab = ordre;
        }
    }

}