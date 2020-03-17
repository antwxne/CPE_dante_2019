/*
** EPITECH PROJECT, 2020
** generator
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdbool.h>

typedef enum dir {
    up,
    left,
} dir_e;

typedef struct pos {
    int y;
    int x;
} pos_t;

typedef struct around {
    bool up;
    bool left;
} around_t;

typedef struct list {

    struct list *left;
    struct list *right;
} list_t;

#endif /* !STRUCT_H_ */
