/*
** EPITECH PROJECT, 2022
** fr
** File description:
** fr
*/
#include "../include/my_malloc.h"

void free(void *str)
{
    my_bloca *pointer;

    if (!str)
        return;

    pointer = (my_bloca *)str - 1;
    pointer->free = 1;
}