/*
** my_get_tube.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sat May  3 20:07:29 2014 rousse_3
** Last update Sun May  4 18:09:33 2014 rousse_3
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"
#include	"my_str.h"

static int	my_extract_tube(const char *str, SDL_Rect *position,
				SDL_Rect *position_bis, t_room *room)
{
  int		i;
  int		j;
  char		*name;
  t_room	*tmp;

  i = 0;
  my_check_name(str, &i, '-');
  name = my_extract_name(str, 0, i);
  if (str[i] != '\0')
    i++;
  tmp = room;
  while (tmp != NULL && my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  free(name);
  j = i;
  my_check_name(str, &i, '\0');
  name = my_extract_name(str, j, i);
  while (room != NULL && my_strcmp(room->name, name) != 0)
    room = room->next;
  if (tmp == NULL || room == NULL)
    return (0);
  my_cp_pos(position, tmp->position);
  my_cp_pos(position_bis, room->position);
  free(name);
  return (1);
}

static int	my_check_position(const SDL_Rect *position,
				  const SDL_Rect *position_bis, t_tube *tube)
{
  while (tube != NULL)
    {
      if ((is_same_pos(position, tube->position) &&
	   is_same_pos(position_bis, tube->position_bis)) ||
	  (is_same_pos(position_bis, tube->position) &&
	   is_same_pos(position, tube->position_bis)) ||
	  is_same_pos(position, position_bis))
	return (1);
      tube = tube->next;
    }
  return (0);
}

extern t_tube	*my_get_tube(t_list **file, t_room *room)
{
  t_tube	*tube;
  SDL_Rect	position;
  SDL_Rect	position_bis;

  tube = NULL;
  while ((*file) != NULL && my_check_tube((*file)->data))
    {
      if (my_extract_tube((*file)->data, &position, &position_bis, room) == 0)
	return (NULL);
      if (my_check_position(&position, &position_bis, tube))
	return (NULL);
      tube = my_add_tube(tube, &position, &position_bis);
      my_get_next_data(file);
    }
  return (tube);
}
