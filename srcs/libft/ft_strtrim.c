/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:59:32 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 20:44:03 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_allo(int slen)
{
	char	*tab;

	tab = (char*)malloc(sizeof(char) * (slen + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

char		*ft_strtrim(const char *s)
{
	int		i;
	int		slen;
	int		k;
	char	*tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (ft_strlen(s) == 0)
		return (ft_strdup(""));
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0' && (size_t)i == ft_strlen(s))
		return (ft_strdup(""));
	slen = ft_strlen(s) - 1;
	k = 0;
	while (s[slen] == '\t' || s[slen] == '\n' || s[slen] == ' ')
	{
		slen--;
		k++;
	}
	slen = ft_strlen(s) - i - k;
	tab = ft_allo(slen);
	tab = ft_strsub(s, i, slen);
	return (tab);
}
