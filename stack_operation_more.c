/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:32:51 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/05 16:35:57 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rra(t_list **stack_a)
{
	write(1, "rra\n", 4);
	ft_rev_rotate(stack_a);
}

void	rrb(t_list **stack_b)
{
	write(1, "rrb\n", 4);
	ft_rev_rotate(stack_b);
}

void	sa(t_list **stack_a)
{
	write(1, "sa\n", 3);
	ft_swap(stack_a);
}
