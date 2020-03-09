/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 21:31:34 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 19:30:29 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (n > 0)
	{
		if (ft_strncmp(&s1[i], &s2[i], n) != 0)
			return (0);
		i++;
		n--;
	}
	return (1);
}
