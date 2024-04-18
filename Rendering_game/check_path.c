/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/18 17:13:38 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 char **ft_copy_map(char **map)
 {
    char    **copy_map;
    int     i;

    i = 0;
    while (map[i]);
        i++;
    copy_map = malloc(sizeof(char) * (i + 1));
    if (!copy_map)
        return (NULL);
    i = 0;
    while (map[i])
    {
        copy_map[i] = ft_strdup(map[i]);
        i++;
    }
    copy_map[i] = '\0';
    return (copy_map);
 }

void check_valid_path(char **map, int x, int y)
{
    if (x < 0 || y < 0 || map[x][y] == '\0' 
    || map[x][y] == '1' || map[x][y] == 'Z')
        return ;
    if (map[x][y] == '0')
        map[x][y] = 'Z';
    if (map[x][y] == 'E')
    {
        map[x][y] = 'Z';
        return ;
    }
    check_valid_path(map, x, y + 1);
    check_valid_path(map, x, y - 1);
    check_valid_path(map, x - 1, y);
    check_valid_path(map, x + 1, y);
}

int loop_maop(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E' || map[i][j] == 'C')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int validation_path(char **map)
{
    t_pos *player;
    char **copy_map;

    player = find_position(map, 'P');
    copy_map = ft_copy_map(map);
    check_valid_path(copy_map, player->x, player->y)
	if (!loop_map(copy_map))
    {
		map_errors(4);
        free_map(copy_map);
		exit(EXIT_FAILURE);
	}
    free_map(copy_map);
    return (1);
}