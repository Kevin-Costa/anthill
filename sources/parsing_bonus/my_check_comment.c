/*
** my_check_comment.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sat May  3 12:59:10 2014 rousse_3
** Last update Sat May  3 13:00:55 2014 rousse_3
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"parsing_bonus.h"

extern int	my_check_comment(const char *data)
{
  if (data[0] != '#')
    return (0);
  if (data[1] == '#')
    {
      if (my_strcmp("##start", data) == 0)
	return (0);
      if (my_strcmp("##end", data) == 0)
	return (0);
    }
  return (1);
}
