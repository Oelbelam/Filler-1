/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:31:16 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/31 18:35:26 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		range;
	char	*ch;
	char	*ch2;

	str = (char*)s1;
	range = ft_strlen(str);
	if (!(ch = (char*)malloc((range + 1) * sizeof(char))))
		return (NULL);
	ch2 = ch;
	while (*str != '\0')
	{
		*ch2 = *str;
		ch2++;
		str++;
	}
	*ch2 = '\0';
	return (ch);
}
