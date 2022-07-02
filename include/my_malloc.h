/*
** EPITECH PROJECT, 2022
** mallouer
** File description:
** mallouer
*/

#ifndef lo
#define lo

#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

typedef struct my_bloca {
    struct my_bloca *nxt;
    bool free;
    size_t s;
}my_bloca;

#define META_SIZE sizeof(struct my_bloca)

void *have = NULL;

typedef struct my_bloca *p_struct;
my_bloca *add_mem(my_bloca *pointer, size_t s);
my_bloca *free_mem(my_bloca *pointer, size_t si);
my_bloca *create_mem(my_bloca *pointer, size_t s);
void *malloc(size_t s);
my_bloca *get_b(void *pointer);
int adress(void *pointer);
my_bloca *comb(my_bloca *pointer);
void free(void *str);
void *realloc(void *pointer, size_t size);
void *calloc(size_t number, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif
