/*
** EPITECH PROJECT, 2020
** solver
** File description:
** new_solv
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "solveur.h"
#include "struct.h"

void display(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        if (maze[i + 1] != NULL)
            printf("%s\n", maze[i]);
        else
            printf(maze[i]);
    }
}

static int dir(char ***maze, pos_t pos, pos_t const size, int i)
{
    maze[0][pos.y][pos.x] = 'o';
    if (i == 200000)
        return (-1);
    if (pos.x == size.x - 1 && pos.y == size.y - 1)
        return (0);
    if (pos.x + 1 < size.x && maze[0][pos.y][pos.x + 1] == '*')
        if (dir(maze, (pos_t) {pos.y, pos.x + 1}, size, i + 1) == 0)
            return (0);
    if (pos.y + 1 < size.y && maze[0][pos.y + 1][pos.x] == '*')
        if (dir(maze, (pos_t) {pos.y + 1, pos.x}, size, i + 1) == 0)
            return (0);
    if (pos.x > 0 && maze[0][pos.y][pos.x - 1] == '*')
        if (dir(maze, (pos_t) {pos.y, pos.x - 1}, size, i + 1) == 0)
            return (0);
    if (pos.y > 0 && maze[0][pos.y - 1][pos.x] == '*')
        if (dir(maze, (pos_t) {pos.y - 1, pos.x}, size, i + 1) == 0)
            return (0);
    maze[0][pos.y][pos.x] = '0';
    return (-1);
}

static char **mod_maze(char **maze)
{
    for (int y = 0; maze[y] != NULL; y++)
        for (int x = 0; maze[y][x] != '\0'; x++)
            if (maze[y][x] == '0')
                maze[y][x] = '*';
    return (maze);
}

char **algo(char **maze, pos_t const size)
{
    int out = dir(&maze, (pos_t) {0, 0}, size, 0);

    if (out == -1) {
        printf("no solution found");
        exit(0);
    }
    maze = mod_maze(maze);
    return (maze);
}
