/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/18 19:15:43 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/* ------ C Library ------ */
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

/* ------------ Structures ------------ */
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map
{
	char	**map;
	int		x;
	int		y;
	int		c;
	t_pos	*player;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	int		size;
	int		moves;
	t_map	*map;
}	t_game;

/* --------------- Libft --------------- */
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen( char *s);
char	*ft_itoa(int n);
void 	ft_putnbr(int nb);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup( char *s);
char	**ft_split(char const *s, char c);

/* ------------ Rendering_game ------------ */
int validate_content(char **map);
int count_size(char **map, char c);
int map_elements(char **map);
int validation_path(char **map);
int is_still(char **map);
void check_valid_path(char **map, int x, int y);
char **ft_copy_map(char **map)
int validation_format(char **map);
int is_rectangular(char **map);
int is_closed(char **map);
t_pos find_position(char **map, char c);
t_map *map_rendering(char *path);
char **map_validation(char *path);
char **reading_map(char *path);
void free_map(char **map);
char *reading(int fd);
char	**get_map(char *str);
int check_extension(char *path);

/* ------------ Errors ------------ */
void maps_errors(int index);
void function_errors(int index);

#endif