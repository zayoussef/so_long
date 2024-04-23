/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/23 19:49:20 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_game  *setting_game_bonus(t_map *map)
{
    t_game *so_long;

    so_long->mlx = mlx_init();
    so_long->win = mlx_new_window(so_long->mlx, map->x * 64, map->y * 64, "so_long_bonus");
    so_long->map = map;
    so_long->size = 64;
    so_long->moves = 0;
    // so_long->placed = malloc(sizeof(int) * (cound_size(map->map, 'N')));
    so_long->direction = 0;
    return (so_long);
}