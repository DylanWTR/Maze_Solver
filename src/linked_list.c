/*
** Maze_Solver
** File description
** linked_list
*/

#include "solver.h"

void push_to_ll(path_ll_t **head_ref, int posx, int posy)
{
    path_ll_t *new_node = (path_ll_t *)malloc(sizeof(path_ll_t));

    new_node->posx = posx;
    new_node->posy = posy;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void delete_first_node(path_ll_t **head)
{
    path_ll_t *tmp = NULL;

    if (head == NULL || *head == NULL)
        return;
    tmp = *head;
    *head = (*head)->next;
    free(tmp);
}
