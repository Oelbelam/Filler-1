/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:23:54 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 15:25:51 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*tab;
	int		i;
	int		slen;

	if (!s || !f)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	tab = (char*)malloc(sizeof(char) * (slen + 1));
	if (!tab)
		return (NULL);
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		tab[i] = f(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
