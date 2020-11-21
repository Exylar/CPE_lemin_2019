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

int get_short_path(map_t *map, int pos, int *count, int value)
{
    for (int i = 0; i < map->rooms[pos].nb_connection; i++) {
        if (map->rooms[map->rooms[pos].connection[i]].num == *count - 1) {
            map->rooms[map->rooms[pos].connection[i]].num = value;
            pos = map->rooms[pos].connection[i];
            *count = *count - 1;
            return pos;
        }
    }
}