/*
** my_get_ant.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sat May  3 13:01:19 2014 rousse_3
** Last update Sat May  3 13:02:09 2014 rousse_3
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"parsing_bonus.h"

extern int	my_get_ant(t_list **file)
{
  int		ant;

  if (file == NULL || *file == NULL)
    return (0);
  ant = my_getnbr((*file)->data);
  my_get_next_data(file);
  return (ant);
}
