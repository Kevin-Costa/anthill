/*
** my_parse_link.c for my_parse_link in /home/plasko_a/rendu/lem_in/sources/my_parsing
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 16 15:19:29 2014 Antoine Plaskowski
** Last update Sun May  4 21:40:26 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static int	my_check_link(t_node *node_1, t_node *node_2)
{
  t_link	*tmp;

  tmp = node_1->link;
  while (tmp != NULL)
    {
      if (tmp->node == node_2)
	return (my_put_error("Warning this link already exist\n"));
      tmp = tmp->next;
    }
  return (0);
}

static int	my_create_link(t_node *node_1, t_node *node_2)
{
  t_link	*link;

  if (my_check_link(node_1, node_2) || my_check_link(node_2, node_1))
    return (0);
  if ((link = my_new_link()) == NULL)
    return (1);
  link->node = node_2;
  if ((node_1->link = my_put_link(node_1->link, link)) == NULL)
    return (1);
  if ((link = my_new_link()) == NULL)
    return (1);
  link->node = node_1;
  if ((node_2->link = my_put_link(node_2->link, link)) == NULL)
    return (1);
  return (0);
}

int		my_parse_link(t_node *node, char **tab)
{
  t_node	*node_1;
  t_node	*node_2;

  if (my_len_tab(tab) != 2)
    return (1);
  node = my_first_node(node);
  if ((node_1 = my_found_node(node, tab[0])) == NULL)
    return (my_put_error("This node doesn't exist\n"));
  if ((node_2 = my_found_node(node, tab[1])) == NULL)
    return (my_put_error("This node doesn't exist\n"));
  if (my_create_link(node_1, node_2))
    return (1);
  return (0);
}
