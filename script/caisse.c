#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double b[] = {2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.50, 0.20, 0.05};
char *n[] = {"2000", "1000", "500", "200", "100", "50", "25", "20", "10", "5", "1", "0.50", "0.20", "0.05"};

void monnaie(double r, int stock[]) {
    printf("Rendu:\n");
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        if (r >= b[i] && stock[i] > 0) {
            int nb = r / b[i];
            printf("%d x %s\n", nb > stock[i] ? stock[i] : nb, n[i]);
            r -= (nb > stock[i] ? stock[i] : nb) * b[i];
            stock[i] -= (nb > stock[i] ? stock[i] : nb);
        }
    }
    if (r > 0.005) printf("Rendu impossible.\n");
}

int peut_rendre(double rendu, int stock[]) {
    double temp_rendu = rendu;
    int temp_stock[sizeof(b) / sizeof(b[0])];
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) temp_stock[i] = stock[i];
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++)
        if (temp_rendu >= b[i] && temp_stock[i] > 0)
            temp_rendu -= (temp_rendu / b[i] > temp_stock[i] ? temp_stock[i] : (int)(temp_rendu / b[i])) * b[i];
    return temp_rendu <= 0.005;
}

void remplir(int stock[]) {
    printf("Remplissage:\n");
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        int ajout;
        printf("Nb %s: ", n[i]);
        scanf("%d", &ajout);
        stock[i] += ajout;
    }
    printf("Caisse remplie.\n");
}

int main() {
    srand(time(0));
    int stock[] = {2, 2, 2, 5, 5, 10, 10, 10, 15, 15, 20, 20, 20, 20};
    int choix;
    double a, p;
    int continuer = 1;

    printf("Stock initial:\n");
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) 
    	printf("%s: %d\n", n[i], stock[i]);

    while (continuer) {
        printf("\n A payer: %.2f Rs\nDonné: RS", (a = (rand() % 50000) / 100.0));
        scanf("%lf", &p);
        if (p != 1) {
            printf("Erreur saisie.\n");
            while (getchar() != '\n');
            continue;
        }

        if (p >= a) {
            if (p > a) {
                if (peut_rendre(p - a, stock)) {
                    monnaie(p - a, stock);
                } else {
                    printf("Rendu impossible.\n");
                    printf("1 Fermer 2 Remplir Choix: ");
                    if (scanf("%d", &choix) == 1) {
                        continuer = 0;
                    } else if (choix == 2) {
                        remplir(stock);
                    }
                }
            } else {
                printf("Pas de monnaie à rendre.\n");
            }
        } else {
            printf("Insuffisant!\n");
        }

        printf("Stock après:\n");
        for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) 
        	printf("%s: %d\n", n[i], stock[i]);
    }

    printf("\nFin.\n");
    return 0;
}
