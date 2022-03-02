/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:43:18 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/15 20:20:12 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef unsigned char	t_bool;

void	sa(t_list **stack_a);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
int		void_int(void *one);
void	ft_rev_rotate(t_list **stack);
void	ft_swap(t_list	**stack1);
void	ft_rotate(t_list **stack);
void	error_ext(void);
void	micro_sort(t_list **a, t_list **b);
void	ft_push(t_list	**stack1, t_list **stack2);
int		find_biggest_pos(t_list *lst);
void	int_checking(char *copy, int *num);
int		find_smallest_pos(t_list *lst);
int		find_biggest(t_list *lst);
int		ft_biggest_next_val(int count, t_list *lst);
void	insertion(t_list **a, t_list **b);
int		find_positions(t_list *lst, int start, int finish);
int		count_inside(t_list *a, int start, int finish);
void	sort_chunk(t_list **a, t_list **b, int chunk_size);
void	rotate_a_for_receiving(t_list **a, int should_be_on_top, t_list **b);
int		find_smallest(t_list *lst);
t_bool	is_sorted(t_list *a);
void	ft_push_swap(t_list **a, t_list **b);
void	rotate_a_to_position(int size, int position, t_list **a);
void	rotate_b_to_position(int size, int position, t_list **b);

#endif
