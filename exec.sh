rm a.out
clear
gcc main.c
make re
LD_PRELOAD=./libmy_malloc.so $1
