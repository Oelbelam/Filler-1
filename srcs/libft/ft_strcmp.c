/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:46:13 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/08 21:07:47 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	cnv;

	cnv = 0;
	while (s1[cnv] && s2[cnv] && s1[cnv] == s2[cnv])
		++cnv;
	return ((unsigned char)s1[cnv] - (unsigned char)s2[cnv]);
}
