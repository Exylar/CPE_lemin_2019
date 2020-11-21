/*
** EPITECH PROJECT, 2019
** PSU_my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

void *get_my_str(char **my_str, va_list ap, int *j)
{
    char *s = va_arg(ap, char *);

    *my_str = my_realloc(*my_str, sizeof(char) * my_strlen(*my_str) + 1,
    sizeof(char) * ((my_strlen(*my_str) + my_strlen(s)) + 1));
    *my_str = my_strcat(*my_str, s);
    *j = *j + my_strlen(s);
}

void get_my_number(char **my_str, va_list ap, int *j)
{
    int n = va_arg(ap, int);

    char *num = my_nbr_to_str(n);
    *my_str = my_realloc(*my_str, sizeof(char) * my_strlen(*my_str) + 1,
    sizeof(char) * (my_strlen(*my_str) + my_strlen(num) + 1));
    *my_str = my_strcat(*my_str, num);
    *j = *j + my_strlen(num);
    free(num);
}

void get_my_char(char **my_str, va_list ap, int *j)
{
    char c = (char)va_arg(ap, int);

    *my_str = my_realloc(*my_str, sizeof(char) * my_strlen(*my_str) + 1,
    sizeof(char) * (my_strlen(*my_str) + 3));
    my_str[0][*j] = c;
    *j = *j + 1;
    my_str[0][*j] = '\0';
}

struct arg my_arg[] = {
    {'s', (void *)&get_my_str},
    {'d', (void *)&get_my_number},
    {'i', (void *)&get_my_number},
    {'c', (void *)&get_my_char},
};

void check_argument(char arg, char **my_str, va_list ap, int *j)
{
    for (int i = 0; i < 4; i++)
        if (my_arg[i].type == arg) {
            my_arg[i].fct(my_str, ap, j);
        }
}

void my_printf(char *str, ...)
{
    va_list ap;
    char *my_str = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;
    int j = 0;

    my_str[0] = '\0';
    va_start(ap, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            check_argument(str[i], &my_str, ap, &j);
            i++;
        } else {
            my_str[j] = str[i];
            my_str[j + 1] = '\0';
            i++;
            j++;
        }
    } my_putstr(my_str);
    va_end(ap);
    free(my_str);
}
