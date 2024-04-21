/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/21 12:50:24 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			maps_errors(3);
			return (0);
		}
		i++;
	}
	j = i - 1;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[j][i] != '1')
		{
			maps_errors(3);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_rectangular(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			maps_errors(3);
			return (0);
		}
		i++;
	}
	return (1);
}

int	validation_format(char **map)
{
	if (!is_closed(map) || !is_rectangular(map))
		return (0);
	return (1);
}
