/*
** my_prepare_push_ant.c for my_prepare_push_ant in /home/plasko_a/rendu/prog_elem/sources/my_game
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May  1 19:44:45 2014 Antoine Plaskowski
** Last update Thu May  1 20:11:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static int	my_link_already(t_node *node, t_link *already)
{
  while (already != NULL)
    {
      if (node == already->node)
	return (1);
      already = already->next;
    }
  return (0);
}

static t_node	*my_max_level(t_link *link, t_link *already)
{
  t_node	*node;
  t_uint	max;

  max = 0;
  node = NULL;
  while (link != NULL)
    {
      if (link->node->level && my_link_already(link->node, already) == 0)
	{
	  if (max < link->node->level || max == 0)
	    {
	      node = link->node;
	      max = link->node->level;
	    }
	}
      link = link->next;
    }
  return (node);
}

t_link		*my_prepare_push_ant(t_node *node)
{
  t_link	*link;
  t_node	*tmp;
  t_node	*start;

  link = NULL;
  if (node == NULL || (start = my_start_node(node)) == NULL)
    return (NULL);
  while ((tmp = my_max_level(start->link, link)) != NULL)
    if ((link = my_create_link_node(link, tmp)) == NULL)
      return (NULL);
  return (link);
}
