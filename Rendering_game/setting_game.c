/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/21 17:51:29 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game *setting_game(t_map *map)
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
        ft_putstr("Mlx fail : Can't init mlx\n", 2);
        exit(EXIT_FAILURE);
    }
    if (map->x * 64 > MAX_WIDTH || map->y * 64 > MAX_HEIGHT)
    {
        ft_putstr("Map too big\n", 2);
        exit(EXIT_FAILURE);
    }
    so_long->win = mlx_new_window(so_long->mlx, map->x * 64, map->y * 64, "so_long");
    so_long->map = map;
    so_long->moves = 0;
    so_long->direction = 1;
    return (so_long);
}
