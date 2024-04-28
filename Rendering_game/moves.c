/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 18:51:41 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x
		- 1][so_long->map->player->y],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->x--;
	ft_putstr("MOVES : ", 1);
	ft_putnbr(so_long->moves);
	ft_putstr("\n", 1);
	so_long->moves++;
}

void	up(t_game *so_long)
{
	char	**map;
	int		x;
	int		y;

	so_long->direction = 0;
	map = so_long->map->map;
	x = so_long->map->player->x;
	y = so_long->map->player->y;
	if (map[x - 1][y] == '1')
		return ;
	if (map[x - 1][y] == '0')
		up_action(so_long);
	else if (map[x - 1][y] == 'C')
	{
		up_action(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x - 1][y] == 'E')
		if (so_long->map->c == 0)
			you_winn_2(so_long);
}

void	down_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x
		+ 1][so_long->map->player->y],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->x++;
	ft_putstr("MOVES : ", 1);
	ft_putnbr(so_long->moves);
	ft_putstr("\n", 1);
	so_long->moves++;
}

void	down(t_game *so_long)
{
	char	**map;
	int		x;
	int		y;

	so_long->direction = 3;
	map = so_long->map->map;
	x = so_long->map->player->x;
	y = so_long->map->player->y;
	if (map[x + 1][y] == '1')
		return ;
	if (map[x + 1][y] == '0')
		down_action(so_long);
	else if (map[x + 1][y] == 'C')
	{
		down_action(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x + 1][y] == 'E')
		if (so_long->map->c == 0)
			you_winn_2(so_long);
}
