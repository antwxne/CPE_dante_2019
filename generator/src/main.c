/*
** EPITECH PROJECT, 2020
** dant generator
** File description:
** main.c
*/

#include <stdlib.h>
#include "generator.h"
#include "my.h"

int main(int ac, char **av)
{
    char **maze;
    int **mask;
    list_t *list = NULL;

    srand(__TIME__);
    if (ac != 3)
        return (84);
    maze = create_base(atoi(av[1]), atoi(av[2]));
    mask = create_mask(atoi(av[1]), atoi(av[2]));
    display_maze(maze);
    printf("\n\n\n");
    display_mask(mask);
    algo(list, &maze, &mask);
    return (0);
}
