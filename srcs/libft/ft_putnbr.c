/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:43:51 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/22 17:57:03 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < -9 || n > 9)
		ft_putnbr(n / 10);
	if (n < 0)
	{
		if (n >= -9)
			ft_putchar('-');
		ft_putchar('0' - (n % 10));
	}
	else
		ft_putchar('0' + (n % 10));
}
