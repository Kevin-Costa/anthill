/*
** my_put_level.c for my_put_level in /home/plasko_a/rendu/prog_elem/sources/my_solve
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sat Apr 19 17:45:29 2014 Antoine Plaskowski
** Last update Thu May  1 19:55:33 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_link		*my_put_level(t_link *old)
{
  t_link	*link;
  t_link	*tmp;

  link = NULL;
  while (old != NULL)
    {
      tmp = old->node->link;
      while (tmp != NULL)
	{
	  if (!tmp->node->level && !tmp->node->stage)
	    {
	      tmp->node->level = old->node->level + 1;
	      if ((link = my_create_link_node(link, tmp->node)) == NULL)
		return (NULL);
	    }
	  tmp = tmp->next;
	}
      old = my_sup_link(old);
    }
  return (link);
}
