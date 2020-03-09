/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_flag_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 17:18:05 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/27 17:27:47 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void			flag_h_hh(const char *frm, int i, t_flag *p)
{
	p->fh = 0;
	p->fhh = 0;
	while (frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
	frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X')
	{
		if (frm[i] == 'h')
		{
			if (frm[i + 1] == 'h')
			{
				p->fhh = 1;
				p->fh = 1;
				break ;
			}
			else
			{
				p->fhh = 0;
				p->fh = 1;
			}
		}
		i++;
	}
}

void			flag_l_ll(const char *frm, int i, t_flag *p)
{
	p->fl = 0;
	p->fll = 0;
	while (frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
	frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X')
	{
		if (frm[i] == 'l')
		{
			if (frm[i + 1] == 'l')
			{
				p->fll = 1;
				p->fl = 1;
				break ;
			}
			else
			{
				p->fll = 0;
				p->fl = 1;
			}
		}
		i++;
	}
}

void			flag_z(const char *frm, int i, t_flag *p)
{
	p->fzero = 0;
	while ((frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
	frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X') &&
	!(frm[i] >= '1' && frm[i] <= '9'))
	{
		if (frm[i] == '0')
		{
			p->fzero = 1;
			break ;
		}
		i++;
	}
}

void			flag_m(const char *frm, int i, t_flag *p)
{
	p->fm = 0;
	while (frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
	frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X')
	{
		if (frm[i] == '-')
		{
			p->fm = 1;
			break ;
		}
		i++;
	}
}

void			flag_p(const char *frm, int i, t_flag *p)
{
	p->fp = 0;
	while (frm[i] != 'd' && frm[i] != 's' && frm[i] != 'i' &&
	frm[i] != 'o' && frm[i] != 'x' && frm[i] != 'X')
	{
		if (frm[i] == '+')
		{
			p->fp = 1;
			break ;
		}
		i++;
	}
}
