/*
** my_check_nbr.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Thu May  1 21:10:19 2014 rousse_3
** Last update Sun May  4 17:57:39 2014 rousse_3
*/

extern int	my_check_nbr(const char *str, int *i, const char end)
{
  int		tmp;

  tmp = *i;
  while (str[tmp] == '-' && str[tmp] == '+')
    tmp++;
  while (str[tmp] != end && str[tmp] != '\0')
    {
      if (str[tmp] > '9' || str[tmp] < '0')
	return (0);
      tmp++;
    }
  *i = tmp;
  return (1);
}
