/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "../include/lem_in.h"
#include "../include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int get_buff(char *buff)
{
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, 30000 - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    return len;
}

int main(void)
{
    map_t *map;
    char buff[30000 + 1];
    int len = get_buff(buff);
    int **paths;

    if (len < 0)
        return (84);
    map = get_map(buff);
    if (map == NULL)
        return (84);
    paths = malloc(sizeof(int *) * map->rooms[map->id_start].nb_connection);
    paths[0] = malloc(1);
    paths[0][0] = -1;
    for (int j = 0; pathfinder(map, 0) != NULL; j++) {
        paths[j] = cal_shortless_path(map, -j - 1);
        reset_value(map);
        map->rooms[map->id_start].num = 0;
    } if (paths[0][0] == -1)
        return 0;
    move_ants(map, paths);
    return (0);
}