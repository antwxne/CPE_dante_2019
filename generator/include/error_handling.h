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

#endif /* !ERROR_HANDLING_H_ */
