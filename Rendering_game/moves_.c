/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 21:09:38 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	you_winn_2(t_game *so_long)
{
	ft_putstr("MOVES : ", 1);
	ft_putnbr(so_long->moves);
	ft_putstr("\n", 1);
	ft_putstr ("\t\tYOU WINN !\t\t\n", 1);
	free_success_exit(so_long);
}

void	right_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x][so_long->map->player->y
		+ 1],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->y++;
	ft_putstr("MOVES : ", 1);
	ft_putnbr(so_long->moves);
	ft_putstr("\n", 1);
	so_long->moves++;
}

void	right(t_game *so_long)
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
		right_action(so_long);
	else if (map[x][y + 1] == 'C')
	{
		right_action(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x][y + 1] == 'E')
		if (so_long->map->c == 0)
			you_winn_2(so_long);
}

void	left_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x][so_long->map->player->y
		- 1],
		&so_long->map->map[so_long->map->player->x][so_long->map->player->y]);
	so_long->map->player->y--;
	ft_putstr("MOVES : ", 1);
	ft_putnbr(so_long->moves);
	ft_putstr("\n", 1);
	so_long->moves++;
}

void	left(t_game *so_long)
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
		left_action(so_long);
	else if (map[x][y - 1] == 'C')
	{
		left_action(so_long);
		map[x][y] = '0';
		so_long->map->c--;
	}
	else if (map[x][y - 1] == 'E')
		if (so_long->map->c == 0)
			you_winn_2(so_long);
}
