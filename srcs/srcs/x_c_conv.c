/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_c_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:23:56 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/28 13:36:43 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	x_c_conv_2_m2(t_flag *p, t_var *v)
{
	if (p->fpr > v->len)
	{
		v->nz = MABS(p->fpr - v->len);
		if (p->fw > p->fpr)
			v->nsc1 = MABS(p->fw - p->fpr - p->fsp);
	}
	else if (p->fzero == 1 && (p->fpr == -1))
		v->nz = MABS(p->fw - v->len - p->fsp);
	else
		v->nsc1 = MABS(p->fw - v->len - p->fsp);
}

void	x_c_conv_2_m(t_flag *p, t_var *v)
{
	if (p->fm == 1)
	{
		if (p->fpr > v->len)
		{
			v->nz = MABS(p->fpr - v->len);
			if (p->fw > p->fpr)
				v->nsc2 = MABS(p->fw - p->fpr - p->fsp);
		}
		if (p->fpr <= v->len)
			v->nsc2 = MABS(p->fw - v->len - p->fsp);
	}
	else
	{
		x_c_conv_2_m2(p, v);
	}
}

void	x_c_conv_s1(t_flag *p, unsigned long long d, int *ret)
{
	t_var	v;

	init_var(&v);
	v.tt = ft_itoa_base_x_c(d, 16);
	v.len = ft_strlen(v.tt);
	if (ft_strcmp(v.tt, "0") == 0)
		x_c_conv_0(p, &v, ret);
	x_c_conv_1(p, &v);
	if (p->fpr > v.len || p->fw > v.len)
		x_c_conv_2_m(p, &v);
	print_spaces(p->fsp);
	print_spaces(v.nsc1);
	if (p->fdiez == 1 && v.is0 != 1)
		p->fdiez = write(1, "0X", 2);
	else
		p->fdiez = 0;
	print_zero(v.nz);
	ft_putstr(v.tt);
	free(v.tt);
	print_spaces(v.nsc2);
	*ret += v.nsc1 + v.nsc2 + v.nz + v.len + p->fsp + p->fdiez;
}

void	x_c_conv(const char *frm, int *i, va_list ap, int *ret)
{
	int						j;
	t_flag					*p;
	unsigned long long int	d;

	j = *i;
	p = (t_flag*)malloc(sizeof(t_flag));
	stock_flag(frm, j, p);
	d = assign_x_c(p, ap);
	x_c_conv_s1(p, d, ret);
	free(p);
}
