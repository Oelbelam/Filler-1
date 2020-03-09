/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:32:43 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 23:00:09 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

char	*pg_5(t_ro *ro, int pr)
{
	ro->temp = lens(ro->s3);
	ro->to_del = ro->s3;
	ro->s3 = ft_add_str(ro->s3, "1");
	free(ro->to_del);
	if (ro->temp < (int)lens(ro->s3))
		ro->s4 = asp(ro->s3, lens(ro->s1) + pr + 2, lens(ro->s1) + 1);
	else
		ro->s4 = asp(ro->s3, lens(ro->s1) + pr + 1, lens(ro->s1));
	free(ro->s1);
	free(ro->s2);
	free(ro->s3);
	return (ro->s4);
}

char	*pp_5(t_ro *ro, int pr, char *str)
{
	if (str[lens(ro->s1) + pr] == '.')
		pr -= 1;
	ro->s4 = asp(ro->s3, lens(ro->s1) + pr + 1, lens(ro->s1));
	free(ro->s1);
	free(ro->s2);
	free(ro->s3);
	return (ro->s4);
}

char	*e_5_c_2(t_ro *ro, int pr)
{
	ro->temp = lens(ro->s3);
	ro->to_del = ro->s3;
	ro->s3 = ft_add_str(ro->s3, "1");
	free(ro->to_del);
	if (ro->temp < (int)lens(ro->s3))
		ro->s4 = asp(ro->s3, lens(ro->s1) + pr + 2, lens(ro->s1) + 1);
	else
		ro->s4 = asp(ro->s3, lens(ro->s1) + pr + 1, lens(ro->s1));
	free(ro->s1);
	free(ro->s2);
	free(ro->s3);
	return (ro->s4);
}

char	*e_5_c(t_ro *ro, int pr, char *str)
{
	if (str[lens(ro->s1) + pr] == '.')
		pr -= 1;
	if ((str[lens(ro->s1) + pr] - '0') % 2 == 0)
	{
		ro->to_del = ro->s1;
		ro->s1 = ft_strjoin(ro->s1, ".");
		free(ro->to_del);
		free(ro->s3);
		ro->s3 = ft_strjoin(ro->s1, ro->s2);
		free(ro->s2);
		free(ro->s1);
		return (ro->s3);
	}
	else
		return (e_5_c_2(ro, pr));
}

char	*e_5(t_ro *ro, int pr, char *str)
{
	while (str[lens(ro->s1) + pr + 1 + ro->i] != '\0')
	{
		if (str[lens(ro->s1) + pr + 1 + ro->i] - '0' != 0)
		{
			ro->r = 0;
			ro->temp = lens(ro->s3);
			ro->to_del = ro->s3;
			ro->s3 = ft_add_str(ro->s3, "1");
			free(ro->to_del);
			if (ro->temp < (int)lens(ro->s3))
				ro->s4 = asp(ro->s3, lens(ro->s1) + pr + 2, lens(ro->s1) + 1);
			else
				ro->s4 = asp(ro->s3, lens(ro->s1) + pr + 1, lens(ro->s1));
			free(ro->s1);
			free(ro->s2);
			free(ro->s3);
			return (ro->s4);
		}
		else
			ro->r = 1;
		ro->i++;
	}
	if (ro->r == 1)
		return (e_5_c(ro, pr, str));
	return (ro->s3);
}
