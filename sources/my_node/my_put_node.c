/*
** my_put_node.c for my_put_node in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 06:21:26 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:22:25 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_node		*my_put_node(t_node *old, t_node *node)
{
  old = my_first_node(old);
  if (node != NULL)
    {
      node->next = old;
      node->prev = NULL;
    }
  else
    node = old;
  return (node);
}
