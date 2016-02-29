/*
** my_pos.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sat May  3 18:09:50 2014 rousse_3
** Last update Sun May  4 16:45:26 2014 rousse_3
*/

#include	<SDL/SDL.h>

extern void	my_cp_pos(SDL_Rect *position,
			  const SDL_Rect *position_bis)
{
  position->x = position_bis->x;
  position->y = position_bis->y;
}

extern int	is_same_pos(const SDL_Rect *position,
			    const SDL_Rect *position_bis)
{
  return (position->x == position_bis->x &&
	  position->y == position_bis->y);
}

extern int	my_check_is_link(SDL_Rect *tube_pos, SDL_Rect *tube_pos_bis,
				 SDL_Rect *pos, SDL_Rect *pos_bis)
{
  if (is_same_pos(tube_pos, pos) && is_same_pos(tube_pos_bis, pos_bis))
    return (1);
  if (is_same_pos(tube_pos, pos_bis) && is_same_pos(tube_pos_bis, pos))
    return (1);
  return (0);
}
