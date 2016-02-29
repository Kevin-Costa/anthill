/*
** my_free_node.c for my_free_node in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_node
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 03:17:57 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:11:51 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

void		my_free_node(t_node *node)
{
  if (node != NULL)
    {
      free(node->name);
      my_free_all_link(node->link);
    }
  free(node);
}

void		my_free_all_node(t_node *node)
{
  t_node	*tmp;

  node = my_first_node(node);
  while (node != NULL)
    {
      tmp = node;
      node = node->next;
      my_free_node(tmp);
    }
}
