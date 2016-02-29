/*
** my_read_file.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu May  1 20:45:49 2014 rousse_3
** Last update Sun May  4 18:08:25 2014 rousse_3
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"
#include	"my_str.h"

static int	my_check_ant(const char *str)
{
  if (my_is_num(str))
    return (0);
  if (my_sign_nbr(str) == -1)
    return (0);
  return (1);
}

extern int	my_check_room(const char *str)
{
  int		i;

  i = 0;
  if (my_check_name(str, &i, ' ') == 0)
    return (0);
  if (str[i] != '\0')
    i++;
  if (my_check_nbr(str, &i, ' ') == 0)
    return (0);
  if (str[i] != '\0')
    i++;
  if (my_check_nbr(str, &i, '\0') == 0)
    return (0);
  return (1);
}

extern int	my_check_tube(const char *str)
{
  int		i;

  i = 0;
  if (!(my_check_nbr(str, &i, '-')))
    return (0);
  if (str[i] != '\0')
    i++;
  if (!(my_check_nbr(str, &i, '\0')))
    return (0);
  return (1);
}

extern int	my_check_move(const char *str)
{
  int		i;

  if (str[0] != 'P')
    return (0);
  i = 1;
  if (!(my_check_nbr(str, &i, '-')))
    return (0);
  if (str[i] != '\0')
    i++;
  if (!(my_check_name(str, &i, ' ')))
    return (0);
  if (str[i] != '\0')
    return (my_check_move(str + i + 1));
  return (1);
}

static int	(*ptr_check[4])(const char *str) =
{
  &my_check_ant,
  &my_check_room,
  &my_check_tube,
  &my_check_move
};

extern t_list	*my_read_file(void)
{
  t_list	*file;
  char		*str;
  char		*epur;
  int		i;

  i = 0;
  file = NULL;
  while ((str = my_get_next_line(0)) != NULL)
    {
      epur = my_epur_str(str);
      free(str);
      if (epur[0] != '#')
	{
	  while (i < 4 && ptr_check[i](epur) != 1)
	    i++;
	  if (i > 4)
	    {
	      my_free_list(file);
	      return (NULL);
	    }
	}
      if (!(file = my_add_link(file, epur)))
	  return (NULL);
    }
  return (file);
}
