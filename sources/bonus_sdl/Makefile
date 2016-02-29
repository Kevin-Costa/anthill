##
## Makefile for bonus in /home/makusa_n/depot_git/prog_elem/bonus_sdl
##
## Made by Nayden Makusa
## Login   <makusa_n@epitech.net>
##
## Started on  Mon Apr 28 17:33:36 CEST 2014 Nayden Makusa
##

CC		=	gcc

RM		=	rm -f

CFLAGS		+=	-Wall -pedantic -Wextra

LDFLAGS		+=	-lm

NAME		=	bonus

SRCS		=	lem-in_bonus.c \

OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -lSDL -lSDLmain -o $(NAME) $(LDFLAGS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
