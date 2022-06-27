/*
** Maze_Solver
** File description
** solver.h
*/

#ifndef __SOLVER__H__
    #define __SOLVER__H__

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <string.h>
    #include <sys/stat.h>

    #define TRUE 1
    #define FALSE 0

    #define VOID '*'
    #define SEEN '+'
    #define GOOD 'o'

typedef struct maze {
    char **map;
    int height;
    int width;
}
maze_t;

typedef struct path_ll {
    int posx;
    int posy;
    struct path_ll *next;
}
path_ll_t;

/* LIB */
char *my_strdup(char const *src);
int my_strlen(const char *str);
char *my_strncpy(char *dest, char const *src, int n);

/* INIT */
char *get_map(maze_t *maze, char *filepath);

/* LINKED LIST */
void push_to_ll(path_ll_t **head_ref, int posx, int posy);
void delete_first_node(path_ll_t **head);

/* MAZE ALGO */
int solve_maze(path_ll_t **path, maze_t *maze, int posx, int posy);
void build_final_path(path_ll_t *path, maze_t *maze);

#endif/*___SOLVER__H__*/
