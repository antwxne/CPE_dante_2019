/*
** EPITECH PROJECT, 2020
** maze
** File description:
** create base with walls
*/

#include <stdlib.h>

char **create_base(int width, int height)
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
        maze[y][width] = '\0';
    }
    maze[width] = NULL;
    return (maze);
}
