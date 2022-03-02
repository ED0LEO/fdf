/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/07 18:12:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_bef(char const *s1, char const *set)
{
	char const		*set_c;
	int				count;

	count = 0;
	while (*s1)
	{
		set_c = set;
		while (*set_c)
		{
			if (*set_c == *s1)
			{
				count++;
				break ;
			}
			else if (*(set_c + 1) == 0)
				return (count);
			set_c++;
		}
		s1++;
	}
	return (count);
}

static int	count_aft(char const *s1, char const *set)
{
	long long int	i;
	char const		*set_c;
	int				count;

	i = (long long) ft_strlen(s1) - 1;
	count = 0;
	while (i > -1)
	{
		set_c = set;
		while (*set_c)
		{
			if (*set_c == s1[i])
			{
				count++;
				break ;
			}
			else if (*(set_c + 1) == 0)
				return (count);
			set_c++;
		}
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new_str;
	size_t			size;
	int				con_b;
	int				con_a;

	if (s1 == 0 || set == 0)
		return (0);
	con_b = count_bef(s1, set);
	con_a = count_aft(s1, set);
	size = ft_strlen(s1) - (con_b + con_a);
	if ((con_b + con_a) > (int) ft_strlen(s1))
		size = ft_strlen(s1);
	new_str = malloc(size + 1);
	if (new_str == 0)
		return (0);
	if (size <= 0)
	{
		new_str[0] = '\0';
		return (new_str);
	}
	ft_memcpy(new_str, s1 + con_b, size);
	new_str[size] = '\0';
	return (new_str);
}
