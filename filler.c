/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:14:30 by oelbelam          #+#    #+#             */
/*   Updated: 2019/10/14 10:45:04 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_the_board(int board_x, int board_y, t_info *info)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	info->brd = board_init(board_x, board_y);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < board_x)
	{
		if (get_next_line(0, &line) <= 0)
		{
			free(line);
			break ;
		}
		temp = ft_strsub(line, 4, board_y);
		ft_strdel(&line);
		map_positions(temp, board_y, info->player, info->brd[i]);
		ft_strdel(&temp);
		i++;
	}
}

void		fill_brd_score(int x, int y, int score, t_info *inf)
{
	if (x + 1 >= 0 && x + 1 < inf->brd_size.x && inf->brd[x + 1][y] == '.')
		inf->brd[x + 1][y] = score;
	if (x + 1 >= 0 && x + 1 < inf->brd_size.x
			&& y + 1 >= 0 && y + 1 < inf->brd_size.y
			&& inf->brd[x + 1][y + 1] == '.')
		inf->brd[x + 1][y + 1] = score;
	if (x + 1 >= 0 && x + 1 < inf->brd_size.x
			&& y - 1 >= 0 && y - 1 < inf->brd_size.y
			&& inf->brd[x + 1][y - 1] == '.')
		inf->brd[x + 1][y - 1] = score;
	if (x - 1 >= 0 && x - 1 < inf->brd_size.x && inf->brd[x - 1][y] == '.')
		inf->brd[x - 1][y] = score;
	if (y - 1 >= 0 && y - 1 < inf->brd_size.y && inf->brd[x][y - 1] == '.')
		inf->brd[x][y - 1] = score;
	if (x - 1 >= 0 && x - 1 < inf->brd_size.x
			&& y - 1 >= 0 && y - 1 < inf->brd_size.y
			&& inf->brd[x - 1][y - 1] == '.')
		inf->brd[x - 1][y - 1] = score;
	if (x - 1 >= 0 && x - 1 < inf->brd_size.x
			&& y + 1 >= 0 && y + 1 < inf->brd_size.y
			&& inf->brd[x - 1][y + 1] == '.')
		inf->brd[x - 1][y + 1] = score;
	if (y + 1 >= 0 && y + 1 < inf->brd_size.y && inf->brd[x][y + 1] == '.')
		inf->brd[x][y + 1] = score;
}

void		manipulate_board(t_info *info)
{
	int		score;
	int		target;
	int		i;
	int		j;
	int		k;

	target = -2;
	score = 1;
	k = -1;
	while (++k < info->brd_size.y)
	{
		i = -1;
		while (++i < info->brd_size.x)
		{
			j = 0;
			while (j < info->brd_size.y)
			{
				if (info->brd[i][j] == target)
					fill_brd_score(i, j, score, info);
				j++;
			}
		}
		target = score;
		score++;
	}
}

int			read_the_board(t_info *info)
{
	char	*line;
	int		i;

	i = 8;
	if (get_next_line(0, &line) <= 0)
		return (0);
	info->brd_size.x = ft_atoi(&line[i - 1]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	info->brd_size.y = ft_atoi(&line[i]);
	get_the_board(info->brd_size.x, info->brd_size.y, info);
	free(line);
	get_next_line(0, &line);
	i = 6;
	info->shape_size.x = ft_atoi(&line[i]);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	info->shape_size.y = ft_atoi(&line[i]);
	info->token = get_token(info->shape_size.x, info->shape_size.y);
	free(line);
	return (1);
}

int			main(void)
{
	char	*line;
	int		i;
	t_info	info;
	int		j;

	info = info_init();
	get_next_line(0, &line);
	info.player = ft_check_player(line + 9);
	ft_strdel(&line);
	while (1)
	{
		if (!read_the_board(&info))
			break ;
		manipulate_board(&info);
		info.shap_vectors = get_start_position(&info);
		player(&info);
		ft_free_board(&(info.brd), info.brd_size.x);
		ft_free_board(&(info.token), info.shape_size.x);
	}
	return (0);
}
