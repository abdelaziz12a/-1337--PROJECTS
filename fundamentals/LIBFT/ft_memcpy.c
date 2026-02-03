/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:01:05 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/22 23:37:37 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*p_sr;
	unsigned char		*p_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	p_sr = (const unsigned char *)src;
	p_dst = (unsigned char *) dst;
	while (n--)
	{
		*p_dst++ = *p_sr++;
	}
	return (dst);
}
