/*
** my_parse_node.c for my_parse_node in /home/plasko_a/rendu/lem_in/sources/my_parsing
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Apr 16 14:55:03 2014 Antoine Plaskowski
** Last update Sun May  4 18:02:37 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"
#include	"my_str.h"

static int	my_check_error(t_node *node, char *name, int x, int y)
{
  node = my_first_node(node);
  while (node != NULL)
    {
      if (my_strcmp(node->name, name) == 0)
	return (my_put_error("This node already exist\n"));
      if (node->x == x && node->y == y)
	return (my_put_error("This coord already exist\n"));
      node = node->next;
    }
  return (0);
}

t_node		*my_parse_node(t_node *old, char **tab, t_uchar stage)
{
  t_node	*node;
  int		x;
  int		y;

  if (my_len_tab(tab) != 3)
    return (NULL);
  x = my_getnbr(tab[1]);
  y = my_getnbr(tab[2]);
  if (my_check_error(old, tab[0], x, y))
    return (NULL);
  if ((node = my_new_node()) == NULL)
    return (NULL);
  node->stage = stage;
  if ((node->name = my_strdup(tab[0])) == NULL)
    return (NULL);
  node->x = x;
  node->y = y;
  return (my_put_node(old, node));
}
