/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:27:25 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/14 14:57:47 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tab;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	tab = (char*)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		tab[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		tab[j] = s2[i];
		j++;
		i++;
	}
	tab[j] = '\0';
	return (tab);
}
