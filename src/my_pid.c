/*
** EPITECH PROJECT, 2017
** my_pid.c
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "navy.h"

int my_pid(void)
{
	pid_t pid = getpid();

	my_printf("my_pid: %d\n", pid);
	return (0);
}
