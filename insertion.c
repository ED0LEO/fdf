/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/15 20:14:01 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_biggest_next_val(int count, t_list *lst)
{
	int		max;
	t_list	*lst_start;
	int		max_temp;

	max = INT32_MIN;
	lst_start = lst;
	while (count)
	{
		max_temp = INT32_MIN;
		lst = lst_start;
		while (lst)
		{
			if (void_int(lst->content) > max_temp)
			{
				if ((void_int(lst->content) < max) || (max == INT32_MIN))
					max_temp = void_int(lst->content);
			}
			lst = lst->next;
		}
		max = max_temp;
		count--;
	}
	return (max);
}

int	find_biggest(t_list *lst)
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

void	insertion(t_list **a, t_list **b)
{
	int	size;
	int	smol;
	int	chunky;

	while (*a)
	{
		size = ft_lstsize(*a);
		smol = find_smallest_pos(*a);
		chunky = find_biggest_pos(*a);
		if (smol < chunky)
			rotate_a_to_position(size, smol, a);
		else
			rotate_a_to_position(size, chunky, a);
		pb(a, b);
		while (*a && (!find_smallest_pos(*a) || !find_biggest_pos(*a)))
			pb(a, b);
	}
	while (*b)
	{
		size = ft_lstsize(*b);
		rotate_b_to_position(size, find_biggest(*b), b);
		pa(a, b);
		while (!find_biggest_pos(*b) && *b)
			pa(a, b);
	}
}

static void	micro_sort_b(t_list **a, t_list **b)
{
	int	a2;
	int	a3;
	int	b_top;
	int	a4;
	int	position;

	while (*b)
	{
		a2 = void_int((*a)->next->content);
		a3 = void_int((*a)->next->next->content);
		if (ft_lstsize((*a)) > 3)
			a4 = void_int(ft_lstlast(*a)->content);
		b_top = void_int((*b)->content);
		position = 0;
		if (ft_lstsize(*a) > 3 && a3 < b_top && a4 > b_top)
			position = find_positions(*a, a4, a4);
		else if (a2 < b_top && a3 > b_top)
			position = find_positions(*a, a3, a3);
		else if (void_int((*a)->content) < b_top && a2 > b_top)
			position = find_positions(*a, a2, a2);
		rotate_a_to_position(ft_lstsize(*a), position, a);
		pa(a, b);
		if (!is_sorted(*a))
			rotate_a_to_position(ft_lstsize(*a), find_smallest_pos(*a), a);
	}
}

void	micro_sort(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		pb(a, b);
	if (void_int((*a)->content) > void_int((*a)->next->content))
		sa(a);
	if (void_int(ft_lstlast(*a)->content) < void_int((*a)->content))
		rra(a);
	if (void_int((*a)->content) > void_int((*a)->next->content))
		sa(a);
	if (is_sorted(*a) && !(*b))
	{
		ft_lstclear(a, free);
		exit (0);
	}
	if (void_int((*a)->next->content) > void_int((*a)->next->next->content))
	{
		rra(a);
		sa(a);
	}
	if (*b)
		micro_sort_b(a, b);
	if (!is_sorted(*a))
		rotate_a_to_position(ft_lstsize(*a), find_smallest_pos(*a), a);
}
