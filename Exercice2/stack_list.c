#include "stack.h"

/**
 * Initialise la pile basée sur une liste chaînée en définissant le sommet de la pile à NULL.
 * 
 * @param s Un pointeur vers la structure de la pile.
 */
void init_stack_list(stack_t *s) 
{
    s->top = NULL;
}

/**
 * Ajoute une nouvelle valeur au sommet de la pile basée sur une liste chaînée.
 * Crée un nouveau nœud avec la valeur spécifiée et l'ajoute au sommet de la pile.
 * 
 * @param s Un pointeur vers la structure de la pile.
 * @param val La valeur à ajouter à la pile.
 * @return 0 en cas de succès, -1 en cas d'échec d'allocation mémoire.
 */
int push_stack_list(stack_t *s, int val) 
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) 
    {
        return -1; // Échec de l'allocation de mémoire
    }

    new_node->val = val;
    new_node->next = s->top;
    s->top = new_node;

    return 0; // Succès
}

/**
 * Supprime la valeur au sommet de la pile basée sur une liste chaînée.
 * Récupère la valeur du sommet, supprime le nœud correspondant et met à jour le sommet.
 * 
 * @param s Un pointeur vers la structure de la pile.
 * @param val Un pointeur vers un entier où stocker la valeur supprimée.
 * @return 0 si une valeur a été supprimée, -1 si la pile est vide.
 */
int pop_stack_list(stack_t *s, int *val) 
{
    if (s->top == NULL) 
    {
        return -1; // La pile est vide
    }

    node_t *top_node = s->top;
    *val = top_node->val;
    s->top = top_node->next;

    free(top_node);

    return 0; // Succès
}

/**
 * Affiche le contenu de la pile basée sur une liste chaînée.
 * Parcourt la liste et affiche chaque valeur de la pile.
 * 
 * @param s Un pointeur vers la structure de la pile.
 */
void display_stack_list(stack_t *s) 
{
    if (s->top == NULL) 
    {
        printf("La pile est vide\n");
    } 
    else 
    {
        printf("Contenu de la pile:\n");
        node_t *current = s->top;
        while (current != NULL) 
        {
            printf("%d\n", current->val);
            current = current->next;
        }
    }
}