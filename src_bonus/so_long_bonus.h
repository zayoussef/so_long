/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/29 18:00:14 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int					x;
	int					y;
}						t_pos;

typedef struct s_pos_list
{
	int					*x;
	int					*y;
	int					*flag;
	struct s_pos_list	*next;
}						t_pos_list;

typedef struct s_map
{
	char				**map;
	int					x;
	int					y;
	int					c;
	t_pos				*player;
	t_pos_list			*enemies;
}						t_map;

typedef struct s_image
{
	void				*img1;
	void				*img2;
	void				*img3;
	void				*img4;
	void				*img5;
	void				*img6;
	void				*img7;
	void				*img8;
	void				*img9;
	void				*img10;
	void				*img11;
	void				*img12;
	void				*img13;
}						t_img;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	void				*img;
	t_img				*image;
	int					size;
	int					moves;
	int					direction;
	t_map				*map;
}						t_game;

/* --------------- Libft --------------- */
char					*ft_strchr(char *s, int c);
char					*ft_strrchr(char *s, int c);
char					*ft_strjoin(char *s1, char *s2);
size_t					ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t					ft_strlen(char *s);
char					*ft_itoa(int n);
void					ft_swap(char *a, char *b);
void					ft_putnbr(int nb);
void					ft_putstr(char *s, int fd);
int						ft_strcmp(char *s1, char *s2);
char					*ft_strdup(char *s);
char					**ft_split(char const *s, char c);
void					ft_lstadd_back(t_pos_list **lst, t_pos_list *new);
t_pos_list				*ft_lstnew(int x, int y);
t_pos_list				*ft_lstlast(t_pos_list *lst);

/* ------------ Rendering_maps ------------ */
int						validate_content(char **map);
int						count_size(char **map, char c);
int						map_elements(char **map);
int						validation_path(char **map);
int						is_still(char **map);
void					check_valid_path(char **map, int x, int y);
char					**ft_copy_map(char **map);
int						validation_format(char **map);
int						is_rectangular(char **map);
int						is_closed(char **map);
t_pos					*find_position(char **map, char c);
t_map					*map_rendering(char *path);
char					**map_validation(char *path);
char					**reading_map(char *path);
char					*reading(int fd);
char					**get_map(char *str);
int						check_extension(char *path);

/* ------------ Rendering_map_bonus ------------ */
t_map					*map_rendering_bonus(char *path);
t_pos_list				*find_enemies(char **map, char c);
char					**map_validation_bonus(char *path);
int						validate_content_bonus(char **map);
t_game					*setting_game_bonus(t_map *map);
void					display_game_bonus(t_game *so_long);
void					draw_textures_bonus(t_game *so_long, int x, int y);
void					display_counter_bonus(t_game *so_long);

/* ------------ moves ------------ */
int						event_bonus(int key, void *param);
void					up_bonus(t_game *so_long);
void					up_action_bonus(t_game *so_long);
void					down_bonus(t_game *so_long);
void					down_action_bonus(t_game *so_long);
void					left_bonus(t_game *so_long);
void					left_action_bonus(t_game *so_long);
void					right_bonus(t_game *so_long);
void					right_action_bonus(t_game *so_long);
int						enemy_rendering(void *param);
void					enemy_move(t_game *so_long);
void					display_enemy_bonus(t_game *so_long);
void					move_up(t_game *so_long);
void					move_down(t_game *so_long);
void					move_to_right(t_game *so_long);
void					move_to_left(t_game *so_long);
void					ft_swap_enemy_up(t_pos_list *tmp, int i, int j,
							t_game *so_long);
void					ft_swap_enemy_down(t_pos_list *tmp, int i, int j,
							t_game *so_long);
void					ft_swap_enemy_right(t_pos_list *tmp, int i, int j,
							t_game *so_long);
void					ft_swap_enemy_left(t_pos_list *tmp, int i, int j,
							t_game *so_long);
int						function_enemy(t_game *so_long);
void					get_images(t_game *so_long);
void					game_over(t_game *so_long);
void					you_winn(t_game *so_long);

/* ------------ free_memory ------------ */
int						free_success_exit(void *param);
int						free_failure_exit(void *param);
void					free_map(char **map);

/* ------------ Errors ------------ */
void					maps_errors(int index);
void					function_errors(int index);

#endif