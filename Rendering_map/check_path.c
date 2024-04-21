/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/21 17:12:06 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**ft_copy_map(char **map)
{
	char	**copy_map;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy_map = malloc(sizeof(char *) * (i + 1));
	if (!copy_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[i] = 0;
	return (copy_map);
}

void	check_valid_path(char **map, int x, int y, int max_x, int max_y)
{
	if (x <= 0 || y <= 0 || map[x][y] == '1' || map[x][y] == 'Z' || x >= max_x || y >= max_y)
		return ;
	if (map[x][y] == '0' || map[x][y] == 'C')
		map[x][y] = 'Z';
	if (map[x][y] == 'E')
	{
		map[x][y] = 'Z';
		return ;
	}
	check_valid_path(map, x + 1, y, max_x, max_y);
	check_valid_path(map, x - 1, y, max_x, max_y);
	check_valid_path(map, x, y + 1, max_x, max_y);
	check_valid_path(map, x, y - 1, max_x, max_y);
}

int	is_still(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validation_path(char **map)
{
	t_pos	*player;
	char	**copy_map;
	int max_x;
	int max_y;

	player = find_position(map, 'P');
	copy_map = ft_copy_map(map);
	max_y = ft_strlen(map[0]);
	max_x = 0;
	while (map[max_x])
		max_x++;
	check_valid_path(copy_map, player->x, player->y, max_x, max_y);
	free(player);
	if (!is_still(copy_map))
	{
		maps_errors(4);
		free_map(copy_map);
		exit(EXIT_FAILURE);
	}
	free_map(copy_map);
	return (1);
}
