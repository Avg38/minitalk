/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avialle- <avialle-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:09:11 by avialle-          #+#    #+#             */
/*   Updated: 2024/02/12 13:27:45 by avialle-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return ((int)(nbr * sign));
}

char	*ft_strjoin_char(char *str, unsigned long long *len, char c)
{
	char		*dest;
	int			i;

	dest = (char *)malloc((*len + 1) * sizeof(char));
	(*len)++;
	if (!dest)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
	}
	dest[i] = c;
	dest[++i] = 0;
	if (str)
		free(str);
	return (dest);
}
