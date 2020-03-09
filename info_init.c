/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:04:55 by oelbelam          #+#    #+#             */
/*   Updated: 2019/10/12 17:58:44 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_info			info_init(void)
{
	t_info		info;

	info.player = 'O';
	info.brd_size.x = 0;
	info.brd_size.y = 0;
	info.shape_size.x = 0;
	info.shape_size.y = 0;
	info.flag = 0;
	return (info);
}

t_player		init_player(void)
{
	t_player	player;

	player.score = 100000;
	player.start.x = 0;
	player.start.y = 0;
	return (player);
}
