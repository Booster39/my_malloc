/*
** EPITECH PROJECT, 2022
** cal
** File description:
** cal
*/
#include "../include/my_malloc.h"

void *calloc(size_t number, size_t size)
{
    size_t *p = NULL;
    size_t c = 0;
    size_t nb = number * size;

    void *pointer = malloc(nb);
    memset(pointer, 0, nb);
    return p;
}