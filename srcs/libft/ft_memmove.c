/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:47:29 by oelbelam          #+#    #+#             */
/*   Updated: 2018/11/01 22:27:20 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*srcd;

	srcd = (char*)malloc(sizeof(char) * len);
	ft_memcpy(srcd, src, len);
	ft_memcpy((char*)dst, srcd, len);
	return (dst);
}
