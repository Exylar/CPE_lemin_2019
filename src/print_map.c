/*
** EPITECH PROJECT, 2019
** get_map
** File description:
** get map
*/

#include "../include/lem_in.h"
#include "../include/my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void print_no_comment(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '#'; i++)
        my_putchar(str[i]);
}

int get_loc_ant(char **item)
{
    for (int i = 0; item[i] != NULL; i++) {
        if (my_str_isnum(item[i]) == 1)
            return (i);
    }
    return (-1);
}

int begin_room(char **item, int *ant_d)
{
    int i = 0;

    for (; (item[i] != NULL && test_one_room(item[i]) == -1) &&
    (my_strcmp(item[i], "##start")) &&
    (my_strcmp(item[i], "##end")); i++) {
        if (my_str_isnum(item[i]) == 1) {
            my_putstr("#number_of_ants\n");
            my_putstr(item[i]);
            my_putchar('\n');
            *ant_d = 1;
        }
    }
    return (i);
}

void print_room(char **item, int *i)
{
    my_putstr("#rooms\n");
    for (; (item[*i] != NULL && test_one_path(item[*i]) == -1); (*i)++) {
        if (my_strcmp(item[*i], "##start") == 0) {
            my_putstr("##start\n");
        } else if (my_strcmp(item[*i], "##end") == 0) {
            my_putstr("##end\n");
        } else if (test_one_room(item[*i]) == 0) {
            print_no_comment(item[*i]);
            my_putchar('\n');
        }
    }
}

void print_map(char **item)
{
    int l_at = get_loc_ant(item);
    int ant_d = 0;
    int i = begin_room(item, &ant_d);

    if (l_at == -1)
        exit (84);
    print_room(item, &i);
    my_putstr("#tunnels\n");
    for (; item[i] != NULL && ((ant_d == 0 && i < l_at) || ant_d == 1); i++) {
        if (test_one_room(item[i]) == 0)
            break;
        if (test_one_path(item[i]) == 0) {
            print_no_comment(item[i]);
            my_putchar('\n');
        }
    }
    if (ant_d == 0) {
        my_putstr("#number_of_ants\n");
        my_putstr(item[l_at]);
        my_putchar('\n');
    }
}