/*
** EPITECH PROJECT, 2019
** util_map
** File description:
** util map
*/

#include "../include/lem_in.h"
#include "../include/my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int is_path(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            return (0);
    }
    return (1);
}

int get_nb_room(char **item)
{
    int rtrn = 0;

    for (int i = 0; is_path(item[i]); i++) {
        if (test_one_room(item[i]) == 0)
            rtrn++;
    }
    rtrn++;
    return (rtrn);
}

int nb_comment(char **c)
{
    int current = 0;

    while (c[current][0] == '#')
        current++;
    return (current);
}

void add_connection(room_t *room, int new_path)
{
    int *temp = malloc(sizeof(int) * (room->nb_connection + 1));

    for (int i = 0; i < room->nb_connection; i++)
        temp[i] = room->connection[i];
    temp[room->nb_connection] = new_path;
    (room->nb_connection)++;
    room->connection = temp;
}

int find_room(char *room, map_t *m)
{
    int rtrn = 0;

    while (rtrn < m->nb_room && my_strcmp(room, m->rooms[rtrn].name) != 0)
        rtrn++;
    if (rtrn == m->nb_room)
        return (-1);
    return (rtrn);
}
