/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/07 19:43:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_finding(size_t i, char *h_c, const char *needle)
{
	size_t	j;
	char	*hi_c;
	char	*n_c;

	while (*h_c && i)
	{
		hi_c = h_c;
		j = i;
		n_c = (char *) needle;
		while (*n_c && j)
		{
			if (*n_c != *hi_c)
				break ;
			n_c++;
			hi_c++;
			j--;
			if (*n_c == '\0')
				return (h_c);
		}
		i--;
		h_c++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h_c;

	h_c = (char *) haystack;
	i = len;
	if (*needle == 0)
		return (h_c);
	return (ft_finding(i, h_c, needle));
}
