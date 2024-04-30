/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/30 12:58:38 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_images_2(t_game *so_long)
{
	so_long->image->img1 = mlx_xpm_file_to_image(so_long->mlx,
			"textures_enemy/enemy_1.xpm", &so_long->size, &so_long->size);
	so_long->image->img2 = mlx_xpm_file_to_image(so_long->mlx,
			"textures_enemy/enemy_2.xpm", &so_long->size, &so_long->size);
	so_long->image->img3 = mlx_xpm_file_to_image(so_long->mlx,
			"textures_enemy/enemy_3.xpm", &so_long->size, &so_long->size);
	so_long->image->img4 = mlx_xpm_file_to_image(so_long->mlx,
			"textures_enemy/enemy_4.xpm", &so_long->size, &so_long->size);
	so_long->image->img5 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/collect.xpm", &so_long->size, &so_long->size);
	so_long->image->img6 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/exit.xpm", &so_long->size, &so_long->size);
}

void	get_images(t_game *so_long)
{
	get_images_2(so_long);
	so_long->image->img7 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_up.xpm", &so_long->size, &so_long->size);
	so_long->image->img8 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/wall.xpm", &so_long->size, &so_long->size);
	so_long->image->img9 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/empty.xpm", &so_long->size, &so_long->size);
	so_long->image->img10 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_down.xpm", &so_long->size, &so_long->size);
	so_long->image->img11 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_left.xpm", &so_long->size, &so_long->size);
	so_long->image->img12 = mlx_xpm_file_to_image(so_long->mlx,
			"textures/player_rigth.xpm", &so_long->size, &so_long->size);
	if (!so_long->image->img1 || !so_long->image->img2 || !so_long->image->img3
		|| !so_long->image->img4 || !so_long->image->img5
		|| !so_long->image->img6 || !so_long->image->img7
		|| !so_long->image->img8 || !so_long->image->img9
		|| !so_long->image->img10 || !so_long->image->img11
		|| !so_long->image->img12)
	{
		ft_putstr("Invalid file xpm content\n", 2);
		free_failure_exit(so_long);
	}
}

int	free_clean_way(t_game *game)
{
	free_map(game->map->map);
	free(game->image);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
	return (1);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*so_long;

	if (ac != 2)
	{
		function_errors(1);
		return (0);
	}
	map = map_rendering_bonus(av[1]);
	if (!map)
		exit(EXIT_FAILURE);
	so_long = setup_game_bonus(map);
	display_game_bonus(so_long);
	mlx_hook(so_long->win, 2, 0, &event_bonus, so_long);
	mlx_loop_hook(so_long->mlx, &function_enemy, so_long);
	mlx_hook(so_long->win, 17, 0, free_clean_way, so_long);
	mlx_loop(so_long->mlx);
}
