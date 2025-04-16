#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void monnaie(double r) {
    double b[] = {2000,1000,500,200,100,50,25,20,10,5,1,0.50,0.20,0.05};
    char *n[] = {"Rs2000","Rs1000","Rs500","Rs200","Rs100","Rs50","Rs25","Rs20","Rs10","Rs5","Rs1","50 sous","20 sous","5 sous"};
    for(int i = 0; i < 14; i++) {
        if(r <= 0)
            break;
        if(r >= b[i]) {
            int nb = r / b[i];
            printf("%d x %s\n", nb, n[i]);
            r -= nb * b[i];
        }
    }
}

int main() {
    srand(time(0));
    double a = (rand() % 500000) / 100.0;
    double p;
    printf("Montant à payer: %.2f Rs\n", a);
    do {
        printf("Argent donné: RS");
        scanf("%lf", &p);
        if(p < a) {
            printf("Montant insuffisant!\n");
        }
    } while(p < a);
    
    if(p > a) {
        monnaie(p - a);
    }
    return 0;
}
