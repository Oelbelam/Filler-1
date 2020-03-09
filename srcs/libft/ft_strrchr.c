/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:46:25 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/22 18:51:07 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ch;
	char *temp;

	ch = (char*)s;
	temp = ch;
	while (*ch)
	{
		ch++;
	}
	while (*ch != *temp)
	{
		if (*ch == c)
			return (ch);
		ch--;
	}
	if (*ch == c)
		return (ch);
	return (NULL);
}
