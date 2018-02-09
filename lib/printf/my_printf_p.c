/*
** EPITECH PROJECT, 2017
** my_printf_p.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

#include <stdlib.h>
#include "include/my.h"

void my_printf_p(void *data)
{
	unsigned int p = (unsigned int)data;
	my_putstr("0x");
	my_putnbr_base(p, "0123456789abcdef");
}
