/*
** EPITECH PROJECT, 2019
** move ants
** File description:
** move ants
*/

#include "../include/my.h"
#include "../include/lem_in.h"

int **delete_useless_path(int **path)
{
    int first_len = -1;
    int len = -1;

    while (path[0][++first_len] != -1);
    for (int i = 1; path[i] != NULL; ++i) {
        while (path[i][++len] != -1);
        if (len > (first_len * 2)) {
            path[i] = NULL;
            return path;
        }
        len = -1;
    }
    return path;
}

char move(map_t *map, int *path , char action)
{
    for (int i = 0; path[i + 1] != -1; ++i) {
        if (i == 0 && map->rooms[path[i + 1]].ant != 0) {
            (action == 1) ? my_putchar(' ') : 0;
            action = 1;
            move_start(map, path, i);
        }
        else if (path[i + 2] == -1 && map->rooms[path[i + 1]].ant > 0) {
            (action == 1) ? my_putchar(' ') : 0;
            action = 1;
            move_end(map, path, i);
        }
        else if (map->rooms[path[i + 1]].ant != 0) {
            (action == 1) ? my_putchar(' ') : 0;
            action = 1;
            move_mid(map, path, i);
        }
        if (map->rooms[map->id_end].ant > map->nb_ant)
            return action;
    }
    return action;
}

void move_ants(map_t *map, int **path)
{
    char action = 0;

    my_putstr("#moves\n");
    if (path[0] == NULL)
        return;
    path = delete_useless_path(path);
    map->rooms[map->id_start].ant = map->nb_ant;
    while (map->rooms[map->id_end].ant < map->nb_ant) {
        for (int i = 0; path[i] != NULL; ++i)
            action = move(map, path[i], action);
        action = 0;
        my_putchar('\n');
    }
}