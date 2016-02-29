/*
** my_aff_node.c for my_aff_node in /home/plasko_a/rendu/CPE_2013_lem_in/sources
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Apr 17 15:41:02 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:11:11 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static int	my_aff_stage(t_uchar stage, const int fd)
{
  my_putstr("\nstage = ", fd);
  if (!stage)
    my_putstr("node\n", fd);
  else if (stage & MY_START)
    my_putstr("start\n", fd);
  else if (stage & MY_END)
    my_putstr("end\n", fd);
  else
    my_putstr("?\n", fd);
  return (0);
}

int		my_aff_node(t_node *node, const int fd)
{
  node = my_first_node(node);
  while (node != NULL)
    {
      my_putstr("name = ", fd);
      my_putstr(node->name, fd);
      my_putstr("\nlink = ", fd);
      my_aff_link(node->link, fd);
      my_putstr("x = ", fd);
      my_putnbr(node->x, fd);
      my_putstr("\ny = ", fd);
      my_putnbr(node->y, fd);
      my_putstr("\nlevel = ", fd);
      my_putnbr(node->level, fd);
      my_aff_stage(node->stage, fd);
      node = node->next;
    }
  return (0);
}
