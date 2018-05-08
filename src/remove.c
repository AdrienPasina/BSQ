/*
** EPITECH PROJECT, 2017
** remove.c
** File description:
** Made by Hugo SOHM
*/

#include "bsq.h"

char	*remove1(char *map)
{
	int i = my_strlen2(map);
	int j = 0;
	char *first = malloc(sizeof(char*) * my_strlen(map) + 1);

	while (map[i]) {
		first[j] = map[i];
		j++;
		i++;
	}
	return (first);
}

char calc(char s1, char s2, char s3)
{
	if (s1 <= s2 && s1 <= s3)
		return s1;
	else if (s2 <= s1 && s2 <= s3)
		return s2;
	else if (s3 <= s1 && s3 <= s2)
		return s3;
	else
		return '0';
}
