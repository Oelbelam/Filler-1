/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_solv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:14:46 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 23:00:23 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void			get_final_man(char *man1, char *man2)
{
	size_t		i_man1;
	size_t		i_man2;

	i_man2 = ft_strlen(man2) - 1;
	i_man1 = ft_strlen(man1) - 1;
	while ((int)i_man2 >= 0)
	{
		if ((int)i_man1 >= 0)
			man2[i_man2] = man1[i_man1];
		else
			man2[i_man2] = '0';
		i_man2--;
		i_man1--;
	}
}

char			*ft_manipulate_str(char *man2, int exp)
{
	char		*sum;
	char		*del_sum;
	char		*del_frac;
	char		*frac;
	int			i;

	i = 0;
	sum = (exp == 0) ? ft_strdup("0") : ft_strdup("1");
	while (man2[i])
	{
		del_sum = sum;
		sum = ft_mult_str(sum, "10", 1);
		free(del_sum);
		if (man2[i] == '1')
		{
			frac = ft_pow_str(i + 1, "5");
			del_frac = frac;
			del_sum = sum;
			sum = ft_add_str(sum, frac);
			free(del_sum);
			free(del_frac);
		}
		i++;
	}
	return (sum);
}

char			*ft_new_frac(char *fract, int i)
{
	char		*res;
	int			j;

	j = 0;
	res = ft_strnew(i);
	while (fract[j])
	{
		res[j] = fract[j];
		j++;
		i--;
	}
	while (i > 0)
	{
		res[j] = '0';
		j++;
		i--;
	}
	res[j] = '\0';
	return (res);
}

char			*ft_manipulate_lexp(int res_bias, int *point)
{
	char		*exp_num;

	if (res_bias < 0)
	{
		exp_num = ft_pow_str(res_bias * -1, "5");
		*point = res_bias * -1 + 63;
	}
	else
	{
		exp_num = ft_pow_str(res_bias, "2");
		*point = 63;
	}
	return (exp_num);
}

char			*man_man_exp_sign(t_ldata ldata, int *point)
{
	char		*man;
	char		*sum;
	char		*final_num;
	char		*exp_num;
	char		*man2;

	man = atoi_base(ldata.m, 2);
	man2 = ft_strnew(63);
	if (ldata.exp == 32767 && !ldata.m)
		final_num = (ldata.signe == 0) ? ft_strdup("-inf") : ft_strdup("inf");
	else if (ldata.exp == 32767 && ldata.m)
		final_num = ft_strdup("nan");
	else
	{
		ft_memset(man2, '0', 63);
		get_final_man(man, man2);
		sum = ft_manipulate_str(man2, ldata.num);
		exp_num = ft_manipulate_lexp(ldata.exp - 16383, point);
		final_num = ft_mult_str(exp_num, sum, 0);
		free(exp_num);
		free(sum);
	}
	free(man2);
	free(man);
	return (final_num);
}
