/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelbelam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 19:08:37 by oelbelam          #+#    #+#             */
/*   Updated: 2018/10/22 21:43:24 by oelbelam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	if (!lst)
		return (NULL);
	new = f(lst);
	head = new;
	while (lst->next)
	{
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (head);
}
