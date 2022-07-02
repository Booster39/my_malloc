/*
** EPITECH PROJECT, 2022
** malll
** File description:
** malll
*/

#include "../include/my_malloc.h"

my_bloca *free_mem(my_bloca *h, size_t si)
{
    size_t two = 2;
    size_t odd = 2;
    my_bloca *pointer = sbrk(0);

    while ((odd * getpagesize()) < si) {
        two = odd;
        odd += 2;
    }
    void *ask = sbrk(two * getpagesize());
    if (ask == ((void *) -1))
        return NULL;
    if (h)
        h->nxt = pointer;
    
    pointer->s = si;
    pointer->nxt = NULL;
    pointer->free = 0;
    return pointer;
}

void align_to_power_two(size_t *s)
{
  *s += META_SIZE;
  --*s;
  *s = (*s | *s >> 1);
  *s = (*s | *s >> 2);
  *s = (*s | *s >> 4);
  *s = (*s | *s >> 8);
  *s = (*s | *s >> 16);
  ++*s;
}

my_bloca *search_mem(my_bloca **new_p, size_t si)
{
  my_bloca *pointer = have;
  my_bloca *this;

  for (this = have; this != NULL; this = this->nxt) {
    *new_p = this;
    if (this->free == 1 && this->s == si)
      return this;
  }
  while (pointer && !(pointer->free && pointer->s >= si)) {
    *new_p = pointer;
    pointer = pointer->nxt;
  }
  return pointer;
}

void *malloc(size_t s)
{
    my_bloca *pointer;

    if (s == 0 || !s) {
        sbrk(2 * getpagesize());
        return NULL;
    }
    align_to_power_two(&s);
    if (!have) {
        pointer = free_mem(NULL, s);
        if (!pointer)
            return NULL;
        have = pointer;
    } else {
        my_bloca *new_p = have;
        pointer = search_mem(&new_p, s);
        if (!pointer) {
            pointer = free_mem(new_p, s);
            if (!pointer)
                return NULL;
        }
        else
            pointer->free = 0;
    }
    return (pointer + 1);
}

void free(void *str)
{
    my_bloca *pointer;

    if (!str)
        return;
    pointer = ((my_bloca *)str - 1);
    pointer->free = 1;
}

void *calloc(size_t number, size_t size)
{
    size_t nb = number * size;

    void *pointer = malloc(nb);
    memset(pointer, 0, nb);
    return pointer;
}

void *realloc(void *pointer, size_t size)
{
    my_bloca *ptr;
    void *h;

    if (!pointer)
        return malloc(size);
    if (size == 0) {
        sbrk(2 * getpagesize());
        return NULL;
    }

    ptr = ((my_bloca *)pointer - 1);
    if (ptr->s >= size)
        return pointer;

    h = malloc(size);
    if (h == NULL)
        return NULL;

    memcpy(h, pointer, ptr->s);
    free(pointer);
    return h;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return realloc(ptr, nmemb * size);
}