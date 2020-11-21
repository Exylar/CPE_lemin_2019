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

void add_t_connection(int tnum1, int tnum2, map_t *m)
{
    if (!(tnum1 == -1 || tnum2 == -1)) {
        add_connection(&(m->rooms[tnum1]), tnum2);
        add_connection(&(m->rooms[tnum2]), tnum1);
    }
}

void get_path(map_t *m, char **item)
{
    int tnum1;
    int tnum2;
    char **temp_p;
    int current = 0;

    for (; item[current] != NULL; current++) {
        if (test_one_path(item[current]) == 0) {
            temp_p = my_pars(clear_data(item[current]), '-');
            tnum1 = find_room(temp_p[0], m);
            tnum2 = find_room(temp_p[1], m);
            add_t_connection(tnum1, tnum2, m);
        }
    }
}

int get_nb_ant(char **item)
{
    int rtrn = 0;

    for (int i = 0; item[i] != NULL; i++) {
        if (my_str_isnum(item[i]) == 1)
            return (my_getnbr(item[i]));
    }
    return (-1);
}

map_t *get_map(char *str)
{
    char **item;
    map_t *rtrn = malloc(sizeof(map_t));
    int current = 0;

    rtrn->id_end = 0;
    rtrn->id_start = 0;
    rtrn->nb_room = 0;
    item = my_pars(str, '\n');
    print_map(item);
    if ((rtrn->nb_ant = get_nb_ant(item)) == -1)
        return (NULL);
    rtrn->rooms = malloc(sizeof(room_t) * get_nb_room(&item[current]));
    get_room(rtrn, &item[current], &current);
    get_path(rtrn, &item[current]);
    return (rtrn);
}