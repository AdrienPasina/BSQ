/*
** EPITECH PROJECT, 2017
** algo.c
** File description:
** Made by Hugo SOHM
*/

#include "bsq.h"

char *ret(char *map)
{
	int i = my_strlen2(map);

	while (map[i]) {
		if (map[i] != 'x' && map[i] != 'o' && map[i] != '\n' && map[i])
			map[i] = '.';
		i++;
	}
	if (map[my_strlen2(map)] == '.' && my_getnbr(map) == 0
	|| my_strlen3(map) == 1 && my_getnbr(map) == 1)
		map[my_strlen2(map)] = 'x';
	return (map);
}

char	*replace(char *map, int j, char *max)
{
	int a = (int)max - 48;
	int b = (int)max - 48;

	while (b != 0) {
		map[j] = 'x';
		j--;
		a--;
		if (a == 0) {
			a = (int)max - 48;
			b--;
			j = (j - my_strlen3(map) - 1 + a);
		}
	}
	return (ret(map));
}

char	biggest(char *map, int *j)
{
	int i = my_strlen2(map);
	char max = '1';

	while (map[i]) {
		if (map[i] > max && map[i] != 'o') {
			max = map[i];
			*j = i;
		}
		i++;
	}
	return (max);
}

char	*algo2(char *map)
{
	int i = my_strlen3(map);
	int j = 0;
	char max;

	while (map[i]) {
		if (map[i] == '.' && map[i - 1] != 'o' && map[i - 1] != '\n'
		&& map[i - my_strlen3(map) - 1] != 'o'
		&& map[i - my_strlen3(map) - 1] != '\n'
		&& map[i - my_strlen3(map) - 2] != 'o'
		&& map[i - my_strlen3(map) - 2] != '\n')
			map[i] = calc(map[i - 1], map[i - my_strlen3(map) - 1],
			map[i - my_strlen3(map) - 2]) + 1;
		else if (map[i] == '.')
			map[i] = '1';
		i++;
	}
	max = biggest(map, &j);
	map = replace(map, j, max);
	return (map);
}

char	*algo1(char *map)
{
	int i = my_strlen2(map);
	int j = 0;
	char max;

	while (map[i] != '\n' && map[i]) {
		if (map[i] == '.')
			map[i] = '1';
		i++;
	}
	while (map[i]) {
		if (map[i] == 'o' && map[i + 1] == '.')
			map[i + 1] = '1';
		if (map[i] == 'o' && map[i + 1 + my_strlen3(map)] == '.')
			map[i + 1 + my_strlen3(map)] = '1';
		if (map[i] == 'o' && map[i + 2 + my_strlen3(map)] == '.')
			map[i + 2 + my_strlen3(map)] = '1';
		i++;
	}
	return (map = algo2(map));
}
