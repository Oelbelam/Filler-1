/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:18:40 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/27 15:30:37 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	d_conv_s2(t_flag *p, t_var *v)
{
	print_spaces(p->fsp);
	print_spaces(v->nsc1);
	checkpm(p, v);
	print_zero(v->nz);
	ft_putstr(v->tt);
	free(v->tt);
	print_spaces(v->nsc2);
}

void	d_conv_s1(t_flag *p, long long int d, int *ret)
{
	t_var			v;

	init_var(&v);
	v.tt = ft_itoa_w_o_p(d, &v);
	v.len = ft_nbrlen(d);
	if (ft_strcmp(v.tt, "0") == 0 && (p->fpr == 0))
	{
		free(v.tt);
		v.tt = ft_strdup("");
		v.len = 0;
		p->fzero = 0;
		v.is0 = 1;
	}
	(p->fm == 1) ? p->fzero = 0 : p->fzero;
	(p->fp == 1 || v.isn == 1) ? p->fsp = 0 : p->fsp;
	if (p->fpr > v.len || p->fw > v.len)
		d_conv_s1_m(p, &v);
	d_conv_s2(p, &v);
	*ret += v.nsc1 + v.nsc2 + v.nz + v.len + checkpmr(p, &v) + p->fsp;
}

void	d_conv(const char *frm, int *i, va_list ap, int *ret)
{
	int				j;
	t_flag			*p;
	long long int	d;

	j = *i;
	p = (t_flag*)malloc(sizeof(t_flag));
	stock_flag(frm, j, p);
	d = assign_d(p, ap);
	d_conv_s1(p, d, ret);
	free(p);
}
