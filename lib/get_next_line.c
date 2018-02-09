/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** Made by Nathan GRIMAUD <Jimmy>
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char *over_read(char *str)
{
	int i = 0;
	int j = 0;
	char *temp = malloc(sizeof(char) * (1 + 1));

	if (temp == NULL)
		return (NULL);
	while (str[i] != '\n')
		i++;
	i++;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	return (temp);
}

int check_n(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char *my_strcatn(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j] != '\0' && src[j] != '\n')
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	char *buffer = NULL;
	char *str = malloc(4096);
	static char *over_str = NULL;

	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	if (over_str != NULL)
		str = my_strcatn(str, over_str);
	while (1) {
		buffer = malloc(sizeof(char) * (1 + 1));
		if (buffer == NULL)
			return (NULL);
		if (read(fd, buffer, 1) == 0) {
			free(buffer);
			return (NULL);
		}
		buffer[1] = '\0';
		str = my_strcatn(str, buffer);
		if (check_n(buffer) == 1) {
			free(over_str);
			over_str = over_read(buffer);
			free(buffer);
			break;
		}
		free(buffer);
	}
	return (str);
}
