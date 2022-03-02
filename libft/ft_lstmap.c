/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/07 21:25:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*nl_i;

	if (lst == 0)
		return (0);
	new_lst = ft_lstnew(0);
	nl_i = new_lst;
	if (new_lst == 0)
		return (0);
	while (lst)
	{
		nl_i->content = f(lst->content);
		if (lst->next)
		{
			nl_i->next = ft_lstnew(0);
			nl_i = nl_i->next;
		}
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (new_lst);
}
