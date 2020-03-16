/*
** EPITECH PROJECT, 2020
** generator
** File description:
** generator
*/

#include <stdlib.h>
#include <string.h>

static char **in_out(char **maze)
{
    int i = 0;

    maze[0][0] = '*';
    for (; maze[i] != NULL; i++);
    maze[i-1][strlen(maze[i-1]) - 1] = '*';
    return (maze);
}

static char *fil_line(int len)
{
    char *dest = malloc(sizeof(char)*len + 1);
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; i < len; i++)
        dest[i] = 'X';
    dest[rand() % len] = '*';
    dest[i] = 0;
    return (dest);
}

static char *simple_line(int len)
{
    char *dest = malloc(sizeof(char)*len + 1);
    int i = 0;

    if (dest == NULL)
        return (NULL);
    for (; i < len; i++)
        dest[i] = '*';
    dest[i] = 0;
    return (dest);
}

char **maze_base_p(int x, int y)
{
    char **maze = malloc(sizeof(char *)*(y + 1));
    int i = 0;

    if (maze == NULL)
        return (NULL);
    for (; i < y; i++) {
        if (i % 2 == 0)
            maze[i] = simple_line(x);
        else
            maze[i] = fil_line(x);
    }
    maze[i] = NULL;
    return (in_out(maze));
}