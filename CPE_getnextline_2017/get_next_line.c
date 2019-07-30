/*
** EPITECH PROJECT, 2018
** stumper5
** File description:
** my_get_next_line
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "info.h"
#include "proto.h"

char *my_strcat(char *str, char *str2)
{
	int i = 0;
	int l = 0;
	int m = 0;
	char *str3 = malloc(sizeof(char) * my_strlen(str) +
		my_strlen(str2) + 1);

	while (str[i] != '\0') {
		str3[m] = str[i];
		i++;
		m++;
	}
	while (str2[l] != '\0') {
		str3[m] = str2[l];
		m++;
		l++;
	}
	str3[m] = '\0';
	free(str);
	return (str3);
}

void end_buffer(int i, char *str, int j)
{
	if (i > 0 && str[i - 1] == '\n')
		str[j] = '\0';
	str[i] = '\0';
}

char *get_next_line(int fd)
{
	int i = 0;
	int j = 0;
	char buffer[2];
	int size;
	char *str = malloc(sizeof(char) * 2);

	if (buffer == NULL || str == NULL || fd == -1)
		return (NULL);
	buffer[i] = str[i] = '\0';
	size = read(fd, buffer, 1);
	while ((size == 1) && buffer[j] != '\n') {
		str[i] = buffer[j];
		i++;
		str[i] = '\0';
		buffer[j + 1] = '\0';
		str = my_strcat(str, buffer);
		end_buffer(i, str, j);
		size = read(fd, buffer, 1);
	}
	return (((i == 0 && size == 0) ? NULL : str));
}
