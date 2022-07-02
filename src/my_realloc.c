/*
** EPITECH PROJECT, 2022
** ca
** File description:
** ca
*/
#include "../include/my_malloc.h"

void *realloc(void *pointer, size_t size)
{
    my_bloca *ptr;
    void *h;

    if (!pointer)
        return malloc(size);

    if (size == 0)
    {
        sbrk(2 * getpagesize());
        return NULL;
    }

    ptr = (my_bloca *)pointer - 1;
    if (ptr->s >= size)
        return pointer;

    h = malloc(size);
    if (h == NULL)
        return NULL;

    memcpy(h, pointer, ptr->s);
    free(pointer);
    return h;
}