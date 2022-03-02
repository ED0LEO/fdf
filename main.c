/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:33:22 by mlothair          #+#    #+#             */
/*   Updated: 2021/11/15 21:40:53 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_bool	doubles_clean(t_list *lst)
{
	t_list	*copy;

	while (lst->next)
	{
		copy = lst->next;
		while (copy)
		{
			if (void_int(lst->content) == void_int(copy->content))
				return (0);
			copy = copy->next;
		}
		lst = lst->next;
	}
	return (1);
}

void	parse_string(t_list **a, char *str)
{
	int		*num;
	t_list	*new;

	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		num = malloc(sizeof (int *));
		if (!num)
			error_ext();
		*num = ft_atoi(str);
		if (*str == '-')
			str++;
		int_checking(str, num);
		new = ft_lstnew(num);
		if (!new)
			error_ext();
		ft_lstadd_back(a, new);
		if (*str == '-')
			str++;
		while (*str && *str != ' ')
			str++;
	}
	if (!ft_lstsize(*a))
		error_ext();
}

void	parse_args(t_list **a, int argc, char **argv)
{
	int		i;
	int		*num;
	t_list	*new;

	i = 1;
	while (i < argc)
	{
		if (!argv[i])
			error_ext();
		num = malloc(sizeof (int *));
		if (!num)
			error_ext();
		*num = ft_atoi(argv[i]);
		if (*argv[i] == '-')
			argv[i]++;
		int_checking(argv[i], num);
		new = ft_lstnew(num);
		if (!new)
			error_ext();
		ft_lstadd_back(a, new);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = 0;
	b = 0;
	if (argc < 2)
		exit (0);
	if (argc == 2)
		parse_string(&a, argv[1]);
	else
		parse_args(&a, argc, argv);
	if (!doubles_clean(a))
		error_ext();
	if (is_sorted(a))
	{
		ft_lstclear(&a, free);
		exit (0);
	}
	ft_push_swap(&a, &b);
	exit (0);
}
