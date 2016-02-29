/*
** my_found_node.c for my_found_node in /home/plasko_a/rendu/prog_elem/sources
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Apr 24 20:39:45 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:11:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_node		*my_found_node(t_node *node, char *name)
{
  node = my_first_node(node);
  while (node != NULL)
    {
      if (my_strcmp(node->name, name) == 0)
	return (node);
      node = node->next;
    }
  return (NULL);
}
