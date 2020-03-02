/*
** EPITECH PROJECT, 2020
** generator
** File description:
** unit_tests
*/

#include <criterion/criterion.h>
#include "generator.h"

Test (create_base, test1)
{
    int width = 5;
    int height = 5;
    int size = (sizeof(char)*width)*(sizeof(char *)*height);
    char **got = create_base(width, height);
    int i = 0;
    /* char *expected[] = {"XXXXX", */
    /*                     "XXXXX", */
    /*                     "XXXXX", */
    /*                     "XXXXX", */
    /*                     "XXXXX"}; */
    char expected[] = "XXXXX";

    for (; got[i] != NULL; i++)
        cr_assert_str_eq(got[i], expected);
    cr_assert_eq(i, 5);
    my_free_arr(got, 0);
}

Test (create_base, test2)
{
    int width = 10;
    int height = 10;
    int size = (sizeof(char)*width)*(sizeof(char *)*height);
    char **got = create_base(width, height);
    char expected[] = "XXXXXXXXXX";
    int i = 0;

    for (; got[i] != NULL; i++)
        cr_assert_str_eq(got[i], expected);
    cr_assert_eq(i, 10);
    my_free_arr(got, 0);
}
