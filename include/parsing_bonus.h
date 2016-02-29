/*
** parsing_bonus.h for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu May  1 20:35:27 2014 rousse_3
** Last update Sun May  4 23:08:06 2014 Antoine Plaskowski
*/

#ifndef		PARSING_BONUS_H_
# define	PARSING_BONUS_H_

#include	<SDL/SDL.h>

typedef	struct	s_list
{
  struct s_list *prev;
  char		*data;
  struct s_list	*next;
}		t_list;

typedef	struct	s_room
{
  struct s_room	*prev;
  int		flag;
  char		*name;
  SDL_Rect	*position;
  struct s_room *next;
}		t_room;

typedef	struct	s_tube
{
  struct s_tube	*prev;
  SDL_Rect	*position;
  SDL_Rect	*position_bis;
  struct s_tube	*next;
}		t_tube;

typedef	struct	s_move
{
  struct s_move	*prev;
  int		pid;
  SDL_Rect	*position;
  struct s_move	*next;
}		t_move;

typedef	struct	s_ant
{
  struct s_ant	*prev;
  int		pid;
  SDL_Rect	*position;
  struct s_ant	*next;
}		t_ant;

int		my_check_nbr(const char*, int*, const char);
int		my_check_name(const char*, int*, const char);
int		my_check_comment(const char*);
t_list		*my_add_link(t_list*, char*);
int		my_check_room(const char*);
t_room		*my_add_room(t_room*, char*, const SDL_Rect*, const int);
int		my_check_tube(const char*);
t_tube		*my_add_tube(t_tube*, const SDL_Rect*, const SDL_Rect*);
int		my_check_move(const char*);
t_move		*my_add_move(t_move*, const int, SDL_Rect*);
void		my_get_next_data(t_list**);
int		my_get_ant(t_list**);
char		*my_extract_name(const char*, const int, const int);
int		my_extract_nbr(const char*, const int, const int);
t_room		*my_get_room(t_list**);
void		my_cp_pos(const SDL_Rect*, const SDL_Rect*);
int		is_same_pos(const SDL_Rect*, const SDL_Rect*);
int		my_check_is_link(SDL_Rect*, SDL_Rect*,
				 SDL_Rect*, SDL_Rect*);
t_tube		*my_get_tube(t_list**, t_room*);
t_move		*my_get_move(t_list**, t_room*, t_tube*);
t_list		*my_read_file(void);
void		my_free_list(t_list*);
int		my_parse_bonus(t_list**, t_room**, t_tube**, t_move**);
int		my_create_path(t_tube*, SDL_Surface*);
void		my_pause();
int		my_move_ant(t_move*, SDL_Surface*, t_room*, SDL_Surface*);
void		my_sdl(t_room*, t_tube*, t_move*);

#endif /* !PARSING_BONUS_H */
