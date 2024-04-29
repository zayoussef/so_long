/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/29 17:59:03 by yozainan         ###   ########.fr       */
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

void	get_images_3(t_game *so_long, int x, int y)
{
	if (so_long->direction == 1)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img12, y * 64, x * 64);
	else if (so_long->direction == 2)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img11, y * 64, x * 64);
	else if (so_long->direction == 0)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img7, y * 64, x * 64);
	else if (so_long->direction == 3)
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img10, y * 64, x * 64);
}

void	draw_textures_bonus(t_game *so_long, int x, int y)
{
	if (so_long->map->map[x][y] == 'N')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img1, y * 64, x * 64);
	else if (so_long->map->map[x][y] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img5, y * 64, x * 64);
	else if (so_long->map->map[x][y] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img6, y * 64, x * 64);
	else if (so_long->map->map[x][y] == 'P')
		get_images_3(so_long, x, y);
	else if (so_long->map->map[x][y] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img8, y * 64, x * 64);
	else if (so_long->map->map[x][y] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->image->img9, y * 64, x * 64);
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
