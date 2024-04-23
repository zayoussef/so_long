/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozainan <yozainan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 03:26:53 by yozainan          #+#    #+#             */
/*   Updated: 2024/04/23 19:52:33 by yozainan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src_bonus/so_long_bonus.h"

int	check_extension(char *path)
{
	char	*tmp;

	if (ft_strrchr(path, '/'))
	{
		tmp = ft_strrchr(path, '/') + 1;
		if ((tmp[0] && tmp[0] == '.') || !tmp[0])
		{
			ft_putstr("Invalid map extention\n", 2);
			return (0);
		}
	}
	if (ft_strlen(path) < 5 || (ft_strlen(path) - 4) <= 0)
	{
		maps_errors(5);
		return (0);
	}
	tmp = path + ft_strlen(path) - 4;
	if (ft_strcmp(tmp, ".ber") == 0)
		return (1);
	else
	{
		maps_errors(1);
		return (0);
	}
}

char	**get_map(char *str)
{
	char	**map;
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') || ((str[0] == '\n')
				|| str[ft_strlen(str) - 1] == '\n'))
		{
			maps_errors(2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	map = ft_split(str, '\n');
	if (!map)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	return (map);
}

char	*reading(int fd)
{
	char	*map;
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * 11);
	if (!buffer)
		return (NULL);
	map = NULL;
	i = 1;
	while (i)
	{
		i = read(fd, buffer, 10);
		if (i < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		map = ft_strjoin(map, buffer);
	}
	free(buffer);
	return (map);
}

char	**reading_map(char *path)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		function_errors(2);
		exit(EXIT_FAILURE);
	}
	line = reading(fd);
	if (!line)
	{
		function_errors(4);
		exit(EXIT_FAILURE);
	}
	close(fd);
	map = get_map(line);
	if (!map)
	{
		free(line);
		exit(EXIT_FAILURE);
	}
	free(line);
	return (map);
}

char	**map_validation(char *path)
{
	char	**map;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		function_errors(2);
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (!check_extension(path))
		exit(EXIT_FAILURE);
	map = reading_map(path);
	if (!validate_content(map) || !validation_format(map)
		|| !validation_path(map))
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}

char **map_validation_bonus(char *path)
{
	char **map;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		function_errors(2);
		exit(EXIT_FAILURE);
	}
	close(fd);
	if (!check_extension(path))
		exit(EXIT_FAILURE);
	map = reading_map(path);
	if (!validate_content_bonus(map) || !validation_format(map)
		|| !validation_path(map))
	{
		free_map(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}
