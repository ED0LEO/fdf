/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <mlothair@student.21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 14:15:09 by mlothair          #+#    #+#             */
/*   Updated: 2021/10/06 16:01:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dst_cpy;
	char	*src_cpy;
	size_t	n;
	size_t	dlen;

	n = dstsize;
	src_cpy = (char *) src;
	dst_cpy = dst;
	while (n-- != 0 && *dst_cpy != '\0')
		dst_cpy++;
	dlen = dst_cpy - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(src_cpy));
	while (*src_cpy != '\0')
	{
		if (n != 1)
		{
			*dst_cpy++ = *src_cpy;
			n--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (dlen + (src_cpy - src));
}
