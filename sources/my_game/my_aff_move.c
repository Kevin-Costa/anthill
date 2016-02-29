/*
** my_aff_move.c for my_aff_move in /home/plasko_a/rendu/prog_elem/sources/my_game
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 23 23:14:59 2014 Antoine Plaskowski
** Last update Fri Apr 25 02:13:52 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_str.h"

int		my_aff_move(t_uint ant, char *name)
{
  static int	first = 0;

  if (ant == 0 || name == NULL)
    {
      my_putchar('\n', 1);
      first = 0;
      return (0);
    }
  if (first)
    my_putchar(' ', 1);
  else
    first = 1;
  my_putchar('P', 1);
  my_putnbr(ant, 1);
  my_putchar('-', 1);
  my_putstr(name, 1);
  return (0);
}
