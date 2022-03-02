/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:32:51 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/13 17:06:48 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	write(1, "pa\n", 3);
	ft_push(stack_a, stack_b);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	write(1, "pb\n", 3);
	ft_push(stack_b, stack_a);
}

void	ra(t_list **stack_a)
{
	write(1, "ra\n", 3);
	ft_rotate(stack_a);
}

void	rb(t_list **stack_b)
{
	write(1, "rb\n", 3);
	ft_rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	write(1, "rr\n", 3);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}
