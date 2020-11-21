/*
** EPITECH PROJECT, 2019
** get_map2
** File description:
** get map2
*/

#include "../include/lem_in.h"
#include "../include/my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void make_room(char *str, room_t *room)
{
    char **line = my_pars(str, ' ');

    room->name = my_strdup(line[0]);
    room->coord_x = my_getnbr(line[1]);
    room->coord_y = my_getnbr(line[2]);
    room->nb_connection = 0;
    room->ant = 0;
    room->num = 0;
    for (int i = 0; line[i] != NULL; i++)
        free(line[i]);
    free(line);
}

void get_room(map_t *m, char **item, int *current)
{
    int end = 0;
    int start = 0;

    for (; is_path(item[*current]); (*current)++) {
        if (test_one_room(item[*current]) == 0) {
            make_room(item[*current], &(m->rooms[m->nb_room]));
            m->nb_room++;
        }
        if (my_strcmp(item[*current], "##end") == 0 && end == 0) {
            m->id_end = (m->nb_room);
            end = 1;
        }
        if (my_strcmp(item[*current], "##start") == 0 && start == 0) {
            m->id_start = (m->nb_room);
            start = 1;
        }
    }
    if (end == 0 || start == 0)
        exit(84);
}