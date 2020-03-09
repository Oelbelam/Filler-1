/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:33:33 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/27 15:37:46 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	o_conv_2_m2(t_flag *p, t_var *v)
{
	if (p->fpr > v->len)
	{
		v->nz = MABS(p->fpr - v->len);
		if (p->fw > p->fpr && p->fzero == 1)
		{
			v->nz = MABS(p->fpr - v->len);
			v->nsc1 = MABS(p->fw - p->fpr - p->fsp);
		}
		else if (p->fw > p->fpr)
			v->nsc1 = MABS(p->fw - p->fpr - p->fsp);
	}
	else if (((p->fzero == 1) || (p->fzero == 1 && v->is0 == 1)) &&
			(p->fpr > v->len || p->fpr == -1))
		v->nz = MABS(p->fw - v->len - p->fsp);
	else
		v->nsc1 = MABS(p->fw - v->len - p->fsp);
}

void	o_conv_2_m(t_flag *p, t_var *v)
{
	if (p->fm == 1)
	{
		if (p->fpr > v->len)
		{
			v->nz = MABS(p->fpr - v->len);
			if (p->fw > p->fpr)
			{
				if (p->fzero == 1)
					v->nz = MABS(p->fpr - v->len - p->fsp);
				else
					v->nsc2 = MABS(p->fw - p->fpr - p->fsp);
			}
			else if (v->len > p->fpr)
				v->nsc2 = MABS(p->fsp);
		}
		if (p->fpr <= v->len)
			v->nsc2 = MABS(p->fw - v->len - p->fsp);
	}
	else
		o_conv_2_m2(p, v);
}

void	o_conv_s1(t_flag *p, unsigned long long d, int *ret)
{
	t_var	v;

	init_var(&v);
	v.tt = atoi_base(d, 8);
	v.len = ft_strlen(v.tt);
	if (ft_strcmp(v.tt, "0") == 0)
		o_conv_0(p, &v, ret);
	o_conv_1(p, &v);
	if (p->fpr > v.len || p->fw > v.len)
		o_conv_2_m(p, &v);
	print_spaces(p->fsp);
	print_spaces(v.nsc1);
	if (p->fdiez == 1 && v.is0 != 1 && p->fpr < v.len)
		write(1, "0", 1);
	else
		p->fdiez = 0;
	print_zero(v.nz);
	ft_putstr(v.tt);
	free(v.tt);
	print_spaces(v.nsc2);
	*ret += v.nsc1 + v.nsc2 + v.nz + v.len + p->fsp + p->fdiez;
}

void	o_conv(const char *frm, int *i, va_list ap, int *ret)
{
	int						j;
	t_flag					*p;
	unsigned long long int	d;

	j = *i;
	p = (t_flag*)malloc(sizeof(t_flag));
	stock_flag(frm, j, p);
	d = assign_o(p, ap);
	o_conv_s1(p, d, ret);
	free(p);
}
