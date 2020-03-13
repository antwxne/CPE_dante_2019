/*
** EPITECH PROJECT, 2020
** maze
** File description:
** create base with walls
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

void display_mask(int **mask)
{
    int y = 0;

    for (; mask[y] != NULL; y++) {
        for (int x = 0; mask[y][x] != -1; x++)
            printf("%d", mask[y][x]);
        printf("\n");
    }
}

void display_maze(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        printf("%s\n", maze[i]);
}

int **create_mask(int width, int height)
{
    int **maze = malloc(sizeof(int *)*(height + 1));
    int y = 0;

    if (maze == NULL)
        return (NULL);
    for (; y < height; y++) {
        maze[y] = malloc(sizeof(int)*(width + 1));
        if (maze[y] == NULL)
            return (NULL);
        for (int x = 0; x < width; x++)
            maze[y][x] = 0;
        maze[y][width] = -1;
    }
    maze[height] = NULL;
    return (maze);
}

static char **in_out(char **maze)
{
    int i = 0;

    maze[0][0] = '*';
    for (; maze[i] != NULL; i++);
    maze[i-1][strlen(maze[i-1]) - 1] = '*';
    return (maze);
}

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
        maze[y][width] = 0;
    }
    maze[height] = NULL;
    return (in_out(maze));
}
