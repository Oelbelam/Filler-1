/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 13:51:04 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/07 13:45:29 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

unsigned long long		assign_x(t_flag *p, va_list ap)
{
	unsigned long long d;

	if (p->fh == 1 && p->fhh == 0)
		d = (unsigned short)va_arg(ap, int);
	else if (p->fh == 1 && p->fhh == 1)
		d = (unsigned char)va_arg(ap, int);
	else if (p->fl == 1 && p->fll == 0)
		d = (unsigned long)va_arg(ap, long int);
	else if (p->fl == 1 && p->fll == 1)
		d = (unsigned long long)va_arg(ap, long long);
	else
		d = (unsigned int)va_arg(ap, int);
	return (d);
}

void					x_conv_0(t_flag *p, t_var *v, int *ret)
{
	v->is0 = 1;
	if (p->fpr == 0)
	{
		if (p->fdiez == 1 && p->fw != 0)
			p->fw = p->fw + 2;
		if (p->fw == 0)
		{
			free(v->tt);
			v->tt = ft_strdup("");
			*ret -= 1;
		}
		else
		{
			free(v->tt);
			v->tt = ft_strdup(" ");
		}
	}
	if (p->fpr > 0 && p->fw > 1 && p->fdiez == 1)
		p->fw = p->fw + 2;
	if (p->fpr == -1 && p->fdiez == 1)
		p->fw = p->fw + 2;
}

void					x_conv_1(t_flag *p, t_var *v)
{
	(p->fm == 1) ? p->fzero = 0 : p->fzero;
	if (p->fdiez == 1 && p->fw > p->fpr)
	{
		if (p->fpr < v->len)
			p->fw = p->fw + 2;
	}
	if (p->fdiez == 1 && p->fpr < v->len)
		p->fw = p->fw - 2;
	if (p->fdiez == 1)
		p->fw = p->fw - 2;
}
