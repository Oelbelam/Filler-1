/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 22:26:53 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/07 13:38:17 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_putstr_p(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
		ret += write(1, &str[ret], 1);
	return (ret);
}

void	p_format(t_flags flg, unsigned long p, int *ret)
{
	char *str;

	if (flg.flg_n)
	{
		str = atoi_base((unsigned long)p, 16);
		*ret += write(1, "0x", 2);
		*ret += ft_putstr_p(str);
		*ret += print_spaces(flg.wd - (int)ft_strlen(str) - 2);
	}
	else
	{
		str = atoi_base((unsigned long)p, 16);
		*ret += print_spaces(flg.wd - (int)ft_strlen(str) - 2);
		*ret += write(1, "0x", 2);
		*ret += ft_putstr_p(str);
	}
	free(str);
}

void	p_conv(const char *frm, int *i, va_list ap, int *ret)
{
	t_flags			flag;
	unsigned long	p;

	flag = init_flags();
	while (frm[*i] != 'p' && frm[*i])
	{
		if (frm[*i] == '-')
			flag.flg_n = 1;
		else if (frm[*i] >= '1' && frm[*i] <= '9')
			flag.wd = ft_atoi(&frm[*i]);
		(*i)++;
	}
	p = (unsigned long)va_arg(ap, void*);
	p_format(flag, p, ret);
}
