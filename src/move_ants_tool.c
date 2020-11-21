/*
** EPITECH PROJECT, 2019
** move ants
** File description:
** move ants
*/

#include "../include/my.h"
#include "../include/lem_in.h"

void move_start(map_t *map, int *path, int i)
{
    my_printf("P%i-%s", map->rooms[path[i + 1]].ant, map->rooms[path[i]].name);
    map->rooms[path[i]].ant += 1;
    map->rooms[path[i + 1]].ant = 0;
}

void move_end(map_t *map, int *path, int i)
{
    map->rooms[path[i]].ant = map->nb_ant - map->rooms[path[i + 1]].ant + 1;
    map->rooms[path[i + 1]].ant -= 1;
    my_printf("P%i-%s", map->rooms[path[i]].ant, map->rooms[path[i]].name);
}

void move_mid(map_t *map, int *path, int i)
{
    map->rooms[path[i]].ant = map->rooms[path[i + 1]].ant;
    map->rooms[path[i + 1]].ant = 0;
    my_printf("P%i-%s", map->rooms[path[i]].ant, map->rooms[path[i]].name);
}