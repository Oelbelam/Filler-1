/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulat_flag0_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:43:11 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/07 13:23:52 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		manipulat_dot(t_flags flg, char *res, int *ret_temp, int *ret)
{
	char	*temp;
	char	*to_del;

	temp = ro(res, flg.pr, flg.dot);
	to_del = temp;
	temp = ft_delet_zeros(temp);
	ft_strdel(&to_del);
	*ret_temp = print_float(temp, flg.pr, flg.dot, flg.hsh);
	*ret += *ret_temp;
	free(temp);
}

void		manipulat_flgn(t_flags flg, int signe, char *res, int *ret)
{
	char	*to_del;
	char	*temp;
	int		ret_temp;

	ret_temp = 0;
	flg.wd += (signe == 1) ? 1 : 0;
	*ret += p_m_chk_f(&flg, signe);
	temp = NULL;
	if (flg.dot)
		manipulat_dot(flg, res, &ret_temp, ret);
	else
	{
		temp = ro(res, flg.pr, flg.dot);
		to_del = temp;
		temp = ft_delet_zeros(temp);
		ft_strdel(&to_del);
		ret_temp += print_float(temp, 6, flg.dot, flg.hsh);
		*ret += ret_temp;
	}
	*ret += print_spaces((signe == 0) ?
			(flg.wd - ret_temp) : (flg.wd - ret_temp - 1));
	free(temp);
}

void		manipulat_flg0(t_flags flg, int si, char *res, int *ret)
{
	char	*temp;
	char	*to_del;

	*ret += p_m_chk_f(&flg, si);
	if (!flg.dot)
	{
		*ret += print_zero((si == 0) ? flg.wd -
				(len_point(res) + 5) : flg.wd - (len_point(res) + 6));
		temp = ro(res, flg.pr, flg.dot);
		to_del = temp;
		temp = ft_delet_zeros(temp);
		free(to_del);
		*ret += print_float(temp, 6, flg.dot, flg.hsh);
	}
	else
	{
		temp = ro(res, flg.pr, flg.dot);
		to_del = temp;
		temp = ft_delet_zeros(temp);
		free(to_del);
		*ret += print_zero((si == 0) ? flg.wd - (len_point(temp) + flg.pr + 1)
				: flg.wd - (len_point(temp) + flg.pr + 1));
		*ret += print_float(temp, flg.pr, flg.dot, flg.hsh);
	}
	free(temp);
}
