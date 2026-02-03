/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:49:49 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/05 21:33:09 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	len_s;

	len_s = ft_strlen(src);
	if (dstsize > 0)
	{
		if (dstsize > len_s)
			d = len_s;
		else
			d = dstsize - 1;
		ft_memcpy(dst, src, d);
		dst[d] = '\0';
	}
	return (len_s);
}
