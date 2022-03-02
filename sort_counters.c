/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_counters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/13 18:57:41 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	find_smallest_pos(t_list *lst)
{
	int			min;
	int			iter;
	t_list		*lst_start;

	min = INT32_MAX;
	lst_start = lst;
	iter = 0;
	while (lst)
	{
		if (void_int(lst->content) < min)
			min = void_int(lst->content);
		lst = lst->next;
	}
	lst = lst_start;
	while (lst)
	{
		if (void_int(lst->content) == min)
			break ;
		iter++;
		lst = lst->next;
	}
	return (iter);
}

int	find_biggest_pos(t_list *lst)
{
	int		max;
	int		iter;
	t_list	*lst_start;

	max = INT32_MIN;
	lst_start = lst;
	iter = 0;
	while (lst)
	{
		if (void_int(lst->content) > max)
			max = void_int(lst->content);
		lst = lst->next;
	}
	lst = lst_start;
	while (lst)
	{
		if (void_int(lst->content) == max)
			break ;
		iter++;
		lst = lst->next;
	}
	return (iter);
}

int	find_positions(t_list *lst, int start, int finish)
{
	int			iter;

	iter = 0;
	while (lst)
	{
		if (void_int(lst->content) >= start && void_int(lst->content) <= finish)
			break ;
		iter++;
		lst = lst->next;
	}
	return (iter);
}

int	count_inside(t_list *a, int start, int finish)
{
	int	count;

	count = 0;
	while (a)
	{
		if (void_int(a->content) >= start && void_int(a->content) <= finish)
			count++;
		a = a->next;
	}
	return (count);
}

int	find_smallest(t_list *lst)
{
	int	min;

	min = INT32_MAX;
	while (lst)
	{
		if (void_int(lst->content) < min)
			min = void_int(lst->content);
		lst = lst->next;
	}
	return (min);
}
