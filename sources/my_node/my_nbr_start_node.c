/*
** my_nbr_start_node.c for my_nbr_start_node in /home/plasko_a/rstartu/prog_elem
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun May  4 15:59:24 2014 Antoine Plaskowski
** Last update Sun May  4 16:00:44 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_uint		my_nbr_start_node(t_node *node)
{
  t_uint	i;

  i = 0;
  node = my_first_node(node);
  while (node != NULL)
    {
      if (node->stage & MY_START)
	i++;
      node = node->next;
    }
  return (i);
}
