/*
** my_last_node.c for my_last_node in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_node
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 06:50:12 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:11:59 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_node		*my_last_node(t_node *node)
{
  if (node != NULL)
    while (node->next)
      node = node->next;
  return (node);
}
