/*
** my_extract_data.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sat May  3 13:04:48 2014 rousse_3
** Last update Sun May  4 18:09:42 2014 rousse_3
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"
#include	"my_str.h"

extern char	*my_extract_name(const char *data, const int beg, const int end)
{
  char		*str;
  int		i;

  if (!(str = my_malloc(sizeof(char) * (end - beg + 1))))
    return (NULL);
  i = beg;
  while (i < end)
    {
      str[i - beg] = data[i];
      i++;
    }
  str[i - beg] = '\0';
  return (str);
}

extern int	my_extract_nbr(const char *data, const int beg, const int end)
{
  char		*str;
  int		nb;

  str = my_extract_name(data, beg, end);
  nb = my_getnbr(str);
  return (nb);
}
