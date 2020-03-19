/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** error_handling
*/

#ifndef ERROR_HANDLING_H_
#define ERROR_HANDLING_H_

#include <string.h>
#include <stdlib.h>

static inline int parse_arg(char *arg)
{
    for (int i = 0; arg[i] != 0; i++)
        if (!(arg[i] >= '0' && arg[i] <= '9'))
            return (-1);
    return (0);
}

static inline int error_handling(int ac, char **av)
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

#endif /* !ERROR_HANDLING_H_ */
