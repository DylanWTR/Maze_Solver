/*
** Maze_Solver
** File description
** my_strlen
*/

#include "solver.h"

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
