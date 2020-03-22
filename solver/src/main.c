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

void display(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        printf("%s\n", maze[i]);
}

int main(int ac, char **av)
{
    if (ac == 2) {
        return (start(av[1]));
    }
    return (84);
}
