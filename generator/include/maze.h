/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** perfect
*/

#ifndef PERFECT_H_
#define PERFECT_H_

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

static inline void display(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        if (maze[i + 1] != NULL)
            printf("%s\n", maze[i]);
        else
            printf(maze[i]);
    }
}

static inline around_t check_around(pos_t pos, around_t around)
{
    around = (around_t) {false, false};
    around.left = pos.x > 0 ? true : false;
    around.up = pos.y > 0 ? true : false;
    return (around);
}

static inline char **in_out_i(char **maze, int width, int height)
{
    maze[0][0] = '*';
    for (int i = 0; i < width; i++)
        maze[height - 1][i] = '*';
    return (maze);
}

static inline char **in_out_p(char **maze, int width, int height)
{
    maze[0][0] = '*';
    maze[height - 1][width - 2] = '*';
    maze[height - 1][width - 1] = '*';
    return (maze);
}

static inline char **mod_maze(char **maze, pos_t pos, around_t around)
{
    int connect = rand() % 2;

    if (around.up == false && around.left == false) {
        maze[pos.y][pos.x] = '*';
        return (maze);
    }
    maze[pos.y][pos.x] = '*';
    if (around.up == true && around.left == true) {
        if (connect == up)
            maze[pos.y -1][pos.x] = '*';
        else
            maze[pos.y][pos.x -1] = '*';
    }
    if (around.up == true && around.left == false)
        maze[pos.y - 1][pos.x] = '*';
    if (around.up == false && around.left == true)
        maze[pos.y][pos.x - 1] = '*';
    return (maze);
}

static inline char **algo_p(char **maze, int width, int height)
{
    around_t around = {false, false};

    for (int y = 0; y < height; y += 2)
        for (int x = 0; x < width; x += 2) {
            around = check_around((pos_t) {y, x}, around);
            maze = mod_maze(maze, (pos_t) {y, x}, around);
        }
    return (in_out_p(maze, width, height));
}

static inline char **algo_i(char **maze, int width, int height)
{
    around_t around = {false, false};

    for (int y = 0; y < height; y += 2)
        for (int x = 0; x < width; x += 2) {
            around = check_around((pos_t) {y, x}, around);
            maze = mod_maze(maze, (pos_t) {y, x}, around);
        }
    return (in_out_i(maze, width, height));
}

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

#endif /* !PERFECT_H_ */
