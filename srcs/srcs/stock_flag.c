/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:01:52 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/27 16:25:13 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			flag_space(const char *frm, int i, t_flag *p)
{
	p->fsp = 0;
	while (frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
	frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X')
	{
		if (frm[i] == ' ')
		{
			p->fsp = 1;
			break ;
		}
		i++;
	}
}

void			flag_diez(const char *frm, int i, t_flag *p)
{
	p->fdiez = 0;
	while (frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
	frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X')
	{
		if (frm[i] == '#')
		{
			p->fdiez = 1;
			break ;
		}
		i++;
	}
}

void			flag_w_p(const char *frm, int i, t_flag *p)
{
	while (!(frm[i] >= '1' && frm[i] <= '9') &&
			(frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
			frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X'))
	{
		if (frm[i] == '.')
		{
			p->fpr = ft_atoi(&frm[(i + 1)]);
			break ;
		}
		else
			p->fpr = 0;
		i++;
	}
	if ((frm[i] >= '1' && frm[i] <= '9'))
		p->fw = ft_atoi(&frm[i]);
	else
		p->fw = 0;
	while (frm[i] >= '0' && frm[i] <= '9')
		i++;
	if (frm[i] == '.')
		p->fpr = ft_atoi(&frm[(i + 1)]);
	else
		p->fpr = -1;
}

void			stock_flag(const char *frm, int j, t_flag *p)
{
	flag_z(frm, j, p);
	flag_space(frm, j, p);
	flag_diez(frm, j, p);
	flag_m(frm, j, p);
	flag_p(frm, j, p);
	flag_w_p(frm, j, p);
	flag_l_ll(frm, j, p);
	flag_h_hh(frm, j, p);
}
