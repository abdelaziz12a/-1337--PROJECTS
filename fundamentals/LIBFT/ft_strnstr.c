/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:54:49 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/14 11:16:41 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	o;

	o = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!haystack && len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		o = 0;
		while (haystack[i + o] && haystack[i + o] == needle[o] && (i + o) < len)
		{
			o++;
			if (needle[o] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
