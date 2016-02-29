/*
** my_aff_link.c for my_aff_link in /home/costa_b/rendu/prog_elem/sources/my_link
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun May  4 16:46:46 2014 Kevin Costa
** Last update Sun May  4 16:46:49 2014 Kevin Costa
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

int		my_aff_link(t_link *link, const int fd)
{
  while (link != NULL)
    {
      if (link->node != NULL)
	my_putstr(link->node->name, fd);
      if ((link = link->next) != NULL)
	my_putchar(' ', fd);
    }
  my_putchar('\n', fd);
  return (0);
}
