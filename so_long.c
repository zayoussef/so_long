/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/21 18:05:50 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_game	*so_long;

	if (ac != 2)
	{
		function_errors(1);
		return (0);
	}
	map = map_rendering(av[1]);
	if (!map)
		exit(EXIT_FAILURE);
	so_long = setting_game(map);
	display_game(so_long);
	printf("NOW WE CAN DISPLAY THE MAP\n");
	mlx_hook(so_long->win, 2,  0 << 1L,&event, so_long);
	mlx_hook(so_long->win, 17, 0, free_exit, so_long);
	mlx_loop(so_long->mlx);
	printf ("END OF THE GAME\n");
}
