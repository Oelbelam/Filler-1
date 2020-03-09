/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 10:10:25 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/07 13:39:21 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int					ft_putstr_s(const char *s, int pr)
{
	int	count;

	count = 0;
	while (*s && pr)
	{
		count += write(1, s, 1);
		s++;
		pr--;
	}
	return (count);
}

static void			s_conv_n(t_flag *p, char *s, int *ret)
{
	if (p->fw >= p->fpr)
	{
		if (p->fpr >= 0)
		{
			*ret += ft_putstr_s(s, p->fpr);
			if (ft_strlen(s) > (size_t)p->fpr)
				*ret += print_spaces(p->fw - p->fpr);
			else
				*ret += print_spaces(p->fw - ft_strlen(s));
		}
		else
		{
			*ret += ft_putstr_s(s, (int)ft_strlen(s));
			*ret += print_spaces(p->fw - ft_strlen(s));
		}
	}
	else if (p->fw < p->fpr)
	{
		*ret += ft_putstr_s(s, p->fpr);
		*ret += print_spaces(p->fw - ft_strlen(s));
	}
}

static void			s_conv_p(t_flag *p, char *s, int *ret)
{
	if (p->fm == 0 && p->fw >= p->fpr)
	{
		if (p->fpr >= 0)
		{
			if (ft_strlen(s) > (size_t)p->fpr)
				*ret += print_spaces(p->fw - p->fpr);
			else
				*ret += print_spaces(p->fw - ft_strlen(s));
			*ret += ft_putstr_s(s, p->fpr);
		}
		else
		{
			*ret += print_spaces(p->fw - ft_strlen(s));
			*ret += ft_putstr_s(s, (int)ft_strlen(s));
		}
	}
	else if (p->fm == 0 && p->fw < p->fpr)
	{
		*ret += print_spaces(p->fw - ft_strlen(s));
		*ret += ft_putstr_s(s, p->fpr);
	}
	else if (p->fm == 1)
		s_conv_n(p, s, ret);
}

void				s_conv(const char *frm, int *i, va_list ap, int *ret)
{
	char		*s;
	char		*str;
	int			j;
	t_flag		*p;

	s = va_arg(ap, char*);
	str = (s == NULL) ? ft_strdup("(null)") : ft_strdup(s);
	j = *i;
	p = (t_flag*)malloc(sizeof(t_flag));
	stock_flag(frm, j, p);
	s_conv_p(p, str, ret);
	free(str);
	free(p);
}
