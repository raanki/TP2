#include "stack.h"

/**
 * Initialise la pile basée sur un tableau statique. Réinitialise l'indice du sommet à -1,
 * indiquant que la pile est vide.
 * 
 * @param s Un pointeur vers la structure de la pile.
 */
void init_stack_array(stack_t *s) 
{
    s->top = -1;
}

/**
 * Ajoute une nouvelle valeur au sommet de la pile basée sur un tableau statique.
 * Vérifie si la pile n'est pas pleine avant d'ajouter la valeur.
 * 
 * @param s Un pointeur vers la structure de la pile.
 * @param val La valeur à ajouter à la pile.
 * @return 0 en cas de succès, -1 si la pile est pleine.
 */
int push_stack_array(stack_t *s, int val) 
{
    if (s->top >= MAX - 1) 
    {
        return -1; // La pile est pleine
    }
    else 
    {
        s->tab[++(s->top)] = val;
        return 0; // Succès
    }
}

/**
 * Supprime et récupère la valeur du sommet de la pile basée sur un tableau statique.
 * Vérifie si la pile n'est pas vide avant de retirer la valeur.
 * 
 * @param s Un pointeur vers la structure de la pile.
 * @param val Un pointeur vers un entier où stocker la valeur supprimée.
 * @return 0 si une valeur a été supprimée, -1 si la pile est vide.
 */
int pop_stack_array(stack_t *s, int *val) 
{
    if (s->top == -1) 
    {
        return -1; // La pile est vide
    }
    else 
    {
        *val = s->tab[(s->top)--];
        return 0; // Succès
    }
}

/**
 * Affiche le contenu de la pile basée sur un tableau statique.
 * Parcourt le tableau de la fin au début pour afficher les valeurs.
 * 
 * @param s Un pointeur vers la structure de la pile.
 */
void display_stack_array(stack_t *s) 
{
    if (s->top == -1) 
    {
        printf("La pile est vide\n");
    } 
    else 
    {
        printf("Contenu de la pile:\n");
        for (int i = s->top; i >= 0; i--) 
        {
            printf("%d\n", s->tab[i]);
        }
    }
}
