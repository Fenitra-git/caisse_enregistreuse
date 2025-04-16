#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));
    double montant_a_payer = (double)(rand() % 500000) / 100.0;
    double montant_paye;

    printf("Montant à payer: %.2f Rs\n", montant_a_payer);
    
    do {
        printf("Entrez le montant que vous donnez pour payer: ");
        scanf("%lf", &montant_paye);
        
        if(montant_paye < montant_a_payer) {
            printf("Montant insuffisant! Il manque %.2f Rs.\n", montant_a_payer - montant_paye);
        }
    } while(montant_paye < montant_a_payer);
    
    printf("Merci pour votre paiement de %.2f Rs.\n", montant_paye);
    
    if(montant_paye > montant_a_payer) {
        printf("Monnaie à rendre: %.2f Rs\n", montant_a_payer - montant_paye);
    } else {
        printf("Paiement exact, pas de monnaie à rendre.\n");
    }
    
    return 0;
}
