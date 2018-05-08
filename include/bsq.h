/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** Made by Hugo SOHM
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char calc(char s1, char s2, char s3);
char *algo1(char *map);
char *remove1(char *map);
int is_num(char *map);

int my_strlen(char *str);
int my_strlen2(char *str);
int my_strlen3(char *str);

int my_getnbr(char const *str);
int my_putstr(char const *str);
void my_putchar(char);
