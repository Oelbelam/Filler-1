/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:08:12 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 21:34:27 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ft_pow_str(int pow, char *num)
{
	int					i;
	char				*res;
	unsigned int		count;
	char				*del;

	i = 2;
	count = 0;
	if (pow == 0)
		return (ft_strdup("1"));
	if (pow == 1)
		return (ft_strdup(num));
	res = ft_strdup(num);
	while (i <= pow)
	{
		del = res;
		res = ft_mult_str(res, num, 0);
		free(del);
		i++;
	}
	return (res);
}
