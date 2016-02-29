/*
** main.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun May  4 16:56:57 2014 rousse_3
** Last update Sun May  4 20:54:01 2014 rousse_3
*/

#include	<stdlib.h>
#include	"my_str.h"
#include	"parsing_bonus.h"

int		main()
{
  t_list	*file;
  t_room	*room;
  t_tube	*tube;
  t_move	*move;
  int		ant;

  if (!(file = my_read_file()))
    return (-1);
  if (!(ant = my_parse_bonus(&file, &room, &tube, &move)))
    return (-1);
  my_sdl(room, tube, move);
  return (0);
}
