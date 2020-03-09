/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_solv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:54:55 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/10/11 11:55:08 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long long int			assign_d(t_flag *p, va_list ap)
{
	long long int d;

	if (p->fh == 1 && p->fhh == 0)
		d = (long long int)va_arg(ap, int);
	else if (p->fh == 1 && p->fhh == 1)
		d = (long long int)va_arg(ap, int);
	else if (p->fl == 1 && p->fll == 0)
		d = (long long int)va_arg(ap, long int);
	else if (p->fl == 1 && p->fll == 1)
		d = va_arg(ap, long long int);
	else
		d = (long long int)va_arg(ap, int);
	return (d);
}

int						ft_nbrlen(long long int nbr)
{
	if ((nbr / 10) == 0)
		return (1);
	else
		return (1 + ft_nbrlen(nbr / 10));
}

int						isnegative(long long int n)
{
	int isnegative;

	isnegative = 0;
	if (n < 0)
	{
		isnegative = 1;
	}
	return (isnegative);
}

int						getlen_w_o_p(long long int nn, long long int n)
{
	long long int	tmp;
	int				len;

	len = 0;
	tmp = n;
	if (nn == 0)
		len = 1;
	while (tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	return (len);
}

char					*ft_itoa_w_o_p(long long int n, t_var *v)
{
	unsigned long long int	nn;
	char					*tab;
	int						i;

	nn = (unsigned long long int)n;
	if (!(tab = malloc((getlen_w_o_p(nn, n) + 1))))
		return (NULL);
	if (isnegative(n) == 1)
	{
		v->isn = 1;
		nn = -nn;
	}
	tab[getlen_w_o_p(nn, n)] = '\0';
	i = getlen_w_o_p(nn, n) - 1;
	if (nn == 0)
		tab[i] = '0';
	while (nn && nn != 0)
	{
		if (nn < 10)
			tab[i] = nn + '0';
		tab[i--] = nn % 10 + '0';
		nn /= 10;
	}
	return (tab);
}
