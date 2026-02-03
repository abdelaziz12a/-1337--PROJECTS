/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 23:11:37 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/21 20:12:27 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i1;
	size_t	i2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return ((char *)s2);
	if (s1 && !s2)
		return ((char *)s1);
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	p = (char *)malloc((i1 + i2 + 1) * sizeof (char));
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, i1);
	ft_memcpy(p + i1, s2, i2);
	p[i1 + i2] = '\0';
	return (p);
}
