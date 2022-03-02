/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_commads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:32:51 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/05 19:03:45 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(t_list	**stack1)
{
	t_list	*tmp;

	if (ft_lstsize(*stack1) < 2)
		return ;
	tmp = (*stack1)->next;
	(*stack1)->next = tmp->next;
	tmp->next = *stack1;
	*stack1 = tmp;
}

void	ft_push(t_list	**stack1, t_list **stack2)
{
	t_list	*s1_first;

	if (ft_lstsize(*stack2) < 1)
		return ;
	s1_first = *stack2;
	*stack2 = (*stack2)->next;
	s1_first->next = *stack1;
	*stack1 = s1_first;
}

void	ft_rotate(t_list **stack)
{
	t_list	*s_last;
	t_list	*s_first;

	if (ft_lstsize(*stack) < 2)
		return ;
	s_last = *stack;
	s_first = (*stack)->next;
	(ft_lstlast(*stack))->next = s_last;
	s_last->next = 0;
	*stack = s_first;
}

void	ft_rev_rotate(t_list **stack)
{
	t_list	*s_last;
	t_list	*s_first;

	if (ft_lstsize(*stack) < 2)
		return ;
	s_last = *stack;
	while (s_last->next->next)
		s_last = s_last->next;
	s_first = ft_lstlast(*stack);
	s_first->next = *stack;
	s_last->next = 0;
	*stack = s_first;
}
