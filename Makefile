##
## EPITECH PROJECT, 2022
## ma
## File description:
## ma
##

CC	=	gcc

RM	=	rm -f

SRCS	=	src/my_malloc.c\


OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy_malloc.so

CPPFLAGS	=	-Wall -Wextra -Wno-deprecated -g3 -fPIC -I ./include/

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -fPIC -shared -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
	$(RM) $(OBJS)
	$(RM) $(SRCS:.c=.c~)
	$(RM) $(SRCS:.c=.c#)
	$(RM) Makefile~
	$(RM) include/*.h~
	$(RM) include/*.h~#
	$(RM) rm -f *.o

fclean:	clean
	$(RM) $(NAME)

re: fclean all