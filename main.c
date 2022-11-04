#include "bibliotheque.h"

int main() {

    FILE * ifs = fopen("map.txt","r");

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event = {0};

    int fini = 0;
    int niveau = 0;
    int construction;
    int NbrHabitant = 0;
    COMPTEUR compteur;
    float rotationX = 1;
    float rotationY = 1.5f;
    int compteEnBanque = 999999999;


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

    allegroCreation(&display, &queue, &timer);
    al_start_timer(timer);

    while (!fini) {

        al_wait_for_event(queue, &event);
        switch (event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE: {
                /*FILE * n = fopen("map.txt","w+");
                for (int y = 0; y < LIGNES; y++) {
                    for (int x = 0; x < COLONNES; x++) {
                        fprintf(n, "%d ",tabCase[x][y].construction.type);
                    }
                    fputs("\n",n);
                }*/
                fini = 1;
                break;
            }
            case ALLEGRO_EVENT_KEY_UP: {

                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_SPACE : {
                        if (niveau != 2) {
                            niveau++;
                        } else {
                            niveau = 0;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_RIGHT : {
                        if (categorieConstruction != 4) {
                            categorieConstruction++;
                        } else {
                            categorieConstruction = 0;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_DOWN : {

                        break;
                    }
                    case ALLEGRO_KEY_UP : {

                        break;
                    }

                }
            }

            case ALLEGRO_EVENT_MOUSE_AXES: {
                for (int y = 0; y < LIGNES; y++) {
                    for (int x = 0; x < COLONNES; x++) {
                        if (event.mouse.x % 32 != 0 && event.mouse.y % 32 != 0 && event.mouse.x != 0 && event.mouse.y != 0) {
                            if (event.mouse.x > tabCase[x][y].x - (TUILE / 2) &&
                                event.mouse.y > tabCase[x][y].y - (TUILE / 2) &&
                                event.mouse.x < tabCase[x][y].x + (TUILE / 2) &&
                                event.mouse.y < tabCase[x][y].y + (TUILE / 2)) {

                                if(categorieConstruction==0 && tabCase[x][y].construction.type == 0) {
                                    routeApercu(tabCase, x, y);
                                }
                                if(categorieConstruction==1 && tabCase[x][y].construction.type == 0) {
                                    habitationApercu(tabCase, x, y);
                                }
                                if(categorieConstruction==2 && tabCase[x][y].construction.type == 0) {
                                    batimentApercu(tabCase, x, y,3);
                                }
                                if(categorieConstruction==3 && tabCase[x][y].construction.type == 0) {
                                    batimentApercu(tabCase, x, y,2);
                                }
                            }
                            else{
                                tabCase[x][y].construction.apercu = 0;
                            }
                        }
                    }
                }
                break;
            }

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {

                for (int y = 0; y < LIGNES; y++) {
                    for (int x = 0; x < COLONNES; x++) {
                        if (event.mouse.x % 32 != 0 && event.mouse.y % 32 != 0 && event.mouse.x != 0 && event.mouse.y != 0) {
                            if (event.mouse.x > tabCase[x][y].x - (TUILE / 2) &&
                                event.mouse.y > tabCase[x][y].y - (TUILE / 2) &&
                                event.mouse.x < tabCase[x][y].x + (TUILE / 2) &&
                                event.mouse.y < tabCase[x][y].y + (TUILE / 2)) {
                                niveau = 0;

                                if(categorieConstruction==0 && tabCase[x][y].construction.type == 0) {
                                    if(compteEnBanque >= COUT_ROUTE) {
                                        route(tabCase, x, y, &(compteur.nbRues));
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
                break;
            }
            case ALLEGRO_EVENT_TIMER: {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                for (int y = 0; y < LIGNES; y++) {
                    for (int x = 0; x < COLONNES; x++) {
                        affichageConstruction(tabCase, x, y, niveau);
                        apercuConstruction(tabCase, x, y);
                    }
                }
            }
        }
        for(int i=0; i<=35; i++){
            for(int y = 0; y<=45; y++) {
                al_draw_line(y * TUILE, 0, y * TUILE, TUILE * 35, al_map_rgb(255, 255, 255), 0);
            }
            al_draw_line(0, i * TUILE, TUILE * 45, i * TUILE, al_map_rgb(255, 255, 255), 0);
        }
        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_timer(timer);
    return 0;
}
