/*
** my_check_level.c for my_check_level in /home/plasko_a/rendu/prog_elem/sources/my_solve
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 23 20:14:06 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:12:55 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

int		my_check_level(t_node *node)
{
  t_node	*start;
  t_link	*tmp;

  start = my_start_node(node);
  tmp = start->link;
  while (tmp)
    {
      if (tmp->node->level)
	return (0);
      tmp = tmp->next;
    }
  return (my_put_error("Warning there are no path between start and end\n"));
}
