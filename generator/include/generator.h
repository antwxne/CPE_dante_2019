/*
** EPITECH PROJECT, 2020
** generator
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "my.h"

typedef enum direction {
    up,
    down,
    left,
    right,
    wall_up,
    wall_down,
    wall_left,
    wall_right,
} direct_e;

typedef enum type {
    wall,
    path,
} type_e;

typedef struct pos
{
    int y;
    int x;
} position_t;

typedef struct list
{
    position_t pos;
    int type;
    struct list *next;
    struct list *prev;
} list_t;

void display_mask(int **mask);
void display_maze(char **maze);
char **create_base(int width, int height);
int **create_mask(int width, int height);
int algo(list_t **list, char ***maze, int ***mask);

#endif /* !GENERATOR_H_ */
