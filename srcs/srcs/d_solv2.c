/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_solv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:13:16 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/27 15:14:53 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	checkpm(t_flag *p, t_var *v)
{
	if (p->fp == 1 && v->isn == 0)
		write(1, "+", 1);
	else if (p->fp == 0 && v->isn == 1)
		write(1, "-", 1);
	else if (p->fp == 1 && v->isn == 1)
		write(1, "-", 1);
}

int		checkpmr(t_flag *p, t_var *v)
{
	if (p->fp == 1 && v->isn == 0)
		return (1);
	else if (p->fp == 0 && v->isn == 1)
		return (1);
	else if (p->fp == 1 && v->isn == 1)
		return (1);
	return (0);
}

void	d_conv_s1_m(t_flag *p, t_var *v)
{
	if (p->fm == 1)
	{
		if (p->fpr > v->len)
		{
			v->nz = MABS(p->fpr - v->len);
			if (p->fw > p->fpr)
				v->nsc2 = MABS(p->fw - p->fpr - p->fsp - checkpmr(p, v));
		}
		if (p->fpr <= v->len)
			v->nsc2 = MABS(p->fw - v->len - p->fsp - checkpmr(p, v));
	}
	else
		d_conv_s1_p(p, v);
}

void	d_conv_s1_p(t_flag *p, t_var *v)
{
	if (p->fpr > v->len)
	{
		v->nz = MABS(p->fpr - v->len);
		if (p->fw > p->fpr)
			v->nsc1 = MABS(p->fw - p->fpr - p->fsp - checkpmr(p, v));
	}
	else if ((p->fzero == 1) && (p->fpr == -1))
		v->nz = MABS(p->fw - v->len - p->fsp - checkpmr(p, v));
	else
		v->nsc1 = MABS(p->fw - v->len - p->fsp - checkpmr(p, v));
}
