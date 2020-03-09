/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:55:26 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/12 15:03:33 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char*)malloc(size + 1);
	if (!tab)
		return (NULL);
	while (i <= size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
