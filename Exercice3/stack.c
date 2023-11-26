#include "stack.h"

/**
 * Initialise la structure de la pile pour utiliser un fichier spécifique pour le stockage.
 * 
 * @param s Un pointeur vers la structure de la pile.
 * @param filename Le nom du fichier à utiliser pour la pile.
 */
void set_file(stack_t *s, char *filename) {
    strncpy(s->filename, filename, MAX_FLNM);
}

/**
 * Initialise la pile basée sur un fichier. Si le fichier existe déjà, il est réécrit.
 * Cette fonction crée un nouveau fichier ou réécrit le fichier existant avec un compteur
 * d'éléments initialisé à 0.
 * 
 * @param s Un pointeur vers la structure de la pile.
 */
void init_stack_file(stack_t *s) {
    FILE *file = fopen(s->filename, "w");
    if (file) {
        fprintf(file, "0\n");  // Écrire 0 pour le nombre d'éléments initialement
        fclose(file);
    }
}

/**
 * Ajoute une valeur à la pile stockée dans un fichier. La fonction met à jour le compteur
 * d'éléments en tête de fichier et ajoute la nouvelle valeur à la fin du fichier.
 * 
 * @param s Un pointeur vers la structure de la pile.
 * @param val La valeur à ajouter à la pile.
 * @return 0 en cas de succès, -1 en cas d'échec.
 */
int push_stack_file(stack_t *s, int val) {
    int count = 0;
    FILE *file = fopen(s->filename, "r+");
    if (file) {
        fscanf(file, "%d", &count);  // Lire le nombre actuel d'éléments
        fseek(file, 0, SEEK_END);    // Aller à la fin du fichier
        fprintf(file, "%d\n", val);  // Ajouter la nouvelle valeur
        fseek(file, 0, SEEK_SET);    // Retourner au début
        fprintf(file, "%d\n", count + 1);  // Mettre à jour le nombre d'éléments
        fclose(file);
        return 0;
    }
    return -1;
}

/**
 * Supprime la dernière valeur de la pile stockée dans un fichier. La fonction lit le
 * compteur d'éléments, copie les éléments (sauf le dernier) dans un fichier temporaire,
 * puis remplace le fichier original par ce fichier temporaire.
 * 
 * @param s Un pointeur vers la structure de la pile.
 * @param val Un pointeur vers un entier où stocker la valeur supprimée.
 * @return 0 si une valeur a été supprimée, -1 si la pile est vide ou en cas d'erreur.
 */
int pop_stack_file(stack_t *s, int *val) {
    int count = 0, temp_val, last_val = 0;
    FILE *file = fopen(s->filename, "r");
    FILE *temp_file = fopen("temp_stack.txt", "w");

    if (!file || !temp_file) {
        if (file) fclose(file);
        if (temp_file) fclose(temp_file);
        return -1;
    }

    fscanf(file, "%d", &count);
    if (count == 0) {
        fclose(file);
        fclose(temp_file);
        remove("temp_stack.txt");
        return -1;  // La pile est vide
    }

    fprintf(temp_file, "%d\n", count - 1);  // Mettre à jour le nombre d'éléments
    for (int i = 0; i < count - 1; i++) {
        fscanf(file, "%d", &temp_val);
        fprintf(temp_file, "%d\n", temp_val);
        last_val = temp_val;
    }

    fclose(file);
    fclose(temp_file);
    remove(s->filename);
    rename("temp_stack.txt", s->filename);

    *val = last_val;
    return 0;
}

/**
 * Affiche le contenu de la pile stockée dans un fichier. La fonction commence par lire
 * le nombre d'éléments à partir du début du fichier, puis affiche chaque élément.
 * 
 * @param s Un pointeur vers la structure de la pile.
 */
void display_stack_file(stack_t *s) {
    int count, val;
    FILE *file = fopen(s->filename, "r");
    if (file) {
        fscanf(file, "%d", &count);
        printf("Contenu de la pile (%d éléments) :\n", count);
        while (fscanf(file, "%d", &val) == 1) {
            printf("%d\n", val);
        }
        fclose(file);
    }
}
