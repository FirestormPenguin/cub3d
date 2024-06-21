/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 04:52:35 by egiubell          #+#    #+#             */
/*   Updated: 2024/06/21 05:12:22 by egiubell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_isrgb(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		if (ft_atoi(mtx[i]) < 0 || ft_atoi(mtx[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] < '0' || mtx[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
