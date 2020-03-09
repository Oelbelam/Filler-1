/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 22:32:23 by oelbelam          #+#    #+#             */
/*   Updated: 2019/08/06 22:41:35 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

size_t		lens(char *str)
{
	size_t n;

	n = 0;
	while (1)
	{
		if (str[n] == '\0')
		{
			return (n);
		}
		n++;
	}
}

int			ft_strlen_dot(char *str)
{
	int n;

	n = 0;
	while (str[n] != '.')
	{
		n++;
	}
	return (n);
}

char		*asp(char *str, size_t size, int point)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == point)
		{
			ret[i] = '.';
			point = 0;
			j++;
		}
		else
		{
			ret[j] = str[i];
			j++;
			i++;
		}
	}
	ret[size] = '\0';
	return (ret);
}

void		init_ro(t_ro *ro)
{
	ro->i = 1;
	ro->r = 1;
	ro->temp = 0;
}

char		*ron1(t_ro *ro)
{
	ro->to_del = ro->s1;
	ro->s1 = ft_strjoin(ro->s1, ".");
	free(ro->to_del);
	free(ro->s3);
	ro->s3 = ft_strjoin(ro->s1, ro->s2);
	free(ro->s1);
	free(ro->s2);
	return (ro->s3);
}
