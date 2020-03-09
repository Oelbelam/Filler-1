/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:30:59 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/09 14:03:08 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *str;

	str = dest;
	while (*str != '\0')
		str++;
	while (*src != '\0')
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';
	return (dest);
}
