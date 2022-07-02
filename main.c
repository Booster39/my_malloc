/*
** EPITECH PROJECT, 2021
** My malloc
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "include/my_malloc.h"

#define getVarName(var) #var

void my_putnbr(size_t nb)
{
    size_t i = 0;

    if (nb > 9)
        my_putnbr(nb / 10);
    i = nb % 10 + 48;
    write(1, &i, 1);
}

int main(void)
{
    srand(time(NULL));
    size_t size = 100;
    const size_t ptr_tab_len = 1000;
    int *ptr1[ptr_tab_len];

    for (size_t i = 0; i < ptr_tab_len; ++i) {
        size = rand() % 10001;
        write(1, "size in main = ", 16);
        my_putnbr(size);
        write(1, "\n", 1);
        fflush(NULL);
        ptr1[i] = calloc(size, sizeof(int));
    }
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
/////test1////
/*
void try(int input, int wanted)
{
    if (input != wanted)
        printf("\x1B[31mFAIL\033[0m\n");
    else
        printf("\x1B[32mOKAY\033[0m\n");
}

int main(void)
{
    char *test = malloc(5);
    int i;

    if (test == NULL) {
        write(1, "Malloc failed\n", strlen("Malloc failed\n"));
        return (0);
    }

    test[0] = 't';
    test[1] = 'e';
    test[2] = 's';
    test[3] = 't';
    test[4] = '\0';
    printf("*test == test : ");
    try(strcmp(test, "test") == 0, 1);

    free(test);

    char *lol = malloc(18);
    lol[0] = 'l';
    lol[1] = 'o';
    lol[2] = 'l';
    lol[3] = '\0';
    printf("*lol == lol : ");
    try(strcmp(lol, "lol") == 0, 1);

    free(lol);

    char *big = malloc(22);
    for (i = 0; i < 21; i++)
        big[i] = 'a' + i;
    big[i] = '\0';
    printf("*big == [a-u] : ");
    try(strcmp(big, "abcdefghijklmnopqrstu") == 0, 1);

    //////////////////////////////////////// fail because of malloc not used best fit
    /// best fit comprare with page size NOT Block size
    printf("big == test : ");
    try(big == test, 1);

    printf("\n");

    char *newbig = realloc(big, 150);
    printf("newbig != big : ");
    try(newbig == big, 0);

    char *newbig2 = realloc(newbig, 22);
    printf("newbig == newbig2 : ");
    try(newbig == newbig2, 1);
    printf("*newbig2 == [a-u] : ");
    try(strcmp(newbig2, "abcdefghijklmnopqrstu") == 0, 1);
    free(newbig2);
    return (0);
}
*/
/*

/// test2/////
void try(int input, int wanted)
{
    if (input != wanted)
        printf("\x1B[31mFAIL\033[0m\n");
    else
        printf("\x1B[32mOKAY\033[0m\n");
}

int main(void)
{
    int *ints;
    int i;

    ints = malloc(4 * sizeof(int));
    for (i = 0; i < 4; i++)
        ints[i] = i + 1337;
    for (i = 0; i < 4; i++) {
        printf("ints[%d] == %d : ", i, i + 1337);
        try(ints[i] == i + 1337, 1);
    }
    free(ints);

    void *pos = sbrk(0);

    char *pows = malloc(3274);
    free(pows);
    printf("pos == sbrk(0) : ");
    try(pos == sbrk(0), 1);
    // printf("pos(%p) != sbrk(%p)\n", pos, sbrk(0));

    return (0);
}
*/
////test3//////
/*
int	try(int input, int wanted)
{
  if (input != wanted)
    write(0, "\x1B[31mFAIL\033[0m\n", 15);
  else
    write(0, "\x1B[32mOKAY\033[0m\n", 15);
  return (input == wanted);
}

int main(void)
{
    int *ints;
    int *prev;
    void *pos;
    int i;

    pos = sbrk(0);
    t_block head = pos;
    for (i = 1; i <= 10000; i++)
    {
        ints = malloc(4 * (rand() % 10000) * sizeof(int));
        free(ints);
        write(0, "sbrk(0) == pos : \n", 19);
        if (!try(sbrk(0) == pos, 1))
            write(0, "check your adress block", 10);
    }
    return (0);
}
*/

/////test4//////

/*
int	main(void)
{
  char	*var = malloc(5);

  free(var);
  free(var);

  return (0);
}
*/
/// test5

/*
void try(int input, int wanted)
{
    if (input != wanted)
        printf("\x1B[31mFAIL\033[0m\n");
    else
        printf("\x1B[32mOKAY\033[0m\n");
}

int main(void)
{
    char *datas = malloc(150);
    //t_block head = get_block_adress(datas); //get your frist metadata adress for test it
    //pr_list(head);//check your list block
    printf("==========================\n");

    free(datas);
    //pr_list(head);//check your list block
    printf("==========================\n");

    char *p1 = malloc(15);
    char *p2 = malloc(121);
    //pr_list(head);//check your list block

    return (0);
}
*/

/// test6////
/*
int	try(int input, int wanted)
{
  if (input != wanted)
    write(0, "\x1B[31mFAIL\033[0m\n", 15);
  else
    write(0, "\x1B[32mOKAY\033[0m\n", 15);
  return (input == wanted);
}

int main(void)
{
    char * tmp = sbrk(0);
    char *lil = malloc(42);
    free(lil);

    char *big = malloc(1457664);
    free(big);

    try(sbrk(0) == tmp, 1);
    return (0);
}
*/