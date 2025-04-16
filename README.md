# caisse_enregistreuse
Ce programme en C est une mode de paiement et affiche la monnaie à rendre à l'utilisateur, ainsi que le détail la monnaie et du stock dans la caisse.

## Fonctionnement du Programme

Génération Aléatoire du Montant à Payer :
Au démarrage, le programme génère aléatoirement un montant à payer entre 0 et 5000.00 roupies mauriciennes (Rs). Ce montant est affiché à l'utilisateur.

Demande de l'Argent Donné par l'Utilisateur :
    * Le programme invite l'utilisateur à entrer le montant d'argent qu'il donne pour payer.
    * Il vérifie si le montant donné est suffisant par rapport au montant à payer.
    * Si le montant donné est inférieur, un message "Montant insuffisant!" est affiché et l'utilisateur est invité à entrer un montant plus élevé.
    * Cette étape se répète jusqu'à ce que l'utilisateur fournisse un montant égal ou supérieur au montant à payer.

Calcul et Affichage de la Monnaie à Rendre :
    * Si le montant donné est supérieur au montant à payer, le programme calcule la différence (la monnaie à rendre).
    * La fonction `monnaie` est appelée pour afficher le montant total à rendre et le détail des coupures et pièces nécessaires.
    * Si le montant donné est exactement égal au montant à payer, le programme affiche le message "Pas de monnaie à rendre."

Détail de la Monnaie à Rendre (Fonction `monnaie`) :
    * La fonction `monnaie` prend en entrée le montant à rendre.
    * Elle utilise deux tableaux :
        * `b`: Un tableau de `double` contenant les valeurs des différentes coupures et pièces disponibles (2000, 1000, 500, 200, 100, 50, 25, 20, 10, 5, 1, 0.50, 0.20, 0.05).
        * `n`: Un tableau de chaînes de caractères (`char *`) contenant les noms correspondants de ces coupures et pièces ("Rs2000", "Rs1000", etc.).
    * La fonction itère à travers ces tableaux. Pour chaque coupure/pièce :
        * Elle vérifie si le montant à rendre est supérieur ou égal à la valeur de la coupure/pièce courante.
        * Si c'est le cas, elle calcule le nombre de fois que cette coupure/pièce peut être utilisée pour rendre la monnaie.
        * Elle affiche le nombre et le nom de la coupure/pièce (par exemple, "2 x Rs500").
        * Elle soustrait la valeur totale de ces coupures/pièces du montant à rendre.
        * La boucle s'arrête lorsque le montant à rendre devient nul ou négatif.

