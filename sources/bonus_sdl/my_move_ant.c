/*
** my_move_ant.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun May  4 17:45:45 2014 rousse_3
** Last update Sun May  4 23:22:24 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"
#include	"mouvement.h"
#include	"my_str.h"

static void	my_show_room(t_room *room, SDL_Surface **ecran,
			     SDL_Surface *rectangle)
{
  while (room)
    {
      SDL_BlitSurface(rectangle, NULL, *ecran, room->position);
      room = room->next;
    }
}

t_ant		*my_check_pid(int pid, t_ant *ant)
{
  while (ant != NULL && ant->pid != pid)
    ant = ant->next;
  return (ant);
}

t_ant		*my_create_ant(t_ant **ant, t_room *room, int pid)
{
  t_ant		*new;

  while (room != NULL && room->flag != 1)
    room = room->next;
  if (room == NULL)
    return (NULL);
  if (!(new = my_malloc(sizeof(t_ant))))
    return (NULL);
  if (!(new->position = my_malloc(sizeof(SDL_Rect))))
    return (NULL);
  my_cp_pos(new->position, room->position);
  new->pid = pid;
  new->next = NULL;
  while ((*ant) != NULL && (*ant)->next != NULL)
    (*ant) = (*ant)->next;
  if ((*ant) != NULL)
    (*ant)->next = new;
  new->prev = (*ant);
  *ant = new;
  while ((*ant)->prev != NULL)
    (*ant) = (*ant)->prev;
  return (new);
}

int		my_move_ant(t_move *moves, SDL_Surface *ecran,
			    t_room *room, SDL_Surface *rectangle)
{
  t_ant		*ant;
  t_ant		*tmp;

  ant = NULL;
  while (moves)
    {
      if (!(tmp = my_check_pid(moves->pid, ant)))
	tmp = my_create_ant(&ant, room, moves->pid);
      moves->position->x *= 25;
      moves->position->y *= 25;
      move(tmp->position, moves->position, ecran);
      moves = moves->next;
      my_show_room(room, &ecran, rectangle);
    }
  return (0);
}
