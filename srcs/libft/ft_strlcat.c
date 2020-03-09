/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 11:44:17 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 23:41:26 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*d_temp;
	const char		*s_temp;
	unsigned int	n;
	unsigned int	dlen;

	d_temp = dst;
	s_temp = src;
	n = size;
	while (n-- != 0 && *d_temp != '\0')
		d_temp++;
	dlen = d_temp - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s_temp));
	while (*s_temp != '\0')
	{
		if (n != 1)
		{
			*d_temp++ = *s_temp;
			n--;
		}
		s_temp++;
	}
	*d_temp = '\0';
	return (dlen + (s_temp - src));
}
