/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

#include <stdio.h>
#include <stdarg.h>
#include "include/my.h"

void my_printf(char *str, ...)
{
	va_list ap;
	int i = 0;
	int j = 0;
	int nb_args = calc_nb_args(str);
	char *types = find_type(str, nb_args);

	va_start(ap, str);
	while (str[j] != '\0') {
		if (str[j] != '%') {
			my_putchar(str[j]);
			j++;
		} else if (str[j] == '%') {
			args1(types, ap, i);
			args2(types, ap, i);
			args3(types, ap, i);
			i++;
			j += 2;
		}
	}
	va_end(ap);
}
