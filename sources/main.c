/*
** main.c for main in /home/plasko_a/rendu/prog_elem
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 25 03:17:18 2014 Antoine Plaskowski
** Last update Sun May  4 16:06:10 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

int		main(void)
{
  t_node	*node;
  t_uint	ant;

  ant = 0;
  if ((node = my_parse_file(&ant)) == NULL)
    return (1);
  if (my_level(node))
    {
      my_free_all_node(node);
      return (1);
    }
  my_game(node, ant);
  my_free_all_node(node);
  return (0);
}
