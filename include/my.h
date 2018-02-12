/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** libmy prototypes
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <fcntl.h>

#ifndef MY_H_H_
# define MY_H_H_

void my_putchar(char);
void my_putstr(char*);
int my_strlen(char const*);
void my_printf(char*, ...);
int my_put_nbr(int);
int my_putnbr_base(int, char const*);
int my_getnbr(char*);
char *get_next_line(int);

#endif
