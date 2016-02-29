/*
** my_sup_link.c for my_sup_link in /home/plasko_a/rendu/prog_elem/sources/my_level
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Apr 24 23:15:48 2014 Antoine Plaskowski
** Last update Thu Apr 24 23:17:43 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_link		*my_sup_link(t_link *link)
{
  t_link	*tmp;

  if (link == NULL)
    return (NULL);
  tmp = link->next;
  my_free_link(link);
  return (tmp);
}
