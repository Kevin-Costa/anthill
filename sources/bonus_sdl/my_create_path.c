/*
** my_create_path.c for lem-in in /home/rousse_3/rendu/prog_elem
** 
** Made by rousse_3
** Login   <rousse_3@epitech.net>
** 
** Started on  Sun May  4 17:16:34 2014 rousse_3
** Last update Sun May  4 23:02:12 2014 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"parsing_bonus.h"
#include	"mouvement.h"

int		my_create_path(t_tube *tube, SDL_Surface *ecran)
{
  SDL_Rect	pos;
  SDL_Rect	pos_bis;

  while (tube)
    {
      my_cp_pos(&pos, tube->position);
      my_cp_pos(&pos_bis, tube->position_bis);
      pos.x *= 25;
      pos.y *= 25;
      pos_bis.x *= 25;
      pos_bis.y *= 25;
      chemin(&pos, &pos_bis, ecran);
      tube = tube->next;
    }
  return (0);
}
