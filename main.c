
#include "bibliotheque.h"

int main() {
    int niveau = 0;
    int construction;
    int ordre;
    int mode = 0;
    int detruire = 0;
    int rotationBattiment;
    COMPTEUR compteur;

    compteur.nbChateauO=0;
    compteur.nbHab=0;
    compteur.nbRues=0;
    compteur.nbUsines=0;
    int compteEnBanque = 999999999;
    float tempsEcoule = 0;
    float tempsDepart;
    int jeuEnCour = 0;
    enum gameMode modeActuel = MENU;



    FILE *ifs = fopen("../map.txt", "r");
    FILE *ifs2 = fopen("../ordreConstruction.txt", "r");
    VECTEUR mouseIso;
    ECECITY *JEU = iniJeu();
    JEU->compteur.nbChateauO=0;
    JEU->compteur.nbHab=0;
    JEU->compteur.nbRues=0;
    JEU->compteur.nbUsines=0;


    int categorieConstruction = 0; // 0:route 1:habitation 2:usine 3:chateauEau 4:caserne


    JEU->G->tabCase = malloc((COLONNES) * sizeof(CASE *));
    for (int i = 0; i < COLONNES; i++) {
        JEU->G->tabCase[i] = malloc((LIGNES) * sizeof(CASE));
    }

    for (int y = 0; y < LIGNES; y++) {
        for (int x = 0; x < COLONNES; x++) {
            fscanf(ifs, "%d", &construction);
            fscanf(ifs2, "%d", &ordre);
            JEU->G->tabCase[x][y].type = construction; // 0: rien 1:route 2:Usine 3:chateauEau 4:caserne 5:terrain vague
            JEU->G->tabCase[x][y].identite = ordre;
            initialisationOrdre(JEU->G->tabCase, ordre, x, y,&JEU->compteur);
        }
    }

    InitWindow(1600, 800, "Projet");
    SetWindowState(FLAG_WINDOW_RESIZABLE);

    Texture2D Tiles =  LoadTexture("../tiles/tiles.png");
    Texture2D Routes =  LoadTexture("../tiles/route.png");

    Image img =  LoadImage("../tilesTest.png");

    Texture2D team = LoadTexture("../Bitmap/Profile.png");
    Texture2D fontMenu = LoadTexture("../Bitmap/font.png");
    Texture2D rules = LoadTexture("../Bitmap/rules.png");
    Texture2D capitaliste = LoadTexture("../Bitmap/capitaliste.png");
    Texture communiste = LoadTexture("../Bitmap/communiste.png");



    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);



        switch (modeActuel){
            case MENU : {
                DrawTexturePro(fontMenu,
                               (Rectangle) {.x = 0, .y = 0, .width = fontMenu.width, .height =  fontMenu.height},
                               (Rectangle) {300, 0, .width = 1000, .height = 800}, (Vector2) {0, 0}, 0, WHITE);

                ///DESSINER LES 3 RECTANGLES DES MENUS

                DrawRectangle(556, 300, 512, 80, (Color) {255, 255, 0, 255});
                DrawRectangle(556, 400, 512, 80, (Color) {255, 255, 0, 255});
                DrawRectangle(556, 500, 512, 80, (Color) {255, 255, 0, 255});
                DrawRectangle(556, 600, 512, 80, (Color) {255, 255, 0, 255});

                DrawText("PLAY", 750, 318, 50, (Color) {0, 150, 0, 250});
                DrawText("RULES", 750, 418, 50, (Color) {0, 150, 0, 250});
                DrawText("TEAM", 750, 518, 50, (Color) {0, 150, 0, 250});
                DrawText("MODE", 750, 618, 50, (Color) {0, 150, 0, 250});


                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX() > 556 && GetMouseY > 300 && GetMouseX() < 778 && GetMouseY() < 380) {
                    DrawRectangle(556, 300, 512, 80, (Color) {150, 150, 150, 115});
                } else if (GetMouseX() > 556 && GetMouseY > 420 && GetMouseX() < 778 && GetMouseY() < 480) {
                    DrawRectangle(556, 400, 512, 80, (Color) {150, 150, 150, 115});
                } else if (GetMouseX() > 556 && GetMouseY > 500 && GetMouseX() < 778 && GetMouseY() < 580) {
                    DrawRectangle(556, 500, 512, 80, (Color) {150, 150, 150, 115});
                } else if (GetMouseX() > 556 && GetMouseY > 600 && GetMouseX() < 778 && GetMouseY() < 680) {
                    DrawRectangle(556, 600, 512, 80, (Color) {150, 150, 150, 115});
                }
                break;
            }
            case RULES : {
                DrawTexturePro(rules,
                               (Rectangle) {.x = 0, .y = 0, .width = rules.width, .height =  rules.height},
                               (Rectangle) {260, 0, .width = 1000, .height = 800}, (Vector2) {0, 0}, 0, WHITE);


                ///FLECHES RETOUR
                DrawRectangle(50, 50, 140, 90, (Color) {87, 213, 241, 180});
                DrawText("RETURN", 55, 75, 30, (Color) {0, 0, 0, 255});

                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
                }
                break;
            }
            case TEAM : {
                DrawTexturePro(team,
                               (Rectangle) {.x = 0, .y = 0, .width = team.width, .height =  team.height},
                               (Rectangle) {260, 0, .width = 1000, .height = 800}, (Vector2) {0, 0}, 0, WHITE);

                ///FLECHES RETOUR
                DrawRectangle(50, 50, 140, 90, (Color){87, 213, 241, 180});
                DrawText("RETURN", 55, 75, 30, (Color){0, 0, 0, 255});

                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX()>50 && GetMouseY()>50 && GetMouseX()< 200 && GetMouseY()<150) {
                    DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
                }
                break;
            }
            case MODE : {
                //DrawTexture(capitaliste, 100, 100, WHITE);
                //DrawTexture(communiste, 600, 100, WHITE);
                DrawTexturePro(capitaliste,
                               (Rectangle) {.x = 0, .y = 0, .width = capitaliste.width, .height =  capitaliste.height},
                               (Rectangle) {300, 300, .width = 300, .height = 300}, (Vector2) {0, 0}, 0, WHITE);
                if (GetMouseX() > 300 && GetMouseY()>300 && GetMouseX()<700 && GetMouseY()<600){
                    DrawTexturePro(capitaliste,
                                   (Rectangle) {.x = 0, .y = 0, .width = capitaliste.width, .height =  capitaliste.height},
                                   (Rectangle) {300, 300, .width = 400, .height = 400}, (Vector2) {0, 0}, 0, WHITE);
                }
                DrawTexturePro(communiste,
                               (Rectangle) {.x = 0, .y = 0, .width = communiste.width, .height =  communiste.height},
                               (Rectangle) {800, 300, .width = 300, .height = 300}, (Vector2) {0, 0}, 0, WHITE);
                if (GetMouseX() >800 && GetMouseY()>300 && GetMouseX()<1200 && GetMouseY()<600){
                    DrawTexturePro(communiste,
                                   (Rectangle) {.x = 0, .y = 0, .width = communiste.width, .height =  communiste.height},
                                   (Rectangle) {800, 300, .width = 400, .height = 400}, (Vector2) {0, 0}, 0, WHITE);
                }
                DrawText("CHOISISSEZ UN MODE DE JEU :", 400, 50, 40, BLACK);
                DrawText("MODE CAPITALISTE", 290, 150, 30, BLACK);
                DrawText("MODE COMMUNISTE", 790, 150, 30, BLACK);


                ///FLECHES RETOUR
                DrawRectangle(50, 50, 140, 90, (Color) {87, 213, 241, 180});
                DrawText("RETURN", 55, 75, 30, (Color) {0, 0, 0, 255});

                ///On fait surbriller le rectangle sur lequelle se trouve la souris
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
                }

                break;
            }
            case PLAY:

                coordSourisIso(&mouseIso, img);
                affichageGrille(mouseIso, Tiles);
                affichageRoute(Routes, JEU->G->tabCase, niveau);
                affichageTerrain(Tiles, JEU->G->tabCase);
                affichageBattiment(Tiles, JEU->G->tabCase);
                evolutionBat(JEU->G->tabCase, &tempsEcoule, tempsDepart, JEU);
                if (jeuEnCour == 1){

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
                    if (IsKeyPressed(KEY_UP) == true) {
                        if (rotationBattiment != 1) {
                            rotationBattiment++;
                        } else {
                            rotationBattiment = 0;
                        }
                    }
                    if (IsKeyPressed(KEY_KP_1) == true) {
                        if (detruire != 1) {
                            detruire++;
                        } else {
                            detruire = 0;
                        }
                    }

                    if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_S))) {
                        enregistrerPartie(JEU->G->tabCase);
                    }
                    if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_KP_0))) {
                        recommencerPartie(JEU->G->tabCase,&JEU->compteur);
                    }
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                        constructionSouris(&mouseIso, categorieConstruction, &niveau, JEU->G->tabCase, &compteEnBanque, &JEU->compteur, rotationBattiment, detruire, JEU);
                        detruireConstruction(&mouseIso,JEU->G->tabCase,&JEU->compteur,rotationBattiment,detruire,JEU);
                        printf("nb route: %d\nnb hab: %d\nnb usine: %d\nnb chateauO: %d\n ", JEU->compteur.nbRues,JEU->compteur.nbHab, JEU->compteur.nbUsines, JEU->compteur.nbChateauO);
                        //CalculeElec(JEU);
                        //CalculeO(JEU);
                    }
                }else {
                    jeuEnCour = 0;

                }
                break;
        }


        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
            //Rectangle rectangle = {256, 300, 512, 80};
            //if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {}

            switch (modeActuel) {
                case RULES : {
                    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                        modeActuel = MENU;
                    }
                    break;
                }
                case TEAM : {
                    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                        modeActuel = MENU;
                    }
                    break;
                }
                case MODE : {
                    if (GetMouseX() > 300 && GetMouseY()>300 && GetMouseX()<700 && GetMouseY()<600){
                        mode = 1;  ///MODE CAPITALISTE
                        DrawText("MODE CHOISI : CAPITALISTE", 400, 400,30,  BLACK);
                    }else if (GetMouseX() >800 && GetMouseY()>300 && GetMouseX()<1200 && GetMouseY()<600){
                        mode = 2;  ///MODE COMMUNISTE
                        DrawText("MODE CHOISI : COMMUNISTE", 400, 400,30,  BLACK);
                    }
                    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                        modeActuel = MENU;
                    }
                    break;
                }
                case MENU : {
                    if (GetMouseX() > 256 && GetMouseY > 300 && GetMouseX() < 778 && GetMouseY() < 380) {
                        modeActuel = PLAY;
                        tempsDepart = GetTime();
                        jeuEnCour = 1;
                    } else if (GetMouseX() > 256 && GetMouseY > 420 && GetMouseX() < 778 && GetMouseY() < 480) {
                        modeActuel = RULES;

                    } else if (GetMouseX() > 256 && GetMouseY > 500 && GetMouseX() < 778 && GetMouseY() < 580) {
                        modeActuel = TEAM;
                    } else if (GetMouseX() > 256 && GetMouseY > 620 && GetMouseX() < 778 && GetMouseY() < 680) {
                        modeActuel = MODE;
                    }
                    break;
                }

            }
        }













        /* while (!WindowShouldClose()) {

             BeginDrawing();
             ClearBackground(BLACK);


             coordSourisIso(&mouseIso, img);
             affichageGrille(mouseIso, Tiles);
             affichageRoute(Routes, JEU->G->tabCase, niveau);
             affichageTerrain(Tiles, JEU->G->tabCase);
             affichageBattiment(Tiles, JEU->G->tabCase);
             evolutionBat(JEU->G->tabCase, &tempsEcoule, JEU);



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
             if (IsKeyPressed(KEY_UP) == true) {
                 if (rotationBattiment != 1) {
                     rotationBattiment++;
                 } else {
                     rotationBattiment = 0;
                 }
             }
             if (IsKeyPressed(KEY_KP_1) == true) {
                 if (detruire != 1) {
                     detruire++;
                 } else {
                     detruire = 0;
                 }
             }

             if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_S))) {
                 enregistrerPartie(JEU->G->tabCase);
             }
             if ((IsKeyDown(KEY_LEFT_CONTROL)) && (IsKeyPressed(KEY_KP_0))) {
                 recommencerPartie(JEU->G->tabCase,&JEU->compteur);
             }
             if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
                 constructionSouris(&mouseIso, categorieConstruction, &niveau, JEU->G->tabCase, &compteEnBanque, &JEU->compteur, rotationBattiment, detruire, JEU);
                 detruireConstruction(&mouseIso,JEU->G->tabCase,&JEU->compteur,rotationBattiment,detruire,JEU);
                 printf("nb route: %d\nnb hab: %d\nnb usine: %d\nnb chateauO: %d\n ", JEU->compteur.nbRues,JEU->compteur.nbHab, JEU->compteur.nbUsines, JEU->compteur.nbChateauO);
                 //CalculeElec(JEU);
                 //CalculeO(JEU);
             }*/

        EndDrawing();

    }

    UnloadTexture(fontMenu);
    UnloadTexture(team);
    UnloadTexture(rules);
    UnloadTexture(capitaliste);
    UnloadTexture(communiste);
    return 0;
}
