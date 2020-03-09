/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:49:51 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/31 18:35:10 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*tab;

	if (s == NULL || start > len)
		return (NULL);
	tab = (char*)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[start] && len > 0)
	{
		tab[i] = s[start];
		len--;
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
