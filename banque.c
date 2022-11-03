
#include "graphe.h"
#include "banque.h"
void payerTaxebanque(int * compteEnBanque, int NbrHabitant, int compteur){
    if (compteur %15==0){
        compteEnBanque = compteEnBanque + NbrHabitant * TAXE;
    }
}

void payerBanque(BATIMENT batiment);

