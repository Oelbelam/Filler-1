/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:29:17 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 21:53:54 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_nan_inf(char *res, int *ret, t_flags flags)
{
	if (ft_strcmp(res, "nan") == 0)
		ft_nan(flags, ret);
	else
	{
		if (ft_strcmp(res, "inf") != 0)
			plus_inf(flags, ret);
		else
			neg_inf(flags, ret);
	}
}

char	*dbl_num_sub(long double lf, int *signe)
{
	union u_ldata	ldata;
	char			*to_del;
	int				point;
	char			*res;
	int				flag;

	ldata.lf = lf;
	res = man_man_exp_sign(ldata.ldata, &point);
	to_del = res;
	flag = 0;
	if (ft_strcmp(res, "inf") != 0 &&
			ft_strcmp(res, "-inf") != 0 && ft_strcmp(res, "nan") != 0)
	{
		res = strnew_point(res, (point <= (int)ft_strlen(res)) ?
				ft_strlen(res) + 1 : point, point);
		free(to_del);
		flag = 1;
	}
	to_del = res;
	res = ft_delet_zeros(res);
	free(to_del);
	*signe = ldata.ldata.signe;
	return (res);
}

char	*dbl_num(long double lf, int *signe)
{
	union u_ldata	ldata;
	int				point;
	char			*res;
	int				i;

	if (lf == 0)
	{
		i = 0;
		res = ft_strnew(8);
		while (i < 8)
		{
			if (i == 1)
				res[i] = '.';
			else
				res[i] = '0';
			i++;
		}
		ldata.lf = lf;
		point = 1;
		*signe = ldata.ldata.signe;
	}
	else
		res = dbl_num_sub(lf, signe);
	return (res);
}
