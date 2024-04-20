/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/20 22:17:22 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	// t_game	so_long;
	if (ac != 2)
	{
		function_errors(1);
		return (0);
	}
	map = map_rendering(av[1]);
	if (!map)
		exit(EXIT_FAILURE);
	printf("NOW WE CAN DISPLAY THE MAP\n");
	// so_long = setting_game(map);
	// display(so_long);
}
