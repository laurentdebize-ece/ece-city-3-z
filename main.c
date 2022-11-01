#include "bibliotheque.h"

int main() {

    Graphe * g=lire_graphe("./fichierGrapheTab2D.txt");

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_EVENT event = {0};
    int fini = 0;
    int niveau = 1;

    typedef struct{
        int route, habitation, usine, chateauEau, caserne;
    }CONSTRUCTION;
    typedef struct{
        float x, y;
        CONSTRUCTION construction;
    }CASE;


    int categorieConstruction = 0; // 0:route 1:habotation 2:usine 3:chateauEau 4:caserne

    CASE ** tabCase = malloc((COLONNES)*sizeof(CASE*));
    for(int i = 0; i<COLONNES; i++){
        tabCase[i] = malloc((LIGNES)*sizeof(CASE));
    }

    for(int x=0; x<COLONNES; x++) {
        for (int y = 0; y < LIGNES; y++) {
            tabCase[x][y].x = TUILE/2+x*TUILE;
            tabCase[x][y].y = TUILE/2+y*TUILE;
            tabCase[x][y].construction.route=0;
            tabCase[x][y].construction.habitation=0;
            tabCase[x][y].construction.usine=0;
            tabCase[x][y].construction.chateauEau=0;
            tabCase[x][y].construction.caserne=0;
        }
    }

    allegroCreation(&display, &queue, &timer);
    al_start_timer(timer);

    while (!fini) {
        al_wait_for_event(queue, &event);
        switch (event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fini = 1;
                break;

            case ALLEGRO_EVENT_KEY_UP:

                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_SPACE : {
                        if(niveau!=2){
                            niveau++;
                        }
                        else{
                            niveau=0;
                        }
                        break;
                    }
                    case ALLEGRO_KEY_RIGHT : {
                        if(categorieConstruction!=4) {
                            categorieConstruction++;
                        }
                        else{
                            categorieConstruction=0;
                        }
                        break;
                    }
                }

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: {

                for(int x=0; x<COLONNES; x++) {
                    for (int y = 0; y < LIGNES; y++) {
                        if (event.mouse.x % 32 != 0 && event.mouse.y % 32 != 0 && event.mouse.x != 0 && event.mouse.y != 0) {
                            if (event.mouse.x > tabCase[x][y].x - (TUILE / 2) &&
                                event.mouse.y > tabCase[x][y].y - (TUILE / 2) &&
                                event.mouse.x < tabCase[x][y].x + (TUILE / 2) &&
                                event.mouse.y < tabCase[x][y].y + (TUILE / 2)) {
                                niveau = 0;
                                if(categorieConstruction==0) {
                                    tabCase[x][y].construction.route = 1;
                                }
                            }
                        }
                    }
                }
                break;
            }
            case ALLEGRO_EVENT_TIMER: {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                for(int x=0; x<COLONNES; x++) {
                    for (int y = 0; y < LIGNES; y++) {
                        if(tabCase[x][y].construction.route == 1){
                            if(niveau==0) {
                                al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                                         tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                                         al_map_rgb(255, 255, 255));
                            }
                            if(niveau==1) {al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                                                    tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                                                    al_map_rgb(0, 0, 255));}
                            if(niveau==2) {al_draw_filled_rectangle(tabCase[x][y].x - TUILE / 2, tabCase[x][y].y - TUILE / 2,
                                                                    tabCase[x][y].x + TUILE / 2, tabCase[x][y].y + TUILE / 2,
                                                                    al_map_rgb(255, 255, 0));}
                        }
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
