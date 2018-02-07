/*
** EPITECH PROJECT, 2017
** get_next_line
** File description:
** Made by Daykem
*/

#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include "get_next_line.h"

int     my_strlen(char *str)
{
        int i = 0;

        while (str && str[i])
		i++;
        return (i);
}

char    *my_strcat(char *dest, char *src)
{
 	char *tab;
        int a = 0;
        int b = 0;
        int i = 0;

        tab = malloc(sizeof(char) * (my_strlen(dest)
                                     + my_strlen(src) + 1));
        while (dest && dest[a]) {
                tab[i] = dest[a];
		a++;
		i++;
	}
        while (src && src[b]) {
		tab[i] = src[b];
		i++;
		b++;
	}
        tab[i] = '\0';
	return (tab);
}

char	*my_strdup(char *src, int size)
{
	int i = 0;
	char *tmp = src;

	src = malloc(sizeof(char*) * size);
	if (src == NULL)
		return (0);
	for (i = 0; tmp[i]; i++)
		src[i] = tmp[i];
	free(tmp);
	return (src);
}

char	*get_next_line(int fd)
{
	int size = (READ_SIZE + 1);
	char *buffer = malloc(sizeof(char) * size);
	char result;
	int i = 0;
	static int res;
	static char buff[READ_SIZE];
	static char *tmp;

	if (res == 0) {
		res = read(fd, buff, READ_SIZE);
		tmp =  my_strcat(tmp, buff);
		if (res == 0 || res == -1)
			return (0);
	}
	result = *tmp;
	res--;
	tmp++;
	if (buffer == NULL)
		return (0);
	while (result != '\n' && result) {
		buffer[i] = result;
		if (res == 0) {
			res = read(fd, buff, READ_SIZE);
			tmp =  my_strcat(tmp, buff);
			if (res == 0 || res == -1)
				return (0);
		}
		result = *tmp;
		res--;
		tmp++;
		i++;
		if ((i % size) == 0)
			buffer = my_strdup(buffer, (size + i));
	}
	buffer[i] = 0;
	return (buffer);
}
/*
int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *s = get_next_line(fd);

	while (s) {
	  printf("%s\n", s);
	  free(s);
	  s = get_next_line(fd);
	}
	return 0;
}
*/
