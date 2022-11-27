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

void afficherBarreOutils(animationBarre* boiteOutils, int seconde, Texture2D monnaie, Texture2D temps, Texture2D eau, Texture2D elec, Texture2D souris, Texture2D calendrier, int min, int argent, int heure, int mois, int annee, Texture2D moinsAccel, Texture2D plusAccel, Texture2D route, Texture2D maison, Texture2D centrale, Texture2D puit, Texture2D caserne, Texture2D rotation, Texture2D enregister, Texture2D demolition, int construire, int detruire, Texture2D cosntruireOn, Texture2D cosntruireOff, Texture2D demolitionOff, Texture2D plage, Texture2D plage2){
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

    DrawTexture(plage, 0, 0, WHITE);
   //DrawTriangle((Vector2){-10, -10}, (Vector2){0, 300},(Vector2){600, 0},  BLUE);
    DrawTexture(temps, 10, 15, WHITE);
    DrawTexture(monnaie, 200, 15, WHITE);
    DrawTexture(calendrier, 10, 100, WHITE);
    DrawRectangleRounded((Rectangle){76, 38, 82, 24}, 0.2, 16, WHITE);
    DrawRectangleRounded((Rectangle){270, 38, 150, 24}, 0.2, 16, WHITE);
    DrawText(TextFormat("%.2d:%.2d:%.2d",heure, min, seconde), 78, 40, 20, ColorAlpha(BLACK, 1));
    DrawText(TextFormat("%d", argent), 272, 40, 20, ColorAlpha(BLACK, 1));
    DrawText(TextFormat("%s", m[mois]), 78, 110, 20, ColorAlpha(BLACK, 1));
    DrawText(TextFormat("%d", annee), 78, 140, 20, ColorAlpha(BLACK, 1));
    DrawTexture(moinsAccel, 10, 200, WHITE);
    DrawTexture(plusAccel, 80, 200, WHITE);

    DrawTexture(plage2, 0, 400, WHITE);
    //DrawTriangle((Vector2){0, 400}, (Vector2){0, HAUTEUR}, (Vector2){750, HAUTEUR}, BLUE);
    if (construire == 0){
        DrawTexture(cosntruireOn, 30, 700, WHITE);
    } else{
        DrawTexture(cosntruireOff, 30, 700, WHITE);
    }
    DrawTexture(rotation, 300, 700, WHITE);
    DrawTexture(enregister, 175, 700, WHITE);
    if (detruire == 0){
        DrawTexture(demolitionOff, 425, 700, WHITE);
    } else{
        DrawTexture(demolition, 425, 700, WHITE);
    }

    DrawTexture(eau, 170, 515, WHITE);
    DrawTexture(elec, 240, 600, WHITE);
    DrawText("Niveau d'Eau :", 20, 530, 20, ColorAlpha(BLACK, 1));
    DrawText("Niveau d'Electricite :", 20, 620, 20, ColorAlpha(BLACK, 1));
    DrawRectangleRounded((Rectangle){20, 565, 200, 24}, 0.2, 16, WHITE);
    DrawRectangleRounded((Rectangle){20, 655, 200, 24}, 0.2, 16, WHITE);

    DrawRectangleLines(1000, 50, 200, 24, WHITE);
    DrawText("Quitter la partie", 1005, 52, 20, WHITE);
    DrawRectangleLines(1000, 80, 250, 24, WHITE);
    DrawText("Recommencer la partie", 1005, 82, 20, WHITE);

}