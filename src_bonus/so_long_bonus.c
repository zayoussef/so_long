/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/24 16:26:00 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	so_long = setting_game_bonus(map);
	display_game_bonus(so_long);
	mlx_hook(so_long->win, 2, 0, &event_bonus, so_long);
	mlx_hook(so_long->win, 17, 0, free_success_exit, so_long);
	mlx_loop(so_long->mlx);
}
