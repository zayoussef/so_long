/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/18 19:37:59 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int map_elements(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1' && map[i][j] != '0' 
            && map[i][j] != 'P' && map[i][j] != 'E' 
            && map[i][j] != 'C')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int count_size(char **map, char c)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                count++;
            j++;
        }
        i++;
    }
    return (count);
}

int validate_content(char **map)
{
     if (!map_elements(map) || count_size(map, 'P') != 1 
     || count_size(map, 'E') != 1 || count_size(map, 'C') < 1)
    {
        maps_errors(2);
        return (0);
    }
    return (1);
}