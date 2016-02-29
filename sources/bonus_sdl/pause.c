/*
** pause.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun May  4 16:23:59 2014 rousse_3
** Last update Sun May  4 23:06:35 2014 Antoine Plaskowski
*/

#include	<SDL/SDL.h>

void		my_pause(void)
{
  int		tmp;
  SDL_Event	event;

  tmp = 1;
  while (tmp)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	tmp = 0;
      if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
        tmp = 0;
    }
}
