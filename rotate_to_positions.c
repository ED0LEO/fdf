/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_positions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/13 20:54:29 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rotate_a_to_position(int size, int position, t_list **a)
{
	if (position <= (size / 2))
	{
		while (position)
		{
			position--;
			ra(a);
		}
	}
	else
	{
		position = size - position;
		while (position)
		{
			position--;
			rra(a);
		}
	}
}

void	rotate_b_to_position(int size, int position, t_list **b)
{
	if (position <= (size / 2))
	{
		while (position)
		{
			position--;
			rb(b);
		}
	}
	else
	{
		position = size - position;
		while (position)
		{
			position--;
			rrb(b);
		}
	}
}

static int	find_pos_by_val(t_list *lst, int val)
{
	int	res;

	res = 0;
	while (lst)
	{
		if (void_int(lst->content) == val)
			break ;
		res++;
		lst = lst->next;
	}
	return (res);
}

void	rotate_a_for_receiving(t_list **a, int should_be_on_top, t_list **b)
{
	int	position;

	position = find_pos_by_val(*a, should_be_on_top);
	if (position <= (ft_lstsize(*a) / 2))
	{
		while (position--)
		{
			if (*b && (*b)->next
				&& void_int((*b)->content) < void_int((*b)->next->content))
				rr(a, b);
			else
				ra(a);
		}
		return ;
	}
	position = ft_lstsize(*a) - position;
	while (position--)
	{
		if (*b && (*b)->next
			&& void_int((*b)->content) < void_int((*b)->next->content))
			rr(a, b);
		else
			rra(a);
	}
}
