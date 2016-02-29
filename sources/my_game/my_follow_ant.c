/*
** my_follow_ant.c for my_follow_ant in /home/plasko_a/rendu/prog_elem/sources
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 23 21:43:30 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:14:30 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static int	my_move_ant(t_node *node)
{
  t_link	*tmp;

  tmp = node->link;
  while (tmp != NULL)
    {
      if (node->level == tmp->node->level + 1 && tmp->node->ant == 0)
	{
	  if (!tmp->node->stage)
	    tmp->node->ant = node->ant;
	  my_aff_move(node->ant, tmp->node->name);
	  node->ant = 0;
	  return (1);
	}
      tmp = tmp->next;
    }
  return (0);
}

int		my_follow_ant(t_node *node, t_uint max)
{
  t_node	*tmp;
  t_uint	level;
  int		ret;

  ret = 1;
  level = 2;
  while (level <= max)
    {
      tmp = node;
      while (tmp != NULL)
	{
	  if (tmp->level == level && tmp->ant)
	    if (my_move_ant(tmp))
	      ret = 0;
	  tmp = tmp->next;
	}
      level++;
    }
  return (ret);
}
