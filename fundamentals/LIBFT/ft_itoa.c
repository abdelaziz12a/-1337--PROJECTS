/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboudra <aaboudra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:21:00 by aaboudra          #+#    #+#             */
/*   Updated: 2024/11/21 20:20:23 by aaboudra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	seg(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				lent;
	char			*res;

	lent = len(n);
	res = (char *)malloc(sizeof(char) * (lent + 1));
	if (!res)
		return (NULL);
	res[lent] = '\0';
	nb = seg(n);
	if (nb == 0)
	{
		res[0] = '0';
		return (res);
	}
	if (n < 0)
		res[0] = '-';
	while (nb > 0)
	{
		res[--lent] = (nb % 10) + '0';
		nb /= 10;
	}
	return (res);
}
