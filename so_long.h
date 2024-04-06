/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/06 07:32:05 by yozainan         ###   ########.fr       */
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
char	*get_next_line(int fd);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen( char *s);
int	ft_strcmp(char *str1, char *str2);
char	*ft_strdup( char *s);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_ft(char *s1, char *s2);

#endif