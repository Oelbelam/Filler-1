/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 10:23:55 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/12 13:03:26 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if (*(unsigned char*)dst == (unsigned char)c)
			return (++dst);
		dst++;
		src++;
		i++;
	}
	return (NULL);
}
