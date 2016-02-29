##
## Makefile for Makefile in /home/plasko_a/rendu/CPE_2014_corewar
## 
## Made by Antoine Plaskowski
## Login   <plasko_a@epitech.net>
## 
## Started on  Tue Mar 25 13:37:17 2014 Antoine Plaskowski
## Last update Sun May  4 22:17:40 2014 Antoine Plaskowski
##

CC			=	gcc

DEBUG			=	0

LEVEL			=	3

RM			=	rm -f

MKDIR			=	mkdir -p

RMDIR			=	rmdir

CFLAGS			=	-Wall -Wextra -O$(LEVEL)
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-I include/

ifeq ($(DEBUG), 1)
CFLAGS			+=	-g
endif

LDFLAGS			=

BONUS_FLAGS		=	-lSDL -lSDLmain

DFLAGS			=	-Yinclude/ -w80

NAME			=	lem_in

BONUS			=	bonus

include				SRC.mk
include				BONUS.mk

OBJ			=	$(SRC:.c=.o)
OBJ_BONUS		=	$(SRC_BONUS:.c=.o)

all			:	$(NAME) $(BONUS)

$(NAME)			:	$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(BONUS)		:	$(OBJ_BONUS)
				$(CC) $(OBJ_BONUS) -o $(BONUS) $(BONUS_FLAGS)

clean			:
				$(RM) $(OBJ)
				$(RM) $(OBJ_BONUS)

fclean			:	clean
				$(RM) $(NAME)
				$(RM) $(BONUS)

re			:	fclean all


depend			:
				makedepend $(SRC) $(DFLAGS)
				makedepend $(SRC_BONUS) $(DFLAGS)

%.o			:	%.c
				$(CC) -c $< -o $@ $(CFLAGS)

%.s			:	%.c
				$(CC) -S $< -o $@ $(CFLAGS)

.PHONY			:	all clean fclean re %.o %.s

.SUFFIXES		:	.o.c .s.c

# DO NOT DELETE

sources/main.o: include/my_lem_in.h include/my_str.h include/my_typedef.h
sources/my_game/my_game.o: include/my_lem_in.h include/my_str.h
sources/my_game/my_game.o: include/my_typedef.h
sources/my_game/my_follow_ant.o: include/my_lem_in.h include/my_str.h
sources/my_game/my_follow_ant.o: include/my_typedef.h
sources/my_game/my_push_ant.o: include/my_lem_in.h include/my_str.h
sources/my_game/my_push_ant.o: include/my_typedef.h
sources/my_game/my_aff_move.o: include/my_str.h include/my_typedef.h
sources/my_game/my_prepare_push_ant.o: include/my_lem_in.h include/my_str.h
sources/my_game/my_prepare_push_ant.o: include/my_typedef.h
sources/my_level/my_level.o: include/my_lem_in.h include/my_str.h
sources/my_level/my_level.o: include/my_typedef.h
sources/my_level/my_put_level.o: include/my_lem_in.h include/my_str.h
sources/my_level/my_put_level.o: include/my_typedef.h
sources/my_level/my_check_level.o: include/my_lem_in.h include/my_str.h
sources/my_level/my_check_level.o: include/my_typedef.h
sources/my_parsing/my_parse_file.o: include/my_lem_in.h include/my_str.h
sources/my_parsing/my_parse_file.o: include/my_typedef.h
sources/my_parsing/my_parse_link.o: include/my_lem_in.h include/my_str.h
sources/my_parsing/my_parse_link.o: include/my_typedef.h
sources/my_parsing/my_parse_node.o: include/my_lem_in.h include/my_str.h
sources/my_parsing/my_parse_node.o: include/my_typedef.h
sources/my_parsing/my_define_info.o: include/my_lem_in.h include/my_str.h
sources/my_parsing/my_define_info.o: include/my_typedef.h
sources/my_node/my_new_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_new_node.o: include/my_typedef.h
sources/my_node/my_free_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_free_node.o: include/my_typedef.h
sources/my_node/my_put_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_put_node.o: include/my_typedef.h
sources/my_node/my_len_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_len_node.o: include/my_typedef.h
sources/my_node/my_first_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_first_node.o: include/my_typedef.h
sources/my_node/my_last_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_last_node.o: include/my_typedef.h
sources/my_node/my_aff_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_aff_node.o: include/my_typedef.h
sources/my_node/my_found_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_found_node.o: include/my_typedef.h
sources/my_node/my_start_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_start_node.o: include/my_typedef.h
sources/my_node/my_end_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_end_node.o: include/my_typedef.h
sources/my_node/my_nbr_start_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_nbr_start_node.o: include/my_typedef.h
sources/my_node/my_nbr_end_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_nbr_end_node.o: include/my_typedef.h
sources/my_node/my_found_coord_node.o: include/my_lem_in.h include/my_str.h
sources/my_node/my_found_coord_node.o: include/my_typedef.h
sources/my_link/my_new_link.o: include/my_lem_in.h include/my_str.h
sources/my_link/my_new_link.o: include/my_typedef.h
sources/my_link/my_free_link.o: include/my_lem_in.h include/my_str.h
sources/my_link/my_free_link.o: include/my_typedef.h
sources/my_link/my_put_link.o: include/my_lem_in.h include/my_str.h
sources/my_link/my_put_link.o: include/my_typedef.h
sources/my_link/my_len_link.o: include/my_lem_in.h include/my_str.h
sources/my_link/my_len_link.o: include/my_typedef.h
sources/my_link/my_aff_link.o: include/my_lem_in.h include/my_str.h
sources/my_link/my_aff_link.o: include/my_typedef.h
sources/my_link/my_sup_link.o: include/my_lem_in.h include/my_str.h
sources/my_link/my_sup_link.o: include/my_typedef.h
sources/my_link/my_create_link_node.o: include/my_lem_in.h include/my_str.h
sources/my_link/my_create_link_node.o: include/my_typedef.h
sources/my_str/my_putchar.o: include/my_str.h include/my_typedef.h
sources/my_str/my_putstr.o: include/my_str.h include/my_typedef.h
sources/my_str/my_putnbr.o: include/my_str.h include/my_typedef.h
sources/my_str/my_putnbr_base.o: include/my_str.h include/my_typedef.h
sources/my_str/my_strlen.o: include/my_typedef.h
sources/my_str/my_strcpy.o: include/my_typedef.h
sources/my_str/my_strncpy.o: include/my_typedef.h
sources/my_str/my_strdup.o: include/my_str.h include/my_typedef.h
sources/my_str/my_strndup.o: include/my_str.h include/my_typedef.h
sources/my_str/my_getnbr.o: include/my_str.h include/my_typedef.h
sources/my_str/my_getnbr_base.o: include/my_str.h include/my_typedef.h
sources/my_str/my_malloc.o: include/my_typedef.h include/my_str.h
sources/my_str/my_epur_str.o: include/my_str.h include/my_typedef.h
sources/my_str/my_str.o: include/my_str.h include/my_typedef.h
sources/my_str/my_open.o: include/my_str.h include/my_typedef.h
sources/my_str/my_get_next_line.o: include/my_str.h include/my_typedef.h
sources/my_str/my_tab.o: include/my_str.h include/my_typedef.h
sources/my_str/my_str_to_tab.o: include/my_str.h include/my_typedef.h
sources/my_str/my_put_error.o: include/my_str.h include/my_typedef.h
sources/parsing_bonus/my_check_comment.o: include/my_str.h include/my_typedef.h
sources/parsing_bonus/my_check_comment.o: include/parsing_bonus.h
sources/parsing_bonus/my_add_link.o: include/my_str.h include/my_typedef.h
sources/parsing_bonus/my_add_link.o: include/parsing_bonus.h
sources/parsing_bonus/my_read_file.o: include/parsing_bonus.h include/my_str.h
sources/parsing_bonus/my_read_file.o: include/my_typedef.h
sources/parsing_bonus/my_get_next_data.o: include/parsing_bonus.h
sources/parsing_bonus/my_get_ant.o: include/my_str.h include/my_typedef.h
sources/parsing_bonus/my_get_ant.o: include/parsing_bonus.h
sources/parsing_bonus/my_extract_data.o: include/parsing_bonus.h
sources/parsing_bonus/my_extract_data.o: include/my_str.h include/my_typedef.h
sources/parsing_bonus/my_get_room.o: include/parsing_bonus.h include/my_str.h
sources/parsing_bonus/my_get_room.o: include/my_typedef.h
sources/parsing_bonus/my_get_tube.o: include/parsing_bonus.h include/my_str.h
sources/parsing_bonus/my_get_tube.o: include/my_typedef.h
sources/parsing_bonus/my_parse_bonus.o: include/parsing_bonus.h
sources/parsing_bonus/my_parse_bonus.o: include/my_str.h include/my_typedef.h
sources/parsing_bonus/my_free_list.o: include/parsing_bonus.h
