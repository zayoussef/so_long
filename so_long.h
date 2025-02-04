/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/30 12:46:47 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ------ display Macros ------ */
# define MAX_WIDTH 2560
# define MAX_HEIGHT 1440

/* ------ C Library ------ */
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/* ------------ Structures ------------ */
typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		c;
	t_pos	*player;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		size;
	int		moves;
	int		direction;
	t_map	*map;
}			t_game;

/* --------------- Libft --------------- */
char		*ft_strchr(char *s, int c);
char		*ft_strrchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(char *s);
char		*ft_itoa(int n);
void		ft_swap(char *a, char *b);
void		ft_putnbr(int nb);
void		ft_putstr(char *s, int fd);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s);
char		**ft_split(char const *s, char c);

/* ------------ Rendering_maps ------------ */
int			validation_content(char **map);
int			count_size(char **map, char c);
int			check_elements(char **map);
int			validation_path(char **map);
int			is_still(char **map);
void		check_valid_path(char **map, int x, int y);
char		**ft_copy_map(char **map);
int			validation_format(char **map);
int			is_rectangular(char **map);
int			is_closed(char **map);
t_pos		*find_position(char **map, char c);
t_map		*map_rendering(char *path);
char		**map_validation(char *path);
char		**reading_map(char *path);
char		*reading(int fd);
char		**get_map(char *str);
int			check_extension(char *path);

/* ------------ Rendering_game ------------ */
t_game		*setup_game(t_map *map);
void		display_game(t_game *so_long);
int			event(int key, void *param);
char		*textures_path(t_game *game, char c);
void		draw_textures(t_game *so_long, int x, int y);

/* ------------ moves ------------ */
void		up(t_game *so_long);
void		up_action(t_game *so_long);
void		down(t_game *so_long);
void		down_action(t_game *so_long);
void		left(t_game *so_long);
void		left_action(t_game *so_long);
void		right(t_game *so_long);
void		right_action(t_game *so_long);
void		you_winn_2(t_game *so_long);

/* ------------ free_memory ------------ */
int			free_success_exit(void *param);
int			free_failure_exit(void *param);
void		free_map(char **map);

/* ------------ Errors ------------ */
void		maps_errors(int index);
void		function_errors(int index);

#endif