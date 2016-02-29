/*
** my_lem_in.h for my_lem_in in /home/plasko_a/rendu/prog_elem
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.eu>
** 
** Started on  Fri Apr 25 03:16:25 2014 Antoine Plaskowski
** Last update Sun May  4 16:05:20 2014 Antoine Plaskowski
*/

#ifndef		MY_LEM_IN_H_
# define	MY_LEM_IN_H_

# include	"my_str.h"

# define	MY_START	1
# define	MY_END		MY_START * 2

typedef	struct	s_node	t_node;
typedef	struct	s_link	t_link;

struct		s_node
{
  t_node	*prev;
  char		*name;
  t_link	*link;
  int		x;
  int		y;
  t_uint	level;
  t_uchar	stage;
  t_uint	ant;
  t_node	*next;
};

struct		s_link
{
  t_node	*node;
  t_link	*next;
};

/*
**
**		my_game
**
*/

int		my_game(t_node *node, t_uint ant);

int		my_follow_ant(t_node *node, t_uint max);

t_uint		my_push_ant(t_link *link, t_uint ant, t_uint current);

int		my_aff_move(t_uint ant, char *name);

t_link		*my_prepare_push_ant(t_node *node);

/*
**
**		my_level
**
*/

int		my_level(t_node *node);

int		my_check_level(t_node *node);

t_link		*my_put_level(t_link *old);

/*
**
**		my_parsing
**
*/

t_node		*my_parse_file(t_uint *ant);

t_node		*my_parse_node(t_node *node, char **tab, t_uchar stage);

int		my_parse_link(t_node *node, char **tab);

t_node		*my_define_info(t_node *node, char *str, int *info);

/*
**
**		my_node
**
*/

void		my_free_all_node(t_node *node);

void		my_free_node(t_node *node);

t_node		*my_new_node(void);

t_node		*my_put_node(t_node *old, t_node *node);

int		my_aff_node(t_node *node, const int fd);

t_node		*my_found_node(t_node *node, char *name);

t_node		*my_start_node(t_node *node);

t_node		*my_end_node(t_node *node);

t_uint		my_nbr_start_node(t_node *node);

t_uint		my_nbr_end_node(t_node *node);

t_node		*my_first_node(t_node *node);

t_node		*my_last_node(t_node *node);

t_uint		my_len_node(t_node *node);

t_node		*my_found_coord_node(t_node *node, int x, int y);

/*
**
**		my_link
**
*/

void		my_free_all_link(t_link *link);

void		my_free_link(t_link *link);

t_link		*my_new_link(void);

t_link		*my_put_link(t_link *old, t_link *link);

int		my_aff_link(t_link *link, const int fd);

t_uint		my_len_link(t_link *link);

t_link		*my_sup_link(t_link *link);

t_link		*my_create_link_node(t_link *old, t_node *node);

#endif		/* !MY_LEM_IN_H_ */
