/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/13 17:28:28 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	push_to_b(int start, int finish, t_list **a, t_list **b)
{
	int	size;
	int	position;
	int	amount;

	amount = count_inside(*a, start, finish);
	while (amount)
	{
		size = ft_lstsize(*a);
		position = find_positions(*a, start, finish);
		rotate_a_to_position(size, position, a);
		pb(a, b);
		amount--;
	}
}

void	push_to_a(t_list **a, t_list **b)
{
	int	size;
	int	position;
	int	biggest;
	int	smallest;

	while (*b)
	{
		size = ft_lstsize(*b);
		biggest = find_biggest_pos(*b);
		smallest = find_smallest_pos(*b);
		position = biggest;
		if (smallest < biggest)
			position = smallest;
		rotate_b_to_position(size, position, b);
		pa(a, b);
		if (smallest < biggest)
			ra(a);
	}
}

int	find_next_chunk(t_list *lst, int chunk_size)
{
	int			start;
	static int	count;
	int			size;

	size = ft_lstsize(lst);
	start = INT32_MIN;
	while (chunk_size)
	{
		if (count >= size)
			return (INT32_MIN);
		start = ft_biggest_next_val(count, lst);
		count++;
		chunk_size--;
	}
	return (start);
}

void	sort_remaining(t_list **a, t_list **b, int start, int finish)
{
	start = INT32_MIN;
	push_to_b(start, finish, a, b);
	push_to_a(a, b);
}

void	sort_chunk(t_list **a, t_list **b, int chunk_size)
{
	int	start;
	int	finish;
	int	i;
	int	size;
	int	top;

	i = 0;
	size = ft_lstsize(*a);
	finish = INT32_MAX;
	while (i * chunk_size < size)
	{
		start = find_next_chunk(*a, chunk_size);
		push_to_b(start, finish, a, b);
		if (i > 0)
			rotate_a_for_receiving(a, top, b);
		i++;
		if (i * chunk_size <= size)
		{
			top = find_smallest(*b);
			push_to_a(a, b);
			finish = start - 1;
		}
	}
	if (size % chunk_size > 0)
		sort_remaining(a, b, start, finish);
}
