/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 22:20:05 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 22:26:58 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*ro(char *str, int pr, int dot)
{
	t_ro	ro;

	init_ro(&ro);
	if (pr == 0 && dot == 0)
		return (ft_strdup(str));
	ro.s1 = ft_strsub(str, 0, ft_strlen_dot(str));
	ro.s2 = ft_strsub(str, ft_strlen_dot(str) + 1, pr);
	ro.s3 = ft_strjoin(ro.s1, ro.s2);
	if ((int)lens(ro.s2) < pr)
		return (ron1(&ro));
	else
	{
		if (str[lens(ro.s1) + pr + 1] - '0' > 5)
			return (pg_5(&ro, pr));
		else if (str[lens(ro.s1) + pr + 1] - '0' < 5)
			return (pp_5(&ro, pr, str));
		else if (str[lens(ro.s1) + pr + 1] - '0' == 5)
			return (e_5(&ro, pr, str));
	}
	return (ro.s3);
}
