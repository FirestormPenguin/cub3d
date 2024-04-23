/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:08:21 by egiubell          #+#    #+#             */
/*   Updated: 2024/04/23 16:08:33 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
