/*
** EPITECH PROJECT, 2018
** send
** File description:
** Made by Daykem
*/

#include "navy.h"

int gfunc3(int value, int mode)
{
	static int save = 0;

	if (mode == 0)
		save = value;
	return (save);
}

void sighandler(int sigul, siginfo_t *info, void *context)
{
	int pid = info->si_pid;

	my_printf("\nenemy connected\n");
	gfunc3(pid, 0);
}

void send_sig(void)
{
	struct sigaction act;
	struct sigaction oldact;

	my_pid();
	my_printf("waiting for enemy connection...\n");
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &act, NULL);
	usleep(100000000);
}
