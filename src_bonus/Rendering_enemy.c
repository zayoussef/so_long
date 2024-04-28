/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rendering_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/28 18:47:38 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_over(t_game *so_long)
{
	ft_putstr ("\t\tGAME OVER !\t\t\n", 1);
	free_success_exit(so_long);
}

void	you_winn(t_game *so_long)
{
	ft_putstr ("\t\tYOU WINN !\t\t\n", 1);
	free_success_exit(so_long);
}

void	put_image_enemy(t_game *so_long, t_img *tmp)
{
	int			x;
	int			y;
	t_pos_list	*tmp_enemy;

	tmp_enemy = so_long->map->enemies;
	while (tmp_enemy != NULL)
	{
		x = *tmp_enemy->x;
		y = *tmp_enemy->y;
		mlx_put_image_to_window(so_long->mlx, so_long->win, tmp, x * 64, y
			* 64);
		tmp_enemy = tmp_enemy->next;
	}
}

int	function_enemy(t_game *so_long)
{
	static int	i;
	t_img		*tmp;

	tmp = NULL;
	if (i < 5)
		tmp = so_long->image->img1;
	else if (i < 10)
		tmp = so_long->image->img2;
	else if (i < 15)
		tmp = so_long->image->img3;
	else if (i <= 20)
		tmp = so_long->image->img4;
	put_image_enemy(so_long, tmp);
	if (i == 20)
		i = 0;
	enemy_rendering(so_long);
	return (i++);
}

int	enemy_rendering(void *param)
{
	t_game		*so_long;
	static int	i;

	so_long = (t_game *)param;
	i++;
	if (i == 20)
	{
		move_to_right(so_long);
		move_to_left(so_long);
		i = 0;
	}
	return (1);
}
