/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_solv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 22:16:42 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/07 13:40:01 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int				ft_nbln_u(unsigned long long u, t_flags flg)
{
	int len;

	len = 0;
	if (u == 0 && flg.dot == 1)
		return (0);
	if (u == 0)
		len++;
	while (u)
	{
		len++;
		u = u / 10;
	}
	return (len);
}

static int		ft_pf_putnbr_u(unsigned long long u, t_flags flg)
{
	unsigned long long		temp;
	unsigned long long		counter;
	unsigned long long int	nb;
	int						count;

	counter = 1;
	nb = u;
	count = 0;
	if (u == 0 && flg.dot == 1)
		return (0);
	temp = nb;
	while ((temp = temp / 10) != 0)
		counter *= 10;
	while (counter)
	{
		ft_putchar((nb / counter) + '0');
		nb = nb % counter;
		counter /= 10;
		count++;
	}
	return (count);
}

int				post_flag_u(unsigned long long u, t_flags flg)
{
	int ret;

	ret = 0;
	if (flg.flag == 5)
		ret += ft_pf_putnbr_u(((unsigned int)u), flg);
	if (flg.flag == 2)
		ret += ft_pf_putnbr_u(((unsigned short)u), flg);
	if (flg.flag == 1)
		ret += ft_pf_putnbr_u(((unsigned char)u), flg);
	if (flg.flag == 4)
		ret += ft_pf_putnbr_u(((unsigned long)u), flg);
	if (flg.flag == 3)
		ret += ft_pf_putnbr_u((u), flg);
	return (ret);
}

void			m_chk_u(t_flags flg, unsigned long long u, int *ret)
{
	if (flg.flg_n == 1)
	{
		*ret += print_zero(flg.pr - ft_nbln_u(u, flg));
		*ret += post_flag_u(u, flg);
		*ret += print_spaces((flg.pr > ft_nbln_u(u, flg)) ?
				(flg.wd - flg.pr) : (flg.wd - ft_nbln_u(u, flg)));
	}
	else if (flg.flg_0 == 1 && flg.dot == 0)
	{
		*ret += print_zero(flg.wd - ft_nbln_u(u, flg));
		*ret += post_flag_u(u, flg);
	}
	else
	{
		*ret += print_spaces(((flg.pr > ft_nbln_u(u, flg)) ?
				(flg.wd - flg.pr) : (flg.wd - ft_nbln_u(u, flg))));
		*ret += print_zero(flg.pr - ft_nbln_u(u, flg));
		*ret += post_flag_u(u, flg);
	}
}
