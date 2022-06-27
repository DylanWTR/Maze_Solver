/*
** Maze_Solver
** File description
** maze_algo
*/

#include "solver.h"

static int _free_side(maze_t *maze, int *posx, int *posy)
{
    if (*posy > 0)
        if (maze->map[*posy][*posx - 1] == VOID) {
            *posx -= 1;
            return TRUE;
        }
    if (*posx > 0)
        if (maze->map[*posy - 1][*posx] == VOID) {
            *posy -= 1;
            return TRUE;
        }
    return FALSE;
}

static int free_side(maze_t *maze, int *posx, int *posy)
{
    if (*posx < maze->width - 1)
        if (maze->map[*posy][*posx + 1] == VOID) {
            *posx += 1;
            return TRUE;
        }
    if (*posy < maze->height - 1)
        if (maze->map[*posy + 1][*posx] == VOID) {
            *posy += 1;
            return TRUE;
        }
    if (_free_side(maze, posx, posy))
        return TRUE;
    else
        return FALSE;
    return FALSE;
}

int solve_maze(path_ll_t **path, maze_t *maze, int posx, int posy)
{
    if (!free_side(maze, &posx, &posy)) {
        delete_first_node(path);
        if (!path) {
            maze->map[0][0] = '*';
            return TRUE;
        }
        if (solve_maze(path, maze, (*path)->posx, (*path)->posy))
            return TRUE;
    }
    maze->map[posy][posx] = SEEN;
    push_to_ll(path, posx, posy);
    if (posy == maze->height - 1 && posx == maze->width - 1)
        return TRUE;
    if (solve_maze(path, maze, posx, posy))
        return TRUE;
    return FALSE;
}

void build_final_path(path_ll_t *path, maze_t *maze)
{
    int posx = 0;
    int posy = 0;

    for (path_ll_t *tmp = path; tmp; tmp = tmp->next) {
        posx = tmp->posx;
        posy = tmp->posy;
        maze->map[posy][posx] = GOOD;
    }
}
