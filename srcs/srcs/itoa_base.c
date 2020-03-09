/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:24:24 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/07 13:34:48 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*atoi_base(unsigned long long nbr, int base)
{
	char				*str;
	unsigned long long	temp;
	int					count;
	char				*res;

	count = 0;
	temp = nbr;
	str = "0123456789abcdef";
	if (nbr == 0)
		return (ft_strdup("0"));
	while (temp != 0)
	{
		temp /= base;
		count++;
	}
	res = ft_strnew(count);
	res[count] = '\0';
	while (nbr != 0)
	{
		res[--count] = str[nbr % base];
		nbr /= base;
	}
	return (res);
}

char	*ft_itoa_base_x_c(unsigned long long value, int base)
{
	char				*str;
	unsigned long long	temp;
	int					count;
	char				*res;

	count = 0;
	temp = value;
	str = "0123456789ABCDEF";
	if (value == 0)
		return (ft_strdup("0"));
	while (temp != 0)
	{
		temp /= base;
		count++;
	}
	res = ft_strnew(count);
	res[count] = '\0';
	while (value != 0)
	{
		res[--count] = str[value % base];
		value /= base;
	}
	return (res);
}
