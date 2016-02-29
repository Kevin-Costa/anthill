/*
** my_create_link_node.c for my_create_link_node in /home/plasko_a/rendu/prog_elem
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu May  1 19:53:30 2014 Antoine Plaskowski
** Last update Thu May  1 19:56:13 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_link		*my_create_link_node(t_link *old, t_node *node)
{
  t_link	*link;

  if ((link = my_new_link()) == NULL)
    return (NULL);
  link->node = node;
  return (my_put_link(old, link));
}

