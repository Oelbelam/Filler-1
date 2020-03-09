/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:07:31 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 14:41:09 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	j;
	char	*s2;
	int		i;

	s2 = (char *)s;
	j = 0;
	i = 0;
	while (j < n)
	{
		if ((unsigned char)s2[i] == (unsigned char)c)
			return (s2 + i);
		j++;
		i++;
	}
	return (NULL);
}
