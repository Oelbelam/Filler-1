/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 22:05:32 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/07 13:44:24 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static int			check_h_l_u(const char *frm, int *i)
{
	int		index;
	int		flag_u;

	index = *i;
	flag_u = 0;
	while (frm[index + 1] != 'u')
		index++;
	if (frm[index] == 'h')
	{
		if (frm[index - 1] == 'h')
			flag_u = 1;
		else if (frm[index] == 'h' && frm[index - 1] != 'h')
			flag_u = 2;
	}
	else if (frm[index] == 'l')
	{
		if (frm[index - 1] == 'l')
			flag_u = 3;
		else if (frm[index] == 'l' && frm[index - 1] != 'l')
			flag_u = 4;
	}
	else
		flag_u = 5;
	return (flag_u);
}

unsigned long long	assign_u(int flag_u, va_list ap)
{
	unsigned long long	u;

	u = 0;
	if (flag_u == 5)
		u = (unsigned int)va_arg(ap, unsigned int);
	else if (flag_u == 2)
		u = (unsigned short int)va_arg(ap, unsigned int);
	else if (flag_u == 1)
		u = (unsigned char)va_arg(ap, unsigned int);
	else if (flag_u == 4)
		u = (unsigned long int)va_arg(ap, unsigned long int);
	else if (flag_u == 3)
		u = (unsigned long long)va_arg(ap, unsigned long long);
	return (u);
}

static t_flags		chck_flags_u(const char *frm, int *i)
{
	t_flags	flags;

	flags = init_flags();
	while (frm[*i] != 'u' && frm[*i] != '.')
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
			return (flags);
		if (frm[*i] == '-')
			flags.flg_n = 1;
		if (frm[*i] == '0')
			flags.flg_0 = 1;
		(*i)++;
	}
	return (flags);
}

static void			wdth_prc_u(const char *frm, int *i, t_flags *flags)
{
	while (frm[*i] != 'h' && frm[*i] != 'l' && frm[*i] != 'u' && frm[*i])
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
		{
			flags->wd = ft_atoi(&frm[*i]);
			while (frm[*i] != '.' && frm[*i] != 'u')
				(*i)++;
		}
		if (frm[*i] == '.')
		{
			flags->dot = 1;
			flags->pr = ft_atoi(&frm[(*i) + 1]);
			break ;
		}
	}
	while (frm[*i] != 'u')
		(*i)++;
}

void				u_conv(const char *frm, int *i, va_list ap, int *ret)
{
	long long int	u;
	t_flags			flags;
	int				flag_u;

	flag_u = check_h_l_u(frm, i);
	u = assign_u(flag_u, ap);
	flags = chck_flags_u(frm, i);
	flags.flag = flag_u;
	wdth_prc_u(frm, i, &flags);
	m_chk_u(flags, u, ret);
}
