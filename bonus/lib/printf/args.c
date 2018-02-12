/*
** EPITECH PROJECT, 2017
** args.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

#include <stdarg.h>
#include "include/my.h"

void args1(char *types, va_list ap, int i)
{
	switch (types[i]) {
		case 'd':
			my_put_nbr(va_arg(ap, int));
			break;
		case 's':
			my_putstr(va_arg(ap, const char*));
			break;
		case 'c':
			my_putchar(va_arg(ap, int));
			break;
		case 'b':
			my_putnbr_base(va_arg(ap, unsigned int), "01");
			break;
	}
}

void args2(char *types, va_list ap, int i)
{
	switch (types[i]) {
		case 'S':
			my_showstr(va_arg(ap, const char*));
			break;
		case 'x':
			my_putnbr_base(va_arg(ap, unsigned int),
			"0123456789abcdef");
			break;
		case 'X':
			my_putnbr_base(va_arg(ap, unsigned int),
			"0123456789ABCDEF");
			break;
		case 'o':
			my_putnbr_base(va_arg(ap, unsigned int), "01234567");
			break;
	}
}

void args3(char *types, va_list ap, int i)
{
	switch (types[i]) {
		case 'u':
			my_put_nbr_u(va_arg(ap, unsigned int));
			break;
		case '%':
			my_putchar('%');
			break;
		case 'p':
			my_printf_p(va_arg(ap, void*));
			break;
	}
}
