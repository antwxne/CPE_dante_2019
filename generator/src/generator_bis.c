/*
** EPITECH PROJECT, 2020
** dante
** File description:
** maze generator
*/

#include "generator.c"

int create_maze(list_t **list)
{
    list_t *element;
    int y = 0;
    int x = 0;

    while (1) {
        element = malloc(sizeof(element));
        element->pos = {y, x};
        element->type = path;
        element
    }
    return (0);
}

int main(void)
{
    list_t *list = NULL;

    create_maze(&list);
}
