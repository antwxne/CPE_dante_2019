/*
** EPITECH PROJECT, 2020
** generator
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "generator.h"
#include "my.h"

static inline void display(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        printf("%s\n", maze[i]);
}

int main(int ac, char **av)
{
    char **maze;

    srand(time(NULL));
    if (ac != 4)
        return (84);
    if (strcmp(av[3], "[perfect]") == 0) {
        maze = create_base(atoi(av[1]), atoi(av[2]));
        display(maze);
    }
    my_free_arr(maze, 0);
    return (0);
}