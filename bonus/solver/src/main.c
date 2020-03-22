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

int main(int ac, char **av)
{
    if (ac == 2) {
        return (start(av[1]));
    }
    return (84);
}
