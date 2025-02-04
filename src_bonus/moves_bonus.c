/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 18:47:10 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	up_action_bonus(t_game *so_long)
{
	so_long->direction = 0;
	ft_swap(&so_long->map->map[so_long->map->player->x
		- 1][so_long->map->player->y],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->x--;
	so_long->moves++;
}

void	up_bonus(t_game *so_long)
{
	char	**map;
	int		x;
	int		y;

	map = so_long->map->map;
	x = so_long->map->player->x;
	y = so_long->map->player->y;
	if (map[x - 1][y] == '1')
		return ;
	if (map[x - 1][y] == '0')
		up_action_bonus(so_long);
	else if (map[x - 1][y] == 'C')
	{
		up_action_bonus(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x - 1][y] == 'N')
		game_over(so_long);
	else if (map[x - 1][y] == 'E')
		if (so_long->map->c == 0)
			you_winn(so_long);
}

void	down_action_bonus(t_game *so_long)
{
	so_long->direction = 3;
	ft_swap(&so_long->map->map[so_long->map->player->x
		+ 1][so_long->map->player->y],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->x++;
	so_long->moves++;
}

void	down_bonus(t_game *so_long)
{
	char	**map;
	int		x;
	int		y;

	map = so_long->map->map;
	x = so_long->map->player->x;
	y = so_long->map->player->y;
	if (map[x + 1][y] == '1')
		return ;
	if (map[x + 1][y] == '0')
		down_action_bonus(so_long);
	else if (map[x + 1][y] == 'C')
	{
		down_action_bonus(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x + 1][y] == 'N')
		game_over(so_long);
	else if (map[x + 1][y] == 'E')
		if (so_long->map->c == 0)
			you_winn(so_long);
}
