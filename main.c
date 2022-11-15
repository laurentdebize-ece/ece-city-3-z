
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int NbrHabitant = 0;
    COMPTEUR compteur;
    int compteEnBanque = 999999999;

    FILE *ifs = fopen("../map.txt", "r");
    VECTEUR mouseIso;
    VECTEUR mouseIsoClic;
    
    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne
   
    
    CASE **tabCase = malloc((COLONNES) * sizeof(CASE *));
    for (int i = 0; i < COLONNES; i++) {
        tabCase[i] = malloc((LIGNES) * sizeof(CASE));
    }

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            tabCase[x][y].construction.type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague

        }
    }

    InitWindow(LARGEUR, HAUTEUR, "Projet");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Texture2D Tiles =  LoadTexture("../tiles/tiles.png");
    Texture2D Routes =  LoadTexture("../tiles/route.png");

    Image img =  LoadImage("../tilesTest.png");

    while (!WindowShouldClose()) {

        BeginDrawing();

        coordSourisIso(&mouseIso, img);
        affichageGrille(mouseIso, Tiles);
        affichageRoute(Routes, tabCase, niveau);
        affichageTerrain(Tiles, tabCase);
        affichageBattiment(Tiles, tabCase);

        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_SPACE) == true) {
            if (niveau != 2) {
                niveau++;
            } else {
                niveau = 0;
            }
        }
        if (IsKeyPressed(KEY_RIGHT) == true) {
            if (categorieConstruction != 4) {
                categorieConstruction++;
            } else {
                categorieConstruction = 0;
            }
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) == true) {
            if(mouseIso.x>=0 && mouseIso.y>=0 && mouseIso.x<COLONNES && mouseIso.y<LIGNES) {
                coordSourisIso(&mouseIsoClic, img);
                niveau = 0;
                if (categorieConstruction == 0 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_ROUTE) {
                        route(tabCase, mouseIsoClic.x, mouseIsoClic.y, &(compteur.nbRues));
                        compteEnBanque = compteEnBanque - COUT_ROUTE;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }


                if (categorieConstruction == 1 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_TERRAIN_VAGUE) {
                        habitation(tabCase, mouseIso.x, mouseIso.y, &(compteur.nbHab));
                        compteEnBanque = compteEnBanque - COUT_TERRAIN_VAGUE;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }

                if (categorieConstruction == 2 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_CHATEAU_DEAU) {
                        batiment(tabCase, mouseIso.x, mouseIso.y, &(compteur.nbUsines), 3);
                        compteEnBanque = compteEnBanque - COUT_CHATEAU_DEAU;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }

                if (categorieConstruction == 3 &&
                    tabCase[mouseIso.x][mouseIso.y].construction.type == 0) {
                    if (compteEnBanque >= COUT_CENTRAL) {
                        batiment(tabCase, mouseIso.x, mouseIso.y, &(compteur.nbChateauO), 2);
                        compteEnBanque = compteEnBanque - COUT_CENTRAL;
                    } else {
                        printf("Vous n'avez pas assez d'argent\n");
                    }
                }
            }
        }


        EndDrawing();

    }
    return 0;
}
