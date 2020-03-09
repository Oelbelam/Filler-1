/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:44:28 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/09 14:02:30 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;
	char	*ch;
	char	*tmp;

	ch = (char*)src;
	tmp = dest;
	i = 0;
	while (*tmp)
		tmp++;
	while (ch[i] != '\0' && (int)n > 0)
	{
		*tmp = ch[i];
		i++;
		n--;
		tmp++;
	}
	*tmp = '\0';
	return (dest);
}
