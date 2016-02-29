/*
** my_add_link.c for lem_in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu May  1 21:20:46 2014 rousse_3
** Last update Sun May  4 23:19:41 2014 Antoine Plaskowski
*/

#include	<SDL/SDL.h>
#include	<stdlib.h>
#include	"my_str.h"
#include	"parsing_bonus.h"

extern t_list	*my_add_link(t_list *file, char *str)
{
  t_list	*new;

  if (!(new = my_malloc(sizeof(t_list))))
    return (NULL);
  new->next = NULL;
  new->data = str;
  if (file != NULL)
    {
      while (file->next != NULL)
	file = file->next;
      file->next = new;
    }
  new->prev = file;
  while (new->prev != NULL)
    new = new->prev;
  return (new);
}

extern t_room	*my_add_room(t_room *room, char *name,
			     const SDL_Rect *position, int flag)
{
  t_room	*new;

  if ((new = my_malloc(sizeof(t_room))) == NULL)
    return (NULL);
  new->next = NULL;
  new->name = name;
  if ((new->position = my_malloc(sizeof(SDL_Rect))) == NULL)
    return (NULL);
  my_cp_pos(new->position, position);
  new->flag = flag;
  if (room != NULL)
    {
      while (room->next != NULL)
	room = room->next;
      room->next = new;
    }
  new->prev = room;
  while (new->prev != NULL)
    new = new->prev;
  return (new);
}

extern t_tube	*my_add_tube(t_tube *tube,
			     const SDL_Rect *position,
			     const SDL_Rect *position_bis)
{
  t_tube	*new;

  if (!(new = my_malloc(sizeof(t_tube))))
    return (NULL);
  new->next = NULL;
  if (!(new->position = my_malloc(sizeof(SDL_Rect))))
    return (NULL);
  if (!(new->position_bis = my_malloc(sizeof(SDL_Rect))))
    return (NULL);
  my_cp_pos(new->position, position);
  my_cp_pos(new->position_bis, position_bis);
  if (tube != NULL)
    {
      while (tube->next != NULL)
	tube = tube->next;
      tube->next = new;
    }
  new->prev = tube;
  while (new->prev != NULL)
    new = new->prev;
  return (new);
}

extern t_move	*my_add_move(t_move *move, const int pid, SDL_Rect *position)
{
  t_move	*new;

  if (!(new = my_malloc(sizeof(t_move))))
    return (NULL);
  new->next = NULL;
  new->pid = pid;
  if (!(new->position = my_malloc(sizeof(SDL_Rect))))
    return (NULL);
  my_cp_pos(new->position, position);
  if (move)
    {
      while (move->next)
	move = move->next;
      move->next = new;
    }
  new->prev = move;
  while (new->prev)
    new = new->prev;
  return (new);
}
