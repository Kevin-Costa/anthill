/*
** my_free_list.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu May  1 21:29:44 2014 rousse_3
** Last update Thu May  1 21:31:51 2014 rousse_3
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"

extern void	my_free_list(t_list *list)
{
  while (!(list->next))
    list = list->next;
  while (!(list->prev))
    {
      list = list->prev;
      free(list->next->data);
      free(list->next);
    }
  free(list->next->data);
  free(list->next);
  free(list->data);
  free(list);
}
