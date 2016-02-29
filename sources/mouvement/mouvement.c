/*
** mouvement.c for mouvement in /home/costa_b/rendu/prog_elem/mouvement
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun May  4 16:47:50 2014 Kevin Costa
** Last update Sun May  4 23:14:35 2014 Antoine Plaskowski
*/

#include	"SDL/SDL.h"
#include	"mouvement.h"

void		right(SDL_Rect *position, int x, SDL_Surface *ecran)
{
  SDL_Surface	*fourmi;
  SDL_Surface	*test;
  int		delay;

  fourmi = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(fourmi, NULL, 0x992500);
  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  delay = 10000 / (x - position->x);
  while (position->x < x)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->x += 10;
      SDL_BlitSurface(fourmi, NULL, ecran, position);
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
      SDL_Delay(delay);
    }
}

void		down(SDL_Rect *position, int y, SDL_Surface *ecran)
{
  SDL_Surface	*fourmi;
  SDL_Surface	*test;
  int		delay;

  fourmi = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(fourmi, NULL, 0x992500);
  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  delay = 10000 / (y - position->y);
  while (position->y < y)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->y += 10;
      SDL_BlitSurface(fourmi, NULL, ecran, position);
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
      SDL_Delay(delay);
    }
}

void		top(SDL_Rect *position, int y, SDL_Surface *ecran)
{
  SDL_Surface	*fourmi;
  SDL_Surface	*test;
  int		delay;

  fourmi = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(fourmi, NULL, 0x992500);
  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  delay = 10000 / (position->y - y);
  while (position->y > y)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->y -= 10;
      SDL_BlitSurface(fourmi, NULL, ecran, position);
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
      SDL_Delay(delay);
    }
}

void		left(SDL_Rect *position, int x, SDL_Surface *ecran)
{
  SDL_Surface	*fourmi;
  SDL_Surface	*test;
  int		delay;

  fourmi = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(fourmi, NULL, 0x992500);
  test = SDL_CreateRGBSurface(SDL_HWSURFACE, 25, 25, 32, 0, 0, 0, 0);
  SDL_FillRect(test, NULL, 0xA76726);
  delay = 10000 / (position->x - x);
  while (position->x > x)
    {
      SDL_BlitSurface(test, NULL, ecran, position);
      position->x -= 10;
      SDL_BlitSurface(fourmi, NULL, ecran, position);
      SDL_WM_SetCaption("Lem-in !", NULL);
      SDL_Flip(ecran);
      SDL_Delay(delay);
    }
}

void		move(SDL_Rect *position, SDL_Rect *position_bis,
		     SDL_Surface *ecran)
{
  if (position->x < position_bis->x)
    right(position, position_bis->x, ecran);
  if (position->x > position_bis->x)
    left(position, position_bis->x, ecran);
  if (position->y < position_bis->y)
    down(position, position_bis->y, ecran);
  if (position->y > position_bis->y)
    top(position, position_bis->y, ecran);
}
