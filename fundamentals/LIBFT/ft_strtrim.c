/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:25:52 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/14 11:24:31 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chec(char c, const char *st)
{
	while (*st)
	{
		if (*st == c)
			return (1);
		st++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	s;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (!*set)
		return (ft_strdup(s1));
	l = ft_strlen(s1);
	s = 0;
	while (s1[s] && chec(s1[s], set))
		s++;
	while (l > s && chec(s1[l - 1], set))
		l--;
	return (ft_substr(s1, s, l - s));
}
