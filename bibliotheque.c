//
// Created by Théophile Dutrey on 01/11/2022.
//

#include "bibliotheque.h"
void allegroCreation(ALLEGRO_DISPLAY** display, ALLEGRO_EVENT_QUEUE** queue, ALLEGRO_TIMER** timer){

    assert(al_init());
    assert(al_init_primitives_addon());
    assert(al_init_image_addon());
    assert(al_install_keyboard());
    assert(al_install_mouse());
    al_init_font_addon();
    assert(al_init_ttf_addon());
    al_install_audio();
    al_init_acodec_addon();

    // Créations (al_create...())
    *display = al_create_display(LARGEUR, HAUTEUR);


    al_set_window_position(*display, 0, 0);
    assert(*display != NULL);
    al_set_window_title(*display, "ECE city");
    *timer = al_create_timer(1.0 / 120.0); // determinera le nombre d'images par seconde (FPS)
    // assert(timer != NULL); // assert pas idéal car on mettrait fin au programme sans
    // avoir pu libérer la fenêtre déjà allouée. Du coup on préfère utiliser un if :
    if (*timer == NULL) {
        al_destroy_display(*display);
        exit(EXIT_FAILURE); // exit(EXIT_FAILURE); // return 1; // return EXIT_FAILURE;
    }
    *queue = al_create_event_queue();
    if (*queue == NULL) {
        al_destroy_display(*display);
        al_destroy_timer(*timer);
        exit(EXIT_FAILURE);
    }
    al_register_event_source(*queue, al_get_display_event_source(*display));
    al_register_event_source(*queue, al_get_timer_event_source(*timer));
    al_register_event_source(*queue, al_get_keyboard_event_source());
    al_register_event_source(*queue, al_get_mouse_event_source());

}
