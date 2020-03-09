/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:33:07 by oelbelam          #+#    #+#             */
/*   Updated: 2019/10/12 18:17:11 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				check_place_c(t_pos br_pos, t_pos st_pos,
		t_info info, t_pos index)
{
	t_pos		ret_pos;

	if (!(index.x == st_pos.x && index.y == st_pos.y)
			&& info.token[index.x][index.y] == -1)
	{
		ret_pos.x = br_pos.x + (index.x - st_pos.x);
		ret_pos.y = br_pos.y + (index.y - st_pos.y);
		if (ret_pos.x >= 0 && ret_pos.x < info.brd_size.x
				&& ret_pos.y >= 0 && ret_pos.y < info.brd_size.y)
		{
			if (info.brd[ret_pos.x][ret_pos.y] == -1
					|| info.brd[ret_pos.x][ret_pos.y] == -2)
				return (-1);
			else if (info.brd[ret_pos.x][ret_pos.y] != -1
					&& info.brd[ret_pos.x][ret_pos.y] != -2)
				return (info.brd[ret_pos.x][ret_pos.y]);
		}
		else
			return (-1);
	}
	return (-2);
}

void			check_place(t_pos br_pos, t_pos st_pos,
		t_info info, t_player *p)
{
	t_pos		index;
	int			i;
	int			j;
	int			temp_score;

	temp_score = 0;
	i = -1;
	while (++i < info.shape_size.x)
	{
		j = -1;
		while (++j < info.shape_size.y)
		{
			index.x = i;
			index.y = j;
			if (check_place_c(br_pos, st_pos, info, index) == -1)
				return ;
			else if (check_place_c(br_pos, st_pos, info, index) != -1
					&& check_place_c(br_pos, st_pos, info, index) != -2)
				temp_score += check_place_c(br_pos, st_pos, info, index);
		}
	}
	get_the_scr(temp_score, p, br_pos, st_pos);
}

int				nu_of_starts(t_info *info)
{
	int			count;
	int			i;
	int			j;

	i = 0;
	count = 0;
	while (i < info->shape_size.x)
	{
		j = 0;
		while (j < info->shape_size.y)
		{
			if (info->token[i][j] == -1)
				count++;
			j++;
		}
		i++;
	}
	info->flag = count;
	return (count);
}

t_pos			*get_start_position(t_info *info)
{
	t_pos		*stars;
	int			nu_stars;
	int			i;
	int			j;
	int			k;

	nu_stars = nu_of_starts(info);
	if (!(stars = (t_pos*)malloc(sizeof(t_pos) * nu_stars)))
		return (NULL);
	i = -1;
	k = 0;
	while (++i < info->shape_size.x)
	{
		j = 0;
		while (j < info->shape_size.y)
		{
			if (info->token[i][j] == -1)
			{
				stars[k].x = i;
				stars[k++].y = j;
			}
			j++;
		}
	}
	return (stars);
}

void			player(t_info *info)
{
	int			i;
	int			j;
	int			k;
	t_player	plr;
	t_pos		brd_start;

	i = -1;
	plr = init_player();
	while (++i < info->brd_size.x)
	{
		j = -1;
		while (++j < info->brd_size.y)
		{
			if (info->brd[i][j] == -1)
			{
				brd_start.x = i;
				brd_start.y = j;
				k = -1;
				while (++k < info->flag)
					check_place(brd_start, info->shap_vectors[k], *info, &plr);
			}
		}
	}
	ft_printf("%d %d\n", plr.start.x, plr.start.y);
	free(info->shap_vectors);
}
