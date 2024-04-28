/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 18:39:09 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_swap_enemy_right(t_pos_list *tmp, int i, int j, t_game *so_long)
{
	so_long->map->map[i][j] = '0';
	so_long->map->map[i][j + 1] = 'N';
	*tmp->x = j + 1;
	mlx_clear_window(so_long->mlx, so_long->win);
	display_game_bonus(so_long);
}

void	move_to_right(t_game *so_long)
{
	t_pos_list	*tmp;
	int			i;
	int			j;

	tmp = so_long->map->enemies;
	while (tmp != NULL)
	{
		i = *tmp->y;
		j = *tmp->x;
		if (*tmp->flag == 0 && so_long->map->map[i][j] == 'N'
			&& so_long->map->map[i][j + 1] == '0')
			ft_swap_enemy_right(tmp, i, j, so_long);
		else if ((*tmp->flag == 0 && so_long->map->map[i][j + 1] == 'P'))
			game_over(so_long);
		else
			*tmp->flag = 1;
		tmp = tmp->next;
	}
}

void	ft_swap_enemy_left(t_pos_list *tmp, int i, int j, t_game *so_long)
{
	so_long->map->map[i][j] = '0';
	so_long->map->map[i][j - 1] = 'N';
	*tmp->x = j - 1;
	mlx_clear_window(so_long->mlx, so_long->win);
	display_game_bonus(so_long);
}

void	move_to_left(t_game *so_long)
{
	t_pos_list	*tmp;
	int			i;
	int			j;

	tmp = so_long->map->enemies;
	while (tmp != NULL)
	{
		i = *tmp->y;
		j = *tmp->x;
		if (*tmp->flag == 1 && so_long->map->map[i][j] == 'N'
			&& so_long->map->map[i][j - 1] == '0')
			ft_swap_enemy_left(tmp, i, j, so_long);
		else if ((*tmp->flag == 1 && so_long->map->map[i][j - 1] == 'P'))
			game_over(so_long);
		else
			*tmp->flag = 0;
		tmp = tmp->next;
	}
}
