/*
** EPITECH PROJECT, 2020
** generator
** File description:
** binary_perf
*/

#include "generator.h"
#include "perfect.h"

static inline char **create_base_p(int width, int height)
{
    char **maze = malloc(sizeof(char *)*(height + 1));
    int y = 0;

    if (maze == NULL)
        return (NULL);
    for (; y < height; y++) {
        maze[y] = malloc(sizeof(char)*(width + 1));
        if (maze[y] == NULL)
            return (NULL);
        for (int x = 0; x < width; x++)
            maze[y][x] = 'X';
        maze[y][width] = 0;
    }
    maze[y] = NULL;
    return (algo(maze, width, height));
}