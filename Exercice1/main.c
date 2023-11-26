#include "stack.h"

int main() {
    stack_t p;
    int val, choice;

    init_stack_array(&p); // Initialisation de la pile statique
    printf("Pile sous forme de Tableau.\n\n\n");

    while (1) {
        printf("\n---------------------------------------------------\n");
        printf("\nMenu:\n\n");
        printf("1. Ajouter une valeur\n");
        printf("2. Enlever la dernière valeur\n");
        printf("3. Tout afficher\n");
        printf("4. Tout supprimer\n");
        printf("5. Quitter\n\n");
        printf("Choisissez une option: ");
        scanf("%d", &choice);
        printf("\n---------------------------------------------------\n\n");

        switch (choice) {
            case 1:
                printf("Entrez une valeur à ajouter: ");
                scanf("%d", &val);
                if (push_stack_array(&p, val) == -1) {
                    printf("Erreur : La pile est pleine.\n");
                }
                break;
            case 2:
                if (pop_stack_array(&p, &val) == 0) {
                    printf("Valeur enlevée: %d\n", val);
                } else {
                    printf("La pile est vide.\n");
                }
                break;
            case 3:
                display_stack_array(&p);
                break;
            case 4:
                init_stack_array(&p); // Réinitialise la pile
                printf("La pile a été réinitialisée.\n");
                break;
            case 5:
                printf("Fin du programme.\n");
                return 0;
            default:
                printf("Option invalide.\n");
        }
    }

    return 0;
}
