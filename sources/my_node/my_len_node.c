/*
** my_len_node.c for my_len_node in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 06:50:12 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:12:07 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_uint		my_len_node(t_node *node)
{
  t_uint	i;

  node = my_first_node(node);
  i = 0;
  while (node != NULL)
    {
      i++;
      node = node->next;
    }
  return (i);
}
