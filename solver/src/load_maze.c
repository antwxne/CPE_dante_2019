/*
** EPITECH PROJECT, 2020
** solver
** File description:
** load_maze
*/

#include "loading.h"

int solving(char *filepath)
{
    char **maze;
    char *buff;

    buff = read_maze(filepath);
    if (buff == NULL)
        return (84);
    maze = tab_maze(buff);
    if (maze == NULL)
        return (84);
    display(maze);
    free(maze);
    free(buff);
    return (0);
}