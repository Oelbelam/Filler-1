/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_chk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:35:06 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 23:00:35 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int			p_m_chk_f(t_flags *flg, int signe)
{
	int		ret;

	ret = 0;
	if (flg->flg_p == 1)
	{
		flg->flg_p = (signe == 0) ? write(1, "+", 1) : write(1, "-", 1);
		ret += 1;
		flg->wd -= 1;
	}
	else if (flg->flg_sp == 1 && signe == 0)
	{
		ret += write(1, " ", 1);
		flg->wd -= 1;
	}
	else if (signe == 1)
	{
		ret += write(1, "-", 1);
		flg->wd -= 1;
	}
	return (ret);
}

int			len_point(char *res)
{
	int	i;

	i = 0;
	while (res[i] != '.' && res[i] != '\0')
		i++;
	return (i);
}

int			check_zeros(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0' || str[i] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

void		m_chk_f(t_flags flg, char *res, int *ret, int signe)
{
	char	*temp;
	char	*to_del;

	temp = ro(res, flg.pr, flg.dot);
	to_del = temp;
	temp = ft_delet_zeros(temp);
	free(to_del);
	flg.wd -= (flg.flg_p == 1 || flg.flg_sp == 1 || signe == 1) ? 1 : 0;
	*ret += print_spaces((ft_strcmp(res, "0.000000") == 0) ?
			flg.wd - ft_strlen(res) - 2 : flg.wd - ft_strlen(temp));
	*ret += p_m_chk_f(&flg, signe);
	*ret += print_float(temp, flg.pr == 0 && flg.dot == 0 ?
			6 : flg.pr, flg.dot, flg.hsh);
	if (!flg.dot && flg.pr != 0)
		*ret += print_zero((check_zeros(temp) != 1) ?
				(len_point(temp) + 4) : len_point(temp) + 5);
	free(temp);
}

void		f_chk(t_flags flg, int *ret, char *res, int signe)
{
	int		ret_temp;

	ret_temp = 0;
	if (flg.flg_n == 1)
		manipulat_flgn(flg, signe, res, ret);
	else if (flg.flg_0)
		manipulat_flg0(flg, signe, res, ret);
	else
		m_chk_f(flg, res, ret, signe);
}
