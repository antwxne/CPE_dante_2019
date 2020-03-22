/*
** EPITECH PROJECT, 2020
** solveur
** File description:
** solveur
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "solveur.h"

static void display(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++) {
        if (maze[i + 1] != NULL)
            printf("%s\n", maze[i]);
        else
            printf(maze[i]);
    }
}

int main(int ac, char **av)
{
    if (ac == 2) {
        return (start(av[1]));
    }
    return (84);
}
