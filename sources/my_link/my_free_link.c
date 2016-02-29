/*
** my_free_link.c for my_free_link in /home/plasko_a/rendu/prog_elem
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Fri Apr 18 15:12:39 2014 Antoine Plaskowski
** Last update Thu Apr 24 21:06:47 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

void		my_free_link(t_link *link)
{
  free(link);
}

void		my_free_all_link(t_link *link)
{
  t_link	*tmp;

  while (link != NULL)
    {
      tmp = link;
      link = link->next;
      my_free_link(tmp);
    }
}
