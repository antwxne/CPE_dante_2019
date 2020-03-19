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
    if (width != 1)
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

#endif /* !PERFECT_H_ */
