/*
** EPITECH PROJECT, 2020
** generator
** File description:
** algo
*/

#include <stdlib.h>
#include <stdbool.h>
#include "generator.h"

bool visit(int **mask)
{
    int y = 0;

    for (; mask[y] != NULL; y++)
        for (int x = 0; mask[y][x] != -1; x++)
            if (mask[y][x] == 0)
                return (true);
    return (false);
}

direct_e chose_dir(position_t pos, int **mask)
{
    for (int r = -89; 1;) {
        r = rand() % 4;
        if (pos.y - 1 >= 0 && mask[pos.y - 1][pos.x] == 0 && r == 0)
            return (up);
        if (mask[pos.y + 1] != NULL && mask[pos.y + 1][pos.x] == 0 && r == 1)
            return (down);
        if (pos.x -1 >= 0 && mask[pos.y][pos.x - 1] == 0 && r == 2)
            return (left);
        if (mask[pos.y][pos.x + 1] != -1 && mask[pos.y][pos.x + 1] == 0 && r == 3)
            return (right);
    }
}

position_t update(int dir, position_t pos, char ***maze, int ***mask)
{
    if (dir == up) {
        maze[0][pos.y - 1][pos.x] = '*';
        mask[0][pos.y - 1][pos.x] = 1;
        return ((position_t) {pos.y - 1, pos.x});
    }
    if (dir == down) {
        maze[0][pos.y + 1][pos.x] = '*';
        mask[0][pos.y + 1][pos.x] = 1;
        return ((position_t) {pos.y + 1, pos.x});
    }
    if (dir == left) {
        maze[0][pos.y][pos.x - 1] = '*';
        mask[0][pos.y][pos.x - 1] = 1;
        return ((position_t) {pos.y, pos.x - 1});
    }
    if (dir == right) {
        maze[0][pos.y][pos.x + 1] = '*';
        mask[0][pos.y][pos.x + 1] = 1;
        return ((position_t) {pos.y, pos.x + 1});
    }
}

int algo(list_t **list, char ***maze, int ***mask)
{
    list_t *element;
    int dir = -1;
    position_t pos = {0, 0};

    while (visit(*mask)) {
        dir = chose_dir(pos, *mask);
        pos = update(dir, pos, maze, mask);
        display_maze(*maze);
        printf("\n\n\n");
        display_mask(*mask);
    }
}