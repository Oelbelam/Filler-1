/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:41:48 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/22 17:58:26 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t j;

	j = 0;
	while (src[j] != '\0' && len > 0)
	{
		dst[j] = ((char*)src)[j];
		j++;
		len--;
	}
	while (len > 0)
	{
		dst[j] = '\0';
		j++;
		len--;
	}
	return (dst);
}
