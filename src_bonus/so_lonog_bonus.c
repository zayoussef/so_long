/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_lonog_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/23 19:41:25 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int main(int ac, char **av)
{
    t_map *map;
    t_game *so_long;

    if (ac != 2)
    {
        function_errors(1);
        return (0);
    }
    map = map_rendering_bonus(av[1]);
    if (!map)
        return (0);
    so_long = setting_game_bonus(map);
    if (!so_long)
        return (0);
    
}
