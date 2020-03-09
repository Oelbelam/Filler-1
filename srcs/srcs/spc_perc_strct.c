/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spc_perc_strct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 11:42:52 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/07 13:39:06 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_spaces(int width)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < width)
	{
		count += write(1, " ", 1);
		i++;
	}
	return (count);
}

int		print_zero(int width)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < width)
	{
		count += write(1, "0", 1);
		i++;
	}
	return (count);
}

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.flag = 0;
	flags.flg_p = 0;
	flags.flg_n = 0;
	flags.flg_sp = 0;
	flags.flg_0 = 0;
	flags.wd = 0;
	flags.pr = 0;
	flags.dot = 0;
	flags.hsh = 0;
	return (flags);
}

void	perc_conv(const char *format, int *i, va_list ap, int *ret)
{
	(void)ap;
	write(1, &format[*i], 1);
	*ret += 1;
	(*i)++;
}

void	init_var(t_var *v)
{
	v->isn = 0;
	v->len = 0;
	v->nz = 0;
	v->nsc1 = 0;
	v->nsc2 = 0;
	v->is0 = 0;
}
