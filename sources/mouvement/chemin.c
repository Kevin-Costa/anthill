/*
** chemin.c for chemin in /home/costa_b/rendu/prog_elem/mouvement
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun May  4 16:19:13 2014 Kevin Costa
** Last update Sun May  4 22:50:20 2014 Nayden Makusa
*/

#include	"SDL/SDL.h"
#include	"mouvement.h"

void		chemin(SDL_Rect *position, SDL_Rect *position_bis,
		       SDL_Surface *ecran)
{
  if (position->x < position_bis->x)
    ch_right(position, position_bis->x, ecran);
  if (position->x > position_bis->x)
    ch_left(position, position_bis->x, ecran);
  if (position->y < position_bis->y)
    ch_down(position, position_bis->y, ecran);
  if (position->y > position_bis->y)
    ch_top(position, position_bis->y, ecran);
}

void		ch_left(SDL_Rect *position, int x, SDL_Surface *ecran)
{
  SDL_Surface	*test;

  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  while (position->x > x)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->x -= 10;
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
    }
}

void		ch_top(SDL_Rect *position, int y, SDL_Surface *ecran)
{
  SDL_Surface	*test;

  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  while (position->y > y)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->y -= 10;
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
    }
}

void		ch_down(SDL_Rect *position, int y, SDL_Surface *ecran)
{
  SDL_Surface	*test;

  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  while (position->y < y)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->y += 10;
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
    }
}
void		ch_right(SDL_Rect *position, int x, SDL_Surface *ecran)
{
  SDL_Surface	*test;

  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  while (position->x < x)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->x += 10;
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
    }
}
