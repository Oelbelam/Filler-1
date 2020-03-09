/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:39:46 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 15:25:13 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		slen;
	int		i;
	char	*tab;

	if (!s || !f)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	tab = (char *)malloc(slen + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		tab[i] = f(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
