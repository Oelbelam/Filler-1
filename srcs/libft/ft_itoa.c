/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 13:44:42 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 15:00:40 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_creat_tab(int n, int i)
{
	char	*tab;

	if (n < 0)
		i = i + 1;
	tab = (char*)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (NULL);
	return (tab);
}

static char	*ft_minivalue(int i)
{
	if (i == 0)
		return (ft_strdup("0"));
	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	return (NULL);
}

static void	*ft_filltab(char *tab, int i, int n)
{
	int	k;
	int f;

	k = n;
	f = n;
	if (n < 0)
	{
		tab[i + 1] = '\0';
		tab[0] = '-';
		k = k * -1;
	}
	else
	{
		tab[i] = '\0';
		i = i - 1;
	}
	while (k != 0)
	{
		f = k % 10;
		k = k / 10;
		tab[i] = f + '0';
		i--;
	}
	return (tab);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		i;

	if (n == 0 || n == -2147483648)
		return (ft_minivalue(n));
	i = ft_intlen(n);
	tab = ft_creat_tab(n, i);
	if (tab == NULL)
		return (NULL);
	tab = ft_filltab(tab, i, n);
	return (tab);
}
