/*
** my_new_link.c for my_new_link in /home/plasko_a/rendu/prog_elem/sources/my_link
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 25 03:15:41 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:15:42 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"
#include	"my_str.h"

t_link		*my_new_link(void)
{
  t_link	*link;

  if ((link = my_calloc(sizeof(t_link))) == NULL)
    return (NULL);
  link->node = NULL;
  link->next = NULL;
  return (link);
}
