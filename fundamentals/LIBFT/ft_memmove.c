/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:24:27 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/10 14:46:19 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*p_sr;
	unsigned char		*p_ds;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst == src)
		return (dst);
	p_sr = (const unsigned char *)src;
	p_ds = (unsigned char *)dst;
	if (p_ds < p_sr)
		ft_memcpy(p_ds, p_sr, len);
	else
	{
		p_sr += len;
		p_ds += len;
		while (len--)
		{
			*(--p_ds) = *(--p_sr);
		}
	}
	return (dst);
}
