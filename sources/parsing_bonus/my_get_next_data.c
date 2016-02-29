/*
** my_get_next_data.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sat May  3 13:03:17 2014 rousse_3
** Last update Sat May  3 13:03:47 2014 rousse_3
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"

extern void	my_get_next_data(t_list **file)
{
  int		tmp;
  t_list	*tmp_free;

  tmp = 1;
  while ((*file != NULL) && (tmp || my_check_comment((*file)->data)))
    {
      if (tmp == 1)
	tmp = 0;
      tmp_free = (*file);
      (*file) = (*file)->next;
      free(tmp_free->data);
      free(tmp_free);
    }
}
