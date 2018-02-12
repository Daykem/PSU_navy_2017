/*
** EPITECH PROJECT, 2017
** test.c
** File description:
** Made by devlopers
*/

#include <criterion/criterion.h>
#include "navy.h"
#include <string.h>

Test(test1, error1)
{
	cr_assert_str_eq(("", ""), "");
}

Test(test2, error2)
{
	cr_assert_str_eq(("1", ""), "");
}

Test(test3, error3)
{
	cr_assert_str_eq(("a", ""), "");
}

Test(test4, error4)
{
	cr_assert_str_eq((NULL, ""), "");
}
