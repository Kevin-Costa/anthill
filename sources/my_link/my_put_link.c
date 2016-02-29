/*
** my_put_room.c for my_put_link in /home/plasko_a/rendu/CPE_2014_corewar/src_vm/my_link
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Apr 13 06:21:26 2014 Antoine Plaskowski
** Last update Thu Apr 24 21:14:04 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

t_link		*my_put_link(t_link *old, t_link *link)
{
  if (link != NULL)
    link->next = old;
  else
    link = old;
  return (link);
}
