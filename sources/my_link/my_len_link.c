/*
** my_len_link.c for my_len_link in /home/costa_b/rendu/prog_elem/sources/my_link
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun May  4 16:47:17 2014 Kevin Costa
** Last update Sun May  4 16:47:18 2014 Kevin Costa
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_uint		my_len_link(t_link *link)
{
  t_uint	i;

  i = 0;
  while (link != NULL)
    {
      i++;
      link = link->next;
    }
  return (i);
}
