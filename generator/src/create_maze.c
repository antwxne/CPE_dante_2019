/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** create_maze
*/

#include "maze.h"

static char **algo_p(char **maze, int width, int height)
{
    around_t around = {false, false};

    for (int y = 0; y < height; y += 2)
        for (int x = 0; x < width; x += 2) {
            around = check_around((pos_t) {y, x}, around);
            maze = mod_maze(maze, (pos_t) {y, x}, around);
        }
    return (in_out_p(maze, width, height));
}

static char **algo_i(char **maze, int width, int height)
{
    around_t around = {false, false};

    for (int y = 0; y < height; y += 2)
        for (int x = 0; x < width; x += 2) {
            around = check_around((pos_t) {y, x}, around);
            maze = mod_maze(maze, (pos_t) {y, x}, around);
        }
    return (in_out_i(maze, width, height));
}

char **create_base_p(int width, int height)
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
    return (algo_p(maze, width, height));
}

char **create_base_i(int width, int height)
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
    return (algo_i(maze, width, height));
}