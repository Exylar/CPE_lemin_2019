/*
** EPITECH PROJECT, 2019
** test map
** File description:
** test map
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/lem_in.h"
#include "../include/my.h"

int test_one_room(char *str)
{
    char **room = my_pars(str, ' ');
    int size = 0;

    if (str[0] == '#')
        return (-1);
    while (room[size] != NULL)
        size++;
    if (size < 3)
        return (-1);
    for (int i = 0; i < size; i++) {
        if (my_strlen(room[i]) < 1)
            return (-1);
    }
    return (0);
}

char *clear_data(char *str)
{
    int size = 0;
    char *rtrn;

    for (; str[size] != '\0' && str[size] != '#'; size++);
    rtrn = malloc(size);
    for (int i = 0; i < size; i++) {
        rtrn[i] = str[i];
    }
    return (rtrn);
}

int test_one_path(char *str)
{
    char **path = my_pars(str, '-');
    int size = 0;

    if (str[0] == '#')
        return (-1);
    while (path[size] != NULL)
        size++;
    if (size < 2)
        return (-1);
    for (int i = 0; i < size; i++) {
        if (my_strlen(path[i]) < 1)
            return (-1);
    }
    return (0);
}