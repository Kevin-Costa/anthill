/*
** my_push_ant.c for my_push_ant in /home/plasko_a/rendu/prog_elem/sources/my_game
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 23 22:34:36 2014 Antoine Plaskowski
** Last update Fri May  2 03:01:02 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static double	my_rule_the_game(t_link *link, t_link *tmp, t_uint tmp_cu)
{
  t_uint	max;

  max = 0;
  while (tmp != link && tmp != NULL)
    {
      if (link->node->level != tmp->node->level && tmp->node->ant == tmp_cu)
	{
	  tmp_cu++;
	  max += link->node->level - tmp->node->level;
	}
      tmp = tmp->next;
    }
  return (max);
}

t_uint		my_push_ant(t_link *link, t_uint ant, t_uint current)
{
  t_link	*tmp;
  t_uint	tmp_cu;

  tmp_cu = current + 1;
  tmp = link;
  while (link != NULL)
    {
      if (link->node->ant == 0 && current < ant
	  && my_rule_the_game(link, tmp, tmp_cu) <= ant - current)
	{
	  link->node->ant = ++current;
	  my_aff_move(current, link->node->name);
	}
      link = link->next;
    }
  return (current);
}
