/*
** my_game.c for my_game in /home/plasko_a/rendu/prog_elem/sources/my_game
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Mon Apr 21 11:50:20 2014 Antoine Plaskowski
** Last update Sun May  4 15:59:05 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static t_uint	my_max_level(t_node *node)
{
  t_node	*start;
  t_link	*tmp;
  t_uint	max;

  max = 0;
  if ((start = my_start_node(node)) == NULL)
    tmp = NULL;
  else
    tmp = start->link;
  while (tmp != NULL)
    {
      if (max < tmp->node->level)
	max = tmp->node->level;
      tmp = tmp->next;
    }
  return (max);
}

int		my_game(t_node *node, t_uint ant)
{
  t_node	*end;
  t_link	*link;
  t_uint	max;
  t_uint	current;

  if (node == NULL
      || (end = my_end_node(node)) == NULL
      || (link = my_prepare_push_ant(node)) == NULL
      || (max = my_max_level(node)) == 0)
    return (1);
  current = 0;
  while (42)
    {
      if (my_follow_ant(node, max) && current >= ant)
	{
	  my_free_all_link(link);
	  return (0);
	}
      current = my_push_ant(link, ant, current);
      end->ant = 0;
      my_aff_move(0, NULL);
    }
  return (1);
}
