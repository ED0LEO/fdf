/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/08 14:39:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*remove_doubles(const char *s, char c)
{
	char	*ns;
	int		i;

	i = 0;
	ns = malloc(ft_strlen(s) + 2);
	if (ns == 0)
		return (0);
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c && *(s + 1) == c)
		{
			s++;
			continue ;
		}
		ns[i] = *s;
		s++;
		i++;
	}
	i--;
	while (ns[i] == c)
		i--;
	ns[i + 1] = '\0';
	return (ns);
}

int	splitting_logic(char **new_str, char *ss, char c, int *ns_i)
{
	int		ns_j;
	size_t	size;

	ns_j = 0;
	size = ft_strlen(ss);
	while (*ss)
	{
		if (*ss != c)
		{
			new_str[*ns_i][ns_j] = *ss++;
			ns_j++;
			continue ;
		}
		new_str[*ns_i][ns_j] = '\0';
		if (*(ss + 1))
		{
			(*ns_i)++;
			ns_j = 0;
			new_str[*ns_i] = malloc(size);
			if (new_str[*ns_i] == 0)
				return (0);
		}
		ss++;
	}
	return (ns_j);
}

static int	count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	count += 2;
	return (count);
}

int	split_valid(char const *s, char c, char **ss, char ***new_str)
{
	*new_str = malloc(2 * sizeof (char *));
	if (*new_str == 0)
		return (0);
	(*new_str)[0] = 0;
	(*new_str)[1] = 0;
	if (count_words(s, c) == 2 && ft_strlen(s) > 1)
	{
		(*new_str)[0] = remove_doubles(s, c);
		return (1);
	}
	if (count_words(s, c) == (int) ft_strlen(s) + 2)
		return (1);
	free (*new_str);
	*ss = remove_doubles(s, c);
	if (*ss == 0)
		return (0);
	*new_str = malloc(count_words(*ss, c) * sizeof (char *));
	if (*new_str == 0)
		return (0);
	(*new_str)[0] = *ss;
	(*new_str)[1] = 0;
	if (c == '\0')
		return (1);
	return (3);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	char	*ss;
	int		ns_i;
	int		ret;
	int		result;

	ns_i = 0;
	if (s == 0)
		return (0);
	result = split_valid(s, c, &ss, &new_str);
	if (result == 1)
		return (new_str);
	else if (result == 0)
		return (0);
	new_str[ns_i] = malloc(ft_strlen(ss));
	ret = splitting_logic(new_str, ss, c, &ns_i);
	free (ss);
	if (!ret)
		return (0);
	new_str[ns_i][ret] = '\0';
	new_str[ns_i + 1] = 0;
	return (new_str);
}
