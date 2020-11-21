/*
** EPITECH PROJECT, 2019
** parsargs
** File description:
** pars args
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/lem_in.h"
#include "../include/my.h"

int my_size_db(char *begin)
{
    int rtrn = 0;

    while (begin[rtrn] != '\0' && begin[rtrn] != '"')
        rtrn++;
    if (begin[rtrn] != '\0')
        rtrn++;
    return (rtrn);
}

int my_size_wd(char *begin, char separateur)
{
    int rtrn = 0;

    while (begin[rtrn] != '\0' && begin[rtrn] != separateur)
        rtrn++;
    return (rtrn);
}

int my_count_nb_word(char *args, char separateur)
{
    int rtrn = 0;
    int size_word = 0;
    int size = my_strlen(args);

    for (int i = 0; i < size; i++) {
        if (args[i] == '"')
            size_word = (my_size_db(&args[i + 1]));
        else
            size_word = (my_size_wd(&args[i], separateur));
        i += size_word;
        if (size_word > 0)
            rtrn++;
    }
    return (rtrn);
}

char **my_pars(char *args, char separateur)
{
    int nb_arg = my_count_nb_word(args, separateur);
    char **rtrn = malloc(sizeof(char *) * (nb_arg + 1));
    int size_word = 0;
    int current = 0;

    for (int i = 0; i < nb_arg; current += size_word) {
        if (args[current] == '"') {
            size_word = (my_size_db(&args[current + 1]) - 1);
            current += 2;
        } else {
            size_word = (my_size_wd(&args[current], separateur));
            current++;
        }
        if (size_word > 0) {
            rtrn[i] = my_strndup(&args[current - 1], size_word);
            i++;
        }
    }
    rtrn[nb_arg] = NULL;
    return (rtrn);
}
