/*
** my_new_node.c for my_new_node in /home/plasko_a/rendu/CPE_2014_corewar/src_vm
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Sun Apr 13 01:01:04 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:12:14 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"
#include	"my_str.h"

t_node		*my_new_node(void)
{
  t_node	*node;

  if ((node = my_calloc(sizeof(t_node))) == NULL)
    return (NULL);
  node->prev = NULL;
  node->name = NULL;
  node->link = NULL;
  node->x = 0;
  node->y = 0;
  node->stage = 0;
  node->level = 0;
  node->ant = 0;
  node->next = NULL;
  return (node);
}
