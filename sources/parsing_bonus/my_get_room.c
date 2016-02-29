/*
** my_get_room.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sat May  3 16:26:47 2014 rousse_3
** Last update Sun May  4 18:00:56 2014 rousse_3
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"
#include	"my_str.h"

static void	my_extract_room(const char *str, char **name,
				int *x, int *y)
{
  int		i;
  int		j;

  i = 0;
  my_check_name(str, &i, ' ');
  *name = my_extract_name(str, 0, i);
  if (str[i] != '\0')
    i++;
  j = i;
  my_check_nbr(str, &i, ' ');
  *x = my_extract_nbr(str, j, i);
  if (str[i] != '\0')
    i++;
  j = i;
  my_check_nbr(str, &i, '\0');
  *y = my_extract_nbr(str, j, i);
}

static void	my_check_same_room(const char *name,
				   const SDL_Rect *position,
				   t_room *room)
{
  while (room != NULL)
    {
      if (!(my_strcmp(room->name, name)) ||
	  (room->position->x == position->x
	   && room->position->y == position->y))
	{
	  my_putstr("Same room\n", 2);
	  exit (0);
	}
      room = room->next;
    }
}

static int	my_get_flag(t_list **file)
{
  int		flag;

  flag = 0;
  if (my_strcmp("##start", (*file)->data) == 0)
    flag = 1;
  if (my_strcmp("##end", (*file)->data) == 0)
    flag = 2;
  if (flag != 0)
    my_get_next_data(file);
  return (flag);
}

extern t_room	*my_get_room(t_list **file)
{
  t_room	*room;
  char		*name;
  SDL_Rect	position;
  int		flag;

  room = NULL;
  name = NULL;
  flag = 0;
  while ((*file) != NULL &&
	 ((flag = my_get_flag(file)) != -1 &&
	  my_check_room((*file)->data)))
    {
      my_extract_room((*file)->data, &name,
		      (int*)(&position.x), (int*)(&position.y));
      my_check_same_room(name, &position, room);
      if ((room = my_add_room(room, name, &position, flag)) == NULL)
	return (NULL);
      my_get_next_data(file);
    }
  return (room);
}
