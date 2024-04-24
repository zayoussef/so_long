/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/24 16:21:17 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_pos	*find_enemies(char **map, char c)
{
	int		i;
	int		k;
	int		l;
	t_pos	*enemies;

	i = count_size(map, c);
	enemies = malloc(sizeof(t_pos) * (i + 1)); //
	k = 0;
	while (map[k])
	{
		l = 0;
		while (map[k][l])
		{
			if (map[k][l] == c)
			{
				i--;
				enemies[i].x = l;
				enemies[i].y = k;
			}
			l++;
		}
		k++;
	}
	return (enemies);
}

t_map	*map_rendering_bonus(char *path)
{
	t_map	*map;
	int		i;

	i = 0;
	map = malloc(sizeof(t_map));
	if (!map)
	{
		function_errors(3);
		exit(EXIT_FAILURE);
	}
	map->map = map_validation_bonus(path);
	map->x = ft_strlen(map->map[0]);
	while (map->map[i])
		i++;
	map->y = i;
	map->c = count_size(map->map, 'C');
	map->player = find_position(map->map, 'P');
	map->enemies = find_enemies(map->map, 'N');
	return (map);
}
