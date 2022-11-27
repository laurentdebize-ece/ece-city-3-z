//
// Created by Ilayda Kocer on 04/11/2022.
//

#include "bibliotheque.h"

void choixModeJeu(int* modeActuel, int* mode, float* tempsDepart, int* jeuEnCour){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) == true) {
        //Rectangle rectangle = {256, 300, 512, 80};
        //if (CheckCollisionPointRec(GetMousePosition(), rectangle)) {}

        switch (*modeActuel) {
            case RULES : {
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    *modeActuel = MENU;
                }
                break;
            }
            case TEAM : {
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    *modeActuel = MENU;
                }
                break;
            }
            case MODE : {
                if (GetMouseX() > 300 && GetMouseY() > 300 && GetMouseX() < 700 && GetMouseY() < 600) {
                    *mode = 1;  ///MODE CAPITALISTE
                    DrawText("MODE CHOISI : CAPITALISTE", 400, 400, 30, BLACK);
                } else if (GetMouseX() > 800 && GetMouseY() > 300 && GetMouseX() < 1200 &&
                           GetMouseY() < 600) {
                    *mode = 2;  ///MODE COMMUNISTE
                    DrawText("MODE CHOISI : COMMUNISTE", 400, 400, 30, BLACK);
                }
                if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
                    *modeActuel = MENU;
                }
                break;
            }
            case MENU : {
                if (GetMouseX() > 556 && GetMouseY > 300 && GetMouseX() < 1078 && GetMouseY() < 380) {
                    *modeActuel = PLAY;
                    *tempsDepart = GetTime();
                    *jeuEnCour = 1;
                } else if (GetMouseX() > 556 && GetMouseY > 420 && GetMouseX() < 1078 &&
                           GetMouseY() < 480) {
                    *modeActuel = RULES;

                } else if (GetMouseX() > 556 && GetMouseY > 500 && GetMouseX() < 1078 &&
                           GetMouseY() < 580) {
                    *modeActuel = TEAM;
                } else if (GetMouseX() > 556 && GetMouseY > 620 && GetMouseX() < 1078 &&
                           GetMouseY() < 680) {
                    *modeActuel = MODE;
                }
                break;
            }
        }
    }
}

void affichageMenu(Texture2D fontMenu){
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
    if (GetMouseX() > 556 && GetMouseY() > 300 && GetMouseX() < 1078 && GetMouseY() < 380) {
        DrawRectangle(556, 300, 512, 80, (Color) {150, 150, 150, 115});
    } else if (GetMouseX() > 556 && GetMouseY() > 420 && GetMouseX() < 1078 && GetMouseY() < 480) {
        DrawRectangle(556, 400, 512, 80, (Color) {150, 150, 150, 115});
    } else if (GetMouseX() > 556 && GetMouseY() > 500 && GetMouseX() < 1078 && GetMouseY() < 580) {
        DrawRectangle(556, 500, 512, 80, (Color) {150, 150, 150, 115});
    } else if (GetMouseX() > 556 && GetMouseY() > 600 && GetMouseX() < 1078 && GetMouseY() < 680) {
        DrawRectangle(556, 600, 512, 80, (Color) {150, 150, 150, 115});
    }
}

void affichageRegles(Texture2D rules){
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
}

void affichageTeam(Texture2D team){
    DrawTexturePro(team,
                   (Rectangle) {.x = 0, .y = 0, .width = team.width, .height =  team.height},
                   (Rectangle) {260, 0, .width = 1000, .height = 800}, (Vector2) {0, 0}, 0, WHITE);

    ///FLECHES RETOUR
    DrawRectangle(50, 50, 140, 90, (Color) {87, 213, 241, 180});
    DrawText("RETURN", 55, 75, 30, (Color) {0, 0, 0, 255});

    ///On fait surbriller le rectangle sur lequelle se trouve la souris
    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
        DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
    }
}

void affichageMode(Texture2D capitaliste, Texture2D communiste){
    DrawTexturePro(capitaliste,
                   (Rectangle) {.x = 0, .y = 0, .width = capitaliste.width, .height =  capitaliste.height},
                   (Rectangle) {300, 300, .width = 300, .height = 300}, (Vector2) {0, 0}, 0, WHITE);
    if (GetMouseX() > 300 && GetMouseY() > 300 && GetMouseX() < 700 && GetMouseY() < 600) {
        DrawTexturePro(capitaliste,
                       (Rectangle) {.x = 0, .y = 0, .width = capitaliste.width, .height =  capitaliste.height},
                       (Rectangle) {300, 300, .width = 400, .height = 400}, (Vector2) {0, 0}, 0, WHITE);
    }
    DrawTexturePro(communiste,
                   (Rectangle) {.x = 0, .y = 0, .width = communiste.width, .height =  communiste.height},
                   (Rectangle) {800, 300, .width = 300, .height = 300}, (Vector2) {0, 0}, 0, WHITE);
    if (GetMouseX() > 800 && GetMouseY() > 300 && GetMouseX() < 1200 && GetMouseY() < 600) {
        DrawTexturePro(communiste,
                       (Rectangle) {.x = 0, .y = 0, .width = communiste.width, .height =  communiste.height},
                       (Rectangle) {800, 300, .width = 400, .height = 400}, (Vector2) {0, 0}, 0, WHITE);
    }
    DrawText("CHOISISSEZ UN MODE DE JEU :", 400, 50, 40, YELLOW);
    DrawText("MODE CAPITALISTE", 290, 150, 30, YELLOW);
    DrawText("MODE COMMUNISTE", 790, 150, 30, YELLOW);


    ///FLECHES RETOUR
    DrawRectangle(50, 50, 140, 90, (Color) {87, 213, 241, 180});
    DrawText("RETURN", 55, 75, 30, (Color) {0, 0, 0, 255});

    ///On fait surbriller le rectangle sur lequelle se trouve la souris
    if (GetMouseX() > 50 && GetMouseY() > 50 && GetMouseX() < 200 && GetMouseY() < 150) {
        DrawRectangle(50, 50, 140, 90, (Color) {162, 213, 268, 50});
    }
}
