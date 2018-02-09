/*
** EPITECH PROJECT, 2017
** check_end.c
** File description:
** Made by Nathan GRIMAUD an Tom ROUVER
*/

int check_win(char **tab)
{
	int i = -1;
	int j = -1;

	while (tab[++j] != NULL) {
		i = -1;
		while (tab[j][++i] != '\0') {
			if (tab[j][i] >= '2' && tab[j][i] <= '5') {
				return (0);
			}
		}
	}
	my_printf("Enemy won\n");
	return (1);
}
