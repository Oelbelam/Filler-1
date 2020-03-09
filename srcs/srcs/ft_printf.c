/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:46:25 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/07 13:48:13 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

const	t_flags_struct g_struct_var =
{
	{ "%csdioxXpuf" },
	{ &perc_conv, &c_conv, &s_conv, &d_conv, &d_conv,
		&o_conv, &x_conv, &x_c_conv, &p_conv, &u_conv, &f_conv }
};

void	det_flag(const char *format, int *i, va_list ap, int *ret)
{
	int				it;
	t_flags_struct	struct_tobe_man;
	int				old_index;

	old_index = *i;
	struct_tobe_man = g_struct_var;
	while (format[*i])
	{
		it = 0;
		while (it < 11)
		{
			if (struct_tobe_man.flag[it] == format[*i])
			{
				struct_tobe_man.flg_ft[it](format, &old_index, ap, ret);
				return ;
			}
			it++;
		}
		(*i)++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			det_flag(format, &i, ap, &ret);
		}
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (ret);
}
