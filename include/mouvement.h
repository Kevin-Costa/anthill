/*
** mouvement.h for mouvement.h in /home/costa_b/rendu/prog_elem/mouvement
** 
** Made by Kevin Costa
** Login   <costa_b@epitech.net>
** 
** Started on  Sun May  4 16:24:33 2014 Kevin Costa
** Last update Sun May  4 23:06:23 2014 Antoine Plaskowski
*/

#ifndef		MOUVEMENT_H_
# define	MOUVEMENT_H_

void		chemin(SDL_Rect *position, SDL_Rect *position_bis,
		       SDL_Surface *ecran);
void		ch_left(SDL_Rect *position, int x, SDL_Surface *ecran);
void		ch_top(SDL_Rect *position, int y, SDL_Surface *ecran);
void		ch_down(SDL_Rect *position, int y, SDL_Surface *ecran);
void		ch_right(SDL_Rect *position, int x, SDL_Surface *ecran);
void		pause(void);
void		right(SDL_Rect *position, int x, SDL_Surface *ecran);
void		down(SDL_Rect *position, int y, SDL_Surface *ecran);
void		top(SDL_Rect *position, int y, SDL_Surface *ecran);
void		left(SDL_Rect *position, int x, SDL_Surface *ecran);
void		move(SDL_Rect *position, SDL_Rect *position_bis,
		     SDL_Surface *ecran);

#endif		/* !MOUVEMENT_H */
