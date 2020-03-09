/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:50:29 by oelbelam          #+#    #+#             */
/*   Updated: 2019/10/12 17:55:23 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_the_scr(int score, t_player *p, t_pos br_pos, t_pos st_pos)
{
	if (score < p->score)
	{
		p->score = score;
		p->start.x = br_pos.x - st_pos.x;
		p->start.y = br_pos.y - st_pos.y;
	}
}
