/*
** EPITECH PROJECT, 2018
** send
** File description:
** Made by Daykem
*/

#include "navy.h"

void sighandler(int sigul, siginfo_t *info, void *str)
{
	my_printf("enemy connected\n\n");
}

void send_sig()
{
	struct sigaction act;
	struct sigaction oldact;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &act, NULL);
	sleep(100);
}
