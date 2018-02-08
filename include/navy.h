/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** Made by Nathan GRIMAUD and Tom ROUVIER
*/

#include "my.h"

#ifndef NAVY_H_
#define NAVY_H_

int my_pid(void);
char **create_tab(char*);
void help();
char *read_my_pos(char*);
void fill_hor(char**, int, int, char);
void fill_ver(char**, int, int, char);
void game1(char*);
void game2(char*);
void fill_map(char**, char);
void affect_map(char**, char*, int);
void print_tab(char**);
void send_sig();
int check_hit(char**, char*);
void enemy_hit(char **, char*, int);

#endif /* NAVY_H_ */
