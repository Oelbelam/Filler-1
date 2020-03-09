/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:44:22 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 20:54:16 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (a);
	}
	return (a);
}
