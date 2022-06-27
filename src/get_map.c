/*
** Maze_Solver
** File description
** get_map
*/

#include "solver.h"

static int get_lines_nbr(char *filname)
{
    int fd = open(filname, O_RDONLY);
    int nb_lines = 0;
    const int buffer_size = 32000;
    char buffer[buffer_size] = {0};

    read(fd, &buffer, buffer_size);
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == '\n')
            nb_lines++;
        if (buffer[i + 1] == '\0' && buffer[i] != '\n')
            nb_lines++;
    }
    close(fd);
    return nb_lines;
}

static char **convert_in_2d_array(maze_t *maze, char *filepath, char *str)
{
    const char *sep = "\n";
    char *str_token = strtok(str, sep);
    char **tab = NULL;
    int i = 0;

    maze->height = get_lines_nbr(filepath);
    maze->width = my_strlen(str_token);
    tab = (char **)malloc(sizeof(char *) * (maze->height + 1));

    for (; str_token != NULL; i++) {
        tab[i] = my_strdup(str_token);
        str_token = strtok(NULL, sep);
    }
    tab[i] = NULL;
    return tab;
}

char *get_map(maze_t *maze, char *filepath)
{
    int fd;
    struct stat st;
    char *buff = 0;
    int size = 0;

    if ((fd = open(filepath, O_RDONLY)) == -1)
        return NULL;
    stat(filepath, &st);
    size = st.st_size;
    buff = malloc(sizeof(char) * (size + 2));
    if ((read(fd, buff, size)) == -1)
        return NULL;
    close(fd);
    buff[size] = '\n';
    buff[size + 1] = '\0';
    maze->map = convert_in_2d_array(maze, filepath, buff);
    return buff;
}
