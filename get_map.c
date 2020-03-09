/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:34:37 by oelbelam          #+#    #+#             */
/*   Updated: 2019/10/12 19:41:16 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		ft_check_player(char *line)
{
	if (ft_strncmp("p1", line, 2))
		return ('X');
	else
		return ('O');
}

int			**board_init(int board_x, int board_y)
{
	int		**board;
	int		i;

	i = 0;
	if (!(board = (int**)malloc(sizeof(int*) * (board_x) + 1)))
		return (NULL);
	while (i < board_x)
	{
		if (!(board[i] = (int*)malloc(sizeof(int) * (board_y) + 1)))
			return (NULL);
		i++;
	}
	return (board);
}

void		shape_positions(int *token, char *line, int shape_y)
{
	int		i;

	i = 0;
	while (i < shape_y)
	{
		if (line[i] == '*')
			token[i] = -1;
		else
			token[i] = 0;
		i++;
	}
}

int			**get_token(int shape_x, int shape_y)
{
	int		**token;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	token = board_init(shape_x, shape_y);
	while (i < shape_x)
	{
		ret = get_next_line(0, &line);
		if (ret <= 0)
		{
			ft_strdel(&line);
			break ;
		}
		shape_positions(token[i], line, shape_y);
		ft_strdel(&line);
		i++;
	}
	return (token);
}

void		map_positions(char *line, int board_y, char player, int *token)
{
	int		i;

	i = 0;
	while (i < board_y)
	{
		if (line[i] == player || line[i] == (player - 'A') + 'a')
			token[i] = -1;
		else if (line[i] == '.')
			token[i] = '.';
		else
			token[i] = -2;
		i++;
	}
}
