/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:32:13 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/23 20:27:08 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	char	*temp;
	char	temp2;
	int		i;

	i = 0;
	temp = s;
	while (*s)
		s++;
	s = s - 1;
	while (temp[i] != *s)
	{
		temp2 = temp[i];
		temp[i] = *s;
		*s = temp2;
		i++;
		s--;
	}
}
