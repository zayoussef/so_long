/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/23 19:31:31 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_pos **find_enemies(char **map, char c)
{
    t_pos **enemies;
    int i;
    int j;

    i = count_size(map, c);
    enemies = malloc(sizeof(t_pos) * i);
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
            {
                if (!(enemies[i] = malloc(sizeof(t_pos))))
                    return(function_errors(3),exit(EXIT_FAILURE),NULL);
                enemies[i]->x = i;
                enemies[i]->y = j;
            }
            j++;
        }
        i++;
    }
    return (enemies);
}

t_map *map_rendering_bonus(char *path)
{
    t_map *map;
    int i;

    i = 0;
    map = malloc(sizeof(t_map));
    if (!map)
    {
        function_errors(3);
        exit(EXIT_FAILURE);
    }
    map->map = map_validation_bonus(path);
    map->x = ft_strlen(map->map[0]);
    while (map->map[i])
        i++;
    map->y = i;
    map->c = count_size(map->map, 'C');
    map->pos = find_position(map->map, 'P');
    map->enemies = find_enemies(map->map, 'N');
    return (map);
}
