/*
** my_parse_file.c for my_parse_file in /home/plasko_a/rendu/CPE_2013_lem_in/sources/my_parsing
** 
** Made by Antoine Plaskowski
** Login   <antoine.plaskowski@epitech.eu>
** 
** Started on  Wed Apr 16 23:11:21 2014 Antoine Plaskowski
** Last update Sun May  4 16:04:23 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_lem_in.h"
#include	"my_str.h"

static int	my_putstr_with_n(const char *str)
{
  my_putstr(str, 1);
  my_putchar('\n', 1);
  return (0);
}

static int	my_get_ant(t_uint *ant)
{
  char		*str;
  char		*epur;
  int		num;
  int		sign;

  if (ant == NULL)
    return (1);
  if ((str = my_get_next_line(0)) == NULL)
    return (1);
  if ((epur = my_epur_str(str)) == NULL)
    return (1);
  if ((num = my_is_num(epur)) == 1)
    my_putstr("The number of ant is not correct\n", 2);
  if ((sign = my_sign_nbr(epur)) == -1)
    my_putstr("The number of ant is negatif\n", 2);
  *ant = my_getnbr(epur);
  if (num == 0 && sign != -1)
    my_putstr_with_n(str);
  free(str);
  free(epur);
  return (num != 0 || sign == -1);
}

static t_node	*my_check_node(t_node *node)
{
  t_uint	start;
  t_uint	end;

  node = my_first_node(node);
  if ((start = my_nbr_start_node(node)) == 0)
    my_putstr("There are not start node\n", 2);
  else if (start > 1)
    my_putstr("There are too many start node\n", 2);
  if ((end = my_nbr_end_node(node)) == 0)
    my_putstr("There are not end node\n", 2);
  else if (end > 1)
    my_putstr("There are too many end node\n", 2);
  if (start != 1 || end != 1)
    {
      my_free_all_node(node);
      return (NULL);
    }
  return (node);
}

t_node		*my_parse_file(t_uint *ant)
{
  t_node	*node;
  char		*str;
  int		info;

  if (my_get_ant(ant))
    return (NULL);
  info = 0;
  node = NULL;
  while (info != 2 && (str = my_get_next_line(0)) != NULL)
    {
      node = my_define_info(node, str, &info);
      if (info != 2)
	my_putstr_with_n(str);
      free(str);
    }
  return (my_check_node(node));
}
