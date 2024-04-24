/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/24 16:56:21 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	right_action_bonus(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x][so_long->map->player->y
		+ 1],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->y++;
	so_long->moves++;
}

void	right_bonus(t_game *so_long)
{
	char	**map;
	int		x;
	int		y;

	so_long->direction = 1;
	map = so_long->map->map;
	x = so_long->map->player->x;
	y = so_long->map->player->y;
	if (map[x][y + 1] == '1')
		return ;
	if (map[x][y + 1] == '0')
		right_action_bonus(so_long);
	else if (map[x][y + 1] == 'C')
	{
		right_action_bonus(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x][y + 1] == 'E')
		if (so_long->map->c == 0)
			exit(EXIT_SUCCESS);
}

void	left_action_bonus(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x][so_long->map->player->y
		- 1],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->y--;
	so_long->moves++;
}

void	left_bonus(t_game *so_long)
{
	char	**map;
	int		x;
	int		y;

	so_long->direction = 2;
	map = so_long->map->map;
	x = so_long->map->player->x;
	y = so_long->map->player->y;
	if (map[x][y - 1] == '1')
		return ;
	if (map[x][y - 1] == '0')
		left_action_bonus(so_long);
	else if (map[x][y - 1] == 'C')
	{
		left_action_bonus(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x][y - 1] == 'E')
		if (so_long->map->c == 0)
			exit(EXIT_SUCCESS);
}
