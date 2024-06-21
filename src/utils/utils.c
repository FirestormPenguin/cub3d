/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:08:21 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 04:52:33 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strchr2(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return (str);
	return (NULL);
}

char	*format_itoa(int mem, char *str, int size)
{
	while (mem > 9 || mem < -9)
	{
		if (mem < 0)
			str[size--] = -(mem % 10) + '0';
		else
			str[size--] = mem % 10 + '0';
		mem /= 10;
	}
	str[0] = (mem + '0');
	if (mem < 0)
	{
		str[0] = '-';
		str[1] = (-mem + '0');
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		mem;

	mem = n;
	size = 2;
	if (n < 0)
		size = 3;
	while ((n > 9 || n < -9) && size++)
		n /= 10;
	str = malloc((size--) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	return (format_itoa(mem, str, size));
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}
