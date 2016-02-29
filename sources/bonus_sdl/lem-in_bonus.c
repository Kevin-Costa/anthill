/*
** test.c for lem-in in /home/makusa_n/depot_git/prog_elem/bonus_sdl
** 
** Made by Nayden Makusa
** Login   <makusa_n@epitech.net>
** 
** Started on  Mon Apr 28 17:09:37 2014 Nayden Makusa
** Last update Sun May  4 22:31:27 2014 Nayden Makusa
*/

#include	<SDL/SDL.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"parsing_bonus.h"

static void	my_show_room(t_room *room, SDL_Surface **ecran,
			     SDL_Surface *rectangle)
{
  while (room)
    {
      room->position->x = room->position->x * 25;
      room->position->y = room->position->y * 25;
      SDL_BlitSurface(rectangle, NULL, *ecran, room->position);
      room = room->next;
    }
}

static void	my_verif(SDL_Surface **ecran, SDL_Surface **rectangle)
{
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      printf("Erreur d'initialisation de la SDL : \n");
      printf("%s\n", SDL_GetError());
      exit(1);
    }
  if (!((*ecran) = SDL_SetVideoMode(510, 510, 32, SDL_SWSURFACE)))
    {
      printf("Impossible de charger le mode video de la SDL : \n");
      printf("%s\n", SDL_GetError());
      exit(1);
    }
  if (!((*rectangle) = SDL_CreateRGBSurface
	(SDL_SWSURFACE, 25, 25, 32, 0, 0, 0, 0)))
    {
      printf("Impossible de charger le rectangle de la SDL : \n");
      printf("%s\n", SDL_GetError());
      exit(1);
    }
}

static void	check_list(t_room *room)
{
  while (room)
    {
      if (room->position->x >= 30 || room->position->x < 0 ||
	  room->position->y >= 30 || room->position->y < 0)
  	{
	  printf("Erreur. La position des salles doit etre comprise entre ");
	  printf("0 et 30 pour pouvoir utiliser l'interface graphique.\n");
  	  exit(1);
  	}
      room = room->next;
    }
}

void		my_sdl(t_room *room, t_tube *tube, t_move *move)
{
  SDL_Surface	*ecran;
  SDL_Surface	*rectangle;

  ecran = NULL;
  rectangle = NULL;
  my_verif(&ecran, &rectangle);
  SDL_FillRect(ecran, NULL, 0xA0522D);
  SDL_FillRect(rectangle, NULL, 0x006400);
  check_list(room);
  my_create_path(tube, ecran);
  my_show_room(room, &ecran, rectangle);
  my_move_ant(move, ecran, room, rectangle);
  SDL_Flip(ecran);
  SDL_WM_SetCaption("Le-min makusa_n", NULL);
  my_pause();
  SDL_FreeSurface(rectangle);
  SDL_Quit();
}
