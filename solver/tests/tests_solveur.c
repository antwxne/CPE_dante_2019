/*
** EPITECH PROJECT, 2020
** solver
** File description:
** tests_solveur
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "solveur.h"
#include "struct.h"
#include "my.h"

void redirect_all(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (start, test1, .init = redirect_all)
{
    int got = start("tests/maze_10_10_p_1.txt");
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (start, test2, .init = redirect_all)
{
    int got = start("tests/maze_10_0_p_1.txt");
    int expected = 84;

    cr_assert_eq(got, expected);
}