/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:25:49 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/21 20:34:58 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		p = (char *)malloc(1);
		if (!p)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	i = ft_strlen(s);
	if (i - start < len)
		len = (ft_strlen(s) - start);
	p = (char *)malloc((len + 1) * sizeof (char));
	if (!p)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
