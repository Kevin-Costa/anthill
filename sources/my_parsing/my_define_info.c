/*
** my_define_info.c for my_define_info in /home/plasko_a/rendu/CPE_2013_lem_in/sources/my_parsing
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Thu Apr 17 17:28:51 2014 Antoine Plaskowski
** Last update Fri Apr 25 03:13:22 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"

static t_node	*my_check_comment(t_node *node, char *str, t_uchar *stage)
{
  if (*str++ == '#')
    {
      if (my_strcmp(str, "start") == 0)
	{
	  if (*stage)
	    my_putstr("Warning the stage node was already set\n", 2);
	  *stage = MY_START;
	}
      else if (my_strcmp(str, "end") == 0)
	{
	  if (*stage)
	    my_putstr("Warning the stage node was already set\n", 2);
	  *stage = MY_END;
	}
      else
	my_putstr("Unknown command\n", 2);
    }
  return (node);
}

static int	my_check_tab(char **tab, int *info)
{
  int		len;

  len = my_len_tab(tab);
  if (len == 3 && *info == 0)
    return (0);
  else if (len == 2 && *info == 0)
    {
      *info = 1;
      return (0);
    }
  else if (len == 2 && *info == 1)
    return (0);
  *info = 2;
  return (0);
}

t_node			*my_define_info(t_node *node, char *str, int *info)
{
  static t_uchar	stage = 0;
  t_node		*tmp;
  char			**tab;

  if (str == NULL || info == NULL)
    return (NULL);
  if (*str == '#')
    return (my_check_comment(node, str + 1, &stage));
  if ((tab = my_str_to_tab(str, " -\t")) == NULL)
    return (NULL);
  my_check_tab(tab, info);
  if (*info == 0)
    {
      if ((tmp = my_parse_node(node, tab, stage)) == NULL)
	*info = 2;
      else
	node = tmp;
      stage = 0;
    }
  else if (*info == 1 && my_parse_link(node, tab))
    *info = 2;
  my_free_tab(tab);
  return (node);
}
