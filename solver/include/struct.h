/*
** EPITECH PROJECT, 2020
** solver
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdbool.h>

typedef enum dir {
    up,
    down,
    left,
    right,
    error,
} dir_e;

typedef struct around {
    bool up;
    bool down;
    bool left;
    bool right;
} around_t;

typedef struct pos {
    unsigned int y;
    unsigned int x;
} pos_t;

typedef struct list {
    around_t around;
    pos_t pos;
    struct list *prev;
    struct list *up;
    struct list *down;
    struct list *left;
    struct list *right;
} list_t;

#endif /* !STRUCT_H_ */
