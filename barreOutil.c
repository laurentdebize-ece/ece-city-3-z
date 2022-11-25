//
// Created by Théophile Dutrey on 25/11/2022.
//

#include "bibliotheque.h"
void barreOutilSouris(int PosXMouse, int PosYMouse,  animationBarre* barre, int* categorieConstruction){

    if (barre->etat == FERME && PosXMouse > 1520 && PosXMouse < 1600 && PosYMouse > 340 && PosYMouse < 400) {
        barre->etat = OUVERT;
    }
    if (barre->etat == OUVERT && PosXMouse > 1300 && PosXMouse < 1370 && PosYMouse > 340 && PosYMouse < 400) {
        barre->etat = FERME;
    }
    if (barre->etat == OUVERT && PosXMouse > 1380 && PosXMouse < 1480 && PosYMouse > 40 && PosYMouse < 140) {
        *categorieConstruction = 0;
    }
    if (barre->etat == OUVERT && PosXMouse > 1380 && PosXMouse < 1480 && PosYMouse > 190 && PosYMouse < 290) {
        *categorieConstruction = 1;
    }
    if (barre->etat == OUVERT && PosXMouse > 1380 && PosXMouse < 1480 && PosYMouse > 340 && PosYMouse < 440) {
        *categorieConstruction = 2;
    }
    if (barre->etat == OUVERT && PosXMouse > 1380 && PosXMouse < 1480 && PosYMouse > 490 && PosYMouse < 590) {
        *categorieConstruction = 3;
    }
}

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