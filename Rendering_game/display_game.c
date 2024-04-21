/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/21 17:53:41 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	up_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x - 1]
	[so_long->map->player->y],
		&so_long->map->map[so_long->map->player->x]
	[so_long->map->player->y]);
	so_long->map->player->x--;
	printf("MOVES : %d\n", so_long->moves);//
	so_long->moves++;//
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
	so_long->moves++;//
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
			exit(0);
}

void	right_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x]
	[so_long->map->player->y + 1],
		&so_long->map->map[so_long->map->player->x]
	[so_long->map->player->y]);
	so_long->map->player->y++;
	so_long->moves++;
	printf("MOVES : %d\n", so_long->moves);//
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
			exit(0);
}

void	left_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x]
	[so_long->map->player->y - 1],
		&so_long->map->map[so_long->map->player->x]
	[so_long->map->player->y]);
	so_long->map->player->y--;
	so_long->moves++;
	printf("MOVES : %d\n", so_long->moves);//
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
			exit(0);
}


void	down_action(t_game *so_long)
{
	ft_swap(&so_long->map->map[so_long->map->player->x + 1]
	[so_long->map->player->y],
		&so_long->map->map[so_long->map->player->x]
	[so_long->map->player->y]);
	so_long->map->player->x++;
	printf("MOVES : %d\n", so_long->moves);//
	so_long->moves++;//
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
			exit(0);
}

int	event(int key, void	*param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == 13 || key == 126)
		up(game);
    else if (key == 1 || key == 125)
        down(game);
    else if (key == 0 || key == 123)
        left(game);
    else if (key == 2 || key == 124)
        right(game);
	else if (key == 53 || key == 17)
		free_exit(game);
	mlx_clear_window(game->mlx, game->win);
	display_game(game);
	mlx_loop(game->mlx);
	return (0);
}

char	*textures_path(t_game *game, char c)
{
	char	*path;

	path = NULL;
	if (c == '0')
		path = "textures/empty.xpm";
	else if (c == '1')
		path = "textures/wall.xpm";
	else if (c == 'P')
	{
		if (game->direction == 1)
			path = "textures/player_right_1.xpm";
		else if (game->direction == 2)
			path = "textures/player_left_1.xpm";
		else if (game->direction == 0)
			path = "textures/player_up_1.xpm";
		else if (game->direction == 3)
			path = "textures/player_down_1.xpm";
	}
	else if (c == 'C')
	path = "textures/collect.xpm";
		else if (c == 'E')
	path = "textures/exit.xpm";
    if (!path)
        return (NULL);
	return (path);
    // check empty file for the textures and the path
}

void draw_textures(t_game *so_long, int x, int y)
{
    
    char *texture;
    
    texture = textures_path(so_long, so_long->map->map[x][y]);
    if (!texture)
        return ;
    so_long->img = mlx_xpm_file_to_image(so_long->mlx, texture, &so_long->size, &so_long->size);
    mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->img, y * 64, x * 64);
    mlx_destroy_image(so_long->mlx, so_long->img);
}

int	free_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free(game->map->player);
	free_map(game->map->map);
	free(game->map);
	free(game);
	exit(0);
	return (1);
}
void display_game(t_game *so_long)
{
    int x;
    int y;

    x = 0;
    while (so_long->map->map[x])
    {
        y = 0;
        while (so_long->map->map[x][y] && so_long->map->map[x][y] != '\n')
        {
            draw_textures(so_long, x, y);
            y++;
        }
        x++;
    }
}
