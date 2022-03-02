/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/07 21:34:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void					*or_dst;
	long long int			i;
	char					*dst_cpy;
	char					*src_cpy;

	i = -1;
	or_dst = dst;
	dst_cpy = (char *) dst;
	src_cpy = (char *) src;
	if ((dst == 0 && src == 0) || dst_cpy == src_cpy || len == 0)
		return (dst);
	if ((dst_cpy > src_cpy) && (dst_cpy < src_cpy + len))
	{
		i = (long long) len - 1;
		while (i-- > -1)
			dst_cpy[i + 1] = src_cpy[i + 1];
	}
	else
	{
		i++;
		while (i++ < (long long) len)
			dst_cpy[i - 1] = src_cpy[i - 1];
	}
	return (or_dst);
}
