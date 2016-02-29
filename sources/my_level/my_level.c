/*
** my_level.c for my_level in /home/plasko_a/rendu/prog_elem/sources/my_level
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Apr 18 21:19:13 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:13:00 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static t_link	*my_init_level(t_node *node)
{
  t_link	*link;

  if ((link = my_new_link()) == NULL)
    return (NULL);
  if ((link->node = my_end_node(node)) == NULL)
    return (NULL);
  return (link);
}

int		my_level(t_node *node)
{
  t_link	*link;

  if (node == NULL)
    return (1);
  if ((link = my_init_level(node)) == NULL)
    return (1);
  link->node->level = 1;
  while (link != NULL)
    link = my_put_level(link);
  return (my_check_level(node));
}
