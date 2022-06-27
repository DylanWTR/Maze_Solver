/*
** Maze_Solver
** File description
** my_strdup
*/

#include "solver.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int j = my_strlen(src);

    str = malloc(sizeof(char) * j);
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
