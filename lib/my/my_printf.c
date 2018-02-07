/*
** EPITECH PROJECT, 2017
** printf
** File description:
** Made by daykem
*/

#include <stdio.h>
#include <stdarg.h>
#include "../../include/my.h"

void	my_printf(char *str, ...) {
	va_list ap;
	int i = 0;
	int a = 0;

	va_start(ap, str);
	while (str[i] != '\0') {
		if (str[i] == '%') {
			switch (str[i + 1]) {
			case 'd':
				my_put_nbr(va_arg(ap, int));
				break;
			case 'i':
				my_put_nbr(va_arg(ap, int));
				break;
			case 'u':
				my_put_nbr(va_arg(ap, unsigned int));
				break;
			case 's':
				my_putstr(va_arg(ap, char *));
				break;
			case '%':
				my_putchar('%');
				break;
			case 'c':
				my_putchar((char)va_arg(ap, int));
				break;
			case 'x':
				a = va_arg(ap, unsigned int);
				my_putnbr_base(a, "0123456789abcdef");
				break;
			case 'X':
				a = va_arg(ap, unsigned int);
				my_putnbr_base(a, "0123456789ABCDEF");
				break;
			case 'b':
				a = va_arg(ap, unsigned int);
				my_putnbr_base(a, "01");
				break;
			case 'o':
				a = va_arg(ap, unsigned int);
				my_putnbr_base(a, "01234567");
				break;
			case 'S':
				my_putstr(va_arg(ap, char *));
				break;
			case 'p':
				a = va_arg(ap, unsigned int);
				my_putstr("0x");
				my_putnbr_base(a, "0123456789abcdef");
				break;
			default :
				my_putchar(str[i]);
				my_putchar(str[i + 1]);
				break;
			}
			i++;
		} else
			my_putchar(str[i]);
		i++;
	}
	va_end(ap);
}
