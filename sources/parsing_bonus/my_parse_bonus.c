/*
** my_parse_file.c for lem-in in /home/rousse_3/rendu/prog_elem/sources/parsing_bonus
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Fri May  2 13:36:12 2014 rousse_3
** Last update Sun May  4 16:46:01 2014 rousse_3
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"

extern int	my_parse_bonus(t_list **file, t_room **room,
			       t_tube **tube, t_move **move)
{
  int		ant;

  if ((ant = my_get_ant(file)) == 0)
    return (0);
  if (!(*room = my_get_room(file)))
    return (0);
  if (!(*tube = my_get_tube(file, *room)))
    return (0);
  if (!(*move = my_get_move(file, *room, *tube)))
    return (0);
  return (ant);
}
