/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:52:59 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 15:31:00 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchar(const char *s, char c, int i)
{
	int		cmp;

	cmp = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		cmp++;
	}
	return (cmp);
}

static int	ft_contnstr(const char *s, char c)
{
	int		i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				cmp++;
			}
			i++;
		}
	}
	return (cmp);
}

static int	ft_countindex(const char *s, char c, int i)
{
	while (s[i] == c)
		i++;
	return (i);
}

static void	ft_filltab(const char *s, int index, char c, char *tab)
{
	int		i;

	i = 0;
	while (s[index] != c && s[index] != c && s[index])
	{
		tab[i] = s[index];
		i++;
		index++;
	}
	tab[i] = '\0';
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		start;
	int		j;
	char	**tab;
	int		k;

	if (!s || !c)
		return (NULL);
	k = 0;
	i = 0;
	j = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (ft_contnstr(s, c) + 1))) == NULL)
		return (NULL);
	while (ft_contnstr(s, c) > k)
	{
		start = i + j;
		j = ft_countindex(s, c, start);
		i = ft_countchar(s, c, j);
		tab[k] = (char *)malloc(sizeof(char) * (i + 1));
		ft_filltab(s, j, c, tab[k]);
		k++;
	}
	tab[k] = 0;
	return (tab);
}
