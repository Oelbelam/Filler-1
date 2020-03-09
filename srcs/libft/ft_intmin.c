/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:02:04 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 23:00:02 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intmin(int a, int b, int c)
{
	if (a > c)
	{
		if (b > c)
			return (c);
		else
			return (b);
	}
	else
	{
		if (b > a)
			return (a);
		else
			return (b);
	}
}
