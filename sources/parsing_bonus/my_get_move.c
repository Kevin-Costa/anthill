/*
** my_get_move.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun May  4 16:44:06 2014 rousse_3
** Last update Sun May  4 23:20:03 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"
#include	"my_str.h"

static t_ant	*my_init_ant(void)
{
  t_ant		*ant;

  if (!(ant = my_malloc(sizeof(t_ant))))
    return (0);
  if (!(ant->position = my_malloc(sizeof(SDL_Rect))))
    return (0);
  ant->prev = NULL;
  ant->next = NULL;
  return (ant);
}

static int	my_extract_move(const char *str, t_ant **ant,
				int *i, t_room *room)
{
  int		j;
  char		*name;

  *ant = my_init_ant();
  j = *i;
  my_check_nbr(str, i, '-');
  (*ant)->pid = my_extract_nbr(str, j, *i);
  if (str[*i] != '\0')
    (*i)++;
  j = *i;
  my_check_name(str, i, ' ');
  name = my_extract_name(str, j, *i);
  while (room != NULL && my_strcmp(room->name, name) != 0)
    room = room->next;
  if (room == NULL)
    return (0);
  my_cp_pos((*ant)->position, room->position);
  free(name);
  if (str[*i] != '\0')
    {
      (*i) += 2;
      return (1);
    }
  else
    return (-1);
}

static int	my_add_ant(t_ant **ant, t_ant *new, t_room *room, t_tube *tube)
{
  while (room != NULL && room->flag != 1)
    room = room->next;
  if (room == NULL)
    return (0);
  while (tube != NULL && my_check_is_link(tube->position,
					  tube->position_bis,
					  room->position, new->position) != 1)
    tube = tube->next;
  if (tube == NULL)
    return (0);
  if ((*ant))
    {
      while ((*ant)->next != NULL)
	(*ant) = (*ant)->next;
      (*ant)->next = new;
    }
  new->prev = *ant;
  while (new->prev != NULL)
    new = new->prev;
  (*ant) = new;
  return (1);
}

static int	my_check_ant(t_ant **ant, t_tube *tube, t_ant *new,
			     t_room *room)
{
  t_ant		*tmp;

  tmp = *ant;
  while (tmp != NULL && tmp->pid != new->pid)
    tmp = tmp->next;
  if (tmp == NULL)
    my_add_ant(ant, new, room, tube);
  else
    {
      while (tube != NULL && my_check_is_link(tube->position,
					      tube->position_bis,
					      (*ant)->position,
					      new->position) != 1)
	tube = tube->next;
      if (tube == NULL)
	return (0);
      my_cp_pos((*ant)->position, new->position);
    }
  return (1);
}

extern t_move	*my_get_move(t_list **file, t_room *room, t_tube *tube)
{
  t_move	*move;
  t_ant		*ant;
  t_ant		*tmp;
  int		i;
  int		error;

  move = NULL;
  ant = NULL;
  while ((*file) != NULL && my_check_move((*file)->data))
    {
      i = 1;
      error = 1;
      while (error == 1)
	{
	  if ((error = my_extract_move((*file)->data,
				       &tmp, &i, room)) == 0)
	    return (NULL);
	  my_check_ant(&ant, tube, tmp, room);
	  move = my_add_move(move, tmp->pid, tmp->position);
	}
      my_get_next_data(file);
    }
  return (move);
}
