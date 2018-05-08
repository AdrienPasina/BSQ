/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Made by Hugo SOHM
*/

#include "bsq.h"

int	main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	struct stat size;
	char *map;

	(void)ac;
	if (stat(av[1], &size) == -1)
		return (84);
	map = malloc(sizeof(char *) * size.st_size);
	if (fd == -1) {
		my_putstr("Error to open\n");
		return (1);
	}
	read(fd, map, size.st_size + 1);
	map[size.st_size] = 0;
	map = algo1(map);
	map = remove1(map);
	my_putstr(map);
	close(fd);
	free(map);
	return (0);
}
