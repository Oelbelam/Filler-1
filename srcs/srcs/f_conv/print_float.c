/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:21:39 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 20:23:08 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		print_float(char *res, int prec, int dot, int hsh)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = 0;
	while (res[i] != '.' && res[i] != '\0')
		ret += write(1, &res[i++], 1);
	j = 0;
	if (hsh && dot && prec == 0)
		return (ret += write(1, ".", 1));
	else if (!hsh && dot && prec == 0)
		return (ret);
	while (res[i] != '\0' && j++ <= prec)
		ret += write(1, &res[i++], 1);
	while (res[i] == '\0' && j++ <= prec)
		ret += write(1, "0", 1);
	return (ret);
}
