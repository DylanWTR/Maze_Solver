/*
** Maze_Solver
** File description
** main
*/

#include "solver.h"

static void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        printf("%s", tab[i]);
        if (tab[i + 1] != NULL)
            printf("\n");
    }
}

static int is_maze_valid(maze_t *maze)
{
    if (maze->map[0][0] != '*')
        return FALSE;
    if (maze->map[maze->height - 1][maze->width - 1] != '*')
        return FALSE;
    return TRUE;
}

static void remove_alternative_paths(maze_t *maze)
{
    for (int i = 0; maze->map[i] != NULL; i++)
        for (int j = 0; maze->map[i][j] != '\0'; j++)
            if (maze->map[i][j] == SEEN)
        maze->map[i][j] = VOID;
}

int main(int argc, char **argv)
{
    path_ll_t *path = NULL;
    maze_t *maze = (maze_t *)malloc(sizeof(maze_t));
    maze->map = NULL;

    if (argc != 2)
        return 84;
    get_map(maze, argv[1]);
    if (!is_maze_valid(maze))
        return 0;
    maze->map[0][0] = 'o';
    solve_maze(&path, maze, 0, 0);
    build_final_path(path, maze);
    remove_alternative_paths(maze);
    print_tab(maze->map);
    return 0;
}
