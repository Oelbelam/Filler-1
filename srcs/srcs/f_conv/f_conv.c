/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:26:56 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 22:27:04 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void					plus_inf(t_flags flags, int *ret)
{
	flags.wd -= (flags.flg_sp || flags.flg_p) ? 1 : 0;
	if (flags.flg_n)
	{
		*ret += (flags.flg_sp && !flags.flg_p) ?
			write(1, " ", 1) : write(1, "", 0);
		*ret += (flags.flg_p) ? write(1, "+", 1) : write(1, "", 0);
		*ret += ft_putstr_s("inf", 4);
		*ret += print_spaces(flags.wd - 3);
	}
	else
	{
		*ret += print_spaces(flags.wd - 3);
		*ret += (flags.flg_sp && !flags.flg_p) ?
			write(1, " ", 1) : write(1, "", 0);
		*ret += (flags.flg_p) ? write(1, "+", 1) : write(1, "", 0);
		*ret += ft_putstr_s("inf", 4);
	}
}

void					neg_inf(t_flags flags, int *ret)
{
	if (flags.flg_n)
	{
		*ret += ft_putstr_s("-inf", 5);
		*ret += print_spaces(flags.wd - 4);
	}
	else
	{
		*ret += print_spaces(flags.wd - 4);
		*ret += ft_putstr_s("-inf", 5);
	}
}

void					ft_nan(t_flags flags, int *ret)
{
	if (flags.flg_n)
	{
		*ret += ft_putstr_s("nan", 4);
		*ret += print_spaces(flags.wd - 3);
	}
	else
	{
		*ret += print_spaces(flags.wd - 3);
		*ret += ft_putstr_s("nan", 4);
	}
}

static long double		assigned_f(va_list ap, int flag_f)
{
	if (flag_f == 1)
		return ((long double)va_arg(ap, double));
	else
		return (va_arg(ap, long double));
}

void					f_conv(const char *frm, int *i, va_list ap, int *ret)
{
	long double			lf;
	t_flags				flags;
	char				*res;
	int					signe;

	lf = assigned_f(ap, check_h_l_f(frm, i));
	signe = 0;
	res = dbl_num(lf, &signe);
	flags = chck_flags_f(frm, i);
	wdth_prc_f(frm, i, &flags);
	if (ft_strcmp(res, "inf") != 0
			&& ft_strcmp(res, "-inf") != 0 && ft_strcmp(res, "nan") != 0)
	{
		f_chk(flags, ret, res, signe);
	}
	else
	{
		ft_nan_inf(res, ret, flags);
	}
	free(res);
}
