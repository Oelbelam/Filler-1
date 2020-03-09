/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:38:26 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 22:27:07 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int				check_h_l_f(const char *frm, int *i)
{
	int			index;
	int			flag_f;

	index = *i;
	flag_f = 0;
	while (frm[index + 1] != 'f')
		index++;
	if (frm[index] == 'l')
		flag_f = 1;
	else if (frm[index] == 'L')
		flag_f = 2;
	else
		flag_f = 1;
	return (flag_f);
}

t_flags			chck_flags_f(const char *frm, int *i)
{
	t_flags		flags;

	flags = init_flags();
	while (frm[*i] != 'f' && frm[*i] != '.')
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
			return (flags);
		if (frm[*i] == '+')
			flags.flg_p = 1;
		if (frm[*i] == '#')
			flags.hsh = 1;
		if (frm[*i] == '-')
			flags.flg_n = 1;
		if (frm[*i] == ' ')
			flags.flg_sp = 1;
		if (frm[*i] == '0')
			flags.flg_0 = 1;
		(*i)++;
	}
	return (flags);
}

void			wdth_prc_f(const char *frm, int *i, t_flags *flags)
{
	while (frm[*i] != 'L' && frm[*i] != 'l' && frm[*i] != 'f' && frm[*i])
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
		{
			flags->wd = ft_atoi(&frm[*i]);
			if (flags->wd < 0)
			{
				flags->wd = 0;
				flags->flg_n = 1;
			}
			while (frm[*i] != '.' && frm[*i] != 'f')
				(*i)++;
		}
		if (frm[*i] == '.')
		{
			flags->dot = 1;
			flags->pr = ft_atoi(&frm[(*i) + 1]);
			if (flags->pr < 0)
				flags->pr = 6;
			break ;
		}
	}
	while (frm[*i] != 'f')
		(*i)++;
}

char			*ft_delet_zeros(char *str)
{
	int			j;

	j = 0;
	if (str[0] == '0' && str[1] == '\0')
		return (ft_strdup("0"));
	while (str[j] == '0' && str[j + 1] != '.' && str[j] != '\0')
		j++;
	return (ft_strsub(str, j, ft_strlen(str) - j));
}

char			*strnew_point(char *str, size_t size, int point)
{
	char		*ret;
	int			i;
	int			j;

	ret = ft_strnew(size + 1);
	ft_memset(ret, '0', size);
	i = ft_strlen(str) - 1;
	j = ft_strlen(ret) - 1;
	while (i >= 0)
	{
		if (point == 0)
		{
			ret[j] = '.';
			point--;
			j--;
		}
		else
		{
			ret[j--] = str[i--];
			point--;
		}
	}
	return (ret);
}
