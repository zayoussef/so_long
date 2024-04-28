/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 15:20:10 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**map_validation_bonus(char *path)
{
	char	**map;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		function_errors(2);
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (!check_extension(path))
		exit(EXIT_FAILURE);
	map = reading_map(path);
	if (!validate_content_bonus(map) || !validation_format(map)
		|| !validation_path(map))
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}

t_game	*setting_game_bonus(t_map *map)
{
	t_game	*so_long;

	so_long = malloc(sizeof(t_game));
	so_long->image = malloc(sizeof(t_img));
	if (!so_long || !so_long->image)
		return (NULL);
	so_long->mlx = mlx_init();
	if (map->x * 64 > MAX_WIDTH || map->y * 64 > MAX_HEIGHT)
	{
		ft_putstr("Map too big\n", 2);
		free(so_long);
		free_map(map->map);
		free(map->enemies);
		free(map->player);
		free(so_long->image);
		exit(EXIT_FAILURE);
	}
	enemy_images_bonus(so_long);
	so_long->win = mlx_new_window(so_long->mlx, map->x * 64, map->y * 64,
			"so_long_bonus");
	so_long->map = map;
	so_long->size = 64;
	so_long->moves = 0;
	so_long->direction = 1;
	return (so_long);
}
