/*
** my_found_coord_node.c for my_found_coord_node in /home/plasko_a/rendu/CPE_2013_lem_in/sources/my_parsing
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Apr 17 16:29:20 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:11:34 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_node		*my_found_coord_node(t_node *node, int x, int y)
{
  node = my_first_node(node);
  while (node != NULL)
    {
      if (node->x == x && node->y == y)
	return (node);
      node = node->next;
    }
  return (NULL);
}
