/*
** EPITECH PROJECT, 2019
** map_lemin
** File description:
** map and room
*/

typedef struct room
{
    char *name;
    int *connection;
    int nb_connection;
    int ant;
    int num;
    int coord_x;
    int coord_y;
} room_t;

typedef struct map
{
    room_t *rooms;
    int id_start;
    int id_end;
    int nb_room;
    int nb_ant;
} map_t;

#ifndef LEM_IN_H
#define LEM_IN_H

char **my_pars(char *str, char sep);
int get_nb_room(char **begin);
int test_one_room(char *str);
int test_one_path(char *str);
char *clear_data(char *str);
int nb_comment(char **c);
void make_room(char *str, room_t *room);
void get_room(map_t *m, char **item, int *current);
void add_connection(room_t *room, int new_path);
int find_room(char *room, map_t *m);
map_t *get_map(char *str);
int *cal_shortless_path(map_t *map, int value);
int get_short_path(map_t *map, int pos, int *count, int value);
map_t *pathfinder(map_t *map, int value);
void set_value(map_t *map, int count, int i);
void check_value(map_t *map, int i, int j, int count);
void reset_value(map_t *map);
int is_path(char *str);
//move ants
void move_ants(map_t *map, int **path);
void move_start(map_t *map, int *path, int i);
void move_end(map_t *map, int *path, int i);
void move_mid(map_t *map, int *path, int i);
void print_map(char **item);
int get_loc_ant(char **item);
void print_ant(char *str);
#endif