/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:11:24 by oelbelam          #+#    #+#             */
/*   Updated: 2019/10/12 18:12:05 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "srcs/ft_printf.h"

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_player
{
	int			score;
	t_pos		start;
}				t_player;

typedef struct	s_info
{
	char		player;
	t_pos		brd_size;
	t_pos		shape_size;
	t_pos		*shap_vectors;
	t_pos		player_pos;
	int			**brd;
	int			**token;
	int			flag;
}				t_info;

t_info			info_init(void);
void			player(t_info *info);
t_player		init_player(void);
void			ft_free_board(int ***tab, int x);
t_pos			*get_start_position(t_info *info);
char			ft_check_player(char *line);
int				**board_init(int board_x, int board_y);
void			shape_postions(int *token, char *line, int shape_y);
int				**get_token(int shaoe_x, int shape_y);
void			map_positions(char *line, int board_y, char player, int *token);
void			get_the_scr(int score, t_player *p, t_pos br_pos, t_pos st_pos);

#endif
