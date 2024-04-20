/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/20 16:20:10 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game setting_game(t_map *map)
{
    t_game *so_long;

    so_long = malloc(sizeof(t_game));
    if (!so_long)
    {
        function_errors(3);
        exit(EXIT_FAILURE);
    }
    so_long->mlx = mlx_init();
    if (!so_long->mlx)
    {
        ft_putstr("Mlx fail : Can't init mlx", 2);
        exit(EXIT_FAILURE);
    }
    so_long->win = mlx_new_window(so_long->mlx, map->x * 32, map->y * 32, "so_long");
    so_long->map = map;
    so_long->moves = 0;
    return (*so_long);
}
