/*
** EPITECH PROJECT, 2017
** libmy prototypes
** File description:
** Made by Nathan GRIMAUD
*/

#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

void my_putchar(char);
int my_putstr(const char*);
int my_put_nbr(int);
int my_put_nbr_u(unsigned int);
int my_strlen(char*);
int calc_nb_args(char*);
char *find_type(char*, int);
int my_putnbr_base(int nbr, char const*);
char *my_revstr(char*);
int my_showstr(char const *str);
void my_printf(char*, ...);
void args1(char*, va_list, int);
void args2(char*, va_list, int);
void args3(char*, va_list, int);
void my_printf_p(void*);

#endif
