/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** error_handling
*/

#include "error_handling.h"

int error_handling(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (-1);
    if (ac == 3)
        if (atoi(av[1]) < 0 || atoi(av[2]) < 0 ||
            parse_arg(av[1]) == -1 || parse_arg(av[2]) == -1)
            return (-1);
    if (ac == 4)
        if (atoi(av[1]) < 0 || atoi(av[2]) < 0 || parse_arg(av[1]) == -1 ||
        parse_arg(av[2]) == -1 || strcmp(av[3], "perfect") != 0)
            return (-1);
    return (0);
}