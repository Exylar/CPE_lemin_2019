/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** alloc
*/

#include<stdlib.h>

char *my_strndup(char const *src, int n)
{
    int i = 0;
    char *rtrnd;

    rtrnd = malloc(sizeof(char) * (n + 1));
    for (; src[i] != '\0' && i < n; i++)
        rtrnd[i] = src[i];
    rtrnd[i] = '\0';
    return (rtrnd);
}
