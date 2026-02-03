/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:50:05 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/09 18:23:35 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s1);
	p = (char *)malloc((i + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, i + 1);
	return (p);
}
