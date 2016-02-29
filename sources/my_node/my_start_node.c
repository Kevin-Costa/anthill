/*
** my_start_node.c for my_start_node in /home/plasko_a/rendu/prog_elem
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Apr 24 20:47:19 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:12:28 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_node		*my_start_node(t_node *node)
{
  node = my_first_node(node);
  while (node != NULL)
    {
      if (node->stage & MY_START)
	return (node);
      node = node->next;
    }
  return (NULL);
}
