#include "stack.h"

int main() {
    stack_t p;
    int val, choice;

    set_file(&p, "stack.txt"); // Définit le fichier pour la pile
    init_stack_file(&p);      // Initialise la pile

    printf("Pile sous forme de fichier.\n\n\n");
    while (1)
    {
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

        switch (choice)
        {
            case 1:
                printf("Entrez une valeur à ajouter: ");
                scanf("%d", &val);
                push_stack_file(&p, val);
                break;
            case 2:
                if (pop_stack_file(&p, &val) == 0)
                {
                    printf("Valeur enlevée: %d\n", val);
                }
                else
                {
                    printf("La pile est vide.\n");
                }
                break;
            case 3:
                display_stack_file(&p);
                break;
            case 4:
                init_stack_file(&p); // Réinitialise la pile
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
