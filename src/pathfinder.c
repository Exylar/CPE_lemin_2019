/*
** EPITECH PROJECT, 2019
** pathfinder
** File description:
** pathfinder
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/lem_in.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

void reset_value(map_t *map)
{
    for (int i = 0; i < map->nb_room; i++) {
        if (map->rooms[i].num >= 0)
            map->rooms[i].num = 0;
    }
}

void check_value(map_t *map, int i, int j, int count)
{
    if (map->rooms[map->rooms[i].connection[j]].num == 0)
        map->rooms[map->rooms[i].connection[j]].num = count + 1;
}

void set_value(map_t *map, int count, int i)
{
    if (map->rooms[i].num == count) {
        for (int j = 0; j < map->rooms[i].nb_connection; j++)
            check_value(map, i, j, count);
    }
}

map_t *pathfinder(map_t *my_map, int value)
{
    int count = 1;
    my_map->rooms[my_map->id_start].num = count;

    while (count <= my_map->nb_room &&
    my_map->rooms[my_map->id_end].num == 0) {
        for (int i = 0; i < my_map->nb_room; i++)
            set_value(my_map, count, i);
        count++;
    }
    if (my_map->rooms[my_map->id_end].num == 0)
        return NULL;
    return my_map;
}

int *cal_shortless_path(map_t *map, int value)
{
    int count = map->rooms[map->id_end].num;
    int pos = map->id_end;
    int *path = malloc(sizeof(int) * map->nb_room + 1);

    path[0] = map->id_end;
    while (map->rooms[map->id_start].num == 1) {
        pos = get_short_path(map, pos, &count, value);
        path[map->rooms[map->id_end].num - count] = pos;
        path[map->rooms[map->id_end].num - count + 1] = -1;
    }
    return path;
}