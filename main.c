#include <stdio.h>
#include <raylib.h>
#include "bibliotheque.h"

int main() {
    int fini = 0;
    int niveau = 0;
    int construction;
    int NbrHabitant = 0;
    COMPTEUR compteur;
    float rotationX = 1;
    float rotationY = 1.5f;
    int compteEnBanque = 999999999;
    FILE * ifs = fopen("../map.txt","r");
    int n;
    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne

    CASE ** tabCase = malloc((COLONNES)*sizeof(CASE*));
    for(int i = 0; i<COLONNES; i++){
        tabCase[i] = malloc((LIGNES)*sizeof(CASE));
    }

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            tabCase[x][y].construction.type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague
            tabCase[x][y].x = TUILE/2+x*TUILE;
            tabCase[x][y].y = TUILE/2+y*TUILE;
        }
    }

    InitWindow(1024, 768, "Projet");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);
        if(IsKeyPressed(KEY_SPACE) == true){
            if (niveau != 2) {
                niveau++;
            } else {
                niveau = 0;
            }
        }
        if(IsKeyPressed(KEY_RIGHT) == true){
            if (categorieConstruction != 4) {
                categorieConstruction++;
            } else {
                categorieConstruction = 0;
            }
        }
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) == true){
            for (int y = 0; y < LIGNES; y++) {
                for (int x = 0; x < COLONNES; x++) {
                    if (GetMouseX() % 20 != 0 && GetMouseY() % 20 != 0 && GetMouseX() != 0 && GetMouseY() != 0) {
                        if (GetMouseX() > tabCase[x][y].x - (TUILE / 2) &&
                            GetMouseY() > tabCase[x][y].y - (TUILE / 2) &&
                            GetMouseX() < tabCase[x][y].x + (TUILE / 2) &&
                            GetMouseY() < tabCase[x][y].y + (TUILE / 2)) {
                            niveau = 0;
                            if(categorieConstruction==0 && tabCase[x][y].construction.type == 0) {
                                if(compteEnBanque >= COUT_ROUTE) {
                                    route(tabCase, x, y, &(compteur.nbRues));
                                    /*for (int y = 0; y < LIGNES; y++) {
                                        for (int x = 0; x < COLONNES; x++) {
                                            printf("%d\n", tabCase[x][y].construction.identite);
                                        }
                                    }*/
                                    compteEnBanque = compteEnBanque - COUT_ROUTE;
                                }
                                else {
                                    printf("Vous n'avez pas assez d'argent\n");
                                }
                            }


                            if(categorieConstruction==1 && tabCase[x][y].construction.type == 0) {
                                if(compteEnBanque >= COUT_TERRAIN_VAGUE) {
                                    habitation(tabCase, x, y, &(compteur.nbHab));
                                    compteEnBanque = compteEnBanque - COUT_TERRAIN_VAGUE;
                                }
                                else{
                                    printf("Vous n'avez pas assez d'argent\n");
                                }
                            }

                            if(categorieConstruction==2 && tabCase[x][y].construction.type == 0) {
                                if (compteEnBanque >= COUT_CHATEAU_DEAU){
                                    batiment(tabCase, x, y, &(compteur.nbUsines), 3);
                                    compteEnBanque = compteEnBanque - COUT_CHATEAU_DEAU;
                                }
                                else{
                                    printf("Vous n'avez pas assez d'argent\n");
                                }
                            }

                            if(categorieConstruction==3 && tabCase[x][y].construction.type == 0) {
                                if (compteEnBanque >= COUT_CENTRAL){
                                    batiment(tabCase, x, y, &(compteur.nbChateauO), 2);
                                    compteEnBanque = compteEnBanque - COUT_CENTRAL;
                                }
                                else{
                                    printf("Vous n'avez pas assez d'argent\n");
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int y = 0; y < LIGNES; y++) {
            for (int x = 0; x < COLONNES; x++) {
                if (tabCase[x][y].construction.type == 1) {
                    if (niveau == 0) {
                        DrawRectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                      TUILE, TUILE,
                                      WHITE);
                    }
                    if (niveau == 1) {
                        DrawRectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,TUILE, TUILE,BLUE);
                    }

                    if (niveau == 2) {
                        DrawRectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,TUILE, TUILE,YELLOW);
                    }

                }
                if (tabCase[x][y].construction.type == 5) {
                    DrawRectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,  TUILE, TUILE,
                                  GREEN);
                }
                if (tabCase[x][y].construction.type == 3) {
                    DrawRectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,  TUILE, TUILE,RED);
                }
                if (tabCase[x][y].construction.type == 2) {
                    DrawRectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,  TUILE, TUILE,PURPLE);
                }
            }
        }
        for(int y=0; y<=35; y++){
            for(int x = 0; x<=45; x++) {
                DrawLine(x * TUILE, 0, x * TUILE, TUILE * 35, WHITE);
            }
            DrawLine(0, y * TUILE, TUILE * 45, y * TUILE, WHITE);
        }
        /*int hauteur = 30;
        int largeur = 52;
        for (int y = 0; y < LIGNES; y++) {
            for (int x = 0; x < COLONNES; x++) {
                DrawRectangleLines((hauteur/2 * y) + (hauteur/2 * x), (largeur/2 * y) + (largeur/2 * x), WHITE);
            }
        }*/
        EndDrawing();

    }
    return 0;
}
