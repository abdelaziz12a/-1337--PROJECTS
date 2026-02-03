/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:18:08 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/14 11:15:09 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	len_s;
	size_t	d;

	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if (dstsize <= len_d)
		return (len_s + dstsize);
	else
	{
		if (dstsize - len_d - 1 >= len_s)
			d = len_s;
		else
			d = dstsize - len_d - 1;
		ft_memcpy(dst + len_d, src, d);
		dst[len_d + d] = '\0';
	}
	return (len_d + len_s);
}
