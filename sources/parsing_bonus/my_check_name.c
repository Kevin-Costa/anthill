/*
** my_check_name.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu May  1 21:14:24 2014 rousse_3
** Last update Sat May  3 12:31:32 2014 rousse_3
*/

extern int	my_check_name(const char *str, int *i, const char end)
{
  int		tmp;

  tmp = *i;
  while (str[tmp] != end && str[tmp] != '\0')
    {
      if (str[tmp] == '-' || str[tmp] == '#')
	return (0);
      tmp++;
    }
  *i = tmp;
  return (1);
}
