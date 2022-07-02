/*
** EPITECH PROJECT, 2022
** re
** File description:
** re
*/
#include "../include/my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return realloc(ptr, nmemb * size);
}