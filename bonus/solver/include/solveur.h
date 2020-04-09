/*
** EPITECH PROJECT, 2020
** solver
** File description:
** solveur
*/

#ifndef SOLVEUR_H_
#define SOLVEUR_H_

#include "struct.h"

int start(char const *filepath);
void display(char const **maze);
char **algo(char **maze, pos_t const size);

#endif /* !SOLVEUR_H_ */
