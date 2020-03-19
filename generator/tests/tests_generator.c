/*
** EPITECH PROJECT, 2020
** generator
** File description:
** tests_generator
*/

#include <criterion/criterion.h>
#include "maze.h"
#include "error_handling.h"
#include "my.h"

Test (parfait, test_small)
{
    char **maze = create_base_p(10, 10);

    cr_assert_not_null(maze);
    my_free_arr(maze, 0);
}

Test (parfait, test_negatif1)
{
    char **maze = create_base_p(-10, 10);

    cr_assert_null(maze);
}

Test (parfait, test_negatif2)
{
    char **maze = create_base_p(10, -10);

    cr_assert_null(maze);
}

Test (imparfait, test_small)
{
    char **maze = create_base_i(10, 10);

    cr_assert_not_null(maze);
    my_free_arr(maze, 0);
}

Test (imparfait, test_negatif1)
{
    char **maze = create_base_i(-10, 10);

    cr_assert_null(maze);
}

Test (imparfait, test_negatif2)
{
    char **maze = create_base_i(10, -10);

    cr_assert_null(maze);
}

Test (error_handling, test_ok)
{
    int ac = 3;
    char *av[] = {NULL, "3", "4"};
    int got = error_handling(ac, av);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_ok2)
{
    int ac = 4;
    char *av[] = {NULL, "3", "4", "perfect"};
    int got = error_handling(ac, av);
    int expected = 0;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail1)
{
    int ac = 1;
    char *av[] = {NULL, "3", "4"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail2)
{
    int ac = 5;
    char *av[] = {NULL, "3", "4"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail3)
{
    int ac = 3;
    char *av[] = {NULL, "-3", "4"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail4)
{
    int ac = 3;
    char *av[] = {NULL, "3", "-4"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail5)
{
    int ac = 3;
    char *av[] = {NULL, "a3", "4"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail6)
{
    int ac = 3;
    char *av[] = {NULL, "3", "a4"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail7)
{
    int ac = 4;
    char *av[] = {NULL, "-3", "4", "perfect"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail8)
{
    int ac = 4;
    char *av[] = {NULL, "3", "-4", "perfect"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail9)
{
    int ac = 4;
    char *av[] = {NULL, "a3", "4", "perfect"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail10)
{
    int ac = 4;
    char *av[] = {NULL, "3", "a4", "perfect"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}

Test (error_handling, test_fail11)
{
    int ac = 4;
    char *av[] = {NULL, "3", "4", "perfec"};
    int got = error_handling(ac, av);
    int expected = -1;

    cr_assert_eq(got, expected);
}