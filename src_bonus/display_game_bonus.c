/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 15:27:29 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	event_bonus(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 13 || key == 126)
		up_bonus(game);
	else if (key == 1 || key == 125)
		down_bonus(game);
	else if (key == 0 || key == 123)
		left_bonus(game);
	else if (key == 2 || key == 124)
		right_bonus(game);
	else if (key == 53)
		free_success_exit(game);
	mlx_clear_window(game->mlx, game->win);
	display_game_bonus(game);
	mlx_loop(game->mlx);
	return (0);
}

char	*textures_path_bonus(t_game *game, char c)
{
	if (c == '0')
		return ("textures/empty.xpm");
	else if (c == '1')
		return ("textures/wall.xpm");
	else if (c == 'P')
	{
		if (game->direction == 1)
			return ("textures/player_rigth.xpm");
		else if (game->direction == 2)
			return ("textures/player_left.xpm");
		else if (game->direction == 0)
			return ("textures/player_up.xpm");
		else if (game->direction == 3)
			return ("textures/player_down.xpm");
	}
	else if (c == 'N')
		return ("textures_enemy/enemy_1.xpm");
	else if (c == 'C')
		return ("textures/collect.xpm");
	else if (c == 'E')
		return ("textures/exit.xpm");
	return (NULL);
}

void	draw_textures_bonus(t_game *so_long, int x, int y)
{
	char	*texture;

	texture = textures_path_bonus(so_long, so_long->map->map[x][y]);
	if (!texture)
		return ;
	so_long->img = mlx_xpm_file_to_image(so_long->mlx, texture, &so_long->size,
			&so_long->size);
	if (!so_long->img)
	{
		ft_putstr("Invalid file xpm content\n", 2);
		free_failure_exit(so_long);
	}
	mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->img, y * 64, x
		* 64);
	mlx_destroy_image(so_long->mlx, so_long->img);
}

void	display_counter_bonus(t_game *so_long)
{
	char	*counter;

	counter = ft_itoa(so_long->moves);
	mlx_string_put(so_long->mlx, so_long->win, 8, 10, 0XFFFFFF, counter);
	free(counter);
}

void	display_game_bonus(t_game *so_long)
{
	int	x;
	int	y;

	x = 0;
	while (so_long->map->map[x])
	{
		y = 0;
		while (so_long->map->map[x][y] && so_long->map->map[x][y] != '\n')
		{
			draw_textures_bonus(so_long, x, y);
			y++;
		}
		x++;
	}
	display_counter_bonus(so_long);
}
