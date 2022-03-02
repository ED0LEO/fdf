/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:46:31 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/15 20:20:43 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
 * Transform void pointer to int
 */

int	void_int(void *one)
{
	return (*(int *)one);
}

t_bool	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (void_int(a->content) > void_int(a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_push_swap(t_list **a, t_list **b)
{
	int	top;
	int	chunks;

	if (ft_lstsize(*a) <= 5)
	{
		micro_sort(a, b);
		return ;
	}
	if (ft_lstsize(*a) <= 60)
	{
		insertion(a, b);
		return ;
	}
	else
		chunks = ft_lstsize(*a) / 10;
	sort_chunk(a, b, chunks);
	top = find_smallest(*a);
	rotate_a_for_receiving(a, top, b);
}

void	int_checking(char *copy, int *num)
{
	int	counter;

	counter = 0;
	while (*copy && (*copy != ' '))
	{
		if (!ft_isdigit(*copy++))
			error_ext();
		counter++;
	}
	if ((void_int(num) == 0 || void_int(num) == -1 ) && counter != 1)
		error_ext();
}

void	error_ext(void)
{
	write (2, "Error\n", 6);
	exit (1);
}
